#ifndef MYSTRUCTS_H
#define MYSTRUCTS_H
#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Базовый класс для всех пищевых элементов
class FoodItem {
public:
    virtual ~FoodItem() = default;
    virtual double calculateCalories() const = 0;
    virtual string getName() const = 0;
    virtual void input() = 0;
};

// Производный класс Ingredient
class Ingredient : public FoodItem {
private:
    string name;
    double cal_per_100g;
    double weight_in_grams;

public:
    Ingredient() : name(""), cal_per_100g(0), weight_in_grams(0) {}
    ~Ingredient() override {}

    double calculateCalories() const override;
    string getName() const override;
    void input() override;
};

// Производный класс DetailedIngredient
class DetailedIngredient : public FoodItem {
private:
    Ingredient ingredient;

public:
    DetailedIngredient() : ingredient() {}
    ~DetailedIngredient() override {}

    double calculateCalories() const override;
    string getName() const override;
    void input() override;
};

// Класс для представления блюда     
class Dish {
private:
    string name;
    vector<shared_ptr<FoodItem>> ingredients;

public:
    Dish();
    ~Dish();

    void addIngredient(const shared_ptr<FoodItem>& ingredient);
    double calculateCalories() const;
    void input();
    string getName() const;
};

// Класс для приёма пищи (завтрак, обед, ужин и т.д.)           
class Meal {
private:
    string name;
    vector<Dish> dishes;

public:
    Meal();
    ~Meal();

    void addDish(const Dish& dish);
    double calculateCalories() const;
    void input();
    string getName() const;
};

// Класс для меню
class Menu {
private:
    vector<Meal> meals;

public:
    Menu();
    ~Menu();

    void addMeal(const Meal& meal);
    double calculateCalories() const;
    void input();
    void sortMealsByCalories();
    const Meal* findMealByName(const string& name) const;
    void print() const;
};

// Класс для представления пользователя               
class User {
private:
    string name;

public:
    User();
    ~User();

    string getName() const;
    void input();
};

// Класс для учета физической активности              
class PhysicalActivity {
private:
    double calories_burned;

public:
    PhysicalActivity();
    ~PhysicalActivity();

    double getCaloriesBurned() const;
    void input();
};

#endif // MYSTRUCTS_H
