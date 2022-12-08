#include <iostream>
#include <map>

using namespace std;

class Student
{
public:
  Student(const char *name1 = "", const int &age1 = 0) : name(name1), age(age1) {}

private:
  string name;
  int age;
  friend ostream &operator<<(ostream &os, Student &stu);
};

ostream &operator<<(ostream &os, Student &stu)
{
  os << stu.name << " " << stu.age;
  return os;
}

void print(map<string, Student> mp)
{
  for (auto &i : mp)
  {
    cout << i.first << " " << i.second << endl;
  }
  cout << endl;
}

// 候选人
class Candidate
{
public:
  Candidate(string name1 = "") : name(name1), cnt(0) {}
  string name;
  int cnt;
};

int main()
{

  Student stu("apple", 22);

  // 默认按照 key 升序
  map<string, Student> mp{
      {"01", Student("apple", 22)},
      {"02", Student("pear", 23)},
      {"00", Student("water", 111)}};

  mp.insert({"04", Student("pear", 213)});
  mp["05"] = Student("melon", 222);
  print(mp);

  typedef map<string, Student>::iterator MIT;
  MIT i = mp.begin();
  cout << (*i).first << " " << (*i).second << endl;
  cout << endl;

  mp.erase("00");
  mp.erase("01");
  print(mp);

  cout << "--------------实现 选举候选人功能--------" << endl;
  Candidate c1("apple");
  Candidate c2("pear");
  map<char, Candidate> c_mp;
  c_mp['A'] = c1;
  c_mp['B'] = c2;
  c_mp['C'] = Candidate("water");
  // 老师的写法
  // typedef map<char, Candidate>::iterator CIT;
  // for (int i = 0; i <3; i++)
  // {
  //   for (auto &j : c_mp)
  //   {
  //     cout << '(' << j.first << ')' << j.second.name << endl;
  //   }
  //   cout<<endl;
  //   char wt;cin>>wt;
  //   CIT it = c_mp.find(wt);
  //   if(it != c_mp.end()) {
  //     ++(*it).second.cnt;
  //   }else {
  //     cout<<"查无此人;;;"<<endl;
  //   }
  // }
  // for(auto const& i:c_mp){
  //   cout<<i.first << " " << i.second.name <<" "<<i.second.cnt<< endl;
  // }

  // 我的写法
  for (int i = 0; i < 3; i++)
  {
    for (auto &j : c_mp)
    {
      cout << '(' << j.first << ')' << j.second.name << endl;
    }
    cout << endl;
    char wt;
    cin >> wt;
    if(c_mp.count(wt)) {
      c_mp[wt].cnt++;
    }else {
      cout<<"查无此人"<<endl;
    }
  }
  for (auto const &i : c_mp)
  {
    cout << i.first << " " << i.second.name << " " << i.second.cnt << endl;
  }
  return 0;
}