#include <iostream>

using namespace std;

int main()
{
	int* p;
	int x = 10;
	p = &x;
	*p = 20;
	cout << x << endl;


	return EXIT_SUCCESS; 
}