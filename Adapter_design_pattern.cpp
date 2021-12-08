#include<iostream>
using namespace std;

class IndianSocket
{
	public:
		virtual void indianCharger()=0;
};

class USASocket
{
	public:
		void usaCharger()
		{
			cout<<"USA charger "<<endl;
		}
};

class SocketAdapter:public IndianSocket, public USASocket
{
	public:
		void indianCharger()
		{
			usaCharger();
		}
};


int main()
{
	IndianSocket *obj = new SocketAdapter();
	obj->indianCharger();
}
