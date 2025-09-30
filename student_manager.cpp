#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    students[num_of_students++] = Student(name, id, midterm, final);
}

void StudentManager::deleteStudent(int id) {
    /* TODO */
    int idx = findStudentByID(id);

    if(idx != -1){
        for(int i = idx; i < num_of_students - 1; i++){
            students[i] = students[i + 1];
        }
        num_of_students--;
    }

}

void StudentManager::modifyStudent(const Student& student) {

    int idx = findStudentByID(student.getID());

    if(idx != -1){
        students[idx] = student;
    }
}

int StudentManager::findStudentByID(int id) const {
    /* TODO */

    for(int i = 0; i < num_of_students; i++){
        if(students[i].getID() == id){
            return i;
        }
    }

    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    float max = 0;
    int max_student = -1;

    for(int i = 0 ; i < num_of_students; i++){
        StudentRecord sr = students[i].getRecord();
        
        if(sr.getMidterm() > max){
            max = sr.getMidterm();
            max_student = students[i].getID();
        }
    }

    return max_student;
}

int StudentManager::findBestStudentInFinal() const {
    float max = 0;
    int max_student = -1;

    for(int i = 0 ; i < num_of_students; i++){
        StudentRecord sr = students[i].getRecord();
        
        if(sr.getFinal() > max){
            max = sr.getFinal();
            max_student = students[i].getID();
        }
    }

    return max_student;
}

int StudentManager::findBestStudent() const {
    float max = 0;
    int max_student = -1;

    for(int i = 0 ; i < num_of_students; i++){
        StudentRecord sr = students[i].getRecord();
        
        if(sr.getFinal() + sr.getMidterm() > max){
            max = sr.getFinal() + sr.getMidterm();
            max_student = students[i].getID();
        }
    }

    return max_student;
}

float StudentManager::getMidtermAverage() const {
    float sum = 0;

    for(int i = 0 ; i < num_of_students; i++){
        StudentRecord sr = students[i].getRecord();
        sum += sr.getMidterm();
    }

    sum = sum / (float)num_of_students;

    return sum;
}

float StudentManager::getFinalAverage() const {
    float sum = 0;

    for(int i = 0 ; i < num_of_students; i++){
        StudentRecord sr = students[i].getRecord();
        sum += sr.getFinal();
    }

    sum = sum / (float)num_of_students;

    return sum;
}

float StudentManager::getTotalAverage() const {
    float sum = 0;

    for(int i = 0 ; i < num_of_students; i++){
        StudentRecord sr = students[i].getRecord();
        sum += sr.getFinal() + sr.getMidterm();
    }

    sum = sum / (float)num_of_students;

    return sum;
}

