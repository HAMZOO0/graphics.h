#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;

const int MAX_SEGMENTS = 10;

struct SnakeSegment {
    int x, y;
};
const int screenWidth = 800;
const int screenHeight = 600;
int foodX , foodY ; 


void generateFood() 
{
    foodX = (5465465 % screenWidth) ;
    foodY = (45645564556% screenHeight) ;
    
    rectangle(foodX, foodY, foodX + 20, foodY + 20);
}


int main() {
    initwindow(screenWidth, screenHeight, "SNAKE.CPP");
    setbkcolor(GREEN);
    cleardevice();
    
    
    setcolor(RED);
	setfillstyle( SOLID_FILL, RED); // this is function to fill a RED colour inside the box  

    SnakeSegment snake[MAX_SEGMENTS] = { {60,60},{80,60},{100,60} };

    while (1) {
    	
        cleardevice();
         generateFood() ;
        // Draw and fill the snake segments
        for (int i = 0; i < MAX_SEGMENTS; ++i) {
            rectangle(snake[i].x, snake[i].y, snake[i].x + 20, snake[i].y + 20);
            floodfill(snake[i].x + 10, snake[i].y + 10, RED);
        }

        // Check the direction and move the entire snake
        for (int i = MAX_SEGMENTS - 1; i > 0; --i) {
            snake[i].x = snake[i - 1].x;
            snake[i].y = snake[i - 1].y;
        }

        if (GetAsyncKeyState(VK_RIGHT)) {
            snake[0].x += 20; // right 
        }
        else if (GetAsyncKeyState(VK_LEFT)) {
            snake[0].x -= 20;//left
        }
        else if (GetAsyncKeyState(VK_UP)) {
            snake[0].y -= 20;//down
        }
        else if (GetAsyncKeyState(VK_DOWN)) {
            snake[0].y += 20; //up
       }
       

        delay(60);
    }

    getch();
    closegraph();

    return 0;
}
