#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

int object; // код товара
bool flag = false; // true -- склад заполнен, false -- склад пуст
bool work1 = true, work2 = true;
vector<int> v1, v2;// v1 -- производство, v2 – потребление

mutex m;

void factory_m()
{
	while (work1)
	{
		m.lock(); 
		if (flag)
		{
			m.unlock();
			this_thread::sleep_for(1s);
		}
		else
		{
			object = rand();
			v1.push_back(object);
			flag = true;
			m.unlock();
		}
	}
}

void consumer_m()
{
	while (work2)
	{
		m.lock();
		if (flag)
		{
			m.unlock();
			this_thread::sleep_for(1s);
		}
		else
		{
			object = rand();
			v2.push_back(object);
			flag = false;
			m.unlock();
		}
	}
}
void check_all_m()
{
	thread t1(factory_m);
	thread t2(factory_m);
	thread t3(consumer_m);
	thread t4(consumer_m);
	thread t5(consumer_m);
	this_thread::sleep_for(2s);
	work1 = false;
	work2 = false;
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	for (int x : v1)
		cout << x << endl;
	for (int y : v2)
		cout << y << endl;
}


int main()
{
	check_all_m();
	
	return 0;
}