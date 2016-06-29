/*
			      SAINAG GANESH SHETTY

				  XII M.P.C

				   4661965

*/
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<graphics1.h>
#include<mouse.h>

/////////////////////////////GLOBAL VARIABLES/////////////////////////////////
int timess[10][10];
int peleft,size=0;
//////////////////////////////CLASSES/////////////////////////////////////////
class school
{
	char schname[40];
	int days;
	int noperiweek;

	public:

		void sch_det(char s[],int m,int n)
		{
			strcpy(schname,s);
			days=m;
			noperiweek=n;
			peleft=m*n;
		}
		int noperiodsweek()
		{
			return noperiweek;
		}
		int workdays()
		{
			return days;
		}
		char* scname()
		{
			return schname;
		}
}sch;
class detail
{
	int scode;
	int no,chk;
	char sub[50],subsh[5],tea[50],teash[5];

      public:

	detail()
	{
		strcpy(sub,"");
		strcpy(subsh,"");
		strcpy(tea,"");
		strcpy(teash,"");
		no=0;
		scode=random(9999)+1;
	}

	void enter(char s[],char ssh[],char t[],char tsh[],int n=1,int i=-1,int j=-1)
	{
		strcpy(sub,s);
		strcpy(subsh,ssh);
		strcpy(tea,t);
		strcpy(teash,tsh);
		no=n;
		peleft-=n;
		if(i!=-1||j!=-1)
		{
			timess[j][i]=scode;
			chk=-1;
		}
		else
			chk=0;

		size++;
       }
       int check()
       {
		return chk;
       }
       char* subject()
       {
		return subsh;
       }
       char* teacher()
       {
		return teash;
       }
       int subcode()
       {
		return scode;
       }
       int periods()
       {
		return no;
       }
}per[15];

//////////////////////////FUNCTIONS PROTOTYPE/////////////////////////////////
void graph();
char title[20][100]={"CREATE","CREDITS","EXIT","MODIFY","SAVE","ADD","SUBJECTS","SPECIFY","PERIODS","NEW","GENERATE","PERIODS","LEFT:","EDIT","SCHOOL NAME","PERIODS","SPECIFY","NO OF PERIODS LEFT:","CLASS DETAILS","NEXT"};
void draw_tab(int &v1,int &v2);
void zoom(int x1,int y1,int cxx,int dxx);
int side_col(int no,int &x,int &temps);
char* writ_gmode(int x,int y,int fsize,int delcol);
void scr2(int tle[],char title[10][100]);
void scr0();
int scr1(char,int,char);
void choice_scr0();
void disp(detail per[],int,int);


///////////////////////////////MAIN//////////////////////////////////////////////
void main()
{
	graph();
	setrgbpalette(0,0,0,0);
	scr0();
	choice_scr0();
	getch();
}
/////////////////////////FUNCTION DEFINATIONS/////////////////////////////////
void graph()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
}
////////////////////////////////////
void allocate(detail per[],int size,int rand=1)
{
	int sco,npe,ck,m,n;
	n=sch.workdays();
	m=sch.noperiodsweek();
	int i=0,j=0;
	for(int k=0;k<size;k++)
	{
		ck=per[k].check();
		if(ck==0)
		{
			sco=per[k].subcode();
			npe=per[k].periods();
			for(i=0;i<=m;i++)
			for(j=0;j<=n;j++)
			{
				if(timess[i][j]==sco)
				{
					timess[i][j]=0;
				}
			}
		}
	}
	int h=0;
	for(k=0;k<size;k++)
	{
		ck=per[k].check();
		if(ck==0)
		{
			sco=per[k].subcode();
			npe=per[k].periods();
			for(h=0;h<npe;)
			{
				i=random(m);
				j=random(n);

				if(timess[i][j]==0)
				{
					timess[i][j]=sco;
					h++;
				}
			 }
		}
	}
	rand++;
}
////////////////////////////////////////
void disp(detail per[],int size,int chk)
{
	if(chk==0)
	allocate(per,size);
	int m,n,num;
	n=sch.workdays();
	m=sch.noperiodsweek();
	int v1,v2;
	draw_tab(v1,v2);
	for(int w=0;w<size;w++)
	{
		for(int i=0,x=105,x3=130;i<=n;i++,x+=60,x3+=60)
		for(int j=0,y2=115,y3=146;j<=m;j++,y2+=50,y3+=50)
		{
			num=per[w].subcode();
			if(num==timess[j][i])
			{
				char sh[10],th[10];
				setcolor(WHITE);
				strcpy(sh,per[w].subject());
				outtextxy(x,y2,sh);
				strcpy(th,per[w].teacher());
				outtextxy(x3,y3,th);
			}

		}
	}
}
//////////////////////////////////
void draw_tab(int &v1,int &v2)
{
	char daqy[7][7]={"MON","TUE","WED","THURS","FRI","SAT","SUN"},qb[10][3]={"1","2","3","4","5","6","7","8","9","10"};
	cleardevice();
	int m,n;
	n=sch.workdays();
	m=sch.noperiodsweek();
	setcolor(WHITE);
	for(int q=0,y1=60;q<=m;q++,y1+=50)
	for(int w=0,x1=40;w<=n;w++,x1+=60)
	{
		rectangle(x1,y1,x1+60,y1+50);
		if((q==0||w==0))
		{
			setfillstyle(6,RED);
			floodfill(x1+1,y1+1,WHITE);
		}
	}
	int i;
	v1=x1,v2=y1;
	settextstyle(0,0,1);
	for(i=0,x1=105;i<n;i++,x1+=60)
		outtextxy(x1,65,daqy[i]);
	for(i=0,y1=65+50;i<m;i++,y1+=50)
		outtextxy(45,y1,qb[i]);
}
///////////////////////////////////////////
void zoom(int x1,int y1,int cxx,int dxx)
{
	float xtem1,xtem2,ytem1,ytem2;
	setfillstyle(1,BLUE);
	floodfill(cxx+5,dxx+5,WHITE);
	xtem1=(170-(x1*60+100))/10.0;
	xtem2=(470-(x1*60+160))/10.0;
	ytem1=(140-(y1*50+110))/10.0;
	ytem2=(340-(y1*50+160))/10.0;
	setcolor(WHITE);
	for(int i1=0;i1<10;i1++)
	{
		setcolor(15);
		rectangle(x1*60+100+xtem1*i1,y1*50+110+ytem1*i1,x1*60+160+xtem2*i1,y1*50+160+ytem2*i1);
		delay(55);
		setcolor(0);
		rectangle(x1*60+100+xtem1*i1,y1*50+110+ytem1*i1,x1*60+160+xtem2*i1,y1*50+160+ytem2*i1);
	}
	setcolor(BLUE);
	rectangle(getmaxx()/2-150,getmaxy()/2-100,getmaxx()/2+150,getmaxy()/2+100);
	setfillstyle(1,BLUE);
	floodfill(getmaxx()/2,getmaxy()/2,BLUE);
}

/////////////////////////////////////////
int side_col(int no,int &x,int &temps)
{
	int i=480/no;
	x=530;
	int y=i/4;
	setcolor(BLUE);
	rectangle(514,0,639,479);
	setfillstyle(1,BLUE);
	floodfill(515,1,BLUE);
	temps=y;
	setcolor(CYAN);
	for(int u=0;u<no;u++)
	{
		rectangle(x,y,x+90,y+i/2);
		setfillstyle(1,CYAN);
		floodfill(x+1,y+1,CYAN);
		y+=i;
	}
	setcolor(15);
	return i;
}
//////////////////////////////////////////////////////
char* writ_gmode(int x,int y,int fsize=1,int delcol=0)
{
	int i=0,s1=0;
	settextstyle(0,0,fsize);
	char s[100],cha[100];
	setcolor(15);
	while(s[s1-1]!=13)
	{
		s[s1++]=getch();
		if(s[s1-1]==13)
		{s[s1-1]='\0';
		break;
		}

		s[s1]='\0';
		if(s[s1-1]==8)
		{
			for(i=0;i<s1;i++)
			{
			cha[i]=' ';
			}
			cha[i]=0;
			cha[s1-2]=s[s1-2];

			setcolor(delcol);
			outtextxy(x,y,cha);

			setcolor(15);
			s[s1-2]='\0';
			s1-=2;

		}

		else
		{
			outtextxy(x,y,s);
			}


	}
	return s;
}
///////////////////////////////////////////////////////
int specify(int v1,int v2,int tle[],char title[10][100])
{
	int x,temps,i,no=2;
	char st[100],*s;
	s=sch.scname();
	strcpy(st,s);
	setmouselimit();
	settextstyle(2,0,5);
	outtextxy(1,1,st);
	i=side_col(no,x,temps);
	settextstyle(3,0,1);
	outtextxy(x+5,temps+20,title[tle[0]]);
	outtextxy(x+5,temps+40,title[tle[1]]);
	temps+=i;
	outtextxy(x+5,temps+20,title[tle[2]]);
	outtextxy(x+5,temps+40,title[tle[3]]);
	int h3,x1,y1;
	showmouse();
	char s1[40],ssnn[10],tte[40],inii[10];
	while(1)
	{
		getstatus();
		if(bx==1)
		{
		   x1=cx-100;
		   y1=dx-110;
		   x1=x1/60;
		   y1=y1/50;
		   if(x1>=0&&y1>=0)
		   {
			if(cx>=100&&dx>=110&&cx<=v1&&dx<=v2)
			{
				hidemouse();
				zoom(x1,y1,cx,dx);
				setcolor(0);
				settextstyle(0,0,2);
				char *sp,*sn,*ini,*tea;
				setcolor(15);
				outtextxy(184,194,"Subject: ");
				outtextxy(184,224,"Short name: ");
				outtextxy(184,254,"Teacher: ");
				outtextxy(184,284,"Initial: ");
				settextstyle(0,0,2);
				sp=writ_gmode(320,194,2,1);
				strcpy(s1,sp);
				sn=writ_gmode(362,224,2,1);
				strcpy(ssnn,sn);
				tea=writ_gmode(318,254,2,1);
				strcpy(tte,tea);
				ini=writ_gmode(318,284,2,1);
				strcpy(inii,ini);
				per[size].enter(s1,ssnn,tte,inii,1,x1,y1);
				cleardevice();
				i=side_col(no,x,temps);
				settextstyle(3,0,1);
				outtextxy(x+5,temps+20,title[tle[0]]);
				outtextxy(x+5,temps+40,title[tle[1]]);
				temps+=i;
				outtextxy(x+5,temps+20,title[tle[2]]);
				outtextxy(x+5,temps+40,title[tle[3]]);
				setcolor(RED);
				rectangle(175,175,385,263);
				setfillstyle(1,RED);
				floodfill(176,176,RED);
				setcolor(15);
				settextstyle(3,0,3);
				outtextxy(100,120,"PERIODS LEFT: ");
				outtextxy(200,200,"GENERATE NOW");
				gotoxy(35,9);
				cout<<peleft;
				setcolor(15);
				showmouse();
				changemouse(4);
				break;
			}
		  }
	     }
	}
	int sss=0;
	while(1)
	{
		getstatus();
		if(bx==1)
		{
			if(cx>=530&&dx>=(i/4)&&dx<=((i/4)*3)&&cx<=620)
			{
				sss=2;
				break;
			}
			if(cx>=530&&dx>=(i+i/4)&&dx<=((i+i/4)*3)&&cx<=620)
			{
				sss=1;
				break;
			}
			if(cx>=175&&dx>=175&&cx<=385&&dx<=265)
			{
				sss=3;
				break;
			}
		}
		}
		if(sss==3)
		{
			st:
			clrscr();
			hidemouse();
			disp(per,size,0);
			i=side_col(no,x,temps);
			settextstyle(3,0,1);
			outtextxy(x+20,temps+20,title[tle[4]]);
			outtextxy(x+26,temps+40,"&");
			outtextxy(x+20,temps+70,title[tle[5]]);
			temps+=i;
			outtextxy(x+5,temps+20,title[tle[6]]);
			outtextxy(x+5,temps+40,title[tle[7]]);
			showmouse();
			int tt=0;
			while(1)
			{

				getstatus();
				if(bx==1)
				{
				if(cx>=530&&dx>=(i/4)&&dx<=((i/4)*3)&&cx<=620)
				{
					tt=1;
					break;
				}
				if(cx>=530&&dx>=(i+i/4)&&dx<=((i+i/4)*3)&&cx<=620)
				{
					tt=2;
					break;
				}
				}
			}
			if(tt==1)
			{
				ofstream fout("c:\\timetable.txt");
				fout<<40+(sch.noperiodsweek()+1)*60<<" "<<60+(sch.workdays()+1)*50<<" ";
				int g=0;
				for(i=0;i<530;i++)
				for(int j=0;j<480;j++)
				{fout<<i<<" "<<j<<" ";
				 g=getpixel(i,j);
				 fout<<g<<" ";
				}
				ofstream fout11("c:\\check.txt");
				int n=32;
				fout11<<n;
				fout11.close();
				exit(3);


			}
			if(tt==2)
			{
					do
			{
				getstatus();
			}while(bx==1);
				goto st;
			}
		}

		if(sss==1)
		{
				disp(per,size,-1);
				specify(v1,v2,tle,title);
		}
		if(sss==2)
		{
			scr2(tle,title);
		}
		return 0;
}
//////////////////////////////////////////////
void scr2(int tle[],char title[10][100])
{
	int i,no=2,x,temps,v1,v2;
	char *s,st[100];
	s=sch.scname();
	strcpy(st,s);
	cleardevice();
	hidemouse();
	i=side_col(no,x,temps);
	settextstyle(3,0,1);
	outtextxy(x+5,temps+20,title[tle[0]]);
	outtextxy(x+5,temps+40,title[tle[1]]);
	temps+=i;
	outtextxy(x+5,temps+20,title[tle[2]]);
	outtextxy(x+5,temps+40,title[tle[3]]);
	char s1[40],ssnn[10],tte[40],inii[10];
	settextstyle(2,0,5);
	outtextxy(1,1,st);
   //////////////
	settextstyle(1,0,3);
	outtextxy(40,50,"Enter Details:");
	settextstyle(2,0,6);
	outtextxy(70,124,"Short Name: ");
	outtextxy(70,156,"No. of Periods: ");
	outtextxy(70,188,"Teacher: ");
	outtextxy(70,220,"Teacher Initial: ");
  //////////////
  //////////////
	setcolor(2);
	settextstyle(2,0,6);
	outtextxy(70,95,"Subject: ");
	setcolor(15);
	s=writ_gmode(200,104);
	strcpy(s1,s);
 ////////////////
	setcolor(15);
	settextstyle(2,0,6);
	outtextxy(70,95,"Subject: ");
	setcolor(2);
	outtextxy(70,124,"Short Name: ");
	setcolor(15);
	s=writ_gmode(200,133);
	strcpy(ssnn,s);
 //////////////////
	setcolor(15);
	settextstyle(2,0,6);
	outtextxy(70,124,"Short Name: ");
	setcolor(2);
	outtextxy(70,156,"No. of Periods: ");
	setcolor(15);
	gotoxy(37,11);
	cin>>i;
  //////////////
	setcolor(15);
	settextstyle(2,0,6);
	outtextxy(70,156,"No. of Periods: ");
	setcolor(2);
	outtextxy(70,188,"Teacher: ");
	setcolor(15);
	s=writ_gmode(200,197);
	strcpy(tte,s);
  /////////
	setcolor(15);
	settextstyle(2,0,6);
	outtextxy(70,188,"Teacher: ");
	setcolor(2);
	outtextxy(70,220,"Teacher Initial: ");
	setcolor(15);
	s=writ_gmode(225,229);
	strcpy(inii,s);
	per[size].enter(s1,ssnn,tte,inii,i);
	cleardevice();
	i=side_col(no,x,temps);
	settextstyle(3,0,1);
	outtextxy(x+5,temps+20,title[tle[0]]);
	outtextxy(x+5,temps+40,title[tle[1]]);
	temps+=i;
	outtextxy(x+5,temps+20,title[tle[2]]);
	outtextxy(x+5,temps+40,title[tle[3]]);
	setcolor(RED);
	rectangle(175,175,385,263);
	setfillstyle(1,RED);
	floodfill(176,176,RED);
	setcolor(15);
	settextstyle(3,0,3);
	outtextxy(100,120,"PERIODS LEFT: ");
	outtextxy(200,200,"GENERATE NOW");
	gotoxy(35,9);
	cout<<peleft;
	setcolor(15);
	showmouse();
	int sss=0;
	while(1)
	{
		getstatus();

		if(bx==1)
		{
			if(cx>=530&&dx>=(i/4)&&dx<=((i/4)*3)&&cx<=620)
			{
				sss=2;
				break;
			}
			if(cx>=530&&dx>=(i+i/4)&&dx<=((i+i/4)*3)&&cx<=620)
			{
				sss=1;
				break;
			}
			if(cx>=175&&dx>=175&&cx<=385&&dx<=265)
			{
				sss=3;
				break;
			}

		}

		}
		if(sss==1)
		{
			do
			{
				getstatus();
			}while(bx==1);
			hidemouse();
			draw_tab(v1,v2);
			specify(v1,v2,tle,title);
		}
		if(sss==2)
		{
			scr2(tle,title);
		}
		if(sss==3)
		{
			st:
			hidemouse();
			disp(per,size,0);
			i=side_col(no,x,temps);
			settextstyle(3,0,1);
			outtextxy(x+20,temps+20,title[tle[4]]);
			outtextxy(x+26,temps+40,"&");
			outtextxy(x+20,temps+70,title[tle[5]]);
			temps+=i;
			outtextxy(x+5,temps+20,title[tle[6]]);
			outtextxy(x+5,temps+40,title[tle[7]]);
			showmouse();
			int tt=0;
			while(1)
			{

				getstatus();
				if(bx==1)
				{
				if(cx>=530&&dx>=(i/4)&&dx<=((i/4)*3)&&cx<=620)
				{
					tt=1;
					break;
				}
				if(cx>=530&&dx>=(i+i/4)&&dx<=((i+i/4)*3)&&cx<=620)
				{
					tt=2;
					break;
				}}

			}
			if(tt==1)
			{
				ofstream fout("c:\\timetable.txt");
				fout<<40+(sch.noperiodsweek()+1)*60<<" "<<60+(sch.workdays()+1)*50<<" ";
				int g=0;
				for(i=0;i<530;i++)
				for(int j=0;j<480;j++)
				{
					fout<<i<<" "<<j<<" ";
					g=getpixel(i,j);
					fout<<g<<" ";
				}
				ofstream fout11("c:\\check.txt");
				int n=32;
				fout11<<n;
				fout11.close();
				exit(3);

			}
			if(tt==2)
			{

				do
				{
					getstatus();
				}while(bx==1);
				goto st;
			}

		}
}
/////////////////////////////////////////
void scr0()
{
	cleardevice();
	int x,temps;
	setrgbpalette(0,0,0,0);
	setcolor(RED);
	rectangle(30,240,610,400);
	setfillstyle(1,RED);
	floodfill(31,241,RED);
	setcolor(GREEN);
	rectangle(30,100,560/3+32,232);
	setfillstyle(1,GREEN);
	floodfill(31,101,GREEN);
	setcolor(MAGENTA);
	rectangle(560/3+40,100,560/3+560/3+42,232);
	setfillstyle(1,MAGENTA);
	floodfill(560/3+41,101,MAGENTA);
	setcolor(BLUE);
	rectangle(560/3+560/3+50,100,560+52,232);
	setfillstyle(1,BLUE);
	floodfill(560/3+560/3+51,101,BLUE);
	setcolor(WHITE);
	settextstyle(8,0,5);
	outtextxy(80,282,"TIMETABLE CREATOR");
	setcolor(15);
	settextstyle(3,0,3);
	outtextxy(133,200,"CREATE");
	outtextxy(325,200,"CREDITS");
	outtextxy(555,200,"EXIT");

}
/////////////////////////////////////////////
int scr1(int tle[],char title[10][100])
{

	int no=2,x,temps,i,m,n,p;
	char *s,st[100];
	hidemouse();
	cleardevice();
	i=side_col(no,x,temps);
	settextstyle(3,0,1);
	outtextxy(x+5,temps+20,title[tle[0]]);
	outtextxy(x+5,temps+40,title[tle[1]]);
	temps+=i;
	outtextxy(x+5,temps+20,title[tle[2]]);
	outtextxy(x+5,temps+40,title[tle[3]]);
	settextstyle(1,0,3);
	outtextxy(40,50,"Your School:");
	settextstyle(2,0,6);
	outtextxy(70,124,"Periods in a Day: ");
	outtextxy(70,156,"Number of working Days: ");
	setcolor(2);
	outtextxy(70,95,"School Name: ");
	setcolor(15);
	s=writ_gmode(200,104);
	strcpy(st,s);
	settextstyle(2,0,6);
	setcolor(2);
	outtextxy(70,124,"Periods in a Day: ");
	setcolor(15);
	outtextxy(70,95,"School Name: ");
	gotoxy(34,9.5);
	cin>>n;
	setcolor(15);
	outtextxy(70,124,"Periods in a Day: ");
	setcolor(2);
	outtextxy(70,156,"Number of working Days: ");
	gotoxy(40,11);
	cin>>m;
	sch.sch_det(st,m,n);
	showmouse();
	int sss=0;
	while(1)
	{
		getstatus();

		if(bx==1)
		{
			if(cx>=530&&dx>=(i/4)&&dx<=((i/4)*3)&&cx<=620)
			{
				sss=2;
				break;
			}
			if(cx>=530&&dx>=(i+i/4)&&dx<=((i+i/4)*3)&&cx<=620)
			{
				sss=1;
				break;
			}
		}
		}
		int v1,v2;
		if(sss==1)
		{
			do
			{
				getstatus();
			}while(bx==1);
			hidemouse();
			draw_tab(v1,v2);
			specify(v1,v2,tle,title);
		}
		if(sss==2)
		{
			scr2(tle,title);
		}

    return 0;
}
////////////////////////////////////////////
void choice_scr0()
{
	int fin=0;
	setmouselimit();
	showmouse();
	while(1)
	{
		getstatus();

		if(bx==1)
		{
			if(cx>=30&&dx>=10&&cx<=560/3+30&&dx<=230)
			{
				fin=1;
				break;
			}
			if(cx>=422&&dx>=100&&cx<=611&&dx<=230)
			{
				ofstream fout14("c:\\check.txt");
				int n=37;
				fout14<<n;
				fout14.close();

				exit(1);
			}
			if(cx>=225&&dx>=99&&cx<=414&&dx<=233)
			{
				ofstream fout11("c:\\check.txt");
				int n=24;
				fout11<<n;
				fout11.close();
				exit(2);
			}

		}
	}
	if(fin==1)
	{
		int tle[10],i;
		tle[0]=5;
		tle[1]=6;
		tle[2]=7;
		tle[3]=8;
		tle[4]=4;
		tle[5]=2;
		tle[6]=10;
		tle[7]=9;

		scr1(tle,title);

	}
}

//////////////////////////END OF PROGRAM CODE/////////////////////////////////

//////////////////////////////JAI SAI RAM/////////////////////////////////////