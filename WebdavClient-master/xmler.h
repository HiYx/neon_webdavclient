#ifndef _XMLER_H_
#define _XMLER_H_

#include <tinyxml.h>
#include <fstream>
#include <iostream>
#include <string>//标准C++库字符串类std::string的用法
#include <list>


namespace xmlSpace 
{
class Xmler 
{
 public:
    
  Xmler(std::string& filename);
  int bigversion;//文件大版本
  // 把检索到的名字存入string类的列表里面
  std::list<std::string> filelist;
  ~Xmler();
};
};

#endif  