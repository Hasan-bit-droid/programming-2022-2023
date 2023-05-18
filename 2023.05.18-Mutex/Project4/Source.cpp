#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;

int object; // код товара
bool flag = false; // true -- склад заполнен, false -- склад пуст
bool work1 = true, work2 = true;
vector<int> v1, v2;// v1 -- производство, v2 – потребление

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