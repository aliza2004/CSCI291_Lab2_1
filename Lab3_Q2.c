#include <stdio.h>

int main() {
    int balance = 1000; 
    int transactions[] = {200, -150, -500, -400, -50, -200, 300};
    int numTransactions = 7;
    int tobeprocessed[7]; // Array size matches numTransactions.
    int tobeprocessed_count = 0;

    for (int i = 0; i < numTransactions; i++) {
        if (transactions[i] < 0 && -transactions[i] > balance) {
            // Invalid withdrawal because of insufficient balance.
            printf("Transaction %d (withdrawal of %d AED) is not possible due to insufficient balance.\n", i + 1, -transactions[i]);
            tobeprocessed[tobeprocessed_count++] = transactions[i];
        } else {
            // Update balance as the transaction is valid.
            balance += transactions[i];
            printf("Transaction %d processed. Current balance: %d AED\n", i + 1, balance);

            // Stop processing if balance reaches zero.
            if (balance == 0) {
                printf("Balance is 0 AED. No further transactions can be processed.\n");
                // Add remaining transactions to unprocessed list.
                for (int j = i + 1; j < numTransactions; j++) {
                    tobeprocessed[tobeprocessed_count++] = transactions[j];
                }
                break;
            }
        }
    }

    // Final balance.
    printf("\nFinal balance: %d AED\n", balance);

    // Unprocessed transactions.
    printf("Unprocessed transactions: ");
    if (tobeprocessed_count == 0) {
        printf("None\n");
    } else {
        for (int i = 0; i < tobeprocessed_count; i++) {
            printf("%d ", tobeprocessed[i]);
        }
        printf("\n");
    }

    return 0;
}
