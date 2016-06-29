#include<graphics.h>
#include<fstream.h>
main()
{
    int gd=0,gm;
    initgraph(&gd,&gm,"");
    initwindow(1440,900);
    readimagefile("3f.jpg",0,0,1368,768);
    ofstream fout("3.txt");
    int i,j,co;
    for(i=0;i<1368;i++)
    for(j=0;j<768;j++)
    {
        co=getpixel(i,j);
        if(co==WHITE)
        fout<<i<<" "<<j<<" ";

    }
    fout.close();
    readimagefile("1.jpg",0,0,1368,768);
    ofstream fout("1FILE.txt");
    for(i=200;i<1440;i++)
    for(j=300;j<600;j++)
    {
        co=getpixel(i,j);
        fout<<i<<" "<<j<<" "<<co<<" ";
    }
    getch();
}
