#include "MyStructs.h"
#include <iostream>
#include <limits>
#include <locale.h>

using namespace std;

    int main() {
        setlocale(LC_ALL, "RUS");

        // Создаем пользователя
        User user;
        cout << "Введите данные пользователя:\n";
        user.input();
        cout << "Привет, " << user.getName() << "!\n";

        cout << "\nСейчас будет продемонстрирована работа с динамическим массив данных\n";

        // Работа с динамическим массивом объектов класса Meal
        int numMeals;
        cout << "Введите количество приемов пищи: ";
        while (!(cin >> numMeals)) {
            cout << "Ошибка ввода. Пожалуйста, введите число.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Создаем динамический массив объектов класса Meal
        Meal* mealsArray = new Meal[numMeals];
        for (int i = 0; i < numMeals; ++i) {
            cout << "Введите информацию о приеме пищи " << (i + 1) << ":\n";
            mealsArray[i].input();
        }

        // Подсчет калорий для каждого приема пищи
        for (int i = 0; i < numMeals; ++i) {
            cout << "Калории в приеме пищи " << (i + 1) << ": " << mealsArray[i].calculateCalories() << " ккал\n";
        }

        // Удаление динамического массива объектов класса Meal
        delete[] mealsArray;

        cout << "\nСейчас будет продемонстрирована работа с массивом динамических данных\n";

        // Работа с массивом динамических объектов класса Dish
        int numDishes;
        cout << "Введите количество блюд: ";
        while (!(cin >> numDishes)) {
            cout << "Ошибка ввода. Пожалуйста, введите целое число.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Создаем массив указателей на объекты класса Dish
        Dish** dishesArray = new Dish * [numDishes];
        for (int i = 0; i < numDishes; ++i) {
            // Создаем каждый объект с помощью new
            dishesArray[i] = new Dish();
            cout << "Введите информацию о блюде " << (i + 1) << ":\n";
            dishesArray[i]->input();
        }

        // Подсчет калорий для каждого блюда
        for (int i = 0; i < numDishes; ++i) {
            cout << "Калории в блюде " << (i + 1) << ": " << (*dishesArray[i]).calculateCalories() << " ккал\n";
        }

        // Удаление массива динамических объектов класса Dish
        for (int i = 0; i < numDishes; ++i) {
            delete dishesArray[i]; // Удаляем каждый объект
        }
        delete[] dishesArray; // Удаляем массив указателей

        return 0;
    }
