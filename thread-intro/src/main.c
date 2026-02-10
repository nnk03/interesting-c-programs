#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* myTurn( void* arg ) {
   for ( int i = 0; i < 8; ++i ) {
      sleep( 1 );
      printf( "My Turn! i = %d\n", i );
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

   pthread_create( &myTurnThread, NULL, myTurn, NULL );
   yourTurn();
   pthread_join( myTurnThread, NULL );

   return EXIT_SUCCESS;
}
