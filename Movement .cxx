//circle
#include <graphics.h>
int main() {
initwindow(500,500);
setbkcolor(RED);
cleardevice();

  // circle 
int x = 100,y=100;
while(1)
{
	cleardevice();
	circle(x,y,50);
	if(GetAsyncKeyState(VK_RIGHT))
	x+=10;
	
	else if(GetAsyncKeyState(VK_LEFT))
	x-=10;
	
	
	else if(GetAsyncKeyState(VK_UP))
	y-=10;
	
	else if(GetAsyncKeyState(VK_DOWN))
	y+=10;
	
	if(GetAsyncKeyState(VK_RETURN))
	break;
	
	delay(10);
	
	
}

    closegraph();
}

// rectanlge 


int x1 = 100 , y1=100 , x2 = 150 ,  y2 = 150 ;
while(1)
{
	cleardevice();
	rectangle(x1,y1,x2,y2);
	if(GetAsyncKeyState(VK_RIGHT)){
	
	x1+=10;
	x2+=10;
}
	
	else if(GetAsyncKeyState(VK_LEFT)){
	
    x1-=10;
	x2-=10;	
}
	else if(GetAsyncKeyState(VK_UP)){
	
	y1-=10;
	y2-=10;
}
	else if(GetAsyncKeyState(VK_DOWN))
	{
	
     y1+=10;
	y2+=10;
}
	if(GetAsyncKeyState(VK_RETURN))
	break;
	
	delay(10);
	
	
}
