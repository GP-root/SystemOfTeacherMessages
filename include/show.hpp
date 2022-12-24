#ifndef _show_H_
#define _show_H_
#include<iostream>
#include <fstream>
#include "Teacher.hpp"
using namespace std;

// 显示菜单
void showMenu();

// 该函数类似于setW(),setfill()的聚合体,用于解决setW()对中文不友好的情况
void print(string str, int length, string loaction = "left", char substitute = ' ', bool isBreak = false);
void printl(string str, int length, string loaction = "left", char substitute = ' ');

// 打印一行教师数据
void printOneTeacher(Teacher t);

// 打印表头
void printHeader(string header);

// 打印部分表格
void printTableOfPart(ifstream &file, int num = 40);

// 打印全部表格
void printTableOfAll(ifstream &file);
#endif