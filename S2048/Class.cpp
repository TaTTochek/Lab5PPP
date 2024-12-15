#include "Class.h"
#include "Functions.h"
#include <iostream>
#include <Windows.h>


using namespace std;


// Конструктор по умолчанию
cell::cell() : value(0) {}

// Установить значение
void cell::setValue(int valu) {
    value = valu;
}

// Получить значение
int cell::getValue() const {
    return value;
}



// Конструктор
mainGame2048::mainGame2048() {
    MainGrid = new cell * [GridSize];
    for (int i = 0; i < GridSize; i++) {
        MainGrid[i] = new cell[GridSize];
    }
    initializedCell();
}

// Деструктор
mainGame2048::~mainGame2048() {
    for (int i = 0; i < GridSize; i++) {
        delete[] MainGrid[i];
    }
    delete[] MainGrid;
}

// Инициализация поля
void mainGame2048::initializedCell() {
    for (int i = 0; i < GridSize; i++) {
        for (int j = 0; j < GridSize; j++) {
            MainGrid[i][j].setValue(0);
        }
    }
    new_number(MainGrid);
    new_number(MainGrid);
}

// Сумма всех клеток
int mainGame2048::sumGrid() const {
    int temp = 0;
    for (int i = 0; i < GridSize; i++) {
        for (int j = 0; j < GridSize; j++) {
            temp += MainGrid[i][j].getValue();
        }
    }
    return temp;
}


void mainGame2048::squash_array(cell col[GridSize], bool key)
{
    if (key) {
        for (int dest = GridSize - 1; dest >= 0; --dest) {
            int src = dest - 1;
            while (src >= 0 && col[src].getValue() == 0)
                --src;
            if (src < 0)
                break;
            if (col[dest].getValue() == col[src].getValue()) {
                col[dest].setValue(col[dest].getValue() << 1);
                col[src].setValue(0);
            }
            if (col[dest].getValue() == 0) {
                std::swap(col[dest], col[src]);
                ++dest;
            }
        }
    }
    else {
        for (int dest = 0; dest <= GridSize - 1; ++dest) {
            int src = dest + 1;
            while (src <= GridSize - 1 && col[src].getValue() == 0)
                ++src;
            if (src > GridSize - 1)
                break;
            if (col[dest].getValue() == col[src].getValue()) {
                col[dest].setValue(col[dest].getValue() << 1);
                col[src].setValue(0);
            }
            if (col[dest].getValue() == 0) {
                std::swap(col[dest], col[src]);
                --dest;
            }
        }
    }
}


// Проверка, завершена ли игра
bool mainGame2048::isGameEnd(cell** grid) const {
    for (int i = 0; i < GridSize; i++) {
        for (int j = 0; j < GridSize; j++) {
            if (grid[i][j].getValue() == 0) return false;
        }
    }
    return true;
}

// Вывод поля
void mainGame2048::displayGrid(cell**& Grid) const {
    for (int i = 0; i < GridSize; i++) {
        for (int j = 0; j < GridSize; j++) {
            printf("%d ", Grid[i][j].getValue());
        }
        cout << endl;
    }
}

int mainGame2048::displaycell(int x, int y) {
    return MainGrid[x][y].getValue();
}

// Генерация нового числа на поле
void mainGame2048::new_number(cell**& grid) {
    srand(time(NULL));
    while (true) {
        int x = rand() % GridSize;
        int y = rand() % GridSize;
        if (grid[x][y].getValue() == 0) {
            grid[x][y].setValue(getRandomNumber());
            return;
        }
    }
}

// Движение по горизонтали
void mainGame2048::horizontalMove(cell**& grid, bool key) {
    for (int i = 0; i < GridSize; i++) {
        squash_array(grid[i], key);
    }
}

// Движение по вертикали
void mainGame2048::verticalMove(cell**& grid, bool key) {
    cell temp[GridSize][GridSize];
    for (int i = 0; i < GridSize; i++) {
        for (int j = 0; j < GridSize; j++) {
            temp[i][j].setValue(grid[j][i].getValue());
        }
    }
    for (int i = 0; i < GridSize; i++) squash_array(temp[i], key);
    for (int i = 0; i < GridSize; i++) {
        for (int j = 0; j < GridSize; j++) {
            grid[i][j].setValue(temp[j][i].getValue());
        }
    }
}

// Основной цикл игры
void mainGame2048::playGame2048() {
    char input;
    while (true) {
        if (isGameEnd(MainGrid)) {
            cout << "Игра завершена" << endl;
            cout << "Ваш результат: " << GetScore() << endl;
            return;
        }
        displayGrid(MainGrid);
        cout << "\nEnter move (w: up, s: down, a: left, d: right, q: quit): ";
        cin >> input;

        switch (input) {
        case 'w': verticalMove(MainGrid, 0); new_number(MainGrid); break;
        case 'a': horizontalMove(MainGrid, 0); new_number(MainGrid); break;
        case 's': verticalMove(MainGrid, 1); new_number(MainGrid); break;
        case 'd': horizontalMove(MainGrid, 1); new_number(MainGrid); break;
        case 'q': cout << "Game Over!\n"; return;
        default: cout << "Invalid input. Try again.\n"; continue;
        }
        system("cls");
    }
}
char mainGame2048::playGame2048(char a) {
    if (isGameEnd(MainGrid)) {
        return 'L';
    }

        switch (a) {
        case 'w': verticalMove(MainGrid, 0); new_number(MainGrid); break;
        case 'a': horizontalMove(MainGrid, 0); new_number(MainGrid); break;
        case 's': verticalMove(MainGrid, 1); new_number(MainGrid); break;
        case 'd': horizontalMove(MainGrid, 1); new_number(MainGrid); break;
        case 'q': return 'L';
        default:  return 'N';
        
    }
}

// Результат
int mainGame2048::GetScore() const {
    return sumGrid();
}
