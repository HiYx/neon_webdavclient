#include "xmler.h"


namespace xmlSpace 
{

Xmler::Xmler(std::string& filename)
{
  TiXmlDocument* Document = new TiXmlDocument();
  if(!Document->LoadFile(filename.c_str()))
    {
        std::cerr << "cannot load xml file！" << std::endl;
        return; 
    }
  TiXmlElement* NextElement = Document->RootElement();//RootElement();获取该xml文件的根节点
  const char *p=NextElement->GetText();//得到第一个根目录字符,对应‘bigversion（文件标识符）’
  if(p)
  {
    bigversion=atoi(p);//将字符串str转换成一个整数并返回结果
    //p=strchr(p,' ');//strchr函数功能为在一个串中查找给定字符的第一个匹配之处
  }

  NextElement = NextElement->NextSiblingElement();//NextSiblingElement();该函数指向兄弟节点<file_element>
  for(;NextElement!=NULL;NextElement = NextElement->NextSiblingElement())
  {
    TiXmlElement* ChildElement = NextElement->FirstChildElement();//    <name>temp.zip</name>
    //得到文件名
    p=ChildElement->GetText();
    filelist.push_back(p);
    
/*     //得到序列号uuid
    ChildElement=ChildElement->NextSiblingElement();
    // p=ChildElement->GetText();
    // atof(p);
    
    //得到日期date
    ChildElement=ChildElement->NextSiblingElement();
    // p=ChildElement->GetText();
    // atof(p);
    
    //得到version
    ChildElement=ChildElement->NextSiblingElement();
    // p=ChildElement->GetText();

    //得到type
    ChildElement=ChildElement->NextSiblingElement();
    // p=ChildElement->GetText();


    // ChildElement=ChildElement->NextSiblingElement();
    // ChildElement=ChildElement->NextSiblingElement();
    // ChildElement=ChildElement->NextSiblingElement();
    // ChildElement=ChildElement->NextSiblingElement(); */
    }

  delete Document;
}

}