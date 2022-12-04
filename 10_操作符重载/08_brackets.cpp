/**
 * 括号重载 -> 用于比较
 */

#include <iostream>
using namespace std;

class Bracket
{
public:
  int operator()(int x, int y)
  {
    return x > y ? x : y;
  }
  int operator()(int x, int y, char oper)
  {
    if (oper == '+')
    {
      return x + y;
    }
    return x-y;
  }
  void operator()(void)
  {
    cout << "nothing" << endl;
  }

};

int main()
{
  Bracket bt;
  cout << bt(1, 2) << endl; // bracket.operator()(a,b)
  cout << bt(1, 3, '-') << endl; 
  return 0;
}