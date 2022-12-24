#ifndef _tool_H_
#define _tool_H_
#include <vector>
#include <string>
#include "Teacher.hpp"
using namespace std;

// 将数组添加到class属性里面
Teacher transformStruct(vector<string> data);

// 将字符串转换成数组
vector<string> transformArray(string message);

// 将教师信息字符串转换成class
Teacher handleStr(string message);

// 返回包含中文字符的string字符个数,默认返回全部字符个数
int getStrLen(string str, string language, int len = 3);

#endif