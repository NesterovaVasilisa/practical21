#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Рекурсивная функция для заполнения квадрата
void fillSquare(vector<vector<char>>& grid, int x1, int y1, int x2, int y2, char texture, int depth = 0) {
    // Базовый случай: если размер квадрата меньше 3x3, просто выходим
    if (x2 - x1 < 2 || y2 - y1 < 2) {
        return;
    }

    // Рисуем границы текущего квадрата
    for (int i = x1; i <= x2; i++) {
        grid[y1][i] = texture;  // Верхняя граница
        grid[y2][i] = texture;  // Нижняя граница
    }
    for (int j = y1; j <= y2; j++) {
        grid[j][x1] = texture;  // Левая граница
        grid[j][x2] = texture;  // Правая граница
    }

    // Рекурсивный вызов для внутреннего квадрата (со смещением на 2)
    fillSquare(grid, x1 + 2, y1 + 2, x2 - 2, y2 - 2, texture, depth + 1);
}

void drawRecursiveSquare(int size, char texture) {
    clearScreen();

    // Вывод шапки программы
    cout << "[ 21 ] Самостоятельная работа | H-" << endl;
    cout << "Тема: [ FOR ]" << endl;
    cout << "Продолжение программы \"Геометрические фигуры\"." << endl;
    cout << endl;
    cout << "[ + ] Программа - \"Геометрические фигуры\"" << endl;
    cout << "----------------------------------------" << endl << endl;

    // Информация о выбранной фигуре
    cout << "[ + ] Фигура: \"Рекурсивный квадрат\"" << endl << endl;
    cout << "[ + ] Размер: \t" << size << endl;
    cout << "[ + ] Текстура: \t" << texture << endl << endl;
    cout << "[ + ] Результат:" << endl << endl;

    // Проверка на минимальный размер
    if (size < 3) {
        cout << "Ошибка: Минимальный размер - 3" << endl;
        return;
    }

    // Проверка на нечетность размера (для симметрии)
    if (size % 2 == 0) {
        cout << "Рекомендуется использовать нечетный размер для лучшего отображения" << endl << endl;
    }

    // Создаем двумерный вектор для хранения символов
    vector<vector<char>> grid(size, vector<char>(size, '.'));

    // Заполняем рекурсивный квадрат
    fillSquare(grid, 0, 0, size - 1, size - 1, texture);

    // Выводим результат
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << grid[i][j];
            // Добавляем разделители (5 пробелов между символами)
            if (j < size - 1) {
                cout << "     ";
            }
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    clearScreen();

    // Главное меню
    cout << "[ 21 ] Самостоятельная работа | H-" << endl;
    cout << "Тема: [ FOR ]" << endl;
    cout << "Продолжение программы \"Геометрические фигуры\"." << endl;
    cout << endl;
    cout << "[ + ] Программа - \"Геометрические фигуры\"" << endl;
    cout << "----------------------------------------" << endl << endl;

    // Меню выбора фигур
    cout << "Доступные фигуры:" << endl;
    for (int i = 1; i <= 9; i++) {
        cout << "[ " << i << " ] Фигура " << i << endl;
    }
    cout << "[ 10 ] Рекурсивный квадрат" << endl;
    cout << "[ 0 ] Выход" << endl << endl;

    int choice;
    cout << "[ + ] Выберите фигуру: ";
    cin >> choice;

    if (choice == 10) {
        int size;
        char texture;

        cout << "[ + ] Размер: \t";
        cin >> size;

        cout << "[ + ] Текстура: \t";
        cin >> texture;

        drawRecursiveSquare(size, texture);
    }
    else if (choice == 0) {
        cout << "Выход из программы..." << endl;
    }
    else {
        cout << "Фигура №" << choice << " будет реализована позже." << endl;
    }

    return 0;
}
