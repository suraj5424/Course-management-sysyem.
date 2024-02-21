#include <iostream> // improted library for input and output functionality
#include <limits> //library for numeric functionality.
#include <string>// library for string functionality.

using namespace std;// to use standard terms of the libraries without error.

// created the base class PERSON to derive.
class PERSON {
public:
    string surname;
    string firstname;
    string email;
    // craeted method to fetch the details of the PERSON.
    string getDetails() const {
        return firstname + " " + surname + " (" + email + ")";
    }
};

// created Lecturer class which is inheriting from PERSON.
class Lecturer : public PERSON {
public:
    string academic_title;
    
    //created CONSTRUCTORS for the Lecturer class.
    Lecturer() {} //default constructor.

    Lecturer(const string& prefix, const string& name, const string& mail, const string& subject) {
        academic_title = prefix;
        firstname = name;
    }
};
// created Student class which is inheriting from PERSON.
class Student : public PERSON {
public:
    int matriculation_number;
    string university;
    int enrolled_course_count = 0;
    string enrolled_courses[3];
};

// created COURSE class 
class Course {
public:
    string course_name; // created object of the Lecturer class to fetch the details of lecturers.
    Lecturer lecturer;
    Student participants[10];  // created object of the Student class to fetch the details of lecturers.
    int participant_count = 0;

    // constuctor for course class.
    Course(string name, Lecturer lecturer) : course_name(name), lecturer(lecturer) {}
};
// created fuction that will display the details of courses.
void displayCourse(const Course& course) {
        // this will dispaly the course name, lecturer and participants details
    cout << "Course: " << course.course_name << ", Lecturer: " << course.lecturer.firstname << " "
        << course.lecturer.surname << " (" << course.lecturer.academic_title << ")" << endl;

    cout << "Participants:" << endl;
    for (int i = 0; i < course.participant_count; ++i) {
        cout << course.participants[i].firstname << " " << course.participants[i].surname << " (" << course.participants[i].email << ")" << endl;
    }

// added condition for a class to be held.
    if (course.participant_count < 3) {
        cout << "Course will not take place." << endl;
    }
}
// created fuction that will display the details of courses.
void displayNotFullyBookedCourses(const Course courses[], int courseCount) {
    cout << "Courses not fully booked:" << endl;
    for (int i = 0; i < courseCount; ++i) {
        int free_places = 10 - courses[i].participant_count;
        if (free_places > 0) {
            cout << "Course: " << courses[i].course_name << ", Free Places: " << free_places << ", Lecturer: "
                << courses[i].lecturer.firstname << " " << courses[i].lecturer.surname << " (" << courses[i].lecturer.academic_title << ")" << endl;
        }
    }
}
// added fuction that will show the enrolled course 
void displayEnrolledCourses(const Student students[], int studentCount) {
    cout << "Enrolled courses for each student:" << endl;
    for (int i = 0; i < studentCount; ++i) {
        cout << students[i].firstname << " " << students[i].surname << ": ";
        for (int j = 0; j < students[i].enrolled_course_count; ++j) {
            cout << students[i].enrolled_courses[j] << ", ";
        }
        cout << endl;
    }
}
// function to handle invalid data.
void handleInvalidInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input. Please enter a valid number." << endl;
}

// intiated main function 
int main() {
    
    
    // created instance for each lecturer in lecturer class
    // names taken here are completely random. 
    Lecturer programmingLecturer{"frank", "pascal", "frank@gmail.com", "Professor"};
    Lecturer databasesLecturer{"gold", "brace", "gold@gmail.com", "Associate Professor"};
    Lecturer softwareEngineeringLecturer{"magda", "evan", "magda@gmail.com", "researcher"};

// created instances for course using constructor.
    Course allCourses[3] = {
        Course("Programming", programmingLecturer),
        Course("Databases", databasesLecturer),
        Course("Software Engineering", softwareEngineeringLecturer)
    };

// created an array to store student data.
    Student allStudents[30];
    int choice; // to store the user input choice
    int courseCount = 3;
    int studentCount = 0;
    
    
    //  added welcome message with course infromation.

    cout << "----:Welcome to The Tech University(TU):---\n";
    cout << "\nAt TU university, 3 courses are offered:\n \"Programming\", \"Databases\" and \"Software Engineering\".\n";

// dispalyed the menus which can be performed.
    do {
        cout << "\nMenu:";
        cout << "\n1. Register for a course";
        cout << "\n2. Output course details";
        cout << "\n3. Output not fully booked courses";
        cout << "\n4. Display enrolled courses for each student";
        cout << "\n5. End program";
        cout << "\nEnter choice: ";
// handled the invalid input 
        if (!(cin >> choice)) {
            handleInvalidInput();
            continue;
        }

// use SWITCH to perform different actions for menu.
        switch (choice) {
            case 1: {
                int courseChoice;

                cout << "Enter the course number you'd like to register for:\n";
                cout << "1: Programming\n";
                cout << "2: Databases\n";
                cout << "3: Software Engineering\n";
                cout << "Enter choice: ";
// handled in valid input.
                if (!(cin >> courseChoice)) {
                    handleInvalidInput();
                    continue;
                }

                if (courseChoice >= 1 && courseChoice <= 3) {
                    Course& selectedCourse = allCourses[courseChoice - 1];
// verify if seates are valible or not. then will proceeed
                    if (selectedCourse.participant_count < 10) {
                        Student student;

                        cout << "Enter student details:" << endl;
                        cout << "First name: ";
                        cin >> student.firstname;

                        cout << "Last name: ";
                        cin >> student.surname;

                        cout << "Email: ";
                        cin >> student.email;

                        cout << "Matriculation number: ";
                        while (!(cin >> student.matriculation_number)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Invalid input. Please enter a number: ";
                        }
                        cout << "\nStudents from TU will write TU in the University field\n";
                        cout << "University: ";
                        cin >> student.university;
                        // for unique email and student from TU can register for three courses using same email address.
                        // non TU student and register for only one course using same email address.
                        bool emailExists = false;
                        for (int i = 0; i < studentCount; ++i) {
                            if (allStudents[i].email == student.email) {
                                emailExists = true;
                                if ((student.university == "TU" && allStudents[i].enrolled_course_count < 3) ||
                                    (student.university != "TU" && allStudents[i].enrolled_course_count == 0)) {
                                    if (selectedCourse.participant_count < 10) {
                                        selectedCourse.participants[selectedCourse.participant_count++] = student;
                                        allStudents[i].enrolled_courses[allStudents[i].enrolled_course_count++] = selectedCourse.course_name;
                                        cout << "Successfully registered for the course " << selectedCourse.course_name << "." << endl;
                                    } else {
                                        cout << "Course is fully booked." << endl;
                                    }
                                } else {
                                    if (student.university == "TU") {
                                        cout << "You have registered for all three courses." << endl;
                                    } else {
                                        cout << "You have already registered for a course." << endl;
                                    }
                                }
                                break;
                            }
                        }
                         //if new email is going to be registred.
                        if (!emailExists) {
                            allStudents[studentCount++] = student;
                            selectedCourse.participants[selectedCourse.participant_count++] = student;
                            allStudents[studentCount - 1].enrolled_courses[allStudents[studentCount - 1].enrolled_course_count++] = selectedCourse.course_name;
                            cout << "Successfully registered for the course " << selectedCourse.course_name << "." << endl;
                        }
                    } else {
                        cout << "Course is fully booked." << endl;
                    }
                } else {
                    cout << "Invalid choice!" << endl;
                }
                break;
            }
            case 2: {
                int courseChoice;
                    
                    // dispalyed the details for user to select the course.
                cout << "Enter the course number for which you'd like to display the details:\n";
                cout << "1: Programming\n";
                cout << "2: Databases\n";
                cout << "3: Software Engineering\n";
                cout << "Enter choice: ";
                // handles invalid input
                if (!(cin >> courseChoice)) {
                    handleInvalidInput();
                    continue;
                }

                if (courseChoice >= 1 && courseChoice <= 3) {
                    Course& selectedCourse = allCourses[courseChoice - 1];
                    displayCourse(selectedCourse);
                } else {
                    cout << "Invalid choice!" << endl;
                }
                break;
            }
            case 3: {
                displayNotFullyBookedCourses(allCourses, courseCount);
                break;
            }
            case 4: {
                displayEnrolledCourses(allStudents, studentCount);
                break;
            }
            case 5:
                cout << " Participants and professors to be notified if the course does not take place:" << endl;
                
                // to display the information of the persons who will be notified when course will not take place due to less than 3 students participation.

                for (int i = 0; i < courseCount; ++i) {
                    if (allCourses[i].participant_count < 3) {
                        cout << "For course '" << allCourses[i].course_name << "':";
                        for (int j = 0; j < allCourses[i].participant_count; ++j) {
                            cout << " " << allCourses[i].participants[j].getDetails();
                        }
                        cout << ". Prof. " << allCourses[i].lecturer.firstname << " " << allCourses[i].lecturer.surname << " (" << allCourses[i].lecturer.academic_title << ")";
                        cout << endl;
                    }
                }
                cout << "END THE PROGRAM" << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != 5);
    // loop ends

    return 0;
}
// code completed 