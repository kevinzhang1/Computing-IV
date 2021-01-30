/**********************************************************************

* readme.txt template 

* Markov Model

 **********************************************************************/


Name: Kevin Zhang


Hours to complete assignment: 16 hours

/**********************************************************************

 *  Briefly discuss the assignment itself and what you accomplished.

 **********************************************************************/

Our task was to implement a program That automates the task of brute forcing to generate text according to a Markov Model in a more efficient way. I managed to accomplish in implementing the program, getting it to work, and having it pass all the tests needed.





  /**********************************************************************

 *  Discuss one or more key algorithms, data structures, or

 *  OO designs that were central to the assignment.

 **********************************************************************/


The constructor is very important because it is what’s needed to initialize the class in the first place. Without the constructor it would be impossible to even use the program. The constructor takes two arguments, a string and an integer, and uses it to initialize the private variables.




/**********************************************************************

 *  Briefly explain the workings of the features you implemented.

 *  Include code excerpts.

 **********************************************************************/


For the constructor a function, the first thing it does is that it initializes the texts variable with the string argument. It then initialize is the kgrams variable and the alphabet variable. The korder function returns the k variable. The frequency function that takes only a string returns the frequency that you can find the string in the kgrams variable. The frequency function that takes both a string and a character first pushes the character to the back of the string, then it returns the frequency that you can find the string in the kgrams variable. The krand function takes a string variable and returns a random character based on the string. The generate function takes a string and an integer and generates a random string based on the parameters. The operator function overrides the ostream operator and makes it output our properties of the class when it is entered there.




/**********************************************************************

 *  Did you complete the whole assignment?

 *  Successfully or not?

 *  Indicate which parts you think are working, and describe

 *    how you know that they're working.

 **********************************************************************/

I completed the whole assignment successfully. I feel that all parts are working because when I execute the textgenerator executable, it gives me the output I’m looking for. Also when I execute the test executable, it doesn’t show any errors in my program.




/**********************************************************************

 *  Does your implementation pass the unit tests?

 *  Indicate yes or no, and explain how you know that it does or does not.

 **********************************************************************/

Yes my implementation passes the unit tests because when I run the executable it doesn’t turn up any errors.




 /**********************************************************************

 *  Describe where you used exceptions.

 *  Provide files and lines of the code.

 ***********************************************************************/

Both frequency functions and kRand and generate function are programmed to throw a run time error whenever it gets a string and/or character who’s length is not equal to the k variable. In addition, the kRand function is also meant to throw a run time error whenever it’s argument cannot be found in the kgrams variable.




/**********************************************************************

 *  List whatever help (if any) you received from lab TAs,

 *  classmates, or anyone else.

 **********************************************************************/

I did not receive help from anyone.



/**********************************************************************

 *  Describe any serious problems you encountered.                   

 **********************************************************************/

I encountered problems in figuring out an efficient way to search for the frequency of a string in another string, but eventually I used the map vector to figure it out.



/**********************************************************************

 *  List any other comments here.                                   

 **********************************************************************/
