#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class police
{
public:
    void disp()
    {
        cout << "\t\t\t\t\t\t\t\t\tWELCOME TO POLICE MANAGEMENT SYSTEM\t\t\t\t\t\t\t\t\t\t\t\t" << endl;
        cout << "\n\n\n"
             << endl;
        cout << "Which record do you want to view \n a)Officer records b)Criminal record\n"
             << endl;
    }
};

class officerrecords : public police
{
    string id[50], name[100], address[80], dob[50], currentpost[80], doj[50], sex[50];

public:
    int total = 0; // to store total record in system

    void loadFromFile()
    {
        ifstream inFile("officer_records.txt");
        if (!inFile)
        {
            // File does not exist or empty - no data to load
            return;
        }
        total = 0;
        string line;
        while (getline(inFile, line))  //substr return index th element of string  
        {
            if (line.empty())
                continue;
            if (line.find("Id:") == 0)
                id[total] = line.substr(3);
            else if (line.find("Full name:") == 0)
                name[total] = line.substr(10);
            else if (line.find("Gender:") == 0)
                sex[total] = line.substr(7);
            else if (line.find("Address:") == 0)
                address[total] = line.substr(8);
            else if (line.find("Dob:") == 0)
                dob[total] = line.substr(4);
            else if (line.find("Post of officer:") == 0)
                currentpost[total] = line.substr(16);
            else if (line.find("Date of joining:") == 0)
            {
                doj[total] = line.substr(16);
                total++;
            }
        }
        inFile.close();
    }

    void enter()
    {
        int ch = 0;
        cout << "How many officer data do you want to enter ??" << endl;
        cin >> ch;
        for (int i = total; i < total + ch; i++)
        {
            cout << "\nEnter the data of officer " << i + 1 << endl;
            cout << "Enter name:" << endl;
            cin >> name[i];
            cout << "Enter id:" << endl;
            cin >> id[i];
            cout << "Enter gender:" << endl;
            cin >> sex[i];
            cout << "Enter address:" << endl;
            cin >> address[i];
            cout << "Enter date of birth[DD/MM/YYYY]:" << endl;
            cin >> dob[i];
            cout << "Enter current post:" << endl;
            cin >> currentpost[i];
            cout << "Enter date of joining[DD/MM/YYYY]:" << endl;
            cin >> doj[i];
            cout << "\n"
                 << endl;
        }
        total += ch;
    }

    void show()
    {
        ifstream onfile("officer_records.txt");
        if (!onfile)
        {
            cerr << "file not opened" << endl;
            return;
        }
        string line;
        while (getline(onfile, line))
        {
            cout << line << endl;
        }
        onfile.close();
    }

    void search()
    {
        if (total == 0)
        {
            cout << "No data entered\n"
                 << endl;
            return;
        }
        string idd;
        cout << "\nEnter id of officer" << endl;
        cin >> idd;
        bool found = false;
        for (int i = 0; i < total; i++)
        {
            if (idd == id[i])
            {
                cout << "\nResult for officer " << endl;
                cout << "Full name:" << name[i] << endl;
                cout << "Id:" << id[i] << endl;
                cout << "Gender:" << sex[i] << endl;
                cout << "Address:" << address[i] << endl;
                cout << "Dob:" << dob[i] << endl;
                cout << "Post of officer:" << currentpost[i] << endl;
                cout << "Date of joining:" << doj[i] << endl;
                cout << "\n"
                     << endl;
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Officer with this ID not found." << endl;
    }

    void update()
    {
        if (total == 0)
        {
            cout << "No data is entered\n"
                 << endl;
            return;
        }
        string rollno;
        cout << "\nEnter id of officer which you want to change" << endl;
        cin >> rollno;
        bool found = false;
        for (int i = 0; i < total; i++)
        {
            if (rollno == id[i])
            {
                cout << "\nPrevious data entered:" << endl;
                cout << "Full name:" << name[i] << endl;
                cout << "Id:" << id[i] << endl;
                cout << "Gender:" << sex[i] << endl;
                cout << "Address:" << address[i] << endl;
                cout << "Dob:" << dob[i] << endl;
                cout << "Post of officer:" << currentpost[i] << endl;
                cout << "Date of joining:" << doj[i] << endl;
                cout << "\n Please enter new data" << endl;
                cout << "Enter new name:" << endl;
                cin >> name[i];
                cout << "Enter gender:" << endl;
                cin >> sex[i];
                cout << "Enter new address:" << endl;
                cin >> address[i];
                cout << "Enter new date of birth (DD/MM/YYYY):" << endl;
                cin >> dob[i];
                cout << "Enter new current post:" << endl;
                cin >> currentpost[i];
                cout << "Enter new date of joining (DD/MM/YYYY):" << endl;
                cin >> doj[i];
                cout << "RECORD UPDATED.\nPlease click on save option to save updated record." << endl;
                cout << "\n"
                     << endl;
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Officer with this ID not found." << endl;
    }

    void delete1()
    {
        if (total == 0)
        {
            cout << "No data is entered yet\n"
                 << endl;
            return;
        }
        int a;
        cout << "\nAre you sure to delete all records?" << endl;
        cout << "Press 1 to delete all records" << endl;
        cin >> a;
        if (a == 1)
        {
            total = 0;
            cout << "All records deleted !!\nPlease click on save option\n"
                 << endl;
        }
        else
        {
            cout << "Please press 1 to delete all records" << endl;
        }
    }

    void saveToFile()
    {
        ofstream onFile("officer_records.txt");
        if (onFile.is_open())
        {
            for (int i = 0; i < total; i++)
            {
                onFile << "Id:" << id[i] << endl;
                onFile << "Full name:" << name[i] << endl;
                onFile << "Gender:" << sex[i] << endl;
                onFile << "Address:" << address[i] << endl;
                onFile << "Dob:" << dob[i] << endl;
                onFile << "Post of officer:" << currentpost[i] << endl;
                onFile << "Date of joining:" << doj[i] << endl;
                onFile << "\n"
                       << endl;
            }
            onFile.close();
            cout << "\nData saved to officer_records.txt\n"
                 << endl;
        }
        else
        {
            cout << "Unable to open file" << endl;
        }
    }
};
class criminalrecord : public police
{
    string id[50], name[100], crime[80], address[80], dob[50], gender[20], status[50];

public:
    int total = 0;

    void loadFromFile()
    {
        ifstream inFile("criminal_records.txt");
        if (!inFile)
        {
            // No file or empty file - no data to load
            return;
        }
        total = 0;
        string line;
        while (getline(inFile, line))
        {
            if (line.empty())
                continue;
            if (line.find("Id:") == 0)
                id[total] = line.substr(3);
            else if (line.find("Full name:") == 0)
                name[total] = line.substr(10);
            else if (line.find("Gender:") == 0)
                gender[total] = line.substr(7);
            else if (line.find("Address:") == 0)
                address[total] = line.substr(8);
            else if (line.find("Dob:") == 0)
                dob[total] = line.substr(4);
            else if (line.find("Crime:") == 0)
                crime[total] = line.substr(6);
            else if (line.find("Status:") == 0)
            {
                status[total] = line.substr(7);
                total++;
            }
        }
        inFile.close();
    }

    void enter()
    {
        int ch = 0;
        cout << "How many criminal records do you want to enter ??" << endl;
        cin >> ch;
        for (int i = total; i < total + ch; i++)
        {
            cout << "\nEnter the data of criminal " << i + 1 << endl;
            cout << "Enter name:" << endl;
            cin >> name[i];
            cout << "Enter id:" << endl;
            cin >> id[i];
            cout << "Enter gender:" << endl;
            cin >> gender[i];
            cout << "Enter address:" << endl;
            cin >> address[i];
            cout << "Enter date of birth[DD/MM/YYYY]:" << endl;
            cin >> dob[i];
            cout << "Enter crime committed:" << endl;
            cin >> crime[i];
            cout << "Enter status (e.g., In Custody, Released):" << endl;
            cin >> status[i];
            cout << "\n"
                 << endl;
        }
        total += ch;
    }

    void show()
    {
        ifstream inFile("criminal_records.txt");
        if (!inFile)
        {
            cerr << "file not opened" << endl;
            return;
        }
        string line;
        while (getline(inFile, line))
        {
            cout << line << endl;
        }
        inFile.close();
    }

    void search()
    {
        if (total == 0)
        {
            cout << "No data entered\n"
                 << endl;
            return;
        }
        string idd;
        cout << "\nEnter id of criminal" << endl;
        cin >> idd;
        bool found = false;
        for (int i = 0; i < total; i++)
        {
            if (idd == id[i])
            {
                cout << "\nResult for criminal " << endl;
                cout << "Full name:" << name[i] << endl;
                cout << "Id:" << id[i] << endl;
                cout << "Gender:" << gender[i] << endl;
                cout << "Address:" << address[i] << endl;
                cout << "Dob:" << dob[i] << endl;
                cout << "Crime committed:" << crime[i] << endl;
                cout << "Status:" << status[i] << endl;
                cout << "\n"
                     << endl;
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Criminal with this ID not found." << endl;
    }

    void update()
    {
        if (total == 0)
        {
            cout << "No data is entered\n"
                 << endl;
            return;
        }
        string rollno;
        cout << "\nEnter id of criminal which you want to change" << endl;
        cin >> rollno;
        bool found = false;
        for (int i = 0; i < total; i++)
        {
            if (rollno == id[i])
            {
                cout << "\nPrevious data entered:" << endl;
                cout << "Full name:" << name[i] << endl;
                cout << "Id:" << id[i] << endl;
                cout << "Gender:" << gender[i] << endl;
                cout << "Address:" << address[i] << endl;
                cout << "Dob:" << dob[i] << endl;
                cout << "Crime committed:" << crime[i] << endl;
                cout << "Status:" << status[i] << endl;
                cout << "\n Please enter new data" << endl;
                cout << "Enter new name:" << endl;
                cin >> name[i];
                cout << "Enter gender:" << endl;
                cin >> gender[i];
                cout << "Enter new address:" << endl;
                cin >> address[i];
                cout << "Enter new date of birth (DD/MM/YYYY):" << endl;
                cin >> dob[i];
                cout << "Enter new crime committed:" << endl;
                cin >> crime[i];
                cout << "Enter new status:" << endl;
                cin >> status[i];
                cout << "RECORD UPDATED.\nPlease click on save option to save updated record." << endl;
                cout << "\n"
                     << endl;
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Criminal with this ID not found." << endl;
    }

    void delete1()
    {
        if (total == 0)
        {
            cout << "No data is entered yet\n"
                 << endl;
            return;
        }
        int a;
        cout << "\nAre you sure to delete all records?" << endl;
        cout << "Press 1 to delete all records" << endl;
        cin >> a;
        if (a == 1)
        {
            total = 0;
            cout << "All records deleted !!\nPlease click on save option\n"
                 << endl;
        }
        else
        {
            cout << "Please press 1 to delete all records" << endl;
        }
    }

    void saveToFile()
    {
        ofstream onFile("criminal_records.txt");
        if (onFile.is_open())
        {
            for (int i = 0; i < total; i++)
            {
                onFile << "Id:" << id[i] << endl;
                onFile << "Full name:" << name[i] << endl;
                onFile << "Gender:" << gender[i] << endl;
                onFile << "Address:" << address[i] << endl;
                onFile << "Dob:" << dob[i] << endl;
                onFile << "Crime:" << crime[i] << endl;
                onFile << "Status:" << status[i] << endl;
                onFile << "\n"
                       << endl;
            }
            onFile.close();
            cout << "\nData saved to criminal_records.txt\n"
                 << endl;
        }
        else
        {
            cout << "Unable to open file" << endl;
        }
    }
};

int main()
{
    officerrecords officers;
    criminalrecord criminals;

    // Load existing data from files at program start
    officers.loadFromFile();
    criminals.loadFromFile();

    police base;
    int choice, choice2;

    while (true)
    {
        base.disp();
        cout << "Enter your choice (1 for Officer records, 2 for Criminal records, 0 to Exit): ";
        cin >> choice;

        if (choice == 0)
        {
            cout << "Exiting system..." << endl;
            break;
        }

        if (choice == 1)
        {
            cout << "\nOfficer Records Menu:\n";
            cout << "1. Enter new records\n";
            cout << "2. Show all records\n";
            cout << "3. Search record\n";
            cout << "4. Update record\n";
            cout << "5. Delete all records\n";
            cout << "6. Save records\n";
            cout << "0. Back to main menu\n";
            cout << "Enter your choice: ";
            cin >> choice2;

            switch (choice2)
            {
            case 1:
                officers.enter();
                break;
            case 2:
                officers.show();
                break;
            case 3:
                officers.search();
                break;
            case 4:
                officers.update();
                break;
            case 5:
                officers.delete1();
                break;
            case 6:
                officers.saveToFile();
                break;
            case 0:
                continue;
            default:
                cout << "Invalid choice." << endl;
            }
        }
        else if (choice == 2)
        {
            cout << "\nCriminal Records Menu:\n";
            cout << "1. Enter new records\n";
            cout << "2. Show all records\n";
            cout << "3. Search record\n";
            cout << "4. Update record\n";
            cout << "5. Delete all records\n";
            cout << "6. Save records\n";
            cout << "0. Back to main menu\n";
            cout << "Enter your choice: ";
            cin >> choice2;

            switch (choice2)
            {
            case 1:
                criminals.enter();
                break;
            case 2:
                criminals.show();
                break;
            case 3:
                criminals.search();
                break;
            case 4:
                criminals.update();
                break;
            case 5:
                criminals.delete1();
                break;
            case 6:
                criminals.saveToFile();
                break;
            case 0:
                continue;
            default:
                cout << "Invalid choice." << endl;
            }
        }
        else
        {
            cout << "Invalid choice. Please select again." << endl;
        }
    }

    return 0;
}
