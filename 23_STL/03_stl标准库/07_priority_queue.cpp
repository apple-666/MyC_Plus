#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Student
{
public:
    Student(int age1 = 0, string const &name1 = "") : age(age1), name(name1) {}
    bool operator>(Student const& that)const{
        return age>that.age;
    }
    bool operator<(Student const& that)const{
        return age<that.age;
    }
private:
    int age;
    string name;
    friend ostream &operator<<(ostream &os, Student const &stu);
};

ostream &operator<<(ostream &os, Student const &stu)
{
    os << stu.age << " " << stu.name;
    return os;
}

int main()
{

    // deque<int> 作为底层容器也行
    // 默认是less<int> 降序   greater<int> 升序弹出（更大的在底部）
    priority_queue<int, vector<int>, greater<int>> pq;
    priority_queue<int, vector<int>> pq2;
    // priority_queue<int> pq3;
    priority_queue<int, vector<int>, greater<int>> pq3;

    pq3.push(111);
    pq3.push(1);
    pq3.push(1111);
    while (!pq3.empty())
    {
        cout << pq3.top() << ' ';
        pq3.pop();
    }
    cout<<endl;

    priority_queue<Student> pst;
    pst.push(Student(21, "apple"));
    pst.push(Student(24, "apple2"));
    pst.push(Student(2, "apple3"));

    while (!pst.empty())
    {
        cout << pst.top() << ' ';
        pst.pop();
    }

    return 0;
}
