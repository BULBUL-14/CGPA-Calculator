#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Subject {
    string name;
    int marks;
    int credits;
};

struct Student {
    string roll_no;
    string name;
    string department;
    string year;
    vector<Subject> subjects; // Subject details: name, marks, and credits
};

// Function to display the college name in a header format
void display_college_name() 
{
    const int length = 50; // Length of the line
    for (int i = 0; i < length; ++i) {
        cout << "-";
    }
    cout << endl; // Move to the next line
    cout << "      Rajiv Gandhi Prodhyogiki Vishwavidyalay" << endl;
   cout << "          Bhopal, Madhya Pradesh" << endl;
   
     {
    const int length = 50; // Length of the line
    for (int i = 0; i < length; ++i) {
        cout << "-";
    }
    cout << endl; // Move to the next line
}
}

// Function to calculate SGPA
float calculate_sgpa(const vector<Subject>& subjects) {
    if (subjects.empty()) return 0;
    float total_points = 0, total_credits = 0;

    for (const auto& subject : subjects) {
        float grade_point = subject.marks / 10.0; // Assuming marks are out of 100, convert to grade points
        total_points += grade_point * subject.credits;
        total_credits += subject.credits;
    }
    return total_credits > 0 ? total_points / total_credits : 0;
}

// Function to calculate CGPA
float calculate_cgpa(const vector<Student>& students, const string& roll_no) {
    float total_sgpa = 0;
    int semesters = 0;

    for (const auto& student : students) {
        if (student.roll_no == roll_no) {
            total_sgpa += calculate_sgpa(student.subjects);
            semesters++;
        }
    }
    return semesters > 0 ? total_sgpa / semesters : 0;
}

// Function to add a student
void add_student(vector<Student>& students) {
    Student student;
    cout << "Enter Roll Number: ";
    cin >> student.roll_no;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, student.name);

    cout << "Enter Department: ";
    getline(cin, student.department);

    cout << "Enter Year: ";
    getline(cin, student.year);

    int num_subjects;
    cout << "Enter number of subjects: ";
    cin >> num_subjects;
    cin.ignore();

    student.subjects.resize(num_subjects);
    for (int i = 0; i < num_subjects; ++i) {
        cout << "Enter Subject " << i + 1 << " Name: ";
        getline(cin, student.subjects[i].name);
        cout << "Enter Marks for " << student.subjects[i].name << ": ";
        cin >> student.subjects[i].marks;
        cout << "Enter Credits for " << student.subjects[i].name << ": ";
        cin >> student.subjects[i].credits;
        cin.ignore();
    }

    students.push_back(student);
    cout << "Student added successfully!" << endl;
}

// Function to find SGPA by Roll Number
void find_sgpa(const vector<Student>& students) {
    string roll_no;
    cout << "Enter Roll Number: ";
    cin >> roll_no;

    for (const auto& student : students) {
        if (student.roll_no == roll_no) {
            cout << "\nStudent Found!" << endl;
            cout << "Name: " << student.name << endl;
            cout << "Department: " << student.department << endl;
            cout << "Year: " << student.year << endl;
            cout << "SGPA: " << fixed << setprecision(2) << calculate_sgpa(student.subjects) << endl;
            return;
        }
    }
    cout << "No student found with Roll Number: " << roll_no << endl;
}

// Function to find CGPA by Roll Number
void find_cgpa(const vector<Student>& students) {
    string roll_no;
    cout << "Enter Roll Number: ";
    cin >> roll_no;

    float cgpa = calculate_cgpa(students, roll_no);
    if (cgpa > 0) {
        cout << "CGPA for Roll Number " << roll_no << ": " << fixed << setprecision(2) << cgpa << endl;
    } else {
        cout << "No data available for Roll Number: " << roll_no << endl;
    }
}

// Function to find the topper of a department
void find_topper_of_department(const vector<Student>& students) {
    string department;
    cout << "Enter Department: ";
    cin >> department;

    const Student* topper = nullptr;
    float highest_sgpa = 0;

    for (const auto& student : students) {
        if (student.department == department) {
            float sgpa = calculate_sgpa(student.subjects);
            if (sgpa > highest_sgpa) {
                highest_sgpa = sgpa;
                topper = &student;
            }
        }
    }

    if (topper) {
        cout << "\nTopper of " << department << " Department:" << endl;
        cout << "Name: " << topper->name << endl;
        cout << "Roll Number: " << topper->roll_no << endl;
        cout << "Year: " << topper->year << endl;
        cout << "SGPA: " << fixed << setprecision(2) << highest_sgpa << endl;
    } else {
        cout << "No topper found in the " << department << " department." << endl;
    }
}

void print_marksheet(const vector<Student>& students) {
    string roll_no;
    cout << "Enter Roll Number: ";
    cin >> roll_no;

    for (const auto& student : students) {
        if (student.roll_no == roll_no) {
            cout << "\nMark Sheet for Roll Number: " << roll_no << endl;
            cout << "Name: " << student.name << endl;
            cout << "Department: " << student.department << endl;
            cout << "Year: " << student.year << endl;
            {
    const int length = 68; // Length of the line
    for (int i = 0; i < length; ++i) {
        cout << "*";
    }
    cout << endl; // Move to the next line

}
            // Table Header
            cout << left << setw(15) << "Subject"
                 << setw(10) << "Marks"
                 << setw(10) << "Credits"
                 << setw(10) << "Grade"
                 << setw(10) << "Result" // Add "Result" column
                 << setw(15) << "Grade Points" << endl;
                 {
                     const int length = 68; // Length of the line
                     for (int i = 0; i < length; ++i) {
                         cout << "*";
                     }
                     cout << endl; // Move to the next line
                    
                 }
            bool overall_pass = true; // Track if the student passed overall

            for (const auto& subject : student.subjects) {
                // Calculate Grade
                string grade;
                if (subject.marks >= 85)
                    grade = "A";
                else if (subject.marks >= 70)
                    grade = "B";
                else if (subject.marks >= 50)
                    grade = "C";
                else if (subject.marks >= 40)
                    grade = "D";
                else
                    grade = "F";

                // Calculate Grade Points
                float grade_points = subject.marks / 10.0;

                // Determine Pass/Fail
                string result = (subject.marks >= 40) ? "Pass" : "Fail";
                if (result == "Fail") overall_pass = false; // Update overall status

                // Display each subject with new columns
                cout << left << setw(15) << subject.name
                     << setw(10) << subject.marks
                     << setw(10) << subject.credits
                     << setw(10) << grade
                     << setw(10) << result // Show pass/fail result
                     << setw(15) << fixed << setprecision(2) << grade_points << endl;
            }

            // Display SGPA
            cout << "\nSGPA: " << fixed << setprecision(2) << calculate_sgpa(student.subjects) << endl;

            // Display Overall Result
            cout << "Overall Result: " << (overall_pass ? "Pass" : "Fail") << endl;
            return;
        }
    }
    cout << "No student found with Roll Number: " << roll_no << endl;
}


// Function to find the topper of the college (across all departments)
void find_topper_of_college(const vector<Student>& students) {
    const Student* topper = nullptr;
    float highest_sgpa = 0;

    for (const auto& student : students) {
        float sgpa = calculate_sgpa(student.subjects);
        if (sgpa > highest_sgpa) {
            highest_sgpa = sgpa;
            topper = &student;
        }
    }

    if (topper) {
        cout << "\nTopper of Rajiv Gandhi Prodhyogiki Vishwavidyalay, Bhopal, Madhya Pradesh:" << endl;
        cout << "Name: " << topper->name << endl;
        cout << "Roll Number: " << topper->roll_no << endl;
        cout << "Department: " << topper->department << endl;
        cout << "Year: " << topper->year << endl;
        cout << "SGPA: " << fixed << setprecision(2) << highest_sgpa << endl;
    } else {
        cout << "No data available for topper." << endl;
    }
}

// Main function
int main() {
    vector<Student> students = {
        {"0112IT231012", "bharti mandrai", "IT", "2nd Year", {{"Maths", 85, 3}, {"Physics", 88, 4}, {"Chemistry" , 80, 3}, {"BEEE", 89, 3}, {"Programming", 90, 4}}},
        {"0112IT231014", "Bulbul Ahirwar", "IT", "2nd Year", {{"Maths", 82, 3}, {"Physics", 80, 4}, {"Chemistry" , 90, 3}, {"BEEE", 69, 3}, {"Programming", 89, 4}}},
        {"0112CS231001", "Aarav Sharma", "Computer Science", "2nd Year", {{"Maths", 90, 3}, {"Chemistry" , 80, 3}, {"BEEE", 89, 3}, {"Physics", 85, 4}, {"Programming", 92, 4}}},
        {"0112EE231002", "Sunita Mishra", "Electrical", "1st Year", {{"Circuits", 88, 3},  {"Chemistry" , 82, 3}, {"BEEE", 81, 3}, {"Machines", 92, 4}, {"Maths", 87, 3}}},
        {"0112EC231003", "Ishita Verma", "Electronics", "3rd Year", {{"Circuits", 78, 4},  {"Chemistry" , 70, 3}, {"BEEE", 79, 3}, {"Maths", 88, 3}, {"Signals", 84, 3}}},
        {"0112ME231005", "Rohan Gupta", "Mechanical", "1st Year", {{"Thermodynamics", 76, 3},  {"Chemistry" , 80, 3}, {"BEEE", 89, 3}, {"Mechanics", 81, 4}, {"Physics", 85, 3}}}
    };

    int choice;
    do {
        display_college_name();
        cout << "\nMenu: \n";
        cout << "1. Add Student\n";
        cout << "2. Find SGPA by Roll Number\n";
        cout << "3. Find CGPA by Roll Number\n";
        cout << "4. Find Topper of Department\n";
        cout << "5. Print Marksheet by Roll Number\n";
        cout << "6. Find Topper of College\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: add_student(students); break;
            case 2: find_sgpa(students); break;
            case 3: find_cgpa(students); break;
            case 4: find_topper_of_department(students); break;
            case 5: print_marksheet(students); break;
            case 6: find_topper_of_college(students); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
} 
