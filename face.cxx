#include<graphics.h>
#include<conio.h>

int main()
{
	// window open (width (pixel ), height , window name)
  initwindow(1000,1000,"Snake ");

circle(500,300,200);
circle(400 ,250, 10);
circle(600 ,250, 10);

arc(500,400,0,180,100); // arc (x , y , starting angle (90 ) , end angle (180) , radius/size/(100 pix))



   getch();
}
