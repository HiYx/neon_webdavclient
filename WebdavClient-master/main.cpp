
#include <WebdavClient.h>
#include <iostream>

//http://www2.abiuni.com:81/remote.php/dav/files/admin/

int main(){
  
  const std::string host("www2.abiuni.com");
  const std::string user("user");
  const std::string pass("key");
  const std::string uri("/remote.php/dav/files/admin/update/");
  const unsigned port = 81;

  WebdavClient webdavClient(host, port, user, pass);

  // Upload a file to webdav server
  if(webdavClient.put(uri+"temp2.txt", "temp2.txt")){
    std::cout << "Upload succesfull!" << std::endl;
  }
  else {
    std::cout << "Upload error! " << webdavClient.getLastError() << std::endl;
  }

  // Download a file from webdav server
  if(webdavClient.get(uri+"temp.txt"  ,"temp.txt")){
    std::cout << "Download successfull!" << std::endl;
  }
  else {
    std::cout << "Download error! " << webdavClient.getLastError() << std::endl;
  }

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
  }

  return 0;
}
