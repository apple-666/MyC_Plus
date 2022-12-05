类型:
ifstream  输入
ofstream  输出
fstream   输入输出

写入模式：ofstream
ios::out 不存在则创建 存在则清空
ios::app 不存在则创建 存在则追加
ios::trunc 打开时清空

读取模式: ifstream
ios::in   不存在则失败,存在不清空
ios::ate  定位到文件尾
ios::binary 二进制模式读写

流状态
file stream的状态
可以用函数取各自 或者求总和rdstate
good  0   一切正常
bad   1   发生致命错误    使用clear恢复
eof   2   遇到文件尾
fail  4   打开文件失败或读写字节数未达预期

读写指针的位置
ios::beg  文件第一个字节
ios::cur  文件当前位置
ios::end  文件最后一个字节的下一个位置

io流.clear() //  复位为正常状态，然后在IO操作

seekg/tellg 读取
io流.seekg(0,ios::beg)  // 设置读指针到开始
tellg()  获取读指针位置

seekp/tellp 写入
io流.seekp(0,ios::beg)  // 设置写指针到开始
tellp()  获取写指针位置


gccount() 返回最后一次从输入流读取的字节数


