/**********************************************************************
* readme.txt template
* Synthesizing a Plucked String Sound:
*	RingBuffer implementation with unit tests and exceptions
**********************************************************************/

Name: Kevin Zhang

Hours to complete assignment: 10 hours

/**********************************************************************
* Briefly discuss the assignment itself and what you accomplished.
**********************************************************************/
This assignment involves implementing a RingBuffer program that is meant to simulate plucking a guitar string using the Karplus-Strong algorithm. I accomplished in creating the header file, the cpp file, and the test file and getting it to pass the cpplint requirements.

/**********************************************************************
* Discuss one or more key algorithms, data structures, or
* OO designs that were central to the assignment.
**********************************************************************/
The constructor for the RingBuffer class is important because we need it in order to initialize the class in the first place. It initializes the capacity integer and throws an invalid if the capacity is smaller than 1.
/**********************************************************************
* Briefly explain the workings of the features you implemented.
* Include code excerpts.

**********************************************************************/
For the constructor, my code has an if(capacity<1) then throw invalid exception, print an error message, and exit. It then has this->capacity=capacity to initialize the capacity variable.
/**********************************************************************
* Did you complete the whole assignment?
* Successfully or not?
* Indicate which parts you think are working, and describe
* how you know that they're working.
**********************************************************************/
Yes. Everything is working because when I run make and test the executable it produces desirable results.
/**********************************************************************
* Does your RingBuffer implementation pass the unit tests?
* Indicate yes or no, and explain how you know that it does or does not.
**********************************************************************/
Yes they do because when I run the executable it passes with no errors.

/**********************************************************************
* Explain the time and space performance of your RingBuffer
*	implementation
**********************************************************************/
My RingBuffer implementation utilizes good time and space performance.

/**********************************************************************
* List whatever help (if any) you received from lab TAs,
* classmates, or anyone else.
**********************************************************************/
Asked TA about lambda expressions.
/**********************************************************************
* Describe any serious problems you encountered.
**********************************************************************/
No serious problems.
/**********************************************************************
* List any other comments here.
**********************************************************************/
The two lambda expressions that I have for the extra credit are in the enqueue and dequeue functions in the RingBuffer.cpp. I assumed that it was one point per lambda expression since they didn't specify how many lambda expressions are needed.
