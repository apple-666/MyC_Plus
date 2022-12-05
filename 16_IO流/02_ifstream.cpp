/*
文件流的输入流:
  ifstream
*/
#include <iostream>
#include <fstream>
using namespace std;

void PrintError(const char *filename, unsigned int linenum, const char *errinfo)
{
  cerr << "[Error-" << filename << ":" << linenum << "] " << errinfo << endl;
}
int main(void)
{
  ifstream ifs1("./a1.txt", ios::in);
  if (!ifs1)
  { // ! ifs1.operator bool( )
    PrintError(__FILE__, __LINE__, "ifs1流对象状态错误:打开文件失败");
  }
  int i;
  double d;
  string s1, s2;
  ifs1 >> i >> d >> s1;
  if (!ifs1)
  { // ! ifs1.operator bool( )
    PrintError(__FILE__, __LINE__, "ifs1流对象状态错误:读文件失败");
  }
  ifs1.close();
  cout << i << ' ' << d << ' ' << s1 << endl;



  ifstream ifs2("./a1.txt", ios::ate);
  if (!ifs2)
  { // ! ifs2.operator bool( )
    PrintError(__FILE__, __LINE__, "ifs2流对象状态错误:打开文件失败");
  }

  ifs2.seekg(0, ios::beg); // 修改读指针位置

  int ii;
  double dd;
  string ss1, ss2;
  ifs2 >> ii >> dd >> ss1  ;
  if (!ifs2)
  { // ! ifs2.operator bool( )
    PrintError(__FILE__, __LINE__, "ifs2流对象状态错误:读文件失败");
  }
  ifs2.close();
  cout << ii << ' ' << dd << ' ' << ss1 <<   endl;

  return 0;
}
