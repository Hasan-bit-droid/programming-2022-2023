#include <iostream>
#include <cmath>
#include <vector>
#include <future>
#include <chrono>

using namespace std;
using namespace std::chrono;

const double pi = 3.14159;
const int n = 1000000;
vector <double> v(n + 1);

void sin_table(int from, int to)
{
	double step = pi / (2 * n);
	for (int i = from; i <= to; i++)
		v[i] = sin(i * step);
}

int main()
{
	auto t1 = steady_clock::now();	// программа
	
	future<void> f1 = async(sin_table, 0, n / 2);
	future<void> f2 = async(sin_table, n / 2 + 1, n);
	f1.get();
	f2.get(); // если далее обработка, дожидаемся результатов 
	/*
	sin_table(0, n / 2);
	sin_table(n / 2 + 1, n);*/

	auto t2 = steady_clock::now();
	cout << duration_cast <milliseconds> (t2 - t1).count() << " ms " << endl; 
	
	return 0;
}