#include <stdlib.h>

int main( int argc, char *argv[] ) {
   // west const - look right and that is what is actually made constant
   /* const int x = 5; */
   // east const - look left and that is what is actually made constant
   int const x = 5;
   // not valid
   /* x = 10; */

   // east const is usually consistent
   // pointer to a const int
   int const *a = &x;
   a = &argc; // fine
   // invalid
   /* *a = 100; */

   int y = 100;
   // const pointer to an int
   int *const b = &y;
   *b = 1234; // fine
   /* b = &x;    // invalid */

   int const *const c = &x;
   /* c = &y;    // invalid */
   /* *c = 1234; // invalid */

   return EXIT_SUCCESS;
}
