#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    int roll;
    string name;
    string course;
};

vector<Student> students;

void addStudent() {
    Student s;
    cout << "Enter Roll No: ";
    cin >> s.roll;
    cout << "Enter Name: ";
    cin >> s.name;
    cout << "Enter Course: ";
    cin >> s.course;

    students.push_back(s);
    cout << "Student Added Successfully!\n";
}

void viewStudents() {
    cout << "\nStudent List:\n";
    for (auto s : students) {
        cout << "Roll: " << s.roll
             << " | Name: " << s.name
             << " | Course: " << s.course << endl;
    }
}

void searchStudent() {
    int roll;
    cout << "Enter Roll No to search: ";
    cin >> roll;

    for (auto s : students) {
        if (s.roll == roll) {
            cout << "Found: " << s.name << " (" << s.course << ")\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

void deleteStudent() {
    int roll;
    cout << "Enter Roll No to delete: ";
    cin >> roll;

    for (auto it = students.begin(); it != students.end(); it++) {
        if (it->roll == roll) {
            students.erase(it);
            cout << "Student Deleted!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: exit(0);
            default: cout << "Invalid choice!\n";
        }
    }

    return 0;
}
