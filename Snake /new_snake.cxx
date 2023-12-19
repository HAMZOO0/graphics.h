

#include <iostream>
#include <conio.h>
#include <graphics.h>
#include  <string>
using namespace std;


// ----------------------------------- Global variables -------------------------------------------------

const int ScreenWidth = 800, ScreenHeight = 600;

const int size = 10; // size of snake body block

int snakeX[100], snakeY[100]; // using an array for snake because it increases in length

int length = 2; // default length

int direction = 1; // 1: right, 2: down, 3: left, 4: up

int foodX, foodY;



// ----------------------------------------Functions---------------------------------------------------------

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
    setfillstyle(SOLID_FILL, RED); // Set fill style to solid and color to red

    for (int i = 0; i < length; i++)
    {    
        rectangle(snakeX[i], snakeY[i], snakeX[i] + size, snakeY[i] + size);
        floodfill(snakeX[i] + 1, snakeY[i] + 1, RED); // Fill the rectangle with red
    }
}


// Generate food rendering
void GenerateFood()
{
    // Set a random location for the food box inside the screen
    // Adjust the range to ensure that the food spawns away from the edges
    foodX = (rand() % ((ScreenWidth - 6 * size) / size) + 2) * size;
    foodY = (rand() % ((ScreenHeight - 6 * size) / size) + 2) * size;

    rectangle(foodX, foodY, foodX + size, foodY + size); // Draw the food box
}


// Main function -------------------------------------------------------------------------------------

int main()
{
    initwindow(ScreenWidth, ScreenHeight, "Snake Game"); // Set the main window size
    setbkcolor(CYAN);                                      // Set window color

    // Initialize snake position (head position)
    snakeX[0] = 100;
    snakeY[0] = 100;

    MENU();             // Call menu to show the main screen
    GenerateFood();     // Call this function to set the initial value of food

    while (1)
    {
        cleardevice();
        rectangle(10, 10, 780, 550);
                


        if (kbhit())
        {
            char key = getch();
            switch (key)
            {
            	
            case 'a':
            	if(direction == 1 )
            	{
				direction = 1 ;
            	 break;
				}
                direction = 3;            // a --> 3 // left 
                break;
                
            case 'd':
            	if(direction == 3 )
            	{
				direction = 3 ;
            	 break;
				}
                direction = 1;           // d --> 1 // right  
                break;
                
            case 'w':
            	if(direction == 2 )
            	{
				direction = 2 ;
            	 break;
				}
                direction = 4;                 // w --> 4 //  up   
                break;
                
            case 's':
            	
            	if(direction == 4 )
            	{
				direction = 4 ;
            	 break;
				}
                direction = 2;                           // s --> 4 //   down     
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
        if (snakeX[0] >= 780 || snakeX[0] <= 10 || snakeY[0] >= 550 || snakeY[0] < 10)
        {
            setcolor(RED);
            settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
            outtextxy(200, 200, "GAME OVER");
            delay(2000);
            closegraph();
            break;
        }
        
        
	// food collion 
	if (snakeX[0] == foodX && snakeY[0] == foodY)
{
    GenerateFood();
    length++;

 
}


// snake collion 
for (int i = 1; i < length -1 ; i++)
        {
            if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]  )
            {
            	setcolor(RED);
            settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
            outtextxy(200, 200, "GAME OVER");
            delay(2000);
            closegraph();
            break;
            	
			}
        }


        rectangle(foodX, foodY, foodX + size, foodY + size); // food gernate

        draw_snake(); // snake draw

        delay(50);
        
    } // close loop

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
