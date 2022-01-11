#include "headers/course.h"
#include "headers/student.h"
#include "headers/tools.h"

#include <string>
#include <iostream>
#include <stdio.h>

#define PASSWORD 12345

enum MainMenu {
	STUEDNT = 1, STUFF, EXIT
};

enum StudentManu {
	EDIT = 1, VIEW_COURSE, BACK, EXIT1
};

enum StudEditMenu {
	PROFILE = 1, REGISTER_FOR_COURSE, DROP_COURSE, BACK1, EXIT2
};

enum StuffMenu{
	VIEW_ALL_STUDENTS = 1,
	VIEW_ALL_COURSES,
	SEARCH_STUDENT_FOR_COURSE,
	ADD_STUDENT,
	ADD_COURSE,
	EDIT_STUDENT,
	EDIT_COURSE,
	SEARCH_STUDENT_FOR_ID,
	SEARCH_COURSE_FOR_ID,
	DELETE_STUDENT,
	DELETE_COURSE,
	BACK2,
	EXIT3
};


//Input And Print Handlers
int printMainManu();
int printStudentManu();
int printStudentEditMenu(); 
int printStuffMenu(); 

//Main Manu Case Handlers
bool student(); 
bool stuff(); 

//Student Case Handlers
bool editStudProfile(); 


//Edit Student Profile Case Handlers
void profile();
void registerForCourse();
void dropCourse();


//Stuff Cases Handlers
void addStudent();
void addCourse();
void editStud();
void editCourse();
void searchStudForCourse();
void searchStud();
void searchCourse();
void deleteCourse();
void deleteStud();



int main(int argc, char const *argv[])
{   
	while(true) {
		switch (printMainManu()) {
			case STUEDNT:
				student();
				break;
			case STUFF:
				stuff();
				break;
			case EXIT:
				exit(1);
				break;
			default:
				std::cout<<"Invalid input!\n\n";
		}
	}

    return 0;
}


bool student() {
	while (true) {
		switch (printStudentManu()) {
			case EDIT:
				editStudProfile();
				break;
			case VIEW_COURSE:
				tools::viewAllCourses();
				break;
			case BACK:
				return true;
			case EXIT1:
				exit(1);
			default:
				std::cout<<"Invalid input!\n\n";
		}
	}
}


bool stuff() {
	while (true) {
		switch (printStuffMenu()) {
			case VIEW_ALL_STUDENTS:
				tools::viewAllStuds();
				break;
			case VIEW_ALL_COURSES:
				tools::viewAllCourses();
				break;
			case SEARCH_STUDENT_FOR_COURSE:
				searchStudForCourse();
				break;
			case ADD_STUDENT:
				addStudent();
				break;
			case ADD_COURSE:
				addCourse();
				break;
			case EDIT_STUDENT:
				editStud();
				break;
			case EDIT_COURSE:
				editCourse();
				break;
			case SEARCH_STUDENT_FOR_ID:
				searchStud();
				break;
			case SEARCH_COURSE_FOR_ID:
				searchCourse();
				break;
			case DELETE_STUDENT:
				deleteStud();
				break;
			case DELETE_COURSE:
				deleteCourse();
				break;
			case BACK2:
				return true;
			case EXIT3:
				exit(1);
			default:
				std::cout<<"Invalid input!\n\n";
		}
	}
}


bool editStudProfile() {
	while (true) {
		switch (printStudentEditMenu()) {
			case PROFILE:
				profile();
				break;
			case REGISTER_FOR_COURSE:
				registerForCourse();
				break;
			case DROP_COURSE:
				dropCourse();
				break;
			case BACK1:
				return true;
			case EXIT2:
				exit(1);
			default:
				std::cout<<"Invalid input!\n\n";
		}
	}
}


int printMainManu() {
	int input;
	std::cout << "\n\n===========================" << std::endl;
	std::cout << "MAIN MANU" << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << "<1> Student" << std::endl;
	std::cout << "<2> Staff" << std::endl;
	std::cout << "<3> To Exit" << std::endl;
	std::cout << "===========================\n: ";

	std::cin>>input;
	return input;

}

int printStudentManu() {
	int input;
	std::cout << "\n\n================================" << std::endl;
	std::cout << "STUDENT" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "<1> Edit Student Data " << std::endl;
	std::cout << "<2> View All Courses " << std::endl;
	std::cout << "<3> Back to Pervious Menu " << std::endl;
	std::cout << "<4> Exit " << std::endl;
	std::cout << "================================\n: ";
	
	std::cin>>input;
	return input;
}


int printStudentEditMenu() {
	int input;
	std::cout << "\n\n================================" << std::endl;
	std::cout << "EDIT STUDENT" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "<1> Edit Profile Data " << std::endl;
	std::cout << "<2> Register For A Course " << std::endl;
	std::cout << "<3> Drop A Course " << std::endl;
	std::cout << "<4> Back to Pervious Menu " << std::endl;
	std::cout << "<5> Exit " << std::endl;
	std::cout << "================================\n: ";

	std::cin>>input;
	return input;

}
int printStuffMenu() {
	int input;
	std::cout << "\n\n================================" << std::endl;
	std::cout << "STUFF" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "<1>  View All Students " << std::endl;
	std::cout << "<2>  View All Courses " << std::endl;
	std::cout << "<3>  Search Student For Course " << std::endl;
	std::cout << "<4>  Add Student " << std::endl;
	std::cout << "<5>  Add Course " << std::endl;
	std::cout << "<6>  Edit Student " << std::endl;
	std::cout << "<7>  Edit Course " << std::endl;
	std::cout << "<8>  Search Student By Id " << std::endl;
	std::cout << "<9>  Search Course By Id " << std::endl;
	std::cout << "<10> Delete Student By Id " << std::endl;
	std::cout << "<11> Delete Course By Id " << std::endl;
	std::cout << "<12> Back to Pervious Menu " << std::endl;
	std::cout << "<13> Exit " << std::endl;
	std::cout << "================================\n: ";

	std::cin>>input;
	return input;

}

void profile() {
	tools::viewAllStuds();
	std::cout<<"Enter the student Id to edit: ";
	int sutdId;
	std::cin>>sutdId;
	
	if (tools::searchStud(sutdId).getFullName() != ""){
		std::string fullName;
		int age;
		char temp;
		
		std::cout<<"Enter the Full Name: ";
		std::cin.ignore();
		std::getline(std::cin, fullName);

		std::cout<<"Enter the Age: ";
		std::cin>>age;

		std::cout<<"Enter the gender (M or F): ";
		std::cin>>temp;
		Gender gneder = (temp == 'M')?MALE:FIMALE;

		tools::updateStud(sutdId, fullName, age, gneder);
		std::cout<<"\nSuccessfully Updated!\n\n";
	}
	else {
		std::cout<<"The student doesn't exit in the database!\n";
	}
}

void registerForCourse() {
	tools::viewAllStuds();
	std::cout<<"Enter the student Id to you want to add course: ";
	int sutdId;
	std::cin>>sutdId;

	if (tools::searchStud(sutdId).getFullName() != ""){
		tools::viewAllCourses();
		std::cout<<"Enter the course Id to get registed: ";
		std::string cId;
		std::cin>>cId;
		if (tools::searchCourese(cId).getCId() != "" ) {
			tools::addCourseForStud(sutdId, tools::searchCourese(cId));
			std::cout<<"\nSuccessfully added!\n\n";
		}
		else {
			std::cout<<"Course doesn't exsit!\n\n";
		}

	}
	else {
		std::cout<<"The student doesn't exit in the database!\n";
	}

}

void dropCourse() {
	tools::viewAllStuds();
	std::cout<<"Enter the student Id to you want to drop course: ";
	int sutdId;
	std::cin>>sutdId;

	if (tools::searchStud(sutdId).getFullName() != ""){
		tools::viewAllCourses();
		std::cout<<"Enter the course Id to be droped: ";
		std::string cId;
		std::cin>>cId;
		if (tools::searchCourese(cId).getCId() != "" ) {
			tools::dropCourseForStud(sutdId, cId);
			std::cout<<"\nSuccessfully dropped!\n\n";
		}
		else {
			std::cout<<"Course doesn't exsit!\n\n";
		}


	}
	else {
		std::cout<<"The student doesn't exit in the database!\n";
	}
}


//Stuff Cases Handlers
void addStudent() {
	std::cout<<"Enter an new id : ";
	int id;
	std::cin>>id;
	std::cout<<"Enter the full name : ";
	std::string fullName;
	std::cin.ignore();
	std::getline(std::cin, fullName);
	std::cout<<"Enter the age: ";
	unsigned int age;
	std::cin>>age;
	std::cout<<"Enter the gender(M or F) : ";
	char temp;
	std::cin>>temp;
	Gender gender = (temp == 'M')?MALE:FIMALE;

	std::vector<Course>* registeredCourses = new std::vector<Course>();

	Student new_stud(id, fullName, age, gender, registeredCourses);
	tools::addStud(new_stud);
		std::cout<<"\nSuccessfully Added!\n";
}

void addCourse(){
	std::cout<<"Enter the course Id : ";
	std::string courseId;
	std::cin.ignore();
	std::getline(std::cin, courseId);
	std::cout<<"Enter the Course titile : ";
	std::string courseTitle;
	std::getline(std::cin, courseTitle);
	std::cout<<"Enter the CreditHour : ";
	int creditHour;
	std::cin>>creditHour;

	Course new_course(courseId, courseTitle, creditHour);
	tools::addCourse(new_course);
	std::cout<<"\nSuccessfully Added!\n";

}
void editStud() {
	profile();
}
void editCourse() {
	tools::viewAllCourses();
	std::cout<<"Enter the course Id you want to edit : ";
	std::string courseId;
	std::cin.ignore();
	std::getline(std::cin, courseId);
	std::cout<<"Enter the Title to overide : ";
	std::string title;
	std::getline(std::cin, title);
	std::cout<<"Enter the crediHour : ";
	int creditHour;
	std::cin>>creditHour;

	tools::updateCourse(courseId, title, creditHour);
	std::cout<<"\nSuccessfully updated!\n";
}

void searchStudForCourse(){
	tools::viewAllCourses();
	std::cout<<"Enter the course Id : ";
	std::string courseId;
	std::cin.ignore();
	std::getline(std::cin, courseId);

	std::vector<Student>* studs = tools::searchStudForCourse(courseId);

	tools::studHeader();
	tools::printStuds(studs);
    printf("=======================================================================================================================\n\n\n");

	delete studs;
}

void searchStud(){
	std::cout<<"Enter the Student Id : ";
	int studId;
	std::cin>>studId;

	Student stud = tools::searchStud(studId);
	std::vector<Student>* studs = new std::vector<Student>();


	tools::studHeader();

	if (stud.getFullName() != "") {
				studs->push_back(stud);
			tools::printStuds(studs);
	}
	printf("=======================================================================================================================\n\n\n");
	delete studs;
}
void searchCourse(){
	std::cout<<"Enter the course Id : ";
	std::string cId;
	std::cin.ignore();
	std::getline(std::cin, cId);

	tools::courseHeader();
	Course course = tools::searchCourese(cId);
	if (course.getTitle() != "") {
	printf("%-15s\t%-45s%-10d\n",
			course.getCId().c_str(),
			course.getTitle().c_str(),
			course.getCreditHour()
		);
	}
    printf("========================================================================\n\n\n");
	
}
void deleteCourse(){
	tools::viewAllCourses();
	std::cout<<"Enter the course Id to delete : ";
	std::string courseId;
	std::cin.ignore();
	std::getline(std::cin, courseId);
	if (tools::deleteCourse(courseId)) {
		std::cout <<"\nCourse deleted successfully!\n";
	}
	else {
		std::cout<<"Invalid course Id!\n";
	}
}

void deleteStud(){
	tools::viewAllStuds();
	std::cout<<"Enter the student Id : ";
	int studId;
	std::cin>>studId;

	if(tools::deleteStud(studId)) {
		std::cout<<"Student deleted Successfully!\n";
	}
	else {
		std::cout<<"Invalid student id\n";
	}
}