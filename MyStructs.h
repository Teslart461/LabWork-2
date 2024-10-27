#ifndef MYSTRUCTS_H
#define MYSTRUCTS_H
#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Класс для представления ингредиента
class Ingredient {
private:
    string name;
    double cal_per_100g;
    double weight_in_grams;

public:
    Ingredient() {
        name = "";
        cal_per_100g = 0;
        weight_in_grams = 0;
    }

    ~Ingredient() {
    
    }

    string getName() const {
        return name;
    }

    double calculateCalories() const;
    void input();
};

// Класс для представления пищевой ценности    
class NutritionFacts {
private:
    double proteins;
    double fats;
    double carbs;
    double fiber;

public:
    NutritionFacts() {
        proteins = 0;
        fats = 0;
        carbs = 0;
        fiber = 0;
    }

    ~NutritionFacts() {

    }
};

// Класс, используемый для ингредиентов в случае, если необходима пищевая ценность этого продукта   
class DetailedIngredient {
private:
    Ingredient ingredient;
    NutritionFacts nutrition;

public:
    DetailedIngredient() : ingredient(), nutrition() {}

    ~DetailedIngredient() {

    }

    string getName() const {
        return ingredient.getName();
    }

    double calculateCalories() const;
    void input();
};
