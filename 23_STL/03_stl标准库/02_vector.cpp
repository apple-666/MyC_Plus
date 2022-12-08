/*
push_back  将对象拷贝一份放进容器,原的删除
重载自定义类的 升序降序 sort
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
  // 方法一
  // typedef vector<Student>::iterator IT;
  // for (IT i = s.begin(); i != s.end(); i++)
  //   cout << *i << endl; // 重载<<

  // 方法二
  for (auto &i : s)
    cout << i << "----"; // 用引用性能更快
  cout << endl;
}

int main()
{
  vector<Student> students;
  students.push_back(Student("apple", 22));
  students.push_back(Student("李四", 20));
  students.push_back(Student("王五", 27));
  students.push_back(Student("马六", 18));
  students.insert(++students.begin(), Student("田七", 21));
  print(students);

  students.erase(students.begin());
  print(students);
  print(students);

  sort(students.begin(), students.end());
  cout << "重载运算符< 升序后——----------" << endl;
  print(students);

  sort(students.begin(), students.end(), greater<Student>());
  cout << "重载运算符> 降序后——----------" << endl;
  print(students);
  return 0;
}