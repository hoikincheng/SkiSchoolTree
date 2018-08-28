#include <iostream>
#include "SkiSchool.h"

using namespace std;

/**
 *  This function finds the index of the Instructor with the lowest
 *  number of Students.
 *
 *	@param Nothing.
 *	@return int This is the index of the Instructor with the lowest
 *  number of Students.
*/
int SkiSchool::leastStudentsIndex()
{
    int leastStudentsIndex = 0;
    for (int i = 1; i < root->list.size(); i++)
    {
        if (root->list[i]->list.size() < root->list[leastStudentsIndex]->list.size())
        {
            leastStudentsIndex = i;
        }
    }
    return leastStudentsIndex;
}

/**
 *  This constructor creates a SkiSchool with a head supervisor.
 *
 *	@param Nothing.
 *	@return Nothing.
*/
SkiSchool::SkiSchool()
{
    root = new Node{Person("supervisor"), vector<Node *>()};

}

/**
 *  This function inserts an Instructor into SkiSchool.
 *
 *	@param i This is the Instructor to be inserted into SkiSchool.
 *	@return Nothing.
*/
void SkiSchool::insertInstructor(Instructor i)
{
    Node * temp = new Node{i, vector<Node *>()};
    root->list.push_back(temp);
}

/**
 *  This function inserts a Student into SkiSchool.
 *
 *	@param s This is the Student to be inserted into SkiSchool.
 *	@return Nothing.
*/
void SkiSchool::insertStudent(Student s)
{
    if (root->list.size() == 0)
    {
        cout << "Insert student failed. Ski school must have at least 1 "
             << "instructor." << endl;
    }
    else
    {
        int leastStudentsInd = leastStudentsIndex();
        int minStudentsPerInstr = root->list[leastStudentsInd]->list.size();
        Node * temp = new Node{s, vector<Node *>()};

        if (minStudentsPerInstr < 5)
        {
            root->list[leastStudentsInd]->list.push_back(temp);
        }
        else if (minStudentsPerInstr < 8)
        {
            int mostStudentsInd;
            for (int i = 0; i < root->list.size(); i++)
            {
                if (root->list[i]->list.size() < 8)
                {
                    mostStudentsInd = i;
                    break;
                }
            }
            for (int j = mostStudentsInd; j < root->list.size(); j++)
            {
                if (root->list[j]->list.size() >
                    root->list[mostStudentsInd]->list.size() &&
                    root->list[j]->list.size() < 8)
                {
                    mostStudentsInd = j;
                }
            }
            root->list[mostStudentsInd]->list.push_back(temp);
        }
        else
        {
            root->list[leastStudentsInd]->list.push_back(temp);
        }
    }

}

/**
 *  This function inserts a Student into SkiSchool with a specified
 *  Instructor.
 *
 *	@param s This is the Student to be inserted into SkiSchool.
 *  @param instruc This is the specified Instructor.
 *	@return Nothing.
*/
void SkiSchool::insertStudent(Student s, Instructor instruc)
{
    for (int i = 0; i < root->list.size(); i++)
    {
        if(root->list[i]->p.getName() == instruc.getName())
        {
            Node * temp = new Node{s, vector<Node *>()};
            root->list[i]->list.push_back(temp);
        }
    }
}

/**
 *  This function removes a specified Student from SkiSchool.
 *
 *	@param s This is the Student to be removed from SkiSchool.
 *	@return bool This returns true if the Student is found and removed.
 *  Otherwise, this returns false.
*/
bool SkiSchool::removeStudent(Student s)
{
    for (int i = 0; i < root->list.size(); i++)
    {

        for (int j = 0; j < root->list[i]->list.size(); j++)
        {
            if(root->list[i]->list[j]->p.getName() == s.getName())
            {
                root->list[i]->list.erase(root->list[i]->list.begin() + j);
                return true;
            }
        }
    }
    return false;
}

/**
 *  This function removes a specified Instructor from SkiSchool. Any
 *  Students of that Instructor will be re-assigned to other Instructors.
 *
 *	@param instruc This is the Instructor to be removed from SkiSchool.
 *	@return bool This returns true if the Instructor is found and removed.
 *  Otherwise, this returns false.
*/
bool SkiSchool::removeInstructor(Instructor instruc)
{
    for (int i = 0; i < root->list.size(); i++)
    {
        if(root->list[i]->p.getName() == instruc.getName())
        {
            vector<Node *> temp = root->list[i]->list;
            root->list.erase(root->list.begin() + i);
            for (int j = 0; j < temp.size(); j++)
            {
                insertStudent(Student(temp[j]->p.getName()));
            }
            return true;
        }
    }
    return false;
}

/**
 *  This function finds and returns an Instructor in the SkiSchool.
 *
 *	@param instrName This is the name of the instructor to look for.
 *	@return Instructor This is the Instructor to be found.
*/
Instructor SkiSchool::findInstructor(string instrName)
{
    for (int i = 0; i < root->list.size(); i++)
    {
        if(root->list[i]->p.getName() == instrName)
        {
            return Instructor(root->list[i]->p.getName());
        }
    }

    throw "Instructor not found";
}

/**
 *  This function finds and returns an Instructor that teaches the
 *  Student specified.
 *
 *	@param studentName This is the name of the Student to look for
 *  the Instructor.
 *	@return Instructor This is the Instructor to be found.
*/
Instructor SkiSchool::findInstrByStuName(string studentName)
{
    for (int i = 0; i < root->list.size(); i++)
    {

        for (int j = 0; j < root->list[i]->list.size(); j++)
        {
            if(root->list[i]->list[j]->p.getName() == studentName)
            {
                return Instructor(root->list[i]->p.getName());
            }
        }
    }
    throw "Instructor not found";
}

/**
 *  This function displays all the Instructors with all their Students.
 *
 *	@param Nothing.
 *	@return Nothing.
*/
void SkiSchool::display()
{
    for (int i = 0; i < root->list.size(); i++)
    {
        cout << "Instructor: " << root->list[i]->p.getName() << endl;
        for (int j = 0; j < root->list[i]->list.size(); j++)
        {
            cout << "   Student: " << root->list[i]->list[j]->p.getName()
                 << endl;
        }
    }
}
