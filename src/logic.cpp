#include <iostream>
#include <windows.h>
#include "logicFunction.hpp"
#include <stdlib.h>
using namespace std;

// 登录
bool login()
{
  bool res;
  showLoginMenu();
  cout << "输入登录选项:";
  int choice;
  cin >> choice;
  switch (choice)
  {
  case 1:
    res = login_Key();
    break;
  case 2:
    res = login_account();
    break;
  case 3:
    break;
  case 4:
    break;
  case 0:
    break;
  default:
    break;
  }
  if (res)
  {
    cout << "[系统]Loading······" << endl;
    Sleep(2000);
  }
  return res;
}

// 操作系统
void operateSystem()
{
  bool exit = false; // 是否退出
  while (true)
  {
    system("cls");
    showMenu(30);
    cout << "请输入选项:";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
      if (!showDataOfAll())
        Sleep(1500);// 留出时间显示报错信息(如文件打开失败)
      break;
    case 2:
      if (!showDataOfPart())
        Sleep(1500);
      break;
    case 0:
      exit = true;
      break;
    default:
      cout << "请重新输入" << endl;
      continue;
    }
    if (exit)
    {
      cout << "已退出系统" << endl;
      break;
    }
  }
}
