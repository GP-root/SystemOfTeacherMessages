#ifndef _Teacher_H_
#define _Teacher_H_

#include <string>
using namespace std;

class Teacher
{
private:
  string id,// 编号
  name,// 姓名
  sex,// 性别
  age,// 年龄
  education,// 学历
  title,// 职称
  money,// 工资
  address,// 住址
  telephone;// 电话号码
public:
  // 获取指定元素
  string getElement(string attribute);
  // 设置指定元素
  void setValue(string attribute,string value);
  // 设置所有元素
  void setValueOfAll(string id,string name,string sex,string age,string education,string title,string money,string address,string telephone);
};
#endif