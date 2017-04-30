#include "stdafx.h"
using namespace std;
//������� �������
const int N = 4, M = 5;
void _init(int **mass, size_t _x, size_t _y);
void _print(int **mass, size_t _x, size_t _y);
void dinamic_mass_zadanie_1(int **mass, size_t x, size_t y);
void dinamic_mass_zadanie_2(int **mass, size_t x, size_t y);
void _sd_ud(int **mass_a, size_t x, int step);
void dinamic_mass_zadanie_3(int **mass, size_t x, size_t y);
void dinamic_mass_zadanie_4(int **mass, size_t x, size_t y);
void dinamic_mass_zadanie_5(char *user, char *number, size_t size_user, size_t size_number);
void dinamic_mass_zadanie_5_search(char **mass, size_t size_user, size_t size_number);
void dinamic_mass_zadanie_5_change(char **mass, size_t size_user, size_t size_number);
//��������� ������� 1
typedef struct complex_chislo {
	double re;
	double im;
}z;
z summa(z compl1, z compl2) {
	z summ;
	summ.re = compl1.re + compl2.re;
	summ.im = compl1.im + compl2.im;
	return summ;
}
z subtr(z compl1, z compl2) {
	z subt;
	subt.re = compl1.re - compl2.re;
	subt.im = compl1.im - compl2.im;
	return subt;
}
z multi(z compl1, z compl2) {
	z mult;
	mult.re = (compl1.re * compl2.re) - (compl1.im * compl2.im);
	mult.im = (compl1.im * compl2.re) + (compl2.im * compl1.re);
	return mult;
}
z divide(z compl1, z compl2) {
	z divi;
	divi.re = (compl1.re * compl2.re + compl1.im * compl2.im) / (pow(compl2.re, 2) + pow(compl2.im, 2));
	divi.im = (compl1.im * compl2.re - compl2.im * compl1.re) / (pow(compl2.re, 2) + pow(compl2.im, 2));
	return divi;
}
//��������� ������� 2
typedef struct _auto {
	float _long;
	int clearance;
	float engine_displacement;
	int engine_power;
	float diameter_of_wheels;
	char color[25];
	char transmission[25];
};
_auto auto_task_of_values(_auto audi) {
	cout << "������� ������: ";
	cin >> audi._long;
	cout << "������� �������: ";
	cin >> audi.clearance;
	cout << "������� ����� ���������: ";
	cin >> audi.engine_displacement;
	cout << "������� �������� ���������: ";
	cin >> audi.engine_power;
	cout << "������� ������� ����: ";
	cin >> audi.diameter_of_wheels;
	cout << "������� ����: ";
	cin >> audi.color;
	cout << "������� ��� ������� �������: ";
	cin >> audi.transmission;
	return audi;
}
void auto_task_of_display(_auto audi) {
	cout << endl;
	cout << "������: ";
	cout << audi._long;
	cout << endl;
	cout << "�������: ";
	cout << audi.clearance;
	cout << endl;
	cout << "����� ���������: ";
	cout << audi.engine_displacement;
	cout << endl;
	cout << "�������� ���������: ";
	cout << audi.engine_power;
	cout << endl;
	cout << "������� ����: ";
	cout << audi.diameter_of_wheels;
	cout << endl;
	cout << "����: ";
	cout << audi.color;
	cout << endl;
	cout << "��� ������� �������: ";
	cout << audi.transmission;
}
void search(_auto audi) {
	cout << "\n��� �� ������ �����(\n0 - ������,\n1 - �������,\n2 - ����� ���������,\n3 - �������� ���������,\n4 - ������� ����,\n5 - ����,\n6 - ��� ������� �������): ";
	int value = 0;
	cin >> value;
	cout << endl;
	if (value == 0) cout << audi._long;
	else if (value == 1) cout << audi.clearance;
	else if (value == 2) cout << audi.engine_displacement;
	else if (value == 3) cout << audi.engine_power;
	else if (value == 4) cout << audi.diameter_of_wheels;
	else if (value == 5) cout << audi.color;
	else if (value == 6) cout << audi.transmission;
}
//��������� ������� 3
const int number_of_book = 3;
struct library {
	char name[20];
	char author[20];
	char publish[20];
	char genre[20];
};
library inicial_book(library book[number_of_book]) {
	for (int i = 0; i < number_of_book; i++) {
		cout << "������� ��������: ";
		cin >> book[i].name;
		cout << "������� ������: ";
		cin >> book[i].author;
		cout << "������� ������������: ";
		cin >> book[i].publish;
		cout << "������� ����: ";
		cin >> book[i].genre;
	}
	return book[number_of_book];
}
library redact_book(library book[number_of_book]) {
	int name_book = 0;
	cout << "����� ����� �� ������ ���������������: ";
	for (int i = 0; i < number_of_book; i++) {
		cout << "\n " << i << ") " << book[i].name;
	}
	cout << endl << "������� �����: ";
	cin >> name_book;
	cout << endl;
	for (int i = 0; i < number_of_book; i++) {
		if (i == name_book) {
			cout << "������� ��������: ";
			cin >> book[i].name;
		}
	}
	return book[number_of_book];
}
void func_print(library book[number_of_book]) {
	for (int i = 0; i < number_of_book; i++) {
		cout << "��������: " << book[i].name << "\n�����: " << book[i].author << "\n������������: " << book[i].publish << "\n����: " << book[i].genre << endl;
	}
}
void search_in_the_author(library book[number_of_book]) {
	char _author[20];
	cout << "������� ������: ";
	cin >> _author;
	for (int i = 0; i < number_of_book; i++) {
		bool value = true;
		for (int j = 0; j < strlen(_author); j++) {
			if (_author[j] != book[i].author[j]) {
				value = false;
			}
		}
		if (value) {
			cout << "��������: " << book[i].name;
		}
	}
}
void search_in_the_name(library book[number_of_book]) {
	char _name[20];
	cout << "������� ��������: ";
	cin >> _name;
	for (int i = 0; i < number_of_book; i++) {
		bool value = true;
		for (int j = 0; j < strlen(_name); j++) {
			if (_name[j] != book[i].name[j]) {
				value = false;
			}
		}
		if (value) {
			cout << "�����: " << book[i].author;
		}
	}
}
library sort_name(library book[number_of_book]) {
	int d;
	do
	{
		d = 0;
		for (int i = 0; i<number_of_book - 1; i++)
			if (strcmp(book[i].name, book[i + 1].name)>0)
			{
				swap(book[i], book[i + 1]);
				d = 1;
			}
	} while (d);
	return book[number_of_book];
}
library sort_author(library book[number_of_book]) {
	int d;
	do
	{
		d = 0;
		for (int i = 0; i<number_of_book - 1; i++)
			if (strcmp(book[i].author, book[i + 1].author)>0)
			{
				swap(book[i], book[i + 1]);
				d = 1;
			}
	} while (d);
	return book[number_of_book];
}
library sort_publish(library book[number_of_book]) {
	int tmp;
	do
	{
		tmp = 0;
		for (int i = 0; i<number_of_book - 1; i++)
			if (strcmp(book[i].publish, book[i + 1].publish)>0)
			{
				swap(book[i], book[i + 1]);
				tmp = 1;
			}
	} while (tmp);
	return book[number_of_book];
}
//��������� ������� 4
const int number_of_car = 10;
struct car {
	char color[20];
	char model[20];
	char number[20];
};
car inicial_car(car _car[number_of_car]) {
	for (int i = 0; i < number_of_car; i++) {
		cout << "������� ����: ";
		cin >> _car[i].color;
		cout << "������� ������: ";
		cin >> _car[i].model;
		cout << "������� �����: ";
		cin >> _car[i].number;
	}
	return _car[number_of_car];
}
car redact_car(car _car[number_of_car]) {
	int name_car = 0;
	cout << "����� ������ �� ������ ���������������: ";
	for (int i = 0; i < number_of_car; i++) {
		cout << i << " ";
	}
	cout << endl << "������� �����: ";
	cin >> name_car;
	int correct = 0;
	cout << "��� �� ������ ������������� 0) Color 1) Model 2) Number: ";
	cin >> correct;
	if (correct == 0) cin >> _car[name_car].color;
	else if (correct == 1) cin >> _car[name_car].model;
	else if (correct == 2) cin >> _car[name_car].number;
	return _car[number_of_car];
}
void func_print_car(car _car[number_of_car]) {
	for (int i = 0; i < number_of_car; i++) {
		cout << "����: " << _car[i].color << "\n������: " << _car[i].model << "\n�����: " << _car[i].number << endl;
	}
}
void search_by_number(car _car[number_of_car]) {
	char _number[20];
	cout << "������� �����: ";
	cin >> _number;
	for (int i = 0; i < number_of_book; i++) {
		bool value = true;
		for (int j = 0; j < strlen(_number); j++) {
			if (_number[j] != _car[i].number[j]) {
				value = false;
			}
		}
		if (value) {
			cout << "����: " << _car[i].color << " ������: " << _car[i].model;
		}
	}
}
int main(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "RUS");
	//������� �������
	int **mass = new int*[N];
	for (int i = 0; i < N; i++){
			mass[i] = new int[M];
		}
	_init(mass, N, M);
	_print(mass, N, M);
	cout << endl;
	dinamic_mass_zadanie_1(mass, N, M);
	cout << endl;
	dinamic_mass_zadanie_2(mass, N, M);
	cout << endl;
	dinamic_mass_zadanie_3(mass, N, M);
	cout << endl;
	dinamic_mass_zadanie_4(mass, N, M);
	cout << endl;
	for (int **ptr = mass, **end = mass + N; ptr < end; ptr++) delete[] * ptr;
	delete[] mass;
	cout << endl;
	cout << "������� ���: ";
	char *user = new char[255];
	cin >> user;
	cout << "������� �������: ";
	char *number = new char[255];
	cin >> number;
	dinamic_mass_zadanie_5(user, number, strlen(user), strlen(number));
	delete[] user;
	delete[] number;
	cout << endl;
	//��������� ������� 1
	z compl1, compl2;
	cout << "������� ��������� ������� ������������ �����" << endl;
	cin >> compl1.re;
	cin >> compl1.im;
	cout << "������� ��������� ������� ������������ �����" << endl;
	cin >> compl2.re;
	cin >> compl2.im;
	z summ = summa(compl1, compl2);
	z subt = subtr(compl1, compl2);
	z mult = multi(compl1, compl2);
	z divi = divide(compl1, compl2);
	cout << endl;
	//��������� ������� 2
	_auto audi = {0,0,0,0,0,"",""};
	audi = auto_task_of_values(audi);
	cout << endl;
	auto_task_of_display(audi);
	cout << endl;
	search(audi);
	//��������� ������� 3
	library book[number_of_book] = { 0 };
	book[number_of_book] = inicial_book(book);
	cout << endl;
	redact_book(book);
	func_print(book);
	cout << endl;
	search_in_the_author(book);
	cout << endl;
	search_in_the_name(book);
	cout << endl;
	cout << "���������� �� ��������:\n ";
	sort_name(book);
	func_print(book);
	cout << endl;
	cout << "���������� �� ������:\n ";
	sort_author(book);
	func_print(book);
	cout << endl;
	cout << "���������� �� ������������:\n ";
	sort_publish(book);
	func_print(book);
	cout << endl;
	//��������� ������� 4
	car _car[number_of_car] = { 0 };
	_car[number_of_car] = inicial_car(_car);
	cout << endl;
	redact_car(_car);
	func_print_car(_car);
	cout << endl;
	search_by_number(_car);
	cout << endl;
	search_by_number(_car);
	cout << endl;
	system("pause");
	return 0;
}
void _init(int **mass, size_t _x, size_t _y) {
	size_t size = _x * _y;
	for (int i = 0; i < _x; i++) {
		for (int j = 0; j < _y; j++) {
			mass[i][j] = rand() % size;
		}
	}
}
void _print(int **mass, size_t _x, size_t _y) {
	for (int i = 0; i < _x; i++) {
		for (int j = 0; j < _y; j++) {
			printf("%4d", mass[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void dinamic_mass_zadanie_1(int **mass, size_t _x, size_t _y) {
	int index_pos;
	cout << "Enter position(0 to " << M - 1 << "): ";
	cin >> index_pos;
	int counter = 0;
	int **mass_a = new int*[N];
	for (int i = 0; i < N; i++) {
		mass_a[i] = new int[M + 1];
	}
	for (int i = 0; i < N; i++) {
		counter = 0;
		for (int j = 0; j < M + 1; j++) {
			if (counter == index_pos) {
				mass_a[i][counter] = mass[i][j];
				counter++;
				mass_a[i][counter] = mass[i][j];
				counter++;
			}
			else {
				mass_a[i][counter] = mass[i][j];
				counter++;
			}
		}
	}
	_print(mass_a, N, M + 1);
	for (int **ptr = mass_a, **end = mass_a + N; ptr < end; ptr++) delete[] * ptr;
	delete[] mass_a;
}
void dinamic_mass_zadanie_2(int **mass, size_t x, size_t y) {
	int index_pos;
	cout << "Enter position(0 to " << M - 1 << "): ";
	cin >> index_pos;
	int counter = 0;
	int **mass_a = new int*[N];
	for (int i = 0; i < N; i++) {
		mass_a[i] = new int[M - 1];
	}
	for (int i = 0; i < N; i++) {
		counter = 0;
		for (int j = 0; j < M; j++) {
			if (counter == index_pos) {
				mass_a[i][counter] = mass[i][j + 1];
				counter++;
				j++;
			}
			else {
				mass_a[i][counter] = mass[i][j];
				counter++;
			}
		}
	}
	_print(mass_a, N, M - 1);
	for (int **ptr = mass_a, **end = mass_a + N; ptr < end; ptr++) delete[] * ptr;
	delete[] mass_a;
}
void _sd_ud(int **mass_a, size_t x, int step) {
	if (step < 0) {
		_sd_ud(mass_a, x, x + step);
		return;
	}
	char *ptr = new char[step * sizeof(*mass_a)];
	memcpy(ptr, mass_a, step * sizeof(*mass_a));
	memcpy(mass_a, mass_a + step, (x - step) * sizeof(*mass_a));
	memcpy(mass_a + x - step, ptr, step * sizeof(*mass_a));
	delete[] ptr;
}
void dinamic_mass_zadanie_3(int **mass, size_t x, size_t y) {
	int step;
	cout << "Enter step: ";
	cin >> step;
	int counter = 0;
	int **mass_a = new int*[N];
	for (int i = 0; i < N; i++) {
		mass_a[i] = new int[M];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			mass_a[i][j] = mass[i][j];
		}
	}
	_sd_ud(mass_a, N, step);
	_print(mass_a, N, M);
	for (int **ptr = mass_a, **end = mass_a + N; ptr < end; ptr++) delete[] * ptr;
	delete[] mass_a;
}
void dinamic_mass_zadanie_4(int **mass, size_t x, size_t y) {
	int **mass_a = new int*[M];
	for (int i = 0; i < M; i++) {
		mass_a[i] = new int[N];
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			mass_a[i][j] = mass[j][i];
		}
	}
	_print(mass_a, M, N);
	for (int **ptr = mass_a, **end = mass_a + M; ptr < end; ptr++) delete[] * ptr;
	delete[] mass_a;
}
void dinamic_mass_zadanie_5(char *user, char *number, size_t size_user, size_t size_number) {
	char **mass_char = new char*[2];
	for (int i = 0; i < 2; i++) {
		mass_char[i] = new char[255];
	}
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < size_user; j++) {
			mass_char[i][j] = user[j];
		}
	}
	for (int i = 1; i < 2; i++) {
		for (int j = 0; j < size_number; j++) {
			mass_char[i][j] = number[j];
		}
	}
	dinamic_mass_zadanie_5_search(mass_char, size_user, size_number);
	cout << endl;
	dinamic_mass_zadanie_5_change(mass_char, size_user, size_number);
}
void dinamic_mass_zadanie_5_search(char **mass, size_t size_user, size_t size_number) {
	int value;
	bool search = true;
	cout << "������ ��� �� ������(0) ��� ����� �� �����(1): ";
	cin >> value;
	if (value == 0) {
		char *search_number = new char[255];
		cout << "������� �����: ";
		cin >> search_number;
		for (int i = 1; i < 2; i++) {
			for (int j = 0; j < size_number; j++) {
				if (search_number[j] != mass[i][j]) {
					search = false;
				}
			}
			if (search) {
				for (int i = 0; i < 1; i++) {
					cout << "���: ";
					for (int j = 0; j < size_user; j++) {
						cout << mass[i][j];
					}
				}
		}
			else {
				cout << "No found";
			}
		}
		delete[] search_number;
	}
	else {
		char *search_user = new char[255];
		cout << "������� ���: ";
		cin >> search_user;
		for (int i = 0; i < 1; i++) {
			for (int j = 0; j < size_user; j++) {
				if (search_user[j] != mass[i][j]) {
					search = false;
				}
			}
			if (search) {
				cout << "�����: ";
				for (int i = 1; i < 2; i++) {
					for (int j = 0; j < size_number; j++) {
						cout << mass[i][j];
					}
				}
			}
			else {
				cout << "No found";
			}
		}
		delete[] search_user;
	}
}
void dinamic_mass_zadanie_5_change(char **mass, size_t size_user, size_t size_number) {
	int value;
	cout << "��� ���� ��������(��� - 1, ����� - 0): ";
	cin >> value;
	if (value) {
		char *change_name = new char[255];
		cout << "������� ���������: ";
		cin >> change_name;
		for (int i = 0; i < 1; i++) {
			for (int j = 0; j < size_user; j++) {
				mass[i][j] = change_name[j];
			}
		}
		for (int i = 0; i < 1; i++) {
			cout << "���: ";
			for (int j = 0; j < size_user; j++) {
				cout << mass[i][j];
			}
		}
		delete[] change_name;
	}
	else {
		char *change_number = new char[255];
		cout << "������� ���������: ";
		cin >> change_number;
		for (int i = 1; i < 2; i++) {
			for (int j = 0; j < size_number; j++) {
				mass[i][j] = change_number[j];
			}
		}
		cout << "�����: ";
		for (int i = 1; i < 2; i++) {
			for (int j = 0; j < size_number; j++) {
				cout << mass[i][j];
			}
		}
		delete[] change_number;
	}
}

