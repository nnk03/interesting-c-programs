#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
   size_t count;
   size_t capacity;
} Header;

/* int *arr_init( size_t init_capacity ) { */
/*    // header + 1 will point to the base of the numbers */
/*    // [header][number] */
/*    // ^ */
/*    // data */
/*    Header *header = malloc( sizeof( int ) * init_capacity + sizeof( Header )
 * ); */
/*    header->count = 0; */
/*    header->capacity = init_capacity; */
/*    return (int *)( header + 1 ); */
/* } */

#define ARR_INIT_CAPACITY 1

// [header][number]
//          ^
//          arr
#define arr_push( arr, x )                                                    \
   do {                                                                       \
      if ( arr == NULL ) {                                                    \
         Header *header =                                                     \
             malloc( sizeof( *arr ) * ARR_INIT_CAPACITY + sizeof( Header ) ); \
         header->count = 0;                                                   \
         header->capacity = ARR_INIT_CAPACITY;                                \
         arr = (void *)( header + 1 );                                        \
      }                                                                       \
      Header *header = (Header *)( arr ) - 1;                                 \
      if ( header->count >= header->capacity ) {                              \
         header->capacity *= 2;                                               \
         header = realloc( header, sizeof( *( arr ) ) * header->capacity +    \
                                       sizeof( Header ) );                    \
         arr = (void *)( header + 1 );                                        \
      }                                                                       \
      arr[ header->count++ ] = ( x );                                         \
   } while ( 0 )

// [header][number]
//          ^
//          arr
#define arr_len( arr ) ( ( (Header *)( arr ) - 1 )->count )

#define arr_free( arr ) free( (Header *)( arr ) - 1 )

int main( int argc, char *argv[] ) {
   int *numbers = NULL;
   arr_push( numbers, 1 );
   arr_push( numbers, 2 );
   arr_push( numbers, 3 );
   arr_push( numbers, 4 );
   arr_push( numbers, 5 );
   for ( int i = 0; i < arr_len( numbers ); ++i ) {
      printf( "%d\n", numbers[ i ] );
   }

   // invalid, since numbers is not the starting of the dynamic array
   // there is a header behind it
   /* free(numbers); */
   arr_free( numbers );

   return EXIT_SUCCESS;
}
