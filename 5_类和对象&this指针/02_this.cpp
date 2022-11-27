// this 参数
#include <iostream> 
#include <cstring>
using namespace std;
// 在此程序中有两个对象(h/h2)每个对象都有一份成员变量(共有两份成员变量),而成员函数只有一份(代码段)
class Human{
public:
    void setinfo(int age,const char* name) {
        this->age = age;
        strcpy(this->name,name);
    }
    void getinfo(){
        cout<<"getinfo age="<<this->age<<" name="<<this->name<<endl;
    }
private:
    int age;
    char name[200];
};

// 以上代码模拟的是类的设计者(例如: 类库、别人设计的类、自己设计的类)
// ---------------------------------------
// 以下代码模拟的是用户

int main( void ) {
    Human h1 ;
    h1.setinfo(22,"apple");
    h1.getinfo();
    return 0;
}

