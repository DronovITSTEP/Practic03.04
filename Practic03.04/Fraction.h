#pragma once
#include <iostream>

using namespace std;
/*
���������� ����� �����. ���������� ������� ���������
� ����������� � �������� ����������-������. ����������
�������-����� ��� ����� ������ � ����������-�����,
��� ���������� �������������� �������� (��������,
���������, ���������, �������, � �.�.).
*/
class Fraction
{
	int numerator, denominator;

public:
	void InitFract() {
		cout << "������� ��������� "; cin >> numerator;
		cout << "������� ����������� "; cin >> denominator;
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

