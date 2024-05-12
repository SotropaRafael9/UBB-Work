#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <deque>

using namespace std;

class A {
private:
	int* x;
public:
	static int noOfInstances;
	 
	A(int _x = 5)
	{
		x = new int{ _x };
		noOfInstances++;
	}
	int get() { return *x; }
	void set(int _x) { *x = _x; }
	~A() { delete x; }
};
int A::noOfInstances = 0;
int main()
{
	A a1, a2;
	cout << a1.noOfInstances << " "; // 2
	A a3 = a1; //3
	cout << A::noOfInstances << " ";//3
	a1.set(10);
	cout << a1.get() << " ";//10 5 10
	cout << a2.get() << " ";
	cout << a3.get() << " ";
	return 0;
}
