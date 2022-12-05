/*
先ios::end读文件尾,再用tellg获取读指针位置,这样buffer的大小确定,只要一次IO
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
  ofstream ofs("./to.txt", ios::out); //清空
  if (!ofs)
  {
    PrintError(__FILE__, __LINE__, "打开文件失败");
  }
  ifstream ifs("./from.txt", ios::ate); // 最后一个字节的下一个位置
  if (!ifs)
  {
    PrintError(__FILE__, __LINE__, "打开文件失败");
  }

  size_t len = ifs.tellg(); //获取读指针位置
  char buffer[len]; // 
  // 重置指针位置
  ifs.seekg(0,ios::beg);
  ifs.read(buffer, len);
  ofs.write(buffer, len);

  ofs.close();
  ifs.close();
  return 0;
}