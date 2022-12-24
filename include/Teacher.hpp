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
  string getElement(string attribute);
  void setElement(string attribute,string value);
};
#endif