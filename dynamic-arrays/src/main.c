#include <stdio.h>
#include <stdlib.h>

typedef struct {
   float *items;
   size_t count;
   size_t capacity;
} Numbers;

#define da_append( xs, x )                                                  \
   do {                                                                     \
      if ( xs.count >= xs.capacity ) {                                      \
         if ( xs.capacity == 0 )                                            \
            xs.capacity = 2;                                                \
         else                                                               \
            xs.capacity *= 2;                                               \
         xs.items = realloc( xs.items, sizeof( *xs.items ) * xs.capacity ); \
      }                                                                     \
      xs.items[ xs.count++ ] = x;                                           \
   } while ( 0 );

int main( int argc, char *argv[] ) {
   Numbers xs = { 0 };

   for ( int x = 0; x < 10; ++x ) {
      da_append( xs, x );
   }

   for ( size_t i = 0; i < xs.count; ++i ) {
      printf( "%f\n", xs.items[ i ] );
   }

   return EXIT_SUCCESS;
}
