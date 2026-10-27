#include <iostream>
using std::cin;
using std::cout;
using std::endl;

enum Status
{
    PASS,
    FAIL,
    INCOMPLETE
};

union StudentInfo
{
    int id;
    char name[20];
};

struct Student
{
    StudentInfo studentInfo;
    int grades[10];
    float gpa;
    Status status;
};

void input(Student* s, int n, int numberOfGrades);
void average(Student* s, int n, int numberOfGrades);
void display(Student* s, int n, int numberOfGrades);
void search(Student* s, int n);

int main()
{
    int n;
    int numberOfGrades;

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter number of grades: ";
    cin >> numberOfGrades;

    Student* students = new Student[n];

    for (int i = 0; i < n; i++)
    {
        students[i].status = INCOMPLETE;
        students[i].gpa = 0.0f;
    }

    int choice;

    do
    {
        cout << endl;
        cout << "1. Input" << endl;
        cout << "2. Display" << endl;
        cout << "3. Average (Recalculate Manual)" << endl;
        cout << "4. Search" << endl;
        cout << "5. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            input(students, n, numberOfGrades);
            break;

        case 2:
            display(students, n, numberOfGrades);
            break;

        case 3:
        // no need to call avrage function becouse we set it to be automaticaly
            // average(students, n, numberOfGrades);
            cout << "Averages updated!" << endl;
            break;

        case 4:
            search(students, n);
            break;

        case 5:
            break;

        default:
            cout << "Invalid Choice" << endl;
        }

    } while (choice != 5);

    delete[] students;

    return 0;
}

// Updated input function to automatically trigger average calculation
void input(Student* s, int n, int numberOfGrades)
{
    Student* p = s;

    for (int i = 0; i < n; i++, p++)
    {
        cout << endl;
        cout << "Student ID: ";
        cin >> p->studentInfo.id;

        for (int j = 0; j < numberOfGrades; j++)
        {
            cout << "Grade " << j + 1 << ": ";
            cin >> p->grades[j];
        }
    }

    // Automatically update GPA and status right after input entry
    average(s, n, numberOfGrades);
}

void average(Student* s, int n, int numberOfGrades)
{
    if (numberOfGrades <= 0) return;

    Student* p = s;

    for (int i = 0; i < n; i++, p++)
    {
        int sum = 0;

        for (int j = 0; j < numberOfGrades; j++)
        {
            sum += p->grades[j];
        }

        p->gpa = (float)sum / numberOfGrades;

        if (p->gpa >= 60.0f)
            p->status = PASS;
        else
            p->status = FAIL;
    }
}

void display(Student* s, int n, int numberOfGrades)
{
    Student* p = s;

    for (int i = 0; i < n; i++, p++)
    {
        cout << endl;
        cout << "Student ID: " << p->studentInfo.id << endl;

        cout << "Grades: ";
        for (int j = 0; j < numberOfGrades; j++)
        {
            cout << p->grades[j] << " ";
        }

        cout << endl;
        cout << "GPA: " << p->gpa << endl;

        if (p->status == PASS)
            cout << "Status: PASS" << endl;
        else if (p->status == FAIL)
            cout << "Status: FAIL" << endl;
        else
            cout << "Status: INCOMPLETE" << endl;
    }
}

void search(Student* s, int n)
{
    int id;

    cout << "Enter Student ID: ";
    cin >> id;

    Student* p = s;

    for (int i = 0; i < n; i++, p++)
    {
        if (p->studentInfo.id == id)
        {
            cout << "Student Found" << endl;
            return;
        }
    }

    cout << "Student Not Found" << endl;
}