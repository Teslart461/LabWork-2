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
    Ingredient ingredient;       
    NutritionFacts nutrition;    
} DetailedIngredient;

// Структура для представления блюда
typedef struct {
    char name[50];                
    DetailedIngredient ingredients[20];  
    int num_ingredients;          
} Dish;

// Структура для приёма пищи (завтрак, обед, ужин и т.д.)
typedef struct {
    char name[30];                
    Dish dishes[20];             
    int num_dishes;              
} Meal;

// Структура для меню
typedef struct {
    Meal meals[5];  
    int num_meals;          
} Menu;

// Структура для представления пользователя
typedef struct {
    char name[50];                
} User;

#endif // MYSTRUCTS_H
