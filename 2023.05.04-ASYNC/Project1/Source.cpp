#include <iostream>
#include <future>
#include <chrono>
#include <vector>
#include <cmath>
using namespace std;
using namespace std::chrono;
const double pi = 3.14159;
const int N = 1'000000;
const int n = N + 1;
vector <double> v(n);

int block_size(int threads)
{
	return n / threads + (n % threads ? 1 : 0);
}
void sin_table(int threads, int first_index)
{
	double step = pi / (2 * N);
	int bl_size = block_size(threads);

	for (int i = first_index; i < min(first_index + bl_size, n); i++)
		v[i] = sin(i * step);
}
void MultiThreadTable(int threads)
{
	vector<future <void>> fut(threads);
	int bl_size = block_size(threads);
	int first_index = 0;
	int i = 0;
	while (first_index < n)
	{
		fut[i] = async(sin_table, threads, first_index);
		first_index += bl_size;
		i++;
	}
	// можно явно написать вызовы f.get()
	for (int j = 0; j < i; ++j)
		fut[j].get();
	// дожидаемся результатов параллельных вычислений
}
int main()
{
	auto t1 = steady_clock::now();
	int threads = 8;
	auto start = steady_clock::now();
	MultiThreadTable(threads);
	auto finish = steady_clock::now();

	cout << duration_cast <milliseconds> (finish - start).count() << "ms " << endl;
	for (auto x : v)
		cout << x << endl;

	auto t2 = steady_clock::now();
	cout << duration_cast <milliseconds> (t2 - t1).count() << " ms " <<	endl;
	return 0;
}