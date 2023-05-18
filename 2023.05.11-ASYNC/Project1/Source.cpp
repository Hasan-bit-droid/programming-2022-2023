//zadacha 2 , f-ya prinimayushaya 2 stroki
#include <iostream>
#include <cmath>
#include <future>
#include <chrono>
#include <algorithm>
#include <string>
#include <istream>


using namespace std::chrono;
using namespace std;


int block_size(int threads, int n)
{
	return n / threads + (n % threads ? 1 : 0);
}

int count (string s, string what, int a, int b)
{
	int bs = block_size(a, s.size());
	int k = 0;
	for (int i = b; i < min<int>(b + bs, s.size()); i++)
		if (s.substr(i, what.size()) == what)
			k++;
	return k;
}
int MultiThreadTable(int a, string s, string what)
{
	vector<future <int>> fut;
	int bl_size = block_size(a, s.size());
	int b = 0;
	int i = 0;
	while (b < s.size())
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