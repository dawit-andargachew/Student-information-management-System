#ifndef COURSE_FILE_H
#define COURSE_FILE_H

#include "file.h"
#include "course.h"
#include <vector>


class CourseFile: public File<Course>
{
public:
    CourseFile(std::string dir, char mode) 
        : File(dir, mode){
    }

    std::vector<Course>* read() {

        std::string buffer;
        
        std::vector<std::string> objData;

        while(!inFile.eof()) {
            std::getline(inFile, buffer);

            if (!buffer.empty()) {
                objData = split(buffer, ',');

                data->push_back(Course(objData.at(0), objData.at(1), std::stoi(objData.at(2))));
                objData.clear();
            }
        }

        inFile.close();
        return data;
        
    }


    bool write(std::vector<Course>* data) {

        std::string coursesRegistered = "";

        for (int i = 0; i < data->size(); i++) {
            outFile << data->at(i).getCId() <<",";
            outFile << data->at(i).getTitle() <<",";
            outFile << data->at(i).getCreditHour() <<"\n";
        }

        outFile.close();
    
    return true;
    }

};


#endif