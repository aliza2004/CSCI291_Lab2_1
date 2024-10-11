#include <stdio.h>

#define ESPRESSO_BEANS 8 // g
#define ESPRESSO_WATER 30 // mL

#define CAPPUCCINO_BEANS 8 // g
#define CAPPUCCINO_WATER 30 // mL
#define CAPPUCCINO_MILK 70 // mL

#define MOCHA_BEANS 8 // g
#define MOCHA_WATER 30 // mL
#define MOCHA_MILK 70 // ml
#define MOCHA_SYRUP 30 // mL

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

void process_payment(float price) {
    float paid = 0, coin;
    while (paid < price) {
        printf("Insert coin (1 or 0.5 AED): ");
        scanf("%f", &coin);
        if (coin == 1 || coin == 0.5) paid += coin;
        else printf("Invalid coin. Please insert 1 or 0.5 AED.\n");
    }
    printf("Payment complete. Total paid: %.2f AED. Change: %.2f AED\n", paid, paid - price);
    total_amount += price;
}

void order_coffee() {
    int choice;
    printf("\n1. Espresso (3.5 AED)\n");
    printf("2. Cappuccino (4.5 AED)\n");
    printf("3. Mocha (5.5 AED)\n");
    printf("0. Cancel\n");
    printf("Select your coffee: ");
    scanf("%d", &choice);

void admin_mode() {
    int password;
    printf("Enter admin password: ");
    scanf("%d", &password);
    if (password == ADMIN_PASSWORD) {
        int admin_choice;
        printf("\nAdmin Mode:\n");
        printf("1. View total amount of earnings\n");
        printf("2. View ingredients\n");
        printf("3. Refill ingredients\n");
        printf("0. Exit admin mode\n");
        printf("Select an option: ");
        scanf("%d", &admin_choice);

        switch (admin_choice) {
            case 1:
                printf("Total earnings: %.2f AED\n", total_amount);
                break;
            case 2:
                display_ingredients();
                break;
            case 3:
                refill_ingredients();
                break;
            case 0:
                printf("Exiting admin mode.\n");
                return;
            default:
                printf("Invalid option.\n");
        }
    } else {
        printf("Incorrect password.\n");
    }
}

void display_ingredients() {
    printf("Ingredients:\n");
    printf("Beans: %d grams\n", beans);
    printf("Water: %d mL\n", water);
    printf("Milk: %d mL\n", milk);
    printf("Syrup: %d mL\n", syrup);
}

void refill_ingredients() {
    beans = 100;
    water = 500;
    milk = 300;
    syrup = 100;
    printf("Ingredients refilled.\n");
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
                printf("Invalid option, please try again.\n");
        }
    }
}
