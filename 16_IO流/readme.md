����:
ifstream  ����
ofstream  ���
fstream   �������

д��ģʽ��ofstream
ios::out �������򴴽� ���������
ios::app �������򴴽� ������׷��
ios::trunc ��ʱ���

��ȡģʽ: ifstream
ios::in   ��������ʧ��,���ڲ����
ios::ate  ��λ���ļ�β
ios::binary ������ģʽ��д

��״̬
file stream��״̬
�����ú���ȡ���� �������ܺ�rdstate
good  0   һ������
bad   1   ������������    ʹ��clear�ָ�
eof   2   �����ļ�β
fail  4   ���ļ�ʧ�ܻ��д�ֽ���δ��Ԥ��

��дָ���λ��
ios::beg  �ļ���һ���ֽ�
ios::cur  �ļ���ǰλ��
ios::end  �ļ����һ���ֽڵ���һ��λ��

io��.clear() //  ��λΪ����״̬��Ȼ����IO����

seekg/tellg ��ȡ
io��.seekg(0,ios::beg)  // ���ö�ָ�뵽��ʼ
tellg()  ��ȡ��ָ��λ��

seekp/tellp д��
io��.seekp(0,ios::beg)  // ����дָ�뵽��ʼ
tellp()  ��ȡдָ��λ��


gccount() �������һ�δ���������ȡ���ֽ���


