#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>

#include "logicFunction.hpp"
#include "Teacher.hpp"
#include "tool.hpp"
#include "display.hpp"

#define DATA_URL "C:\\Users\\LENOVO\\Desktop\\SystemOfTeacherMessages\\res\\teachersMessages.txt"

using namespace std;

// 显示所有数据
bool showDataOfAll()
{
  ifstream file;
  if (!openFile(file, DATA_URL))
    return false;

  printTableOfAll(file);

  cout << "输入[0]退出浏览:";
  int exit;
  cin >> exit;
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

  return true;
}

// 显示操作菜单
void showMenu(int width)
{
  cout << '+';
  print("菜单", width - 2, "center", '-');
  cout << '+' << endl;

  print("| [1] 显示全体教师数据", width - 1, "left", ' ');
  cout << '|' << endl;

  print("| [2] 显示部分教师数据", width - 1, "left", ' ');
  cout << '|' << endl;

  print("| [3] 查询教师数据", width - 1, "left", ' ');
  cout << '|' << endl;

  print("| [4] 修改教师数据(未实现)", width - 1, "left", ' ');
  cout << '|' << endl;

  print("| [0] 退出系统", width - 1, "left", ' ');
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

  print("| [1] 口令", 29, "left", ' ');
  cout << '|' << endl;

  print("| [2] 账号密码", 29, "left", ' ');
  cout << '|' << endl;

  print("| [0] 退出系统", 29, "left", ' ');
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
        cout << "退出系统中···" << endl;
        Sleep(800);
      }
    }
  } while (errorCount > 0);
  return result;
}

// 账号登录
bool login_account()
{
  return true;
}

// 查询、筛选教师数据
bool getSearchData()
{
  ifstream file;
  if (!openFile(file, DATA_URL))
    return false;

  int choice;
  string input;
  cout << "[0]:编号;[1]:职称(暂不支持,输入中文会乱码);[2]:年龄;" << endl;
  cout << "请选择查询方式:";
  cin >> choice;
  cout << "请输入查询内容:";
  cin >> input;

  printSearchData(searchData(file, input, choice), input, choice);

  cout << "输入[0]退出浏览:";
  int exit;
  cin >> exit;
  file.close();
  return true;
}

// 修改教师数据
bool update()
{
  ifstream file;
  // if (!openFile(file, DATA_URL))
  //   return false;
  if (!openFile(file, "C:\\Users\\LENOVO\\Desktop\\SystemOfTeacherMessages\\src\\1.txt"))
    return false;

  

  file.close();
  return true;
}