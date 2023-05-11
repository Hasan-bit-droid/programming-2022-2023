// vichislenie chisla pi  s pomoshju async; eto prostoy variant
#include <iostream>
#include <cmath>
#include <vector>
#include <future>
#include <chrono>

using namespace std::chrono;
using namespace std;
const int n = 1000000;
vector <double> v(n + 1);

double f(double x)
{
	return 1 / (x*x + 1);
}

double Pi(int from, int to)
{
	double S = 0;
	
	for (int i = from; i <= to; ++i)
		S += f((2 * i - 1.0) / (2 * n));
		return (1.0 / n) * S * 4;
}

int main()
{
	future<double> f1 = async(Pi, 0, n / 2);
	future<double> f2 = async(Pi, n / 2 + 1, n);
	double res = f1.get() + f2.get();
	cout << res << endl;
	return 0;
}