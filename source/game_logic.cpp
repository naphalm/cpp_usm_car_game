#include <game_logic.hpp>
#include <game_objects.hpp>
#include <dos.h>
#include <windows.h>

bool Collision()
{
    if (enemyY[0] + 4 >= 23)
    {
        if (enemyX[0] + 4 - carPos >= 0 && enemyX[0] + 4 - carPos < 9)
        {
            return true;
        }
    }
    return false;
}

void GameOver()
{
    system("cls");
    cout << endl;
    cout << "\t\t--------------------------" << endl;
    cout << "\t\t-------- Game Over -------" << endl;
    cout << "\t\t--------------------------" << endl
         << endl;
    cout << "\t\tPress any key to go back to menu.";
    getch();
}

void UpdateScore()
{
    gotoxy(WIN_WIDTH + 7, 5);
    cout << "Score: " << score << endl;
}

void Instrutions()
{
    system("cls");
    cout << "Instructions";
    cout << "\n----------------";
    cout << "\n Avoid Cars by moving left or right. ";
    cout << "\n\n Press 'a' to move left";
    cout << "\n Press 'd' to move right";
    cout << "\n Press 'escape' to exit";
    cout << "\n\nPress any key to go back to menu";
    getch();
}

void Play()
{
    carPos = -1 + WIN_WIDTH / 2;
    score = 0;
    enemyFlag[0] = 1;
    enemyFlag[1] = 0;
    enemyY[0] = enemyY[1] = 1;

    system("cls");
    drawBorder();
    updateScore();
    genEnemy(0);
    genEnemy(1);

    gotoxy(WIN_WIDTH + 7, 2);
    cout << "Car Game";
    gotoxy(WIN_WIDTH + 6, 4);
    cout << "----------";
    gotoxy(WIN_WIDTH + 6, 6);
    cout << "----------";
    gotoxy(WIN_WIDTH + 7, 12);
    cout << "Control ";
    gotoxy(WIN_WIDTH + 7, 13);
    cout << "-------- ";
    gotoxy(WIN_WIDTH + 2, 14);
    cout << " A Key - Left";
    gotoxy(WIN_WIDTH + 2, 15);
    cout << " D Key - Right";

    gotoxy(18, 5);
    cout << "Press any key to start";
    getch();
    gotoxy(18, 5);
    cout << "                      ";

    while (1)
    {
        if (kbhit())
        {
            char ch = getch();
            if (ch == 'a' || ch == 'A')
            {
                if (carPos > 18)
                    carPos -= 4;
            }
            if (ch == 'd' || ch == 'D')
            {
                if (carPos < 50)
                    carPos += 4;
            }
            if (ch == 27)
            {
                break;
            }
        }

        drawCar();
        drawEnemy(0);
        drawEnemy(1);
        if (collision() == 1)
        {
            gameover();
            return;
        }
        Sleep(50);
        eraseCar();
        eraseEnemy(0);
        eraseEnemy(1);

        if (enemyY[0] == 10)
            if (enemyFlag[1] == 0)
                enemyFlag[1] = 1;

        if (enemyFlag[0] == 1)
            enemyY[0] += 1;

        if (enemyFlag[1] == 1)
            enemyY[1] += 1;

        if (enemyY[0] > SCREEN_HEIGHT - 4)
        {
            resetEnemy(0);
            score++;
            updateScore();
        }
        if (enemyY[1] > SCREEN_HEIGHT - 4)
        {
            resetEnemy(1);
            score++;
            updateScore();
        }
    }
}