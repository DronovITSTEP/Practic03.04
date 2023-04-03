#pragma once
#include <iostream>

using namespace std;

/*
Создайте приложение "Телефонная книга". Необходимо
хранить данные об абоненте (ФИО, домашний телефон,
рабочий телефон, мобильный телефон, дополнительная
информация о контакте) внутри соответствующего класса.
Наполните класс переменными-членами, функциями-членами, конструкторами,
inline-функциями-членами,
используйте инициализаторы, реализуйте деструктор.
Обязательно необходимо выделять динамически память
под ФИО. Предоставьте пользователю возможность добавлять новых абонентов,
удалять абонентов, искать абонентов по ФИО, показывать всех абонентов, сохранять
информацию в файл и загружать из файла.
*/

class PhoneBook
{
	char* FIO;
	char* homePhone;
	char* workPhone;
	char* smartPhone;
	char* info;

public:
	// конструктор принимает ФИО, дом.телефон, раб.телефон, моб.телефон и информацию
	PhoneBook(const char* fio, const char* hPhone, const char* wPhone,
		const char* sPhone, const char* i) :
		FIO{ new char[100] },
		homePhone{ new char[15] },
		workPhone{ new char[15] },
		smartPhone{ new char[15] },
		info{ new char[150] }
	{
		strcpy_s(FIO, 100, fio);
		strcpy_s(homePhone, 15, hPhone);
		strcpy_s(workPhone, 15, wPhone);
		strcpy_s(smartPhone, 15, sPhone);
		strcpy_s(info, 150, i);
	}
	PhoneBook():
		FIO{ new char[100] },
		homePhone{ new char[15] },
		workPhone{ new char[15] },
		smartPhone{ new char[15] },
		info{ new char[150] } 
	{}

	~PhoneBook() {
		delete[] FIO;
		delete[] homePhone;
		delete[] workPhone;
		delete[] smartPhone;
		delete[] info;
	}

	void Print() {
		cout << FIO << " " << homePhone << " "
			<< workPhone << " " << smartPhone << " " << info << endl;
	}

	static PhoneBook** LoadFile() {
		FILE* file; 
		char fio[100];
		char hPhone[15];
		char wPhone[15];
		char sPhone[15];
		char info[150];
		PhoneBook** pBooks = new PhoneBook * [5];
		int i = 0;
		if (!fopen_s(&file, "phonebook.txt", "r")) {
			while (!feof(file))
			{
				fscanf_s(file, "%s", fio, 100);
				fscanf_s(file, "%s", hPhone, 15);
				fscanf_s(file, "%s", wPhone, 15);
				fscanf_s(file, "%s", sPhone, 15);
				fscanf_s(file, "%s", info, 150);
				pBooks[i] = new PhoneBook{ fio, hPhone, wPhone, sPhone, info };
				i++;
			}
		}
		fclose(file);

		return pBooks;
	}
	static void SaveFile(PhoneBook* pbook, int size) {
		FILE* file;
		if (!fopen_s(&file, "phonebook.txt", "a")) {
			for (int i = 0; i < size; i++) {
				fprintf_s(file, "%s %s %s %s %s\n",
					pbook[i].FIO, pbook[i].homePhone,
					pbook[i].workPhone, pbook[i].smartPhone,
					pbook[i].info);
			}
		}
		fclose(file);
	}
};

