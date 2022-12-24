#include <vector>
#include <string>
#include <iostream>

#include "Teacher.hpp"

using namespace std;

// 将数组添加到class属性里面
Teacher transformStruct(vector<string> data)
{
  Teacher t;
  for (int i = 0; i < data.size(); i++)
  {
    string temp = data[i];
    if (i == 0)
    {
      t.setValue("id", temp);
    }
    else if (i == 1)
    {
      t.setValue("name", temp);
    }
    else if (i == 2)
    {
      t.setValue("sex", temp);
    }
    else if (i == 3)
    {
      t.setValue("age", temp);
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
      t.setValue("education", edu);
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
      t.setValue("title", title);
    }
    else if (i == 6)
    {
      t.setValue("money", temp);
    }
    else if (i == 7)
    {
      t.setValue("address", temp);
    }
    else if (i == 8)
    {
      t.setValue("telephone", temp);
    }
  }
  return t;
}

// 将字符串转换成数组
vector<string> transformArray(string message)
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
  return transformStruct(transformArray(message));
}

// 返回包含中文字符的string字符个数,默认返回全部字符个数
int getStrLen(string str, string language, int len)
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
