/*
push_back  �����󿽱�һ�ݷŽ�����,ԭ��ɾ��
*/

#include <iostream>
#include <vector>

using namespace std;

class Student
{
public:
  Student(const char *name1 = "null") : name(name1)
  {
    cout << "ȱʡ������" << name << "(" << this << ")" << endl;
  }
  Student(const Student &that) : name(that.name)
  {
    cout << "�ã�" << that.name << "(" << &that << ")"
             << "����������" << name << "(" << this << ")" << endl;
  }
  ~Student()
  {
    cout << "������" << name << "(" << this << ")" << endl;
  }

private:
  string name;
};

int main()
{
  vector<Student> students;
  cout << "������" << students.capacity() << endl;

  students.push_back(Student("apple")); 
  cout << "������" << students.capacity() << endl;

  students.push_back(Student("apple2"));
  cout << "������" << students.capacity() << endl;
  return 0;
}