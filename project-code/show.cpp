#include<fstream.h>
#include<graphics.h>
main()
{
    int gd=0,gm;
    char s[4][20];
    strcpy(s[0],"1.txt");
    strcpy(s[1],"2.txt");
    strcpy(s[2],"3.txt");
    strcpy(s[3],"4.txt");
    initgraph(&gd,&gm,"");
    initwindow(1440,900);
    int x,y,co,xl,yl;
    readimagefile("ini.jpg",0,0,1368,768);
    for(int q=0;q<4;q++)
    {
        ifstream fin(s[q]);
        while(!fin.eof())
        {
            fin>>x;
            fin>>y;
            putpixel(x,y,WHITE);
        }
        fin.close();
    }
    system("scr.exe");
    int ch,temp=0;
    ifstream fin2("c:\\check.txt");
    while(!fin2.eof())
    {
        fin2>>ch;
        if(ch==24)
        {
            temp=1;
            break;
        }
        if(ch==32)
        {
            temp=2;
            break;
        }
    }
    if(temp==1)
    {
        system("cred.exe");
    }
    if(temp==2)
    {
        system("cpin.exe");
    }
fin2.close();
}
