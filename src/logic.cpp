#include <iostream>
#include "logicFunction.hpp"

using namespace std;

// 登录
bool login()
{
  return true;
}

// 操作系统
void operateSystem()
{
  bool exit = false; // 是否退出
  bool isShowMenu = true;
  while (true)
  {
    if (isShowMenu)
      showMenu(50);
    cout << "请输入选项:";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
      showDataOfAll();
      isShowMenu = true;
      break;
    case 2:
      showDataOfPart();
      isShowMenu = true;
      break;
    case 0:
      exit = true;
      break;
    default:
      cout << "请重新输入" << endl;
      isShowMenu = false;
      continue;
    }
    if (exit)
    {
      cout << "已退出系统" << endl;
      break;
    }
  }
}
