#include <stdio.h>
#include <stdlib.h> //for exit() func
#include <unistd.h>// for getopt() func

void parsing_cmd (int argc, char **argv, FILE *file );

int main(int argc, char **argv)
{
    int help_flag = 0, month_flag = 0, file_flag = 0;

    FILE* in;

    parsing_cmd (argc, argv, in);

    return 0;
}

//анализирует входные опции от пользователя и передает их в main
//если ошибки в входных данных выводит пользователю сообщение об ошибках и заканчивает выполнение программы
void parsing_cmd (int argc, char **argv, FILE *file)
{
    int res = 0, incorrect_sequencde_file_month_flag = 0, month_number = 0;
    int help_flag = 0, month_flag = 0, file_flag = 0;
    char *file_path = 0;
    

    for(opterr = 0; (res = getopt(argc, argv, "hf:m:")) != -1; )
    {
        switch(res)
        {
            case 'h': help_flag = 1;
                      break;
            case 'f': file_path = argv[optind - 1];
                      file_flag = 1;
                      break;
            case 'm':
                    {
                        if(file_flag == 0)
                            {
                                incorrect_sequencde_file_month_flag == 1;
                            }

                            month_flag = 1;
                            month_number = (argv[optind - 1] - '0');
                            break;
                    }
                      
            case '?': printf( "unrecognized command-line option '%s'\n", argv[optind-1]);
                      break;
        }
    }

    if(help_flag)
        {
            printf("help\n");
            exit(EXIT_FAILURE);
        }
    else if (incorrect_sequencde_file_month_flag)
        {
            printf("incorrect_sequencde_file_month_flag\n");
            exit(EXIT_FAILURE);
        }
    else if(month_flag)
        {
            if((month_number < 1) || (month_number > 12))
                {
                    printf("incorrect month number\n");
                    exit(EXIT_FAILURE);
                }
        }
    else if(file_flag)
        {
             if ((file = fopen(file_path, "r")) == NULL)
            {
                printf("Can't open file %s\n", file_path);
                exit(EXIT_FAILURE);
            }
            else
            {
                printf("open file success\n");
            }
        }

    return 0; 
}