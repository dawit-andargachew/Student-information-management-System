#include "headers/tools.h"

namespace tools {

    void courseHeader() {
        printf("\n\n========================================================================\n");
        printf("%-15s\t%-45s%-10s\n", "ID", "TITLE", "CREDITHOURS");
        printf("========================================================================\n");
    }


    bool addCourse(const Course& new_course) {

        CourseFile courseReader("../data/Course.dat", 'r');
        
        std::vector<Course>* courses = courseReader.read();
        courses->push_back(new_course);

        CourseFile courseWriter("../data/Course.dat", 'w');
        courseWriter.write(courses);

        return true;
        
    }

    void viewAllCourses() {

        CourseFile courseReader("../data/Course.dat", 'r');
        std::vector<Course> *courses = courseReader.read();

        courseHeader();

        for (const Course& course: *courses){
            printf("%-15s\t%-45s%-10d\n",
                course.getCId().c_str(),
                course.getTitle().c_str(),
                course.getCreditHour()
            );
        }
        printf("========================================================================\n\n\n");

    }

    Course searchCourese(const std::string& courseId) {

        CourseFile courseReader("../data/Course.dat", 'r');
        std::vector<Course>* courses = courseReader.read();

        for (int i = 0; i < courses->size(); i++) {
            if (courses->at(i).getCId() == courseId)
                return courses->at(i);
        }

        return Course("", "", 0);

    }

    Course searchCourese(const std::string&& courseId) {
        return searchCourese(courseId);
    }


    bool updateCourse(const std::string& courseId, std::string& title, int creditHour) {

        CourseFile courseReader("../data/Course.dat", 'r');
        std::vector<Course>* courses = courseReader.read();

        bool updated = false;

        for (Course& course: *courses) {
            if (course.getCId() == courseId) {
                course.setTitle(title);
                course.setCreditHour(creditHour);
                updated = true;
            }
        }

        CourseFile courseWriter("../data/Course.dat", 'w');
        courseWriter.write(courses);

        return updated;
    }


    bool deleteCourse(const std::string& courseId) {

        CourseFile courseReader("../data/Course.dat", 'r');
        std::vector<Course>* courses = courseReader.read();

        bool deleted = false;
        
        for (int i = 0; i < courses->size(); i++) {
            if (courses->at(i).getCId() == courseId) {
                courses->erase((courses->begin() + i));
                deleted = true;
            }
        }

        CourseFile courseWriter("../data/Course.dat", 'w');
        courseWriter.write(courses);

        return deleted;
    }



    void studHeader() {
        printf("\n\n=======================================================================================================================\n");
        printf("%-5s\t%-35s%-10s%-10s\t\t%-100s\n", "ID", "FULL NAME", "AGE", "GENDER", "REGISTERD COURSES");
        printf("=======================================================================================================================\n");
    }

    void printStuds(std::vector<Student>* studs) {
        for (const Student& stud: *studs) {

            std::vector<Course> *registeredCoures = stud.getCoursesRegistered();
            
            int size = registeredCoures->size();
            std::string courses = "";

            for (int j = 0; j < size; j++){
                if (j == size-1)
                    courses += registeredCoures->at(j).getCId();
                else
                    courses += registeredCoures->at(j).getCId() + ", ";
            }

            printf("%-5d\t%-35s%-10d%-10c\t\t%-100s\n",
                stud.getId(),
                stud.getFullName().c_str(),
                stud.getAge(),
                ((stud.getGender() == MALE)?'M':'F'),
                courses.c_str()
            );
        }
    }

    void viewAllStuds() {

        StudFile studReader("../data/Student.dat", 'r');
        std::vector<Student>* studs = studReader.read();

        studHeader();

        printStuds(studs);
        
        printf("=======================================================================================================================\n\n\n");

    }

    bool addStud(const Student& new_stud) {
        StudFile studReader("../data/Student.dat", 'r');
        std::vector<Student>* studs = studReader.read();

        studs->push_back(new_stud);

        StudFile studWriter("../data/Student.dat", 'w');
        studWriter.write(studs);

        return true;
    }


    std::vector<Student>* searchStudForCourse(const std::string& courseId) {
                
        StudFile studReader("../data/Student.dat", 'r');
        std::vector<Student>* studs = studReader.read();

        std::vector<Student>* searchResult = new std::vector<Student>();

        for (Student& stud: *studs) {
            for (Course& course: *stud.getCoursesRegistered()) {
                if (course.getCId() == courseId) {
                    searchResult->push_back(stud);
                    break;
                }
            }
        }

        return searchResult;
    }


    Student searchStud(int studId) {
        StudFile studReader("../data/Student.dat", 'r');
        std::vector<Student>* studs = studReader.read();

        for (Student& stud: *studs) {
            if (stud.getId() == studId) {
                return stud;
            }
        }

    return Student(0, "", 0, MALE, nullptr);

    }

    bool deleteStud(int studId) {
        StudFile studReader("../data/Student.dat", 'r');
        std::vector<Student>* studs = studReader.read();
        std::vector<Student>* new_studs = new std::vector<Student>();

        bool deleted = false;

        for (int i = 0; i < studs->size(); i++) {
            if (studs->at(i).getId() != studId) {
                new_studs->push_back(studs->at(i));
            }
            else {
                deleted = true;
            }
        }

        StudFile studWriter("../data/Student.dat", 'w');
        studWriter.write(new_studs);

        delete new_studs;
        return deleted;
        
    }

    bool updateStud(int studId, std::string& fullName, unsigned int age, Gender gender) {

        StudFile studReader("../data/Student.dat", 'r');
        std::vector<Student>* studs = studReader.read();

        bool updated = false;
        for (Student& stud: *studs) {
            if (stud.getId() == studId) {
                stud.setFullName(fullName);
                stud.setAge(age);
                stud.setGender(gender);
                updated = true;
            }
        }

        StudFile studWriter("../data/Student.dat", 'w');
        studWriter.write(studs);

        return updated;
    }

    bool updateStud(int studId, std::string&& fullName, unsigned int age, Gender gender) {
        return updateStud(studId, fullName, age, gender);
    }

    bool addCourseForStud(int studId, Course& new_course) {

        StudFile studReader("../data/Student.dat", 'r');
        std::vector<Student>* studs = studReader.read();

        bool added = false;

        for (Student& stud: *studs) {
            if ( studId == stud.getId()) {
                std::vector<Course>* coursesRegistered =  stud.getCoursesRegistered();
                coursesRegistered->push_back(new_course);
                added = true;
            }
        }

        StudFile studWriter("../data/Student.dat", 'w');
        studWriter.write(studs);

        return added;
    }

    bool addCourseForStud(int studId, Course&& new_course) {
        return addCourseForStud(studId, new_course);
    }

    bool dropCourseForStud(int studId, std::string& courseId) {

        StudFile studReader("../data/Student.dat", 'r');
        std::vector<Student>* studs = studReader.read();

        bool added = false;

        for (Student& stud: *studs) {
            if ( studId == stud.getId()) {
                std::vector<Course>* coursesRegistered =  stud.getCoursesRegistered();
                
                for (int i = 0; i < coursesRegistered->size(); i++) {
                    if (coursesRegistered->at(i).getCId() == courseId) {
                        coursesRegistered->erase((coursesRegistered->begin() + i));
                        added = true;
                    }
                }
            }
        }
        
        StudFile studWriter("../data/Student.dat", 'w');
        studWriter.write(studs);

        return added;
    }


    bool dropCourseForStud(int studId, std::string&& courseId) {
        return dropCourseForStud(studId, courseId);
    } 


}