#include <iostream>
#include <clocale>
#include <ctime>
using namespace std;

int count(int* mas, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (mas[i] < 0)
			count += 1;
	return count;
}

int count(string* mas, int n)
{
	int count = 0;
	int l;
	for (int i = 0; i < n; i++)
	{
		l = mas[i].size();
		if (mas[i][0] == mas[i][l-1])
			count += 1;
	}
	return count;
}

int main()
{
	setlocale(0, "");
	srand(time(0));
	int n;
	cout << "Введите длину массива: ";
	cin >> n;
	int* dig = new int[n];
	for (int i = 0; i < n; i++)
		dig[i] = rand() % 100 - 50;
	cout << "Начальный массив" << endl;
	for (int i = 0; i < n; i++)
		cout << dig[i] << ' ';
	cout << endl;
	cout << "Количество отрицательных чисел = " << count(dig, n) << endl;

	cout << "Введите количество слов: ";
	cin >> n;
	cout << "Вводите строку" << endl;
	string* str = new string[n];
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		str[i] = s;
	}
	cout << "Количество слов, с одинаковой буквой в конце и в начале = " << count(str, n) << endl;
	return 0;
}