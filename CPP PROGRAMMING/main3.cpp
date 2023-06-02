//             STOI ERROR
//                PASSWORD FOR ADMIN IS    1234
//                PASSWORD FOR ADMIN IS    1234
//                PASSWORD FOR ADMIN IS    1234
//                PASSWORD FOR ADMIN IS    1234
//                PASSWORD FOR ADMIN IS    1234

#include <iostream>
#include <fstream>
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
public:
    string phone;
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

class Students : public course, public Quiz
{
private:
public:
    string roll;
    string name, adress, course_taking[3] = {"%%", "%%", "%%"}, faculty_name[3] = {"%%", "%%", "%%"};
    string s_password;
    int save_course_taking_info;
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
        cout << "5 View Enrolled Course\n6 Exit To Main Menu\nChoose one : ";
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
        else if (option == 5)
        {
            cout << "\n\n";
            for (int temp = 0; temp < s[i].no_of_course_taken; temp++)
            {
                cout << "Course : " << s[i].course_taking[temp] << "     Teachar : " << s[i].faculty_name[temp] << endl;
            }
            cout << "\n\n";
        }
        else if (option == 6)
        {
            return;
        }
    }
}

//<<<<<<<<<----------MAIN MENU---------------->>>>>>>>>>>>>>>>>>>

void menu()
{
    while (true)
    {
        int option;
    m:
        system("CLS");
        cout << "\n\n1 Admin\n2 Student\n3 Faculty\n4 Exit ans save\nChoose One : ";
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
        else if (option == 4)
        {
            return;
        }
        else
        {
            cout << "Incorrect Choice \nTry Again\n";
            goto m;
        }
    }
}
int main()
{
    // cin.ignore();
    // string ch[3];
    string ch;
    // INPUT FACULTY FROM FILES
    // INPUT FACULTY FROM FILES
    // INPUT FACULTY FROM FILES

    fstream file1;
    file1.open("FacultyData.txt", ios::in);
    if (!file1)
    {
        cout << "File Openng Error\n";
        return 0;
    }
    else
    {
        // cout << "File Opened\n";
        while (!file1.eof())
        {
            getline(file1, ch);
            if (ch.length() == 0)
            {
                getline(file1, f[f_count].f_name);
            }
            else
            {
                f[f_count].f_name = ch;
            }
            //  getline(file1, ch[0]);
            getline(file1, f[f_count].course_name);
            getline(file1, f[f_count].f_password);
            getline(file1, f[f_count].phone);

            // cout << f[f_count].f_name;
            // cout << f[f_count].course_name;
            // cout << f[f_count].phone;
            // cout << f[f_count].f_password << endl;
            f_count++;
        }
    }
    int save_f = f_count;
    file1.close();
    // INPUT COURSE FROM FILES
    // INPUT COURSE FROM FILES
    // INPUT COURSE FROM FILES
    // INPUT COURSE FROM FILES
    fstream file11;
    file11.open("CourseData.txt", ios::in);
    {
        if (!file11)
        {
            cout << "File Course not opened\n";
            return 0;
        }
        else
        {
            cout << "OPENED\n";
            while (!file11.eof())
            {
                getline(file11, ch);
                if (ch.length() == 0)
                {
                    getline(file11, c[c_count].c_name);
                }
                else
                    c[c_count].c_name = ch;
                // getline(file11,ch[0]);
                // cout<<ch[0]<<endl;

                getline(file11, c[c_count].f_name);
                getline(file11, c[c_count].semester);
                getline(file11, c[c_count].year);
                getline(file11, c[c_count].code);
                c_count++;
                // cout<<c[0].c_name;
                // cout<<c[0].f_name;
            }
        }
    }
    int save_c = c_count;
    file11.close();

    // INPUT STUDENTS FROM FILES
    // INPUT STUDENTS FROM FILES
    // INPUT STUDENTS FROM FILES
    // INPUT STUDENTS FROM FILES
    // INPUT STUDENTS FROM FILES

    fstream file111;
    file111.open("StudentData.txt", ios::in);
    if (!file111)
    {
        cout << "Student not\n";
        return 0;
    }
    else
    {
        while (!file111.eof())
        {
            getline(file111, ch);
            if (ch.length() == 0)
            {
                getline(file111, s[s_count].name);
            }
            else
                s[s_count].name = ch;
            getline(file111, s[s_count].s_password);
            getline(file111, s[s_count].adress);
            getline(file111, s[s_count].roll);
            for (int i = 0; i < 3; i++)
            {
                getline(file111, s[s_count].course_taking[i]);
                if (s[s_count].course_taking[i] != "%%")
                    s[s_count].no_of_course_taken++;
            }

            s[s_count].save_course_taking_info = s[s_count].no_of_course_taken;

            for (int i = 0; i < 3; i++)
            {
                getline(file111, s[s_count].faculty_name[i]);
            }
            for (int i = 0; i < 3; i++)
            {
                string q;
                getline(file111, q);

                s[s_count].attandance[i] = std::stoi(q);
            }
            for (int i = 0; i < 3; i++)
            {
                string q;
                getline(file111, q);

                s[s_count].absents[i] = std::stoi(q);
            }
            s_count++;
        }
    }
    int save_s = s_count;
    file111.close();

    menu();

    //                    SAVING FACULTY DATA
    //                    SAVING FACULTY DATA
    //                    SAVING FACULTY DATA
    //                    SAVING FACULTY DATA
    //                    SAVING FACULTY DATA

    fstream outfile1;
    outfile1.open("FacultyData.txt", ios::out);
    if (!outfile1)
    {
        cout << "Error\n";
        return 0;
    }
    else
    {
        for (int i = 0; i < f_count; i++)
        {
            outfile1 << endl;
            outfile1 << f[i].f_name << endl;
            outfile1 << f[i].course_name << endl;
            outfile1 << f[i].f_password << endl;
            outfile1 << f[i].phone;
        }
    }
    outfile1.close();

    //                    SAVING COURSE DATA
    //                    SAVING COURSE DATA
    //                    SAVING COURSE DATA
    //                    SAVING COURSE DATA
    //                    SAVING COURSE DATA

    fstream outfile2;
    outfile2.open("CourseData.txt", ios::out);
    if (!outfile2)
    {
        cout << "Course Output Error";
        return 0;
    }
    else
    {
        for (int i = 0; i < c_count; i++)
        {
            outfile2 << endl;
            outfile2 << c[i].c_name << endl;
            outfile2 << c[i].f_name << endl;
            outfile2 << c[i].semester << endl;
            outfile2 << c[i].year << endl;
            outfile2 << c[i].code;
        }
    }
    outfile2.close();

    //                    SAVING STUDENTS DATA
    //                    SAVING STUDENTS DATA
    //                    SAVING STUDENTS DATA
    //                    SAVING STUDENTS DATA
    //                    SAVING STUDENTS DATA

    fstream outfile3;
    outfile3.open("StudentData.txt", ios::out);
    if (!outfile3)
    {
        cout << "Student sav error";
        return 0;
    }
    else
    {
        for (int i = 0; i < s_count; i++)
        {
            outfile3 << endl;
            outfile3 << s[i].name << endl;
            outfile3 << s[i].s_password << endl;
            outfile3 << s[i].adress << endl;
            outfile3 << s[i].roll << endl;
            for (int j = 0; j < 3; j++)
            {
                outfile3 << s[i].course_taking[j] << endl;
            }
            outfile3 << s[i].faculty_name[0] << endl;
            outfile3 << s[i].faculty_name[1] << endl;
            outfile3 << s[i].faculty_name[2] << endl;
            for (int q = 0; q < 3; q++)
            {
                outfile3 << s[i].attandance[q] << endl;
            }
            for (int q = 0; q < 3; q++)
            {
                outfile3 << s[i].absents[q] << endl;
            }
        }
    }
    outfile3.close();

    getchar();
    return 0;
}
