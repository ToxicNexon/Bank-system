#include <stdio.h>
#include <string.h>

// Simple bank account system - personal project
// Written by: [Your Name]

#define MAX_ACCOUNTS 10

struct Account {
    int id;
    char name[50];
    float balance;
};

struct Account accounts[MAX_ACCOUNTS];
int account_count = 0;

// --- Function Prototypes ---
void create_account();
void view_account();
void deposit();
void withdraw();
int find_account(int id);
void print_menu();

// --- Main ---
int main() {
    int choice;

    printf("=============================\n");
    printf("     Simple Bank System      \n");
    printf("=============================\n");

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("\nInvalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1: create_account(); break;
            case 2: view_account();   break;
            case 3: deposit();        break;
            case 4: withdraw();       break;
            case 5:
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

// --- Menu ---
void print_menu() {
    printf("\n-----------------------------\n");
    printf("  1. Create Account\n");
    printf("  2. View My Account\n");
    printf("  3. Deposit\n");
    printf("  4. Withdraw\n");
    printf("  5. Exit\n");
    printf("-----------------------------\n");
}

// --- Create Account ---
void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("\nError: Maximum number of accounts reached.\n");
        return;
    }

    struct Account new_account;
    new_account.id = account_count + 1001;

    printf("\nEnter your name: ");
    scanf(" %[^\n]", new_account.name);

    printf("Enter initial deposit (JD): ");
    if (scanf("%f", &new_account.balance) != 1) {
        while (getchar() != '\n');
        printf("Error: Invalid amount.\n");
        return;
    }

    if (new_account.balance < 0) {
        printf("Error: Initial deposit cannot be negative.\n");
        return;
    }

    accounts[account_count] = new_account;
    account_count++;

    printf("\nAccount created successfully!\n");
    printf("Your Account ID: %d | Name: %s | Balance: %.2f JD\n",
           new_account.id, new_account.name, new_account.balance);
    printf("Please save your Account ID to access your account.\n");
}

// --- View Account ---
void view_account() {
    int id;
    printf("\nEnter your Account ID: ");
    if (scanf("%d", &id) != 1) {
        while (getchar() != '\n');
        printf("Error: Invalid input. Please enter a number.\n");
        return;
    }

    int index = find_account(id);
    if (index == -1) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("\n--- Your Account ---\n");
    printf("ID      : %d\n", accounts[index].id);
    printf("Name    : %s\n", accounts[index].name);
    printf("Balance : %.2f JD\n", accounts[index].balance);
}

// --- Deposit ---
void deposit() {
    int id;
    float amount;

    printf("\nEnter your Account ID: ");
    if (scanf("%d", &id) != 1) {
        while (getchar() != '\n');
        printf("Error: Invalid input. Please enter a number.\n");
        return;
    }

    int index = find_account(id);
    if (index == -1) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("Enter deposit amount (JD): ");
    if (scanf("%f", &amount) != 1) {
        while (getchar() != '\n');
        printf("Error: Invalid amount.\n");
        return;
    }

    if (amount <= 0) {
        printf("Error: Deposit amount must be greater than zero.\n");
        return;
    }

    accounts[index].balance += amount;
    printf("\nDeposit successful!\n");
    printf("New Balance: %.2f JD\n", accounts[index].balance);
}

// --- Withdraw ---
void withdraw() {
    int id;
    float amount;

    printf("\nEnter your Account ID: ");
    if (scanf("%d", &id) != 1) {
        while (getchar() != '\n');
        printf("Error: Invalid input. Please enter a number.\n");
        return;
    }

    int index = find_account(id);
    if (index == -1) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("Enter withdrawal amount (JD): ");
    if (scanf("%f", &amount) != 1) {
        while (getchar() != '\n');
        printf("Error: Invalid amount.\n");
        return;
    }

    if (amount <= 0) {
        printf("Error: Withdrawal amount must be greater than zero.\n");
        return;
    }

    if (amount > accounts[index].balance) {
        printf("Error: Insufficient funds. Current balance: %.2f JD\n",
               accounts[index].balance);
        return;
    }

    accounts[index].balance -= amount;
    printf("\nWithdrawal successful!\n");
    printf("New Balance: %.2f JD\n", accounts[index].balance);
}

// --- Find Account by ID ---
int find_account(int id) {
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].id == id) {
            return i;
        }
    }
    return -1;
}
