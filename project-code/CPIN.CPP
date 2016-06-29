#include<graphics.h>
#include<fstream.h>
#include<iostream.h>
#include<process.h>

main()
{
      int gd=0,gm;
      initgraph(&gd,&gm,"c:\\tc\\bgi");
      int x,y,co,xl,yl,chk;
      ifstream fi("c:\\check.txt");
      fi>>chk;
      if(chk==32)
      {
                 ifstream fin("c:\\timetabl.txt");
                 fin>>xl;
                 fin>>yl;
                 while(!fin.eof())
                 {
                                  fin>>x;
                                  fin>>y;
                                  fin>>co;
                                  putpixel(x,y,co);
                 }
      writeimagefile("img.jpg",40,60,xl-60,yl);}
      
      else
          exit(3);
}
