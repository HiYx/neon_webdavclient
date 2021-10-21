#include <iostream>
#include <list>
#include "xmler.h"
#include <string>

int main()//WebdavClient cilent
{
    std::string dir = "update_index.xml";
    // 读取xml文件，获得列表
    xmlSpace::Xmler xmler(dir);
    // 打印版本号码
    std::cout<<"version:"<<xmler.bigversion<<std::endl;
    // 生成需要下载的文字列表
    for (std::list<std::string>::iterator iter = xmler.filelist.begin();
        iter != xmler.filelist.end(); iter++)
        {
        std::cout<<*iter<<std::endl;
        } 

    //进行下载
    
    return 0;
};