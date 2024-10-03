#include <game_utils.hpp>
#include <iostream>

void CursorCursorGotoXY(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

void SetCursor(bool visible, int size)
{
    if (size == 0)
        size = 20;

    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

void DrawBorder()
{
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            CursorGotoXY(0 + j, i);
            cout << "±";
            CursorGotoXY(WIN_WIDTH - j, i);
            cout << "±";
        }
    }
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        CursorGotoXY(SCREEN_WIDTH, i);
        cout << "±";
    }
}