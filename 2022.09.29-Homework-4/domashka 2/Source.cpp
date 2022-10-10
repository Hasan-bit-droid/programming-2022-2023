// 7
#include <iostream>

using namespace std;

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << &arr[6] - &arr[3];
	cout << endl;
	cout << &arr[1] - &arr[3];
	return 0;
}