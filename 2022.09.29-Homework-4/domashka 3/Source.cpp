// 8 
#include <iostream>

using namespace std;

int dis(int arr[], int size, int* p)
{
	if (p - &arr[0] < &arr[size - 1] - p)
	{
		return p - &arr[0];
	}
	else if (&arr[size - 1] - p <= p - &arr[0])
	{
		return &arr[size - 1] - p;
	}
}

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* p = &arr[3];
	cout << dis(arr, 10, p);
	cout << endl;
	
	return 0;
}