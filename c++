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

void fillSquare(vector<vector<char>>& grid, int x1, int y1, int x2, int y2, char texture, int depth = 0) {
    if (x2 - x1 < 2 || y2 - y1 < 2) {
        return;
    }
    
    for (int i = x1; i <= x2; i++) {
        grid[y1][i] = texture;  
        grid[y2][i] = texture;  
    }
    for (int j = y1; j <= y2; j++) {
        grid[j][x1] = texture;  
        grid[j][x2] = texture;  
    }
    
    fillSquare(grid, x1 + 2, y1 + 2, x2 - 2, y2 - 2, texture, depth + 1);
}
void drawRecursiveSquare(int size, char texture) {
    clearScreen();
    
    cout << "[ 21 ] Самостоятельная работа | H-" << endl;
    cout << "Тема: [ FOR ]" << endl;
    cout << "Продолжение программы \"Геометрические фигуры\"." << endl;
    cout << endl;
    cout << "[ + ] Программа - \"Геометрические фигуры\"" << endl;
    cout << "----------------------------------------" << endl << endl;

    cout << "[ + ] Фигура: \"Рекурсивный квадрат\"" << endl << endl;
    cout << "[ + ] Размер: \t" << size << endl;
    cout << "[ + ] Текстура: \t" << texture << endl << endl;
    cout << "[ + ] Результат:" << endl << endl;


    if (size < 3) {
        cout << "Ошибка: Минимальный размер - 3" << endl;
        return;
    }

    
    if (size % 2 == 0) {
        cout << "Рекомендуется использовать нечетный размер для лучшего отображения" << endl << endl;
    }
    
    vector<vector<char>> grid(size, vector<char>(size, '.'));


    fillSquare(grid, 0, 0, size - 1, size - 1, texture);


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << grid[i][j];
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

   
    cout << "[ 21 ] Самостоятельная работа | H-" << endl;
    cout << "Тема: [ FOR ]" << endl;
    cout << "Продолжение программы \"Геометрические фигуры\"." << endl;
    cout << endl;
    cout << "[ + ] Программа - \"Геометрические фигуры\"" << endl;
    cout << "----------------------------------------" << endl << endl;

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
