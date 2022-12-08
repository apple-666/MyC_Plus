/*
push_back  �����󿽱�һ�ݷŽ�����,ԭ��ɾ��
�����Զ������ ������ sort
*/

#include <iostream>
#include <vector>
#include <algorithm> //   find/sort

using namespace std;

class Student
{
public:
  Student(const char *name1 = "null", const int age1 = 1) : name(name1), age(age1) {}
  Student(const Student &that) : name(that.name), age(that.age) {}
  ~Student() {}
  bool operator<(const Student &that) const
  {
    return age < that.age;
  }
  bool operator>(const Student &that) const
  {
    return age > that.age;
  }

private:
  string name;
  int age;
  friend ostream &operator<<(ostream &os, const Student &that);
};

ostream &operator<<(ostream &os, const Student &that)
{
  os << that.name << " " << that.age;
  return os;
}

void print(vector<Student> s)
{
  // ����һ
  // typedef vector<Student>::iterator IT;
  // for (IT i = s.begin(); i != s.end(); i++)
  //   cout << *i << endl; // ����<<

  // ������
  for (auto &i : s)
    cout << i << "----"; // ���������ܸ���
  cout << endl;
}

int main()
{
  vector<Student> students;
  students.push_back(Student("apple", 22));
  students.push_back(Student("����", 20));
  students.push_back(Student("����", 27));
  students.push_back(Student("����", 18));
  students.insert(++students.begin(), Student("����", 21));
  print(students);

  students.erase(students.begin());
  print(students);
  print(students);

  sort(students.begin(), students.end());
  cout << "���������< ����󡪡�----------" << endl;
  print(students);

  sort(students.begin(), students.end(), greater<Student>());
  cout << "���������> ����󡪡�----------" << endl;
  print(students);
  return 0;
}