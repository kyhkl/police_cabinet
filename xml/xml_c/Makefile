CC = /home/ky/work/gcc-linaro-arm-linux-gnueabihf-4.7-2013.03-20130313_linux/bin/arm-linux-gnueabihf-gcc
CC = gcc
CFLAGS = -I .
TARGET = xml.cgi
objects =  cgic.o ctemplate.o sqlite3.o
INSTALL =/www/htdocs/


$(TARGET):$(objects)

	$(CC)  -g xml.c ctemplate.o cgic.o -L./ -lmxml -o xml.cgi -I./   -lpthread -ldl

ctemplate.o: 
	$(CC) -I . -c -o ctemplate.o ctemplate.c   
	 
cgic.o:
	$(CC)  -I . -c -o cgic.o cgic.c  
	

	
install : 
	cp xml.cgi index.html set.html power.html $(INSTALL) -r	
	cp xml.cgi   /www/cgi-bin/ -r	
	cp lcd /www/htdocs/ -r
	rm xml.cgi 
clean :
	rm *.o  xml.cgi 
	
	
