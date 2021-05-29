#include <iostream>
#include<fstream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

class Password {
private:
    string pw = "123456", username = "booksy_anu", cuser, cpw;
    int recovery = 2;
public:
    int login() {
        string passw, uname;
        int tries = 0, x;
        do {
            cout << "Enter username: ";
            cin >> uname;
            cout << "\nEnter password: ";
            cin >> passw;
            if (passw == pw && uname == username) {
                x = 1;
                break;
            }
            else if (passw != pw || uname != username) {
                cout << "password or username wrong" << endl;
                tries++;
                x = 0;
            }
        } while (tries != 3);
        if (x == 1) {
            return 1;
        }
        else {
            return 0;
        }
    }
    void recover() {
        int year = 0, x = 0;
        cout << "You only get one chance. 1+1 is?" << endl;
        cin >> year;
        if (year == recovery) {
            cout << "Your username is " << username << " and your password is " << pw << endl;
        }
        else {
            cout << "1+1 is 2 you idiot!" << endl;
        }
    }
};

class Manage {
private:
    string pw = "123456";
    int recoverynumber = 2;
    char bname[1000], aname[1000];
    int price, copies;
public:
    Manage() {
        price = 0;
        strcpy_s(bname, "no title");
        strcpy_s(aname, "no title");
        copies = 0;
    }
    void addbooks() {
        cout << "Hello! Enter details in the following manner.\nExample- Harry Potter will be written as harrypotter." << endl;
        cout << "BOOKNAME: ";
        cin >> bname;
        cout << "AUTHORNAME: ";
        cin >> aname;
        cout << "PRICE: ";
        cin >> price;
        cout << "NUMBER OF COPIES: ";
        cin >> copies;
        ofstream fout;
        fout.open("books.txt", ios::app);
        fout.write((char*)this, sizeof(*this));
        fout.close();
        cout << "Books added!" << endl;
    }
    void deletebname(char* t) {
        ifstream fin;
        ofstream fout;
        fin.open("books.txt",
            ios::app);
        if (!fin)
            cout << "\n File not found";
        else {
            fout.open("tempfile.txt",
                ios::app);
            fin.read((char*)this, sizeof(*this));

            // Until end of file is not reached
            while (!fin.eof()) {
                if (strcmp(bname, t))
                    fout.write((char*)this, sizeof(*this));
                fin.read((char*)this, sizeof(*this));
            }
            fin.close();
            fout.close();
            remove("books.txt");
            rename("tempfile.txt", "books.txt");
        }
    }
    void inventory() {
        ifstream fin;
        // Open function open file named
        fin.open("books.txt", ios::in);
        if (!fin)
        {
            cout << "File not found";
        }
        else {
            cout << "BOOKNAME\t\tAUTHORNAME\t\tPRICE\t\tCOPIES" << endl;
            fin.read((char*)this, sizeof(*this));

            // Until end of file is
            // not reached
            while (!fin.eof()) {
                cout << "\n" << bname << "\t\t" << aname << "\t\t" << price << "\t\t" << copies << endl;

                // read is object of ifstream
                // class which is used for
                // read data of file
                fin.read((char*)this, sizeof(*this));
            }
            fin.close();
        }
    }
    void search(char* t) {
        int counter = 0;
        ifstream fin;
        fin.open("books.txt", ios::in);

        // If file is not found
        if (!fin)
            cout << "File not found";
        else {
            fin.read((char*)this, sizeof(*this));

            // Until end of file is not reached
            while (!fin.eof()) {
                if (!strcmp(t, bname)) {
                    cout << "\n"
                        << bname
                        << "\t" << aname << "\t" << price << "\t" << copies;
                    counter++;
                }
                fin.read((char*)this, sizeof(*this));
            }
            if (counter == 0)
                cout << "No record found";
            fin.close();
        }
    }
    void update(char* t) {
        int counter = 0;
        ifstream fin;
        fin.open("books.txt", ios::in);

        // If file is not found
        if (!fin)
            cout << "File not found";
        else {
            fin.read((char*)this, sizeof(*this));

            // Until end of file is not reached
            while (!fin.eof()) {
                if (!strcmp(t, bname)) {
                    cout << "\n"
                        << bname
                        << "\t" << aname << "\t" << price << "\t" << copies;
                    counter++;
                }
                fin.read((char*)this, sizeof(*this));
            }
            if (counter == 0)
                cout << "No record found";
            fin.close();
        }
        cout << "\n";
        ofstream fout;
        fin.open("books.txt",
            ios::app);
        if (!fin)
            cout << "\n File not found";
        else {
            fout.open("tempfile.txt",
                ios::app);
            fin.read((char*)this, sizeof(*this));

            // Until end of file is not reached
            while (!fin.eof()) {
                if (strcmp(bname, t))
                    fout.write((char*)this, sizeof(*this));
                fin.read((char*)this, sizeof(*this));
            }
            fin.close();
            fout.close();
            remove("books.txt");
            rename("tempfile.txt", "books.txt");
        }
        cout << "\n";
        cout << "Hello! Enter details in the following manner.\nExample- Harry Potter will be written as harrypotter." << endl;
        cout << "BOOKNAME: ";
        cin >> bname;
        cout << "AUTHORNAME: ";
        cin >> aname;
        cout << "PRICE: ";
        cin >> price;
        cout << "NUMBER OF COPIES: ";
        cin >> copies;
        fout.open("books.txt", ios::app);
        fout.write((char*)this, sizeof(*this));
        fout.close();
        cout << "\nRecord updated!\n";
    }
    void searcha(char* t) {
        int counter = 0;
        ifstream fin;
        fin.open("books.txt", ios::in);

        // If file is not found
        if (!fin)
            cout << "File not found";
        else {
            fin.read((char*)this, sizeof(*this));

            // Until end of file is not reached
            while (!fin.eof()) {
                if (!strcmp(t, aname)) {
                    cout << "\n"
                        << bname
                        << "\t" << aname << "\n";
                    counter++;
                }
                fin.read((char*)this, sizeof(*this));
            }
            if (counter == 0)
                cout << "\nNo record found\n";
            fin.close();
        }
    }
    void donation() {
        cout << "Hello! Enter details in the following manner.\nExample- Harry Potter will be written as harrypotter." << endl;
        cout << "BOOKNAME: ";
        cin >> bname;
        cout << "AUTHORNAME: ";
        cin >> aname;
        cout << "PRICE: ";
        cin >> price;
        cout << "NUMBER OF COPIES: ";
        cin >> copies;
        ofstream fout;
        fout.open("donated.txt", ios::app);
        fout.write((char*)this, sizeof(*this));
        fout.close();
        cout << "Books donated!" << endl;
    }
    void buy(char* t) {
        ifstream fin;
        ofstream fout;
        int counter = 0,pr,co;
        char a[1000];
        fin.open("books.txt", ios::in);

        // If file is not found
        if (!fin)
            cout << "File not found";
        else {
            fin.read((char*)this, sizeof(*this));

            // Until end of file is not reached
            while (!fin.eof()) {
                if (!strcmp(t, bname)) {
                    strcpy_s(a, aname);
                    pr = price;
                    co = copies-1;
                    counter++;
                }
                fin.read((char*)this, sizeof(*this));
            }
            fin.close();
            if (counter == 0)
            {
                cout << "SOLD OUT! SORRY\n";
            }
            else {
                fin.open("books.txt",
                    ios::app);
                if (!fin)
                    cout << "\n File not found";
                else {
                    fout.open("tempfile.txt",
                        ios::app);
                    fin.read((char*)this, sizeof(*this));

                    // Until end of file is not reached
                    while (!fin.eof()) {
                        if (strcmp(bname, t))
                            fout.write((char*)this, sizeof(*this));
                        fin.read((char*)this, sizeof(*this));
                    }
                    fin.close();
                    fout.close();
                    remove("books.txt");
                    rename("tempfile.txt", "books.txt");
                }
                strcpy_s(bname, t);
                strcpy_s(aname, a);
                price = pr;
                copies = co;
                fout.open("books.txt", ios::app);
                fout.write((char*)this, sizeof(*this));
                fout.close();
                cout << "Price is-" << price << " . Pay here! Thank you for shopping at BOOKSY <3\n";
            }

        }

    }
    void displaydonated() {
        ifstream fin;
        // Open function open file named
        fin.open("donated.txt", ios::in);
        if (!fin)
        {
            cout << "File not found";
        }
        else {
            cout << "BOOKNAME\t\tAUTHORNAME\t\tPRICE\t\tCOPIES" << endl;
            fin.read((char*)this, sizeof(*this));

            // Until end of file is
            // not reached
            while (!fin.eof()) {
                cout << "\n" << bname << "\t\t" << aname << "\t\t" << price << "\t\t" << copies << endl;

                // read is object of ifstream
                // class which is used for
                // read data of file
                fin.read((char*)this, sizeof(*this));
            }
            fin.close();
        }
    }
    void deletedonation() {
        displaydonated();
        char t[1000];
        cout << "\nEnter title of book you want to delete: ";
        cin >> t;
        ifstream fin;
        ofstream fout;
        fin.open("donated.txt",
            ios::app);
        if (!fin)
            cout << "\n File not found";
        else {
            fout.open("tempfile.txt",
                ios::app);
            fin.read((char*)this, sizeof(*this));

            // Until end of file is not reached
            while (!fin.eof()) {
                if (strcmp(bname, t))
                    fout.write((char*)this, sizeof(*this));
                fin.read((char*)this, sizeof(*this));
            }
            fin.close();
            fout.close();
            remove("donated.txt");
            rename("tempfile.txt", "books.txt");
        }
    }
    void displaybought() {
        ifstream fin;
        // Open function open file named
        fin.open("bought.txt", ios::in);
        if (!fin)
        {
            cout << "File not found";
        }
        else {
            cout << "BOOKNAME\t\tAUTHORNAME\t\tPRICE\t\tCOPIES" << endl;
            fin.read((char*)this, sizeof(*this));

            // Until end of file is
            // not reached
            while (!fin.eof()) {
                cout << "\n" << bname << "\t\t" << aname << "\t\t" << price << "\t\t" << copies <<  endl;

                // read is object of ifstream
                // class which is used for
                // read data of file
                fin.read((char*)this, sizeof(*this));
            }
            fin.close();
        }
    }
};
class Customer : public Manage {
private:
    char cname[100];
public:
    Customer() {
        strcpy_s(cname, "no title");
    }
    void donatebook() {
        cout << "Enter your name: ";
        cin >> cname;
        donation();
        cout << "Thank you for donating " << cname << ". You are taking a very good step." << endl;
    }
    void buybook() {
        char title[1000];
        cout << "\nEnter title of "
            << "book you want to buy : ";
        cin.ignore();
        cin.getline(title, 19);
       buy(title);
    }
    void searchbyname() {
        char title[1000];
        cout << "\nEnter title of "
            << "book to search : ";
        cin.ignore();
        cin.getline(title, 19);
        search(title);
    }
    void searchbyauthor() {
        char title[1000];
        cout << "\nEnter name of "
            << "author to search : ";
        cin.ignore();
        cin.getline(title, 19);
        searcha(title);
    }
};


void welcome() {
    cout << "WELCOME TO BOOKSY!" << endl;
}
int main()
{
    welcome();
    int n, y = 0;
    Password p;
    int flag = 0;
    char title[1000];
    Manage m;
    Customer c;
    do {
        cout << "\nAre you a customer or the management. Press 1 for customer and 2 for management. Press 3 to exit" << endl;
        cin >> n;
        switch (n) {
        case 1: cout << "\nEnter number according to choice!" << endl;
            cout << "1)Buy a book\n2)Donate a book\n3)Search a book by name\n4)Search a book by author name\n5)Exit\n";
            cin >> y;
            switch (y) {
            case 1:cout << "\n***********BUY BOOKS***********\n"; 
                c.buybook();
                cout << endl;
                break;
            case 2:cout << "\n***********DONATE BOOKS***********\n";
                c.donatebook();
                cout << endl;
                break;
            case 3:cout << "\n***********SEARCH BOOKS***********\n"; 
                c.searchbyname();
                cout << endl;
                break;
            case 4:cout << "\n***********SEARCH BY AUTHOR***********\n";
                c.searchbyauthor();
                cout << endl;
                break;
            case 5:exit(0);
                break;
            }

            break;
        case 2: flag = p.login();
            do {
                if (flag == 1) {
                    cout << "\n****************MENU************\n";
                    cout << "\nEnter number according to choice\n1)Add new books\n2)Update book details\n3)Delete a book\n4)Display details of a book\n5)Display all books\n6)Display donated books\n7)Delete Donated books\n8)Exit" << endl;
                    cin >> y;
                    switch (y) {
                    case 1:cout << "\n***********ADD BOOKS***********\n";
                        m.addbooks();
                        cout << endl;
                        break;
                    case 2:cout << "\n***********UPDATE BOOKS***********\n";
                        cout << "\nEnter book title "
                        << "to update record : ";
                        cin.ignore();
                        cin.getline(title, 19);
                        m.update(title);
                        cout << endl;
                        break;
                    case 3:cout << "\n***********DELETE BOOKS***********\n";
                        cout << "\nEnter book title "
                        << "to delete record : ";
                        cin.ignore();
                        cin.getline(title, 19);
                        m.deletebname(title);
                        cout << "Deleted!" << endl;
                        break;
                    case 4:cout << "\n***********SEARCH BOOKS***********\n"; 
                        cout << "\nEnter title of "
                        << "book to search : ";
                        cin.ignore();
                        cin.getline(title, 19);
                        m.search(title);
                        cout << endl;
                        break;
                    case 5:cout << "\n***********DISPLAY ALL BOOKS***********\n";
                        m.inventory();
                        cout << endl;
                        break;
                    case 6: cout << "\n***********DISPLAY DONATED BOOKS***********\n";
                        m.displaydonated();
                        cout << endl;
                        break;
                    case 7: cout << "\n***********DELETE DONATED BOOKS***********\n";
                        m.deletedonation();
                        cout << endl;
                        break;
                    }
                }
                else {
                    cout << "wrong!!!! try again" << endl;
                    p.recover();
                }
            } while (y != 8);
            break;
        case 3:exit(0);
            break;
        }
    } while (n != 3);
}
