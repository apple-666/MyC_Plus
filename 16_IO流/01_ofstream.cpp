/*
文件流的打开输出流:
  ofstream
*/

#include <iostream>
#include <fstream>
using namespace std;

void PrintError(const char *filename, int linenum, const char *errinfo)
{
  cerr << "[Error-" << filename << ":" << linenum << "行 ] " << errinfo << endl;
}

int main()
{
  ofstream ofs1("./a1.txt", ios::out); // out打开会重开
  if (!ofs1)
  {
    // FILE当前文件,LINE当前行
    PrintError(__FILE__, __LINE__, "ofs1流对象状态错误:打开文件失败");
  }
  ofs1 << 111 << " " << 211 << " apple" << '\n';
  if (!ofs1)
  { // ! ofs1.operator bool( )
    PrintError(__FILE__, __LINE__, "ofs1流对象状态错误:写文件失败");
  }
  ofs1.close();

  ofstream ofs2("./a2.txt", ios::app); // 追加
  if (!ofs2)
  { // ! ofs2.operator bool( )
    PrintError(__FILE__, __LINE__, "ofs2流对象状态错误:打开文件失败");
  }
  ofs2 << "world" << endl;
  if (!ofs2)
  { // ! ofs2.operator bool( )
    PrintError(__FILE__, __LINE__, "ofs2流对象状态错误:写文件失败");
  }
  ofs2.close();

  return 0;
}