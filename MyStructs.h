#ifndef MYSTRUCTS_H
#define MYSTRUCTS_H

// Структура для представления ингредиента
typedef struct {
    char name[50];             
    double cal_per_100g;     
    double weight_in_grams;       
} Ingredient;

// Структура для представления пищевой ценности
typedef struct {
    double proteins;  
    double fats;      
    double carbs;     
    double fiber;     
} NutritionFacts;

// Структура используемая для ингредиентов в случае, если необходима пищевая ценность этого продукта
typedef struct {
    Ingredient ingredient;       // Ингредиент
    NutritionFacts nutrition;    // Пищевая ценность на 100 грамм
} DetailedIngredient;

// Структура для представления блюда
typedef struct {
    char name[50];                // Название блюда
    DetailedIngredient ingredients[20];  // Массив ингредиентов
    int num_ingredients;          // Количество ингредиентов
} Dish;

