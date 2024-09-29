#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>
#include "MyStruct.h"

// Функция для подсчета калорий одного ингредиента
double calculate_cal(Ingredient ingredient) {
    return (ingredient.cal_per_100g * ingredient.weight_in_grams) / 100;
}

// Функция для подсчета калорий блюда
double calculate_dish_calories(Dish dish) {
    double dish_calories = 0;
    for (int i = 0; i < dish.num_ingredients; i++) {
        dish_calories += calculate_cal(dish.ingredients[i].ingredient);
    }
    return dish_calories;
}
