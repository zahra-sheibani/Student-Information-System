#include <iostream>
#include <limits>  // For input validation

using namespace std;

struct Course {
    string id;
    string name;
    float grade;
    int unit;
    Course* next;
    Course* prev;
};

struct Student {
    string id;
    string fname;
    string lname;
    Course* course;
    Student* next;
    Student* prev;
};

// Function to validate integer input
int getValidInt() {
    int value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cout << "Invalid input! Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return value;
}

// Function to validate float input
float getValidFloat() {
    float value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cout << "Invalid input! Please enter a valid number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return value;
}

// Insert a new student into the list
Student* insert_student(Student* head) {
    Student* newStudent = new Student;
    cout << "Enter first name: ";
    cin >> newStudent->fname;
    cout << "Enter last name: ";
    cin >> newStudent->lname;
    cout << "Enter student ID: ";
    cin >> newStudent->id;

    // Check if student already exists
    Student* temp = head;
    while (temp != nullptr) {
        if (temp->id == newStudent->id) {
            cout << "This student already exists!\n";
            delete newStudent;
            return head;
        }
        temp = temp->next;
    }

    newStudent->prev = nullptr;
    newStudent->next = nullptr;
    newStudent->course = nullptr;

    if (head == nullptr)
        return newStudent;

    // Append to the end of the list
    temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    
    temp->next = newStudent;
    newStudent->prev = temp;
    
    cout << "Student added successfully.\n";
    return head;
}

// Insert a course for a student
Course* insert_course(Course* head) {
    Course* newCourse = new Course;
    cout << "Enter course name: ";
    cin >> newCourse->name;
    cout << "Enter course ID: ";
    cin >> newCourse->id;
    cout << "Enter student grade in this course: ";
    newCourse->grade = getValidFloat();
    cout << "Enter the number of units for the course: ";
    newCourse->unit = getValidInt();

    newCourse->next = nullptr;
    newCourse->prev = nullptr;

    // Check if course already exists
    Course* temp = head;
    while (temp != nullptr) {
        if (temp->id == newCourse->id) {
            cout << "This course is already available.\n";
            delete newCourse;
            return head;
        }
        temp = temp->next;
    }

    if (head == nullptr)
        return newCourse;

    temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newCourse;
    newCourse->prev = temp;

    return head;
}

// Assign a course to a student
Student* student_add_course(Student* head) {
    cout << "Enter student ID: ";
    string stid;
    cin >> stid;

    Student* temp = head;
    while (temp != nullptr) {
        if (temp->id == stid) {
            temp->course = insert_course(temp->course);
            return head;
        }
        temp = temp->next;
    }

    cout << "Student not found!\n";
    return head;
}

// Print a student's report card
void print_student_course(Student* head) {
    cout << "Enter student ID: ";
    string stid;
    cin >> stid;

    Student* temp = head;
    while (temp != nullptr) {
        if (temp->id == stid) {
            cout << temp->fname << " " << temp->lname << "'s Courses:\n";
            if (temp->course == nullptr) {
                cout << "No courses enrolled.\n";
                return;
            }

            Course* course = temp->course;
            float totalGrade = 0;
            int totalUnits = 0;

            while (course != nullptr) {
                cout << "Course: " << course->name << " (ID: " << course->id << ")\n";
                cout << "Grade: " << course->grade << ", Units: " << course->unit << "\n";
                totalGrade += course->grade * course->unit;
                totalUnits += course->unit;
                course = course->next;
            }

            cout << "GPA: " << (totalGrade / totalUnits) << "\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Student not found!\n";
}

// Main menu
int main() {
    Student* head = nullptr;
    int choice;

    while (true) {
        cout << "\n1. Add Student\n";
        cout << "2. Add Course to Student\n";
        cout << "3. Print Student Report Card\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        choice = getValidInt();

        switch (choice) {
            case 1:
                head = insert_student(head);
                break;
            case 2:
                head = student_add_course(head);
                break;
            case 3:
                print_student_course(head);
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
