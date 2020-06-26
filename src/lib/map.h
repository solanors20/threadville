#ifndef MAP_H_
#define MAP_H_

char* paradas[P]={
    "1","2","1","2","1","2","1","2","1","2","1","2",
    "8","3","8","3","8","3","8","3","8","3","8","3",
    "7","4","7","4","7","4","7","4","7","4","7","4",
    "6","5","6","5","6","5","6","5","6","5","6","5",
    "1","2","1","2","1","2","1","2","1","2","1","2",
    "6","3","6","3","6","3","6","3","6","3","6","3",
    "5","4","5","4","5","4","5","4","5","4","5","4",
    "1","2","1","2","1","2","1","2","1","2","1","2",
    "6","3","6","3","6","3","6","3","6","3","6","3",
    "5","4","5","4","5","4","5","4","5","4","5","4",
    "1","2","1","2","1","2","1","2","1","2","1","2",
    "8","3","8","3","8","3","8","3","8","3","8","3",
    "7","4","7","4","7","4","7","4","7","4","7","4",
    "6","5","6","5","6","5","6","5","6","5","6","5"
};


int map2[FILAS2][COLUMNAS2]={
        {0,0,1,1,5,1,1,5,1,1,1,1,5,1,1,5,1,1,1,1,5,1,1,5,1,1,1,1,5,1,1,5,1,1,1,1,5,1,1,5,1,1,1,1,5,1,1,5,1,1,0,0},
        {0,0,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,0,0},
        {0,0,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,0,0},
        {0,0,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,0,0},
        {0,0,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,0,0},
        {0,0,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,0,0},
        {0,0,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,0,0},
        {0,0,1,1,6,1,1,6,1,1,1,1,6,1,1,6,1,1,1,1,6,1,1,6,1,1,1,1,6,1,1,6,1,1,1,1,6,1,1,6,1,1,1,1,6,1,1,6,1,1,0,0},
        {0,0,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,0,0},
        {0,0,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,0,0},
        {0,0,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,0,0},
        {0,0,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,0,0},
        {0,0,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,0,0},
        {0,0,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,0,0},
        {0,0,1,3,3,3,3,3,3,1,1,3,3,3,3,3,3,1,1,3,3,3,3,3,3,1,1,3,3,3,3,3,3,1,1,3,3,3,3,3,3,1,1,3,3,3,3,3,3,1,0,0},
        {5,1,5,5,1,1,1,1,1,9,8,1,1,1,1,1,1,9,8,1,1,1,1,1,1,9,8,1,1,1,1,1,1,9,8,1,1,1,1,1,1,9,8,1,1,1,1,1,5,5,1,5},
        {1,3,1,5,1,1,1,1,1,7,7,1,1,1,1,1,1,7,7,1,1,1,1,1,1,7,7,1,1,1,1,1,1,7,7,1,1,1,1,1,1,7,7,1,1,1,1,1,5,1,3,1},
        {1,3,1,5,1,1,1,1,1,7,7,1,1,1,1,1,1,7,7,1,1,1,1,1,1,7,7,1,1,1,1,1,1,7,7,1,1,1,1,1,1,7,7,1,1,1,1,1,5,1,3,1},
        {5,1,5,5,1,1,1,1,1,9,8,1,1,1,1,1,1,9,8,1,1,1,1,1,1,9,8,1,1,1,1,1,1,9,8,1,1,1,1,1,1,9,8,1,1,1,1,1,5,5,1,5},
        {0,0,1,3,3,3,3,3,3,1,1,3,3,3,3,3,3,1,1,3,3,3,3,3,3,1,1,3,3,3,3,3,3,1,1,3,3,3,3,3,3,1,1,3,3,3,3,3,3,1,0,0},
        {0,0,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,0,0},
        {0,0,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,0,0},
        {0,0,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,0,0},
        {0,0,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,0,0},
        {0,0,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,0,0},
        {0,0,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,0,0},
        {0,0,1,1,6,1,1,6,1,1,1,1,6,1,1,6,1,1,1,1,6,1,1,6,1,1,1,1,6,1,1,6,1,1,1,1,6,1,1,6,1,1,1,1,6,1,1,6,1,1,0,0},
        {0,0,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,0,0},
        {0,0,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,0,0},
        {0,0,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,0,0},
        {0,0,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,0,0},
        {0,0,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,5,4,2,2,2,2,4,5,0,0},
        {0,0,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,1,2,4,2,2,4,2,1,0,0},
        {0,0,1,1,5,1,1,5,1,1,1,1,5,1,1,5,1,1,1,1,5,1,1,5,1,1,1,1,5,1,1,5,1,1,1,1,5,1,1,5,1,1,1,1,5,1,1,5,1,1,0,0}, 
  
};


static void draw_background (cairo_t * cr) {

    int x, y, p=0;
    for(x=0; x<FILAS2;x++){
        for(y=0; y<COLUMNAS2; y++){
            if(map2[x][y]==1){ //calle
                cairo_set_source_rgb (cr, 0.5, 0.5, 0.5); //gris_de_calle -> rgb(0.17, 0.18, 0.18)
                cairo_rectangle(cr,y*TILESIZE,x*TILESIZE,TILESIZE,TILESIZE);
                cairo_fill (cr);
            }else if(map2[x][y]==2){ //amarillo cuadra
                cairo_set_source_rgb (cr, 1.0, 1.0, 0.0); // amarillo -> 1.0,0.99,0.33
                cairo_rectangle(cr,y*TILESIZE,x*TILESIZE,TILESIZE,TILESIZE);
                cairo_fill (cr);
            }else if(map2[x][y]==3){ //verde en puentes
                cairo_set_source_rgb (cr, 0.3,0.8,0.0); // verde s0.01,0.49,0.0
                cairo_rectangle(cr,y*TILESIZE,x*TILESIZE,TILESIZE,TILESIZE);
                cairo_fill (cr);
            }else if(map2[x][y]==4){ //paradas letrero 
                cairo_set_source_rgb (cr, 1.0, 1.0, 1.0); //
                cairo_rectangle(cr,y*TILESIZE,x*TILESIZE,TILESIZE,TILESIZE);
                cairo_fill (cr);
                
                cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
                cairo_set_font_size(cr, 13);
                cairo_move_to(cr, y*TILESIZE+6,x*TILESIZE+15);

                cairo_show_text(cr, paradas[p]);
                p++;
            }else if(map2[x][y]==5 || map2[x][y]==6){ //paradas
                //cairo_set_source_rgb (cr, 0.0, 0.0, 1.0);
                cairo_set_source_rgb (cr, 0.5, 0.5, 0.5); //gris_de_calle -> rgb(0.17, 0.18, 0.18)
                cairo_rectangle(cr,y*TILESIZE,x*TILESIZE,TILESIZE,TILESIZE);
                cairo_fill (cr);
            }
        } // for y
    } // for x

    int x_limit, y_limit;
    x_limit = 6;
    y_limit = 2;

    cairo_set_font_size(cr, 54);
    cairo_text_extents_t extents;
    char *utf8;
    x=0;
    y=0;

    char *letters_array[2][6] = {
        {"A", "B", "C", "D", "E", "F"},
        {"G", "H", "I", "J", "K", "L"} 
    };

    for (size_t i = 0; i < y_limit; i++)
    {
        for (size_t j = 0; j < x_limit; j++)
        {
            utf8 = letters_array[i][j];
            cairo_text_extents (cr, utf8, &extents);
            y = ((i * 140) + 80) - (extents.height/2 + extents.y_bearing);
            x = ((j * 160) + 120) - (extents.width/2 + extents.x_bearing);
            cairo_move_to(cr, x, y);
            cairo_show_text(cr, utf8);
        }
        
    }

    char *letters_array2[2][6] = {
        {"M", "N", "O", "P", "Q", "R"},
        {"S", "T", "U", "V", "W", "X"} 
    };

    for (size_t i = 0; i < y_limit; i++)
    {
        for (size_t j = 0; j < x_limit; j++)
        {
            utf8 = letters_array2[i][j];
            cairo_text_extents (cr, utf8, &extents);
            y = ((i * 140) + 460) - (extents.height/2 + extents.y_bearing);
            x = ((j * 160) + 120) - (extents.width/2 + extents.x_bearing);
            cairo_move_to(cr, x, y);
            cairo_show_text(cr, utf8);
        }
        
    }
 
     
} // draw_background

#endif
