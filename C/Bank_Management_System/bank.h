#ifndef BANK_H
#define BANK_H

#define MAX_ACCOUNTS 100

typedef struct {
int accountNumber;
char name[50];
double balance;
} Account;

/* Global Data */
extern Account accounts[MAX_ACCOUNTS];
extern int accountCount;

/* File Operations */
int loadAccounts(void);
int saveAccounts(void);

/* Input Helpers */
int getInt(const char *prompt);
double getDouble(const char *prompt);

/* Account Operations */
void createAccount(void);
void viewAccount(void);
void depositMoney(void);
void withdrawMoney(void);
void transferMoney(void);
void updateAccount(void);
void deleteAccount(void);
void listAccounts(void);

/* Utility Functions */
int findAccount(int accountNumber);
int generateAccountNumber(void);

#endif
