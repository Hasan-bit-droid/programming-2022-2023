#include <iostream>
#include <cmath>
#include <cstdlib>
#include <omp.h>

using namespace std;

bool prime(int n)
{
	if (n == 1) return false;
	if (n % 2 == 0 && n != 2) // отдельно проверим делимость на 2
		return false;
	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;
	// выход из функции, как только нашли делитель
	return true; // цикл закончился, делителей не нашлось
}


int main()
{
	
	int n, c = 0;
	cin >> n;
#pragma omp parallel sections reduction(+:c)
	{
#pragma omp section
		{
			for (int i = 2; i * i <= n / 2; ++i)
				if (prime(i))
					c++;
		}
#pragma omp section
		{
			for (int i = n/2; i < n; ++i)
				if (prime(i))
					c++;
		}
	}
	cout << c << endl;

	return 0;
}
// 3я задача