#include <stdio.h>
#include <stdlib.h>

int foo() { return 15; }
int bar( void ) { return 15; }

int main( int argc, char *argv[] ) {
   /* int result = foo(); */
   int result = foo( 12 );
   int result2 = bar( 12 );
   printf( "result is %d\n", result );
   return EXIT_SUCCESS;
}
