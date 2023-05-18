#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
mutex m;
int sum = 0;
void f_sum()
{
	for (int i = 0; i < 1'000'000; i++)
	{
		m.lock(); // ��������� mutex
		sum++;
		m.unlock(); // ��������� mutex
	}
}
int main()
{
	thread t1(f_sum);
	thread t2(f_sum);

	t1.join();
	t2.join();
	cout << "Sum: " << sum << endl; // ��������� ������ 2000000
	return 0;
}