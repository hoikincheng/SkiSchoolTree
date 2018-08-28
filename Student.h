/**
*   Student.h declares and defines the functions for the Student class.
*
*	@author Hoi Kin Cheng.
*	@date 11/29/2017.
*/

#pragma once

/**
*   The Student class keeps track of the name of the Student.
*/
class Student : public Person
{

public:

    /**
    *	This constructor creates a Student with a name.
    *
    *	@param name This is the name of the Student.
    *	@return Nothing.
    */
    Student(string name) : Person(name) {}

};
