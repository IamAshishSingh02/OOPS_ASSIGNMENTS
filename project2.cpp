#include<bits/stdc++.h>
using namespace std;

//Forward declaration of the class to use it as a friend class
class StudentDatabase;

//Student Class
class Student 
{
    private:
    string name;
    int roll;
    string Class;
    char div;
    string dob;
    string bg;
    string add;
    string mob;
    string li;
    static int st_ct;//Static member variable to keep track of number of students

    public:
    //Default Constructor
    Student():name(""),roll(0),Class(""),div(' '),dob(""),bg(""),add(""),mob(""),li("")
    {
        st_ct++;
    }

    //Parameterized Constructor
    Student(string n,int roll,string Class,char div,string dob,string bg,string add,string mob,string li):name(n),roll(roll),Class(Class),div(div),dob(dob),bg(bg),add(add),mob(mob),li(li)
    {
        st_ct++;
    }

    //Copy Constructor
    Student(const Student& other):name(other.name),roll(other.roll),Class(other.Class),div(other.div),dob(other.dob),bg(other.bg),add(other.add),mob(other.mob),li(other.li)
    {
        st_ct++;
    }

    //Destructor
    ~Student()
    {
        st_ct--;
    }

    //Static member function to get student count
    static int get_st()
    {
        return st_ct;
    }
    
    //Friend class declaration
    friend class StudentDatabase;

    //Member functions
    void displayInfo()const 
    {
        cout<<"Name: "<<name<<"\n";
        cout<<"Roll Number: "<<roll<<"\n";
        cout<<"Class: "<<Class<<"\n";
        cout<<"Division: "<<div<<"\n";
        cout<<"Date of Birth: "<<dob<<"\n";
        cout<<"Blood Group: "<<bg<<"\n";
        cout<<"Contact Address: "<<add<<"\n";
        cout<<"Telephone Number: "<<mob<<"\n";
        cout<<"Driving License No: "<<li<<"\n";
    }
};

//Initialize static member
int Student::st_ct=0;

//StudentDatabase class
class StudentDatabase 
{
    private:
    vector<Student*>students;

    public:
    //Constructor
    StudentDatabase(){}

    //Destructor
    ~StudentDatabase() 
    {
        for(auto student:students) 
        {
            delete student;
        }
    }

    //Function to add student
    void addStudent(const Student& student) 
    {
        students.push_back(new Student(student));
    }

    //Function to display all students
    void disp() const 
    {
        for(const auto& student:students) 
        {
            student->displayInfo();
        }
    }

    //Function to get student count
    static int get_st() 
    {
        return Student::get_st();
    }
};

int main() 
{
    try 
    {
        StudentDatabase db;

        //Add some students
        db.addStudent(Student("Ashish Singh",15,"Comp",'B',"02-01-2004","O+","OBH, 201D","1234567890","DL123456"));
        db.addStudent(Student("Anish Pandey",12,"Comp",'B',"05-09-2004","O+","OBH, 201D","9876543210","DL654321"));

        //Display all students
        db.disp();

        //Display student count
        cout<<"Total students: "<<db.get_st()<<"\n";

        //Handle invalid operations
        if(Student::get_st()<0) 
        {
            throw runtime_error("Student count cannot be negative.");
        }
    }
    catch(const exception& e) 
    {
        cout<<"Exception: "<<e.what()<<endl;
    }

    return 0;
}