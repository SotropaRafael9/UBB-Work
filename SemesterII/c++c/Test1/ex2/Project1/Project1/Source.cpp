#include <string>
#include <cassert>
#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>
#include <cstring>

class Complex {
	double real, imaginary;
	public:
		Complex(double real = 0, double imaginary = 0) : real{ real }, imaginary{ imaginary } {}
		double getReal() const { return real; }
		double getImaginary() const { return imaginary; }
		Complex operator/(double x) const {
			if (x == 0) throw std::runtime_error("Division by zero!");
			return Complex{ real / x, imaginary / x };
		}
		bool operator==(const Complex& other) const {
			return real == other.real && imaginary == other.imaginary;
		}
		friend std::ostream& operator<<(std::ostream& out, const Complex& c) {
			out << c.real << "+" << c.imaginary << "i";
			return out;
		}



};
class Vector {
	std::vector<std::string> v;
	public:
		Vector(const std::vector<std::string>& v) : v{ v } {}
		void printAll(std::ostream& out) const {
			for (const auto& s : v) {
				out << s << " ";
			}
			out << "\n";
		}

};

template <typename T>

void complex()
{
	Complex a{}, b{ 1,2 }, c{ 6,4 }, d{ b };
	assert(a.getReal() == 0 && a.getImag() == 0);
	assert(c.getImaginary() == 4);
	assert(b ==d);
	Complex res1 = c / 2;
	cout << res1 << "\n"; // prints 3+2i
	try {
		Complex res2 = b / 0;
	}
	catch (runtime_error& e) {
		assert(strcmp(e.what(), "Division by zero!") == 0);
	}
	Vector<string> v1 {std::vector<string>{"hello","bye"}};
	v1.printAll(std::cout);//printss hello bye

	Vector<Complex> v2{std::vector<Complex>{a,b,c,d}};
	v2.printAll(std::cout);//prints 0+0i 1+2i 6+4i 1+2i
}


int main()
{
	complex<Complex>();
	return 0;
}
