#include <iostream>
#include <Windows.h>
#include <conio.h>

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
    ConsoleCursorVisible(false, 100);
    GoToXY(50, 13);
    std::cout << "Hello World!\n";
    _getch();

}
