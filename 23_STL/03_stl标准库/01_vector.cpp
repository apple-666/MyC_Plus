/*
push_back  将对象拷贝一份放进容器,原的删除
*/

#include <iostream>
#include <vector>

using namespace std;

class Student
{
public:
  Student(const char *name1 = "null") : name(name1)
  {
    cout << "缺省构造了" << name << "(" << this << ")" << endl;
  }
  Student(const Student &that) : name(that.name)
  {
    cout << "用：" << that.name << "(" << &that << ")"
             << "拷贝构造了" << name << "(" << this << ")" << endl;
  }
  ~Student()
  {
    cout << "析构了" << name << "(" << this << ")" << endl;
  }

private:
  string name;
};

int main()
{
  vector<Student> students;
  cout << "容量：" << students.capacity() << endl;

  students.push_back(Student("apple")); 
  cout << "容量：" << students.capacity() << endl;

  students.push_back(Student("apple2"));
  cout << "容量：" << students.capacity() << endl;
  return 0;
}