#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>

using namespace std;

class Icecream
{

public:
	virtual string getDescription() = 0;
	virtual int computePrice() = 0;

};

class SimpleIcream : public Icecream
{
	string description;
	int price;
public:
	SimpleIcream(string description, int price): description{description}, price{price} {}
	string getDescription() override
	{
		return "simple ice cream with " + description;
	}
	
	int computePrice() override
	{
		return price;
	}
};
class IceCreamWithTopping:public Icecream
{
protected:
	Icecream* icecream;


public:
	IceCreamWithTopping(Icecream* ice) {
		this->icecream =ice;
	}
	virtual string addTopping() = 0;
	string getDescription() override
	{
		return icecream->getDescription() + " " + addTopping();
	}
	
};
class IcecreamWithChocolateTopping : public IceCreamWithTopping
{
public:
	string addTopping() override
	{
		return "with chocolate topping";
	}
	int computePrice() override
	{
		return icecream->computePrice() + 3;
	}
};

class IcecreamWithCaramelTopping : public IceCreamWithTopping
{
public:
	string addTopping() override
	{
		return "with caramel topping";
	}
	int computePrice() override
	{
		return icecream->computePrice() + 2;
	}
};
class Order
{
private:
	vector<Icecream*> icecream;
public:
	void addIcream(Icecream* icecreamm)
	{
		icecream.push_back(icecreamm);
	}
	void printOrder()
	{
		
	}

};

int main()
{
	Order order;
	order.addIcream(new SimpleIcream("vanilla", 5));
	order.addIcream(new IcecreamWithChocolateTopping(new IcecreamWithCaramelTopping(new SimpleIcream("pista", 5))));
	order.addIcream(new)

}

// 