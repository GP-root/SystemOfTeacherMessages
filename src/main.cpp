#include <iostream>
#include <stdlib.h>
#include "logic.hpp"

using namespace std;

int main()
{
  system("chcp 65001");// 将独立终端的显示语言切换为UTF-8
  system("cls");
  if(login()){
    operateSystem();
  }
  return 0;
}