#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <err.h>

void
usage( void )
{
	fprintf( stderr, "usage: timeout secs command [arg ...]\n" );
	exit( 2 );
}

pid_t kid = 0;

void
kill_kid( int s )
{
	kill( kid, SIGINT );
}

int
main( int argc, char *argv[] )
{
	int sec = 0;

	if( argc < 3 ) usage();

	sec = atoi( argv[1] );
	if( sleep < 0 ) usage();

	if( ( kid = fork() ) ) {
		if( kid == -1 ) err( 1, "%s", argv[ 2 ] );

		{
			struct sigaction a;
			memset( &a, 0, sizeof a );
			a.sa_handler = kill_kid;
			sigaction( SIGALRM, &a, NULL );
		}

		alarm( sec );

		waitpid( kid, NULL, 0 );
	}
	else {
		if( execvp( argv[ 2 ], argv + 2 ) ) err( 1, "%s", argv[ 2 ] );
	}

	return( 0 );
}
