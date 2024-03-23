#include <iostream>
using namespace std;

class Student{
    int grade;
    
    public:
        // constructor
        Student(int grade, string school){
            this->grade = grade;
            this->school = school;
        };
        // setter
        void set_grade(int n){
            this->grade = n;
        };
        
        // getter
        int get_grade(){
            return this->grade;
        };
        string school;
        void do_work();
    
};

// inheritance
// ND Student isa public Student
class NDStudent : public Student{
    public:
        int NDID;
        NDStudent(int grade, string school) : Student(grade, school) {}
};

// define method outside class
void Student::do_work(){
    cout << "doing work" << endl;
}

int main() {
    Student std1(100, "ND");
    
    cout << std1.get_grade() << endl;
    cout << "setting grade" << endl;
    std1.set_grade(80);
    cout << std1.get_grade() << endl;
    cout << std1.school << endl;
    std1.do_work();
        
    NDStudent std2(100, "ND");
    
    std2.NDID = 123456789;
    cout << std2.NDID << endl;
    
    return 0;
}
