#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* myTurn( void* arg ) {
   int* iptr = (int*)arg;
   for ( int i = 0; i < 8; ++i ) {
      sleep( 1 );
      printf( "My Turn! i = %d %d\n", i, *iptr );
      ( *iptr )++;
   }

   return NULL;
}

void yourTurn() {
   for ( int i = 0; i < 5; ++i ) {
      sleep( 2 );
      printf( "Your Turn! i = %d\n", i );
   }
}

int main( int argc, char* argv[] ) {
   pthread_t myTurnThread;
   int v = 5;

   pthread_create( &myTurnThread, NULL, myTurn, &v );
   yourTurn();
   pthread_join( myTurnThread, NULL );
   printf( "thread's done: v = %d", v );

   return EXIT_SUCCESS;
}
