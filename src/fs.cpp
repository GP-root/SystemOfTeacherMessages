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
