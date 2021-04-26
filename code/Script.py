import os 
import sys
 
def run_c_program(): 
    base=os.path.dirname(os.path.dirname(__file__)) 
    path_compile=os.path.join(base,"xscal_c.c")  
    print(path_compile)
    os.system("gcc xscal_c.c -o ./xscal_c ")
    if (sys.argv[2]):
     os.system("./xscal_c {} {} {}".format(sys.argv[2],sys.argv[3],sys.argv[4]))   
    else: os.system("./xscal_c")

def run_halide_program(): 
    path_halide=sys.argv[1]
    base=os.path.dirname(os.path.dirname(__file__)) 
    path_compile=os.path.join(base,"xscal_halide.cpp")  
    #print(path_compile)
    os.system("g++ xscal_halide.cpp -g -lHalide -lpthread -ldl -o ./xscal_halide")
    if (sys.argv[2]):
     os.system("./xscal_halide {} {} {}".format(sys.argv[2],sys.argv[3],sys.argv[4]))   
    else: os.system("./xscal_halide")

def compare(): 
    run_halide_program()
    run_c_program()
    

    base=os.path.dirname(os.path.dirname(__file__)) 

    path_result_c=os.path.join(base,"../results/c_results.txt")  
    file_c = open(path_result_c, 'r')

    path_result_halide=os.path.join(base,"../results/halide_results.txt")  
    file_halide = open(path_result_halide, 'r')

    content_c=(file_c.read()).split(" ")
    content_halide=(file_halide.read()).split(" ")

    if (content_c==content_halide): 
        print("Success! Your implementation in Halide matches the one from C.")
        print(file_c.read())
    else: 
        print("Emm.. the results don't match, something is wrong")
    file_c.close()
    file_halide.close()

compare()



    

