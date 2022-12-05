/*
��ios::end���ļ�β,����tellg��ȡ��ָ��λ��,����buffer�Ĵ�Сȷ��,ֻҪһ��IO
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
  ifstream ifs("./from.txt", ios::ate); // ���һ���ֽڵ���һ��λ��
  if (!ifs)
  {
    PrintError(__FILE__, __LINE__, "���ļ�ʧ��");
  }

  size_t len = ifs.tellg(); //��ȡ��ָ��λ��
  char buffer[len]; // 
  // ����ָ��λ��
  ifs.seekg(0,ios::beg);
  ifs.read(buffer, len);
  ofs.write(buffer, len);

  ofs.close();
  ifs.close();
  return 0;
}