/*
file stream的状态
可以用函数取各自 或者求总和rdstate
good  0   一切正常
bad   1   发生致命错误    使用clear恢复
eof   2   遇到文件尾
fail  4   打开文件失败或读写字节数未达预期
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

  ifstream ifs2("./a1.txt", ios::ate);
  if (!ifs2)
  { // ! ifs2.operator bool( )
    PrintError(__FILE__, __LINE__, "ifs2流对象状态错误:打开文件失败");
  }

  int ii;
  double dd;
  string ss1;
  cout << "-----------第一次读文件-------------" << endl;
  ifs2 >> ii >> dd >> ss1  ;
  if (!ifs2)
  { // ! ifs2.operator bool( )
    PrintError(__FILE__, __LINE__, "ifs2流对象状态错误:读文件失败");
  }
  cout << "ifs2是0状态吗? " << ifs2.good() << ", ifs2是1状态吗? " << ifs2.bad()
       << ", ifs2是2状态吗? " << ifs2.eof() << ", ifs2是4状态吗? " << ifs2.fail() << endl;

  cout << "ifs2具体状态值: " << ifs2.rdstate() << endl;
  cout << ii << ' ' << dd << ' ' << ss1 << endl;

  cout << "-----------第二次读文件-------------" << endl;
  cout << "-----------第二次读文件-------------" << endl;
  cout << "-----------第二次读文件-------------" << endl;
  ifs2.clear(); // 流对象如果状态错误，需要复位为正常状态，然后在IO操作
  ifs2.seekg(0, ios::beg); // 设置到开始
  

  ifs2 >> ii >> dd >> ss1  ;
  if (!ifs2)
  { // ! ifs2.operator bool( )
    PrintError(__FILE__, __LINE__, "ifs2流对象状态错误:读文件失败");
  }
  cout << "ifs2是0状态吗? " << ifs2.good() << ", ifs2是1状态吗? " << ifs2.bad()
       << ", ifs2是2状态吗? " << ifs2.eof() << ", ifs2是4状态吗? " << ifs2.fail() << endl;

  cout << "ifs2具体状态值: " << ifs2.rdstate() << endl;
  cout << ii << ' ' << dd << ' ' << ss1   << endl;

  ifs2.close();
}