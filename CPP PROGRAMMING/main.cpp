//                PASSWORD FOR ADMIN IS    1234
//                PASSWORD FOR ADMIN IS    1234
//                PASSWORD FOR ADMIN IS    1234
//                PASSWORD FOR ADMIN IS    1234
//                PASSWORD FOR ADMIN IS    1234

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;
class Quiz
{
public:
    void create_quiz()
    {
        // no_of_quiz++;
        cin.ignore();
        cout << "Enter Question 1\n";
        getline(cin, Quiz_Question[0]);
        cout << "Enter Question 2\n";
        getline(cin, Quiz_Question[1]);
        cout << "Enter Question 3\n";
        getline(cin, Quiz_Question[2]);

        cout << "<<<<------Quiz Created------>>>>>>\n\n";
    }
    void check_quiz()
    {
        cout << "Question 1 : " << Quiz_Question[0] << endl;
        cout << "Answer     : " << Quiz_Answers[0] << endl
             << endl;
        cout << "Question 2 : " << Quiz_Question[1] << endl;
        cout << "Answer     : " << Quiz_Answers[1] << endl
             << endl;
        cout << "Question 3 : " << Quiz_Question[2] << endl;
        cout << "Answer     : " << Quiz_Answers[2] << endl
             << endl;

        cout << "Enter Marks of Student : ";
        cin >> marks;
    }
    void take_quiz()
    {
        cin.ignore();
        cout << "Question 1 : " << Quiz_Question[0] << endl;
        cout << "Write Answers:";
        getline(cin, Quiz_Answers[0]);
        cout << "Question 2 : " << Quiz_Question[1] << endl;
        getline(cin, Quiz_Answers[1]);
        cout << "Question 3 : " << Quiz_Question[2] << endl;
        getline(cin, Quiz_Answers[2]);

        cout << "<<<-----Quiz Completed----->>>\n\n";
    }
    string Quiz_Question[3], Quiz_Answers[3];
    int marks;
};
// <<<<<<---------------FACULTY----------------------->>>>>>>>>>>>
class faculty
{

protected:
    string phone;

public:
    string f_name, f_password, course_name;
    void set_data()
    {
        system("CLS");
        cin.ignore();
        cout << "\n\nEnter Name : ";
        getline(cin, f_name);
        cout << "Enter Password for " << f_name << " : ";
        cin >> f_password;
        cin.ignore();
        cout << "Enter Phone No. : ";
        getline(cin, phone);
        // cin.ignore();
        cout << "Enter Department : ";
        getline(cin, course_name);
        cout << "\nFaculty Data Entered\n";
    }
    void display_data()
    {
        cout << "Name is : " << f_name << endl;
        cout << "phone is : " << phone << endl;
        cout << "Dept is : " << course_name << endl;
    }
};
faculty f[3];
int f_count = 0;

//<<<<<<<<<---------------COURSE-------------------->>>>>>>>>

class course : public faculty //, public Quiz
{
protected:
public:
    string c_name, semester, year, code;
    // Quiz q[3];
    // int no_of_quiz = -1;
    void set_data()
    {
        system("CLS");
        cin.ignore();
        cout << "Enter Course Name : ";
        getline(cin, c_name);
        cout << "Enter Teacher Name\n";
        cout << "Available Faculty Members are\n";
        for (int i = 0; i < f_count; i++)
        {
            cout << f[i].f_name << endl;
        }
        getline(cin, f_name);
        // cin.ignore();
        cout << "Enter Semester (Spring or Fall) : ";
        getline(cin, semester);
        // cin.ignore();
        cout << "Enter year : ";
        getline(cin, year);
        cout << "Enter code : ";
        getline(cin, code);
        cout << "\nCourse Data Entered\n";
    }

    void display_data()
    {

        cout << "\n\nCourse Name is : " << c_name << endl;
        cout << "Teacher is : " << f_name << endl;
        cout << "Semester is : " << semester << endl;
        cout << "Year is : " << year << endl;
        cout << "Code is : " << code << endl;
    }
};

course c[3];
int c_count = 0;

//<<<<<<<<<<----------------STUDENTS-------------->>>>>>>>>>>>

class Students : public course,public Quiz
{
private:
    int roll;

public:
    string name, adress, course_taking[3], faculty_name[3];
    string s_password;
    int attandance[3] = {0, 0, 0}, absents[3] = {0, 0, 0}, marks;
    int no_of_course_taken = 0;
    void set_student_data()
    {
        system("CLS");
        cin.ignore();
        cout << "\n\nEnter Name : ";
        getline(cin, name);
        cout << "Enter Password for " << name << " : ";
        cin >> s_password;
        cin.ignore();
        cout << "Enter Adress : ";
        getline(cin, adress);
        // cin.ignore();
        cout << "Enter Roll No : ";
        cin >> roll;
        cout << "\nStudent Data Entered\n";
    }
    void display_data()
    {
        cout << "Name is : " << name << endl;
        cout << "Adress is : " << adress << endl;
        cout << "Roll No is : " << roll << endl;
    }
    void eroll_course()
    {
        cin.ignore();
        for (int i = no_of_course_taken; i < c_count; i++)
        {
            cout << "Course name and Faculty name : ";
            getline(cin, course_taking[i]);
            getline(cin, faculty_name[i]);
            cout << endl;
            no_of_course_taken++;
        }
    }
};
Students s[3];
int s_count = 0;

//<<<<<<<<<<<<<--------------ADMIN------------------->>>>>>>>>>>>

class Admin : public Students
{
public:
    string A_password = "1234";
};
Admin A;

//<<<<<<<<<<<-----------ADMIN PANEL------------->>>>>>>>>>>>>

void admin_panel()
{
    string p;
    cout << "Enter Password for Admin : ";
    cin >> p;
    if (p == A.A_password)
    {
    }
    else
    {
        return;
    }
    int option;
    while (true)
    {
    ap:
        system("CLS");
        cout << "<<<<<<<<---------Wellcome To Admin Panel---------->>>>>>>>\n\n";
        cout << "1 Create Student\n3 View Students\n4 Add Faculty\n5 View Faculty\n";
        cout << "6 Add Course\n7 View Courses\n8 To Exit to Main Menu\nChoose one : ";
        cin >> option;
        if (option == 1)
        {

            s[s_count].set_student_data();
            s_count++;
        }

        else if (option == 3)
        {
            cout << "The Student is following\n";
            for (int i = 0; i < s_count; i++)
            {
                s[i].display_data();
            }
        }
        else if (option == 4)
        {
            f[f_count].set_data();
            f_count++;
        }
        else if (option == 5)
        {
            cout << "The Faculty is following\n";
            for (int i = 0; i < f_count; i++)
            {
                f[i].display_data();
            }
        }
        else if (option == 6)
        {
            c[c_count].set_data();
            c_count++;
        }
        else if (option == 7)
        {
            cout << "The Courses are following\n";
            for (int i = 0; i < c_count; i++)
            {
                c[i].display_data();
            }
        }
        else if (option == 8)
        {
            return;
        }
        else
        {
            cout << "Incorrect Choice \nTry Again\n";
            goto ap;
        }
    }
}
//<<<<<<<<<----------FACULTY PANEL------------->>>>>>>>>>

void faculty_panel()
{
    int iii, qq;
    string n;
    int i;
    cout << "Enter Name : ";
    cin.ignore();
    getline(cin, n);
    for (i = 0; i < f_count; i++)
    {
        if (n == f[i].f_name)
        {
            string p;
            cout << "Enter Password for " << f[i].f_name << " : ";
            cin >> p;
            if (p == f[i].f_password)
            {
                system("CLS");
                cout << "<<<<--------Wellcome " << f[i].f_name << " To Faculty Panel------>>>>\n\n";
                break;
            }
            else
            {
                return;
            }
        }
        if (i == f_count - 1)
        {
            cout << "Name does'nt Match\n";
            return;
        }
    }
    while (true)
    {
        int option;
        cout << "1 Mark Attendance\n2 View Enrolled Student\n";
        cout << "3 Add Quiz\n4 Check Quiz\n5 To Exit To Main Menu\nChoose One : ";
        cin >> option;
        if (option == 1)
        {
            for (int ii = 0; ii < s_count; ii++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (s[ii].faculty_name[j] == n)
                    {
                        char a;
                        cout << "Student Name : " << s[ii].name << "       Present/Absent(p/a) : ";
                        cin >> a;
                        if (a == 'p')
                        {
                            s[ii].attandance[j]++;
                        }
                        else
                        {
                            s[ii].absents[j]++;
                        }
                        break;
                    }
                }
            }
        }
        else if (option == 2)
        {
            for (iii = 0; iii < s_count; iii++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (s[iii].faculty_name[j] == n)
                    {
                        cout << "Student Name : " << s[iii].name << endl;
                        break;
                    }
                }
            }
        }
        else if (option == 3)
        {
        }
        else if (option == 4)
        {
        }
        else if (option == 5)
        {
            return;
        }
    }
}

//<<<<<<<<<<<<----------STUDENT PANEL------------>>>>>>>>>>>>

void student_panel()
{
    string p;
    string current_student;
    int i;
    cin.ignore();
    cout << "Enter Student Name : ";
    getline(cin, current_student);
    for (i = 0; i < s_count; i++)
    {
        if (current_student == s[i].name)
        {
            cout << "Enter Password for " << s[i].name << " : ";
            cin >> p;
            if (p == s[i].s_password)
            {
                system("CLS");
                cout << "<<<<<<<<-----Welcome " << s[i].name << " To Student Panel-------->>>>>\n\n";
                break;
            }
        }
        if (i == s_count - 1)
        {
            cout << "No Student Found\n";
            return;
        }
    }
    while (true)
    {
        int option;
        cout << "1 Enroll a course\n2 View Attandance\n3 Take Quiz\n4 Check Marks\n";
        cout << "5 Exit To Main Menu\nChoose one : ";
        cin >> option;

        if (option == 1)
        {
            cout << "List of all Courses Offered\n";
            //       cout<<"Name           Teacher        Code\n";
            for (int ii = 0; ii < c_count; ii++)
            {
                cout << endl;
                c[ii].display_data();
                cout << endl;
            }

            s[i].eroll_course();
        }
        else if (option == 2)
        {
            int op;
            for (int ii = 0; ii < s[i].no_of_course_taken; ii++)
            {
                cout << "Course : " << s[i].course_taking[ii] << "     Teachar : " << s[i].faculty_name[ii] << endl;
            }
            cout << "Select Course(1 or 2 or 3)\n";
            cin >> op;
            cout << "Course Name : " << s[i].course_taking[op - 1] << "      Total Lectures : " << s[i].absents[op - 1] + s[i].attandance[op - 1] << "     Presents : " << s[i].attandance[op - 1] << "       Absents : " << s[i].absents[op - 1] << endl;
        }
        else if (option == 3)
        {
        }
        else if (option == 4)
        {
        }
        else if (option == 5)
        {
            return;
        }
    }
}
//<<<<<<<<<----------MAIN MENU---------------->>>>>>>>>>>>>>>>>>>

void menu()
{
    int option;
m:
    system("CLS");
    cout << "\n\n1 Admin\n2 Student\n3 Faculty\nChoose One : ";
    cin >> option;
    if (option == 1)
    {
        admin_panel();
    }
    else if (option == 3)
    {
        faculty_panel();
    }
    else if (option == 2)
    {
        student_panel();
    }
    else
    {
        cout << "Incorrect Choice \nTry Again\n";
        goto m;
    }
}
int main()
{

    while (true)
    {
        menu();
    }
    getchar();
    return 0;
}