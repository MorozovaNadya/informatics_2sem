#include <iostream>
#include <ctime>
#include <clocale>
using namespace std;

void print(string* matr, int& n, int k)
{
	for (int i = 0; i < n; i++)
	{
		if (i != k - 1)
			cout << matr[i] << endl;
		else continue;
	}
}

int main()
{
	setlocale(0, "");
	srand(time(0));
	int n;
	string s;
	cout << "Введите размер массива: ";
	cin >> n;
	string* matr = new string[n];
	cout << "Вводите сстроки массива (через enter)" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		matr[i] = s;
	}

	int k;
	cout << "Введите номер строки, который необходимо удалить: ";
	cin >> k;
	string* nmatr = new string[n];
	for (int i = 0; i < n; i++)
	{
		if (i != k - 1)
			nmatr[i] = matr[i];
		else continue;
	}
	delete[] matr;

	cout << "Конечная матрица:" << endl;
	print(nmatr, n, k);
	delete[] nmatr;
	return 0;
}