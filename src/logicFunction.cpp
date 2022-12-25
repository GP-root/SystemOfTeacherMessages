#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdlib.h>

#include "logicFunction.hpp"
#include "Teacher.hpp"
#include "tool.hpp"
#include "display.hpp"

#define DATA_URL "../res/teachersMessages.txt"

using namespace std;

// 显示所有数据
bool showDataOfAll()
{
  ifstream file;
  if (!openFile(file, DATA_URL))
    return false;

  printTableOfAll(file);

  file.close();
  return true;
}

// 显示部分数据(分页查询)
bool showDataOfPart()
{
  ifstream file;
  if (!openFile(file, DATA_URL))
    return false;

  printTableOfPart(file);

  file.close();
  return true;
}

// 显示操作菜单
void showMenu(int width)
{
  cout << '+';
  print("菜单", width - 2, "center", '-');
  cout << '+' << endl;

  print("| 1.显示全体教师数据", width - 1, "left", ' ');
  cout << '|' << endl;

  print("| 2.显示部分教师数据", width - 1, "left", ' ');
  cout << '|' << endl;

  print("| 0.退出系统", width - 1, "left", ' ');
  cout << '|' << endl;

  cout << '+';
  printC('-', width - 2, false);
  cout << '+' << endl;
}

// 显示登录菜单
void showLoginMenu()
{
  cout << '+';
  print("登录选项", 28, "center", '-');
  cout << '+' << endl;

  print("| 1.口令", 29, "left", ' ');
  cout << '|' << endl;

  print("| 2.账号密码", 29, "left", ' ');
  cout << '|' << endl;

  print("| 3.注册", 29, "left", ' ');
  cout << '|' << endl;

  print("| 0.退出系统", 29, "left", ' ');
  cout << '|' << endl;

  cout << '+';
  printC('-', 28, false);
  cout << '+' << endl;
}

// 口令登录
bool login_Key()
{
  bool result = false;
  short errorCount = 3;
  cout << "请输入口令:";
  do
  {
    string key;
    cin >> key;
    if (verifyKey(key))
    {
      result = true;
      break;
    }
    else
    {
      errorCount--;
      if (errorCount > 0)
      {
        cout << "口令错误,剩余" << errorCount << "次机会,请重新输入:";
      }
      else
      {
        cout << "退出系统" << endl;
      }
    }
  } while (errorCount > 0);
  return result;
}

// 账号登录
bool login_account(){
  return true;
}