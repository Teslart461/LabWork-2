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

    // Вычисляем общее количество калорий в меню
    double totalCalories = menu.calculateCalories();
    cout << "Общее количество калорий в меню: " << totalCalories << " ккал\n";

    // Ввод данных о физической активности
    PhysicalActivity activity;
    cout << "Введите данные о физической активности:\n";
    activity.input();
    double caloriesBurned = activity.getCaloriesBurned();
    cout << "Сожжено калорий: " << caloriesBurned << " ккал\n";

    // Вычисляем баланс калорий
    double netCalories = totalCalories - caloriesBurned;
    cout << "Итоговый баланс калорий: " << netCalories << " ккал\n";

return 0:
}
