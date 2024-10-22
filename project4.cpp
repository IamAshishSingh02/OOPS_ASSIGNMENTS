#include<bits/stdc++.h>
using namespace std;

class Employee {
private:
    string name;
    int id;
    double salary;

public:
    void accept() {
        cout << "Enter Employee Name: ";
        cin.ignore();  
        getline(cin, name);
        cout << "Enter Employee Id: ";
        cin >> id;
        cout << "Enter Employee Salary: ";
        cin >> salary;
    }

    void disp() const {
        cout << "\nName: " << name;
        cout << "\nId: " << id;
        cout << "\nSalary: " << salary << endl;
    }

    void writeToFile(ofstream &f) const {
        f << name << endl << id << endl << salary << endl;
    }

    void readFromFile(ifstream &f) {
        getline(f, name);
        f >> id;
        f >> salary;
        f.ignore(); 
    }
};

int main() {
    Employee o[10];
    ofstream fout("demo.txt");
    int n;

    cout << "Enter the number of employees (max 10): ";
    cin >> n;

    if (n > 10) {
        cout << "Maximum number of employees is 10." << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter details of Employee " << i + 1 << ": \n";
        o[i].accept();
        o[i].writeToFile(fout);
    }
    fout.close();

    ifstream fin("demo.txt");
    cout << "\nInformation of Employees is as follows: \n";
    for (int i = 0; i < n; i++) {
        cout << "\nEmployee " << i + 1 << ": ";
        o[i].readFromFile(fin);
        o[i].disp();
    }
    fin.close();
}
