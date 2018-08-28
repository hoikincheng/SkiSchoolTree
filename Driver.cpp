/**
*   Driver.cpp demonstrates the SkiSchool object.
*
*	@author Hoi Kin Cheng.
*	@date 11/29/2017.
*/

#include <iostream>
#include "SkiSchool.h"

using namespace std;

/**
*   This is the main method which calls functions to demonstrate the
*	SkiSchool class.
*
*	@param Unused.
*	@return int This returns 0.
*/
int main()
{
    cout << "----------------------------------------------------" << endl;

    cout << "\nCreating a SkiSchool containing 3 teachers and 19 students:"
         << endl;

    SkiSchool s1;

    cout << "\nInserting 3 instructors:" << endl;
    s1.insertInstructor(Instructor("Mario"));
    s1.insertInstructor(Instructor("Donkey Kong"));
    s1.insertInstructor(Instructor("Bowser"));

    s1.display();

    cout << "\nStudents are inserted until each instructor has "
         << "5 students:" << endl;

    s1.insertStudent(Student("Luigi"));
    s1.insertStudent(Student("Donkey Kong Jr."));
    s1.insertStudent(Student("Toad"));
    s1.insertStudent(Student("Princess Peach"));
    s1.insertStudent(Student("Wario"));
    s1.insertStudent(Student("Waluigi"));
    s1.insertStudent(Student("Kirby"));
    s1.insertStudent(Student("Princess Daisy"));
    s1.insertStudent(Student("Boo"));
    s1.insertStudent(Student("Rosalina"));
    s1.insertStudent(Student("Koopa Troopa"));
    s1.insertStudent(Student("Goomba"));
    s1.insertStudent(Student("Pikachu"));
    s1.insertStudent(Student("Bulbasaur"));
    s1.insertStudent(Student("Charmander"));

    s1.display();


    cout << "\nInserting the last 4 students:" << endl;
    s1.insertStudent(Student("Squirtle"));
    s1.insertStudent(Student("Pidgey"));
    s1.insertStudent(Student("Rattata"));
    s1.insertStudent(Student("Jigglypuff"));

    s1.display();


    cout << "\n----------------------------------------------------" << endl;

    cout << "\nRemoving one teacher (Mario) from SkiSchool:" << endl;
    s1.removeInstructor(Instructor("Mario"));
    s1.display();

    cout << "\n----------------------------------------------------" << endl;

    cout << "\nAttempting to insert a student for the teacher that was "
         << "previously removed (Mario):" << endl;
    s1.insertStudent(Student("Mewtwo"), Instructor("Mario"));
    s1.display();

    cout << "\n----------------------------------------------------" << endl;

    return 0;
}
