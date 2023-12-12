int main() {
   initwindow(800,600,"$"); // main window size 
	
	setcolor(RED);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
	
	outtextxy(200,200,"GAME OVER");
	getch();
    closegraph();
    return 0;
}
