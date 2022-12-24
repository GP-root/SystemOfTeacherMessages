#include <string>
#include "teacher.hpp"

using namespace std;

string Teacher::getElement(string attribute)
{
  if (attribute == "id")
    return id;
  if (attribute == "name")
    return name;
  if (attribute == "sex")
    return sex;
  if (attribute == "age")
    return age;
  if (attribute == "education")
    return education;
  if (attribute == "title")
    return title;
  if (attribute == "money")
    return money;
  if (attribute == "address")
    return address;
  if (attribute == "telephone")
    return telephone;

  return "获取失败，请检查参数";
}

void Teacher::setValue(string attribute, string value)
{
  if (attribute == "id")
  {
    id = value;
    return;
  }
  else if (attribute == "name")
  {
    name = value;
    return;
  }
  else if (attribute == "sex")
  {
    sex = value;
    return;
  }
  else if (attribute == "age")
  {
    age = value;
    return;
  }
  else if (attribute == "education")
  {
    education = value;
    return;
  }
  else if (attribute == "title")
  {
    title = value;
    return;
  }
  else if (attribute == "money")
  {
    money = value;
    return;
  }
  else if (attribute == "address")
  {
    address = value;
    return;
  }
  else if (attribute == "telephone")
  {
    telephone = value;
    return;
  }
}

void Teacher::setValueOfAll(string id,string name,string sex,string age,string education,string title,string money,string address,string telephone){
  setValue("id", id);
  setValue("name", name);
  setValue("sex", sex);
  setValue("age", age);
  setValue("education", education);
  setValue("title", title);
  setValue("money", money);
  setValue("address", address);
  setValue("telephone", telephone);
}