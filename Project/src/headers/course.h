#ifndef COURSE_H
#define COURSE_H

#include <string>


class Course
{
private:
    std::string cId;
    std::string title;
    int creditHour;

public:
    Course(std::string, std::string, int);
    const std::string& getCId() const;
    const std::string& getTitle() const;
    int getCreditHour() const;

    bool setCId(std::string cId);
    bool setTitle(std::string title);
    bool setCreditHour(int creditHour);

    ~Course();
};

#endif
