
#include <iostream>
#define PASSWORD 12345

void PrintFirstPage();
void PrintStudentInfo(); 
void PrintCourseAddMenu();
void PrintStudentUpdateMenu();
void PrintStuffMenu();

enum FirstPage {
	STUEDNT = 1, STUFF, EXIT1,
};

enum StudentManu {
	UPDATE=1,VIEWCOURSE,BACK1,EXIT2,
};

enum CourseUpdate {
	ADD=1,DROP,BACK2, EXIT3,
};

enum StuffMenu{
	VIEW = 1, SEARCH, DELETES, DELETEC, BACK3, EXIT4,
};


int main()
{
	system("color D");
	int First_Menu_choice;
	int UpdateInfo;
	std::cout << " " << std::endl;

	while (true)
	{
		PrintFirstPage();
		std::cout << "Enter: ";
		std::cin >> First_Menu_choice;
		switch (First_Menu_choice)
		{
		case STUEDNT:
		{
			PrintStudentInfo();
			std::cout << "Enter: ";
			std::cin >> First_Menu_choice;
			while (true)
			{
				switch (First_Menu_choice)
				{
				
				case UPDATE:
				{
					PrintStudentUpdateMenu();
					while (true)
					{
						std::cout << "Enter: ";
						std::cin >> UpdateInfo;
						switch (UpdateInfo)
						{
						case ADD:
						{
							int Student_ID, Course_ID;
							std::cout << "Enter Your ID: ";
							std::cin >> Student_ID;
							//call function that read student ID
							//call function that print available course
							std::cout << "Enter Course ID: ";
							std::cin >> Course_ID;
							//call function that read Course I
						}
						break;
						case DROP:
							//call function that delete course
							break;

						case BACK2:
							break;
						case EXIT3:
							exit(1);
						}
						break;
					}
					break;
				}
				break;
				case VIEWCOURSE:
					//call function that print student name and course
					break;
				case BACK1:
					break;

				case EXIT2:
					exit(1);
				}
				break;
			}
			break;
		}
		break;

		case STUFF:
		{
			int stuffInfo;
			std::cout << "********STUDENT DATA********" << std::endl;

			std::cout << std::endl;
			std::cout << std::endl;

			std::cout << "------ENTER------" << std::endl;
			PrintStuffMenu();
			std::cin >> stuffInfo;
			while (true)
			{
				switch (stuffInfo)
				{

				case VIEW:

					// call function print all student 
				case SEARCH:
					// call function search for student 

				case DELETES:
					// call function that delete student 

				case DELETEC:
					// call function that delete course 
				case BACK3:
					break;
				case EXIT4:
					exit(1);

				}
				break;
			}
			break;
		}
		break;
		case EXIT1:
			exit(1);

		}

	}
}



void PrintFirstPage()
{
	std::cout << "========================== = " << std::endl;
	std::cout << "--------ENTER--------" << std::endl;
	std::cout << "1.For Student" << std::endl;
	std::cout << "2.For Stuff" << std::endl;
	std::cout << "3.To Exit" << std::endl;
	std::cout << "===========================" << std::endl;
}


void PrintStudentInfo()
{
	std::cout << "=============================================" << std::endl;
	std::cout << "|	-----WELCOME TO STUDENT PAGE!-----" << std::endl;
	std::cout << "|		1.To Upgrade Data " << std::endl;
	std::cout << "|		2.To View All Courses " << std::endl;
	std::cout << "|		3.Back to main page" << std::endl;
	std::cout << "|		4.Exit" << std::endl;
	std::cout << "============================================="<<std::endl;

}
void PrintCourseAddMenu()
{
	int StudentID, CourseID;
	std::cout << "To Add course" << std::endl;
	std::cout << "Enter your ID:" << std::endl;
	std::cin >> StudentID;
	//call function read StudentID
	std::cout << "You Can Add The Following Courses" << std::endl;
	//call function that print course
	std::cout << "Enter course ID" << std::endl;
	std::cin >> CourseID;
	//call function that read CourseID
	
}

void PrintStudentUpdateMenu()
{
	std::cout << "-----------UPDATE-----------" << std::endl;
	std::cout << "1.To Add course" << std::endl;
	std::cout << "2.To Drop course" << std::endl;
	std::cout << "3.Back to previes page" << std::endl;
}




void PrintStuffMenu()

{
	std::cout << "----------STUFF ONLY----------" << std::endl;
	std::cout << "1.View All Students" << std::endl;
	std::cout << "2.Search Student" << std::endl; 
	std::cout << "3.Delete Student" << std::endl; 
	std::cout << "4.Delete Course" << std::endl;
	std::cout << "5.Back to previes page" << std::endl;
	std::cout << "6.Exit" << std::endl;




}