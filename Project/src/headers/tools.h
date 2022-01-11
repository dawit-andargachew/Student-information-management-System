
#pragma once

#include "course.h"
#include "student.h"
#include "course_file.h"
#include "stud_file.h"
#include "file.h"
#include <stdio.h>
#include <algorithm>

namespace tools {

    void viewAllCourses();
    bool addCourse(const Course& new_course);
    Course searchCourese(const std::string& courseId);
    Course searchCourese(const std::string&& courseId);
    bool updateCourse(const std::string& courseId, std::string& title, int creditHour);
    bool deleteCourse(const std::string& courseId);


    void viewAllStuds();
    bool addStud(const Student& new_stud);
    std::vector<Student>* searchStudForCourse(const std::string& courseId);
    Student searchStud(int studId);
    bool deleteStud(int studId);
    void printStuds(std::vector<Student>* studs);
    bool updateStud(int studId, std::string& fullName, unsigned int age, Gender gender);
    bool updateStud(int studId, std::string&& fullName, unsigned int age, Gender gender);
    bool addCourseForStud(int studId, Course& new_course);
    bool addCourseForStud(int studId, Course&& new_course);
    bool dropCourseForStud(int studId, std::string& courseId);
    bool dropCourseForStud(int studId, std::string&& courseId);

    void studHeader();
    void courseHeader();

}
