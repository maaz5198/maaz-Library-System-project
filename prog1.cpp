#include <iostream>
#include <string>
using namespace std;

class LibraryItem
{
private:
    string Title;
    string Author;
    string DueDate;

public:
    LibraryItem(string t, string a, string d)
    {
        Title = t;
        Author = a;
        DueDate = d;
    }

    string getTitle() { return Title; }
    string getAuthor() { return Author; }
    string getDueDate() { return DueDate; }

    void setTitle(string t) { Title = t; }
    void setAuthor(string a) { Author = a; }
    void setDueDate(string d) { DueDate = d; }

    virtual void CheckOut() = 0;
    virtual void ReturnItem() = 0;
    virtual void DisplayDetails() = 0;

    virtual ~LibraryItem() {}
};
class Book : public LibraryItem
{
private:
    string isbn;
    bool issued;

public:
    Book(string t, string a, string d, string i)
        : LibraryItem(t, a, d)
    {
        isbn = i;
        issued = false;
    }

    void CheckOut() override
    {
        if (issued)
            cout << "Book already issued!"<<endl;
        else
        {
            issued = true;
            cout << "Book checked out successfully."<<endl;
        }
    }

    void ReturnItem() override
    {
        issued = false;
        cout << "Book returned successfully."<<endl;
    }

    void DisplayDetails() override
    {
        cout <<endl<< "[BOOK]"<<endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Due Date: " << getDueDate() << endl;
    }
};
class DVD : public LibraryItem
{
private:
    int duration;

public:
    DVD(string t, string a, string d, int dur)
        : LibraryItem(t, a, d)
    {
        if (dur <= 0)
            throw runtime_error("Invalid DVD duration!");
        duration = dur;
    }

    void CheckOut() override
    {
        cout << "DVD checked out."<<endl;
    }

    void ReturnItem() override
    {
        cout << "DVD returned."<<endl;
    }

    void DisplayDetails() override
    {
        cout <<endl<< "[DVD]"<<endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Duration: " << duration << " minutes"<<endl;
        cout << "Due Date: " << getDueDate() << endl;
    }
};
class Magazine : public LibraryItem
{
private:
    int issueNumber;

public:
    Magazine(string t, string a, string d, int issue)
        : LibraryItem(t, a, d)
    {
        issueNumber = issue;
    }

    void CheckOut() override
    {
        cout << "Magazine checked out."<<endl;
    }

    void ReturnItem() override
    {
        cout << "Magazine returned.\n";
    }

    void DisplayDetails() override
    {
        cout <<endl<< "[MAGAZINE]"<<endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Issue No: " << issueNumber << endl;
        cout << "Due Date: " << getDueDate() << endl;
    }
};
int main()
{
    LibraryItem *item[20];
    int count = 0;
    int choice;

    do
    {
        cout <<endl<< "----- LIBRARY MENU -----"<<endl;
        cout << "1. Add Book"<<endl;
        cout << "2. Add DVD"<<endl;
        cout << "3. Add Magazine"<<endl;
        cout << "4. Display All Items"<<endl;
        cout << "5. Check Out Item"<<endl;
        cout << "6. Return Item"<<endl;
        cout << "7. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;
        try
        {
            switch (choice)
            {
            case 1:
            {
                string t, a, d, isbn;
                cout << "Title: ";
                cin >> t;
                cout << "Author: ";
                cin >> a;
                cout << "Due Date: ";
                cin >> d;
                cout << "ISBN: ";
                cin >> isbn;

                item[count++] = new Book(t, a, d, isbn);
                cout << "Book Added Successfully."<<endl;
                break;
            }

            case 2:
            {
                string t, a, d;
                int dur;
                cout << "Title: ";
                cin >> t;
                cout << "Author: ";
                cin >> a;
                cout << "Due Date: ";
                cin >> d;
                cout << "Duration: ";
                cin >> dur;

                item[count++] = new DVD(t, a, d, dur);
                cout << "DVD Added Successfully."<<endl;
                break;
            }

            case 3:
            {
                string t, a, d;
                int issue;
                cout << "Title: ";
                cin >> t;
                cout << "Author: ";
                cin >> a;
                cout << "Due Date: ";
                cin >> d;
                cout << "Issue Number: ";
                cin >> issue;

                item[count++] = new Magazine(t, a, d, issue);
                cout << "Magazine Added Successfully."<<endl;
                break;
            }

            case 4:
            {
                if (count == 0)
                {
                    cout << "No items available."<<endl;
                }
                else
                {
                    for (int i = 0; i < count; i++)
                        item[i]->DisplayDetails();
                }
                break;
            }

            case 5:
            {
                int index;
                cout << "Enter item index: ";
                cin >> index;
                item[index]->CheckOut();
                break;
            }

            case 6:
            {
                int index;
                cout << "Enter item index: ";
                cin >> index;
                item[index]->ReturnItem();
                break;
            }

            case 7:
                cout << "Exited Succesfully..."<<endl;
                break;

            default:
                cout << "Invalid Choice!"<<endl;
            }
        }
        catch (exception& e)
        {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 7);
    for (int i = 0; i < count; i++)
        delete item[i];

    return 0;
}