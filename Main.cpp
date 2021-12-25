#include <conio.h>
#include <iostream>
#include<stdio.h>
#include <ctime>
#include <windows.h>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define SPACE 32



void setCursorPointer(int x = 0, int y = 0)
{
    HANDLE handle;
    COORD coordinates;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(handle, coordinates);
}

void buildSpaceShip(int& x1, int& y1, int& x2, int& y2, int& x3, int& y3, int& x4, int& y4, int &x5, int &y5, int key)
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
    printf("%c", 17);
    setCursorPointer(x2, y2);
    printf("     %c", 16);                     //    printf("%c%c%c%c%c", 17, 30, 223, 30, 16);
    setCursorPointer(x3, y3);
    printf("%c%c%c", 30,223,30);
    setCursorPointer(x4, y4);
    printf("  %c   ", 4);
    setCursorPointer(x5, y5);
    printf("   %c  ", 30);
}

void createAliens(char arr[][20]) {
    int x = 0;
    int y = 0;

    for (int i = 0; i < 400; i++) {
        x = rand() % 100;
        y = rand() % 20;

        setCursorPointer(x, y);

        arr[x][y] = '+';
        cout << arr[x][y];
    }
}

int main()
{
    srand(time(0));

    int key = 0;
    int x1 = 30, y1 = 29, x2 = 31, y2 = 29, x3 = 32, y3 = 29, x4 = 31, y4 = 28, x5 = 30, y5 = 27;
    char aliens[100][20];

    buildSpaceShip(x1, y1, x2, y2, x3, y3, x4, y4,x5,y5, 0);

    createAliens(aliens);


    while (1)
    {
        switch ((key = _getch())) {
        case KEY_LEFT:
            if (x1 == 0) {
                break;
            }

            x1--;
            x2--;
            x3--;
            x4--;
            x5--;
            buildSpaceShip(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5 ,key);

            break;
        case KEY_RIGHT:
            if (x3 == 100) {
                break;
            }

            x1++;
            x2++;
            x3++;
            x4++;
            x5++;
            buildSpaceShip(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, key);
            break;
        }

    }

    return 0;
}
