#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <err.h>

#define USAGE ( \
			"usage: execdir dir command [option ...]\n" \
			"\n" \
			"       changes into the specified directory, then executes the given command\n" \
			"\n" )

int
main( int argc, char *argv[] )
{
	if( argc < 3 ) {
		fprintf( stderr, USAGE );
		exit( 2 );
	}
	if( chdir( argv[ 1 ] ) ) err( 1, "%s", argv[ 1 ] );
	if( execvp( argv[ 2 ], argv + 2 ) ) err( 1, "%s", argv[ 2 ] );
	return -1;
}
