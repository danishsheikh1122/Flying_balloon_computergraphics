#include<graphics.h>
#include<alloc.h>
#include<conio.h>
#include<dos.h>

void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	setcolor(WHITE);

	outtextxy(0,1,"COLOURED BALLOONS");
	void *balloon[4];
	setfillstyle(SLASH_FILL,RED);
	setcolor(RED);
	fillellipse(75,200,10,15);
	line(75,215,75,250);
	balloon[0]=malloc(imagesize(60,180,90,255));
	getimage(60,180,90,255,balloon[0]);

	setfillstyle(CLOSE_DOT_FILL,YELLOW);
	setcolor(YELLOW);
	circle(200,350,10);
	line(200,360,200,400);
	floodfill(200,350,YELLOW);
	balloon[1]=malloc(imagesize(190,340,210,400));
	getimage(190,340,210,400,balloon[1]);

	setfillstyle(SOLID_FILL,BLUE);
	setcolor(BLUE);
	fillellipse(330,300,10,15);
	fillellipse(330,320,10,15);
	fillellipse(330,340,10,15);
	line(330,355,330,400);
	balloon[2]=malloc(imagesize(320,280,340,400));
	getimage(320,280,340,400,balloon[2]);

	setfillstyle(XHATCH_FILL,GREEN);
	setcolor(GREEN);
	circle(500,400,25);
	line(500,425,500,475);
	floodfill(500,400,GREEN);
	balloon[3]=malloc(imagesize(475,375,525,475));
	getimage(475,375,525,475,balloon[3]);

	int x[4]={60,190,320,475};
	int y[4]={180,340,280,375};

	int x1[4]={250,400,120,15};
	int y1[4]={290,185,190,350};

	while(!kbhit())
	{
		for(int i=0;i<4;i++)
		{
			if(y[i]<0)
			{
				x[i]+=50;
				if(x[i]>550)
					x[i]=50;
				y[i]=470;
			}
			if(y1[i]<0)
			{
				x1[i]+=50;
				if(x1[i]>550)
					x1[i]=50;
				y1[i]=470;

			}
		}
		i=0;

		//RED BALLOON
		putimage(x[i],y[i]--,balloon[i],XOR_PUT);
		putimage(x[i],y[i],balloon[i],OR_PUT);
		putimage(x1[i],y1[i]--,balloon[i],XOR_PUT);
		putimage(x1[i],y1[i],balloon[i],OR_PUT);
		i++;
		//YELLOW BALLON
		putimage(x[i],y[i]--,balloon[i],XOR_PUT);
		putimage(x[i],y[i],balloon[i],OR_PUT);
		putimage(x1[i],y1[i]--,balloon[i],XOR_PUT);
		putimage(x1[i],y1[i],balloon[i],OR_PUT);
		i++;
		//BLUE BALLOON
		putimage(x[i],y[i]--,balloon[i],XOR_PUT);
		putimage(x[i],y[i],balloon[i],OR_PUT);
		putimage(x1[i],y1[i]--,balloon[i],XOR_PUT);
		putimage(x1[i],y1[i],balloon[i],OR_PUT);
		i++;
		//GREEN BALLOON
		putimage(x[i],y[i]--,balloon[i],XOR_PUT);
		putimage(x[i],y[i],balloon[i],OR_PUT);
		putimage(x1[i],y1[i]--,balloon[i],XOR_PUT);
		putimage(x1[i],y1[i],balloon[i],OR_PUT);
		delay(10);
	}
	closegraph();
}







