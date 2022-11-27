// 必须自己显示写 this的情况
// class中function 形参列表中 隐式的假了指针： YourClass* this
#include <iostream>
using namespace std;

class Float
{
public:
    void setinfo(float i)
    {
        this->i = i;
    }
    void getinfo()
    {
        void PrintMy(Float i);

        PrintMy(*this);
        cout << this->i << endl;
    }
    // Float& 别名为本身，所以可以串联调用
    Float &increment(/* Float* this */)
    {
        this->i = this->i + 1.5; // 这里是 float型
        return *this;            // 需要返回一个class类型，所以不能用this->i
    }

private:
    float i;
};

void PrintMy(Float i)
{
    cout << "print(传*this):" << endl;
}

// 以上代码模拟的是类的设计者(例如: 类库、别人设计的类、自己设计的类)
// ---------------------------------------
// 以下代码模拟的是用户
int main(void)
{
    Float f;
    f.setinfo(2.5);
    f.getinfo();
    f.increment().increment().increment();

    f.getinfo();
    return 0;
}
