#include "MyStructs.h"
#include <limits>

using namespace std;

Ingredient::Ingredient() : name(""), cal_per_100g(0), weight_in_grams(0) {}
Ingredient::~Ingredient() {}

string Ingredient::getName() const { return name; }

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

ostream& operator<<(ostream& os, const Ingredient& ingredient) {
    os << "Ингредиент: " << ingredient.getName() << " (калорийность: " << ingredient.calculateCalories() << " ккал)";
    return os;
}

DetailedIngredient::DetailedIngredient() : ingredient(), nutrition() {}
DetailedIngredient::~DetailedIngredient() {}

string DetailedIngredient::getName() const { return ingredient.getName(); }

double DetailedIngredient::calculateCalories() const { return ingredient.calculateCalories(); }

void DetailedIngredient::input() { ingredient.input(); }

ostream& operator<<(ostream& os, const DetailedIngredient& di) {
    os << di.ingredient;
    return os;
}

Dish::Dish() : name("") {}
Dish::Dish(const Dish& other) : name(other.name), ingredients(other.ingredients) {}

Dish& Dish::operator=(const Dish& other) {
    if (this == &other) return *this;
    name = other.name;
    ingredients = other.ingredients;
    return *this;
}

void Dish::addIngredient(const DetailedIngredient& ingredient) {
    ingredients.push_back(ingredient);
}

double Dish::calculateCalories() const {
    double total_cal = 0;
    for (const auto& ingredient : ingredients) {
        total_cal += ingredient.calculateCalories();
    }
    return total_cal;
}

void Dish::input() {
    cout << "Введите название блюда: ";
    cin >> name;
    int numIngredients;
    cout << "Введите количество ингредиентов в блюде: ";
    while (!(cin >> numIngredients)) {
        cout << "Ошибка ввода. Пожалуйста, введите целое число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    for (int i = 0; i < numIngredients; ++i) {
        DetailedIngredient ingredient;
        cout << "Ингредиент " << (i + 1) << ":\n";
        ingredient.input();
        addIngredient(ingredient);
    }
}

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

Menu::Menu() { menuCount++; }
Menu::~Menu() { menuCount--; }

int Menu::getMenuCount() { return menuCount; }

void Menu::addMeal(const Meal& meal) { meals.push_back(meal); }

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

    try {
        if (numMeals < 0) throw invalid_argument("Количество приемов пищи не может быть отрицательным.");

        for (int i = 0; i < numMeals; ++i) {
            Meal meal;
            cout << "Прием пищи " << (i + 1) << ":\n";
            meal.input();
            addMeal(meal);
        }
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
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
