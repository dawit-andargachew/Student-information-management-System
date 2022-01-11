#ifndef STUD_FILE_H
#define STUD_FILE_H

#include "file.h"
#include "student.h"
#include "course.h"
#include "course_file.h"
#include <vector>


class StudFile : public File<Student>
{

private:
    static std::vector<Course>* getRegisteredCourses(std::string rawCoursesIds) {

        std::vector<std::string> courseIds = split(rawCoursesIds, '|');
        std::vector<Course>* coursesRegistered = new std::vector<Course>();

        CourseFile courseReader("../data/Course.dat", 'r');

        std::vector<Course>* courses =  courseReader.read();

        for (int i = 0; i < courseIds.size(); i++) {
            for (int j = 0; j < courses->size(); j++) {
                if (courseIds.at(i) == ((courses->at(j)).getCId())) {
                    coursesRegistered->push_back(courses->at(j));
                }
            }
        }
        return coursesRegistered;
    }

public:
    StudFile(std::string dir, char mode)
        : File(dir, mode) {
    }


    std::vector<Student>* read() {

        std::string buffer;
        
        std::vector<std::string> objData;

        while(!inFile.eof()) {
            std::getline(inFile, buffer);

            if (!buffer.empty()){
                objData = split(buffer, ',');
                std::vector<Course>* registeredCourses = getRegisteredCourses(
                    objData[objData.size()-1]
                );

                data->push_back(Student(
                    std::stoi(objData.at(0)),
                    objData.at(1), std::stoi(objData.at(2)),
                    Gender(std::stoi(objData.at(3))),
                    registeredCourses
                    ));

                objData.clear();
            }
            
        }

        inFile.close();
        return data;

    }

    bool write(std::vector<Student>* data) {

        std::string coursesRegistered = "";
        int courseSize;
        
        for (int i = 0; i < data->size(); i++) {
            outFile << data->at(i).getId() <<",";
            outFile << data->at(i).getFullName() <<",";
            outFile << data->at(i).getAge() <<",";
            outFile << data->at(i).getGender() <<",";

            courseSize = data->at(i).getCoursesRegistered()->size();

            for (int j = 0; j < courseSize; j++) {
                if (j == (courseSize-1)) {
                    coursesRegistered += data->at(i).getCoursesRegistered()->at(j).getCId();
                }
                else
                    coursesRegistered += data->at(i).getCoursesRegistered()->at(j).getCId() + "|";
            }

            outFile << coursesRegistered << "\n";
            coursesRegistered = "";    
        }

    outFile.close();
    
    return true;
    }

};


#endif