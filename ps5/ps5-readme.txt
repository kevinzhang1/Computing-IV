/**********************************************************************
 *  readme 
 *  DNA Sequence Alignment
 **********************************************************************/

Name: Kevin Zhang

Hours to complete assignment: 12 hours

/**********************************************************************
    * Explain which approach you decided to use when implementing
 * (either recursive with memoization, recursive without memoization,
 * dynamic programming or Hirschberg?s algorithm). Also describe why
      * you chose this approach and what its pros and cons are.
**********************************************************************/
I use dynamic programming instead of recursion for implementing this. I chose
this approach because I felt that it was easier to wrap my head around it then
if I use recursion. Recursion tends to be unpredictable. The advantages of
dynamic programming are that it breaks up a problem into smaller sub problems
and then stores the answer to the sub problems and then uses the stored answers
to solve the original problem which avoids computing the same quantity over
and over again. The disadvantages to dynamic programming are that each situation
for dynamic programming requires it’s own way of creating it. Also storing the
answers to the sub problems can take up memory.

/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/
Input:

atattat_
_tattata

Expected output:

Edit distance = 2
a _ 1
t t 0
a a 0
t t 0
t t 0
a a 0
t t 0
_ a 1

What happened:

Before I inserted the gaps the program terminated
 after throwing an instance of out of range
 exception after I inserted the caps the program
 printed out the output as shown above.
/**********************************************************************
 * Look at your computer?s specs in the settings and find the total 
 * amount of RAM. Place it below. 
 **********************************************************************/

The amount of RAM storage on my linux machine is
 1.9GB

/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 8GB (billion bytes) of memory?
 **********************************************************************/
a = 24
b = 4
largest N = 8 Billion bytes since that's the memory capacity

/**********************************************************************
 * Run valgrind if you can and attach the output file to your submission. 
 * If you cannot run it, explain why, and list all errors you?re seeing. 
 * If you can run it successfully, does the memory usage nearly match that 
 * found in the question above? 
 * Explain why or why not. 
/**********************************************************************
I ran valgrind while executing the program and
having example10.text be the input file that the
program was inputting. The massiffile is attached to
 the submission in the form of massif.out.27581. The
 program usage does not appear to match that found
 in the question above most likely because the
 amount of gigabytes that my computer has available
 is different from the problem shown above.
/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
 *  out the last rows of the table.
 **********************************************************************/

data file           distance       time (seconds)     memory (MB)
------------------------------------------------------------------
ecoli2500.txt       121      Got Segmentation Fault
ecoli5000.txt       163      Got Segmentation Fault
ecoli7000.txt       197      Got Segmentation Fault
ecoli10000.txt      226      Got Segmentation Fault
ecoli20000.txt      3177     Got Segmentation Fault
ecoli28284.txt   Could not find distance 10 seconds

/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730



/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
a = 2
b = 2
largest N = it depends on the speed of the computer

/
**********************************************************************
 *  Did you use the lambda expression in your assignment? If yes, where 
 * (describe a method or provide a lines numbers)
 **********************************************************************/

I used two lambda expressions, one in the main.cpp file where I have to print
out the distance and the other in the ED.cpp in the OptDistance method where
the method is called push and it's used where the vector is pushed into the
matrix.


**********************************************************************
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
