#include <iostream>
#include <ostream>

using namespace std;

double funk(double **arr, int n, int m)
{
	double sum = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (i = j)
			{
				sum += arr[i][j];
			}
		}
	}
	return sum;
}

int main()

{
	const int n = 3;
	int m;
	
	double** arr = new double* [n];
	
	srand(time(NULL));
	for (int i = 0; i < n; i++)   //строки массива
		for (int j = 0; j < m; j++)   //столбцы массива
			arr[i][j] = 1 + rand() % 10;  //заполн€ем текущую €чейку

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			
			cout <<	"sum=";
			
		}
	}
	delete[]arr;
	arr = nullptr;
	cout << endl;
	cout << arr[n][m] << endl;

	
	return 0;
}