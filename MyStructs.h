#ifndef MYSTRUCTS_H
#define MYSTRUCTS_H
#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/ Класс для представления ингредиента
class Ingredient {
private:
    string name;
    double cal_per_100g;
    double weight_in_grams;

public:
    Ingredient();
    ~Ingredient();

    string getName() const;
    double calculateCalories() const;
    void input();

    friend ostream& operator<<(ostream& os, const Ingredient& ingredient);
};

// Класс для представления пищевой ценности    
class NutritionFacts {
private:
    double proteins;
    double fats;
    double carbs;
    double fiber;

public:
    NutritionFacts() : proteins(0), fats(0), carbs(0), fiber(0) {}
    ~NutritionFacts() {}
};

// Класс, используемый для ингредиентов в случае, если необходима пищевая ценность этого продукта   
class DetailedIngredient {
private:
    Ingredient ingredient;
    NutritionFacts nutrition;

public:
    DetailedIngredient();
    ~DetailedIngredient();

    string getName() const;
    double calculateCalories() const;
    void input();

    friend ostream& operator<<(ostream& os, const DetailedIngredient& di);
};

// Класс для представления блюда     
class Dish {
private:
    string name;
    vector<DetailedIngredient> ingredients; // Создание контейнера, для хранения объектов типа DetailedIngredient

public:
    Dish() {
        name = "";
    }

    ~Dish() {

    }

    string getName() const {
        return name;
    }

    void addIngredient(const DetailedIngredient& ingredient);
    double calculateCalories() const;
    void input();
};

// Класс для приёма пищи (завтрак, обед, ужин и т.д.)           
class Meal {
private:
    string name;
    vector<Dish> dishes;

public:
    Meal() {
        name = "";
    }

    ~Meal() {

    }

    string getName() const {
        return name;
    }

    void addDish(const Dish& dish);
    double calculateCalories() const;
    void input();
};

// Класс для меню        
class Menu {
private:
    vector<Meal> meals;

public:
    Menu() {

    }

    ~Menu() {

    }

    void addMeal(const Meal& meal);
    double calculateCalories() const;
    void input();
};

// Класс для представления пользователя               
class User {
private:
    string name;

public:
    User() {
        name = "";
    }

    ~User() {

    }

    string getName() const {
        return name;
    }

    void input();
};

// Класс для учета физической активности              
class PhysicalActivity {
private:
    double calories_burned;

public:
    PhysicalActivity() {
        calories_burned = 0;
    }

    ~PhysicalActivity() {

    }

    double getCaloriesBurned() const {
        return calories_burned;
    }

    void input();
};

#endif // MYSTRUCTS_H
