#include <iostream>
#include <fstream>
#include "tool.hpp"
#include "Teacher.hpp"
using namespace std;


// 该函数类似于setW(),setfill()的聚合体,用于解决setW()对中文不友好的情况
void _print(string str, int length, string loaction, char substitute, bool isBreak)
{
  /*
  str:目标字符串  length：宽度（字节）
  substitute：填充字符
  loaction：目标字符串位置(左/右/中对齐)
  isBreak：是否换行
  */
  int len = getStrLen(str, "!zh") + getStrLen(str, "zh") * 2; // count：字符串显示长度（字节）（一个中文字符显示时的长度等于2个字节的字母或数字的长度）

  if (loaction == "center")
  {
    int l = (length - len) / 2;
    for (int i = 0; i < l; i++)
    {
      cout << substitute;
    }
    cout << str;
    for (int i = 0; i < length - l - len; i++)
    {
      cout << substitute;
    }
    if (isBreak == true)
    {
      cout << endl;
    }
    return;
  }
  if (loaction == "left")
  {
    cout << str;
    for (int i = 0; i < length - len; i++)
    {
      cout << substitute;
    }
    if (isBreak == true)
    {
      cout << endl;
      return;
    }
    return;
  }
  if (loaction == "right")
  {
    for (int i = 0; i < length - len; i++)
    {
      cout << substitute;
    }
    cout << str;
    if (isBreak == true)
    {
      cout << endl;
      return;
    }
    cout << endl;
    return;
  }
}

// 打印固定宽度的字符串，不换行
void print(string str, int length, string loaction, char substitute){
   _print(str, length, loaction, substitute, false);
}

// 打印固定宽度的字符串，换行
void printl(string str, int length, string loaction, char substitute)
{
  _print(str, length, loaction, substitute, true);
}

// 打印输入长度的字符
void printC(char c, int l, bool isBreak){
  if(isBreak){
    printl("",l,"left",c);
  }else{
    print("",l,"left",c);
  }
}

// 打印一行教师数据
void printOneTeacher(Teacher t){
  print(t.getElement("id"),10,"left",' ');
  print(t.getElement("name"),10,"left",' ');
  print(t.getElement("sex"),10,"left",' ');
  print(t.getElement("age"),10,"left",' ');
  print(t.getElement("education"),10,"left",' ');
  print(t.getElement("title"),15,"left",' ');
  print(t.getElement("money"),10,"left",' ');
  print(t.getElement("address"),50,"left",' ');
  printl(t.getElement("telephone"),10,"left",' ');
}

// 打印表头
void printHeader(string header){
  printl("教师信息表",135,"center",'=');
  printOneTeacher(handleStr(header));
  printl("=",135,"left",'=');
}

// 打印部分表格
void printTableOfPart(ifstream &file, int num){
  /*
  file:输入文件流
  num:展示数据条数,默认40
  */
  int page = 1;// 页数
  int state = 1;// 状态,[1]:仍有数据;[0]:没有数据;
  string data;// 教师数据 
  string header;// 表头数据
  getline(file, header);
  while (true)  
  {
    printHeader(header);
    for(int count = 0; count < num;count++){
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
}

// 打印全部表格
void printTableOfAll(ifstream &file){
  string data;// 教师数据 
  string header;// 表头数据
  getline(file, header);
  printHeader(header);
  while (getline(file, data))
  {
    printOneTeacher(handleStr(data));
  }
  printC('=',135,true);
}
