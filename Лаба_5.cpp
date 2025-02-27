#include <iostream>
#include <clocale>
#include <ctime>
using namespace std;

int maxim(int max, int elem1, int elem2)
{
	if (elem1 == elem2)
		if (elem1 > max)
			max = elem1;
	return max;
}

int main()
{
	setlocale(0, "");
	srand(time(0));
	const int n = 7, m = 9;
	int mas[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			mas[i][j] = rand() % 100 - 50;
	}

	cout << "Вывод матрицы:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << mas[i][j] << ' ';
		cout << endl;
	}
	cout << endl;

	int max = -1000;
	for (int i = 0; i < n; i++)
	{
		for (int l = i; l < n; l++)
			for (int j = 0; j < m; j++)
				for (int k = j + 1; k < m; k++)
					max = maxim(max, mas[i][j], mas[l][k]);
	}
	if (max == -1000)
		cout << "Повторяющихся элементов в массиве нет";
	else
		cout << "Максимальный из повторяющихся элементов массива = " << max;
	return 0;
}