#include <iostream>

#include <cstdlib>

using namespace std;

int main()

{

	int n;

	cout << "Input the number: ";

	cin >> n;


	cout << "(-1)^n = " << (n % 2 == 0 ? 1 : -1) << endl;

	return EXIT_SUCCESS;

}