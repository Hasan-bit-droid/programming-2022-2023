#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;

int object; // ��� ������
bool flag = false; // true -- ����� ��������, false -- ����� ����
bool work1 = true, work2 = true;
vector<int> v1, v2;// v1 -- ������������, v2 � �����������

void factory()
{
	while (work1)
	{
		if(flag)
			this_thread::sleep_for(100ms);
		else
		{
			object = rand();
			v1.push_back(object);
			flag = true;
		}
	}
}

void consumer()
{

}
void 
{

}


int main()
{
	
	return 0;
}