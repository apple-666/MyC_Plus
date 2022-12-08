/*
push_back  将对象拷贝一份放进容器,原的删除
重载自定义类的 升序降序 sort
*/

#include <iostream>
#include <deque>
#include <algorithm> //   find/sort

using namespace std;

class Student
{
public:
  Student(const char *name1 = "null", const int age1 = 1) : name(name1), age(age1) {}
  Student(const Student &that) : name(that.name), age(that.age) {}
  ~Student() {}
  bool operator==(Student const &that) const
  {
    return name == that.name && age == that.age;
  }
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

void print(deque<Student> s)
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
  deque<Student> ds;
  typedef deque<Student>::iterator IT;
  ds.push_front(Student("apple", 22));
  ds.push_front(Student("apple2", 23));
  ds.push_front(Student("apple3", 24));
  ds.push_back(Student("apple4", 25));

  ds.insert(ds.begin(), Student("newApple", 1));
  ds.insert(ds.begin() + 2, Student("newApple", 1));

  ds.erase(ds.begin() + 2);
  ds.erase(ds.begin());

  IT idx = ds.begin() + 1;
  *idx = Student("newApple", 22);

  IT findidx = find(ds.begin(), ds.end(), Student("newApple", 22));
  if (findidx == ds.end())
    cout << "没有找到" << endl;
  else
    cout << "找到了" << *findidx << endl;
  print(ds);
  
  ds.pop_front();
  print(ds);
  ds.pop_back();
  print(ds);

  ds[1] = Student("newApple",222);
  print(ds);

  return 0;
}