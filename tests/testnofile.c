#include<stdio.h>
#include <sys/resource.h>
#include <errno.h>



int main( int argc, char *argv[] ) 
{
	int i;
	FILE *f[argc];
	struct rlimit rl;
	if ( getrlimit( RLIMIT_NOFILE , &rl) != 0 ) {
	    printf("getrlimit() failed with errno=%d\n", errno);
		return 255;
	};
	//printf("nofile: soft=%d hard=%d , files to open: %d \n" , rl.rlim_cur , rl.rlim_max , argc-1 ); 
	for( i=1 ; i<argc ; i++ ) {
		printf("open file %10d of %10d getrlimit nofile: soft=%10d hard=%10d %-60s\n" , i , argc-1 , rl.rlim_cur , rl.rlim_max ,  argv[i] ); 
		errno=0;
		f[i] = fopen( argv[i] , "r" );
		if(errno || (NULL == f[i])) {
	    		printf("fopen() number %d failed with errno=%d \n", i, errno );
			return 255;
		};
	}
	sleep(10);
	for( i=1 ; i<argc ; i++ ) {
		//printf("close file: %s \n" , argv[i] ); 
		fclose( f[i] );
	}
	return 0;
}

