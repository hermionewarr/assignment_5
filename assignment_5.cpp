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
	//extraction friend
	friend std::istream& operator>>(std::istream &is, complex &complex_no);
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
	double modulus()
	{
		double modulus = pow(real, 2) + pow(im, 2);
		return modulus;
	}
	// Return argument
	double argument() 
	{
		double arg = atan(im/real);
		return arg;
	}
	// Return complex conjugate
	complex conjugate() const
	{
		double conj_im_componrnt = -im;
		complex complex_conjugate{ real, conj_im_componrnt};
		return complex_conjugate;
	}
	// Overload + operator for addition 
	complex operator+(const complex& complex_one) const
	{
		//complex added_complex{ real_component() + complex_one.real_component(), im_component() + complex_one.im_component() };
		complex added_complex{ real + complex_one.real_component(), im + complex_one.im_component() };
		return added_complex;
	}
	// Overload - operator for subtraction
	complex operator-(const complex& complex_one) const
	{
		complex subtraction_complex{ real - complex_one.real_component(), im - complex_one.im_component() };
		return subtraction_complex;
	}
	// Overload * operator for multiplication
	complex operator*(const complex& complex_one) const
	{
		complex multiplied_complex{ (real*complex_one.real_component()) -(im*complex_one.im_component()), (real*complex_one.im_component()) + (im*complex_one.real_component()) };
		return multiplied_complex;
	}
	// Overload / operator for division first by double and then by complex
	complex operator/(const double &denominator) const 
	{
		complex div_by_double{ real / denominator, im / denominator };
		return div_by_double;
	}
	complex operator/(const complex& complex_one) const
	{
		
		complex divided_complex{(*this) * complex_one.conjugate()/ (complex_one * (complex_one.conjugate())).real_component() };
		return divided_complex;
	}
};

// Function to overload << operator for complex numbers
std::ostream &operator<<(std::ostream& os, const complex &complex_no) 
{
	if (complex_no.im > 0) {
		os << complex_no.real << "+" << complex_no.im << "i";
	}
	else {
		os << complex_no.real << complex_no.im << "i";
	}
	return os;
}
//function to extract complex numbers. overload >> operator
std::istream &operator>>(std::istream &is, complex& complex_no) 
{
	is >> complex_no.real >> complex_no.im;
	return is;
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
	std::cout << "imaginary part of a: " << a.im_component() << "\nimaginary part of b: " << b.im_component()<< std::endl;
	std::cout << "modulus of a: " << a.modulus() << "\nmodulus of b: " << b.modulus() << std::endl;
	std::cout << "argument of a: " << a.argument() << "radians\nargument of b: " << b.argument() << "radians" << std::endl;
	// Get conjugates
	std::cout << "complex conjugate of a: "<< a.conjugate() << std::endl;
	std::cout << "complex conjugate of b: " << b.conjugate() << std::endl;
	// Get sum, difference, product and quotient of a and b
	complex sum = a + b;
	std::cout << "Sum of a and b: " << sum << std::endl;
	complex difference = a - b;
	std::cout << "Difference of a and b: " << difference << std::endl;
	complex product = a * b;
	std::cout << "Product of a and b: " << product << std::endl;
	complex quotient = a/b;
	std::cout << "Quotient of a and b: " << quotient << std::endl;

	//user enter a complex number and overload >> function
	complex entered_complex_number;
	std::cout << "please enter a complex number of the form a +/- bi: ";
	std::cin >> entered_complex_number;
	std::cout << entered_complex_number;

	return 0;
}