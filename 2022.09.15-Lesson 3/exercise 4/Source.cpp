#include <iostream>

using namespace std;

void swap(double* p, double* q)
{
	double tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}

int main()
{ 
	double x = 7, y = 3;
	double* p = &x;
	double* q = &y;

	swap(p, q);
	cout << x << " " << y << endl;

	return EXIT_SUCCESS;
}