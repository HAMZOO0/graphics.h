#include <iostream>
#include <conio.h>
#include <graphics.h>

using namespace std;

const int ScreenWidth = 800, ScreenHeight = 600;

const int size = 20; // size of snake body block

int snakeX[100], snakeY[100]; // using an array for snake because it increases in length

int length = 2; // default length

int direction = 1; // 1: right, 2: down, 3: left, 4: up

int foodX, foodY;

// Main menu
void MENU()
{
    setcolor(RED);
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 4);
    outtextxy(200, 200, "Press any key to continue");
    getch();
}

// Draw the snake
void draw_snake()
{
    for (int i = 0; i < length; i++)
    {
        rectangle(snakeX[i], snakeY[i], snakeX[i] + size, snakeY[i] + size);
    }
}

// Generate food rendering
void GenerateFood()
{
    // Set a random location for the food box on the x-y axis
    foodX = rand() % (600/size)*size;
    foodY = rand() % (450/size)*size;
    rectangle(foodX, foodY, foodX + size, foodY + size);
}

// Main function
int main()
{
    initwindow(ScreenWidth, ScreenHeight, "Snake Game"); // Set the main window size
    setbkcolor(GREEN);                                      // Set window color

    // Initialize snake position (head position)
    snakeX[0] = 100;
    snakeY[0] = 100;

    MENU();             // Call menu to show the main screen
    GenerateFood();     // Call this function to set the initial value of food

    while (1)
    {
        cleardevice();
        rectangle(10, 10, 780, 500);

        if (kbhit())
        {
            char key = getch();
            switch (key)
            {
            case 'a':
                direction = 3;
                break;
            case 'd':
                direction = 1;
                break;
            case 'w':
                direction = 4;
                break;
            case 's':
                direction = 2;
                break;
            }
        }

        // Move the snake: previous block position to new
        for (int i = length - 1; i > 0; i--)
        {
            snakeX[i] = snakeX[i - 1];
            snakeY[i] = snakeY[i - 1];
        }

        switch (direction)
        {
        case 1:
            snakeX[0] += size;
            break;
        case 2:
            snakeY[0] += size;
            break;
        case 3:
            snakeX[0] -= size;
            break;
        case 4:
            snakeY[0] -= size;
            break;
        }

        // Wall collision
        if (snakeX[0] >= 780 || snakeX[0] <= 10 || snakeY[0] >= 500 || snakeY[0] < 10)
        {
            setcolor(RED);
            settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
            outtextxy(200, 200, "GAME OVER");
            delay(2000);
            closegraph();
            break;
        }
	
	if(snakeX[0] == foodX && snakeY[0] == foodY )
	{
		  GenerateFood(); 
		  length++;
	}
	
        rectangle(foodX, foodY, foodX + size, foodY + size); // food gernate

        draw_snake(); // snake draw
        delay(200);
    } // close loo

    closegraph();
    return 0;
}

/*
Wall collison system how it works 
Condition (snakeX[0] >= WIDTH || snakeX[0] < 0 || snakeY[0] >= HEIGHT || snakeY[0] < 0):
snakeX[0] >= WIDTH: Checks if the head of the snake has moved beyond the right edge of the window.
snakeX[0] < 0: Checks if the head of the snake has moved beyond the left edge of the window.
snakeY[0] >= HEIGHT: Checks if the head of the snake has moved beyond the bottom edge of the window.
snakeY[0] < 0: Checks if the head of the snake has moved beyond the top edge of the window.
*/
