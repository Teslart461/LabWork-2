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

    // Пример работы с Ingredient и дружественной функцией
    Ingredient sampleIngredient;
    sampleIngredient.input();
    cout << "Проверка дружественной функции: " << sampleIngredient << endl;

    // Пример работы с Dish (конструктор копии и оператор присваивания)
    Dish dish1;
    cout << "Введите данные для первого блюда:\n";
    dish1.input();

    Dish dish2 = dish1;  // Конструктор копии
    cout << "Калорийность блюда dish2 (копия dish1): " << dish2.calculateCalories() << endl;

    Dish dish3;
    cout << "Введите данные для второго блюда:\n";
    dish3.input();

    dish3 = dish1;  // Оператор присваивания
    cout << "Калорийность блюда dish3 (после присваивания dish1): " << dish3.calculateCalories() << endl;
    
    return 0;
}
