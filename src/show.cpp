#include <iostream>

#include "tool.hpp"
#include "Teacher.hpp"
using namespace std;

void showMenu(){
  
}

// 该函数类似于setW(),setfill()的聚合体,用于解决setW()对中文不友好的情况
void print(string str, int length, string loaction, char substitute, bool isBreak)
{
  /*
  str:目标字符串
  length：宽度（字节）
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

void printl(string str, int length, string loaction, char substitute)
{
  print(str, length, loaction, substitute, true);
}


// 打印一行教师数据
void printOneTeacher(Teacher t){
  print(t.getElement("id"),10,"left",' ',false);
  print(t.getElement("name"),10,"left",' ',false);
  print(t.getElement("sex"),10,"left",' ',false);
  print(t.getElement("age"),10,"left",' ',false);
  print(t.getElement("education"),10,"left",' ',false);
  print(t.getElement("title"),15,"left",' ',false);
  print(t.getElement("money"),10,"left",' ',false);
  print(t.getElement("address"),50,"left",' ',false);
  printl(t.getElement("telephone"),10,"left",' ');
}

// 打印表头
void printHeader(string header){
  printl("教师信息表",135,"center",'=');
  printOneTeacher(handleStr(header));
  printl("=",135,"left",'=');
}
