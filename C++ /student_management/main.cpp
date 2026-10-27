#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string;
using std::getline;
using std::ws;
using std::left;
using std::right;

#include <iomanip>
using std::setw;

// Pre-populated default list of 25 students
struct Student {
    int id;
    string name;
    int trackIndex;   // 0 = CS, 1 = Engineering, 2 = Science
    double grade[5];
    double gpa;
    string status;
};

static int nextStudentId = 726; // Unique auto-incrementing ID

// ------------------------------------------------------------------------------------- Function Prototypes------------------------------------------------
void start(string subject[][5], string trackSubjects[], int subjectSize);
void NewStudentFromUser(Student [], int& );
Student NewStudentInfo();
void displayStudents(const Student [], const int size, const string trackSubjects[], int subjectSize, const string subjects[][5]);
void displayStudentDetail(const Student student[], const int size, const string trackSubjects[], const string subjects[][5], int targetIndex);
void viewStudentByIndex(const Student student[], const int size, const string subject[][5], const string trackSubjects[]);
void searchById(const Student student[], const int size, const string subject[][5]);
void searchByName(const Student student[], const int size, const string subject[][5]);
void searchStudent(const Student studentList[], const int size, const string subject[][5]);
void edit(Student student[], string subject[][5], string trackSubjects[], int subjectSize, int size);
void updateStudentDetails(Student sstudent[], int size, string subject[][5], string trackSubjects[], int subjectSize, int searchId);
void editStudentMenu(Student student[], int size, string subject[][5], string trackSubjects[], int subjectSize, int searchId);

// ------------------------------------------------------------------------------Global State-----------------------------------------

// Pre-populated default list of 25 students with Track Index (0 = CS, 1 = Eng, 2 = Science)
Student studentList[100] = {
    {101, "Alice Johnson",   0, {88.0, 92.5, 79.0, 95.0, 85.0}, 3.5, "PASS"},
    {102, "Bob Smith",       1, {55.0, 60.0, 58.0, 62.0, 50.0}, 1.0, "FAIL"},
    {103, "Charlie Brown",   2, {95.0, 98.0, 91.0, 94.0, 96.0}, 4.0, "PASS"},
    {104, "Diana Prince",    0, {82.0, 85.0, 88.0, 80.0, 84.0}, 3.5, "PASS"},
    {105, "Ethan Hunt",      1, {70.0, 75.0, 72.0, 78.0, 74.0}, 3.0, "PASS"},
    {106, "Fiona Gallagher", 2, {45.0, 50.0, 52.0, 48.0, 40.0}, 1.0, "FAIL"},
    {107, "George Clark",    0, {89.0, 91.0, 87.0, 93.0, 90.0}, 4.0, "PASS"},
    {108, "Hannah Abbott",   1, {65.0, 68.0, 62.0, 70.0, 66.0}, 2.0, "PASS"},
    {109, "Ian Malcolm",     2, {78.0, 81.0, 80.0, 83.0, 79.0}, 3.0, "PASS"},
    {110, "Julia Roberts",   0, {92.0, 94.0, 96.0, 90.0, 95.0}, 4.0, "PASS"},
    {111, "Kevin Bacon",     1, {58.0, 55.0, 60.0, 52.0, 59.0}, 1.0, "FAIL"},
    {112, "Laura Croft",     2, {85.0, 88.0, 90.0, 87.0, 86.0}, 3.5, "PASS"},
    {113, "Michael Scott",   0, {62.0, 65.0, 60.0, 68.0, 64.0}, 2.0, "PASS"},
    {114, "Nina Williams",   1, {76.0, 79.0, 75.0, 82.0, 78.0}, 3.0, "PASS"},
    {115, "Oscar Martinez",  2, {91.0, 93.0, 89.0, 95.0, 92.0}, 4.0, "PASS"},
    {116, "Peter Parker",    0, {98.0, 96.0, 100.0, 94.0, 97.0}, 4.0, "PASS"},
    {117, "Quinn Fabray",    1, {73.0, 70.0, 75.0, 72.0, 74.0}, 3.0, "PASS"},
    {118, "Rachel Green",    2, {67.0, 69.0, 64.0, 71.0, 68.0}, 2.0, "PASS"},
    {119, "Sam Winchester",  0, {84.0, 87.0, 82.0, 89.0, 85.0}, 3.5, "PASS"},            
    {120, "Tina Fey",        1, {90.0, 92.0, 88.0, 91.0, 89.0}, 4.0, "PASS"},
    {121, "Ulysses Grant",   2, {50.0, 48.0, 55.0, 52.0, 45.0}, 1.0, "FAIL"},
    {122, "Victor Stone",    0, {81.0, 83.0, 85.0, 80.0, 82.0}, 3.5, "PASS"},
    {123, "Wanda Maximoff",  1, {93.0, 95.0, 91.0, 97.0, 94.0}, 4.0, "PASS"},
    {124, "Xavier Charles",  2, {99.0, 97.0, 98.0, 100.0, 96.0}, 4.0, "PASS"},
    {125, "Yara Greyjoy",    0, {77.0, 80.0, 75.0, 81.0, 76.0}, 3.0, "PASS"}
};

int studentCount = 25;

//====================================================================== < main > ----------------------------------------------------

int main() {
    // 2D Array: 3 Major Tracks x 5 Courses each
    string subjects[3][5] = {
        // Track 0: Computer Science
        {"Calculus", "Physics", "Programming", "Statistics", "English"},
        
        // Track 1: Engineering
        {"Calculus II", "Physics II", "Circuits", "Thermodynamics", "Linear Algebra"},
        
        // Track 2: General Science
        {"Biology", "Chemistry", "Algebra", "Psychology", "Technical Writing"}
    };
    int subjectSize = 3;
    string trackSubjects[3]; 

    trackSubjects[0] = "Computer Science";
    trackSubjects[1] = "Engineering";
    trackSubjects[2] = "General Science";

    cout << "\n=========================( STUDENT MANAGEMENT SYSTEM ) ==========================\n";
    start(subjects, trackSubjects, subjectSize);

    return 0;
}

// ----------------------------------------------------------------------start function --------------------------------------

void start(string subjects[][5], string trackSubjects[], int subjectSize) {
    string command;
    
    // Main navigation loop
    while (true) {
        cout << "\n";
        const char *Opration[] = {"🔵  Add Student", "🟢 Display Students", "🟡 Search Student", "🟠 Compute GPA", "⚪ Edit Student Info ", "🔴 Exit"};
        const int oprationSize = sizeof(Opration) / sizeof(Opration[0]);
        
        for (int i = 0; i < oprationSize; i++) {
            cout << i + 1 << ": " << Opration[i] << "\n";
        }
        cout << "--------------------------( use numbers to navigate )------------------------\n";
        cout << "🫟 ✳️ 🫟 ❭❭ ";

        cin >> command;

        if (command == "1") {
            NewStudentFromUser(studentList, studentCount);
        } else if (command == "2") {
            displayStudents(studentList, studentCount, trackSubjects, subjectSize, subjects);
        } else if (command == "3") {
            searchStudent(studentList, studentCount, subjects);
        } else if (command == "4") {
            cout << "GPA computation coming soon...\n";
        } else if (command == "5") {
            edit(studentList, subjects, trackSubjects, subjectSize, studentCount);
        } else if (command == "6") {
            cout << "Exiting program. Goodbye!\n";
            return; // ONLY exit here when selected by user!
        } else {
            cout << "------------------------------------------------------------\n";
            cout << "\t ⚠️ Invalid Entry Please Try Again ⚠️                 | \n  👉  Make Sure To use Provided Numbers Only!  👈          |\n";
            cout << "------------------------------------------------------------\n";
        }
    }
}

void NewStudentFromUser(Student list[], int& size) {
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        if (size >= 100) {
            cout << "⚠️ Record capacity full (Max 100 students).\n";
            break;
        }

        list[size] = NewStudentInfo();
        size++;

        cout << "✅ Student added successfully!!\n";
        
        while (true) {
            cout << "Do you want to add another student? (y/n): ";
            cin >> choice;

            if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N') {
                break;
            }
            cout << "------------------------------------------------------------\n";
            cout << "⚠️ Invalid Choice! Please enter 'y' for Yes or 'n' for No. ⚠️\n";
            cout << "------------------------------------------------------------\n";
        }
    }
}

Student NewStudentInfo() {
    Student s;
    s.id = nextStudentId++; 
    
    cout << "\n[Generated ID: " << s.id << "]\n";
    cout << "Enter Student Name ❭❭ ";
    getline(cin >> ws, s.name);
    
    string selectedCourse;
    while (true) {
        cout << "\n🫟 Select Major / Course :  \n";
        cout << " 1, Computer Science \n";
        cout << " 2, Engineering \n";
        cout << " 3, General Science \n";
        cout << "Choose Course Using number (1, 2, 3) : ";

        cin >> selectedCourse;
        if (selectedCourse == "1") { s.trackIndex = 0; break; }
        else if (selectedCourse == "2") { s.trackIndex = 1; break; }
        else if (selectedCourse == "3") { s.trackIndex = 2; break; }
        
        cout << "------------------------------------------------------------\n";
        cout << "⚠️ Invalid choice! Please enter 1, 2, or 3. ⚠️\n";
        cout << "------------------------------------------------------------\n";
    }

    for (int i = 0; i < 5; ++i) { s.grade[i] = 0.00; }
    s.gpa = 0.00;
    s.status = "Not Graded";
    
    return s;
}

void displayStudents(const Student student[], const int size, const string trackSubjects[], int subjectSize, const string subjects[][5]) {
    cout << "\n--------------------( Registered Students )--------------------\n";
    if (size == 0) {
        cout << "No students registered yet.\n";
        return;
    }
    for (int i = 0; i < size; i++) {
        int track = student[i].trackIndex;
        string major = (track >= 0 && track < subjectSize) ? trackSubjects[track] : "Unknown Major"; 

        cout << "Index [" << setw(2)  << i + 1 << "] | ID: " << setw(4) << student[i].id 
             << " | Name: " << left << setw(20) << student[i].name 
             << " | course: " << major << "\n";
    } 

    cout << "\nDo you want to view full details for a student? (Enter Index # or 0 to skip): ";
    int choice;
    cin >> choice;

    if (choice > 0 && choice <= size) {
        displayStudentDetail(student, size, trackSubjects, subjects, choice - 1);
    } else if (choice != 0) {
        cout << "-----------------------------------------------------------\n";
        cout << "⚠️ Index out of range (Valid options: 1 to " << size << ")\n";
        cout << "-----------------------------------------------------------\n";
    }
}

void viewStudentByIndex(const Student student[], const int size, const string subject[][5], const string trackSubject[]) {
    if (size == 0) return;
    cout << "\nDo you want to view full details for a student? (Enter Index # or 0 to skip): ";
    int choice;
    cin >> choice;
    
    if (choice > 0 && choice <= size) {
        displayStudentDetail(student, size, trackSubject, subject, choice - 1);
    } else if (choice != 0) {
        cout << "-----------------------------------------------------------\n";
        cout << "⚠️ Index out of range (Valid options: 1 to " << size << ")\n";
        cout << "-----------------------------------------------------------\n";
    }
}

void displayStudentDetail(const Student student[], const int size, const string trackSubjects[], const string subjects[][5], int targetIndex) {
    if (targetIndex < 0 || targetIndex >= size) {
        cout << "--------------------------------------------------------\n";
        cout << "              ❌ Invalid index number!\n";
        cout << "      ⚠️  No students available with this index.\n";
        cout << "--------------------------------------------------------\n";
        return;
    }

    const Student& s = student[targetIndex];
    string major = (s.trackIndex >= 0 && s.trackIndex < 3) ? trackSubjects[s.trackIndex] : "Unknown";

    cout << "\n====================( FULL STUDENT RECORD )====================\n";
    cout << "ID       : " << s.id << "\n";
    cout << "Name     : " << s.name << "\n";
    cout << "Major    : " << major << "\n";
    cout << "---------------------------------------------------------------\n";
    cout << "SUBJECT GRADES:\n";

    int track = s.trackIndex;
    for (int g = 0; g < 5; ++g) {
        cout << "  - " << subjects[track][g] << ": " << s.grade[g] << "\n";
    }

    cout << "---------------------------------------------------------------\n";
    cout << "GPA      : " << s.gpa << "\n";
    cout << "Status   : " << s.status << "\n";
    cout << "===============================================================\n";
}

void searchStudent(const Student studentList[], const int size, const string subjects[][5]) {
    if (size == 0) {
        cout << "--------------------------------------------------------\n";
        cout << "      ⚠️  No students available in the system.\n";
        cout << "--------------------------------------------------------\n";
        return;
    }

    cout << "\n====================( SEARCH STUDENT )====================\n";
    cout << "1. Search by Student ID\n";
    cout << "2. Search by Name\n";
    cout << "Select search option (1 or 2) ❭❭ ";

    string option;
    cin >> option;

    if (option == "1") {
        searchById(studentList, studentCount, subjects); 
    } else if (option == "2") {
        searchByName(studentList, studentCount, subjects); 
    } else {
        cout << "-------------------------------------------------------------\n";
        cout << " ⚠️ Invalid selection! Returning to main menu.\n";
        cout << "-------------------------------------------------------------\n";
    }
}

void searchById(const Student student[], const int size, const string subject[][5]) {
    if (size == 0) {
        cout << "--------------------------------------------------------\n";
        cout << "      ⚠️ No students available in the system.\n";
        cout << "--------------------------------------------------------\n";
        return;
    }

    int searchID;
    cout << "\nEnter Student ID: ";
    cin >> searchID;

    bool found = false;

    cout << "\n--------------------( Search Result )--------------------\n";
    for (int i = 0; i < size; ++i) {
        if (student[i].id == searchID) {
            cout << "Index    : " << i + 1 << "\n";
            cout << "ID       : " << student[i].id << "\n";
            cout << "Name     : " << student[i].name << "\n";
            cout << "Grades   :----------------------\n";

            int course = student[i].trackIndex;
            
            for (int g = 0; g < 5; ++g) {
                cout << "\t   " << left << setw(18) << subject[course][g] << student[i].grade[g] << "\n";
            }
            cout << "\nGPA      : " << setw(3) << student[i].gpa << "\n";
            cout << "Status   : " << student[i].status << "\n";
            cout << "--------------------------------------------------------\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "--------------------------------------------------------\n";
        cout << "  ❌ No student found with ID: " << searchID << "\n";
        cout << "--------------------------------------------------------\n";
    }
}

void searchByName(const Student student[], const int size, const string subject[][5]) {
    if (size == 0) {
        cout << "--------------------------------------------------------\n";
        cout << "\n  ⚠️ No students available in the system.\n";
        cout << "--------------------------------------------------------\n";
        return;
    }

    string searchName;
    cout << "\nEnter exact name to search: ";
    getline(cin >> ws, searchName);

    bool found = false;

    cout << "\n--------------------( Search Results )--------------------\n";
    for (int i = 0; i < size; ++i) {
        if (student[i].name == searchName) {
            cout << "Index    : " << i + 1 << "\n";
            cout << "ID       : " << student[i].id << "\n";
            cout << "Name     : " << student[i].name << "\n";
            cout << "Grades   :----------------------\n";

            int course = student[i].trackIndex;
            
            for (int g = 0; g < 5; ++g) {
                cout << "\t   " << left << setw(18) << subject[course][g] << student[i].grade[g] << "\n";
            }
            cout << "\nGPA      : " << setw(3) << student[i].gpa << "\n";
            cout << "Status   : " << student[i].status << "\n";
            cout << "--------------------------------------------------------\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "--------------------------------------------------------\n";
        cout << " ❌ No student found with name: " << searchName << "\n";
        cout << "--------------------------------------------------------\n";
    }
}

//---------------------------------------------------------------------- edit section ----------------------------------
void edit(Student student[], string subject[][5], string trackSubjects[], int subjectSize, int size) {
    int searchID;
    cout << "\nEnter Student ID: ";
    cin >> searchID;

    bool found = false;

    for (int i = 0; i < size; ++i) {
        if (student[i].id == searchID) {
            cout << "\n--------------------( Search Result )--------------------\n";
            cout << "Index    : " << i + 1 << "\n";
            cout << "ID       : " << student[i].id << "\n";
            cout << "Name     : " << student[i].name << "\n";
            cout << "Grades   :----------------------\n";

            int course = student[i].trackIndex;
            
            for (int g = 0; g < 5; ++g) {
                cout << "\t   " << left << setw(18) << subject[course][g] << student[i].grade[g] << "\n";
            }
            cout << "\nGPA      : " << setw(3) << student[i].gpa << "\n";
            cout << "Status   : " << student[i].status << "\n";
            cout << "--------------------------------------------------------\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "--------------------------------------------------------\n";
        cout << "    ❌ No student found with ID: " << searchID << "\n";
        cout << "--------------------------------------------------------\n";
        return; // Safely return to main menu
    }

    cout << "\nOptions: [1] Update Student Grade or Course \n \t [2] Change Student ID or Name  [-1] Skip: ";
    string opt;
    cin >> opt;
    
    if (opt == "1") {
        updateStudentDetails(student, size, subject, trackSubjects, subjectSize, searchID);
    } else if (opt == "2") {
        editStudentMenu(student, size, subject, trackSubjects, subjectSize, searchID);
    }
}

void updateStudentDetails(Student student[], int size, string subject[][5], string trackSubjects[], int subjectSize, int targetStudent) {
    for (int i = 0; i < size; i++) {
        if (student[i].id == targetStudent) {
            cout << "\nWhat would you like to edit for " << student[i].name << " ?\n";
            break;
        }
    }
    
    cout << "1. Change course \n";
    cout << "2. Edit Grades \n";
    cout << "3. Edit Both \n";
    cout << "Enter choice: ";
    string editChoice;
    cin >> editChoice;

    // 1. Edit course / Major
    if (editChoice == "1" || editChoice == "3") {
        cout << "\nAvailable courses:\n";
        for (int i = 0; i < subjectSize; ++i) {
            cout << "  [" << i << "] " << trackSubjects[i] << "\n";
        }
        cout << "Select new Course: ";
        int newTrack;
        cin >> newTrack;
        if (newTrack >= 0 && newTrack < subjectSize) {
            for (int i = 0; i < size; i++) {
                if (student[i].id == targetStudent) {
                    student[i].trackIndex = newTrack;
                }
            }
            cout << "✅ Track updated to: " << trackSubjects[newTrack] << "\n";
        } else {
            cout << "--------------------------------------------------------\n";
            cout << "    ⚠️ Invalid track index. Keeping existing track.\n";
            cout << "--------------------------------------------------------\n";
        }
    }

    // 2. Edit Subject Grades
    if (editChoice == "2" || editChoice == "3") {
        int targetIdx = -1;
        for (int i = 0; i < size; i++) {
            if (student[i].id == targetStudent) {
                targetIdx = i;
                break;
            }
        }

        if (targetIdx != -1) {
            int track = student[targetIdx].trackIndex;
            double sum = 0.0;
            for (int g = 0; g < 5; g++) {
                cout << "Enter grade for " << subject[track][g] 
                << " (currently " << student[targetIdx].grade[g] << "): ";
                cin >> student[targetIdx].grade[g];
                sum += student[targetIdx].grade[g];
            }
            
            // Recalculate GPA & Status
            double average = sum / 5.0;
            student[targetIdx].gpa = (average / 100.0) * 4.0;
            student[targetIdx].status = (student[targetIdx].gpa >= 2.0) ? "PASS" : "FAIL";
            cout << "✅ Grades and GPA updated successfully!\n";
        }
    }
}

void editStudentMenu(Student student[], int size, string subject[][5], string trackSubjects[], int subjectSize, int targetStudent) {
    if (size == 0) {
        cout << "\nNo students available to edit.\n";
        return;
    }

    cout << "\n====================( EDIT STUDENT INFO )====================\n";
    cout << "What do you want to edit :\n";
    cout << "1. Student ID\n";
    cout << "2. Student Name\n";
    cout << "Enter choice: ";
    string searchChoice;
    cin >> searchChoice;

    if (searchChoice == "1") {
        cout << "Enter New Student ID: ";
        int newId;
        cin >> newId;
        for (int i = 0; i < size; ++i) {
            if (student[i].id == targetStudent) {
                student[i].id = newId;
                break;
            }
        }
        cout << "✅ ID updated successfully!\n";
    } else if (searchChoice == "2") {
        cout << "Enter Student Name: ";
        string newName;
        getline(cin >> ws, newName);
        for (int i = 0; i < size; ++i) {
            if (student[i].id == targetStudent) {
                student[i].name = newName;
                break;
            }
        }
        cout << "✅ Name updated successfully!\n";
    } else {
        cout << "--------------------------------------------------------\n";
        cout << "                 ❌ Invalid choice!\n";
        cout << "--------------------------------------------------------\n";
    }
}