#include <vector>
#include <string>
#include <iostream>

#include "Teacher.hpp"

using namespace std;

// 将数组添加到class属性里面
Teacher _transformStruct(vector<string> data)
{
  Teacher t;
  for (int i = 0; i < data.size(); i++)
  {
    string temp = data[i];
    if (i == 0)
    {
      t.setElement("id", temp);
    }
    else if (i == 1)
    {
      t.setElement("name", temp);
    }
    else if (i == 2)
    {
      t.setElement("sex", temp);
    }
    else if (i == 3)
    {
      t.setElement("age", temp);
    }
    else if (i == 4)
    {
      string edu;
      if (temp == "1")
      {
        edu = "学士";
      }
      else if (temp == "2")
      {
        edu = "硕士";
      }
      else if (temp == "3")
      {
        edu = "博士";
      }
      else
      {
        edu = "学历";
      }
      t.setElement("education", edu);
    }
    else if (i == 5)
    {
      string title;
      if (temp == "1")
      {
        title = "三级教师";
      }
      else if (temp == "2")
      {
        title = "二级教师";
      }
      else if (temp == "3")
      {
        title = "一级教师";
      }
      else if (temp == "4")
      {
        title = "高级教师";
      }
      else if (temp == "5")
      {
        title = "正高级教师";
      }
      else
      {
        title = "职称";
      }
      t.setElement("title", title);
    }
    else if (i == 6)
    {
      t.setElement("money", temp);
    }
    else if (i == 7)
    {
      t.setElement("address", temp);
    }
    else if (i == 8)
    {
      t.setElement("telephone", temp);
    }
  }
  return t;
}
// 将字符串转换成数组
vector<string> _transformArray(string message)
{
  vector<string> result;
  string str;
  for (int i = 0; i < message.length(); i++)
  {
    char c = message[i];
    if (c == '\"')
    {
      if (i == message.length() - 1)
      {
        result.push_back(str);
        str.clear();
      }
      continue;
    }
    if (c == ',')
    {
      result.push_back(str);
      str.clear();
      continue;
    }
    str.push_back(c);
  }
  return result;
}

// 将教师信息字符串转换成class
Teacher handleStr(string message)
{
  return _transformStruct(_transformArray(message));
}

// 返回包含中文字符的string字符个数,默认返回全部字符个数
int _getStrLen(string str, string language = "", int len = 3)
{
  /*
  len:字符串中文字符的编码格式的大小，默认utf-8格式的3个字节
  language:[zh]返回字符串中文字符数量,[!zh]返回字符串非中文字符数量
  */
  int zh = 0;
  int count = 0;
  for (int i = 0; str[i]; i++)
  {
    if (str[i] < 0)
    {
      i += (len - 1);
      zh++;
    }
    count++;
  }
  if (language == "zh")
  {
    return zh;
  }
  else if (language == "!zh")
  {
    return count - zh;
  }
  return count;
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
  int count = _getStrLen(str, "!zh") + _getStrLen(str, "zh") * 2; // count：字符串显示长度（字节）（一个中文字符显示时的长度等于2个字节的字母或数字的长度）

  if (loaction == "center")
  {
    int l = (length - count) / 2;
    for (int i = 0; i < l; i++)
    {
      cout << substitute;
    }
    cout << str;
    for (int i = 0; i < length - l; i++)
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
    for (int i = 0; i < length - count; i++)
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
    for (int i = 0; i < length - count; i++)
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