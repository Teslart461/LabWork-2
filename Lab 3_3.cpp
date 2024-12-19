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

    // Сортировка меню по калориям
    menu.sortMealsByCalories();
    cout << "\nМеню после сортировки приемов пищи по калорийности:\n";
    menu.print();
    
    // Поиск приема пищи по имени
    string searchName;
    cout << "\nВведите название приема пищи для поиска: ";
    cin >> searchName;
    const Meal* foundMeal = menu.findMealByName(searchName);
    if (foundMeal) {
        cout << "Прием пищи найден: " << foundMeal->getName() << "\n";
        cout << "Калорийность приема пищи: " << foundMeal->calculateCalories() << " ккал\n";
    }
    else {
        cout << "Прием пищи не найден.\n";
    }
    
    double totalCalories = menu.calculateCalories();
    cout << "Общее количество калорий в меню: " << totalCalories << " ккал\n";
    
    PhysicalActivity activity;
    cout << "Введите данные о физической активности:\n";
    activity.input();
    double caloriesBurned = activity.getCaloriesBurned();
    cout << "Сожжено калорий: " << caloriesBurned << " ккал\n";
    
    double netCalories = totalCalories - caloriesBurned;
    cout << "Итоговый баланс калорий: " << netCalories << " ккал\n";
    
    return 0;
}
