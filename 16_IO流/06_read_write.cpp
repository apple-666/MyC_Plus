/*
用buffer 边读边写 buffer不能大于总字节数
read(char *buffer,size)
write(char *buffer,size)

总结：边读边写此方法 io次数过多,性能一般
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
  ifstream ifs("./from.txt", ios::in);
  if (!ifs)
  {
    PrintError(__FILE__, __LINE__, "打开文件失败");
  }

  char buffer[3]; // buffer不能大于总字节数
  while(ifs.read(buffer, 3)){ 
    ofs.write(buffer, 3);
  }
  size_t len = ifs.gcount();
  ofs.write(buffer,len);
  ofs.close();
  ifs.close();
  return 0;
}