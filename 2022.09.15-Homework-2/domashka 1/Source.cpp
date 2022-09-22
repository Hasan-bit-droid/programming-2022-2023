#include <iostream>


using namespace std;



void Swap3(double& a, double& b)

{
    double temp = b;

    b = a;

    a = temp;

    cout << "a=" << a << "  b=" << b << "\n";
}


int main()

{
    double a = 5, b = 7;

    Swap3(a, b);

    system("pause");

    return 0;

}