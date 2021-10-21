WebdavClient 
============
A very simple C++ interface for the webdav neon lib

## Description ##
 __WebdavClient__ is a C++ class, that makes it very easy to transmit data between a local machine
 and a webdav server. All the complex neon calls are hidden behind some methods of the
 WebdavClient class.

## Build ##
   + Include WebdavClient.h
   + compile with -lneon
   + example: g++ main.cc WebdavClient.cc -I . -lneon

## Example ##
All methods of WebdavClient class used in a simple example.
```c++

#include <WebdavClient.h>
#include <iostream>

int main(){
  
  const std::string host("my_webdavserver.com");
  const std::string user("my_user");
  const std::string pass("my_password");
  const std::string uri("/my_location/");
  const unsigned port = 80;

  WebdavClient webdavClient(host, port, user, pass);

  // Upload a file to webdav server
  if(webdavClient.put(uri + "my_file_put", "my_file_put")){
    std::cout << "Upload succesfull!" << std::endl;
  }
  else {
    std::cout << "Upload error! " << webdavClient.getLastError() << std::endl;
  }

  // Download a file from webdav server
  if(webdavClient.get(uri + "my_file_put", "my_file_get")){
    std::cout << "Download successfull!" << std::endl;
  }
  else {
    std::cout << "Download error! " << webdavClient.getLastError() << std::endl;
  }

  // Check if a file on webdav server exists
  if(webdavClient.exist(uri + "my_file_put")){
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
  if(webdavClient.rm(uri + "my_file_put")){
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
  }

  return 0;
}
```

## Dependencies ##
 + neon
 + c++99



# demo 设计



1、首先下载update_index.xml文件

2、根据update_index.xml文件下载对应的文件



xml：

```
<bigversion>21</bigversion>

<file_element>
    <name>temp.zip</name>
    <uuid>0</uuid>
    <date>20211020</date>
    <version>1</version>
    <type>zip</type>
    <size>0</size>
    <other>0</other>
    <another>0</another>
    <characters>0</characters>
</file_element>
```





```
Download update_index successfull!
version:21
-----
Downloading:temp.zip
Download update_index successfull<<temp.zip>>
-----
Downloading:temp2.zip
Download update_index error!<<temp2.zip>>404 Not Found

```

