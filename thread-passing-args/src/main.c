#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* myTurn( void* arg ) {
   int* iptr = (int*)malloc( sizeof( int ) );
   *iptr = 5;
   for ( int i = 0; i < 8; ++i ) {
      sleep( 1 );
      printf( "My Turn! i = %d %d\n", i, *iptr );
      ( *iptr )++;
   }

   return iptr;
}

void yourTurn() {
   for ( int i = 0; i < 5; ++i ) {
      sleep( 2 );
      printf( "Your Turn! i = %d\n", i );
   }
}

int main( int argc, char* argv[] ) {
   pthread_t myTurnThread;
   /* int v = 5; */
   int* result;

   pthread_create( &myTurnThread, NULL, myTurn, NULL );
   yourTurn();
   pthread_join( myTurnThread, (void*)&result );
   /* printf( "thread's done: v = %d", v ); */
   printf( "thread's done: *result = %d", *result );

   return EXIT_SUCCESS;
}
