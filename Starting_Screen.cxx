#include<graphics.h>
#include<conio.h>

int main()
{
	// window open (width (pixel ), height , window name)
  initwindow(1000,1000,"Snake ");
  putpixel(100,100,WHITE); // it show a white pixel on 100 (x-axis) X  100(y-axis) 
  
 // cleardevice();         // this function is use to clear 
  putpixel(110,100,RED);

   getch();
}
