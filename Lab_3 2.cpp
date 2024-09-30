#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>
#include "MyStructs.h"

// Функция для подсчета калорий одного ингредиента
double calculate_cal(DetailedIngredient ingredient) {
    return (ingredient.ingredient.cal_per_100g * ingredient.ingredient.weight_in_grams) / 100;
}

// Функция для подсчета калорий блюда
double calculate_dish_calories(Dish *dish) {
    double dish_cal = 0;
    for (int i = 0; i < dish->num_ingredients; i++) {
        dish_cal += calculate_cal(dish->ingredients[i]);
    }
    return dish_cal;
}

// Функция для расчета калорий для приема пищи
double calculate_meal_calories(Meal* meal) {
    double meal_cal = 0.0;
    for (int i = 0; i < meal->num_dishes; i++) {
        meal_cal += calculate_dish_calories(&meal->dishes[i]);
    }
    return meal_cal;
}

// Функция для расчета калорий для меню
double calculate_menu_calories(Menu* menu) {
    double menu_cal = 0.0;
    for (int i = 0; i < menu->num_meals; i++) {
        menu_cal += calculate_meal_calories(&menu->meals[i]);
    }
    return menu_cal;
}
