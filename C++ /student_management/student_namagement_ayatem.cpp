#include <iostream>
#include <string>
#include <iomanip>

using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::ws;
using std::setw;

enum StudentStatus { PASS, FAIL, INCOMPLETE };

union StudentID {
    int numericID;
    char codeID[10];
};

struct Student {
    StudentID idData;
    bool isNumericID;
    string name;
    int trackIndex;
    double grade[5];
    double gpa;
    StudentStatus status;
};

static int nextStudentId = 726;

// Function Prototypes
void start(const string subjects[][5], Student* list, int& size, int capacity);
void NewStudentFromUser(Student* list, int& size, int capacity);
Student NewStudentInfo();
void displayStudents(const Student* list, const int size);
void displayStudentGrades(const Student* list, const int size, const string subjects[][5]);
void searchById(const Student* list, const int size, const string subjects[][5]);
void searchByName(const Student* list, const int size);
void searchStudent(const Student* list, const int size, const string subjects[][5]);
void deleteStudent(Student* list, int& size);
void computeGPA(Student* list, const int size, const string subjects[][5]);
void calculateStudentGPA(Student* st);
string calculateGrade(double score);
string getStatusString(StudentStatus s);

int main() {
    int maxCapacity = 100;
    int totalCount = 3;

    Student* studentList = new Student[maxCapacity];

    // Student 1
    (studentList + 0)->idData.numericID = 101;
    (studentList + 0)->isNumericID = true;
    (studentList + 0)->name = "Alice Johnson";
    (studentList + 0)->trackIndex = 0;
    (studentList + 0)->grade[0] = 88.0; (studentList + 0)->grade[1] = 92.5;
    (studentList + 0)->grade[2] = 79.0; (studentList + 0)->grade[3] = 95.0; (studentList + 0)->grade[4] = 85.0;

    // Student 2
    (studentList + 1)->idData.numericID = 102;
    (studentList + 1)->isNumericID = true;
    (studentList + 1)->name = "Bob Smith";
    (studentList + 1)->trackIndex = 1;
    (studentList + 1)->grade[0] = 55.0; (studentList + 1)->grade[1] = 60.0;
    (studentList + 1)->grade[2] = 58.0; (studentList + 1)->grade[3] = 62.0; (studentList + 1)->grade[4] = 48.0;

    // Student 3
    (studentList + 2)->idData.numericID = 103;
    (studentList + 2)->isNumericID = true;
    (studentList + 2)->name = "Charlie Brown";
    (studentList + 2)->trackIndex = 2;
    (studentList + 2)->grade[0] = 95.0; (studentList + 2)->grade[1] = 98.0;
    (studentList + 2)->grade[2] = 91.0; (studentList + 2)->grade[3] = 94.0; (studentList + 2)->grade[4] = 93.0;

    const string subjects[3][5] = {
        {"Calculus", "Physics", "Programming", "Statistics", "English"},
        {"Calculus II", "Physics II", "Circuits", "Thermodynamics", "Linear Algebra"},
        {"Biology", "Chemistry", "Algebra", "Psychology", "Technical Writing"}
    };

    // Initial GPA Calculation for pre-loaded students
    for (int i = 0; i < totalCount; i++) {
        calculateStudentGPA(studentList + i);
    }

    cout << "\n====================(STUDENT MANAGEMENT SYSTEM)====================\n";
    
    start(subjects, studentList, totalCount, maxCapacity);

    delete[] studentList;
    studentList = nullptr;

    return 0;
}

// Converts numerical score to letter grade automatically
string calculateGrade(double score) {
    if (score >= 90.0) return "A";
    if (score >= 80.0) return "B";
    if (score >= 70.0) return "C";
    if (score >= 60.0) return "D";
    return "F";
}

// Calculates single student's GPA and Status
void calculateStudentGPA(Student* st) {
    if (st == nullptr) return;

    double total = 0.0;
    for (int g = 0; g < 5; g++) {
        total += st->grade[g];
    }
    double avg = total / 5.0;
    st->gpa = (avg / 100.0) * 4.0;
    st->status = (st->gpa >= 2.0) ? PASS : FAIL;
}

string getStatusString(StudentStatus s) {
    switch (s) {
        case PASS: return "PASS";
        case FAIL: return "FAIL";
        case INCOMPLETE: return "INCOMPLETE";
        default: return "UNKNOWN";
    }
}

void start(const string subjects[][5], Student* list, int& size, int capacity) {
    int command;
    do {
        cout << "\n1: Add Student\n"
            << "2: Display All Students\n"
            << "3: Display Student Grades\n"
            << "4: Search Student\n"
            << "5: Edit /(Compute GPA)\n"
            << "6: Delete Student\n"
            << "7: Exit\n";
        cout << "\n---command---->: (use numbers to navigate): ";
        
        if (!(cin >> command)) break;

        switch (command) {
            case 1:
                NewStudentFromUser(list, size, capacity);
                break;
            case 2:
                displayStudents(list, size);
                break;
            case 3:
                displayStudentGrades(list, size, subjects);
                break;
            case 4:
                searchStudent(list, size, subjects);
                break;
            case 5:
                computeGPA(list, size, subjects);
                break;
            case 6:
                deleteStudent(list, size);
                break;
            case 7:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "\n\t Invalid Entry Please Try Again.\n";
                break;
        }
    } while (command != 7);
}

void NewStudentFromUser(Student* list, int& size, int capacity) {
    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        if (size >= capacity) {
            cout << "Record capacity full.\n";
            break;
        }
        
        *(list + size) = NewStudentInfo();
        calculateStudentGPA(list + size);
        size++;
        
        cout << "Student added successfully!!\n";
        
        while (true) {
            cout << "Do you want to add another student? (y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N') {
                break;
            }
            cout << "Invalid Choice! Please enter 'y' or 'n'.\n";
        }
    }
}

Student NewStudentInfo() {
    Student st;
    st.idData.numericID = nextStudentId++;
    st.isNumericID = true;
    st.status = INCOMPLETE;
    st.gpa = 0.0;

    cout << "\n[Generated ID: " << st.idData.numericID << "]\n";
    cout << "Enter Student Name: ";
    getline(cin >> ws, st.name);

    cout << "Select Track (0: CS, 1: Engineering, 2: Science): ";
    cin >> st.trackIndex;
    if (st.trackIndex < 0 || st.trackIndex > 2) st.trackIndex = 0;

    cout << "Enter 5 Grades:\n";
    for (int i = 0; i < 5; i++) {
        cout << " Grade " << i + 1 << ": ";
        cin >> st.grade[i];
    }

    return st;
}

void displayStudents(const Student* list, const int size) {
    cout << "\n====================(Registered Students)====================\n";
    if (size == 0) {
        cout << "No students registered yet.\n";
        return;
    }
    
    const Student* p = list;
    for (int i = 0; i < size; i++, p++) {
        cout << "Index [" << setw(2) << i + 1 << "] | ID: " << setw(4) << p->idData.numericID 
            << " | Name: " << setw(15) << p->name 
            << " | GPA: " << setw(4) << p->gpa
            << " | Status: " << getStatusString(p->status) << "\n";
    }
}

// Display function focused on Name, ID, and Course Grades
// Cleanly displays Student ID, Name, and then each Subject on a new line
void displayStudentGrades(const Student* list, const int size, const string subjects[][5]) {
    cout << "\n====================(STUDENT SUBJECT GRADES)====================\n";
    if (size == 0) {
        cout << "No students registered yet.\n";
        return;
    }

    const Student* ptr = list;
    for (int i = 0; i < size; i++, ptr++) {
        int track = ptr->trackIndex;
        
        // Header line: ID and Name
        cout << "ID: " << ptr->idData.numericID << " | Name: " << ptr->name << "\n";
        cout << "Subjects:\n";
        
        // Subject breakdown on new lines
        for (int g = 0; g < 5; g++) {
            cout << "   - " << setw(18) << std::left << subjects[track][g] 
                << ": " << ptr->grade[g] 
                << " (" << calculateGrade(ptr->grade[g]) << ")\n";
        }
        cout << "----------------------------------------------------------------\n";
    }
}

void searchStudent(const Student* list, const int size, const string std[][5]) {
    if (size == 0) {
        cout << "\nNo students available in the system.\n";
        return;
    }
    
    cout << "\n====================(SEARCH STUDENT)====================\n";
    cout << "1. Search by Student ID\n";
    cout << "2. Search by Name\n";
    cout << "Select search option (1 or 2): ";
    
    string opt;
    cin >> opt;
    
    if (opt == "1") {
        searchById(list, size, std);
    } else if (opt == "2") {
        searchByName(list, size);
    } else {
        cout << "Invalid selection!\n";
    }
}

void searchById(const Student* list, const int size, const string subject[][5]) {
    int searchID;
    cout << "\nEnter Student ID: ";
    cin >> searchID;
    
    bool isFound = false;
    const Student* ptr = list;

    for (int i = 0; i < size; ++i, ++ptr) {
        if (ptr->idData.numericID == searchID) {
            cout << "\n--------------------(Search Result)--------------------\n";
            cout << "ID       : " << ptr->idData.numericID << "\n";
            cout << "Name     : " << ptr->name << "\n";
            cout << "Grades   :\n";
            int course = ptr->trackIndex;
            for (int g = 0; g < 5; ++g) {
                cout << "  - " << setw(18) << std::left << subject[course][g] 
                    << ": " << ptr->grade[g] 
                    << " (" << calculateGrade(ptr->grade[g]) << ")\n";
            }
            cout << "GPA      : " << ptr->gpa << "\n";
            cout << "Status   : " << getStatusString(ptr->status) << "\n";
            cout << "---------------------------------------------------\n";
            isFound = true;
            break;
        }
    }
    
    if (!isFound) {
        cout << "No student found with ID: " << searchID << "\n";
    }
}

void searchByName(const Student* list, const int size) {
    string searchName;
    cout << "\nEnter exact name to search: ";
    getline(cin >> ws, searchName);
    
    bool isFound = false;
    const Student* ptr = list;

    for (int i = 0; i < size; ++i, ++ptr) {
        if (ptr->name == searchName) {
            cout << "ID: " << ptr->idData.numericID
                << " | Name: " << ptr->name
                << " | GPA: " << ptr->gpa
                << " | Status: " << getStatusString(ptr->status) << "\n";
            isFound = true;
        }
    }
    
    if (!isFound) {
        cout << "No student found with name: " << searchName << "\n";
    }
}

void deleteStudent(Student* list, int& size) {
    if (size == 0) {
        cout << "No students to delete.\n";
        return;
    }

    int targetID;
    cout << "Enter Student ID to delete: ";
    cin >> targetID;

    int foundIndex = -1;
    for (int i = 0; i < size; i++) {
        if ((list + i)->idData.numericID == targetID) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        cout << "Student ID not found.\n";
        return;
    }

    for (int i = foundIndex; i < size - 1; i++) {
        *(list + i) = *(list + i + 1);
    }

    size--;
    cout << "Student deleted successfully!\n";
}

// Interactively search for student to view or edit grades and calculate overall GPA
void computeGPA(Student* list, const int size, const string subjects[][5]) {
    if (size == 0) {
        cout << "\nNo students available in the system.\n";
        return;
    }

    int searchID;
    cout << "\n====================(STUDENT GRADES MANAGEMENT)====================\n";
    cout << "Enter Student ID to search: ";
    cin >> searchID;

    bool found = false;
    for (int i = 0; i < size; i++) {
        if ((list + i)->idData.numericID == searchID) {
            found = true;
            Student* current = (list + i);
            int track = current->trackIndex;

            cout << "\nStudent Found: " << current->name << " (ID: " << current->idData.numericID << ")\n";
            cout << "--------------------------------------------------------\n";
            cout << "1. Check / View Grades\n";
            cout << "2. Edit Grades\n";
            cout << "Select an option (1 or 2): ";

            int option;
            cin >> option;

            if (option == 1) {
                // Read-only view
                cout << "\n--- Current Grades for " << current->name << " ---\n";
                for (int g = 0; g < 5; g++) {
                    cout << "  " << setw(18) << std::left << subjects[track][g] 
                        << ": " << current->grade[g] 
                        << " (" << calculateGrade(current->grade[g]) << ")\n";
                }
                cout << "  " << setw(18) << std::left << "Calculated GPA" << ": " << current->gpa << "\n";
                cout << "  " << setw(18) << std::left << "Status" << ": " << getStatusString(current->status) << "\n";
                cout << "--------------------------------------------------------\n";
            } 
            else if (option == 2) {
                // Edit grades
                cout << "\nEnter New Grades:\n";
                for (int g = 0; g < 5; g++) {
                    cout << "  Enter grade for " << subjects[track][g] << ": ";
                    cin >> current->grade[g];
                }

                // Automatically update calculated GPA and Pass/Fail status
                calculateStudentGPA(current);

                cout << "\nGrades, GPA (" << current->gpa << "), and Status updated successfully for " 
                    << current->name << "!\n";
            } 
            else {
                cout << "Invalid option selected!\n";
            }

            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << searchID << " not found.\n";
    }
}