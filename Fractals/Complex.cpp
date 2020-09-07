#include "Complex.hpp"

#include <cmath>

Complex Complex::operator+(const Complex & other) const
{
	auto sumOfReal = real + other.real;
	auto sumOfImaginary = imaginary + other.imaginary;

	return Complex(sumOfReal, sumOfImaginary);
}

Complex Complex::operator*(const Complex & other) const
{
	auto realPart = real * other.real - imaginary * other.imaginary;
	auto imaginaryPart = real * other.imaginary + imaginary * other.real;

	return Complex(realPart, imaginaryPart);
}

float Complex::abs() const
{
	return std::sqrt(real*real + imaginary*imaginary);
}
