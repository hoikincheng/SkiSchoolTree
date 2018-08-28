/**
*   SkiSchool.h declares the functions for the SkiSchool class.
*
*	@author Hoi Kin Cheng.
*	@date 11/29/2017.
*/

#pragma once
#include "Person.h"
#include "Student.h"
#include "Instructor.h"
#include <vector>

/**
*   The SkiSchool class keeps track of Instructors and Students.
*/
class SkiSchool
{

private:

    /**
     *  This struct keeps track of a Person object and a vector that
     *  stores pointers of Node.
    */
    struct Node
    {
        Person p;
        vector<Node *> list;
    };

    Node * root;

    /**
     *  This function finds the index of the Instructor with the lowest
     *  number of Students.
     *
     *	@param Nothing.
     *	@return int This is the index of the Instructor with the lowest
     *  number of Students.
    */
    int leastStudentsIndex();

public:

    /**
     *  This constructor creates a SkiSchool with a head supervisor.
     *
     *	@param Nothing.
     *	@return Nothing.
    */
    SkiSchool();

    /**
     *  This function inserts an Instructor into SkiSchool.
     *
     *	@param i This is the Instructor to be inserted into SkiSchool.
     *	@return Nothing.
    */
    void insertInstructor(Instructor i);

    /**
     *  This function inserts a Student into SkiSchool.
     *
     *	@param s This is the Student to be inserted into SkiSchool.
     *	@return Nothing.
    */
    void insertStudent(Student s);

    /**
     *  This function inserts a Student into SkiSchool with a specified
     *  Instructor.
     *
     *	@param s This is the Student to be inserted into SkiSchool.
     *  @param instruc This is the specified Instructor.
     *	@return Nothing.
    */
    void insertStudent(Student s, Instructor i);

    /**
     *  This function removes a specified Student from SkiSchool.
     *
     *	@param s This is the Student to be removed from SkiSchool.
     *	@return bool This returns true if the Student is found and removed.
     *  Otherwise, this returns false.
    */
    bool removeStudent(Student s);

    /**
     *  This function removes a specified Instructor from SkiSchool. Any
     *  Students of that Instructor will be re-assigned to other Instructors.
     *
     *	@param instruc This is the Instructor to be removed from SkiSchool.
     *	@return bool This returns true if the Instructor is found and removed.
     *  Otherwise, this returns false.
    */
    bool removeInstructor(Instructor i);

    /**
     *  This function finds and returns an Instructor in the SkiSchool.
     *
     *	@param instrName This is the name of the instructor to look for.
     *	@return Instructor This is the Instructor to be found.
    */
    Instructor findInstructor(string instrName);

    /**
     *  This function finds and returns an Instructor that teaches the
     *  Student specified.
     *
     *	@param studentName This is the name of the Student to look for
     *  the Instructor.
     *	@return Instructor This is the Instructor to be found.
    */
    Instructor findInstrByStuName(string studentName);

    /**
     *  This function displays all the Instructors with all their Students.
     *
     *	@param Nothing.
     *	@return Nothing.
    */
    void display();

};
