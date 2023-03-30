#include <iostream>
#include <cmath>
#include <cstdlib>
#include <omp.h>

using namespace std;

double f(double x)
{
	return 1/(x*x +1);
}

double Pi(int n)
{
	double S = 0;
#pragma omp parallel sections reduction(+:S)
	{
#pragma omp section
		{
			for (int i = 1; i <= n / 2; ++i)
				S += f((2 * i - 1.0) / (2 * n));
		}
#pragma omp section
		{

			for (int j = n / 2 + 1; j <= n; ++j)
				S += f((2 * j - 1.0) / (2 * n));
		}
	}
	return (1.0/n) * S * 4;
}

	int main()
	{
		int n;
		n = 1000;
		cout << Pi(n);

		return 0;
	}
