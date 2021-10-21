
#include <WebdavClient.h>
#include <iostream>
#include <list>
#include <string>
#include "xmler.h"

//http://www2.abiuni.com:81/remote.php/dav/files/admin/

int downloadfile(WebdavClient webdavClient,std::string uri)
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
    //进行下载
        std::cout<<"-----"<<std::endl;
        std::cout<<"Downloading:"<<*iter<<std::endl;
          if(webdavClient.get(uri+*iter ,"bigversion_"+std::to_string(xmler.bigversion)+"_"+*iter)){
            std::cout << "Download update_index successfull<<" <<*iter<< ">>" <<std::endl;
          }
          else {
            std::cout << "Download update_index error!<<" <<*iter<< ">>" << webdavClient.getLastError() << std::endl;
          }
        }


}



int main(){
  
  const std::string host("www2.abiuni.com");
  const std::string user("user");
  const std::string pass("user");
  const std::string uri("/remote.php/dav/files/admin/update/");
  const unsigned port = 81;

  WebdavClient webdavClient(host, port, user, pass);

/*   // Upload a file to webdav server
  if(webdavClient.put(uri+"temp2.txt", "temp2.txt")){
    std::cout << "Upload succesfull!" << std::endl;
  }
  else {
    std::cout << "Upload error! " << webdavClient.getLastError() << std::endl;
  } */

  // Download a file from webdav server
  if(webdavClient.get(uri+"update_index.xml"  ,"update_index.xml")){
    std::cout << "Download update_index successfull!" << std::endl;
    downloadfile(webdavClient,uri);
  }
  else {
    std::cout << "Download update_index error! " << webdavClient.getLastError() << std::endl;
  }
/* 
  // Check if a file on webdav server exists
  if(webdavClient.exist(uri + "temp3.txt")){
    std::cout << "File exists! "  << std::endl;
  }
  else {
    std::cout << "File does not exist! " << webdavClient.getLastError() << std::endl;
  }

  // Create directory on webdav server
  if(webdavClient.mkdir(uri + "new_dir")){
    std::cout << "Create folder successfull!" << std::endl;
  }
  else {
    std::cout << "Create folder error! " << webdavClient.getLastError() << std::endl;
  }

  // Remove a file on webdav server
  if(webdavClient.rm(uri + "temp2.txt")){
    std::cout << "Remove file successfull!" << std::endl;
  }
  else {
    std::cout << "Remove file error! " << webdavClient.getLastError() << std::endl;
  }

  // Remove a directory on webdav server
  if(webdavClient.rm(uri + "new_dir/")){
    std::cout << "Remove directory successfull!" << std::endl;
  }
  else {
    std::cout << "Remove directory error! " << webdavClient.getLastError() << std::endl;
  } */

  return 0;
}
