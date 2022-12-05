/*
�ļ����Ĵ������:
  ofstream
*/

#include <iostream>
#include <fstream>
using namespace std;

void PrintError(const char *filename, int linenum, const char *errinfo)
{
  cerr << "[Error-" << filename << ":" << linenum << "�� ] " << errinfo << endl;
}

int main()
{
  ofstream ofs1("./a1.txt", ios::out); // out�򿪻��ؿ�
  if (!ofs1)
  {
    // FILE��ǰ�ļ�,LINE��ǰ��
    PrintError(__FILE__, __LINE__, "ofs1������״̬����:���ļ�ʧ��");
  }
  ofs1 << 111 << " " << 211 << " apple" << '\n';
  if (!ofs1)
  { // ! ofs1.operator bool( )
    PrintError(__FILE__, __LINE__, "ofs1������״̬����:д�ļ�ʧ��");
  }
  ofs1.close();

  ofstream ofs2("./a2.txt", ios::app); // ׷��
  if (!ofs2)
  { // ! ofs2.operator bool( )
    PrintError(__FILE__, __LINE__, "ofs2������״̬����:���ļ�ʧ��");
  }
  ofs2 << "world" << endl;
  if (!ofs2)
  { // ! ofs2.operator bool( )
    PrintError(__FILE__, __LINE__, "ofs2������״̬����:д�ļ�ʧ��");
  }
  ofs2.close();

  return 0;
}