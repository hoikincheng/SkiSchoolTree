#include "Person.h"

/**
*	This constructor creates a Person with a name.
*
*	@param name This is the name of the Person.
*	@return Nothing.
*/
Person::Person(string name)
{
    this->name = name;
}

/**
*	This function returns the name of the Person.
*
*	@param Nothing.
*	@return string This is the name of the Person.
*/
string Person::getName()
{
    return name;
}
