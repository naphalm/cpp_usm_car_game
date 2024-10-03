#include <game_objects.hpp>
#include <iostream>

Enemy enemies = new Enemy;
Car c = new Car;
void GenPlayerCar()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            gotoxy(j + c.position, i + 22);
            cout << c.model[i][j];
        }
    }
    return c;
}

void GenEnemy(int ind)
{
    enemies.x[ind] = 17 + rand() % (33);
}

void DrawEnemy(int ind)
{
    if (enemyFlag[ind] == true)
    {
        gotoxy(enemies.x[ind], enemies.y[ind]);
        cout << "****";
        gotoxy(enemies.x[ind], enemies.y[ind] + 1);
        cout << " ** ";
        gotoxy(enemies.x[ind], enemies.y[ind] + 2);
        cout << "****";
        gotoxy(enemies.x[ind], enemies.y[ind] + 3);
        cout << " ** ";
    }
}

void EraseEnemy(int ind)
{
    if (enemyFlag[ind] == true)
    {
        gotoxy(enemies.x[ind], enemies.y[ind]);
        cout << "    ";
        gotoxy(enemies.x[ind], enemies.y[ind] + 1);
        cout << "    ";
        gotoxy(enemies.x[ind], enemies.y[ind] + 2);
        cout << "    ";
        gotoxy(enemies.x[ind], enemies.y[ind] + 3);
        cout << "    ";
    }
}

void ResetEnemy(int ind)
{
    EraseEnemy(ind);
    enemies.y[ind] = 1;
    GenEnemy(ind);
}

void DrawCar()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            gotoxy(j + c.position, i + 22);
            cout << c.model[i][j];
        }
    }
}

void EraseCar()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            gotoxy(j + c.position, i + 22);
            cout << " ";
        }
    }
}
