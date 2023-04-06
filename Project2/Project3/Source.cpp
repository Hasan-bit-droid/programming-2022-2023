#include <iostream>
#include <cmath>
#include <cstdlib>
#include <omp.h>

using namespace std;

double S[1000000];

int main()
{
	double t = omp_get_wtime();
	int n = 1000000;
#pragma omp for
		{    
			for (int i = 0; i < n; i++)
				S[i] = sin(i * 3.14 / (2 * n));
		}
	
	cout << "S: " << S << endl;
	cout << "Time: " << omp_get_wtime() - t << endl;
	return EXIT_SUCCESS;
}	
// 1 я задача на параллел for