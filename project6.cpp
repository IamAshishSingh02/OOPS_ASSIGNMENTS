#include <bits/stdc++.h>
using namespace std;

class item {
public:
    string name;
    string dob;
    long long tele;

    // Overloading the equality operator for search and delete functionality
    bool operator==(const item& other) const {
        return name == other.name; // Compare by name
    }
};

vector<item> v;

void insert() {
    item i;
    cout << "Enter Employee Name: ";
    cin >> i.name;
    cout << "Enter his DOB: ";
    cin >> i.dob;
    cout << "Enter Telephone Number: ";
    cin >> i.tele;
    v.push_back(i);
}

void print(const item& i) {
    cout << "\nEmployee Name: " << i.name;
    cout << "\nEmployee Date of Birth: " << i.dob;
    cout << "\nEmployee Telephone No.: " << i.tele;
    cout << "\n";
}

void display() {
    for_each(v.begin(), v.end(), print);
}

void search() {
    string na;
    cout << "Enter Name of Employee to search: ";
    cin >> na;

    item searchItem;
    searchItem.name = na; // Set the name for comparison
    auto it = find(v.begin(), v.end(), searchItem);

    if (it != v.end()) {
        cout << "Element Found:\n";
        print(*it);
    } else {
        cout << "Element Not Found!\n";
    }
}

void dele() {
    string nameToDelete;
    cout << "\nEnter Name of Employee to delete: ";
    cin >> nameToDelete;

    item deleteItem;
    deleteItem.name = nameToDelete; // Set the name for comparison
    auto it = find(v.begin(), v.end(), deleteItem);

    if (it == v.end()) {
        cout << "\nNot found!!!\n";
    } else {
        v.erase(it);
        cout << "\nDeleted!!!\n";
    }
}

int main() {
    while (true) {
        int c;
        cout << "\n1. Insert\n2. Display\n3. Search\n4. Sort\n5. Delete\n6. Exit\n";
        cin >> c;

        switch (c) {
            case 1:
                insert();
                break; // Added break
            case 2:
                display();
                break; // Added break
            case 3:
                search();
                break; // Added break
            case 4:
                sort(v.begin(), v.end(), [](const item& a, const item& b) {
                    return a.name < b.name; // Sort by name
                });
                display();
                break; // Added break
            case 5:
                dele();
                break; // Added break
            case 6:
                return 0; // Exit the program
            default:
                cout << "Invalid option! Please try again.\n";
        }
    }
}
