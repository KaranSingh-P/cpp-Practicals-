#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int Id;
    string name;
    float marks;
};

int main() {
    cout << "Student name: Karan Singh\nURN: E25B000312\n\n";
    Student students[] = {
        { 1, "Apple", 80.0 },
        { 2, "Banana", 66.7 },
        { 3, "Cherry", 93.2 }
    };

    // Writing records to CSV file
    ofstream file("students.csv");
    if (!file) {
        cout << "Unable to open file!";
        return 1;
    }
    file << "Id,Name,Marks" << "\n";
    for (int i = 0; i < 3; i++) {
        file << students[i].Id << "," << students[i].name << "," << students[i].marks << "\n";
    }
    if (!file) {
        cout << "Error writing to file!";
        return 1;
    }
    file.close();
    cout << "Student records saved successfully!" << "\n";

    // Reading records from CSV file
    ifstream in("students.csv");
    if (!in) {
        cout << "Unable to open file!";
        return 1;
    }
    string line;
    // Skip the heading
    getline(in, line);
    cout << "\nStudent Records:" << "\n";
    cout << "Id\tName\tMarks" << "\n";
    while (getline(in, line)) {
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ',') {
                line[i] = '\t';
            }
        }
        cout << line << "\n";
    }
    in.close();

    // Demonstration of tellg() and seekg()
    ifstream readFile("students.csv");
    cout << "\nRead Position Demonstration:" << "\n";
    cout << "Initial position: " << readFile.tellg() << "\n";
    readFile.seekg(5);
    cout << "Position after seekg(5): " << readFile.tellg() << "\n";
    char ch;
    readFile.get(ch);
    cout << "Character at position 5: " << ch << "\n";
    readFile.close();


    // Demonstration of tellp() and seekp()
    ofstream writeFile("demo.txt");
    if (!writeFile) {
        cout << "Unable to open demo file!";
        return 1;
    }
    writeFile << "ABCDE";
    cout << "\nWrite Position Demonstration:\n";
    cout << "Position after writing ABCDE: " << writeFile.tellp() << "\n";
    writeFile.seekp(1);
    cout << "Position after seekp(1): " << writeFile.tellp() << "\n";
    writeFile << "X";
    writeFile.close();
    cout << "Updated content of demo.txt: AXCDE\n";

    return 0;
}