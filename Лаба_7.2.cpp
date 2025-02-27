#include <iostream>
#include <clocale>
#include <cmath>
#include <cstdarg>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
using namespace std;

double alfa(int n, ...)
{
    va_list side;
    va_start(side, n);
    double alfa = 60.0;
    if (n == 3)
    {
        int si[3];
        for (int i = 0; i < n; i++)
            si[i] = va_arg(side, int);
        va_end(side);

        // Проверка на существование треугольника
        if (si[0] + si[1] > si[2] && si[1] + si[2] > si[0] && si[0] + si[2] > si[1])
        {
            if (si[0] == si[1] && si[1] == si[2])
                return alfa;
            else
            {
                alfa = acos((pow(si[0], 2) + pow(si[1], 2) - pow(si[2], 2)) / (2.0 * si[0] * si[1]));
                alfa = alfa * 180.0 / M_PI; // Перевод радиан в градусы
                return alfa;
            }
        }
        else
        {
            cout << "Треугольник с такими сторонами не существует." << endl;
            return -1; // Возвращаем -1 в случае ошибки
        }
    }
    else
    {
        alfa = 180.0 * (n - 2) / n;
        return alfa;
    }
}

int main()
{
    setlocale(0, "");
    cout << "Угол в правильном треугольнике = " << alfa(3, 5, 5, 5) << " градусов" << endl;
    cout << "Прямой угол в прямоугольном треугольнике = " << alfa(3, 3, 4, 5) << " градусов" << endl;
    cout << "Другой угол в прямоугольном треугольнике = " << alfa(3, 10, 8, 9) << " градусов" << endl;
    cout << "Угол в неправильном треугольнике = " << alfa(3, 2, 3, 4) << " градусов" << endl;
    cout << "Треугольник со сторонами 1, 2, 3: " << alfa(3, 1, 2, 3) << endl;
    cout << "Угол в 9-угольнике = " << alfa(9) << " градусов" << endl;
    cout << "Угол в 11-угольнике = " << alfa(11) << " градусов" << endl;
    return 0;
}