#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {
   float a = 0.7;
   if ( a < 0.7 ) {
      printf( "Hi\n" );
   } else {
      printf( "Hello\n" );
   }
   printf( "sizeof a : %lu\n", sizeof( a ) );
   printf( "sizeof 0.7 : %lu\n", sizeof( 0.7 ) );
   return EXIT_SUCCESS;
}
