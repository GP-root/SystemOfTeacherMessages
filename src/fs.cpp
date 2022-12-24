#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

#include "fs.hpp"
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

  string data;
  while (getline(file, data))
  {
    printOneTeacher(handleStr(data));
  }

  file.close();
}

// 显示部分数据(分页查询)
void showDataOfPart()
{
  ifstream file = _openFile(DATA_URL);
  if (!file)
  {
    cout << "文件打开失败哈哈哈";
    return;
  }
  
  int page = 1;// 页数
  int state = 1;// 状态,[1]:仍有数据;[0]:没有数据;
  string data;// 教师数据
  string header;// 表头数据
  getline(file, header);
  while (true)  
  {
    printHeader(header);
    for(int count = 0; count < 30;count++){
      if(!getline(file, data)){
        state = 0;
        break;
      }
      printOneTeacher(handleStr(data));
    }
    string index = "第" + to_string(page) + "页";
    printl(index, 135, "center", '=');
    cout << "[0]:退出浏览;[1]:浏览下一页;请输入:";
    int a;
    cin >> a;
    if (a == 0)
    {
      break;
    }
    if (state == 0)
    {
      printl("已经是最后一页了",135,"center",' ');
    }else{
      page++;
    }
  }

  file.close();
  file.clear();
}

void test()
{
  
}