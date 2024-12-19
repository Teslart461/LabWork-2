#include "MyStructs.h"
#include <iostream>
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

    // Создаем меню
    Menu menu;
    cout << "Создание меню:\n";
    menu.input();
    
    return 0;
}
