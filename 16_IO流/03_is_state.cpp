/*
file stream��״̬
�����ú���ȡ���� �������ܺ�rdstate
good  0   һ������
bad   1   ������������    ʹ��clear�ָ�
eof   2   �����ļ�β
fail  4   ���ļ�ʧ�ܻ��д�ֽ���δ��Ԥ��
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
    PrintError(__FILE__, __LINE__, "ifs2������״̬����:���ļ�ʧ��");
  }

  int ii;
  double dd;
  string ss1;
  cout << "-----------��һ�ζ��ļ�-------------" << endl;
  ifs2 >> ii >> dd >> ss1  ;
  if (!ifs2)
  { // ! ifs2.operator bool( )
    PrintError(__FILE__, __LINE__, "ifs2������״̬����:���ļ�ʧ��");
  }
  cout << "ifs2��0״̬��? " << ifs2.good() << ", ifs2��1״̬��? " << ifs2.bad()
       << ", ifs2��2״̬��? " << ifs2.eof() << ", ifs2��4״̬��? " << ifs2.fail() << endl;

  cout << "ifs2����״ֵ̬: " << ifs2.rdstate() << endl;
  cout << ii << ' ' << dd << ' ' << ss1 << endl;

  cout << "-----------�ڶ��ζ��ļ�-------------" << endl;
  cout << "-----------�ڶ��ζ��ļ�-------------" << endl;
  cout << "-----------�ڶ��ζ��ļ�-------------" << endl;
  ifs2.clear(); // ���������״̬������Ҫ��λΪ����״̬��Ȼ����IO����
  ifs2.seekg(0, ios::beg); // ���õ���ʼ
  

  ifs2 >> ii >> dd >> ss1  ;
  if (!ifs2)
  { // ! ifs2.operator bool( )
    PrintError(__FILE__, __LINE__, "ifs2������״̬����:���ļ�ʧ��");
  }
  cout << "ifs2��0״̬��? " << ifs2.good() << ", ifs2��1״̬��? " << ifs2.bad()
       << ", ifs2��2״̬��? " << ifs2.eof() << ", ifs2��4״̬��? " << ifs2.fail() << endl;

  cout << "ifs2����״ֵ̬: " << ifs2.rdstate() << endl;
  cout << ii << ' ' << dd << ' ' << ss1   << endl;

  ifs2.close();
}