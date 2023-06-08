#include <iostream>
#include <string>

using namespace std;

void Admin_login();
void Faculty_login ();
void Student_login ();
void calculate_fee();
int e_count;

int faculty_count = 0;
int student_count = 0;
const int MAX_COURSES = 10;
int course_count = 0;
const int Max_enroll = 4;
const int MAX_ENROLLED_STUDENTS = 10;



class User
{
	protected:
		string User_ID;
		string password;
		string name;
		string phone_no;
		string CNIC_no;
	public:
		User ()
		{
    		User_ID  = " ";
    		password = " ";
    		name     = " ";
    		phone_no = " ";
    		CNIC_no  = " ";
  		}
		User (string User_ID, string password, string name, string phone_no, string CNIC_no)
		{
    		this->User_ID  = User_ID;
    		this->password = password;
    		this->name     = name;
    		this->phone_no = phone_no;
    		this->CNIC_no  = CNIC_no;
		}
		bool log_in (string User_ID, string password)
		{
    		if (this->User_ID == User_ID && this->password == password)
			{
				return true;
			}
			else
			{
				cout << " \n\nWrong ID or Password enterd " << endl;
				return false;
			}
		}
};


string enrolled_students[MAX_ENROLLED_STUDENTS];
class faculty:public User
{
	protected:
		string Department;
	public:
	    
		faculty ():User ()
		{
    		Department = " ";
		}
		faculty (string Department, string User_ID, string password, string name, string phone_no, string CNIC_no):User (User_ID, password, name, phone_no, CNIC_no)
		{
			this->Department = Department;
		}
		void displayEnrolledStudents();
		string get_name ()
		{
    		return name;
		}
		string get_Department ()
		{
    		return Department;
		}
		
        
		void Dislpay_Faculty ()
		{
    		cout << "   User ID            " << User_ID << endl;
    		cout << "   Name               " << name << endl;
    		cout << "   Depatment          " << Department << endl;
    		cout << "   Phone No           " << phone_no << endl;
    		cout << "   CNIC No            " << CNIC_no << endl;
    		cout << endl << endl;
		}
};
faculty Total_Faculty[15];



class course:public faculty
{
	protected:
  		string courses[MAX_COURSES];
  		int semesters[MAX_COURSES];
	public:
    	void add_course (string course)
		{
    		if (course_count < MAX_COURSES )
    		{
        		courses[course_count]    = course;
        		course_count++;
    		}
    		else
    		{
        		cout << "Maximum no of course has been added " << endl;
    		}
		}
		bool check_course(string x)
		{
		    for (int i = 0; i < course_count; i++)
			{
			    if (x ==courses[i] )
                {
                    return true;
                }
			}
			return false;
		}
		void Display_course ()
		{
    		for (int i = 0; i <= course_count; i++)
			{
	    		cout << courses[i] ;
			}
		}
};



string E_course[Max_enroll];
string F_course[Max_enroll];
class Student:public User 
{
	private:
		int Roll_no;
	public:
	    course a;
	    faculty b;
		Student () : User()
    	{
        	Roll_no = 0;
		}
    	Student (int Roll_no, string User_ID, string password,string name, string phone_no, string CNIC_no):User (User_ID, password, name, phone_no, CNIC_no)
		{
    		this->Roll_no = Roll_no;
		}
		string get_name ()
		{
    		return name;
		}
		string get_ID ()
		{
    		return User_ID;
		}
		void display_Student_data ()
		{
			cout << "User ID      :   " << User_ID << endl;
			cout << "Name         :   " << name << endl;
			cout << "Phone No     :   " << phone_no << endl;
			cout << "CNIC No      :   " << CNIC_no << endl;
			cout << "Roll No is   :   " << Roll_no << endl;
			cout << endl << endl;
		}
		
		
	/*	void Display_enroll()
		{
			for (int i = e_count; i < Max_enroll; i++)
			{
            	cout <<E_course[i];
			}
     	}*/
};
Student Total_Student[50];



class Admin:public User 
{
	protected:
    	int semester[8];
	public:
	    int semester_no = 0;
	    Admin (string User_ID, string password):User (User_ID, password, " ", " ", " "){}
		void add_semester (int semester)
		{
			if (semester_no <= 8)
			{
				this->semester[semester_no] = semester;
				if(semester % 2 != 0)
				{
					cout << semester << " Spring Semester is added successfully " << endl;
				}
				else
				{
					cout << semester <<" Semester (Fall Semester) is added successfully " <<endl;
				}
				semester_no++;
			}
			else
			{
				cout << "No more semester can be add in database " << endl;
			}
		}
		void Dispay_Semester()
		{
		    for (int i = 1 ; i <= semester_no ; i++)
		    {
		        if (i % 2 !=  0)
		        {
		            cout << " Semester " << i << " (Spring Semester) " << endl;
		        }
		        else
		        {
		            cout << " Semester " << i << " (Fall Semester) " << endl;
		        }
		     }
		}
};



int main ()
{
	int choice;
	while (1)
	{
		cout << "\n\n-------------------------------------  STUDENT  MANAGEMENT  SYSTEM ---------------------------------------------\n" << endl;
		cout << " 1. Admin Portal   " << endl;
		cout << " 2. Faculty Poratl" << endl;
		cout << " 3. Student Poratl" << endl;
		cout << " 4. Exit    " << endl;
		cout << endl;
		cout << "Enter your choice           ";
		cin >> choice;
		switch (choice)
		{
			case 1:
				Admin_login ();
				break;
			case 2:
				Faculty_login ();
				break;
			case 3:
				Student_login ();
				break;
			case 4:
				cout << " Existing the program ---------------";
				exit (0);
			default:
				cout << " Wrong Input. Please Try Again " << endl;
				break;
		}
    }
	return (0);
}




void Admin_login()
{
    Admin admin("Admin1", "1234");
    string User_ID, password;
    cout << "\nEnter ID:                ";
    cin >> User_ID;
    cout << "Enter Password:          ";
    cin >> password;
    if (admin.log_in(User_ID, password))
    {
        int choice;
        course obj;
        while (1)
        {
            cout << "\n\n----------------------------  ADMIN PORTAL  -----------------------------\n" << endl;
            cout << " 1. Register Student" << endl;
            cout << " 2. Add Semester" << endl;
            cout << " 3. Offer Course" << endl;
            cout << " 4. Assign Faculty" << endl;
            cout << " 5. View Registered Students" << endl;
            cout << " 6. View Assigned Faculty" << endl;
            cout << " 7. Exit" << endl;
            cout << endl;
            cout << "Enter your choice:          ";
            cin >> choice;
            switch (choice)
            {
                case 1:
                {
                    string user_id, password, name, phone_no, cnic_no;
                    int Roll_no;
                    cout << "Enter User ID    :   ";
                    cin.ignore();
                    getline(cin, user_id);
                    cout << "Enter Password   :   ";
                    getline(cin, password);
                    cout << "Enter Name       :   ";
                    getline(cin, name);
                    cout << "Enter Roll No    :   ";
                    cin >> Roll_no;
                    cout << "Enter Phone No   :   ";
                    cin.ignore();
                    getline(cin, phone_no);
                    cout << "Enter CNIC No    :   ";
                    getline(cin, cnic_no);
                    Total_Student[student_count] = Student( Roll_no , user_id, password, name, phone_no, cnic_no);
                    student_count++;
                    cout << "Student registered successfully!" << endl;
                    break;
                }
                case 2:
                {
                    int semester;
                    cout << "Enter the semester:     ";
                    cin >> semester;
                    admin.add_semester(semester);
                    break;
                }
                case 3:
                {
                    string course;
                    cout << "Enter the course:        ";
                    cin.ignore();
                    getline(cin, course);
                    obj.add_course(course);
                    cout << "Course added successfully!" << endl;
                    break;
                }
                case 4:
                {
                    string department, user_id, password, name, phone_no, cnic_no;
                    cin.ignore(); 
                    cout << "Enter User ID       :    ";
                    getline(cin, user_id);
                    cout << "Enter password      :    ";
                    getline(cin, password);
                    cout << "Enter name          :    ";
                    getline(cin, name);
                    cout << "Enter Department    :    ";
                    getline(cin, department);
                    cout << "Enter Phone No      :    ";
                    getline(cin, phone_no);
                    cout << "Enter CNIC No       :    ";
                    getline(cin, cnic_no);
                    Total_Faculty[faculty_count] = faculty(user_id, password, name, phone_no, cnic_no, department);
                    faculty_count++;
                    cout << "Faculty registered successfully!" << endl;
                    break;
                }
                case 5:
                {
                    for (int i = 0; i < student_count; i++)
                    {
                        Total_Student[i].display_Student_data();
                    }
                    break;
                }
                case 6:
                {
                    for (int i = 0; i < faculty_count; i++)
                    {
                        Total_Faculty[i].Dislpay_Faculty();
                    }
                    break;
                }
                case 7:
                {
                    cout << "Exiting the Admin Portal ---------------" << endl;
                    return;
                }
                default:
                    cout << "Wrong Input. Please Try Again" << endl;
                    break;
            }
        }
    }
    else
    {
        cout << "Wrong ID or Password entered." << endl;
        return;
    }
}




void Faculty_login ()
{
    string User_ID, password;
    cout << "Enter faculty User ID:          ";
    cin >> User_ID;
    cout << "Enter   Password:               ";
    cin >> password;
    bool found = false;
    int student_index = -1;
    for (int i = 0; i < student_count; i++)
    {
        if (Total_Student[i].log_in(User_ID, password))
        {
            found = true;
            student_index = i;
            break;
        }
    }
    
    if (found)
    {
    	int choice;
		while (1)
    	{
    		cout <<"\n\n----------------------------  FACULTY PORTAL  -----------------------------\n" << endl;
			cout << " 1. View Enrolled Student            " << endl;
			cout << " 2. Mark Attendennce                 " << endl;
			cout << " 3. Take Quiz                        " << endl;
			cout << " 6. Exit to Main Menu                " << endl;
			cout << endl;
			cout << "Enter your choice           ";
			cin >> choice;
			switch (choice)
			{
			/*	case 1:
				    int enrolled_count = 0;
                    for (int i = 0; i < e_count; i++) 
                    {
                    if (F_course[i] == this) 
                    {
                        enrolled_student++;
                        cout << enrolled_students[i].student->name << endl;
                    }
                    }
                    cout << "Total Enrolled Students: " << enrolled_students << endl;
					break;*/
				case 2:
					break;
				case 3:
					//Student_login();
					break;
				case 4:
					cout << " Exit from Faculty Portal ---------------";
					return;
				default:
					cout << " Wrong Input. Please Try Again " << endl;
					break;
			}
		}
    }
    else
    {
        return;
    }
}




void Student_login ()
{
    Student obj1;
    course a;
    faculty b;
    string User_ID, password;
    cout << "Enter Student User ID:          ";
    cin >> User_ID;
    cout << "Enter   Password:               ";
    cin >> password;
    bool found = false;
    for (int i=0 ;i < student_count ; i++)
    {
        if (Total_Student[i].log_in(User_ID, password) )
        found = true;
        break;
    }
    if (found)
    {
    	int choice;
    	while (1)
    	{
			cout <<"\n\n----------------------------  STUDENT PORTAL  -----------------------------\n" << endl;
			cout << " 1. Enroll Course                " << endl;
			cout << " 2. Generate Fee Challan         " << endl;
			cout << " 3. View Attendance              " << endl;
			cout << " 4. View Marks                   " << endl;
			cout << " 5. Exit to Main Menu            " << endl;cout << endl;
			cout << "Enter your choice           ";
			cin >> choice;
			switch (choice)
			{
			    
				case 1:
					{
					string x;
					a.Display_course();
                    cout << "Enter the course you want to enroll: ";
                    cin.ignore();
                    getline(cin, x);
                    E_course[e_count] = x;
                    b.Dislpay_Faculty();
                    cout << "Enter the faculty for your course: ";
                    getline(cin, F_course[e_count]);
                    e_count++;
                    cout << "Enrollment successful!" << endl;
					//obj1.Display_enroll();
					break;}
				case 2:
					calculate_fee();
					break;
				case 3:
					Student_login ();
					break;
				case 5:
					cout << " Exit from Student Portal ---------------";
					return;
				default:
					cout << " Wrong Input. Please Try Again " << endl;
					break;
			}
    	}
    }
    else
    {
       cout << "Wrong Id or password is entered" << endl;
        return;
    } 
    
}



void calculate_fee()
{
    int transport_fee = 15000;
	int hostel_fee = 28000;
	int tution_fee = e_count * 8000;
	int fee = tution_fee + transport_fee + hostel_fee;
	cout << "The total fee is " << fee << "RS" << endl;
}