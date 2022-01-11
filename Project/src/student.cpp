#include "headers/student.h"
#include <iostream>

Student::Student(unsigned int id,
    std::string fullName,
    unsigned int age,
        Gender gender,
        std::vector<Course>* registeredCourses) 
            : id(id),
            fullName(fullName),
            age(age), gender(gender),
            registeredCourses(registeredCourses)
{
}

Student::Student(const Student& source)
    : id(source.id),
        fullName(source.fullName),
        age(source.age),
        gender(source.gender)
    {
        registeredCourses = new std::vector<Course>();
        *registeredCourses = *(source.registeredCourses);
}


Student::Student(Student&& source) 
    : Student(
    source.id,
    source.fullName,
    source.age,
    source.gender,
    source.registeredCourses
    )
{ 
        source.registeredCourses = nullptr;
}


bool Student::setId(unsigned int id)
{
    this->id = id;
    return true;
}

bool Student::setFullName(std::string fullName)
{
    this->fullName = fullName;
    return true;
}

bool Student::setAge(unsigned int age) 
{
    this->age = age;
    return true;
}

bool Student::setGender(Gender gender) 
{
    this->gender = gender;
    return true;
}

bool Student::setRegisteredCourses(std::vector<Course>* registeredCourses) 
{
    delete this->registeredCourses;
    this->registeredCourses = registeredCourses;
    return true;
}



int Student::getId() const {
    return this->id;
}

const std::string&  Student::getFullName() const {
    return this->fullName;
}

unsigned int Student::getAge() const {
    return this->age;
}

Gender Student::getGender() const {
    return this->gender;
}

std::vector<Course>* Student::getCoursesRegistered() const{
    return this->registeredCourses;
}

Student::~Student(){
        delete registeredCourses;
    }