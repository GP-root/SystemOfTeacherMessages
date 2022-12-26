#ifndef _tool_H_
#define _tool_H_
#include <vector>
#include <string>
#include "Teacher.hpp"
using namespace std;

// 打开文件
bool openFile(ifstream &file, string url);

// 将数组添加到class属性里面
Teacher transformClass(vector<string> data);

// 将字符串转换成数组
vector<string> transformArray(string message);

// 将教师信息字符串转换成class
Teacher handleStr(string message);

// 返回包含中文字符的string字符个数,默认返回全部字符个数
int getStrLen(string str, string language, int len = 3);

// 验证口令
bool verifyKey(string key);

// 验证密码
void verifyPassword();

// 搜索指定数据
vector<Teacher> searchData(ifstream &file, string input, int choice);
#endif