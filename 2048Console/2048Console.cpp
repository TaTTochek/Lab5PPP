//#include <iostream>
//#include <Windows.h>
//#include <time.h>
////#include <cstdlib>
////#include <ctime>
//
//using namespace std;
//const unsigned int GridSize = 3;
//
//
//int getRandomNumber() {
//    int randomValue = rand() % 100;
//
//    // Если число меньше 90, возвращаем 2, иначе возвращаем 4
//    return (randomValue < 90) ? 2 : 4;
//}
//
//
//// клетка игры 2048
//class cell {
//private:
//    unsigned int value : 11;
//
//public: 
//    cell() : value(0)  {};
//
//    void setValue(int valu) { value = valu; };
//    int getValue() { return value; };
//};
//
//// основное поле игры 2048
//class mainGame2048 {
//private:
//    cell** MainGrid;
//
//    void initializedCell() {
//        for (int i = 0; i < GridSize; i++) {
//            for (int j = 0; j < GridSize; j++) {
//                //MainGrid[i][j].setValue(rand() % 3);//rand() % 3;
//                MainGrid[i][j].setValue(0);
//            }
//        }
//        new_number(MainGrid);
//        new_number(MainGrid);
//    }
//
//    int sumGrid() {
//        int temp = 0;
//        for (int i = 0; i < GridSize; i++) {
//            for (int j = 0; j < GridSize; j++) {
//                temp += MainGrid[i][j].getValue();
//            }
//        }
//        return temp;
//    }
//
//public:
//    mainGame2048() { 
//        MainGrid = new cell* [GridSize];
//        for (int i = 0; i < GridSize; i++) {
//            MainGrid[i] = new cell[GridSize];
//        }
//        initializedCell();
//    }
//
//    // - Складывание строк
//    void squash_array(cell col[GridSize], bool key)
//    {
//        if (key) {
//            for (int dest = GridSize - 1; dest >= 0; --dest) {
//                int src = dest - 1;
//                while (src >= 0 && col[src].getValue() == 0)
//                    --src;
//                if (src < 0)
//                    break;
//                if (col[dest].getValue() == col[src].getValue()) {
//                    col[dest].setValue(col[dest].getValue() * 2);
//                    col[src].setValue(0);
//                }
//                if (col[dest].getValue() == 0) {
//                    std::swap(col[dest], col[src]);
//                    ++dest;
//                }
//            }
//        }
//        else {
//            for (int dest = 0; dest <= GridSize - 1; ++dest) {
//                int src = dest + 1;
//                while (src <= GridSize - 1 && col[src].getValue() == 0)
//                    ++src;
//                if (src > GridSize - 1)
//                    break;
//                if (col[dest].getValue() == col[src].getValue()) {
//                    col[dest].setValue(col[dest].getValue() * 2);
//                    col[src].setValue(0);
//                }
//                if (col[dest].getValue() == 0) {
//                    std::swap(col[dest], col[src]);
//                    --dest;
//                }
//            }
//        }
//    }
//
//    // - игра завершена или нет
//    bool isGameEnd(cell** grid) {
//        for (int i = 0; i < GridSize; i++) {
//            for (int j = 0; j < GridSize; j++) {
//                if (grid[i][j].getValue() == 0) return false;
//            }
//        }
//        return true;
//    }
//
//
//    void horizontalMove(cell** &grid, bool key) {
//        for (int i = 0; i < GridSize; i++) squash_array(grid[i], key);
//    }
//
//    void verticalMove(cell**& grid, bool key) {
//        cell temp[GridSize][GridSize];
//        for (int i = 0; i < GridSize; i++) {
//            for (int j = 0; j < GridSize; j++) {
//                temp[i][j].setValue(grid[j][i].getValue());
//            }
//        }
//        for (int i = 0; i < GridSize; i++) squash_array(temp[i], key);
//        for (int i = 0; i < GridSize; i++) {
//            for (int j = 0; j < GridSize; j++) {
//                grid[i][j].setValue(temp[j][i].getValue());
//            }
//        }
//    }
//
//
//    // - Сетка игры
//    cell** getGridCell() const {
//        return MainGrid;
//    }
//
//    void displayGrid(cell** &Grid) {
//        for (int i = 0; i < GridSize; i++) {
//            for (int j = 0; j < GridSize; j++) {
//                printf("%d ", Grid[i][j].getValue());
//            }
//            cout << "\n";
//        }
//    }
//
//    void playGame2048(/*cell** &Grid*/) {
//        char input;
//        cell temp[GridSize][GridSize];
//        while (true) {
//            if (isGameEnd(MainGrid)) {
//                cout << "Игра завершена" << endl;
//                cout << "Ваш результат: " << GetScore() << endl;
//                return;
//            }
//            displayGrid(MainGrid);
//            std::cout << "\nEnter move (w: up, s: down, a: left, d: right, q: quit): ";
//            std::cin >> input;
//
//            switch (input) {
//            case 'w': verticalMove(MainGrid, 0);   new_number(MainGrid); break;
//            case 'a': horizontalMove(MainGrid, 0); new_number(MainGrid); break;
//            case 's': verticalMove(MainGrid, 1);   new_number(MainGrid); break;
//            case 'd': horizontalMove(MainGrid, 1); new_number(MainGrid); break;
//            case 'q': std::cout << "Game Over!\n"; return;
//            default: std::cout << "Invalid input. Try again.\n"; continue;
//            }
//            system("cls");
//        }
//    }
//
//
//
//    // - Результат (Score!)
//    int GetScore() {
//        return sumGrid();
//    }
//
//    // - Добавляем результат
//    void new_number(cell**& grid)
//    {
//        while (true) {
//            int x = rand() % GridSize;
//            int y = rand() % GridSize;
//            if (grid[x][y].getValue() == 0) {
//                grid[x][y].setValue(getRandomNumber());
//                return;
//            }
//        }
//    }
//
//    ~mainGame2048() {
//        for (int i = 0; i < GridSize; i++) {
//            delete MainGrid[i];
//        }
//            delete MainGrid;
//    }
//};
//
//
//int main()
//{
//    srand(time(NULL));
//    system("chcp 1251");
//    system("cls");
//
//    mainGame2048 test;
//    test.playGame2048();
//}
//
////HANDLE hWndConsole;
////if (hWndConsole = GetStdHandle(-12)) {
////    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
////    std::cout << "Hello World!\n";
////    if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo)) {
////        int wight = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
////        int lenght = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
////        printf("Ширина: %d\nВысота: %d\n", wight, lenght);
////    }
////}
//
////struct Window {
////    unsigned int w : 7;
////    unsigned int h : 5;
////};
////for (int i = 0; i < 130; i++) {
////    Window gay = { i, i };
////    cout << gay.h << " " << gay.w << endl;
////}
#include "Class.h"
#include "time.h"
#include <Windows.h>
#include <iostream>

int main() {
    srand(time(NULL));
    system("chcp 1251");
    system("cls");

    mainGame2048 game;
    game.playGame2048();
    return 0;
}