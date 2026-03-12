#include <stdio.h>
#include <stdlib.h>

typedef void ( *foo_t )( void );
typedef void( bar )( void );

void foo_( void ) { printf( "Hello\n" ); }

bar b; // function declaration
void b( void ) { printf( "Hello from b\n" ); }

int main( int argc, char *argv[] ) {
   foo_t foo = foo_;
   foo();

   bar *foo_ptr = foo_;
   foo_ptr();

   b();

   return EXIT_SUCCESS;
}
