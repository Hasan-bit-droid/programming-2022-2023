#include <iostream>


using namespace std;


int main()

{


    int** arr = new int* [2];

    for (int i = 0; i < 2; i++)

    {
        arr[i] = new int[2];


    }

    for (int i = 0; i < 2; ++i)

    {
        for (int j = 0; j < 2; ++j)

        {
            arr[i][j] = rand() % 100;

        }

    }

    for (int i = 0; i < 2; ++i)

    {

        for (int j = 0; j < 2; ++j)

        {

            cout << arr[i][j] << ' ';

        }

        cout << endl;

    }



    int sum = arr[0][0] + arr[1][1];

    int d = arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];

    cout << "sum" << " = " << sum << endl;

    cout << "d" << " = " << d << endl;


    return EXIT_SUCCESS;

}