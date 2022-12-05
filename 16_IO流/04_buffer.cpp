/*
���뻺����:put
���������豸:flush ǿ��
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
    PrintError(__FILE__, __LINE__, "ofs������״̬����:���ļ�ʧ��");
  }
  for (char c = ' '; c <= '~'; c++)
  {
    ofs.put(c);  // ��c�е�����д��ofs������ά���� ��������
    ofs.flush(); // ǿ�ƽ�ofs������ά�������������е����� ˢ�� Ŀ���豸
  }

  ifstream ifs("./a3.txt", ios::in);
  if (!ifs)
  { // ! ifs.operator bool( )
    PrintError(__FILE__, __LINE__, "ifs������״̬����:���ļ�ʧ��");
  }
  char c;
  // ����get
  while (ifs.get(c))
  { // ��ȡһ���ַ����Ƿ�ɹ���ȡ��һ���ַ�ͨ�������������bool�����������ж�
    cout << c;
  }
  cout << endl;
  cout << "ifs���������״ֵ̬: " << ifs.rdstate() << endl;


  cout<<"ifs���������"<<endl;
  cout<<"ifs���������"<<endl;
  cout<<"ifs���������"<<endl;
  ifs.clear(); // Ҫ���+����λ�ò��� ��
  ifs.seekg(0, ios::beg);
  // �޲�get
  while ((c = ifs.get()) != EOF) // EOF���������
  {
    cout << c;
  }
  cout << endl;
  ifs.close();
  ofs.close();
}
