// �����Լ���ʾд this�����
// class��function �β��б��� ��ʽ�ļ���ָ�룺 YourClass* this
#include <iostream>
using namespace std;

class Float
{
public:
    void setinfo(float i)
    {
        this->i = i;
    }
    void getinfo()
    {
        void PrintMy(Float i);

        PrintMy(*this);
        cout << this->i << endl;
    }
    // Float& ����Ϊ�������Կ��Դ�������
    Float &increment(/* Float* this */)
    {
        this->i = this->i + 1.5; // ������ float��
        return *this;            // ��Ҫ����һ��class���ͣ����Բ�����this->i
    }

private:
    float i;
};

void PrintMy(Float i)
{
    cout << "print(��*this):" << endl;
}

// ���ϴ���ģ�������������(����: ��⡢������Ƶ��ࡢ�Լ���Ƶ���)
// ---------------------------------------
// ���´���ģ������û�
int main(void)
{
    Float f;
    f.setinfo(2.5);
    f.getinfo();
    f.increment().increment().increment();

    f.getinfo();
    return 0;
}
