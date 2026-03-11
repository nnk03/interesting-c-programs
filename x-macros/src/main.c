#include <stdio.h>
#include <stdlib.h>

#define LIST_OF_VARIABLES           \
   FUNCTION_WITH_VARIABLE( value1 ) \
   FUNCTION_WITH_VARIABLE( value2 ) \
   FUNCTION_WITH_VARIABLE( value3 )


int value1 = 1;
int value2 = 2;
int value3 = 3;

// use `cpp` command to see the output of the pre-processor alone
// cpp ./main.c -o output
// we will see the below statement but in a `single line`
// printf( "value of %s : %d\n", "value1", value1 ); printf( "value of %s :
// %d\n", "value2", value2 ); printf( "value of %s : %d\n", "value3", value3 );

int main( int argc, char *argv[] ) {
   // name##_t would evaluate such that
   // if name is `value1`, then name##_t would be value1__t
#define FUNCTION_WITH_VARIABLE( name ) \
   printf( "value of %s : %d\n", #name, name );
   LIST_OF_VARIABLES
#undef FUNCTION_WITH_VARIABLE

   return EXIT_SUCCESS;
}
