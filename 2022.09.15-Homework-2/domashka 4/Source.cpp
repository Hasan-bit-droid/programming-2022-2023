#include <iostream>
#include <string>


using namespace std;



int main()
{

    string tmp1, tmp2;

    cin >> tmp1;
    for (int i = 0; i < tmp1.size(); ++i)
    {

        if (tmp1[i] != '+')
        {

            tmp2 += tmp1[i];

        }
        else
        {

            if (tmp1[i + 1] != '-')
            {

                tmp2 += tmp1[i];

            }

        }

    }

    cout << tmp2;

    return EXIT_SUCCESS;

}
