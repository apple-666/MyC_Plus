#include <bits/stdc++.h>
#define fori(i, s, e) for (int i = s; i <= e; i++)
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;

const int N = 1e5 + 5;
int n;

// 使用namespace
namespace A
{
    int count = 0;
    void a1()
    {
        cout << 1 << endl;
    }
}

void global_a1()
{
    cout << "global" << endl;
}


// 定义表（main区域的变量）  可见表（namespace的，和main外部（全局）的变量）
// 定义表/ 可见表都不能重复申明
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    A::a1();
    global_a1();

    // 将A的变量引入当前main的作用域
    using A::count;
    cout<<count<<endl;


    return 0;
}
