#include <stdio.h>

#define espresso_beans 8 // g
#define espresso_water 30 // mL

#define cappuccino_beans 8 // g
#define cappuccino_water 30 // mL
#define cappuccino_milk 70 // mL

#define mocha_beans 8 // g
#define mocha_water 39 // mL
#define mocha_milk 160 // mL
#define mocha_syrup 30 // mL

#define price_espresso 3.5 // AED
#define price_cappuccino 4.5 // AED
#define price_mocha 5.5 // AED

#define admin_password 2004

#define threshold_beans 10
#define threshold_water 50
#define threshold_milk 100
#define threshold_syrup 20

int beans = 100;
int water = 500;
int milk = 300;
int syrup = 100;

float total_amount = 0;

void process_payment(float price) {
    float paid = 0, coin, change;
    while (paid < price) {
        printf("Insert coin (1 or 0.5 AED): ");
        scanf("%f", &coin);
        if (coin == 1 || coin == 0.5) {
            paid += coin;
        } else {
            printf("Invalid. Please insert 1 or 0.5 AED coin.\n");
        }
    }

    change = paid - price;
    printf("Payment complete. Total paid: %.2f AED\n", paid);

    if (change > 0) {
        printf("Returning change: %.2f AED\n", change);
    }
    total_amount += price;
}

void order_coffee() {
    int choice;
    float price = 0;
    while (1) {
        printf("\n1. Espresso: 3.5 AED\n");
        printf("2. Cappuccino: 4.5 AED\n");
        printf("3. Mocha: 5.5 AED\n");
        printf("0. Cancel\n");
        printf("Select your coffee: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (beans >= espresso_beans && water >= espresso_water) {
                    price = price_espresso;
                } else {
                    printf("Not available due to insufficient ingredients.\n");
                    continue;
                }
                break;
            case 2:
                if (beans >= cappuccino_beans && water >= cappuccino_water && milk >= cappuccino_milk) {
                    price = price_cappuccino;
                } else {
                    printf("Not available due to insufficient ingredients.\n");
                    continue;
                }
                break;
            case 3:
                if (beans >= mocha_beans && water >= mocha_water && milk >= mocha_milk && syrup >= mocha_syrup) {
                    price = price_mocha;
                } else {
                    printf("Not available due to insufficient ingredients.\n");
                    continue;
                }
                break;
            case 0:
                return;
            default:
                printf("Invalid selection, please try again.\n");
                continue;
        }

        printf("You selected: ");
        switch (choice) {
            case 1: printf("Espresso"); break;
            case 2: printf("Cappuccino"); break;
            case 3: printf("Mocha"); break;
        }
        printf(" for %.2f AED. Confirm? (1-Yes, 0-No): ", price);
        int confirm;
        scanf("%d", &confirm);

        if (confirm == 1) {
            process_payment(price);

            if (choice == 1) {
                beans -= espresso_beans;
                water -= espresso_water;
            } else if (choice == 2) {
                beans -= cappuccino_beans;
                water -= cappuccino_water;
                milk -= cappuccino_milk;
            } else if (choice == 3) {
                beans -= mocha_beans;
                water -= mocha_water;
                milk -= mocha_milk;
                syrup -= mocha_syrup;
            }

            printf("Enjoy your coffee.\n");

            if (beans <= threshold_beans) printf("Alert: Low beans.\n");
            if (water <= threshold_water) printf("Alert: Low water.\n");
            if (milk <= threshold_milk) printf("Alert: Low milk.\n");
            if (syrup <= threshold_syrup) printf("Alert: Low syrup.\n");
        }
    }
}

void display_ingredients() {
    printf("Current Ingredients:\n");
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

void reset_earnings() {
    total_amount = 0;
    printf("Total earnings have been reset to 0.\n");
}

void admin_mode() {
    int password;
    printf("Enter admin password: ");
    scanf("%d", &password);
    if (password == admin_password) {
        int admin_choice;
        
        while (1) {
            printf("\nAdmin Mode:\n");
            printf("1. View total amount of earnings\n");
            printf("2. View ingredients\n");
            printf("3. Refill ingredients\n");
            printf("4. Reset total earnings\n");
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
                case 4:
                    reset_earnings();
                    break;
                case 0:
                    printf("Exiting admin mode.\n");
                    return;
                default:
                    printf("Invalid option.\n");
            }
        }
    } else {
        printf("Incorrect password.\n");
    }
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
