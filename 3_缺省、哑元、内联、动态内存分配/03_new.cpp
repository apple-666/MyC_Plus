// 动态( 堆 )内存分配
#include <iostream> 
#include <cstdlib>
using namespace std;

// c 的 malloc + free
// C++ 的new + delete


int main( void ) {
    int* pm = (int*)malloc( 4 ); // malloc 返回地址的首位置
    cout << "*pm=" << *pm << endl;
    free( pm ); // 当这行代码执行结束,pm指向的内存被释放,pm变为野指针
    pm = NULL;
    free( pm ); // 不能连续double free，给free传递的参数为野指针,释放野指针会段错误,释放空指针是安全的


    // c++ 的new delete
    int* headerN = new int;
    // int* headerN = new int(40); 
    cout<<"headerN1:"<<*headerN<<endl; // 和malloc的地址一样
    delete headerN;
    cout<<"headerN2:"<<headerN<<endl;
    headerN = NULL;
    cout<<"headerN3:"<<headerN<<endl;
    delete headerN; // 不能连续double delete,给delete传递的参数为野指针,释放野指针会段错误,释放空指针是安全的

    // 会申请4+1个位置。第一个位置是size，后面是数据
    int* parr = new int[4]{ 10,20,30,40 }; // 返回第一个元素的地址
    for( int i=0; i<4; i++ )
        cout << parr[i] << ' ';
    cout << endl;
    delete[] parr; // []告诉delete操作对parr做一个减4字节操作（第一个位置是放size的），获取整个堆内存的首地址，然后一并释放

    int(*p)[4] = new int[3][4]; // 返回第一个元素的地址，是个一维数组指针
    //eg: int (*p)[2][3] = new int[10][2][3]
    delete[] p; // []告诉delete操作对parr做一个减4字节操作，获取整个堆内存的首地址，然后一并释放

    try {
        new int[0xFFFFFFFF]; // 十六g 的内存 要做异常处理，不然系统会捕获new的错误
    }
    catch( ... ) {
        // ...
    }
    return 0;
}

