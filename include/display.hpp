#ifndef _display_H_
#define _display_H_
#include<iostream>
#include <fstream>
#include <vector>
#include "Teacher.hpp"
using namespace std;

// 打印固定宽度的字符串，不换行
void print(string str, int length, string loaction = "left", char substitute = ' ');

// 打印固定宽度的字符串，换行
void printl(string str, int length, string loaction = "left", char substitute = ' ');

// 打印输入长度的字符
void printC(char c, int l, bool isBreak = true);

// 打印一行教师数据
void printOneTeacher(Teacher t);

// 打印表头
void printHeader();

// 打印部分表格
void printTableOfPart(ifstream &file, int num = 40);

// 打印全部表格
void printTableOfAll(ifstream &file);

// 打印搜索结果
void printSearchData(vector<Teacher> t, string input, int choice);
#endif