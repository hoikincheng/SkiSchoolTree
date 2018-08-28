/**
*   Person.h declares the functions for the Person class.
*
*	@author Hoi Kin Cheng.
*	@date 11/29/2017.
*/

#pragma once
#include <string>

using namespace std;

/**
*   The Person class keeps track of the name of the Person.
*/
class Person
{

private:
    string name;

public:

    /**
    *	This constructor creates a Person with a name.
    *
    *	@param name This is the name of the Person.
    *	@return Nothing.
    */
    Person(string name);

    /**
    *	This function returns the name of the Person.
    *
    *	@param Nothing.
    *	@return string This is the name of the Person.
    */
    string getName();
};
