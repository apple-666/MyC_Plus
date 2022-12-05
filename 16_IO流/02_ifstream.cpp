/*
�ļ�����������:
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
    PrintError(__FILE__, __LINE__, "ifs1������״̬����:���ļ�ʧ��");
  }
  int i;
  double d;
  string s1, s2;
  ifs1 >> i >> d >> s1;
  if (!ifs1)
  { // ! ifs1.operator bool( )
    PrintError(__FILE__, __LINE__, "ifs1������״̬����:���ļ�ʧ��");
  }
  ifs1.close();
  cout << i << ' ' << d << ' ' << s1 << endl;



  ifstream ifs2("./a1.txt", ios::ate);
  if (!ifs2)
  { // ! ifs2.operator bool( )
    PrintError(__FILE__, __LINE__, "ifs2������״̬����:���ļ�ʧ��");
  }

  ifs2.seekg(0, ios::beg); // �޸Ķ�ָ��λ��

  int ii;
  double dd;
  string ss1, ss2;
  ifs2 >> ii >> dd >> ss1  ;
  if (!ifs2)
  { // ! ifs2.operator bool( )
    PrintError(__FILE__, __LINE__, "ifs2������״̬����:���ļ�ʧ��");
  }
  ifs2.close();
  cout << ii << ' ' << dd << ' ' << ss1 <<   endl;

  return 0;
}
