// Michael Boling
// CSC 360


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int fib_numbers[100];
void *runner(void *param);


int main(int argc, char *argv[])
{


    pthread_t tid;
    pthread_attr_t attr;


    if (argc != 2)
    {
        // I am assumming that that the user will enter one number representing how many
        // fibonacci numbers are wanting to be outputted.
        printf("Enter the number of fibonacci numbers to generate: \n");
        return -1;
    }


    pthread_attr_init(&attr);
    // creating child thread:
    pthread_create(&tid, &attr, runner, argv[1]);
    // parent thread waiting for child thread:
    pthread_join(tid, NULL);


    char *yy = argv[1];
    int value_of_arg = atoi(yy);


    // This is outputted by the parent thread (via the global array):
    for (int i = 0; i < value_of_arg; i++)
    {
        printf("%d\n", fib_numbers[i]);
    }
}


// This function is performed by the child thread:
void *runner(void *param)
{
    fib_numbers[0] = 0;
    fib_numbers[1] = 1;
    int upper = atoi(param);
    for (int i = 2; i < upper; i++)
    {
        fib_numbers[i] = fib_numbers[i - 1] + fib_numbers[i - 2];
    }
    pthread_exit(0);
}

