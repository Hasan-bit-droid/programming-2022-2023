#include <iostream>

using namespace std;

void funk(double arr[], int size)
{
	for (int i = 0; i < size / 2; ++i)
	{
		double tmp;
		tmp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - i - 1] = tmp;
	}
}

int main()

{
	const int n = 10;
	double arr[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	funk(arr,n);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " " ;
	}
	return 0;
}