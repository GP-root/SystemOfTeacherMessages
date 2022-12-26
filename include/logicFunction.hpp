#ifndef _logicFunction_H_
#define _logicFunction_H_

#include <iostream>
#include <fstream>
using namespace std;

// 显示所有数据
bool showDataOfAll();

// 显示部分数据(分页显示)
bool showDataOfPart();

// 显示操作菜单
void showMenu(int width);

// 显示登录菜单
void showLoginMenu();

// 口令登录
bool login_Key();

// 账号登录
bool login_account();

// 查询、筛选教师数据
bool getSearchData();
#endif