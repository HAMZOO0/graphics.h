#include <graphics.h>

int main() {
initwindow(500,500);
setbkcolor(GREEN);
cleardevice();

int x =100; rectangle(x,50,x+100,200);
circle(x,220,20);
circle(x+100,220,20);
while(1)
{
	cleardevice();
setcolor(RED);
rectangle(x,50,x+100,200);
circle(x,220,20);
circle(x+100,220,20);
	
	if(GetAsyncKeyState(VK_RIGHT)){
	
	x+=10;
}
	
	else if(GetAsyncKeyState(VK_LEFT)){
	
    x-=10;
}
	if(GetAsyncKeyState(VK_RETURN))
	break;
	
	delay(10);
	
	
}
getch();
    closegraph();
}
