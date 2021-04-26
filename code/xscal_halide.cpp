//xSCAL Halide implementation - - scale a vector by a constant
#include "Halide.h"
#include "time.h"

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace Halide;
using namespace std;

//Default values
#define N 10
#define A 2
#define Incx 1


int main(int argc, char **argv) {
  
    int n=N;
    int a=A;
    int incx=Incx;

    if (argc>2)
    {
        n=atoi(argv[1]);
        a=atoi(argv[2]);
        incx=atoi(argv[3]);
    }

    Var vect;
    // declare  the Halide fillVector pipline
    Func fillVector;
    // Add definition to the Halide fillVector pipline
    fillVector(vect)=Halide::cast<int>(vect);
    // Add parallalisation using the vect to the Halide fillVector pipline
    fillVector.parallel(vect);

    //Initialize the buffer
    Buffer<int> vector = fillVector.realize(n);

    cout << "\nVector\n" << endl;
    for (int i=0;i<vector.width();i++){
        cout << vector(i)<< "\t";
    }

    Var Y;
   Func xscal;

   xscal(Y)=a*vector(Y);
   xscal.parallel(Y);

    clock_t t = clock();

    Buffer<int> result = xscal.realize(n);

    t = clock() - t;
    // calculating the execution time of the gemv pipeline
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    // Print the Values to the screen if in debug
   
    cout << "\n\nResult\n";
    for (int i = 0; i < result.width(); i++)
    {
        cout << result(i) << "\t";
    }

    ofstream myfile;
    myfile.open("../results/halide_results.txt");
    for (int i = 0; i < result.width(); i++)
    {
        myfile << result(i) << " ";
    }
    myfile.close();

    printf("\n\nxSCAL BLAS routine implemented with Halide took %f seconds to execute \n", time_taken);
    return 0;
}