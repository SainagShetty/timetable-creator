#include <allegro.h>

BITMAP *bmp;
BITMAP *phot;

void init();
void deinit();


int main() {
	init();
	int x,y=-480,_x,_y,r,g,b,tcol1,tcol;
	float per;
    bmp=load_bitmap("credits.bmp",NULL);
	phot=load_bitmap("b2.bmp",NULL);
    while (!key[KEY_ESC]) 
    {
            if(y<=1167-480)          
            {y+=3;     
            vsync();     
	      	blit(bmp,screen,0,y,0,0,640,480);
	      	
        }
            else
            {for(per=1;per>=0;per-=0.01)
            {for(_y=0;_y<480;_y++)
            {
                 for(_x=0;_x<640;_x++)
                 {
                         tcol=getpixel(phot,_x,_y);
                         r=getr(tcol)*per;
                         g=getg(tcol)*per;
                         b=getb(tcol)*per;
                         putpixel(bmp,_x,_y,makecol(r,g,b));         
                 }   
                   if(key[KEY_ESC])
                      exit(0);               
           }
          vsync();
           blit(bmp,screen,0,0,0,0,640,480);
           }
           break;
           }
            
	      	rest(30);
	}
	system("scr.exe");

	deinit();
	return 0;
}
END_OF_MAIN()

void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, 640, 480, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
	
}

void deinit() {
	clear_keybuf();
	
}
