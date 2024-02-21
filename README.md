## Description:

At a university, 3 courses are offered: "**Programming**", "**Databases**" and "**Software Engineering**".

Each course is offered by a lecturer.

Create for each course an instance of type COURSE (=class) using a constructor (parameters: name of the course and the lecturer).
The lecturer is stored in a data member of type LECTURER (=class). 
The class LECTURER should have at least the data member academic_title.

The courses have a maximum of 10 and a minimum of 3 course participants.
The courses can be attended not only by our own students, but also by students from other universities.

**The class STUDENT should have at least the following data members:** 

_Matriculation number_
_University_


Students from their own university may take any course.
Students from other universities may only take one course.



The classes LECTURER and STUDENT should derive from the class PERSON.
The class PERSON should have at least the following data members:

_Surname_
_First name_
_Email_

### Task: 

Create a program with a menu that covers the following situation:

**1.** Registration for a course (including querying student data). Each student has a unique email, meaning there can't be two or more students with the same email in the same course.

**2.** Output of one/all courses with data of the participants.
    Please note that if there are fewer than 3 participants in a course, an additional message must be displayed - "Course will not take place".

**3.** Output of all courses that are not fully booked yet. The output must include the number of free places, the name of the course and the academic name of the lecturer with its academic title.

**4.** End of program: A message will be displayed stating which participants (=all data members of the class PERSON) have to be notified because your course is not taking place.


If necessary (creation, search, and so on), corresponding messages are to be displayed.
Permanent storage of the data is not required. The data must only be available at the runtime of the program.
