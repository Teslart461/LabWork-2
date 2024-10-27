#include "MyStructs.h"
#include <limits>

using namespace std;

double Ingredient::calculateCalories() const {
    return (cal_per_100g * weight_in_grams) / 100.0;
}

void Ingredient::input() {
    cout << "Введите название ингредиента: ";
    cin >> name;
    cout << "Введите калории на 100 грамм: ";
    while (!(cin >> cal_per_100g)) {
        cout << "Ошибка ввода. Пожалуйста, введите число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Введите вес ингредиента в граммах: ";
    while (!(cin >> weight_in_grams)) {
        cout << "Ошибка ввода. Пожалуйста, введите число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double DetailedIngredient::calculateCalories() const {
    return ingredient.calculateCalories();
}

void DetailedIngredient::input() {
    ingredient.input();
}
