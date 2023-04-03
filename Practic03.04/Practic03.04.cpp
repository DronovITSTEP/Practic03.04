#include <iostream>
#include "Fraction.h"
#include "PhoneBook.h"
#include "String.h"

int main()
{
    setlocale(LC_ALL, "");
 /*   Fraction fraction1;
    Fraction fraction2;
    fraction1.InitFract();
    fraction2.InitFract();
    Fraction fraction3 = fraction1.Add(fraction2);
    fraction3.Show();
    fraction3 = fraction1.Sub(fraction2);
    fraction3.Show();*/

    /*PhoneBook p{ "Ivanov I.I", "+1111111", "+222222", "+333333", "information" };
    p.Print();
    PhoneBook::SaveFile(&p, 1);

    PhoneBook** p = PhoneBook::LoadFile();
    for (int i = 0; i < 2; i++) {
        p[i]->Print();
    }*/

    String str;
    str.Add();
    String str1{ "qwerty" };
    String str2{ 20 };
    str2.Add();

    str.Print();
    str1.Print();
    str2.Print();

    cout << String::count;
}


