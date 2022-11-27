#include <iostream>
using namespace std;

int main( void ) {
    int a;  double b;   float c;    short d;    char e;
    // 任何 基本类型的变量 之间都可以隐式转换
    a = b = c = d = e;
    e = d = c = b = a;
    // 任何其他类型的指针 到 void* 都可以隐式转换。void* 的为小限制
    void* pv = &a;
    pv = &b;
    pv = &c;
    pv = &d;
    pv = &e;
    // void* 到 任何其他类型的指针 都必须强转
    int* pa = static_cast<int*>(pv);
    double* pb = static_cast<double*>(pv);
    float* pc = static_cast<float*>(pv);
    short* pd = static_cast<short*>(pv);
    char* pe = static_cast<char*>(pv);
    // 任何类型的非常指针 到 同类型的常指针 都可以隐式转换,降级不需要强制转换
    const int* cpa = pa;
    const double* cpb = pb;
    const float* cpc = pc;
    const short* cpd = pd;
    const char* cpe = pe;
    // 任何类型常指针 到 同类型的非常指针 都必须强转。因为限制从小到大，要升级。
    pa = const_cast<int*>(cpa); // 专业去掉指针常属性
    pb = const_cast<double*>(cpb);
    pc = const_cast<float*>(cpc);
    pd = const_cast<short*>(cpd);
    pe = const_cast<char*>(cpe);
    // 除了void*以外，其他类型指针之间都必须强转
    // int* 到 double*
    pa = reinterpret_cast<int*>(pb);
    pa = reinterpret_cast<int*>(1111);

    return 0;
}






