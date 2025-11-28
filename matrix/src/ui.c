#include "../include/ui.h"

#include <assert.h>
#include <curses.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

WINDOW *ui_window = NULL;


int color_map[ MAX_INTENSITY + 1 ] = { 1, 2, 2, 3, 3, 3, 4,
                                       4, 4, 4, 4, 5, 3, 6 };

void set_colors() {}

bool init_ui() {
   // set the matrix all to black
   // move this later to matrix.c
   for ( int x = 0; x < MAXX; ++x ) {
      for ( int y = 0; y < MAXY; ++y ) {
         matrix[ x ][ y ].char_value = 0;
         matrix[ x ][ y ].intensity = 0;
      }
   }

   // init curses
   ui_window = initscr();
   if ( ui_window == NULL ) {
      return false;
   }

   start_color();
   if ( !has_colors() || !can_change_color() || COLOR_PAIRS < 6 ) {
      printf( "Warning. Terminal can't handle this program" );
      return false;
   }

   set_colors();

   return true;
}

void cleanup_ui() {
   delwin( ui_window );
   endwin();
   refresh();
}

void show_matrix() {

   for ( int x = 0; x < MAXX; ++x ) {
      for ( int y = 0; y < MAXY; ++y ) {
         int intensity = matrix[ x ][ y ].intensity;
         color_set( color_map[ intensity ], NULL );
         mvaddch( y, x, matrix[ x ][ y ].char_value );
      }
   }

   refresh();
}
