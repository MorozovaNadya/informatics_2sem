#include <iostream>
#include <clocale>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

// Функция для проверки, соответствует ли слово маске
bool isMatch(const string& word, const string& mask)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    size_t wordPos = 0;  // Позиция в слове
    size_t maskPos = 0;  // Позиция в маске
    size_t starIdx = string::npos; // Хранит индекс последней звезды
    size_t matchIdx = 0; // Хранит индекс совпадения в слове

    while (wordPos < word.size())
    {
        // Если символы совпадают или маска содержит '?'
        if (maskPos < mask.size() && (mask[maskPos] == '?' || mask[maskPos] == word[wordPos])) 
        {
            wordPos++;
            maskPos++;
        }
        // Если встречаем '*', запоминаем положение
        else if (maskPos < mask.size() && mask[maskPos] == '*') 
        {
            starIdx = maskPos;
            matchIdx = wordPos;
            maskPos++;
        }
        // Если не совпало, возвращаемся к последней '*'
        else if (starIdx != string::npos)
        {
            maskPos = starIdx + 1;
            wordPos = ++matchIdx; // Пробуем следующее символ в слове
        }
        else
            return false; // Если символ не совпадает и не осталось '*'
    }
    while (maskPos < mask.size() && mask[maskPos] == '*')   // Пропускаем оставшиеся '*' в маске
        maskPos++;
    return maskPos == mask.size();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(0, "");
    string text, mask;

    cout << "Введите продложение: ";
    getline(cin, text);

    cout << "Введите маску (используйте '*' и '?' ): ";
    getline(cin, mask);

    // Удаляем точку в конце строки, если она есть
    if (!text.empty() && text.back() == '.')
        text.pop_back();

    vector<string> words;  // Список слов
    size_t start = 0;      // Начало текущего слова
    size_t end = text.find('_'); // Позиция символа '_'
    while (end != string::npos) // Разделяем строку на слова по символу '_'
    {
        words.push_back(text.substr(start, end - start));
        start = end + 1;
        end = text.find('_', start);
    }
    // Добавляем последнее слово
    words.push_back(text.substr(start));

    cout << "Слова, подходящие маске: ";
    for (const string& w : words)
        if (isMatch(w, mask))
            cout << w << " ";
    return 0;
}