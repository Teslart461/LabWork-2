#include "MyStructs.h"
#include <algorithm> // Для std::sort и std::find_if
#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Реализация методов Ingredient
double Ingredient::calculateCalories() const {
    return (cal_per_100g * weight_in_grams) / 100.0;
}

string Ingredient::getName() const {return name;}

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

// Реализация методов DetailedIngredient
double DetailedIngredient::calculateCalories() const {
    return ingredient.calculateCalories();
}

string DetailedIngredient::getName() const {
    return ingredient.getName();
}

void DetailedIngredient::input() {
    ingredient.input();
}

// Реализация методов Dish
Dish::Dish() : name("") {}
Dish::~Dish() {}

void Dish::addIngredient(const shared_ptr<FoodItem>& ingredient) {
    ingredients.push_back(ingredient);
}

double Dish::calculateCalories() const {
    double total_cal = 0;
    for (const auto& ingredient : ingredients) {
        total_cal += ingredient->calculateCalories();
    }
    return total_cal;
}

void Dish::input() {
    cout << "Введите название блюда: ";
    cin >> name;
    int numIngredients;
    cout << "Введите количество ингредиентов: ";
    while (!(cin >> numIngredients)) {
        cout << "Ошибка ввода. Пожалуйста, введите целое число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    for (int i = 0; i < numIngredients; ++i) {
        shared_ptr<FoodItem> ingredient = make_shared<Ingredient>();
        ingredient->input();
        addIngredient(ingredient);
    }
}

string Dish::getName() const {return name;}

Meal::Meal() : name("") {}
Meal::~Meal() {}

void Meal::addDish(const Dish& dish) {
    dishes.push_back(dish);
}

double Meal::calculateCalories() const {
    double total_cal = 0;
    for (const auto& dish : dishes) {
        total_cal += dish.calculateCalories();
    }
    return total_cal;
}

void Meal::input() {
    cout << "Введите название приема пищи: ";
    cin >> name;
    int numDishes;
    cout << "Введите количество блюд на этом приеме пищи: ";
    while (!(cin >> numDishes)) {
        cout << "Ошибка ввода. Пожалуйста, введите целое число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    for (int i = 0; i < numDishes; ++i) {
        Dish dish;
        cout << "Блюдо " << (i + 1) << ":\n";
        dish.input();
        addDish(dish);
    }
}

string Meal::getName() const {return name;}

Menu::Menu() {}
Menu::~Menu() {}

void Menu::addMeal(const Meal& meal) {
    meals.push_back(meal);
}

double Menu::calculateCalories() const {
    double total_cal = 0;
    for (const auto& meal : meals) {
        total_cal += meal.calculateCalories();
    }
    return total_cal;
}


void Menu::input() {
    int numMeals;
    cout << "Введите количество приемов пищи в меню: ";
    while (!(cin >> numMeals)) {
        cout << "Ошибка ввода. Пожалуйста, введите целое число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    for (int i = 0; i < numMeals; ++i) {
        Meal meal;
        cout << "Прием пищи " << (i + 1) << ":\n";
        meal.input();
        addMeal(meal);
    }
}

void Menu::sortMealsByCalories() {
    sort(meals.begin(), meals.end(), [](const Meal& a, const Meal& b) {
        return a.calculateCalories() < b.calculateCalories();
        });
}

const Meal* Menu::findMealByName(const string& name) const {
    auto it = find_if(meals.begin(), meals.end(), [&name](const Meal& meal) {
        return meal.getName() == name;
        });
    return it != meals.end() ? &(*it) : nullptr;
}

void Menu::print() const {
    for (const auto& meal : meals) {
        cout << meal.getName() << " (калорийность: " << meal.calculateCalories() << " ккал)\n";
    }
}

User::User() : name("") {}
User::~User() {}

string User::getName() const { return name; }

void User::input() {
    cout << "Введите имя пользователя: ";
    cin >> name;
}

PhysicalActivity::PhysicalActivity() : calories_burned(0) {}
PhysicalActivity::~PhysicalActivity() {}

double PhysicalActivity::getCaloriesBurned() const { return calories_burned; }

void PhysicalActivity::input() {
    cout << "Введите количество сожженных калорий за физическую активность: ";
    while (!(cin >> calories_burned)) {
        cout << "Ошибка ввода. Пожалуйста, введите число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
