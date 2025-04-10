# Student-Information-System
This C++ program implements a simple Student Information System (SIS). It allows managing a list of students, where each student has personal details (first name, last name, and student ID) and a list of courses with their corresponding grades and units.\
The system provides several functionalities, including adding students, assigning courses, printing student report cards, and calculating the GPA for each student or a specific course.\
The program uses a doubly linked list to store students and their associated courses. Each student can be linked to multiple courses, and the system can efficiently traverse the list of students and courses.\
________________________________________
Key Data Structures\
1.	Student Structure:\
o	id: Unique identifier for the student (string).\
o	fname: Student's first name (string).\
o	lname: Student's last name (string).\
o	course: Pointer to the first course associated with the student (Course pointer).\
o	next: Pointer to the next student in the list (Student pointer).\
o	prev: Pointer to the previous student in the list (Student pointer).\
2.	Course Structure:\
o	id: Unique identifier for the course (string).\
o	name: Name of the course (string).\
o	grade: Grade the student received in the course (float).\
o	unit: Number of course units (int).\
o	next: Pointer to the next course in the list (Course pointer).\
o	prev: Pointer to the previous course in the list (Course pointer).\
________________________________________
Functions in the Program\
1.	getValidInt():\
o	This function is used to validate integer input. It ensures that the user enters a valid integer, and if not, it prompts the user to try again.\
o	Usage: Called whenever the program expects an integer input (e.g., menu choice or course units).\
2.	getValidFloat():\
o	Similar to getValidInt(), this function validates that the input is a valid floating-point number (used for course grades).\
o	Usage: Used when the program expects a float input, ensuring the user enters a valid number for grades.\
3.	insert_student(Student* head):\
o	This function inserts a new student into the linked list. It prompts the user for the student's first name, last name, and ID. It ensures that no two students have the same ID.\
o	How it works: \
	Creates a new Student structure.\
	Checks if a student with the same ID already exists in the list. If found, the student is not added.\
	Appends the new student to the end of the list if the list is not empty.\
o	Usage: Called when the user selects the option to add a new student.\
4.	insert_course(Course* head):\
o	This function inserts a new course for a student. It prompts the user for the course name, ID, grade, and number of units. It ensures no course has the same ID.\
o	How it works: \
	Creates a new Course structure.\
	Checks if a course with the same ID exists in the list of courses for the student. If found, the course is not added.\
	Appends the new course to the end of the course list for the student.\
o	Usage: Called when a student is being assigned a new course.\
5.	student_add_course(Student* head):\
o	This function adds a course to a specific student by asking for the student ID.\
o	How it works: \
	Searches for the student by ID.\
	If the student is found, it calls insert_course() to add a new course to that student.\
	If the student is not found, it notifies the user.\
o	Usage: Called when the user selects the option to assign a course to a student.\
6.	print_student_course(Student* head):\
o	This function prints a student's report card, including their courses, grades, and GPA.\
o	How it works: \
	Searches for the student by ID.\
	If the student is found, it prints each course, its grade, and units.\
	It also calculates and prints the GPA, which is the weighted average of the grades based on course units.\
	If no courses are assigned to the student, it displays a message indicating that the student has no courses.\
o	Usage: Called when the user selects the option to print a student's report card.\
7.	main():\
o	The main entry point of the program. It provides a menu interface to the user to perform various operations, such as adding a student, assigning courses, printing report cards, and more.\
o	How it works: \
	The program displays a menu and prompts the user to enter a choice.\
	Depending on the user's choice, the corresponding function is called (e.g., insert_student(), student_add_course()).\
	The menu continues until the user chooses to exit.

