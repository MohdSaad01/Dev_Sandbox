#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bank.h"

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

/* =========================
SAFE INPUT FUNCTIONS
========================= */

int getInt(const char *prompt) {
char buffer[100];
int value;
char extra;


while (1) {
    printf("%s", prompt);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        continue;
    }

    if (sscanf(buffer, "%d %c", &value, &extra) == 1) {
        return value;
    }

    printf("Invalid input. Please enter a valid integer.\n");
}


}

double getDouble(const char *prompt) {
char buffer[100];
double value;
char extra;


while (1) {
    printf("%s", prompt);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        continue;
    }

    if (sscanf(buffer, "%lf %c", &value, &extra) == 1) {
        return value;
    }

    printf("Invalid input. Please enter a valid number.\n");
}


}

/* =========================
FILE OPERATIONS
========================= */

int loadAccounts(void) {
FILE *file = fopen("accounts.dat", "rb");


if (file == NULL) {
    return 1;
}

if (fread(&accountCount,
          sizeof(int),
          1,
          file) != 1) {

    fclose(file);
    accountCount = 0;
    return 0;
}

if (accountCount > 0) {
    fread(accounts,
          sizeof(Account),
          accountCount,
          file);
}

fclose(file);
return 1;


}

int saveAccounts(void) {
FILE *file = fopen("accounts.dat", "wb");


if (file == NULL) {
    return 0;
}

fwrite(&accountCount,
       sizeof(int),
       1,
       file);

fwrite(accounts,
       sizeof(Account),
       accountCount,
       file);

fclose(file);

return 1;


}

/* =========================
UTILITY FUNCTIONS
========================= */

int findAccount(int accountNumber) {
for (int i = 0; i < accountCount; i++) {
if (accounts[i].accountNumber == accountNumber) {
return i;
}
}


return -1;


}

int generateAccountNumber(void) {
int highest = 1000;


for (int i = 0; i < accountCount; i++) {
    if (accounts[i].accountNumber > highest) {
        highest = accounts[i].accountNumber;
    }
}

return highest + 1;


}

/* =========================
CREATE ACCOUNT
========================= */

void createAccount(void) {
if (accountCount >= MAX_ACCOUNTS) {
printf("Bank storage is full.\n");
return;
}


Account newAccount;

newAccount.accountNumber = generateAccountNumber();

while (1) {
    printf("Enter Account Holder Name: ");

    if (fgets(newAccount.name,
              sizeof(newAccount.name),
              stdin) == NULL) {
        continue;
    }

    newAccount.name[
        strcspn(newAccount.name, "\n")
    ] = '\0';

    if (strlen(newAccount.name) == 0) {
        printf("Name cannot be empty.\n");
        continue;
    }

    break;
}

while (1) {
    newAccount.balance =
        getDouble("Enter Initial Deposit: ");

    if (newAccount.balance < 0) {
        printf("Deposit cannot be negative.\n");
        continue;
    }

    break;
}

accounts[accountCount] = newAccount;
accountCount++;

saveAccounts();

printf("\nAccount created successfully.\n");
printf("Account Number : %d\n",
       newAccount.accountNumber);
printf("Holder Name    : %s\n",
       newAccount.name);
printf("Balance        : %.2lf\n",
       newAccount.balance);


}

/* =========================
VIEW ACCOUNT
========================= */

void viewAccount(void) {
int accountNumber =
getInt("Enter Account Number: ");


int index =
    findAccount(accountNumber);

if (index == -1) {
    printf("Account not found.\n");
    return;
}

printf("\n");
printf("=================================\n");
printf("         ACCOUNT DETAILS         \n");
printf("=================================\n");

printf("Account Number : %d\n",
       accounts[index].accountNumber);

printf("Account Holder : %s\n",
       accounts[index].name);

printf("Balance        : %.2lf\n",
       accounts[index].balance);

printf("=================================\n");


}

/* =========================
DEPOSIT MONEY
========================= */

void depositMoney(void) {
int accountNumber =
getInt("Enter Account Number: ");


int index =
    findAccount(accountNumber);

if (index == -1) {
    printf("Account not found.\n");
    return;
}

double amount;

while (1) {
    amount =
        getDouble("Enter Amount to Deposit: ");

    if (amount <= 0) {
        printf("Amount must be greater than zero.\n");
        continue;
    }

    break;
}

accounts[index].balance += amount;

saveAccounts();

printf("Deposit successful.\n");
printf("New Balance: %.2lf\n",
       accounts[index].balance);


}

/* =========================
WITHDRAW MONEY
========================= */

void withdrawMoney(void) {
int accountNumber =
getInt("Enter Account Number: ");


int index =
    findAccount(accountNumber);

if (index == -1) {
    printf("Account not found.\n");
    return;
}

double amount;

while (1) {
    amount =
        getDouble("Enter Amount to Withdraw: ");

    if (amount <= 0) {
        printf("Amount must be greater than zero.\n");
        continue;
    }

    break;
}

if (amount > accounts[index].balance) {
    printf("Insufficient balance.\n");
    return;
}

accounts[index].balance -= amount;

saveAccounts();

printf("Withdrawal successful.\n");
printf("Remaining Balance: %.2lf\n",
       accounts[index].balance);


}

/* =========================
TRANSFER MONEY
========================= */

void transferMoney(void) {
int senderAccount =
getInt("Enter Sender Account Number: ");


int receiverAccount =
    getInt("Enter Receiver Account Number: ");

if (senderAccount == receiverAccount) {
    printf("Cannot transfer to the same account.\n");
    return;
}

int senderIndex =
    findAccount(senderAccount);

int receiverIndex =
    findAccount(receiverAccount);

if (senderIndex == -1) {
    printf("Sender account not found.\n");
    return;
}

if (receiverIndex == -1) {
    printf("Receiver account not found.\n");
    return;
}

double amount;

while (1) {
    amount =
        getDouble("Enter Amount to Transfer: ");

    if (amount <= 0) {
        printf("Amount must be greater than zero.\n");
        continue;
    }

    break;
}

if (amount > accounts[senderIndex].balance) {
    printf("Insufficient balance.\n");
    return;
}

accounts[senderIndex].balance -= amount;
accounts[receiverIndex].balance += amount;

saveAccounts();

printf("Transfer successful.\n");
printf("%.2lf transferred.\n", amount);


}

/* =========================
UPDATE ACCOUNT
========================= */

void updateAccount(void) {
int accountNumber =
getInt("Enter Account Number: ");


int index =
    findAccount(accountNumber);

if (index == -1) {
    printf("Account not found.\n");
    return;
}

char newName[50];

while (1) {
    printf("Enter New Name: ");

    if (fgets(newName,
              sizeof(newName),
              stdin) == NULL) {
        continue;
    }

    newName[
        strcspn(newName, "\n")
    ] = '\0';

    if (strlen(newName) == 0) {
        printf("Name cannot be empty.\n");
        continue;
    }

    break;
}

strcpy(accounts[index].name, newName);

saveAccounts();

printf("Account updated successfully.\n");


}

/* =========================
DELETE ACCOUNT
========================= */

void deleteAccount(void) {
int accountNumber =
getInt("Enter Account Number: ");


int index =
    findAccount(accountNumber);

if (index == -1) {
    printf("Account not found.\n");
    return;
}

printf("\n");
printf("Account Found:\n");
printf("Number : %d\n",
       accounts[index].accountNumber);
printf("Name   : %s\n",
       accounts[index].name);

int confirm =
    getInt("Enter 1 to confirm deletion: ");

if (confirm != 1) {
    printf("Deletion cancelled.\n");
    return;
}

for (int i = index;
     i < accountCount - 1;
     i++) {

    accounts[i] = accounts[i + 1];
}

accountCount--;

saveAccounts();

printf("Account deleted successfully.\n");


}

/* =========================
LIST ACCOUNTS
========================= */

void listAccounts(void) {
if (accountCount == 0) {
printf("No accounts available.\n");
return;
}


printf("\n");
printf("============================================================\n");
printf("%-12s %-25s %-15s\n",
       "ACCOUNT NO",
       "NAME",
       "BALANCE");
printf("============================================================\n");

for (int i = 0; i < accountCount; i++) {

    printf("%-12d %-25s %-15.2lf\n",
           accounts[i].accountNumber,
           accounts[i].name,
           accounts[i].balance);
}

printf("============================================================\n");
printf("Total Accounts: %d\n",
       accountCount);


}
