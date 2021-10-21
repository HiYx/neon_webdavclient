Downloading neon:
Run the command below,

wget http://www.webdav.org/neon/neon-0.32.1.tar.gz
Extracting files from the downloaded package:

tar xvzf *.tar.gz
Now, enter the directory where the package is extracted.

cd neon-0.32.1
Configuring neon Library:



./configure --prefix=/usr/local/neon --enable-shared 具体可以看--help

或者启动一些附件

./configure --prefix=/usr/local/neon --with-ssl=openssl --with-libxml2 --with-libs=/usr/local/openssl/:/usr/local/libxml2/ --without-zlib

Replace "/usr/local/neon" with the directory path where you want to copy neon's files and folders, "/usr/local/openssl/" with the path to OpenSSL and "/usr/local/libxml2/" with the path to libxml2. Note: check for any error message.
Compiling neon:

make

Note: check for any error message.
Installing neon:

As root (for privileges on destination directory), run the following.
With sudo,

sudo make install
Without sudo,

make install

Note: check for any error messages.

That’s it. Library has been successfully installed.


转载于:https://www.cnblogs.com/MagicLetters/archive/2012/03/23/4382790.html