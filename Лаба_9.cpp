#include <iostream>
#include <clocale>
#include <string>
#include <sstream>
#include <fstream>
#include <Windows.h>
using namespace std;

bool check(const string& str)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	istringstream ss(str);
	string first, w;
	ss >> first;

	while (ss >> w)
		if (w == first)
			return true;
	return false;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream file1("C:\\Users\\user\\Desktop\\C++\\Лаба_9\\F1.txt");
	ofstream file2("C:\\Users\\user\\Desktop\\C++\\Лаба_9\\F2.txt");

	if (!file1.is_open()) 
	{
		cout << "Не удалось открыть файл!" << endl;
		return 1;
	}
	if (!file2.is_open()) 
	{
		cout << "Не удалось открыть файл!" << endl;
		return 1;
	}
	
	string str, last;
	while (!file1.eof())
	{
		getline(file1, str);
		if (check(str))
		{
			file2 << str << '\n';
			last = str;
		}
	}
	file1.close();
	
	int n = last.length();
	string alf = "цкнгшщзхфвпрлджчсмтб";
	int m = alf.length();
	int count = 0;
	cout<< "Последняя строка в файле F2: " << last << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (last[i] == alf[j])
				count += 1;
	cout << "Количество согласных букв в последней строке = " << count;
	file2.close();
	return 0;
}