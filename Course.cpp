#include "Admin.h"
#include "Student.h"
#include "Course.h"
unordered_map<string, Course*> courses;
Course::Course(string name, string id, int length) {
    Name = name;
    Id = id;
    Length = length;
    courses[Name] = this;
}