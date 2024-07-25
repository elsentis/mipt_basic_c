#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int res = 0;

    for(; (res = getopt(argc, argv, "hf:m:")) != -1; )
    {
        switch(res)
        {
            case 'h': printf( "help\n" );
                      break;
            case 'f': printf( "process file - %s\n" , optarg);
                      break;
            case 'm': printf( "process month - %s\n" , optarg);
                      break;
        }
    }

    return 0; 
}