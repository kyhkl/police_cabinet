CC = /home/ky/work/gcc-linaro-arm-linux-gnueabihf-4.7-2013.03-20130313_linux/bin/arm-linux-gnueabihf-gcc
CC = g++
CFLAGS = -I .  
TARGET = xml.cgi
objects =  cgic.o ctemplate.o 
INSTALL =/www/htdocs/


$(TARGET):$(objects)

	$(CC)  -g xml.cpp ctemplate.o cgic.o -L./ -ltinyxml2 -o xml.cgi -I./   -lpthread -ldl 

ctemplate.o: 
	$(CC) -I . -c -o ctemplate.o ctemplate.cpp   
	 
cgic.o:
	$(CC)  -I . -c -o cgic.o cgic.cpp 
	

	
install : 
	cp  index.html set.html power.html sysconf.xml json.txt log.txt $(INSTALL) -r	
	cp lcd  /www/htdocs/ -r
	rm xml.cgi 
clean :
	rm *.o  xml.cgi 
	
	
