//zadacha 2 , f-ya prinimayushaya 2 stroki
#include <iostream>
#include <cmath>
#include <vector>
#include <future>
#include <chrono>
#include <algorithm>


using namespace std::chrono;
using namespace std;

const int n = 100000;


int block_size(int threads)
{
	return n / threads + (n % threads ? 1 : 0);
}

int count (string s, string what, int a, int b)
{
	int bs = block_size(a);
	int k = 0;
	for (int i = b; i < min(b + bs, s.size()); i++)
		if (s.substr(i, what.size()) == what)
			k++;
	return k;
}
int MultiThreadTable(int a, string s, string what)
{
	vector<future <int>> fut;
	int bl_size = block_size(a);
	int b = 0;
	int i = 0;
	while (b < n)
	{
		fut.push_back(async(count, s, what, a, b));
		b += bl_size;
		i++;
	}
	// можно явно написать вызовы f.get()
	int k = 0;
	for (int j = 0; j < i; ++j)
		k += fut[j].get();
	return k;
	// дожидаемся результатов параллельных вычислений
}


int main()
{
	int a;
	cin >> a;
	string s, what;
	cin >> s >> what;
	auto start = steady_clock::now();
	MultiThreadTable(a, s, what);
	cout << MultiThreadTable(a, s, what) << endl;
	auto finish = steady_clock::now();

	cout << duration_cast <milliseconds> (finish - start).count() << "ms " << endl;
	
	return 0;
}