/**********************************************************************
 *                                                  
 *  Guitar Hero: StringSound implementation and SFML audio output 
 **********************************************************************/

Name: Kevin Zhang

Hours to complete assignment : 12 hours

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes. Every part of my assignment is working I believe. For example, the pluck function in
the StringSound class successfully simulates the plucking of a GuitarString while the
KSGuitarSim main function succeeds in opening the SFML window and playing the guitar notes.

/**********************************************************************
 *  Did you attempt the extra credit parts? Which one(s)?
 *  Successfully or not?  As a pair, or individually?
 **********************************************************************/
I did both extra credit parts individually. The lambda expressions I already attempted in
ps4a so I'm just simply using the old RingBuffer.cpp that already has lambda expressions
in enqueue and dequeue functions. I also created a second executable called extracredit
that does the same thing as KSGuitarSim except that the sounds that play are different.
I did it by changing the frequency to be equal to 440 x 2^((i-64)/12.0) instead of
440 x 2^((i-24)/12.0) which results in a sound that sounds like stereo music or haunted house.

/**********************************************************************
 *  Did you implement exseptions to check your StringSound 
 *	implementation?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
Yes. I created two exceptions. First in the StringSound(double frequency) constructor if the
argument is smaller than or equal to zero it throws an invalid argument exception saying that
the frequency has to be greater than zero. The second is in the tic function where if the size
is smaller than or equal to 1 then it throws an exception saying that the size is too small.
/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/
I did not recieve any help from anybody.


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I struggled to figure out how to read the character text that was entered until the keyboard
until I searched online and found out how to do it.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
