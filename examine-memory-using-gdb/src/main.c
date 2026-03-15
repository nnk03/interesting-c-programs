#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#pragma pack( 1 )
typedef struct {
   int8_t hours;
   uint32_t micros;
   uint16_t seconds;
} Time;

// Use x/nfu <address> to examine memory in gdb
/* Command: x/nfu <address>
 * * n (Count): Number of units to display (default 1)
 * * f (Format):
 * x : Hexadecimal      d : Signed Decimal    u : Unsigned Decimal
 * t : Binary           f : Floating Point    i : Instruction (ASM)
 * s : String           c : Character
 * * u (Unit Size):
 * b : Byte (8 bits)    h : Half-word (16 bits)
 * w : Word (32 bits)   g : Giant-word (64 bits)
 * * Examples:
 * x/4xw &ptr  -> Show 4 words in hex
 * x/16ub &arr -> Show 16 bytes as unsigned decimals
 * x/5i $pc    -> Show next 5 assembly instructions
 */

int main( int argc, char *argv[] ) {
   Time t = {
       .hours = 6,
       .micros = 0x12345678,
       .seconds = 0xEEED,
   };

   printf( "%lu\n", sizeof( t ) );
   return EXIT_SUCCESS;
}
