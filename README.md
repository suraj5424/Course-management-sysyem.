# University Course Registration System

This project is a **University Course Registration System** implemented in C++. It allows students to register for courses, view course details, and check the availability of courses. The system supports three courses: *Programming*, *Databases*, and *Software Engineering*. It also keeps track of student enrollments and notifies participants if a course doesn't have enough students.

## Features

- **Register Students**: Allows students to register for available courses.
- **Track Course Participation**: Each course can have up to 10 participants.
- **Check Course Availability**: Lists all courses that are not fully booked.
- **View Course Details**: Displays the details of courses, including participants and lecturers.
- **Course Eligibility**: Enforces restrictions on how many courses a student can register for, based on their university affiliation (TU students can register for up to three courses, non-TU students can only register for one).
- **Course Cancellation Warning**: If a course has fewer than 3 students, it notifies the lecturer and students that the course will not take place.

## How It Works

1. **Lecturers and Courses**: The system is pre-populated with three courses and corresponding lecturers:
    - *Programming* (Lecturer: Prof. Pascal Frank)
    - *Databases* (Lecturer: Associate Professor Brace Gold)
    - *Software Engineering* (Lecturer: Researcher Evan Magda)

2. **Student Registration**: 
    - Students provide their details including name, email, matriculation number, and university.
    - TU students can register for up to three courses, while non-TU students can register for only one course.
    - The system prevents duplicate registration for the same course.
  
3. **Course Details**: 
    - Displays the participants and lecturer for each course.
    - If fewer than 3 students are registered for a course, the course will not take place.

4. **Menu System**: The main menu offers several options:
    - **1. Register for a course**: Allows students to register for a selected course.
    - **2. Output course details**: Displays the participants and lecturer for a selected course.
    - **3. Output not fully booked courses**: Shows courses with available slots.
    - **4. Display enrolled courses for each student**: Lists all courses a student is registered for.
    - **5. End program**: Ends the program and notifies participants and lecturers about course cancellations if any.

## Classes and Structure

- **PERSON**: Base class that holds common attributes for students and lecturers like `firstname`, `surname`, and `email`.
- **Lecturer**: Derived from PERSON, it includes additional information such as the `academic_title`.
- **Student**: Derived from PERSON, it tracks the `matriculation_number`, `university`, and enrolled courses.
- **Course**: Manages course details, the lecturer, and a list of students participating in the course.

## Program Flow

1. The user is greeted with a welcome message, and the three available courses are displayed.
2. The user can interact with the menu to register for courses, check availability, view participant lists, and more.
3. The system continuously runs until the user selects the option to end the program.

## Compilation and Execution

To compile and run the program, follow these steps:

1. **Compile**:
   ```bash
   g++ -o course_registration course_registration.cpp
   ```

2. **Run**:
   ```bash
   ./course_registration
   ```

## Example Output

```text
----:Welcome to The Tech University(TU):---

At TU university, 3 courses are offered:
 "Programming", "Databases" and "Software Engineering".

Menu:
1. Register for a course
2. Output course details
3. Output not fully booked courses
4. Display enrolled courses for each student
5. End program
Enter choice:
```

## Contributing

If you'd like to contribute to this project, please fork the repository, make your changes, and submit a pull request. Any contributions such as improvements to the functionality, bug fixes, or additional features are welcome!

## License

This project is licensed.
