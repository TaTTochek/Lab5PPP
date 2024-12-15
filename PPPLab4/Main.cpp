#include <iostream>
#include "Class.h"
#include "Function.h"

using namespace std;

int main() {
    system("chcp 1251");
    system("cls");
    Airport Y;

    string test, wntd;
    float Tcost, Tdiscont;

    do {
        cout << "Список комманд:\n"
            << "1 - Добавить тариф с фиксированной скидкой\n"
            << "2 - Добавить тариф без фиксированной скидкой\n"
            << "3 - Вывести список тарифов\n"
            << "4 - Вывести тариф с максимальной стоимостью\n"
            << "5 - Завершить работу\n"
            << "Введите комманду: ";
        cin >> wntd;
        cout << "\n";

        if (wntd == "1") {
            try {
                cout << "Введите стоимость билета" << endl;
                inputFloat(Tcost);
                cout << "Введите фиксированную скидку" << endl;
                inputFloat(Tdiscont);
                cout << "Введите название направления" << endl;
                cin >> test;
                cin.get();
            }
            catch (int code) {
                if (code == -1) cout << "Значение не входит в диапазон [0; 100000]" << endl;
                else if (code == -2) cout << "Значение некорректно" << endl;
                continue;
            }
            if (Tcost < Tdiscont) {
                cout << "Скидка не может быть больше стоимости" << endl;
                continue;
            }
            Y.addTarif(new DiscontTariff(Tcost, test, Tdiscont));
        }
        else if (wntd == "2") {
            try {
                cout << "Введите стоимость билета" << endl;
                inputFloat(Tcost);
                cout << "Введите название направления" << endl;
                cin >> test;
                cin.get();
            }
            catch (int code) {
                if (code == -1) cout << "Значение не входит в диапазон [0; 100000]" << endl;
                else if (code == -2) cout << "Значение некорректно" << endl;
                continue;
            }
            Y.addTarif(new ClassicTariff(Tcost, test));
        }
        else if (wntd == "3") {
            Y.ShowTariff();
        }
        else if (wntd == "4") {
            Y.GetMaxTariff();
        }
    } while (wntd != "5");

    cout << "\n\n\n\tСПАСИБО ЗА ВНИМАНИЕ\n\n\n";
    return 0;
}
