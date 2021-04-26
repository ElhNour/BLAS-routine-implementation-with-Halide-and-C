# BLAS-routine-implementation-with-Halide-and-C
The BLAS1 (Basic Linear Algebra Subprograms) routine **xSCAL** scales a vector by a constant, and this is an implementation of it in Halide and C.<br/>
## **1. Requirements**
Install Halide from source or use the binaries (https://github.com/halide/Halide/blob/master/README.md).
## **2. Build**
2.1. Clone this repo:\
  ```git clone```\
2.2. Go to the repository using ```cd```\
2.3. Go to the "code" directory\
2.3. Run the command ```python Script.py path_to_Halide_folder```\
The script will display the execution times of both implementations and check if the results are the same.\

You can add the following args to the previous command (in this order)
## **3. Arguments**
- n: the vector length
- a: the scalar by which we want to multiply the vector
- incx: is the increment (1 by default), but if incx=2 it means we should only scale every other element
for example :\
```python Script.py '/home/nour/Halide' 100 5 1 ```



