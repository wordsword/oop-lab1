// GolubovychLab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
	string name;
	
	int oop;
	int high_math;
	int it;
	int english;
	int discr_math;
};

int main()
{
	setlocale(LC_ALL, "Ukrainian");
	int count;

	cout << "Введіть кількість студентів: ";
	cin >> count;

	Student *students = new Student[count];


	fstream file;

	for (int i = 1; i <= count; i++) {
		Student stud;

		cout << "Введіть інформацію про студента №" << i << ":" << endl;
		cout << "Ім'я: ";
		cin >> stud.name;


		cout << "Оцінка за іспит з ООП: ";
		cin >> stud.oop;


		cout << "Оцінка за іспит з вищої математики: ";
		cin >> stud.high_math;


		cout << "Оцінка за іспит з інформаційних технологій: ";
		cin >> stud.it;


		cout << "Оцінка за іспит з англійської: ";
		cin >> stud.english;


		cout << "Оцінка за іспит з дискретної математики: ";
		cin >> stud.discr_math;

		students[i - 1] = stud;

		cout << endl << endl;
	}

	file.open("info.dat", ios::out);

	for (int i = 0; i < count; i++) {
		file.write((char *)&students[i], sizeof(Student));
	}
	
	file.close();

	file.open("info.dat", ios::in);

	cout << "Список студентів, що отримали оцінку \"відмінно \":" << endl;

	

	for (int i = 0; i < count; i++) {
		Student stud;
		file.read((char *)&stud, sizeof(Student));
		
		if (stud.discr_math > 4 || stud.english > 4 || stud.high_math > 4 || stud.it > 4 || stud.oop > 4) {
			cout << stud.name << endl;
		}
	}

	system("pause");
    return 0;
}

