#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <cmath>
using namespace std;

double S[1000000];

int main()
{
	double t = omp_get_wtime();
	int n = 1000000;
#pragma omp parallel sections reduction(+: n)
	{
#pragma omp section
		{    
			for (int i = 0; i < 5e5; i++)
				S[i] = sin(3.1416 / 2e6 * i);
		}
#pragma omp section
		{
			for (int i = 5e5; i < 1e6; i++)
				S[i] = sin(3.1416 / 2e6 * i);
		}
	}
	cout << "S: " << S << endl;
	cout << "Time: " << omp_get_wtime() - t << endl;
	return EXIT_SUCCESS;
}	