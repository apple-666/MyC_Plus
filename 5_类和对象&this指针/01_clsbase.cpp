// �� �� ����
#include <iostream>
#include <cstring>
using namespace std;
// ��:��ȡ�������� ����
// struct

class Human
{
public:
    void setinfo(int age = 0, const char *name = "null��") // һ�㴫�ַ����������������ַ�����ָ�룬������const
    {
        if (!strcmp(name, "С��"))
        {
            cout << "��Ҫȡ��ΪС��" << endl;
            return;
        }
        m_age = age;
        strcpy(m_name, name);
    }

    void getinfo()
    {
        cout << "����: " << m_name << ", ����: " << m_age << endl;
    }

private:
    int m_age;
    char m_name[100];
};
// ���ϴ���ģ�������������(����: ��⡢������Ƶ��ࡢ�Լ���Ƶ���)
// ---------------------------------------
// ���´���ģ������û�
int main(void)
{
    // ����h,��h�����ڴ�ռ� int+char = 104
    // ��h��ռ�ڴ�ռ��� ����m_age(��m_age�����ڴ�ռ�)��ֵΪ�����
    // ��h��ռ�ڴ�ռ��� ����m_name(��m_name�����ڴ�ռ�)��ֵΪ�����
    Human h;
    cout << "h�����size��" << sizeof(h) << endl;
    char *a = "yeas!!";
    cout << "strcpy: a:" << a << endl;
    h.setinfo(22, a);
    h.getinfo();

    cout << "after: a: " << a << endl;
    h.m_age = 222;
    strcpy(h.m_name, "�ŷ�");
     strcpy( h.m_name, "С��" );
    cout << "����: " << h.m_name << ", ����: " << h.m_age << endl;
    return 0;
}
