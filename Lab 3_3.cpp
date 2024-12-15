#include "MyStructs.h"
#include <iostream>
#include <limits>
#include <Windows.h>


using namespace std;

    int main() {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        // Создаем пользователя
        User user;
        cout << "Введите данные пользователя:\n";
        user.input();
        cout << "Привет, " << user.getName() << "!\n";

        Menu menu;
        menu.input();

        cout << "Текущее количество меню: " << Menu::getMenuCount() << endl;

        return 0;
    }
