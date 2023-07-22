#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#define UP 72
#define DOWN 80
#define ESC 27
#define ENTER 13

using namespace std;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);  // Получаем хэндл консоли

void GoToXY(short x, short y)
{
    SetConsoleCursorPosition(hStdOut, {x, y});
}

void ConsoleCursorVisible(bool show, short size)
{
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = show;
    structCursorInfo.dwSize = size;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

int main()
{
    SetConsoleTitle(L"Programm Title");
    system("CLS");
    setlocale(0, "Rus");
    ConsoleCursorVisible(false, 100);
    string Menu[] = { "New game", "Download", "Settings", "Exit" };
    int active_menu = 0;




    char ch;
    while (true)
    {
        int x = 50, y = 12;
        int i;
        for (int i = 0; i < size(Menu); i++)
        {
            if (i == active_menu)
            {
                SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            }
            else
            {
                SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
            }
            GoToXY(x, y++);
            cout << Menu[i] << endl;
        }

        ch = _getch();
        if (ch == -32) ch = _getch();
        switch (ch)
        {
        case ESC:
            exit(0);
        case UP:
            if (active_menu > 0)
            {
                --active_menu;
            }
            
            break;
        case DOWN:
            if (active_menu < size(Menu)-1)
            {
                ++active_menu;
            }
            break;
        case ENTER:
            switch (active_menu)
            {
            case 0:
            case 1:
            case 2:
                system("CLS");
                GoToXY(x, y);
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                cout << "You choose \"" << Menu[active_menu] << "\"";
                _getch();
                system("CLS");
                break;
            case 3:
                exit(0);
            }
            break;

        default:
            cout << "Code: " << (int)ch << endl;
        }
    }

    //_getch();

}
