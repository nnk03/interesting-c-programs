#include <stdio.h>
#include <stdlib.h>

static int num = 5;
int num;
extern int num;

int main( int argc, char *argv[] ) {
   printf( "%d", num );
   return EXIT_SUCCESS;
}
