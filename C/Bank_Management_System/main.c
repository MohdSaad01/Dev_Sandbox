#include <stdio.h>
#include "bank.h"

int main(void) {
int choice;


if (loadAccounts()) {
    printf("Accounts loaded successfully.\n");
} else {
    printf("Warning: Could not load account data.\n");
}

do {
    printf("\n");
    printf("====================================\n");
    printf("          BANKING SYSTEM            \n");
    printf("====================================\n");
    printf("1. Create Account\n");
    printf("2. View Account\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. Transfer Money\n");
    printf("6. Update Account\n");
    printf("7. Delete Account\n");
    printf("8. List All Accounts\n");
    printf("9. Exit\n");
    printf("====================================\n");

    choice = getInt("Enter your choice: ");

    switch (choice) {

        case 1:
            createAccount();
            break;

        case 2:
            viewAccount();
            break;

        case 3:
            depositMoney();
            break;

        case 4:
            withdrawMoney();
            break;

        case 5:
            transferMoney();
            break;

        case 6:
            updateAccount();
            break;

        case 7:
            deleteAccount();
            break;

        case 8:
            listAccounts();
            break;

        case 9:
            printf("Saving data...\n");

            if (saveAccounts()) {
                printf("Data saved successfully.\n");
            } else {
                printf("Error while saving data.\n");
            }

            printf("Goodbye.\n");
            break;

        default:
            printf("Invalid menu choice.\n");
    }

} while (choice != 9);

return 0;


}
