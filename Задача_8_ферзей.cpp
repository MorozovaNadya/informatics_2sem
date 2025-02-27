#include <iostream>
using namespace std;

int board[8][8]; // Шахматная доска
int check(int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        if (board[i][col]) // Проверка горизонтали
            return 0; 
        if (col - row + i >= 0)        // Проверка диагоналей
            if (board[i][col - row + i]) 
                return 0;  
        if (col + row - i < 8) 
            if (board[i][col + row - i])
                return 0;
    }
    return 1;
}
void ris()
{
    cout << "_______________" << endl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << (board[i][j] ? "^^" : "()");
        cout << '\n';
    }
    cout << "---------------" << endl;
}

int vert(int i) // Установка i-й вертикали
{
    if (i == 8) 
        return 1;
    for (int j = 0; j < 8; ++j)
        if (check(i, j))
        {
            board[i][j] = 1;
            ris();
            if (vert(i + 1))
                return 1;
            board[i][j] = 0;
            ris();
        }
    return 0;
}

int main()
{
    vert(0);
    ris();
    return 0;
}
