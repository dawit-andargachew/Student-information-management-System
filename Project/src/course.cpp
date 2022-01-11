#include "headers/course.h"

Course::Course(std::string cId, std::string title, int creditHour)
    : cId(cId), title(title), creditHour(creditHour){

}

const std::string&  Course::getCId() const{
    return this->cId;
}

const std::string& Course::getTitle() const{
    return this->title;
}

int Course::getCreditHour() const{
    return this->creditHour;
}


bool Course::setCId(std::string cId){
    this->cId = cId;
    return true;
}
bool Course::setTitle(std::string title) {
    this->title = title;
    return true;
}
bool Course::setCreditHour(int creditHour) {
    this->creditHour = creditHour;
    return true;
}
    
Course::~Course() {

}