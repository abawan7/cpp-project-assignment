#include <conio.h>
#include<stdio.h>
#include <iostream>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include <time.h>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define SPACE 32

void shootAlien(char aliens[][210], int x, int y, int& x1, int& y1, int& x2, int& y2, int& x3, int& y3, int& x4, int& y4, int& x5, int& y5, int key);

int getInput(int key)
{
    if (_kbhit())
    {
        key = _getch();

        return key;
    }

    return false;
};

void setCursorPointer(int x = 0, int y = 0)
{
    HANDLE handle;
    COORD coordinates;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(handle, coordinates);
}

void drawWindowFrame(int a_x, int a_y, int b_x, int b_y)
{
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

    for (int i = a_x; i < b_x; i++)
    {
        setCursorPointer(i, a_y); printf("%c", 205);
        setCursorPointer(i, b_y); printf("%c", 205);
    }
    for (int i = a_y; i < b_y; i++)
    {
        setCursorPointer(a_x, i); printf("%c", 186);
        setCursorPointer(b_x, i); printf("%c", 186);
    }
    setCursorPointer(a_x, a_y); printf("%c", 201);
    setCursorPointer(b_x, a_y); printf("%c", 187);
    setCursorPointer(a_x, b_y); printf("%c", 210);
    setCursorPointer(b_x, b_y); printf("%c", 188);
}

void welcomeMessage()
{
    int x = 77;
    int y = 20;
    setCursorPointer(x, y); printf(" _____                    _____ _           _           ");
    setCursorPointer(x, y + 1); printf("|   __|___ ___ ___ ___   |   __| |_ ___ ___| |_ ___ ___ ");
    setCursorPointer(x, y + 2); printf("|__   | . | .'|  _| -_|  |__   |   | . | . |  _| -_|  _|");
    setCursorPointer(x, y + 3); printf("|_____|  _|__,|___|___|  |_____|_|_|___|___|_| |___|_|  ");
    setCursorPointer(x, y + 4); printf("      |_|");
    setCursorPointer(x, y + 6); printf("                 Press any key to play");
    setCursorPointer(x, y + 7); printf("               developed by Abdullah Awan     ");
}

void buildSpaceShip(int& x1, int& y1, int& x2, int& y2, int& x3, int& y3, int& x4, int& y4, int& x5, int& y5, int key)
{
    if (key == 75) {
        setCursorPointer(x1 + 1, y1);
        cout << " ";
        setCursorPointer(x2 + 1, y2);
        cout << " ";
        setCursorPointer(x3 + 1, y3);
        cout << " ";
        setCursorPointer(x4 + 1, y4);
        cout << " ";
        setCursorPointer(x5 + 1, y5);
        cout << " ";
    }

    if (key == 77) {
        setCursorPointer(x1 - 1, y1);
        cout << " ";
        setCursorPointer(x2 - 1, y2);
        cout << " ";
        setCursorPointer(x3 - 1, y3);
        cout << " ";
        setCursorPointer(x4 - 1, y4);
        cout << " ";
        setCursorPointer(x5 - 1, y5);
        cout << " ";
    }

    setCursorPointer(x1, y1);
    printf("%c", 17);                     //  printf("%c", 17);
    setCursorPointer(x2, y2);
    printf("%c", 223);                 //  printf("     %c", 16);
    setCursorPointer(x3, y3);
    printf("%c", 16);
    setCursorPointer(x4, y4);
    printf("%c", 4);                 //  printf("  %c   ", 4);
    setCursorPointer(x5, y5);
    printf("%c", 30);               //   printf("   %c  ", 30);
}

void createAliens(char aliens[][210]) {
    int x = 0;
    int y = 0;

    for (int i = 0; i < 47; i++) {
        for (int j = 0; j < 210; j++) {
            aliens[i][j] = ' ';
        }
    }

    for (int i = 0; i < 500; i++) {
        x = rand() % 209;
        y = rand() % 14;

        setCursorPointer(x, y);

        aliens[y][x] = 'X';
        cout << aliens[y][x];
    }
}

void performOperation(char aliens[][210], int& x1, int& y1, int& x2, int& y2, int& x3, int& y3, int& x4, int& y4, int& x5, int& y5, int key, bool isShoot)
{
    key = getInput(key);

    if (isShoot && key == SPACE) {
        return;
    }

    switch (key) {
    case 75:
        if (x1 == 0) {
            break;
        }

        x1--;
        x2--;
        x3--;
        x4--;
        x5--;
        buildSpaceShip(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, key);

        break;
    case KEY_RIGHT:
        if (x3 == 210) {
            break;
        }

        x1++;
        x2++;
        x3++;
        x4++;
        x5++;
        buildSpaceShip(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, key);
        break;
    case SPACE:
        shootAlien(aliens, x5, y5, x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, key);
    case NULL:
        break;
    }
}

void shootAlien(char aliens[][210], int x, int y, int& x1, int& y1, int& x2, int& y2, int& x3, int& y3, int& x4, int& y4, int& x5, int& y5, int key) {
    while (aliens[y][x] != 'X') {
        performOperation(aliens, x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, key, true);

        if (y == 0) {
            break;
        }

        y--;

        setCursorPointer(x, y);
        printf("%c", 30);

        Sleep(40);

        setCursorPointer(x, y);
        cout << " ";
    }
    aliens[y][x] = ' ';
}

int main()
{
    system("Color 70");
    system("mode 650");

    drawWindowFrame(0, 1, 210, 50);
    welcomeMessage();
    _getch();

    system("cls");

    srand(time(0));

    int key = 0;
    int x1 = 73, y1 = 48, x2 = 75, y2 = 48, x3 = 77, y3 = 48, x4 = 75, y4 = 47, x5 = 75, y5 = 46;
    char aliens[47][210] = { 0 };

    createAliens(aliens);

    buildSpaceShip(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, 0);

    while (1)
    {
        performOperation(aliens, x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, key, false);
    }
    return 0;
}