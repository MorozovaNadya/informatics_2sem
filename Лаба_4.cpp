#include <iostream>
#include <clocale>
#include <ctime>
using namespace std;

void  print(int* mas, int n) // Вывод массива
{
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << ' ';
	}
	cout << endl;
}

int* fk1(int* mas, int& n, int& k) // влево
{
	int* nmas = new int[n];
	for (int i = 0; i < n; i++)
	{
		nmas[i] = mas[k - i - 1];
		if ((k - i - 1) < 0)
			nmas[i] = mas[n - i + k - 1];
	}
	delete[] mas;
	return nmas;
}

int* fk2(int* mas, int& n, int& k) // вправо
{
	int* nmas = new int[n];
	for (int i = 0; i < n; i++)
	{
		nmas[i] = mas[i + k - 1];
		if ((i + k - 1) >= n)
			nmas[i] = mas[i - n + k - 1];			
	}
	delete[] mas;
	return nmas;
}

int* add_el(int* mas, int& n, int new_el) // Добавление элементов в конец массива
{
	int* nmas = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		nmas[i] = mas[i];
	}
	n++;
	nmas[n - 1] = new_el;
	delete[] mas;
	return nmas;
}

int main()
{
	setlocale(0, "");
	srand(time(0));
	int n;
	cout << "Введите длину массива: ";
	cin >> n;
	int* mas = new int[n];
	for (int i = 0; i < n; i++)
	{
		mas[i] = rand() % 100 - 50;
	}
	cout << "Начальный массив" << endl;
	print(mas, n);

	int k;
	cout << "Введите номер k (меньше длины массива, но больше 0): ";
	cin >> k;
	mas = fk1(mas, n, k);
	cout << "Массив с k-го элемента по кольцу влево" << endl;
	print(mas, n);

	mas = add_el(mas, n, mas[0]);
	for (int j = 0; j < 3; j++)
	{
		mas = add_el(mas, n, mas[n - 4]);
	}
	cout << "Массив с добавленными элементами" << endl;
	print(mas, n);

	cout << "Введите номер k (меньше длины массива, но больше 0): ";
	cin >> k;
	mas = fk2(mas, n, k);
	cout << "Массив с k-го элемента по кольцу вправо" << endl;
	print(mas, n);
	delete[] mas;
	return 0;
}