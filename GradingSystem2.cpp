#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
    string name;
    vector<vector<int>> termMarks; // 2D vector to hold marks for three terms
    vector<double> termAverages;
    vector<string> termGrades;
    double overallAverage;
    string overallGrade;

    void calculateTermAverages() {
        termAverages.clear();
        for (const auto& marks : termMarks) {
            int totalMarks = 0;
            for (int mark : marks) {
                totalMarks += mark;
            }
            double average = static_cast<double>(totalMarks) / marks.size();
            termAverages.push_back(average);
        }
    }

    void assignTermGrades() {
        termGrades.clear();
        for (double average : termAverages) {
            string grade;
            if (average >= 80 && average <= 100) {
                grade = "A";
            }
            else if (average >= 70 && average < 80) {
                grade = "A-";
            }
            else if (average >= 60 && average < 70) {
                grade = "B+";
            }
            else if (average >= 50 && average < 60) {
                grade = "B-";
            }
            else if (average >= 40 && average < 50) {
                grade = "C+";
            }
            else if (average >= 30 && average < 40) {
                grade = "C";
            }
            else {
                grade = "F";
            }
            termGrades.push_back(grade);
        }
    }

    void calculateOverallAverage() {
        double totalAverage = 0;
        for (double average : termAverages) {
            totalAverage += average;
        }
        overallAverage = totalAverage / termAverages.size();
    }

    void assignOverallGrade() {
        if (overallAverage >= 80 && overallAverage <= 100) {
            overallGrade = "A";
        }
        else if (overallAverage >= 70 && overallAverage < 80) {
            overallGrade = "A-";
        }
        else if (overallAverage >= 60 && overallAverage < 70) {
            overallGrade = "B+";
        }
        else if (overallAverage >= 50 && overallAverage < 60) {
            overallGrade = "B-";
        }
        else if (overallAverage >= 40 && overallAverage < 50) {
            overallGrade = "C+";
        }
        else if (overallAverage >= 30 && overallAverage < 40) {
            overallGrade = "C";
        }
        else {
            overallGrade = "F";
        }
    }

public:
    void inputDetails() {
        cout << "Enter the Name of the Student: ";
        cin.ignore();
        getline(cin, name);

        int numSubjects = 7;
        int numTerms = 3;
        for (int term = 1; term <= numTerms; ++term) {
            cout << "Entering marks for Term " << term << ":" << endl;
            vector<int> marks;
            for (int i = 1; i <= numSubjects; ++i) {
                int mark;
                cout << "Enter the marks for subject " << i << ": ";
                cin >> mark;
                marks.push_back(mark);
            }
            termMarks.push_back(marks);
        }

        calculateTermAverages();
        assignTermGrades();
        calculateOverallAverage();
        assignOverallGrade();
    }

    void displayResults() const {
        cout << "Results for: " << name << endl;
        for (size_t term = 0; term < termAverages.size(); ++term) {
            cout << "  Term " << term + 1 << ": Average = " << termAverages[term]
                << ", Grade = " << termGrades[term] << endl;
        }
        cout << "Overall Average: " << overallAverage << ", Overall Grade: " << overallGrade << endl;
    }
};

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    vector<Student> students;
    for (int i = 0; i < numStudents; ++i) {
        cout << "\nEntering details for Student " << i + 1 << ":" << endl;
        Student student;
        student.inputDetails();
        students.push_back(student);
    }

    cout << "\nDisplaying all student results:\n";
    for (const auto& student : students) {
        student.displayResults();
        cout << endl;
    }

    return 0;
}
