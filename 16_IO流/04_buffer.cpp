/*
放入缓存区:put
缓存区到设备:flush 强制
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
  ofstream ofs("./a3.txt", ios::out);
  if (!ofs)
  { // ! ofs.operator bool()
    PrintError(__FILE__, __LINE__, "ofs流对象状态错误:打开文件失败");
  }
  for (char c = ' '; c <= '~'; c++)
  {
    ofs.put(c);  // 将c中的数据写入ofs流对象维护的 流缓冲区
    ofs.flush(); // 强制将ofs流对象维护的流缓冲区中的数据 刷到 目标设备
  }

  ifstream ifs("./a3.txt", ios::in);
  if (!ifs)
  { // ! ifs.operator bool( )
    PrintError(__FILE__, __LINE__, "ifs流对象状态错误:打开文件失败");
  }
  char c;
  // 单参get
  while (ifs.get(c))
  { // 读取一个字符，是否成功读取了一个字符通过将流对象放在bool上下文中来判断
    cout << c;
  }
  cout << endl;
  cout << "ifs流对象具体状态值: " << ifs.rdstate() << endl;


  cout<<"ifs流对象清空"<<endl;
  cout<<"ifs流对象清空"<<endl;
  cout<<"ifs流对象清空"<<endl;
  ifs.clear(); // 要清空+重置位置才能 读
  ifs.seekg(0, ios::beg);
  // 无参get
  while ((c = ifs.get()) != EOF) // EOF代表读完了
  {
    cout << c;
  }
  cout << endl;
  ifs.close();
  ofs.close();
}
