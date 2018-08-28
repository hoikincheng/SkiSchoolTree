/**
*   Instructor.h declares and defines the functions for the Instructor class.
*
*	@author Hoi Kin Cheng.
*	@date 11/29/2017.
*/

#pragma once


/**
*   The Instructor class keeps track of the name of the Instructor.
*/
class Instructor : public Person
{

public:

    /**
    *	This constructor creates an Instructor with a name.
    *
    *	@param name This is the name of the Instructor.
    *	@return Nothing.
    */
    Instructor(string name) : Person(name) {}

};
