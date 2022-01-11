#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "course.h"

enum Gender {
 MALE, FIMALE
};

class Student
{
private:
    unsigned int id;
    std::string fullName;
    unsigned int age;
    Gender gender;
    std::vector<Course>* registeredCourses;



public:
    Student(unsigned int id,
        std::string fullName,
        unsigned int age,
        Gender gender,
        std::vector<Course>* registeredCourses
    );

    Student(Student&& source);
    Student(const Student& source);

    int getId() const;
    const std::string& getFullName() const;
    unsigned int getAge() const;
    Gender getGender() const;
    std::vector<Course>* getCoursesRegistered() const;

    bool setId(unsigned int id);
    bool setFullName(std::string fullName);
    bool setAge(unsigned int age);
    bool setGender(Gender gender);
    bool setRegisteredCourses(std::vector<Course>* registeredCourses);

    ~Student();
};


#endif