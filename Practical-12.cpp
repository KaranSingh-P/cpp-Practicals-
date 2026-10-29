#include <iostream>
#include <exception>
#include <string>
#include <map>
#include <vector>
#include <fstream>
using namespace std;

class InvalidInput : public exception {
public:
    const char* what() const noexcept override {
        return "Entry Invalid. Function aborted.\n";
    }
};

struct Book {
    string title;
    string author;
    int availability;
};

class Library {
    map<int, Book> BookRecord;

    string getBook(int id) {
        return "Book Id: " + to_string(id) + "\nBook Title: " + BookRecord[id].title + "\nBook Author: " + BookRecord[id].author + "\nBook Availability: " + to_string(BookRecord[id].availability);
    }

    bool confirmOverwrite() {
        char check;
        while (true) {
            cout << "Book already exists. Overwrite? [Y/N]: ";
            try {
                if (!(cin >> check)) {
                    throw InvalidInput();
                }
            }
            catch (const InvalidInput& e) {
                cout << e.what();
                cin.clear();
                cin.ignore(100, '\n');
                break;
            }
            if (check == 'Y' || check == 'y')
                return true;
            if (check == 'N' || check == 'n')
                return false;
            cout << "Invalid entry. ";
        }
        return false;
    }
public:
    Library() {
        fstream file("Library.csv", ios::in | ios::out);

        if (!file.is_open()) {
            cout << "Unable to open the Library file.\n";
            exit(-1);
        }

        string line;

        while (getline(file, line)) {
            size_t start = 0, pos;
            vector<int> elements;
            while ((pos = line.find(",", start)) != string::npos) {
                elements.push_back(pos);
                start = pos + 1;
            }
            if (elements.size() != 3) {
                continue;
            }
            BookRecord[stoi(line.substr(0, elements[0]))] =
            { line.substr(elements[0] + 1,(elements[1] - elements[0] - 1)),
             line.substr(elements[1] + 1,(elements[2] - elements[1] - 1)),
             stoi(line.substr(elements[2] + 1)) };
        }

        file.close();
    }

    void Add(int id, string title, string author, int availability) {
        if (id < 0 || availability < 0 || availability > 999) {
            cout << "Invalid ID/Availability Entry.\n";
            return;
        }

        if (BookRecord.find(id) == BookRecord.end()) {
            BookRecord[id] = { title, author, availability };
            cout << "Book successfully added.\n" << getBook(id) << "\n";
            return;
        }

        if (confirmOverwrite()) {
            BookRecord[id] = { title, author, availability };
            cout << "Book successfully added.\n" << getBook(id) << "\n";
            return;
        }
        return;
    }

    void Add(int id, string title, string author) {
        Add(id, title, author, 0);
        return;
    }

    void ChangeBookAmount(int id, int availability) {
        if (id < 0 || availability < 0 || availability > 999) {
            cout << "Invalid ID/Availability Entry.\n";
            return;
        }
        if (BookRecord.find(id) == BookRecord.end()) {
            cout << "Book not found. Add the book to procede or recheck the entered Book ID.\n";
            return;
        }
        BookRecord[id].availability = availability;


        cout << "Book availability updated.\n";
        cout << "Book: " << getBook(id) << "\n";
    }

    void EditBook(int id) {
        if (id < 0) {
            cout << "Invalid ID: " << id << "\n";
            return;
        }
        if (BookRecord.find(id) == BookRecord.end()) {
            cout << "Book does not exist.\n";
            return;
        }
        try {
            string title, author;
            int availability;
            bool changed = false;

            cout << "Your chosen book is: " << getBook(id) << "\n\n";

            cout << "Enter the updated title (Leave Blank for no change): ";
            if (!(getline(cin >> ws, title))) {
                throw InvalidInput();
            }
            cout << "Enter the updated author (Leave Blank for no change): ";
            if (!(getline(cin >> ws, author))) {
                throw InvalidInput();
            }
            cout << "Enter the updated availability (Enter -1 to keep no change): ";
            if (!(cin >> availability)) {
                throw InvalidInput();
            }
            if (availability != -1) {
                if (availability >= 0 && availability <= 999) {
                    BookRecord[id].availability = availability;
                    changed = true;
                }
                else {
                    while (true) {
                        cout << "Invalid. Enter the availability of Book: ";
                        if (!(cin >> availability)) {
                            throw InvalidInput();
                        }
                        if (availability >= 0 && availability <= 999) {
                            BookRecord[id].availability = availability;
                            changed = true;
                            break;
                        }
                        cout << "Invalid. ";
                    }
                }
            }
            if (!title.empty() && BookRecord[id].title != title) {
                BookRecord[id].title = title;
                changed = true;
            }
            if (!author.empty() && BookRecord[id].author != author) {
                BookRecord[id].author = author;
                changed = true;
            }
            if (changed) {
                cout << "Values of book updated: " << getBook(id) << "\n";
                return;
            }
            cout << "No changes. Values of book remains the same: " << getBook(id) << "\n";
        }
        catch (const InvalidInput& e) {
            cout << e.what();
            cin.clear();
            cin.ignore(100, '\n');
            return;
        }
    }

    void search(int id) {
        if (id < 0) {
            cout << "Invalid Id(" << id << ").\n";
            return;
        }
        if (BookRecord.find(id) == BookRecord.end()) {
            cout << "Book[ID = " << id << "] not found.\n";
            return;
        }
        cout << "Book Found:\n " << getBook(id) << "\n";
    }

    void search(const string& author) {
        if (BookRecord.empty()) {
            cout << "The Library is empty.\n";
            return;
        }
        vector<int> Books;
        for (const auto& p : BookRecord) {
            if (p.second.author == author) {
                Books.push_back(p.first);
            }
        }
        if (!Books.empty()) {
            cout << "Books found: " << Books.size() << "\n";
            for (int i : Books) {
                search(i);
            }
        }
        else {
            cout << "No Books by Author[" << author << "] found. \nNote: The search is case senstive.\n";
        }
    }

    void searchTitle(const string& title) {
        if (BookRecord.empty()) {
            cout << "The Library is empty.\n";
            return;
        }
        vector<int> Books;
        for (const auto& p : BookRecord) {
            if (p.second.title == title) {
                Books.push_back(p.first);
            }
        }
        if (!Books.empty()) {
            if (Books.size() > 1) {
                cout << "Books found:\n" << Books.size() << "\n";
                for (int i : Books) {
                    search(i);
                }
            }
            else {
                cout << "Book found:\n" << getBook(Books[0]) << "\n";
            }
        }
        else {
            cout << "No Books by the Title[" << title << "] found. \nNote: The search is case senstive.\n";
        }
    }

    void list_books() {
        if (BookRecord.empty()) {
            cout << "The Library record is empty.\n";
        }
        else {
            for (const auto& p : BookRecord) {
                cout << "Book ID: [" << p.first
                    << "] Title: [" << p.second.title
                    << "] Author: [" << p.second.author
                    << "] Availability: [" << p.second.availability
                    << "]\n";
            }
        }
    }

    void Exit() {
        fstream file("Library.csv", ios::trunc);
        if (!file.is_open()) {
            cout << "Unable to open the file.\n";
            return;
        }
        string line;
        for (const auto& p : BookRecord) {
            file << to_string(p.first) + "," + p.second.title + "," + p.second.author + "," + to_string(p.second.availability) + "\n";
        }

        if (!file) {
            cerr << "Error occurred while saving the library.\n";
        }

        file.close();
    }
};

int main() {
    cout << "Student name: Karan Singh\nURN: E25B000312\n\n";
    Library L1;
    char choice;
    bool run = true;
    while (run) {
        cout << "\nYou are in the Library: \n"
            << "[1] Add Book \n"
            << "[2] Change Book amount \n"
            << "[3] Edit Book details \n"
            << "[4] Search Book(s) by ID \n"
            << "[5] Search Book(s) by Author \n"
            << "[6] Search Book(s) by Title \n"
            << "[7] List all Books in library \n"
            << "[8] Exit\n"
            << "\nChoice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Try again.\n";
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }
        int id, availability;
        string title, author;
        switch (choice) {
        case '1':
            try {
                cout << "Enter the Book ID: ";
                if (!(cin >> id)) {
                    throw InvalidInput();
                }
                cout << "Enter the Book Title: ";
                if (!(getline(cin >> ws, title))) {
                    throw InvalidInput();
                }
                cout << "Enter the Book author: ";
                if (!(getline(cin >> ws, author))) {
                    throw InvalidInput();
                }
                cout << "Enter the Availability of Book: ";
                if (!(cin >> availability)) {
                    throw InvalidInput();
                }
                if (availability == 0) {
                    L1.Add(id, title, author);
                    break;
                }
                L1.Add(id, title, author, availability);
            }
            catch (const InvalidInput& e) {
                cout << e.what();
                cin.clear();
                cin.ignore(100, '\n');
                break;
            }
            break;
        case '2':
            try {
                cout << "Enter the Book Id: ";
                if (!(cin >> id)) {
                    throw InvalidInput();
                }
                cout << "Enter the availability of Book: ";
                if (!(cin >> availability)) {
                    throw InvalidInput();
                }
                L1.ChangeBookAmount(id, availability);
            }
            catch (const InvalidInput& e) {
                cout << e.what();
                cin.clear();
                cin.ignore(100, '\n');
                break;
            }
            break;
        case '3':
            try {
                cout << "Enter the Book Id of the Book you want to edit: ";
                if (!(cin >> id)) {
                    throw InvalidInput();
                }
                L1.EditBook(id);
            }
            catch (const InvalidInput& e) {
                cout << e.what();
                cin.clear();
                cin.ignore(100, '\n');
                break;
            }
            break;
        case '4':
            try {
                cout << "Enter the Book ID: ";
                if (!(cin >> id)) {
                    throw InvalidInput();
                }
                L1.search(id);
            }
            catch (const InvalidInput& e) {
                cout << e.what();
                cin.clear();
                cin.ignore(100, '\n');
                break;
            }
            break;
        case '5':
            try {
                cout << "Enter the Book Author: ";
                if (!(getline(cin >> ws, author))) {
                    throw InvalidInput();
                }
                L1.search(author);
            }
            catch (const InvalidInput& e) {
                cout << e.what();
                cin.clear();
                cin.ignore(100, '\n');
                break;
            }
            break;
        case '6':
            try {
                cout << "Enter the Book Title: ";
                if (!(getline(cin >> ws, title))) {
                    throw InvalidInput();
                }
                L1.searchTitle(title);
            }
            catch (const InvalidInput& e) {
                cout << e.what();
                cin.clear();
                cin.ignore(100, '\n');
                break;
            }
            break;
        case '7':
            L1.list_books();
            break;
        case '8':
            run = false;
            L1.Exit();
            break;
        default:
            cout << "Invalid entry. Enter a number between [1-8].\n";
        }
    }

    return 0;
}