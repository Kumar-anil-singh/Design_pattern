#include<iostream>
#include<mutex>
using namespace std;

mutex mtx;

class Singleton
{
	private:
		int data;
		static Singleton* instance;
		Singleton()
		{
			data = 0;
		}
	public:
		static Singleton* getinstance()
		{
			if(instance == nullptr) // lazy initialization
			{
				mtx.lock();
				if(instance == nullptr)
					instance = new Singleton;
				mtx.unlock();
			}
			return instance;
		}
		Singleton(const Singleton&) = delete;
		Singleton& operator=(const Singleton&) = delete;
		Singleton(Singleton &&) = delete;
		Singleton& operator=(Singleton &&) = delete;
		void setdata(int n)
		{
			data = n;
		}
		int getdata()
		{
			return data;
		}
};

Singleton* Singleton::instance = nullptr;

int main()
{
	Singleton *obj1 = Singleton::getinstance();
	obj1->setdata(100);
	cout<<obj1->getdata()<<endl;	
	Singleton *obj2 = Singleton::getinstance();
	if(obj1 == obj2)  // to check if it is returning the same object or not
		cout<<"returning same object"<<endl;
	else
		cout<<"returning different object"<<endl;
}
		
