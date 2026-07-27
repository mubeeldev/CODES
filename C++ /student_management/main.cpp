#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string;
using std::getline;
using std::ws;

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
void start(const string subject[][5]);
void NewStudentFromUser(Student [], int& ); // Pass by reference using &
Student NewStudentInfo();
void displayStudents( const Student [], const int size );
void searchById( const Student list[], const int size, const string subject[][5]);
void searchByName( const Student list[], const int size);
void searchStudent( const Student list[], const int size, const string subject[][5]);

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

//------------------------------------------------------------ < main > ----------------------------------------------------

int main() {
    // 2D Array: 3 Major Tracks x 5 Courses each
    const string subjects[3][5] = {
        // Track 0: Computer Science
        {"Calculus", "Physics", "Programming", "Statistics", "English"},
        
        // Track 1: Engineering
        {"Calculus II", "Physics II", "Circuits", "Thermodynamics", "Linear Algebra"},
        
        // Track 2: General Science
        {"Biology", "Chemistry", "Algebra", "Psychology", "Technical Writing"}
    };

    cout << "\n=========================( STUDENT MANAGEMENT SYSTEM ) ==========================\n";
    
    // Pass the 2D array to start()
    start(subjects);
    
    return 0;
}

// ----------------------------------------------------------------------start function --------------------------------------

void start(const string subjects[][5]) {
    int command;
    
    // Command navigation loop
    while (true) {
        cout << "\n";
        const char *Opration[] = {"🔵  Add Student", "🟢 Display Students", "🟡 Search Student", "🟠 Compute GPA", "🔴 Exit"};
        const int oprationSize = sizeof(Opration) / sizeof(Opration[0]);
        
        for (int i = 0; i < oprationSize; i++) {
            cout << i + 1 << ": " << Opration[i] << "\n";
        }
        cout << "--------------------------( use numbers to navigate )------------------------\n";
        cout << "\n----command---->:  ";
        if (!(cin >> command)) break; // Exit loop if invalid input stream

        switch (command) {
            case 1:
                NewStudentFromUser(studentList, studentCount);
                break;
            case 2:
                displayStudents(studentList, studentCount);
                break;
            case 3:
                searchStudent( studentList,studentCount , subjects );
                break;
            case 4:
                cout << "GPA computation coming soon...\n";
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                return; // Exits start() and finishes main() cleanly
            
            default:
                cout << "------------------------------------------------------------\n";
                cout << "\t ⚠️ Invalid Entry Please Try Again ⚠️                 | \n  👉  Make Sure To use Provided Numbers Only!  👈          |\n";
                cout << "------------------------------------------------------------\n";
                break;
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

        // Get info and assign unique ID
        list[size] = NewStudentInfo();
        size++; // Increments studentCount directly

        cout << "✅ Student added successfully!!\n";
        // Input validation loop for (y/n)
        while (true) {
            cout << "Do you want to add another student? (y/n): ";
            cin >> choice;

            if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N') {
                break; // Valid input received, exit validation loop
            }
            // Display error for invalid choices
            cout << "------------------------------------------------------------\n";
            cout << "⚠️ Invalid Choice! Please enter 'y' for Yes or 'n' for No. ⚠️\n";
            cout << "------------------------------------------------------------\n";
        }
    }
}

Student NewStudentInfo() {   // ---------------------------------- new student information structure ---------------------
    Student s;
    s.id = nextStudentId++; // Generates a unique sequential ID automatically
    
    cout << "\n[Generated ID: " << s.id << "]\n";
    cout << "Enter Student Name: ";
    getline(cin >> ws, s.name); // Handles names with spaces and consumes leftover newlines
    
    return s;
}

void displayStudents(const Student std[], const int size) {   // -------------------------------------------------student display -------------
    cout << "\n--------------------( Registered Students )--------------------\n";
    if (size == 0) {
        cout << "No students registered yet.\n";
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << "Index [" << setw(2)  << i + 1 << "] | ID: " << setw(4) << std[i].id << " | Name: " << std[i].name << "\n";
    }
}

void searchStudent(const Student list[], const int size, const string std[][5]) {  // -----------------------------------------student search--------------------
    if (size == 0) {
        cout << "--------------------------------------------------------\n";
        cout << "      ⚠️  No students available in the system.\n";
        cout << "--------------------------------------------------------\n";

        return;
    }

    cout << "\n====================( SEARCH STUDENT )====================\n";
    cout << "1. Search by Student ID\n";
    cout << "2. Search by Name\n";
    cout << "Select search option (1 or 2): ";

    string option;
    cin >> option;

    if (option == "1") {
        searchById( studentList, studentCount , std); // search by id function call 
    } 
    else if (option == "2") {
        searchByName( studentList, studentCount ); // search by name function call  
    } 
    else {
        cout << "-------------------------------------------------------------\n";
        cout << " ⚠️ Invalid selection! Please refer to the Instructions page.\n";
        cout << "-------------------------------------------------------------\n";

    }
}

void searchById( const Student list[], const int size, const string subject[][5]) { //-------------------------------------- serch by id -----------------------------
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
        if (list[i].id == searchID) {
            cout << "ID       : " << list[i].id << "\n";
            cout << "Name     : " << list[i].name << "\n";
            cout << "Grades   : ";

            int course = list[i].trackIndex;
            
            for (int g = 0; g < 5; ++g) {
                cout << setw(18) << subject[course][g] << list[i].grade[g] << " ";
            }
            cout << "\nGPA      : " << setw(3) << list[i].gpa << "\n";
            cout << "Status   : " << list[i].status << "\n";
            cout << "--------------------------------------------------------\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "--------------------------------------------------------\n";
        cout << " ❌ No student found with ID: " << searchID << "\n";
        cout << "--------------------------------------------------------\n";
        
    }
}
void searchByName( const Student list[], const int size) {  // ------------------------------search by name ---------------------
    if (size == 0) {
        cout << "--------------------------------------------------------\n";
        cout << "\n ⚠️ No students available in the system.\n";
        cout << "--------------------------------------------------------\n";

        return;
    }

    string searchName;
    cout << "\nEnter exact name to search: ";
    getline(cin >> ws, searchName);

    bool found = false;

    cout << "\n--------------------( Search Results )--------------------\n";
    for (int i = 0; i < size; ++i) {
        // Simple direct string comparison using ==
        if (list[i].name == searchName) {
            cout << "ID: " << list[i].id 
                << " | Name: " << list[i].name 
                << " | GPA: " << list[i].gpa 
                << " | Status: " << list[i].status << "\n";
            found = true;
        }
    }
    cout << "--------------------------------------------------------\n";

    if (!found) {
        cout << "--------------------------------------------------------\n";
        cout << " ❌ No student found with name: " << searchName << "\n";
        cout << "--------------------------------------------------------\n";

    }
}