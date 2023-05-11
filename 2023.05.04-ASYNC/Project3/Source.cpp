// vichislenie chisla pi  s pomoshju async; eto drugoy variant resheniya
#include <iostream>
#include <cmath>
#include <vector>
#include <future>
#include <chrono>

using namespace std::chrono;
using namespace std;

const int N = 1'000'000;
const int n = N + 1;
vector <double> v(n);

int block_size(int threads)
{
	return n / threads + (n % threads ? 1 : 0);
}
double f(double x)
{
	return 1 / (x*x + 1);
}

double Pi(int threads, int first_index)
{
	double S = 0;

	int bl_size = block_size(threads);

	for (int i = first_index; i < min(first_index + bl_size, n); i++)
		S += f((2 * i - 1.0) / (2 * n));
	return (1.0 / n) * S * 4;
}
void MultiThreadTable(int threads)
{
	vector<future <void>> fut;
	int bl_size = block_size(threads);
	int first_index = 0;
	int i = 0;
	while (first_index < n)
	{
		fut.push_back(async(Pi, threads, first_index));
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
	int threads = 8;
	auto start = steady_clock::now();
	MultiThreadTable(threads);
	auto finish = steady_clock::now();

	cout << duration_cast <milliseconds> (finish - start).count() << "ms " << endl;
	for (auto x : v)
		cout << x << endl;
	return 0;
}