#include <iostream>
#include<string>
using namespace std;

class User
{
	protected:
		string User_ID;
		string password;
		string name;
		string phone_no;
		string CNIC_no;
	public:
		
		
		User()
		{
			User_ID  = " ";
			password = " ";
			name     = " ";
			phone_no = " ";
			CNIC_no  = " ";
		}
		User(string User_ID , string password , string name , string phone_no , string CNIC_no)
		{
			this->User_ID  = User_ID ;
			this->password = password ;
			this->name     = name ;
			this->phone_no = phone_no ;
			this->CNIC_no  = CNIC_no ;
		}
		bool log_in(string User_ID , string password)
		{
			if (this->User_ID == User_ID && this->password == password)
			{
				return true;
			}
			else 
			{
				cout << " \n\nWrong ID or Password enterd "<< endl;
				return false;
			}
		}
};

class faculty : public User
{
	protected:
		string Department;
	public:
		//faculty FACULTY[];
		int faculty_count = 0;
		faculty(string Department , string User_ID , string password , string name , string phone_no , string CNIC_no) : User (User_ID , password , name , phone_no , CNIC_no)
		{
			this->Department = Department;
		}
		void set_faculty_data()
		{
			cout << "Enter User ID      ";
			getline (cin , User_ID);
			cout << "Enter password     ";
			getline (cin , password);
			cout << "Enter name         ";
			getline (cin , name);
			cout << "Enter Phone No     ";
			getline (cin , phone_no);
			cout << "Enter CNIC No      ";
			getline (cin , CNIC_no);
			cout << "Enter Department   ";
			getline (cin , Department);
	}
	
		string get_name()
		{
			return name;
		}
		string get_Department()
		{
			return Department;
		}
		void Dislay_Faculty()
		{
			cout << "   User ID            "  << User_ID << endl;
			cout << "   Name               "  << name << endl;
			cout << "   Depatment          "  << Department << endl;
			cout << "   Phone No           "  << phone_no << endl;
			cout << "   CNIC No            "  << CNIC_no << endl ;
		}
};




class course : public faculty
{
	private:
		string course;
	public:
		void set_course( string course)
		{
			this->course = course;
			for (int i = 0 ; i < faculty_count ; i++)
			{
			//	cout << "Faculty Name         " << FACULTY[i].get_name() << "        ";
			//	cout << "Faculty Department   " << FACULTY[i].get_Department() << endl;
			}
		}
		
};

class Student : public User 
{
private:
    int Roll_no;
    string Department;

public:
	Student student[10];
    int student_count = 0;
	Student(string Department , int Roll_no , string User_ID , string password , string name , string phone_no , string CNIC_no) : User (User_ID , password , name , phone_no , CNIC_no)
	{
		this->Department = Department;
		this->Roll_no = Roll_no;
	}
	void Set_Student_Data()
	{
		cout << "Enter User ID      ";
		getline (cin , User_ID);
		cout << "Enter password     ";
		getline (cin , password);
		cout << "Enter name         ";
		getline (cin , name);
		cout << "Enter Phone No     ";
		getline (cin , phone_no);
		cout << "Enter CNIC No      ";
		getline (cin , CNIC_no);
		cout << "Enter Department   ";
		getline (cin , Department);
		cout << "Enter Roll No   ";
		cin >> Roll_no;
	}
    string name, adress, course_taking[3], faculty_name[3];
    string s_password;
    int attandance[3] = {0, 0, 0}, absents[3] = {0, 0, 0};
    int no_of_course_taken = 0;
    
    void display_Student_data()
    {
    	cout << "User ID     : " << User_ID << endl;
        cout << "Name        : " << name << endl;
        cout << "Phone No    : " << phone_no << endl;
        cout << "CNIC No     : " << CNIC_no << endl;
        cout << "Department  : " << Department << endl;
        cout << "Roll No is  : " << Roll_no << endl;
    }
};
  /*  void eroll_course()
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
    }*/
};


class Admin : public User
{

	public:
	    int semester_no = 0;
		Admin(string User_ID , string password) : User (User_ID , password , " " , " " , " "){}
		void add_semester( string semester)
		{
			if (semester_no <= 8)
			{
			//	semester[semester_no] = semester;
				semester_no++;
				cout << "Semester is added successfully " << endl;
			}
			else 
			{
				cout << "No more semester can be add in database " << endl;
			}
		}
};












void Admin_login()
{
    
	Admin admin ("Admin1" , "1234");
	string User_ID , password;
	cout << "Enter  ID                 ";
	cin >> User_ID ;
	cout << "Enter Password            ";
	cin >> password ;
	if (admin.log_in( User_ID , password))
	{
		int choice;
		while (true)
		{
			cout << "\n\n----------------------------  ADMIN PORTAL  -----------------------------\n" << endl;
			cout << " 1. Register Student             " << endl;
			cout << " 2. Offer Course                 " << endl;
			cout << " 3. Assign Faculty               " << endl;
			cout << " 4. View Registered Students     " << endl;
			cout << " 5. view Assign Faculty          " << endl;
			cout << " 6. Exit                         " << endl;
			cout << endl;
			cout << "Enter your choice           ";
			cin >> choice;
			switch (choice)
			{
				case 1:
					admin.student[admin.student_count].Set_Sudent_Data();
					student_count++;
				    break;
				case 2:
				
					break;
				case 3:
					admin.FACULTY[admin.faculty_count].set_faculty_data();
					faculty_count++;
					break;
				case 4:
					for (int i = 0 ; i < student_count ; i++)
					{
						student.display_Student_data() ;
					}
					break;
				case 5:
					for (int i = 0 ; i < faculty_count ; i++)
					{
						faculty.Dislay_Faculty() ;
					}
					break;
				case 6:
					cout << " Exit from Student Portal ---------------" ;
					return ;
				default:
					cout << " Wrong Input. Please Try Again " << endl ;
					break;
			}
		}
	}
	else
	{
		return;
	}
}


void Faculty_login()
{

	int choice;
	while (1)
	{
		cout << "\n\n----------------------------  FACULTY PORTAL  -----------------------------\n" << endl;
		cout << " 1. View Enrolled Student            " << endl;
		cout << " 2. Mark Attendennce                 " << endl;
		cout << " 3. Take Quiz                        " << endl;
		cout << " 4. View Registered Students         " << endl;
		cout << " 5. view Assign Faculty              " << endl;
		cout << " 6. Exit to Main Menu                " << endl;
		cout << endl;
		cout << "Enter your choice           ";
		cin >> choice;

		switch (choice)
		{
			case 1:
				Admin_login();
				break;
			case 2:
				Faculty_login();
				break;
			case 3:
				//Student_login();
				break;
			case 4:
				cout << " Exit from Faculty Portal ---------------" ;
				return ;
			default:
				cout << " Wrong Input. Please Try Again " << endl ;
				break;
		}
	}
}

void Student_login()
{

	int choice;
	while (1)
	{
	cout << "\n\n----------------------------  STUDENT PORTAL  -----------------------------\n" << endl;
	cout << " 1. Enroll Course                " << endl;
	cout << " 2. Generate Fee Challan         " << endl;
	cout << " 3. View Attendance              " << endl;
	cout << " 4. View Marks                   " << endl;
	cout << " 6. Exit to Main Menu            " << endl;
	cout << endl;
	cout << "Enter your choice           ";
	cin >> choice;
	
		switch (choice)
		{
			case 1:
				Admin_login();
				break;
			case 2:
				Faculty_login();
				break;
			case 3:
				Student_login();
				break;
			case 4:
				cout << " Exit from Student Portal ---------------" ;
				return ;
			default:
				cout << " Wrong Input. Please Try Again " << endl ;
				break;
		}
	}
}


int main()
{
	int choice;
	while (1)
	{
		cout << "\n\n-------------------------------------  STUDENT  MANAGEMENT  SYSTEM  ---------------------------------------------\n" << endl;
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
				Admin_login();
				break;
			case 2:
				Faculty_login();
				break;
			case 3:
				Student_login();
				break;
			case 4:
				cout << " Existing the program ---------------" ;
				exit(0);
			default:
				cout << " Wrong Input. Please Try Again " << endl ;
				break;
		}
	}
	return (0);
}