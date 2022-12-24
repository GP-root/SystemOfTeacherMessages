#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

#include "logicFunction.hpp"
#include "Teacher.hpp"
#include "tool.hpp"
#include "show.hpp"

#define DATA_URL "../res/teachersMessages.txt"

using namespace std;

ifstream _openFile(string url)
{
  ifstream file;
  file.open(url, ios::in);
  return file;
}

// 显示所有数据
void showDataOfAll()
{
  ifstream file = _openFile(DATA_URL);
  if (!file)
  {
    cout << "文件打开失败" << endl;
    return;
  }
  printTableOfAll(file);
  file.close();
  file.clear();
}

// 显示部分数据(分页查询)
void showDataOfPart()
{
  ifstream file = _openFile(DATA_URL);
  if (!file)
  {
    cout << "文件打开失败~";
    return;
  }
  
  printTableOfPart(file);
  
  file.close();
  file.clear();
}

// 显示菜单
void showMenu(int width){
  cout<<'+';
  print("菜单",width-2,"center",'-');
  cout<<'+'<<endl;

  print("| 1.显示全体教师数据",width-1,"left",' ');
  cout<<'|'<<endl;

  print("| 2.显示部分教师数据",width-1,"left",' ');
  cout<<'|'<<endl;

  print("| 0.退出",width-1,"left",' ');
  cout<<'|'<<endl;

  cout<<'+';
  printC('-',width-2,false);
  cout<<'+'<<endl;
}

void showLoginMenu(){
  cout<<'+';
  print("菜单",28,"center",'-');
  cout<<'+'<<endl;

  print("| 1.口令",29,"left",' ');
  cout<<'|'<<endl;

  print("| 2.账号密码",29,"left",' ');
  cout<<'|'<<endl;

  print("| 3.注册",29,"left",' ');
  cout<<'|'<<endl;

  print("| 0.退出",29,"left",' ');
  cout<<'|'<<endl;

  cout<<'+';
  printC('-',28,false);
  cout<<'+'<<endl;
}