#include<graphics.h>
#include<conio.h>

int main()
{
  initwindow(600,600,"Snake "); // window  crate
  
  setcolor(GREEN); // boarder 
circle(100,100,100);
setfillstyle( LINE_FILL , RED); // this is function to fill a RED colour inside the box  
floodfill(100,100, GREEN ); // green is also a boarder (100 , 100 is circle inside location to fill )


   getch();
}
