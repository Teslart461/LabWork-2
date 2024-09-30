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

void generate_report(User* user, Menu* menu) {
    printf("Отчет о калориях для пользователя: %s\n", user->name);
    printf("-------------------------------------------------\n");

    // Проходим по каждому приему пищи
    for (int i = 0; i < menu->num_meals; i++) {
        Meal* meal = &menu->meals[i];
        double meal_cal = calculate_meal_calories(meal);  // Используем функцию для подсчета калорий приема пищи

        printf("Прием пищи: %s\n", meal->name);
        printf("Калорийность приема пищи: %.2f калорий\n", meal_cal);

        // Проходим по каждому блюду в приеме пищи
        for (int j = 0; j < meal->num_dishes; j++) {
            Dish* dish = &meal->dishes[j];
            double dish_cal = calculate_dish_calories(dish);  // Используем функцию для подсчета калорий блюда

            printf("  Блюдо: %s, Калорийность: %.2f калорий\n", dish->name, dish_cal);
        }
        printf("-------------------------------------------------\n");
    }

    // Подсчитываем и выводим общую калорийность всего меню
    double total_calories = calculate_menu_calories(menu);  // Используем функцию для подсчета калорий меню
    printf("Общие калории за весь день: %.2f калорий\n", total_calories);
}

void input_ingredient(DetailedIngredient* ingredient) {
    printf("Введите название ингредиента: ");
    scanf("%s", ingredient->ingredient.name);

    printf("Введите калории на 100 грамм: ");
    scanf("%lf", &ingredient->ingredient.cal_per_100g);

    printf("Введите вес ингредиента в граммах: ");
    scanf("%lf", &ingredient->ingredient.weight_in_grams);
}

void input_dish(Dish* dish) {
    printf("Введите название блюда: ");
    scanf("%s", dish->name);

    printf("Введите количество ингредиентов в блюде: ");
    scanf("%d", &dish->num_ingredients);

    for (int i = 0; i < dish->num_ingredients; i++) {
        printf("Ингредиент %d:\n", i + 1);
        input_ingredient(&dish->ingredients[i]);
    }
}

void input_meal(Meal* meal) {
    printf("Введите название приема пищи: ");
    scanf("%s", meal->name);

    printf("Введите количество блюд на этом приеме пищи: ");
    scanf("%d", &meal->num_dishes);

    for (int i = 0; i < meal->num_dishes; i++) {
        printf("Блюдо %d:\n", i + 1);
        input_dish(&meal->dishes[i]);
    }
}

void input_menu(Menu* menu) {
    printf("Введите количество приемов пищи в меню: ");
    scanf("%d", &menu->num_meals);

    for (int i = 0; i < menu->num_meals; i++) {
        printf("Прием пищи %d:\n", i + 1);
        input_meal(&menu->meals[i]);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    User user;
    Menu menu;

    printf("Введите имя пользователя: ");
    scanf("%s", user.name);

    input_menu(&menu);

    generate_report(&user, &menu);

}
