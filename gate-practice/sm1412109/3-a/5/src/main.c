#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {
   //
   char *p;
   p = "%d\n";
   p++;
   p++;
   printf( p - 2, 300 );
   return EXIT_SUCCESS;
}
