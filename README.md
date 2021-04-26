# BLAS-routine-implementation-with-Halide-and-C
The BLAS1 (Basic Linear Algebra Subprograms) routine **xSCAL** scales a vector by a constant, and this is an implementation of it in Halide and C.<br/>
## **1. Requirements**
Install Halide from source or use the binaries (https://github.com/halide/Halide/blob/master/README.md).
## **2. Build**
2.1. Clone this repo\
     git clone\
2.2. Go to the repository using cd\
2.3. Run the make command to build the files\
     make halidePath="/home/nour/Halide/"\
## **3. Arguments**
Arguments are the same for both Halide program and C program.\
- n: the vector length\
- a: the scalar by which we want to multiply the vector\
- incx: is the increment (1 by default), but if incx=2 it means we should only scale every other element\
## **4. Execution**
### **4.1. C program:**
- with default values : bin/c\
- with arguments : bin/c n a incx\
for example : bin/c 50 8 3\
### **4.2. Halide program:**
- Set the Halide path variable:halidePath="/home/nour/Halide/"\
-with default values : LD_LIBRARY_PATH=$halidePath/bin bin/halide\
-with arguments : LD_LIBRARY_PATH=$halidePath/bin bin/halide n a incx\
for example:\
LD_LIBRARY_PATH=$halidePath/bin bin/halide  100 12 1\
## **5. Comparison**
- Give the script execution permissions :\ 
    chmod +x comparison.sh\
-then run the script while providing the Halide path:\
    ./comparison.sh -p "/home/nour/Halide/"\
-or using the variable we set earlier:\
    ./comparison.sh -p $halidePath\
The script will display the execution times of both implementations and check if the results are the same\

