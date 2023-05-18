#include <iostream>
#include <future>
#include <mutex>
using namespace std;
int sum = 0;

mutex m; // ������ mutex
void f_sum()
{
	for (int i = 0; i < 1000000; i++)
	{
		lock_guard <mutex> l(m);
		// ��������� ����� lock_guard<mutex> �������� ������ � mutex
		// ��������� �� ��������� � �����������
		// � ������������ ���������� l ������������� mutex m,
		// � � ����������� �����������
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