#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handler( int num ) { write( STDOUT_FILENO, "Can't interrupt", 15 ); }

void seghandler( int num ) { write( STDOUT_FILENO, "Seg Fault!\n", 10 ); }

int main( int argc, char *argv[] ) {
   /* signal( SIGINT, handler ); */
   /* signal( SIGTERM, handler ); */
   /* signal( SIGKILL, handler );          // no use */
   /* signal( SIGSEGV, seghandler ); */ // we just made a mess
   //
   // kill -STOP <pid>
   // kill -CONT <pid>
   // also user defined signals possible
   // SIGUSR1, SIGUSR2
   //

   // sigaction is new and preferred
   // signals are asynchronous, so only some functions are async-safe
   // check the docs


   /* int *p = NULL; */
   /* *p = 45; */

   struct sigaction sa;
   sa.sa_handler = handler;
   sigaction( SIGINT, &sa, NULL );
   sigaction( SIGTERM, &sa, NULL );

   while ( 1 ) {
      printf( "Wasting CPU cycles: %d\n", getpid() );
      sleep( 1 );
   }
   return EXIT_SUCCESS;
}
