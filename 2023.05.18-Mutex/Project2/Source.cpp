#include <iostream>
#include <future>
#include <mutex>
using namespace std;
int sum = 0;

mutex m; // завели mutex
void f_sum()
{
	for (int i = 0; i < 1000000; i++)
	{
		lock_guard <mutex> l(m);
		// шаблонный класс lock_guard<mutex> упрощает работу с mutex
		// безопасен по отношению к исключениям
		// в конструкторе переменной l захватывается mutex m,
		// а в деструкторе отпускается
		sum++;
	}
}

int main()
{
	future <void> f1 = async(f_sum);
	future <void> f2 = async(f_sum);
	f1.get();
	f2.get();
	cout << "Sum: " << sum << endl;
	return 0;
}