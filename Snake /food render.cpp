#include <iostream>
#include <conio.h>
#include <graphics.h>

const int screenWidth = 800;
const int screenHeight = 600;
int foodX , foodY ; 

void generateFood() {
    foodX = (rand() % screenWidth) ;
    foodY = (rand() % screenHeight) ;
        setcolor(GREEN);
    rectangle(foodX, foodY, foodX + 10, foodY + 10);
    
    
}

int main() {
    initwindow(screenWidth, screenHeight, "Snake Game");
        
while(1){
	    getch();
	  	cleardevice();
       generateFood();

}

    return 0;
}
