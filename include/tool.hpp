#ifndef _tool_H_
#define _tool_H_

#include <string>
#include "Teacher.hpp"
using namespace std;

// 将教师信息字符串转换成class
Teacher handleStr(string message);

// 打印固定宽度的字符串(不换行)
void print(string str, int length, string loaction = "left", char substitute = ' ', bool isBreak = false);
// 打印固定宽度的字符串(换行)
void printl(string str, int length, string loaction = "left", char substitute = ' ');

// 打印一行教师数据
void printOneTeacher(Teacher t);

// 打印表头
void printHeader(string header);

#endif