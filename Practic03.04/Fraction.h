#pragma once
#include <iostream>

using namespace std;
/*
Реализуйте класс Дробь. Необходимо хранить числитель
и знаменатель в качестве переменных-членов. Реализуйте
функции-члены для ввода данных в переменные-члены,
для выполнения арифметических операций (сложение,
вычитание, умножение, деление, и т.д.).
*/
class Fraction
{
	int numerator, denominator;

public:
	void InitFract() {
		cout << "введите числитель "; cin >> numerator;
		cout << "введите знаменатель "; cin >> denominator;
	}
	Fraction Add(Fraction f){
		Fraction fract;
		fract.denominator = denominator * f.denominator;
		fract.numerator = numerator * f.denominator + f.numerator * denominator;

		return fract;
	}
	Fraction Sub(Fraction f){
		Fraction fract;
		fract.denominator = denominator * f.denominator;
		fract.numerator = numerator * f.denominator - f.numerator * denominator;

		return fract;
	}
	void Mult(){}
	void Div(){}

	void Show() {
		cout << numerator << "/" << denominator;
	}
};

