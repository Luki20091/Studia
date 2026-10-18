#include <ctype.h>
#include <errno.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <windows.h>

#define MENU_INPUT_SIZE 64

static int menu(void);
static void discard_line(void);
static void wait_for_enter(void);
static void zadanie1(void);
static void zadanie2(void);
static void zadanie3(void);
static void zadanie4(void);
static void zadanie5(void);
static void zadanie6(void);
static void zadanie7(void);
static float circleArea(int r);





int main(void) {
    setlocale(LC_ALL, "Polish");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    for (;;) {
        int choice = menu();

        system("cls");
        if (choice != 0) { 
            printf("[     Wybrano zadanie: %d     ]\n", choice);
            printf("\n");
        }

        switch (choice) {
            case 0:
                printf("[----- Koniec programu. -----]\n");
                return 0;
            case 1:
                zadanie1();
                break;
            case 2:
                zadanie2();
                break;
            case 3:
                zadanie3();
                break;
            case 4:
                zadanie4();
                break;
            case 5:
                zadanie5();
                break;
            case 6:
                zadanie6();
                break;
            case 7:
                zadanie7();
                break;
        }
        system("cls");
    }
}





static int menu(void) {
    char input[MENU_INPUT_SIZE];
    char *end;
    long choice;

    for (;;) {
        printf("[    Æwiczenia 17.10.2026    ]\n");
        printf("\n");
        printf("1. Zadanie 1      5. Zadanie 5\n");
        printf("2. Zadanie 2      6. Zadanie 6\n");
        printf("3. Zadanie 3      7. Zadanie 7\n");
        printf("4. Zadanie 4      0. WyjdŸ\n");
        printf("\n");
        printf("Wybierz: ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            return 0;
        }

        if (strchr(input, '\n') == NULL) {
            discard_line();
            system("cls");
            printf("Nieprawid³owa opcja. WprowadŸ liczbê od 0 do 7.\n\n");
            continue;
        }

        errno = 0;
        choice = strtol(input, &end, 10);

        while (isspace((unsigned char)*end)) {
            end++;
        }

        if (errno == 0 && end != input && *end == '\0' && choice >= 0 && choice <= 7) {
            return (int)choice;
        }

        system("cls");
        printf("Nieprawid³owa opcja. WprowadŸ liczbê od 0 do 7.\n\n");
    }
}





static void discard_line(void) {
    int character;

    while ((character = getchar()) != '\n' && character != EOF) {
    }
}


static void wait_for_enter(void) {
    printf("\nNaciœnij Enter, aby wróciæ do menu...\n");
    discard_line();
}








static void zadanie1(void) {
    printf("£ukasz Kucharczyk 1IZ12A\n");
    
    wait_for_enter();
}


static void zadanie2(void) {
    int a = 12;
    int h = 5;
    int area = (a * h) / 2;
    printf("a = %d\nh = %d\npole = %d\n", a, h, area);

    wait_for_enter();
}


static void zadanie3(void) {
    int age = 20;
    float height = 173.5f;
    printf("£ukasz Kucharczyk, %d lat, %.1f cm\n", age, height);

    wait_for_enter();
}


static void zadanie4(void) {
    int x = 15;
    int y = 4;
    printf("x = %d, y = %d\n", x, y);
    printf("Dodawanie: %d\n", x + y);
    printf("Odejmowanie: %d\n", x - y);
    printf("Mno¿enie: %d\n", x * y);
    printf("Dzielenie: %d, reszta: %d\n", x / y, x % y);

    wait_for_enter();
}






static void zadanie5(void) {
    int r = 6;
    printf("Pole dla ko³a r=%d, jest równe: %.2f\n", r, circleArea(r));
    r = 11;
    printf("Pole dla ko³a r=%d, jest równe: %.2f\n", r, circleArea(r));
    
    wait_for_enter();
}

static float circleArea(int r) {
    const float pi = 3.14159f;
    return pi * r * r;
}


static void zadanie6(void) {
    int age = 20;
    bool isInRange = age >= 18 && age <= 65;
    printf("Czy wiek %d mieœci siê w przedziale <18, 65>? \nWynik: %d\n", age, isInRange);

    wait_for_enter();
}


static void zadanie7(void) {
    int a = 2;
    printf("Czy liczba %d jest parzysta? \nWynik: %s\n", a, ((a % 2) == 0) ? "Prawda" : "Fa³sz");

    wait_for_enter();
}


















