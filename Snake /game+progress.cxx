#include <iostream>
#include <conio.h>
#include <graphics.h>

using namespace std;


const int size = 20; // size of snake body block 

int snakeX[100], snakeY[100]; // we use array for snake bcz it incr its length 

int length = 2; // default length 

int direction = 1; // 1: right, 2: down, 3: left, 4: up 

//int foodX, foodY;

void MENU()
{
     cleardevice();
     //setcolor(RED);
	settextstyle(EUROPEAN_FONT,HORIZ_DIR,4);
	outtextxy(200,200,"press any key to continue");
	
getch();
}



// here we draw snake
 void draw_snake()
 {
 	for (int i = 0; i < length; i++) {
        rectangle(snakeX[i], snakeY[i], snakeX[i] + size, snakeY[i] + size);    
    
    }
}



// main 
int main() {
   initwindow(800,600,"$"); // main window size 
    setbkcolor(GREEN); // window color 

    // Initialize snake position (head position )
    snakeX[0] = 100;
    snakeY[0] = 100;
    
 //   MENU();
    
    while(1){
    	    	cleardevice();
    	    	    rectangle(10,10,780,500);

    	if (kbhit()) {
            char key = getch();
            switch (key) {
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

//         Move the snake        previs block pos to new 
        for (int i = length - 1; i > 0; i--) {
            snakeX[i] = snakeX[i - 1];
            snakeY[i] = snakeY[i - 1];
        }

        switch (direction) {
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
        
        // WAll collison 
	if(snakeX[0] >= 780 || snakeX[0]<= 10 || snakeY[0] >= 500 || snakeY[0]  < 10  )
	{
	setcolor(RED);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
	outtextxy(200,200,"GAME OVER");
	delay(2000);
	closegraph();
	break;
/*
Condition (snakeX[0] >= WIDTH || snakeX[0] < 0 || snakeY[0] >= HEIGHT || snakeY[0] < 0):
snakeX[0] >= WIDTH: Checks if the head of the snake has moved beyond the right edge of the window.
snakeX[0] < 0: Checks if the head of the snake has moved beyond the left edge of the window.
snakeY[0] >= HEIGHT: Checks if the head of the snake has moved beyond the bottom edge of the window.
snakeY[0] < 0: Checks if the head of the snake has moved beyond the top edge of the window.
*/
}
	
draw_snake();
delay(50);
}
    closegraph();
    return 0;
}
//500 480 520 500
//480 480 500 500
//520 480 540 500
//500 480 520 500
//540 480 560 500
