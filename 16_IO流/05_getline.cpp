/*
  getline
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

  ifstream ifs("./getline.txt", ios::in);
  if (!ifs)
  {
    PrintError(__FILE__, __LINE__, "ifs������״̬����:���ļ�ʧ��");
  }
  char buffer[1024];
  ifs.getline(buffer, 2,'\n'); // Ӧ����3�ֽ�
  cout<<"in��״̬:"<<ifs.rdstate()<<endl;
  cout<<buffer<<"\n";
  ifs.clear();
  ifs.seekg(0,ios::beg);
  cout<<"in��״̬:"<<ifs.rdstate()<<endl;

  while(ifs.getline(buffer,1000,'\n')) {
    cout<<buffer<<endl;
    cout<<"in��״̬:"<<ifs.rdstate()<<endl;
  }

  return 0;

}