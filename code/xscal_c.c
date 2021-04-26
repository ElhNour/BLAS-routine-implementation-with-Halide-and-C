#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10
#define A 2
#define Incx 1

int main(int argc, char **argv){

    int n= N;
    int a=A;
    int incx=Incx;

    if (argc>2)
    {
        n=atoi(argv[1]);
        a=atoi(argv[2]);
        incx=atoi(argv[3]);
    }
    
    int vector[n];

    for (int i=0;i<n;i++){
        //filling with index of element
        vector[i]=i;
    }
    printf("\nVector\n");
    for (int i=0;i<n;i++){
        //filling with index of element
        printf("%d \t",vector[i]);
    }
    int res[n];
       // timing the execution of the xscal pipeline
    clock_t t;
    t = clock();
    for (int i=0;i<n;i+=incx){
        res[i]=a*vector[i];
    }
    // calculating the execution time of the xscal pipeline
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds*/

    printf("\n\nResult\n");
    for (int i=0;i<n;i++){
     printf("%d \t",res[i]);

    }

    FILE *fp;
    /* open the file for writing*/
    fp = fopen("../results/c_results.txt", "w+");

    /* write 10 lines of text into the file stream*/
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d ", res[i]);
    }

    /* close the file*/
    fclose(fp);

    printf("\n\nxSCAL BLAS routine implemented with C took %f seconds to execute \n", time_taken);

    return 0;
}