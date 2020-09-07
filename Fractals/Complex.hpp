#pragma once
class Complex
{
public:
	Complex() : real(0), imaginary(0) {}
	Complex(float real, float imaginary) : real(real), imaginary(imaginary) {}

	Complex operator+(const Complex& other) const;
	Complex operator*(const Complex& other) const;
	float abs() const;

	float real;
	float imaginary;
};

