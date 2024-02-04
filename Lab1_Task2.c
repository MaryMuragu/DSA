#include <iostream>
#include <iomanip>
#include <cstring>

const int MAX_STUDENTS = 40;
const int MAX_STRING_LENGTH = 50;

struct Course {
    char course_code[MAX_STRING_LENGTH];
    char course_name[MAX_STRING_LENGTH];
};

struct Grade {
    int mark;
    char the_grade;
};

struct Student {
    char registration_number[MAX_STRING_LENGTH];
    char name[MAX_STRING_LENGTH];
    int age;
    Course course;
    Grade grades;
    bool grades_calculated;  
};

// Function to add a new student
void addStudent(Student students[], int& studentCount) {
    if (studentCount < MAX_STUDENTS) {
        Student newStudent;
        std::cout << "Enter registration number: ";
        std::cin >> std::setw(MAX_STRING_LENGTH) >> newStudent.registration_number;
        std::cout << "Enter name: ";
        std::cin >> std::setw(MAX_STRING_LENGTH) >> newStudent.name;
        std::cout << "Enter age: ";
        std::cin >> newStudent.age;
        std::cout << "Enter course code: ";
        std::cin >> std::setw(MAX_STRING_LENGTH) >> newStudent.course.course_code;
        std::cout << "Enter course name: ";
        std::cin >> std::setw(MAX_STRING_LENGTH) >> newStudent.course.course_name;

        students[studentCount] = newStudent;
        studentCount++;
        std::cout << "Student added successfully!\n";
    } else {
        std::cout << "Maximum number of students reached.\n";
    }
}

void editStudent(Student students[], int studentCount) {
    if (studentCount > 0) {
        char regNumber[MAX_STRING_LENGTH];
        std::cout << "Enter registration number of the student to edit: ";
        std::cin >> std::setw(MAX_STRING_LENGTH) >> regNumber;

        for (int i = 0; i < studentCount; i++) {
            if (strcmp(students[i].registration_number, regNumber) == 0) {
                std::cout << "Enter new registration number: ";
                std::cin >> std::setw(MAX_STRING_LENGTH) >> students[i].registration_number;
                std::cout << "Enter new name: ";
                std::cin >> std::setw(MAX_STRING_LENGTH) >> students[i].name;
                std::cout << "Enter new age: ";
                std::cin >> students[i].age;
                std::cout << "Enter new course code: ";
                std::cin >> std::setw(MAX_STRING_LENGTH) >> students[i].course.course_code;
                std::cout << "Enter new course name: ";
                std::cin >> std::setw(MAX_STRING_LENGTH) >> students[i].course.course_name;

                std::cout << "Student details updated successfully!\n";
                return;
            }
        }
        std::cout << "Student not found.\n";
    } else {
        std::cout << "No students to edit.\n";
    }
}

void addMarks(Student students[], int studentCount) {
    if (studentCount > 0) {
        char regNumber[MAX_STRING_LENGTH];
        std::cout << "Enter registration number of the student to add marks: ";
        std::cin >> std::setw(MAX_STRING_LENGTH) >> regNumber;

        for (int i = 0; i < studentCount; i++) {
            if (strcmp(students[i].registration_number, regNumber) == 0) {
                if (!students[i].grades_calculated) {
                    std::cout << "Enter mark for " << students[i].name << ": ";
                    std::cin >> students[i].grades.mark;

                    if (students[i].grades.mark > 69) {
                        students[i].grades.the_grade = 'A';
                    } else if (students[i].grades.mark > 59) {
                        students[i].grades.the_grade = 'B';
                    } else if (students[i].grades.mark > 49) {
                        students[i].grades.the_grade = 'C';
                    } else if (students[i].grades.mark > 39) {
                        students[i].grades.the_grade = 'D';
                    } else {
                        students[i].grades.the_grade = 'E';
                    }

                    students[i].grades_calculated = true;
                    std::cout << "Marks and grades added successfully!\n";
                } else {
                    std::cout << "Grades already calculated for this student.\n";
                }
                return;
            }
        }
        std::cout << "Student not found.\n";
    } else {
        std::cout << "No students to add marks.\n";
    }
}

void displayStudentDetails(Student students[], int studentCount) {
    if (studentCount > 0) {
        std::cout << "Student Details:\n";
        for (int i = 0; i < studentCount; i++) {
            std::cout << "---------------------\n";
            std::cout << "Registration Number: " << students[i].registration_number << "\n";
            std::cout << "Name: " << students[i].name << "\n";
            std::cout << "Age: " << students[i].age << "\n";
            std::cout << "Course Code: " << students[i].course.course_code << "\n";
            std::cout << "Course Name: " << students[i].course.course_name << "\n";
            std::cout << "Grades Calculated: " << (students[i].grades_calculated ? "Yes" : "No") << "\n";
            if (students[i].grades_calculated) {
                std::cout << "Mark: " << students[i].grades.mark << "\n";
                std::cout << "Grade: " << students[i].grades.the_grade << "\n";
            }
        }
    } else {
        std::cout << "No students to display.\n";
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Edit Student Details\n";
        std::cout << "3. Add Marks and Calculate Grades\n";
        std::cout << "4. Display Student Details\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, studentCount);
                break;
            case 2:
                editStudent(students, studentCount);
                break;
            case 3:
                addMarks(students, studentCount);
                break;
            case 4:
                displayStudentDetails(students, studentCount);
                break;
            case 5:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
