/*
��buffer �߶���д buffer���ܴ������ֽ���
read(char *buffer,size)
write(char *buffer,size)

�ܽ᣺�߶���д�˷��� io��������,����һ��
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
  ofstream ofs("./to.txt", ios::out); //���
  if (!ofs)
  {
    PrintError(__FILE__, __LINE__, "���ļ�ʧ��");
  }
  ifstream ifs("./from.txt", ios::in);
  if (!ifs)
  {
    PrintError(__FILE__, __LINE__, "���ļ�ʧ��");
  }

  char buffer[3]; // buffer���ܴ������ֽ���
  while(ifs.read(buffer, 3)){ 
    ofs.write(buffer, 3);
  }
  size_t len = ifs.gcount();
  ofs.write(buffer,len);
  ofs.close();
  ifs.close();
  return 0;
}