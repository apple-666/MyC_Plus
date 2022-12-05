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
    PrintError(__FILE__, __LINE__, "ifs流对象状态错误:打开文件失败");
  }
  char buffer[1024];
  ifs.getline(buffer, 2,'\n'); // 应该是3字节
  cout<<"in流状态:"<<ifs.rdstate()<<endl;
  cout<<buffer<<"\n";
  ifs.clear();
  ifs.seekg(0,ios::beg);
  cout<<"in流状态:"<<ifs.rdstate()<<endl;

  while(ifs.getline(buffer,1000,'\n')) {
    cout<<buffer<<endl;
    cout<<"in流状态:"<<ifs.rdstate()<<endl;
  }

  return 0;

}