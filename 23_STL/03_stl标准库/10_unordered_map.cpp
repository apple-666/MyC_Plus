#include <iostream>
#include <unordered_map>
using namespace std;

class Name
{
public:
  Name(string const &first, string const &second)
      : m_first(first), m_second(second) {}
private:
  string m_first;  // ��
  string m_second; // ��
  friend ostream &operator<<(ostream &os, Name const &name);
  friend class NameHash;
  friend class NameEqual;
};
ostream &operator<<(ostream &os, Name const &name)
{
  return os << name.m_first << name.m_second;
}

// hash��
class NameHash
{
public:
  size_t operator()(const Name &that) const
  {
    hash<string> hs; // �õ���ϣֵ
    return hs(that.m_first) ^ (hs(that.m_second) << 1);
  }
};
//equal��
class NameEqual
{
  public:
    bool operator()(const Name &a,const Name &b) const{
      return a.m_first==b.m_first&&a.m_second==b.m_second;
    }
};

main()
{
  // key ��string û������ ��Ĭ�ϵ�hash���equal��
  unordered_map<string, int> m{
      {"zhangsan", 90},
      {"lisi", 88},
      {"wangwu", 92}};

  // key ���Զ�����ʱҪ ��дhash�� �� equal��
  unordered_map<Name, int,NameHash,NameEqual> m2{
      {{"zhang", "san"}, 90},
      {{"li", "si"}, 80},
      {{"wang", "wu"}, 86}};
  for(auto const& p : m){
        cout << p.first << ':' << p.second << endl;
    }
  return 0;
}