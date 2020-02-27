// PHYS 30762 Programming in C++
// Assignment 5 - 26/02/2020
// Hermione Warr
// Class for complex numbers

#include<iostream>
#include<cmath>

class complex
{
	// Make function to overload operator<< a friend
	friend std::ostream& operator<<(std::ostream &os, const complex &complex_no);
private:
	double real;
	double im;
public:
	// Constructors & destructor
	complex() { real = im = 0; }
	complex(double real_part, double im_part) : real{ real_part }, im{ im_part }{}
	~complex() {}

	// Return real component
	double real_component() const {return real; }
	
	// Return imaginary component
	double im_component() const { return im; }

	// Return modulus
	double modulus() {
		double mod = pow(real, 2) + pow(im, 2);
		return mod;
	}
	// Return argument
	double argument() {
		double arg = atan(im/real);
		return arg;
	}
	// Return complex conjugate

	// Overload + operator for addition 
	complex operator+(const complex& complex_one) const
	{
		complex added_complex{real_component() + complex_one.real_component(), im_component() + complex_one.im_component()};
		return added_complex;
	}
	// Overload - operator for subtraction

	// Overload * operator for multiplication, z1*z2

	// Overload / operator for division, z1/z2

};

// Function to overload << operator for complex numbers
std::ostream &operator<<(std::ostream& os, const complex &complex_no) {
	if (complex_no.im > 0) {
		os << complex_no.real << "+" << complex_no.im << "i";
	}
	else {
		os << complex_no.real << complex_no.im << "i";
	}
	return os;
}

int main()
{
	std::cout.precision(3);

	// Create two complex numbers
	complex a{ 3,4 };
	complex b{ 1,-2 };
	//complex e;
	// Get real and imaginary components, modulus and argument
	std::cout << "complex no a: " << a << "\ncomplex no b: " << b << std::endl;
	std::cout << "real part of a: " << a.real_component() << "\nreal part of b: " << b.real_component() << std::endl;
	std::cout << "imaginary part of a: " << a.im_component() << "\nimaginary part of b: " << b.im_component() << std::endl;
	std::cout << "modulus of a: " << a.modulus() << std::endl;
	std::cout << "argument of a: " << a.argument() << std::endl;
	// Get conjugates

	// Get sum, difference, product and quotient of a and b
	complex e = a + b;
	std::cout << "sum of a and b: " << e << std::endl;
	// Print out results, also demonstrating use of overloaded operator<<

	// Show results of overloading arithmetic operators

	return 0;
}