#include <iostream>
#include <cmath>
#include <cstdlib>
#include <omp.h>

using namespace std;

double f(double x)
{
	return 1/(x*x +1);
}


	int main()
	{
		double sum = 0;
#pragma omp parallel for reduction (+:sum)
			
		for (int i = 0; i < 10000; ++i)
				sum += 1/(1+(i/1e4)*(i/1e4));
		cout << sum * 4 / 1e4 << endl;

		return 0;
	}
// 2я задача на параллел for