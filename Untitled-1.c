#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

//note toai viet - _-

//----------------------------------------------------------------
// tao kieu userdata
typedef struct userdata
{
    char name[1000];
    int day;
    int month;
    int year;
    char phoneNumber[100];
    char email[100];
    char account[100];
    char password[100];
} userdata;

typedef struct userLogin
{
    char account[100];
    char password[100];
} userLogin;

typedef struct accountAmount {
    double money;
    int monthSet;
    double inputMoney;

}accountAmount;

//----------------------------------------------------------------
//account for users
void user1 (FILE *fptr1, void(*userData1)()) {
    int choiceUser, loginSuss, n, count = 0;
    userdata user1;
    userLogin userLogin1;
    int UserUp, UserLow, UserDig, UserSpecial, UserSize, out;
    do {
        printf("Do you want to create an account or log in?\n");
        printf("1. Create a new account\n");
        printf("2. Login\n");
        scanf("%d", &choiceUser);
        if (choiceUser == 1) {
            fptr1 = fopen("proDataUser1.txt", "w");
            if (fptr1 == NULL) {
                printf("Error logging into account 2 due to data problems, please try again later");
                return;
            }

            getchar();
            printf("Welcome to your new account Ray bank\n");
            printf("-----------------------------------\n");
            printf("Please enter your full name\n");
            fgets(user1.name, sizeof(user1.name), stdin);
            user1.name[strcspn(user1.name, "\n")] = '\0';
            printf("Please enter date of birth dd-mm-yyyy\n");
            scanf("%d %d %d", &user1.day, &user1.month, &user1.year);
            getchar();
            printf("Please enter email\n");
            fgets(user1.email, sizeof(user1.email), stdin);
            user1.email[strcspn(user1.email, "\n")] = '\0';
            printf("Please create your login account name\n");
            fgets(user1.account, sizeof(user1.account), stdin);
            user1.account[strcspn(user1.account, "\n")] = '\0';
            printf("Please create a password for your account\n");
            printf("(note that the password must include lowercase letters, CAPITAL letters, numbers and special characters and be at least 12 characters long.)\n");
            fgets(user1.password, sizeof(user1.password), stdin);
            user1.password[strcspn(user1.password, "\n")] = '\0';

            do {
                UserUp = UserLow = UserDig = UserSpecial = UserSize = 0;
                if (strlen(user1.password) < 12) {
                    UserSize = 1;
                } else {
                    for (int i = 0; i < strlen(user1.password); i++) {
                        if (isupper(user1.password[i])) {
                            UserUp = 1;
                        } else if (islower(user1.password[i])) {
                            UserLow = 1;
                        } else if (isdigit(user1.password[i])) {
                            UserDig = 1;
                        } else if (!isalnum(user1.password[i]) && user1.password[i] != ' ') {
                            UserSpecial = 1;
                        }
                    }
                }

                if (UserUp == 1 && UserDig == 1 && UserSpecial == 1 && UserLow == 1 && UserSize == 1) {
                    out = 1;
                } else {
                    out = 0;
                }
            } while (out == 1);

            printf("Welcome to Ray bank\n");
            fprintf(fptr1, "%s\n", user1.password);
            fprintf(fptr1, "%s\n", user1.account);
            fprintf(fptr1, "%s\n", user1.email);
            fprintf(fptr1, "%s\n", user1.name);
            fprintf(fptr1, "%d\n", user1.day);
            fprintf(fptr1, "%d\n", user1.month);
            fprintf(fptr1, "%d\n", user1.year);
            fclose(fptr1);
            return;
        }
        if (choiceUser == 2) {
            fptr1 = fopen("proDataUser1.txt", "r");
            if (fptr1 == NULL) {
                printf("Error");
            }
            getchar();
            printf("--------Welcome to Ray bank--------------\n");

            fscanf(fptr1, "%s", user1.account);
            fscanf(fptr1, "%s", user1.password);
            fclose(fptr1);

            do {
                loginSuss = 0;
                printf("Please enter your account:\n");
                fgets(userLogin1.account, sizeof(userLogin1.account), stdin);
                userLogin1.account[strcspn(userLogin1.account, "\n")] = '\0';

                printf("Please enter your password:\n");
                printf("You have 5 turns to try!\n");
                fgets(userLogin1.password, sizeof(userLogin1.password), stdin);
                userLogin1.password[strcspn(userLogin1.password, "\n")] = '\0';

                if (strcmp(userLogin1.account, user1.password) == 0 && strcmp(userLogin1.password, user1.account) == 0) {
                    loginSuss = 1;
                } else {
                    printf("Incorrect login please try again!!!\n");
                    loginSuss = 0;
                    count++;
                }
                if (count == 5) {
                    printf("You've run out of tries!\n");
                    break;
                }
            } while (loginSuss != 1);
            printf("Logged in successfully\n");
            printf("--------------------------------Welcome to Ray bank--------------------------------\n");
            userData1();
        }
    } while (choiceUser != 1 && choiceUser != 2);
    fclose(fptr1);
}

void user2(FILE *fptr2, void (*userData2)()) {
    int choiceUser, loginSuss, n, count = 0;
    userdata user2;
    userLogin userLogin2;
    int UserUp, UserLow, UserDig, UserSpecial, UserSize, out;
    do {
        printf("Do you want to create an account or log in?\n");
        printf("1. Create a new account\n");
        printf("2. Login\n");
        scanf("%d", &choiceUser);
        if (choiceUser == 1) {
            fptr2 = fopen("proDataUser2.txt", "w");
            if (fptr2 == NULL) {
                printf("Error logging into account 2 due to data problems, please try again later");
                return;
            }

            getchar();
            printf("Welcome to your new account Ray bank\n");
            printf("-----------------------------------\n");
            printf("Please enter your full name\n");
            fgets(user2.name, sizeof(user2.name), stdin);
            user2.name[strcspn(user2.name, "\n")] = '\0';
            printf("Please enter date of birth dd-mm-yyyy\n");
            scanf("%d %d %d", &user2.day, &user2.month, &user2.year);
            getchar();
            printf("Please enter email\n");
            fgets(user2.email, sizeof(user2.email), stdin);
            user2.email[strcspn(user2.email, "\n")] = '\0';
            printf("Please create your login account name\n");
            fgets(user2.account, sizeof(user2.account), stdin);
            user2.account[strcspn(user2.account, "\n")] = '\0';
            printf("Please create a password for your account\n");
            printf("(note that the password must include lowercase letters, CAPITAL letters, numbers and special characters and be at least 12 characters long.)\n");
            fgets(user2.password, sizeof(user2.password), stdin);
            user2.password[strcspn(user2.password, "\n")] = '\0';

            do {
                UserUp = UserLow = UserDig = UserSpecial = UserSize = 0;
                if (strlen(user2.password) < 12) {
                    UserSize = 1;
                } else {
                    for (int i = 0; i < strlen(user2.password); i++) {
                        if (isupper(user2.password[i])) {
                            UserUp = 1;
                        } else if (islower(user2.password[i])) {
                            UserLow = 1;
                        } else if (isdigit(user2.password[i])) {
                            UserDig = 1;
                        } else if (!isalnum(user2.password[i]) && user2.password[i] != ' ') {
                            UserSpecial = 1;
                        }
                    }
                }

                if (UserUp == 1 && UserDig == 1 && UserSpecial == 1 && UserLow == 1 && UserSize == 1) {
                    out = 1;
                } else {
                    out = 0;
                }
            } while (out == 1);

            printf("Welcome to Ray bank\n");
            fprintf(fptr2, "%s\n", user2.password);
            fprintf(fptr2, "%s\n", user2.account);
            fprintf(fptr2, "%s\n", user2.email);
            fprintf(fptr2, "%s\n", user2.name);
            fprintf(fptr2, "%d\n", user2.day);
            fprintf(fptr2, "%d\n", user2.month);
            fprintf(fptr2, "%d\n", user2.year);
            fclose(fptr2);
            return;
        }
        if (choiceUser == 2) {
            fptr2 = fopen("proDataUser2.txt", "r");
            if (fptr2 == NULL) {
                printf("Error");
            }
            getchar();
            printf("--------Welcome to Ray bank--------------\n");

            fscanf(fptr2, "%s", user2.account);
            fscanf(fptr2, "%s", user2.password);
            fclose(fptr2);

            do {
                loginSuss = 0;
                printf("Please enter your account:\n");
                fgets(userLogin2.account, sizeof(userLogin2.account), stdin);
                userLogin2.account[strcspn(userLogin2.account, "\n")] = '\0';

                printf("Please enter your password:\n");
                printf("You have 5 turns to try!\n");
                fgets(userLogin2.password, sizeof(userLogin2.password), stdin);
                userLogin2.password[strcspn(userLogin2.password, "\n")] = '\0';

                if (strcmp(userLogin2.account, user2.password) == 0 && strcmp(userLogin2.password, user2.account) == 0) {
                    loginSuss = 1;
                } else {
                    printf("Incorrect login please try again!!!\n");
                    loginSuss = 0;
                    count++;
                }
                if (count == 5) {
                    printf("You've run out of tries!\n");
                    break;
                }
            } while (loginSuss != 1);
            printf("Logged in successfully\n");
            printf("--------------------------------Welcome to Ray bank--------------------------------\n");
            userData2();
        }
    } while (choiceUser != 1 && choiceUser != 2);
    fclose(fptr2);
}


void user3 (FILE *fptr3, void (*userData3)()) {
    int choiceUser, loginSuss, n, count = 0;
    userdata user3;
    userLogin userLogin3;
    int UserUp, UserLow, UserDig, UserSpecial, UserSize, out;
    do {
        printf("Do you want to create an account or log in?\n");
        printf("1. Create a new account\n");
        printf("2. Login\n");
        scanf("%d", &choiceUser);
        if (choiceUser == 1) {
            fptr3 = fopen("proDataUser3.txt", "w");
            if (fptr3 == NULL) {
                printf("Error logging into account 2 due to data problems, please try again later");
                return;
            }

            getchar();
            printf("Welcome to your new account Ray bank\n");
            printf("-----------------------------------\n");
            printf("Please enter your full name\n");
            fgets(user3.name, sizeof(user3.name), stdin);
            user3.name[strcspn(user3.name, "\n")] = '\0';
            printf("Please enter date of birth dd-mm-yyyy\n");
            scanf("%d %d %d", &user3.day, &user3.month, &user3.year);
            getchar();
            printf("Please enter email\n");
            fgets(user3.email, sizeof(user3.email), stdin);
            user3.email[strcspn(user3.email, "\n")] = '\0';
            printf("Please create your login account name\n");
            fgets(user3.account, sizeof(user3.account), stdin);
            user3.account[strcspn(user3.account, "\n")] = '\0';
            printf("Please create a password for your account\n");
            printf("(note that the password must include lowercase letters, CAPITAL letters, numbers and special characters and be at least 12 characters long.)\n");
            fgets(user3.password, sizeof(user3.password), stdin);
            user3.password[strcspn(user3.password, "\n")] = '\0';

            do {
                UserUp = UserLow = UserDig = UserSpecial = UserSize = 0;
                if (strlen(user3.password) < 12) {
                    UserSize = 1;
                } else {
                    for (int i = 0; i < strlen(user3.password); i++) {
                        if (isupper(user3.password[i])) {
                            UserUp = 1;
                        } else if (islower(user3.password[i])) {
                            UserLow = 1;
                        } else if (isdigit(user3.password[i])) {
                            UserDig = 1;
                        } else if (!isalnum(user3.password[i]) && user3.password[i] != ' ') {
                            UserSpecial = 1;
                        }
                    }
                }

                if (UserUp == 1 && UserDig == 1 && UserSpecial == 1 && UserLow == 1 && UserSize == 1) {
                    out = 1;
                } else {
                    out = 0;
                }
            } while (out == 1);

            printf("Welcome to Ray bank\n");
            fprintf(fptr3, "%s\n", user3.password);
            fprintf(fptr3, "%s\n", user3.account);
            fprintf(fptr3, "%s\n", user3.email);
            fprintf(fptr3, "%s\n", user3.name);
            fprintf(fptr3, "%d\n", user3.day);
            fprintf(fptr3, "%d\n", user3.month);
            fprintf(fptr3, "%d\n", user3.year);
            fclose(fptr3);
            return;
        }
        if (choiceUser == 2) {
            fptr3 = fopen("proDataUser3.txt", "r");
            if (fptr3 == NULL) {
                printf("Error");
            }
            getchar();
            printf("--------Welcome to Ray bank--------------\n");

            fscanf(fptr3, "%s", user3.account);
            fscanf(fptr3, "%s", user3.password);
            fclose(fptr3);

            do {
                loginSuss = 0;
                printf("Please enter your account:\n");
                fgets(userLogin3.account, sizeof(userLogin3.account), stdin);
                userLogin3.account[strcspn(userLogin3.account, "\n")] = '\0';

                printf("Please enter your password:\n");
                printf("You have 5 turns to try!\n");
                fgets(userLogin3.password, sizeof(userLogin3.password), stdin);
                userLogin3.password[strcspn(userLogin3.password, "\n")] = '\0';

                if (strcmp(userLogin3.account, user3.password) == 0 && strcmp(userLogin3.password, user3.account) == 0) {
                    loginSuss = 1;
                } else {
                    printf("Incorrect login please try again!!!\n");
                    loginSuss = 0;
                    count++;
                }
                if (count == 5) {
                    printf("You've run out of tries!\n");
                    break;
                }
            } while (loginSuss != 1);
            printf("Logged in successfully\n");
            printf("--------------------------------Welcome to Ray bank--------------------------------\n");
            userData3();
        }
    } while (choiceUser != 1 && choiceUser != 2);
    fclose(fptr3);
}
void user4 (FILE *fptr4, void (*userData4)()) {
    int choiceUser, loginSuss, n, count = 0;
    userdata user4;
    userLogin userLogin4;
    int UserUp, UserLow, UserDig, UserSpecial, UserSize, out;
    do {
        printf("Do you want to create an account or log in?\n");
        printf("1. Create a new account\n");
        printf("2. Login\n");
        scanf("%d", &choiceUser);
        if (choiceUser == 1) {
            fptr4 = fopen("proDataUser4.txt", "w");
            if (fptr4 == NULL) {
                printf("Error logging into account 2 due to data problems, please try again later");
                return;
            }

            getchar();
            printf("Welcome to your new account Ray bank\n");
            printf("-----------------------------------\n");
            printf("Please enter your full name\n");
            fgets(user4.name, sizeof(user4.name), stdin);
            user4.name[strcspn(user4.name, "\n")] = '\0';
            printf("Please enter date of birth dd-mm-yyyy\n");
            scanf("%d %d %d", &user4.day, &user4.month, &user4.year);
            getchar();
            printf("Please enter email\n");
            fgets(user4.email, sizeof(user4.email), stdin);
            user4.email[strcspn(user4.email, "\n")] = '\0';
            printf("Please create your login account name\n");
            fgets(user4.account, sizeof(user4.account), stdin);
            user4.account[strcspn(user4.account, "\n")] = '\0';
            printf("Please create a password for your account\n");
            printf("(note that the password must include lowercase letters, CAPITAL letters, numbers and special characters and be at least 12 characters long.)\n");
            fgets(user4.password, sizeof(user4.password), stdin);
            user4.password[strcspn(user4.password, "\n")] = '\0';

            do {
                UserUp = UserLow = UserDig = UserSpecial = UserSize = 0;
                if (strlen(user4.password) < 12) {
                    UserSize = 1;
                } else {
                    for (int i = 0; i < strlen(user4.password); i++) {
                        if (isupper(user4.password[i])) {
                            UserUp = 1;
                        } else if (islower(user4.password[i])) {
                            UserLow = 1;
                        } else if (isdigit(user4.password[i])) {
                            UserDig = 1;
                        } else if (!isalnum(user4.password[i]) && user4.password[i] != ' ') {
                            UserSpecial = 1;
                        }
                    }
                }

                if (UserUp == 1 && UserDig == 1 && UserSpecial == 1 && UserLow == 1 && UserSize == 1) {
                    out = 1;
                } else {
                    out = 0;
                }
            } while (out == 1);

            printf("Welcome to Ray bank\n");
            fprintf(fptr4, "%s\n", user4.password);
            fprintf(fptr4, "%s\n", user4.account);
            fprintf(fptr4, "%s\n", user4.email);
            fprintf(fptr4, "%s\n", user4.name);
            fprintf(fptr4, "%d\n", user4.day);
            fprintf(fptr4, "%d\n", user4.month);
            fprintf(fptr4, "%d\n", user4.year);
            fclose(fptr4);
            return;
        }
        if (choiceUser == 2) {
            fptr4 = fopen("proDataUser4.txt", "r");
            if (fptr4 == NULL) {
                printf("Error");
            }
            getchar();
            printf("--------Welcome to Ray bank--------------\n");

            fscanf(fptr4, "%s", user4.account);
            fscanf(fptr4, "%s", user4.password);
            fclose(fptr4);

            do {
                loginSuss = 0;
                printf("Please enter your account:\n");
                fgets(userLogin4.account, sizeof(userLogin4.account), stdin);
                userLogin4.account[strcspn(userLogin4.account, "\n")] = '\0';

                printf("Please enter your password:\n");
                printf("You have 5 turns to try!\n");
                fgets(userLogin4.password, sizeof(userLogin4.password), stdin);
                userLogin4.password[strcspn(userLogin4.password, "\n")] = '\0';

                printf("%s\n", userLogin4.account);
                printf("%s\n", userLogin4.password);
                printf("%s\n", user4.account);
                printf("%s\n", user4.password);
                if (strcmp(userLogin4.account, user4.password) == 0 && strcmp(userLogin4.password, user4.account) == 0) {
                    loginSuss = 1;
                } else {
                    printf("Incorrect login please try again!!!\n");
                    loginSuss = 0;
                    count++;
                }
                if (count == 5) {
                    printf("You've run out of tries!\n");
                    break;
                }
            } while (loginSuss != 1);
            printf("Logged in successfully\n");
            printf("--------------------------------Welcome to Ray bank--------------------------------\n");
            userData4();
        }
    } while (choiceUser != 1 && choiceUser != 2);
    fclose(fptr4);
}


void user5 (FILE *fptr5, void (*userData5)()) {
    int choiceUser, loginSuss, n, count = 0;
    userdata user5;
    userLogin userLogin5;
    int UserUp, UserLow, UserDig, UserSpecial, UserSize, out;
    do {
        printf("Do you want to create an account or log in?\n");
        printf("1. Create a new account\n");
        printf("2. Login\n");
        scanf("%d", &choiceUser);
        if (choiceUser == 1) {
            fptr5 = fopen("proDataUser5.txt", "w");
            if (fptr5 == NULL) {
                printf("Error logging into account 2 due to data problems, please try again later");
                return;
            }

            getchar();
            printf("Welcome to your new account Ray bank\n");
            printf("-----------------------------------\n");
            printf("Please enter your full name\n");
            fgets(user5.name, sizeof(user5.name), stdin);
            user5.name[strcspn(user5.name, "\n")] = '\0';
            printf("Please enter date of birth dd-mm-yyyy\n");
            scanf("%d %d %d", &user5.day, &user5.month, &user5.year);
            getchar();
            printf("Please enter email\n");
            fgets(user5.email, sizeof(user5.email), stdin);
            user5.email[strcspn(user5.email, "\n")] = '\0';
            printf("Please create your login account name\n");
            fgets(user5.account, sizeof(user5.account), stdin);
            user5.account[strcspn(user5.account, "\n")] = '\0';
            printf("Please create a password for your account\n");
            printf("(note that the password must include lowercase letters, CAPITAL letters, numbers and special characters and be at least 12 characters long.)\n");
            fgets(user5.password, sizeof(user5.password), stdin);
            user5.password[strcspn(user5.password, "\n")] = '\0';

            do {
                UserUp = UserLow = UserDig = UserSpecial = UserSize = 0;
                if (strlen(user5.password) < 12) {
                    UserSize = 1;
                } else {
                    for (int i = 0; i < strlen(user5.password); i++) {
                        if (isupper(user5.password[i])) {
                            UserUp = 1;
                        } else if (islower(user5.password[i])) {
                            UserLow = 1;
                        } else if (isdigit(user5.password[i])) {
                            UserDig = 1;
                        } else if (!isalnum(user5.password[i]) && user5.password[i] != ' ') {
                            UserSpecial = 1;
                        }
                    }
                }

                if (UserUp == 1 && UserDig == 1 && UserSpecial == 1 && UserLow == 1 && UserSize == 1) {
                    out = 1;
                } else {
                    out = 0;
                }
            } while (out == 1);

            printf("Welcome to Ray bank\n");
            fprintf(fptr5, "%s\n", user5.password);
            fprintf(fptr5, "%s\n", user5.account);
            fprintf(fptr5, "%s\n", user5.email);
            fprintf(fptr5, "%s\n", user5.name);
            fprintf(fptr5, "%d\n", user5.day);
            fprintf(fptr5, "%d\n", user5.month);
            fprintf(fptr5, "%d\n", user5.year);
            fclose(fptr5);
            return;
        }
        if (choiceUser == 2) {
            fptr5 = fopen("proDataUser5.txt", "r");
            if (fptr5 == NULL) {
                printf("Error");
            }
            getchar();
            printf("--------Welcome to Ray bank--------------\n");

            fscanf(fptr5, "%s", user5.account);
            fscanf(fptr5, "%s", user5.password);
            fclose(fptr5);

            do {
                loginSuss = 0;
                printf("Please enter your account:\n");
                fgets(userLogin5.account, sizeof(userLogin5.account), stdin);
                userLogin5.account[strcspn(userLogin5.account, "\n")] = '\0';

                printf("Please enter your password:\n");
                printf("You have 5 turns to try!\n");
                fgets(userLogin5.password, sizeof(userLogin5.password), stdin);
                userLogin5.password[strcspn(userLogin5.password, "\n")] = '\0';
                if (strcmp(userLogin5.account, user5.password) == 0 && strcmp(userLogin5.password, user5.account) == 0) {
                    loginSuss = 1;
                } else {
                    printf("Incorrect login please try again!!!\n");
                    loginSuss = 0;
                    count++;
                }
                if (count == 5) {
                    printf("You've run out of tries!\n");
                    break;
                }
            } while (loginSuss != 1);
            printf("Logged in successfully\n");
            printf("--------------------------------Welcome to Ray bank--------------------------------\n");
            userData5();
        }
    } while (choiceUser != 1 && choiceUser != 2);
    fclose(fptr5);
}
// đây vẫn là code người viết khom phải máy - -
//---------------------------------------- userData ------------------------------------------------------

int count_months_since_epoch() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    int month = tm->tm_mon + 1;
    int year = tm->tm_year + 1900;

    int months = 0;

    months += month;

    months += year * 12;

  return months;
}


void userData1() {
    double money, money1, cache, cache1;
    double percentage1, percentage;
    int choice, choiceSave = 0, month;
    int specifiedMonth2, specifiedMonth1;
    double withdrawalAmount = 0, depositAmount = 0;
    accountAmount userDataMoney1, monthSet1, monthSet12, moneyY1, moneyY12;
    FILE *fptr1;
    FILE *fptrM1;
    fptrM1 = fopen("accountAmount1.txt", "w+");
    FILE *fptrMS1;
    fptrMS1 = fopen("accountAmount1.txt", "w+");
    userdata user1;

    do {
        printf("1: Deposit money into your account\n");
        printf("2: Withdraw money\n");
        printf("3: Checking account balance\n");
        printf("4: Bank savings\n");
        printf("5: Profile user\n");
        printf("6: Log out\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            fptrM1 = fopen("accountAmount1.txt", "r+");
            if (fptrM1 == NULL) {
            printf("Error opening file!\n");
            exit(1);
            }

            printf("Please enter the purchase amount to deposit into your account\n");
            scanf("%lf", &depositAmount);
            getchar();
            fscanf(fptrM1, "%lf", &userDataMoney1.money);
            cache = userDataMoney1.money;
            cache += depositAmount;
            userDataMoney1.money = cache;
            rewind(fptrM1);

            fprintf(fptrM1, "%lf", userDataMoney1.money);
            printf("Deposit to your account successfully!\n");
            fclose(fptrM1);
            break;

        case 2:
            fptrM1 = fopen("accountAmount1.txt", "r+");
            if (fptrM1 == NULL) {
            printf("Error opening file!\n");
            exit(1);
            }

            printf("Enter the amount you want to withdraw\n");
            scanf("%lf", &withdrawalAmount);
            getchar();

            fscanf(fptrM1, "%lf", &userDataMoney1.money);
            //fseek(fptrM1, 0, SEEK_SET);
            cache = userDataMoney1.money;
            cache -= withdrawalAmount;
            userDataMoney1.money = cache;
            rewind(fptrM1);
            fprintf(fptrM1, "%lf", userDataMoney1.money);
            printf("Take money from account successfully!\n");
            fclose(fptrM1);
            break;

        case 3:
            fptrM1 = fopen("accountAmount1.txt", "r");
            if (fptrM1 == NULL) {
            printf("Error opening file!\n");
            exit(1);
            }

            printf("The current balance in your account is: ");
            fscanf(fptrM1, "%lf", &userDataMoney1.money);
            printf("%lf\n", userDataMoney1.money);

            fclose(fptrM1);
            break;
        case 4:
            do {
            monthSet1.monthSet = count_months_since_epoch();
            printf("Welcome to Ray Bank's savings account\n");
            printf("-------------------------------------------\n");
            printf("Please choose your savings deposit term\n");
            printf("1: 6 months\n");
            printf("*interest rate 4%%\n");
            printf("2: 12 months\n");
            printf("*interest rate 9%%\n");
            printf("3: Exit\n");
            scanf("%d", &choiceSave);
                switch (choiceSave)
                {
                case 1:
                    monthSet1.monthSet = count_months_since_epoch();
                    money1 = 0;
                    specifiedMonth1 = 0;
                    percentage1 = 0.04;
                    fptrM1 = fopen("saving1.txt", "r+");
                    fptrMS1 = fopen("accountAmount1.txt", "r+");
                    if (fptrM1 == NULL) {
                        printf("Error");
                    }
                    if (fptrMS1 == NULL) {
                        printf("Error!");
                    }
                    fseek(fptrMS1, 0, SEEK_END);
                    if (ftell(fptrMS1) > 0){
                        month = specifiedMonth1 - monthSet1.monthSet;
                        printf("You have already saved and the remaining time is: %d\n", month);
                    }
                    else {
                        printf("Please enter the amount you want to save\n");
                        scanf("%lf", &money1);
                        moneyY1.inputMoney = money1;
                        fscanf(fptrM1, "%ld", &userDataMoney1.money);
                        cache = userDataMoney1.money;
                        cache -= moneyY1.inputMoney;
                        userDataMoney1.money = cache;
                        fprintf(fptrMS1, "%lf", moneyY1.inputMoney);
                        fprintf(fptrM1, "%d", 1, monthSet1.monthSet);
                        specifiedMonth1 = monthSet1.monthSet + 6;
                        if (specifiedMonth1 == monthSet1.monthSet) {
                            fscanf(fptrMS1, "%lf", &moneyY1.inputMoney);
                            cache1 = moneyY1.inputMoney;
                            cache = cache1 + (1.0 + percentage1);
                            userDataMoney1.money = cache;
                            printf("%lf", userDataMoney1.money);
                            monthSet1.monthSet = '\0';
                            cache1 = '\0';
                            moneyY1.inputMoney = cache1;
                            fprintf(fptrM1, "%d", monthSet1.monthSet);
                            fprintf(fptrM1, "%lf", userDataMoney1.money);
                        }
                    }

                    break;

                case 2:
                    monthSet1.monthSet = count_months_since_epoch();
                    money1 = 0;
                    specifiedMonth1 = 0;
                    percentage1 = 0.09;
                    fptrM1 = fopen("saving11.txt", "w+");
                    fptrMS1 = fopen("accountAmount1.txt", "r+");
                    if (fptrM1 == NULL) {
                        printf("Error");
                    }
                    if (fptrMS1 == NULL) {
                        printf("Error!");
                    }
                    fseek(fptrMS1, 0, SEEK_END);
                    if (ftell(fptrMS1) > 0){
                        month = specifiedMonth2 - monthSet12.monthSet;
                        printf("You have already saved and the remaining time is: %d\n", month);
                    }
                    else {
                        printf("Please enter the amount you want to save\n");
                        scanf("%lf", &money);
                        moneyY12.inputMoney = money;
                        fscanf(fptrM1, "%lf", &userDataMoney1.money);
                        cache = userDataMoney1.money;
                        cache -= moneyY1.inputMoney;
                        userDataMoney1.money = cache;
                        fprintf(fptrMS1, "%lf", moneyY1.inputMoney);
                        fprintf(fptrMS1, "%d", 1, monthSet1.monthSet);
                        specifiedMonth1 = monthSet1.monthSet + 12;
                        if (specifiedMonth1 == monthSet1.monthSet) {
                            fscanf(fptrMS1, "%lf", &moneyY1.inputMoney);
                            cache1 = moneyY1.inputMoney;
                            cache = cache + (1.0 + percentage1);
                            userDataMoney1.money = cache;
                            printf("%lf", userDataMoney1.money);
                            monthSet1.monthSet = '\0';
                            cache = '\0';
                            moneyY1.inputMoney = cache;
                            fprintf(fptrM1, "%d", monthSet1.monthSet);
                            fprintf(fptrM1, "%lf", userDataMoney1.money);
                        }
                    }

                    break;
                }
            }while (choiceSave != 3);
            break;
            case 5:

                fptr1 = fopen("proDataUser1.txt", "r");
                if (fptr1 == NULL) {
                    printf("Error: Cannot open");
                }
                if (fscanf(fptr1, "%49s", user1.account) != 1 ||
                    fscanf(fptr1, "%49s", user1.password) != 1 ||
                    fscanf(fptr1, "%49s", user1.email) != 1 ||
                    fscanf(fptr1, "%49s", user1.name) != 1 ||
                    fscanf(fptr1, "%d", &user1.day) != 1 ||
                    fscanf(fptr1, "%d", &user1.month) != 1 ||
                    fscanf(fptr1, "%d", &user1.year) != 1) {
                    printf("Error: Failed to read data from file");
                    fclose(fptr1);
                }

            printf("----------Your account information-----------------\n");
            printf("Account: %s\n", user1.account);
            printf("Password: %s\n", user1.password);
            printf("Email: %s\n", user1.email);
            printf("Name: %s\n", user1.name);
            printf("Date of birth: %d_%d_%d\n", user1.day, user1.month, user1.year);
            fclose(fptr1);
            break;
        }
    }while (choice != 6);
    fclose(fptrM1);
}

void userData2() {
    double money, money1, cache, cache1;
    double percentage1, percentage;
    int choice, choiceSave = 0, month;
    int specifiedMonth2, specifiedMonth1;
    double withdrawalAmount = 0, depositAmount = 0;
    accountAmount userDataMoney2, monthSet2, monthSet22, moneyY2, moneyY22;
    FILE *fptr2;
    FILE *fptrM2;
    fptrM2 = fopen("accountAmount2.txt", "w+");
    FILE *fptrMS2;
    fptrMS2 = fopen("accountAmount2.txt", "w+");

    do {
        printf("1: Deposit money into your account\n");
        printf("2: Withdraw money\n");
        printf("3: Checking account balance\n");
        printf("4: Bank savings\n");
        printf("5: Profile user\n");
        printf("6: Log out\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            fptrM2 = fopen("accountAmount2.txt", "r+");
            if (fptrM2 == NULL) {
            printf("Error opening file!\n");
            exit(1);
            }

            printf("Please enter the purchase amount to deposit into your account\n");
            scanf("%lf", &depositAmount);
            getchar();
            fscanf(fptrM2, "%lf", &userDataMoney2.money);
            cache = userDataMoney2.money;
            cache += depositAmount;
            userDataMoney2.money = cache;
            rewind(fptrM2);
            fprintf(fptrM2, "%lf", userDataMoney2.money);
            printf("Deposit to your account successfully!\n");
            fclose(fptrM2);
            break;

        case 2:
            fptrM2 = fopen("accountAmount2.txt", "r+");
            if (fptrM2 == NULL) {
            printf("Error opening file!\n");
            exit(1);
            }

            printf("Enter the amount you want to withdraw\n");
            scanf("%lf", &withdrawalAmount);
            getchar();

            fscanf(fptrM2, "%lf", &userDataMoney2.money);
            //fseek(fptrM1, 0, SEEK_SET);
            cache = userDataMoney2.money;
            cache -= withdrawalAmount;
            userDataMoney2.money = cache;
            rewind(fptrM2);
            fprintf(fptrM2, "%lf", userDataMoney2.money);
            printf("Take money from account successfully!\n");
            fclose(fptrM2);
            break;

        case 3:
            fptrM2 = fopen("accountAmount2.txt", "r");
            if (fptrM2 == NULL) {
            printf("Error opening file!\n");
            exit(1);
            }

            printf("The current balance in your account is: ");
            fscanf(fptrM2, "%lf", &userDataMoney2.money);
            printf("%lf\n", userDataMoney2.money);

            fclose(fptrM2);
            break;
        case 4:
            do {
            monthSet2.monthSet = count_months_since_epoch();
            printf("Welcome to Ray Bank's savings account\n");
            printf("-------------------------------------------\n");
            printf("Please choose your savings deposit term\n");
            printf("1: 6 months\n");
            printf("*interest rate 4%%\n");
            printf("2: 12 months\n");
            printf("*interest rate 9%%\n");
            printf("3: Exit\n");
            scanf("%d", &choiceSave);
                switch (choiceSave)
                {
                case 1:
                    monthSet2.monthSet = count_months_since_epoch();
                    money1 = 0;
                    specifiedMonth1 = 0;
                    percentage1 = 0.04;
                    fptrM2 = fopen("saving2.txt", "w+");
                    fptrMS2 = fopen("accountAmount2.txt", "w+");
                    if (fptrM2 == NULL) {
                        printf("Error");
                    }
                    if (fptrMS2 == NULL) {
                        printf("Error!");
                    }
                    fseek(fptrMS2, 0, SEEK_END);
                    if (ftell(fptrMS2) > 0){
                        month = specifiedMonth1 - monthSet2.monthSet;
                        printf("You have already saved and the remaining time is: %d\n", month);
                    }
                    else {
                        printf("Please enter the amount you want to save\n");
                        scanf("%lf", &money1);
                        moneyY2.inputMoney = money1;
                        fscanf(fptrM2, "%ld", &userDataMoney2.money);
                        cache = userDataMoney2.money;
                        cache -= moneyY2.inputMoney;
                        userDataMoney2.money = cache;
                        fprintf(fptrMS2, "%lf", moneyY2.inputMoney);
                        fprintf(fptrMS2, "%d", 1, monthSet2.monthSet);
                        specifiedMonth1 = monthSet2.monthSet + 6;
                        if (specifiedMonth1 == monthSet2.monthSet) {
                            fscanf(fptrMS2, "%lf", &moneyY2.inputMoney);
                            cache1 = moneyY2.inputMoney;
                            cache = cache1 + (1.0 + percentage1);
                            userDataMoney2.money = cache;
                            printf("%lf", userDataMoney2.money);
                            monthSet2.monthSet = '\0';
                            cache1 = '\0';
                            moneyY2.inputMoney = cache1;
                            fprintf(fptrM2, "%d", monthSet2.monthSet);
                            fprintf(fptrM2, "%lf", userDataMoney2.money);
                        }
                    }

                    break;

                case 2:
                    monthSet2.monthSet = count_months_since_epoch();
                    money1 = 0;
                    specifiedMonth1 = 0;
                    percentage1 = 0.09;
                    fptrM2 = fopen("saving21.txt", "w+");
                    fptrMS2 = fopen("accountAmount2.txt", "r+");
                    if (fptrM2 == NULL) {
                        printf("Error");
                    }
                    if (fptrMS2 == NULL) {
                        printf("Error!");
                    }
                    fseek(fptrMS2, 0, SEEK_END);
                    if (ftell(fptrMS2) > 0){
                        month = specifiedMonth2 - monthSet22.monthSet;
                        printf("You have already saved and the remaining time is: %d\n", month);
                    }
                    else {
                        printf("Please enter the amount you want to save\n");
                        scanf("%lf", &money);
                        moneyY22.inputMoney = money;
                        fscanf(fptrM2, "%lf", &userDataMoney2.money);
                        cache = userDataMoney2.money;
                        cache -= moneyY2.inputMoney;
                        userDataMoney2.money = cache;
                        fprintf(fptrMS2, "%lf", moneyY2.inputMoney);
                        fprintf(fptrMS2, "%d", 1, monthSet2.monthSet);
                        specifiedMonth1 = monthSet2.monthSet + 12;
                        if (specifiedMonth1 == monthSet2.monthSet) {
                            fscanf(fptrMS2, "%lf", &moneyY2.inputMoney);
                            cache1 = moneyY2.inputMoney;
                            cache = cache + (1.0 + percentage1);
                            userDataMoney2.money = cache;
                            printf("%lf", userDataMoney2.money);
                            monthSet2.monthSet = '\0';
                            cache = '\0';
                            moneyY2.inputMoney = cache;
                            fprintf(fptrM2, "%d", monthSet2.monthSet);
                            fprintf(fptrM2, "%lf", userDataMoney2.money);
                        }
                    }

                    break;
                }
            }while (choiceSave != 3);
            break;
            case 5:

                fptr2 = fopen("proDataUser2.txt", "r");
                if (fptr2 == NULL) {
                    printf("Error: Cannot open");
                }
                userdata user2;
                if (fscanf(fptr2, "%49s", user2.account) != 1 ||
                    fscanf(fptr2, "%49s", user2.password) != 1 ||
                    fscanf(fptr2, "%49s", user2.email) != 1 ||
                    fscanf(fptr2, "%49s", user2.name) != 1 ||
                    fscanf(fptr2, "%d", &user2.day) != 1 ||
                    fscanf(fptr2, "%d", &user2.month) != 1 ||
                    fscanf(fptr2, "%d", &user2.year) != 1) {
                    printf("Error: Failed to read data from file");
                    fclose(fptr2);
                }

                printf("----------Your account information-----------------\n");
                printf("Pass: %s\n", user2.account);
                //printf("Account: %s\n", user5.phoneNumber);
                printf("Name: %s\n", user2.email);
                printf("Email: %s\n", user2.name);
                printf("Date of birth: %d_%d_%d\n", user2.day, user2.month, user2.year);
                fclose(fptr2);
                break;
        }
    }while (choice != 6);
    fclose(fptrM2);
}

void userData3() {
    double money, money1, cache, cache1;
    double percentage1, percentage;
    int choice, choiceSave = 0, month;
    int specifiedMonth2, specifiedMonth1;
    double withdrawalAmount = 0, depositAmount = 0;
    accountAmount userDataMoney3, monthSet3, monthSet32, moneyY3, moneyY32;
    FILE *fptr3;
    FILE *fptrM3;
    fptrM3 = fopen("accountAmount3.txt", "w+");
    FILE *fptrMS3;
    fptrMS3 = fopen("accountAmount3.txt", "w+");

    do {
        printf("1: Deposit money into your account\n");
        printf("2: Withdraw money\n");
        printf("3: Checking account balance\n");
        printf("4: Bank savings\n");
        printf("5: Profile user\n");
        printf("6: Log out\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            fptrM3 = fopen("accountAmount3.txt", "r+");
            if (fptrM3 == NULL) {
            printf("Error opening file!\n");
            exit(1);
            }

            printf("Please enter the purchase amount to deposit into your account\n");
            scanf("%lf", &depositAmount);
            getchar();
            fscanf(fptrM3, "%lf", &userDataMoney3.money);
            cache = userDataMoney3.money;
            cache += depositAmount;
            userDataMoney3.money = cache;
            rewind(fptrM3);

            fprintf(fptrM3, "%lf", userDataMoney3.money);
            printf("Deposit to your account successfully!\n");
            fclose(fptrM3);
            break;

        case 2:
            fptrM3 = fopen("accountAmount3.txt", "r+");
            if (fptrM3 == NULL) {
            printf("Error opening file!\n");
            exit(1);
            }

            printf("Enter the amount you want to withdraw\n");
            scanf("%lf", &withdrawalAmount);
            getchar();

            fscanf(fptrM3, "%lf", &userDataMoney3.money);
            //fseek(fptrM1, 0, SEEK_SET);
            cache = userDataMoney3.money;
            cache -= withdrawalAmount;
            userDataMoney3.money = cache;
            rewind(fptrM3);
            fprintf(fptrM3, "%lf", userDataMoney3.money);
            printf("Take money from account successfully!\n");
            fclose(fptrM3);
            break;

        case 3:
            fptrM3 = fopen("accountAmount3.txt", "r");
            if (fptrM3 == NULL) {
            printf("Error opening file!\n");
            exit(1);
            }

            printf("The current balance in your account is: ");
            fscanf(fptrM3, "%lf", &userDataMoney3.money);
            printf("%lf\n", userDataMoney3.money);

            fclose(fptrM3);
            break;
        case 4:
            do {
            monthSet3.monthSet = count_months_since_epoch();
            printf("Welcome to Ray Bank's savings account\n");
            printf("-------------------------------------------\n");
            printf("Please choose your savings deposit term\n");
            printf("1: 6 months\n");
            printf("*interest rate 4%%\n");
            printf("2: 12 months\n");
            printf("*interest rate 9%%\n");
            printf("3: Exit\n");
            scanf("%d", &choiceSave);
                switch (choiceSave)
                {
                case 1:
                    monthSet3.monthSet = count_months_since_epoch();
                    money1 = 0;
                    specifiedMonth1 = 0;
                    percentage1 = 0.04;
                    fptrM3 = fopen("saving3.txt", "w+");
                    fptrMS3 = fopen("accountAmount3.txt", "w+");
                    if (fptrM3 == NULL) {
                        printf("Error");
                    }
                    if (fptrMS3 == NULL) {
                        printf("Error!");
                    }
                    fseek(fptrMS3, 0, SEEK_END);
                    if (ftell(fptrMS3) > 0){
                        month = specifiedMonth1 - monthSet3.monthSet;
                        printf("You have already saved and the remaining time is: %d\n", month);
                    }
                    else {
                        printf("Please enter the amount you want to save\n");
                        scanf("%lf", &money1);
                        moneyY3.inputMoney = money1;
                        fscanf(fptrM3, "%ld", &userDataMoney3.money);
                        cache = userDataMoney3.money;
                        cache -= moneyY3.inputMoney;
                        userDataMoney3.money = cache;
                        fprintf(fptrMS3, "%lf", moneyY3.inputMoney);
                        fprintf(fptrMS3, "%d", 1, monthSet3.monthSet);
                        specifiedMonth1 = monthSet3.monthSet + 6;
                        if (specifiedMonth1 == monthSet3.monthSet) {
                            fscanf(fptrMS3, "%lf", &moneyY3.inputMoney);
                            cache1 = moneyY3.inputMoney;
                            cache = cache1 + (1.0 + percentage1);
                            userDataMoney3.money = cache;
                            printf("%lf", userDataMoney3.money);
                            monthSet3.monthSet = '\0';
                            cache1 = '\0';
                            moneyY3.inputMoney = cache1;
                            fprintf(fptrM3, "%d", monthSet3.monthSet);
                            fprintf(fptrM3, "%lf", userDataMoney3.money);
                        }
                    }

                    break;

                case 2:
                    monthSet3.monthSet = count_months_since_epoch();
                    money1 = 0;
                    specifiedMonth1 = 0;
                    percentage1 = 0.09;
                    fptrM3 = fopen("saving31.txt", "w+");
                    fptrMS3 = fopen("accountAmount3.txt", "r+");
                    if (fptrM3 == NULL) {
                        printf("Error");
                    }
                    if (fptrMS3 == NULL) {
                        printf("Error!");
                    }
                    fseek(fptrMS3, 0, SEEK_END);
                    if (ftell(fptrMS3) > 0){
                        month = specifiedMonth2 - monthSet32.monthSet;
                        printf("You have already saved and the remaining time is: %d\n", month);
                    }
                    else {
                        printf("Please enter the amount you want to save\n");
                        scanf("%lf", &money);
                        moneyY32.inputMoney = money;
                        fscanf(fptrM3, "%lf", &userDataMoney3.money);
                        cache = userDataMoney3.money;
                        cache -= moneyY3.inputMoney;
                        userDataMoney3.money = cache;
                        fprintf(fptrMS3, "%lf", moneyY3.inputMoney);
                        fprintf(fptrMS3, "%d", 1, monthSet3.monthSet);
                        specifiedMonth1 = monthSet3.monthSet + 12;
                        if (specifiedMonth1 == monthSet3.monthSet) {
                            fscanf(fptrMS3, "%lf", &moneyY3.inputMoney);
                            cache1 = moneyY3.inputMoney;
                            cache = cache + (1.0 + percentage1);
                            userDataMoney3.money = cache;
                            printf("%lf", userDataMoney3.money);
                            monthSet3.monthSet = '\0';
                            cache = '\0';
                            moneyY3.inputMoney = cache;
                            fprintf(fptrM3, "%d", monthSet3.monthSet);
                            fprintf(fptrM3, "%lf", userDataMoney3.money);
                        }
                    }
                    break;
                }
            }while (choiceSave != 3);
            break;
            case 5:

                fptr3 = fopen("proDataUser3.txt", "r");
                if (fptr3 == NULL) {
                    printf("Error: Cannot open");
                }
                userdata user3;
                if (fscanf(fptr3, "%49s", user3.account) != 1 ||
                    fscanf(fptr3, "%49s", user3.password) != 1 ||
                    fscanf(fptr3, "%49s", user3.email) != 1 ||
                    fscanf(fptr3, "%49s", user3.name) != 1 ||
                    fscanf(fptr3, "%d", &user3.day) != 1 ||
                    fscanf(fptr3, "%d", &user3.month) != 1 ||
                    fscanf(fptr3, "%d", &user3.year) != 1) {
                    printf("Error: Failed to read data from file");
                    fclose(fptr3);
                }

                printf("----------Your account information-----------------\n");
                printf("Pass: %s\n", user3.account);
                //printf("Account: %s\n", user5.phoneNumber);
                printf("Name: %s\n", user3.email);
                printf("Email: %s\n", user3.name);
                printf("Date of birth: %d_%d_%d\n", user3.day, user3.month, user3.year);
                fclose(fptr3);
                break;
            
        }
    }while (choice != 6);
    fclose(fptrM3);
}

void userData4() {
    double money, money1, cache, cache1;
    double percentage1, percentage;
    int choice, choiceSave = 0, month;
    int specifiedMonth2, specifiedMonth1;
    double withdrawalAmount = 0, depositAmount = 0;
    accountAmount userDataMoney4, monthSet4, monthSet42, moneyY4, moneyY42;
    FILE *fptrM4;
    FILE *fptr4;
    fptrM4 = fopen("accountAmount4.txt", "w+");
    FILE *fptrMS4;
    fptrMS4 = fopen("accountAmount4.txt", "w+");

    do {
        printf("1: Deposit money into your account\n");
        printf("2: Withdraw money\n");
        printf("3: Checking account balance\n");
        printf("4: Bank savings\n");
        printf("5: Profile user\n");
        printf("6: Log out\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            fptrM4 = fopen("accountAmount4.txt", "r+");
            if (fptrM4 == NULL) {
            printf("Error opening file!\n");
            exit(1);
            }

            printf("Please enter the purchase amount to deposit into your account\n");
            scanf("%lf", &depositAmount);
            getchar();
            fscanf(fptrM4, "%lf", &userDataMoney4.money);
            cache = userDataMoney4.money;
            cache += depositAmount;
            userDataMoney4.money = cache;
            rewind(fptrM4);

            fprintf(fptrM4, "%lf", userDataMoney4.money);
            printf("Deposit to your account successfully!\n");
            fclose(fptrM4);
            break;

        case 2:
            fptrM4 = fopen("accountAmount4.txt", "r+");
            if (fptrM4 == NULL) {
            printf("Error opening file!\n");
            exit(1);
            }

            printf("Enter the amount you want to withdraw\n");
            scanf("%lf", &withdrawalAmount);
            getchar();

            fscanf(fptrM4, "%lf", &userDataMoney4.money);
            //fseek(fptrM1, 0, SEEK_SET);
            cache = userDataMoney4.money;
            cache -= withdrawalAmount;
            userDataMoney4.money = cache;
            rewind(fptrM4);
            fprintf(fptrM4, "%lf", userDataMoney4.money);
            printf("Take money from account successfully!\n");
            fclose(fptrM4);
            break;

        case 3:
            fptrM4 = fopen("accountAmount4.txt", "r");
            if (fptrM4 == NULL) {
            printf("Error opening file!\n");
            exit(1);
            }

            printf("The current balance in your account is: ");
            fscanf(fptrM4, "%lf", &userDataMoney4.money);
            printf("%lf\n", userDataMoney4.money);

            fclose(fptrM4);
            break;
        case 4:
            do {
            monthSet4.monthSet = count_months_since_epoch();
            printf("Welcome to Ray Bank's savings account\n");
            printf("-------------------------------------------\n");
            printf("Please choose your savings deposit term\n");
            printf("1: 6 months\n");
            printf("*interest rate 4%%\n");
            printf("2: 12 months\n");
            printf("*interest rate 9%%\n");
            printf("3: Exit\n");
            scanf("%d", &choiceSave);
                switch (choiceSave)
                {
                case 1:
                    monthSet4.monthSet = count_months_since_epoch();
                    money1 = 0;
                    specifiedMonth1 = 0;
                    percentage1 = 0.04;
                    fptrM4 = fopen("saving4.txt", "w+");
                    fptrMS4 = fopen("accountAmount4.txt", "w+");
                    if (fptrM4 == NULL) {
                        printf("Error");
                    }
                    if (fptrMS4 == NULL) {
                        printf("Error!");
                    }
                    fseek(fptrMS4, 0, SEEK_END);
                    if (ftell(fptrMS4) > 0){
                        month = specifiedMonth1 - monthSet4.monthSet;
                        printf("You have already saved and the remaining time is: %d\n", month);
                    }
                    else {
                        printf("Please enter the amount you want to save\n");
                        scanf("%lf", &money1);
                        moneyY4.inputMoney = money1;
                        fscanf(fptrM4, "%ld", &userDataMoney4.money);
                        cache = userDataMoney4.money;
                        cache -= moneyY4.inputMoney;
                        userDataMoney4.money = cache;
                        fprintf(fptrMS4, "%lf", moneyY4.inputMoney);
                        fprintf(fptrMS4, "%d", 1, monthSet4.monthSet);
                        specifiedMonth1 = monthSet4.monthSet + 6;
                        if (specifiedMonth1 == monthSet4.monthSet) {
                            fscanf(fptrMS4, "%lf", &moneyY4.inputMoney);
                            cache1 = moneyY4.inputMoney;
                            cache = cache1 + (1.0 + percentage1);
                            userDataMoney4.money = cache;
                            printf("%lf", userDataMoney4.money);
                            monthSet4.monthSet = '\0';
                            cache1 = '\0';
                            moneyY4.inputMoney = cache1;
                            fprintf(fptrM4, "%d", monthSet4.monthSet);
                            fprintf(fptrM4, "%lf", userDataMoney4.money);
                        }
                    }

                    break;

                case 2:
                    monthSet4.monthSet = count_months_since_epoch();
                    money1 = 0;
                    specifiedMonth1 = 0;
                    percentage1 = 0.09;
                    fptrM4 = fopen("saving41.txt", "w+");
                    fptrMS4 = fopen("accountAmount4.txt", "r+");
                    if (fptrM4 == NULL) {
                        printf("Error");
                    }
                    if (fptrMS4 == NULL) {
                        printf("Error!");
                    }
                    fseek(fptrMS4, 0, SEEK_END);
                    if (ftell(fptrMS4) > 0){
                        month = specifiedMonth2 - monthSet42.monthSet;
                        printf("You have already saved and the remaining time is: %d\n", month);
                    }
                    else {
                        printf("Please enter the amount you want to save\n");
                        scanf("%lf", &money);
                        moneyY42.inputMoney = money;
                        fscanf(fptrM4, "%lf", &userDataMoney4.money);
                        cache = userDataMoney4.money;
                        cache -= moneyY4.inputMoney;
                        userDataMoney4.money = cache;
                        fprintf(fptrMS4, "%lf", moneyY4.inputMoney);
                        fprintf(fptrMS4, "%d", 1, monthSet4.monthSet);
                        specifiedMonth1 = monthSet4.monthSet + 12;
                        if (specifiedMonth1 == monthSet4.monthSet) {
                            fscanf(fptrMS4, "%lf", &moneyY4.inputMoney);
                            cache1 = moneyY4.inputMoney;
                            cache = cache + (1.0 + percentage1);
                            userDataMoney4.money = cache;
                            printf("%lf", userDataMoney4.money);
                            monthSet4.monthSet = '\0';
                            cache = '\0';
                            moneyY4.inputMoney = cache;
                            fprintf(fptrM4, "%d", monthSet4.monthSet);
                            fprintf(fptrM4, "%lf", userDataMoney4.money);
                        }
                    }

                    break;
                }
            }while (choiceSave != 3);
            break;
            case 5:

                fptr4 = fopen("proDataUser4.txt", "r");
                if (fptr4 == NULL) {
                    printf("Error: Cannot open");
                }
                userdata user4;
                if (fscanf(fptr4, "%49s", user4.account) != 1 ||
                    fscanf(fptr4, "%49s", user4.password) != 1 ||
                    fscanf(fptr4, "%49s", user4.email) != 1 ||
                    fscanf(fptr4, "%49s", user4.name) != 1 ||
                    fscanf(fptr4, "%d", &user4.day) != 1 ||
                    fscanf(fptr4, "%d", &user4.month) != 1 ||
                    fscanf(fptr4, "%d", &user4.year) != 1) {
                    printf("Error: Failed to read data from file");
                    fclose(fptr4);
                }

                printf("----------Your account information-----------------\n");
                printf("Pass: %s\n", user4.account);
                //printf("Account: %s\n", user5.phoneNumber);
                printf("Name: %s\n", user4.email);
                printf("Email: %s\n", user4.name);
                printf("Date of birth: %d_%d_%d\n", user4.day, user4.month, user4.year);
                fclose(fptr4);
                break;
        }
    }while (choice != 6);
    fclose(fptrM4);
}
void userData5() {
    double money, money1, cache, cache1;
    double percentage1, percentage;
    int choice, choiceSave = 0, month;
    int specifiedMonth2, specifiedMonth1;
    double withdrawalAmount = 0, depositAmount = 0;
    accountAmount userDataMoney5, monthSet5, monthSet52, moneyY5, moneyY52;
    FILE *fptr5;
    FILE *fptrM5;
    fptrM5 = fopen("accountAmount5.txt", "w+");
    FILE *fptrMS5;
    fptrMS5 = fopen("accountAmount5.txt", "w+");

    do {
        printf("1: Deposit money into your account\n");
        printf("2: Withdraw money\n");
        printf("3: Checking account balance\n");
        printf("4: Bank savings\n");
        printf("5: Profile user\n");
        printf("6: Log out\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            fptrM5 = fopen("accountAmount5.txt", "r+");
            if (fptrM5 == NULL) {
            printf("Error opening file!\n");
            exit(1);
            }

            printf("Please enter the purchase amount to deposit into your account\n");
            scanf("%lf", &depositAmount);
            getchar();
            fscanf(fptrM5, "%lf", &userDataMoney5.money);
            cache = userDataMoney5.money;
            cache += depositAmount;
            userDataMoney5.money = cache;
            rewind(fptrM5);

            fprintf(fptrM5, "%lf", userDataMoney5.money);
            printf("Deposit to your account successfully!\n");
            fclose(fptrM5);
            break;

        case 2:
            fptrM5 = fopen("accountAmount5.txt", "r+");
            if (fptrM5 == NULL) {
            printf("Error opening file!\n");
            exit(1);
            }

            printf("Enter the amount you want to withdraw\n");
            scanf("%lf", &withdrawalAmount);
            getchar();

            fscanf(fptrM5, "%lf", &userDataMoney5.money);
            //fseek(fptrM1, 0, SEEK_SET);
            cache = userDataMoney5.money;
            cache -= withdrawalAmount;
            userDataMoney5.money = cache;
            rewind(fptrM5);
            fprintf(fptrM5, "%lf", userDataMoney5.money);
            printf("Take money from account successfully!\n");
            fclose(fptrM5);
            break;

        case 3:
            fptrM5 = fopen("accountAmount5.txt", "r");
            if (fptrM5 == NULL) {
            printf("Error opening file!\n");
            exit(1);
            }

            printf("The current balance in your account is: ");
            fscanf(fptrM5, "%lf", &userDataMoney5.money);
            printf("%lf\n", userDataMoney5.money);

            fclose(fptrM5);
            break;
        case 4:
            do {
            monthSet5.monthSet = count_months_since_epoch();
            printf("Welcome to Ray Bank's savings account\n");
            printf("-------------------------------------------\n");
            printf("Please choose your savings deposit term\n");
            printf("1: 6 months\n");
            printf("*interest rate 4%%\n");
            printf("2: 12 months\n");
            printf("*interest rate 9%%\n");
            printf("3: Exit\n");
            scanf("%d", &choiceSave);
                switch (choiceSave)
                {
                case 1:
                    monthSet5.monthSet = count_months_since_epoch();
                    money1 = 0;
                    specifiedMonth1 = 0;
                    percentage1 = 0.04;
                    fptrM5 = fopen("saving5.txt", "w+");
                    fptrMS5 = fopen("accountAmount5.txt", "w+");
                    if (fptrM5 == NULL) {
                        printf("Error");
                    }
                    if (fptrMS5 == NULL) {
                        printf("Error!");
                    }
                    fseek(fptrMS5, 0, SEEK_END);
                    if (ftell(fptrMS5) > 0){
                        month = specifiedMonth1 - monthSet5.monthSet;
                        printf("You have already saved and the remaining time is: %d\n", month);
                    }
                    else {
                        printf("Please enter the amount you want to save\n");
                        scanf("%lf", &money1);
                        moneyY5.inputMoney = money1;
                        fscanf(fptrM5, "%ld", &userDataMoney5.money);
                        cache = userDataMoney5.money;
                        cache -= moneyY5.inputMoney;
                        userDataMoney5.money = cache;
                        fprintf(fptrMS5, "%lf", moneyY5.inputMoney);
                        fprintf(fptrMS5, "%d", 1, monthSet5.monthSet);
                        specifiedMonth1 = monthSet5.monthSet + 6;
                        if (specifiedMonth1 == monthSet5.monthSet) {
                            fscanf(fptrMS5, "%lf", &moneyY5.inputMoney);
                            cache1 = moneyY5.inputMoney;
                            cache = cache1 + (1.0 + percentage1);
                            userDataMoney5.money = cache;
                            printf("%lf", userDataMoney5.money);
                            monthSet5.monthSet = '\0';
                            cache1 = '\0';
                            moneyY5.inputMoney = cache1;
                            fprintf(fptrM5, "%d", monthSet5.monthSet);
                            fprintf(fptrM5, "%lf", userDataMoney5.money);
                        }
                    }

                    break;

                case 2:
                    monthSet5.monthSet = count_months_since_epoch();
                    money1 = 0;
                    specifiedMonth1 = 0;
                    percentage1 = 0.09;
                    fptrM5 = fopen("saving51.txt", "w+");
                    fptrMS5 = fopen("accountAmount5.txt", "r+");
                    if (fptrM5 == NULL) {
                        printf("Error");
                    }
                    if (fptrMS5 == NULL) {
                        printf("Error!");
                    }
                    fseek(fptrMS5, 0, SEEK_END);
                    if (ftell(fptrMS5) > 0){
                        month = specifiedMonth2 - monthSet52.monthSet;
                        printf("You have already saved and the remaining time is: %d\n", month);
                    }
                    else {
                        printf("Please enter the amount you want to save\n");
                        scanf("%lf", &money);
                        moneyY52.inputMoney = money;
                        fscanf(fptrM5, "%lf", &userDataMoney5.money);
                        cache = userDataMoney5.money;
                        cache -= moneyY5.inputMoney;
                        userDataMoney5.money = cache;
                        fprintf(fptrMS5, "%lf", moneyY5.inputMoney);
                        fprintf(fptrMS5, "%d", 1, monthSet5.monthSet);
                        specifiedMonth1 = monthSet5.monthSet + 12;
                        if (specifiedMonth1 == monthSet5.monthSet) {
                            fscanf(fptrMS5, "%lf", &moneyY5.inputMoney);
                            cache1 = moneyY5.inputMoney;
                            cache = cache + (1.0 + percentage1);
                            userDataMoney5.money = cache;
                            printf("%lf", userDataMoney5.money);
                            monthSet5.monthSet = '\0';
                            cache = '\0';
                            moneyY5.inputMoney = cache;
                            fprintf(fptrM5, "%d", monthSet5.monthSet);
                            fprintf(fptrM5, "%lf", userDataMoney5.money);
                        }
                    }

                    break;
                }
            }while (choiceSave != 3);
            break;
            case 5:

                fptr5 = fopen("proDataUser5.txt", "r");
                if (fptr5 == NULL) {
                    printf("Error: Cannot open");
                }
                userdata user5;
                if (fscanf(fptr5, "%49s", user5.account) != 1 ||
                    fscanf(fptr5, "%49s", user5.password) != 1 ||
                    fscanf(fptr5, "%49s", user5.email) != 1 ||
                    fscanf(fptr5, "%49s", user5.name) != 1 ||
                    fscanf(fptr5, "%d", &user5.day) != 1 ||
                    fscanf(fptr5, "%d", &user5.month) != 1 ||
                    fscanf(fptr5, "%d", &user5.year) != 1) {
                    printf("Error: Failed to read data from file");
                    fclose(fptr5);
                }
                printf("----------Your account information-----------------\n");
                printf("Pass: %s\n", user5.account);
                //printf("Account: %s\n", user5.phoneNumber);
                printf("Name: %s\n", user5.email);
                printf("Email: %s\n", user5.name);
                printf("Date of birth: %d_%d_%d\n", user5.day, user5.month, user5.year);
                fclose(fptr5);
                break;
        }
    }while (choice != 6);
    fclose(fptrM5);
}


//----------------------------------------------------------------
//khu vuc main chay chinh de manu
int main(int argc, char const *argv[])
{
    /* code */
    int input =0;
    FILE *fptr1 = fopen("userData1.text", "r");
    FILE *fptr2 = fopen("userData2.text", "r");
    FILE *fptr3 = fopen("userData3.text", "r");
    FILE *fptr4 = fopen("userData4.text", "r");
    FILE *fptr5 = fopen("userData5.text", "r");

    // if (fptr1 == NULL) {
    //     printf("Error logging into account 1 due to data problems, please try again later!");
    // }
    // if (fptr2 == NULL) {
    //     printf("Error logging into account 2 due to data problems, please try again later!");
    // }
    // if (fptr3 == NULL) {
    //     printf("Error logging into account 3 due to data problems, please try again later!");
    // }
    // if (fptr4 == NULL) {
    //     printf("Error logging into account 4 due to data problems, please try again later!");
    // }
    // if (fptr5 == NULL) {
    //     printf("Error logging into account 5 due to data problems, please try again later!");
    // }
        printf("Welcome to Ray bank\n");
        user1(fptr1, userData1);
    do{
        printf("Welcome to Ray bank\n");
        printf("-------------------------------------------------------------------\n");
        printf("Please select an existing account or you can create a new account\n");
        printf("1: user1\n");
        printf("2: user2\n");
        printf("3: user3\n");
        printf("4: user4\n");
        printf("5: user5\n");
        printf("Exit for Ray bank\n");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            user1(fptr1, userData1);
            break;
        case 2:
            user2(fptr2, userData2);
            break;
        case 3:
            user3(fptr3, userData3);
            break;
        case 4:
            user4(fptr4, userData4);
            break;
        case 5:
            user5(fptr5, userData5);
            break;
        case 6:
            break;
        default:
            printf("Please select again\n");
            break;
        }
    } while (input != 6);

    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
    fclose(fptr4);
    fclose(fptr5);

    printf("Goodbye and see you again");
    return 0;
}
