// ʹ�� string�����
#include <iostream>
using namespace std;

int main(void)
{
  string s1("hello"); // ����s1,����s1.string("hello") ---> s1ά�����ַ���Ϊ"hello"
  cout << "s1:" << s1.c_str() << endl;
  cout << "s1:" << s1 << endl;

  string s2(s1);
  cout << s2.c_str() << endl;

  string s3; // ����s3,����s3.string() ---> s3ά�����ַ���Ϊ"\0"
  cout << "s3��ֵǰ:" << s3.c_str() << endl;
  cout << "s3��ֵǰ:" << s3 << endl;

  // ����ڸ�ֵ ����"="���ߵ�������ȫһ��,������ operator= ��������ĵ���
  s3 = s2; // s3.operator=(s2) ---> s3ά�����ַ��� �� s2ά�����ַ��� ������ͬ
  cout << "s3��ֵ��:" << s3.c_str() << endl;
  cout << "s3��ֵ��:" << s3 << endl;

  // �����=�����ߵ����Ͳ�һ��,�������Ὣ ��=���ұ����ݵ����� ת�ɺ� "="������ݵ����� һ��

  // ���� ����string�����,��������string�����.string("hello")-->����string�����ά�����ַ���Ϊ"hello"
  // string s4 = ����string�����; --> s4ά�����ַ��� �� ����string�����ά�����ַ��� ������ͬ
  // ---> s4ά�����ַ���Ϊ"hello"
  string s4 = "hello";
  cout << "s4:" << s4.c_str() << endl;
  cout << "s4:" << s4 << endl;

  string s5;    // ����s5,����s5.string() ---> s5ά�����ַ���Ϊ"\0"
  s5 = "hello"; // ���� ����string�����,���� ����string�����.string("hello")-->����string�����ά�����ַ���Ϊ"hello"
                // s5 = ����string�����; --> s5ά�����ַ��� �� ����string�����ά�����ַ��� ������ͬ
                // --> s5ά�����ַ���Ϊ"hello"
  cout << "s5:" << s5.c_str() << endl;
  cout << "s5:" << s5 << endl;
}