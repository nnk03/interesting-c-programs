#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_MATCHES 3

int main( int argc, char *argv[] ) {
   if ( argc != 2 ) {
      fprintf( stderr, "Usage %s <string-to-match>\n", argv[ 1 ] );
      return EXIT_FAILURE;
   }

   // representing regex
   regex_t re;
   // for matching
   regmatch_t match[ NUM_MATCHES ];

   // we want strings to be <key>=<value>
   const char *pattern = "^([a-zA-Z]+)=([a-zA-Z0-9_]+)$";
   // reason of parentheses --> to be capturing group
   // that is why we have NUM_MATCHES=3, since we need
   // 1. whole string match
   // 2. key match
   // 3. value match

   // compile regex
   if ( regcomp( &re, pattern, REG_EXTENDED ) ) {
      perror( "Regex compile failed" );
      return EXIT_FAILURE;
   };

   // execute
   int result = regexec( &re, argv[ 1 ], NUM_MATCHES, match, 0 );
   // 3 cases for result
   if ( !result ) {
      printf( "Match!\n" );
      for ( int i = 0; i < NUM_MATCHES; ++i ) {
         printf( "match[%d]: %.*s (%d -- %d) \n", i,
                 match[ i ].rm_eo - match[ i ].rm_so,
                 argv[ 1 ] + match[ i ].rm_so, match[ i ].rm_so,
                 match[ i ].rm_eo );
      }

   } else if ( result == REG_NOMATCH ) {
      printf( "No match!\n" );
   } else {
      perror( "regex failed!" );
      // cleanup
      regfree( &re );
      return EXIT_FAILURE;
   }

   // cleanup
   regfree( &re );

   return EXIT_SUCCESS;
}
