#include<iostream>
using namespace std;

class Toy
{
	protected:
		string name;
	public:
		virtual void prepareParts()=0;
		virtual void assembleParts()=0;
		virtual void applyLabels()=0;
};

class Car:public Toy
{
	public:
		void prepareParts(){ cout<<"Preparing car parts "<<endl;}
		void assembleParts(){ cout<<"Assemble car parts "<<endl;}
		void applyLabels(){ cout<<"Applying car labels "<<endl; name = "Car";}
};

class Bike:public Toy
{
	public:
		void prepareParts(){ cout<<"Preparing Bike parts "<<endl;}
		void assembleParts(){ cout<<"Assemble Bike parts "<<endl;}
		void applyLabels(){ cout<<"Applying Bike labels "<<endl; name = "Bike";}
};

class Plane:public Toy
{
		void prepareParts(){ cout<<"Preparing Plane parts "<<endl;}
		void assembleParts(){ cout<<"Assemble Plane parts "<<endl;}
		void applyLabels(){ cout<<"Applying Plane labels "<<endl; name = "Plane";}
};

class ToyFactory
{
	public:
		static Toy* createInstance(int type)
		{
			Toy *instance = NULL;
			switch(type)
			{
				case 1: {
					instance = new Car;
					break;
				}
				case 2: {
					instance = new Bike;
					break;
				}
				case 3: {
					instance = new Plane;
					break;
				}
			}
			return instance;	
		}
};

int main()
{
	int type;
	while(1)
	{
		cout<<"Enter 1 2 3 for Car Bike Plane instance "<<endl;
		cin>>type;
		if(!type)
			break;
		Toy *toy = ToyFactory::createInstance(type);
		if(toy)
		{
			toy->prepareParts();
			toy->assembleParts();
			toy->applyLabels();
			delete toy;
		}
	}
}
