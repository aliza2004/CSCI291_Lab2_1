#include <stdio.h>

#define ESPRESSO_BEANS 8 // grams
#define ESPRESSO_WATER 30 // milliliters

#define CAPPUCCINO_BEANS 8 // grams
#define CAPPUCCINO_WATER 30 // milliliters
#define CAPPUCCINO_MILK 70 // milliliters

#define MOCHA_BEANS 8 // grams
#define MOCHA_WATER 30 // milliliters
#define MOCHA_MILK 70 // milliliters
#define MOCHA_SYRUP 30 // milliliters

#define PRICE_ESPRESSO 3.5 // AED
#define PRICE_CAPPUCCINO 4.5 // AED
#define PRICE_MOCHA 5.5 // AED

#define ADMIN_PASSWORD 1234

#define THRESHOLD_BEANS 10
#define THRESHOLD_WATER 50
#define THRESHOLD_MILK 100
#define THRESHOLD_SYRUP 20

int beans = 100;
int water = 500;
int milk = 300;
int syrup = 100;

float total_amount = 0;

void order_coffee() {
    printf("Ordering coffee.\n");
}

void admin_mode() {
    printf("Admin mode.\n");
}

void display_ingredients() {
    printf("Ingredients:\n");
    printf("Beans: %d grams\n", beans);
    printf("Water: %d ml\n", water);
    printf("Milk: %d ml\n", milk);
    printf("Syrup: %d ml\n", syrup);
}

void refill_ingredients() {
}

void process_payment(float price) {
}

int main() {
    int choice;

    while (1) {
        printf("\nCoffee Menu:\n");
        printf("1. Order a coffee\n");
        printf("2. Admin mode\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                order_coffee();
                break;
            case 2:
                admin_mode();
                break;
            case 3:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid, please try again.\n");
        }
    }
}
