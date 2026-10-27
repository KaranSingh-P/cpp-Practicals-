#include <iostream>
#include <string>
using namespace std;

int main(){
    cout << "Student name: Karan Singh\nURN: E25B000312\n\n";
    string name;
    int mark_1, mark_2, mark_3, total;
    const int passing_marks = 40;
    bool valid_marks = true;

    cout << "Enter Student name: ";
    cin >> name;

    cout << "\nEnter the marks of subject 1: ";
    cin >> mark_1;
    if (mark_1 > 100 || mark_1 < 0){
        cout << "\nInvalid marks.";
        valid_marks = false;
    }
    cout << "Enter the marks of subject 2: ";
    cin >> mark_2;
    if (mark_2 > 100 || mark_2 < 0){
        cout << "\nInvalid marks.";
        valid_marks = false;
    }
    cout << "Enter the marks of subject 3: ";
    cin >> mark_3;
    if (mark_3 > 100 || mark_3 < 0){
        cout << "\nInvalid marks.";
        valid_marks = false;
    }

    if (valid_marks){
        total = mark_1 + mark_2 + mark_3;
        cout << "\nStudent name: " << name;
        cout << "\nTotal marks: " << total;
        cout << "\nAverage: " << (total / 3.0);
        if (mark_1 > passing_marks && mark_2 > passing_marks && mark_3 > passing_marks){
            cout << "\nResult: Pass";
            if (total > 250){
                cout << "\nRemark: Great Work!";
            }else if (total < 150 && total > 120){
                cout << "\nRemark: You need to study more.";
            }else{
                cout << "\nRemark: Keep it up.";
            }
        }else{
            cout << "\nResult: Fail";
            cout << "\nRemark: Prepare for retest.";
        }
    }
    return 0;
}