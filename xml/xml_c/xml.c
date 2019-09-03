#include <stdio.h>
#include <stdlib.h> // exit(0)
#include <sqlite3.h>
#include <pthread.h>//cannot create thread
#include <dlfcn.h>//undefined 
#include <mxml.h>
#include "cgic.h"              // cgic库的头文件
#include "ctemplate.h"         // libctemplate库的头文件
char cross_road_name[64]="莲花路香梅路路口";
char device_id[32]="SZ0755003";
char ip1[16]="192.168.3.89";
char mask1[16]="255.255.252.0";
char gateway1[16]="192.168.3.254";
char ip2[16]="192.168.3.89";
char mask2[16]="255.255.252.0";
char gateway2[16]="192.168.3.254";
char a3_define[16]="A3定义";
char a2_define[16]="A3定义";
char a1_define[16]="A3定义";
char b3_define[16]="A3定义";
char b2_define[16]="A3定义";
char b1_define[16]="A3定义";
char c3_define[16]="A3定义";
char c2_define[16]="A3定义";
char c1_define[16]="A3定义";
char a3_warn[8]="100";
char a2_warn[8]="100";
char a1_warn[8]="100";
char b3_warn[8]="100";
char b2_warn[8]="100";
char b1_warn[8]="100";
char c3_warn[8]="100";
char c2_warn[8]="100";
char c1_warn[8]="100";
char a3_warn_l[8]="100";
char a2_warn_l[8]="100";
char a1_warn_l[8]="100";
char b3_warn_l[8]="100";
char b2_warn_l[8]="100";
char b1_warn_l[8]="100";
char c3_warn_l[8]="100";
char c2_warn_l[8]="100";
char c1_warn_l[8]="100";

char ip1_tmp[16];
char ip2_tmp[16];
char change_ip = 0;


const char * whitespace_cb(mxml_node_t *node, int where)
{
  const char *element;

 /*
  * We can conditionally break to a new line before or after
  * any element.  These are just common HTML elements...
  */

  element = mxmlGetElement(node);

  if (!strcmp(element, "html") ||
      !strcmp(element, "head") ||
      !strcmp(element, "body") ||
      !strcmp(element, "pre") ||
      !strcmp(element, "p") ||
      !strcmp(element, "h1") ||
      !strcmp(element, "h2") ||
      !strcmp(element, "h3") ||
      !strcmp(element, "h4") ||
      !strcmp(element, "h5") ||
      !strcmp(element, "h6"))
  {
   /*
    * Newlines before open and after close...
    */

    if (where == MXML_WS_BEFORE_OPEN ||
        where == MXML_WS_AFTER_CLOSE)
      return ("\n");
  }
  else if (!strcmp(element, "dl") ||
           !strcmp(element, "ol") ||
           !strcmp(element, "ul"))
  {
   /*
    * Put a newline before and after list elements...
    */

    return ("\n");
  }
  else if (!strcmp(element, "dd") ||
           !strcmp(element, "dt") ||
           !strcmp(element, "li"))
  {
   /*
    * Put a tab before <li>'s, <dd>'s, and <dt>'s, and a
    * newline after them...
    */

    if (where == MXML_WS_BEFORE_OPEN)
      return ("\t");
    else if (where == MXML_WS_AFTER_CLOSE)
      return ("\n");
  }

 /*
  * Otherwise return NULL for no added whitespace...
  */

  return (NULL);
}
// main已经定义在cgic.c中，在main函数中会调用cgiMain
int cgiMain(int argc, char **argv)
{
    
    TMPL_varlist *mainList = 0;
    char val_buf[2048];
    char ip_set_buf[1024];
    int pos = 0;


      if(cgiFormSubmitClicked("baseinfo")==cgiFormSuccess)
        {
            cgiFormStringNoNewlines("cross_road_name",cross_road_name,64);
            cgiFormStringNoNewlines("device_id",device_id,32);
            cgiFormStringNoNewlines("ip1",ip1,16);
            cgiFormStringNoNewlines("mask1",mask1,16);
            cgiFormStringNoNewlines("gateway1",gateway1,16);
            cgiFormStringNoNewlines("ip2",ip2,16);
            cgiFormStringNoNewlines("mask2",mask2,16);
            cgiFormStringNoNewlines("gateway2",gateway2,16);
            cgiFormStringNoNewlines("a3_define",a3_define,16);
            cgiFormStringNoNewlines("a2_define",a2_define,16);
            cgiFormStringNoNewlines("a1_define",a1_define,16);
            cgiFormStringNoNewlines("b3_define",b3_define,16);
            cgiFormStringNoNewlines("b2_define",b2_define,16);
            cgiFormStringNoNewlines("b1_define",b1_define,16);
            cgiFormStringNoNewlines("c3_define",c3_define,16);
            cgiFormStringNoNewlines("c2_define",c2_define,16);
            cgiFormStringNoNewlines("c1_define",c1_define,16);
            cgiFormStringNoNewlines("a3_warn",a3_warn,8);
            cgiFormStringNoNewlines("a2_warn",a2_warn,8);
            cgiFormStringNoNewlines("a1_warn",a1_warn,8);
            cgiFormStringNoNewlines("b3_warn",b3_warn,8);
            cgiFormStringNoNewlines("b2_warn",b2_warn,8);
            cgiFormStringNoNewlines("b1_warn",b1_warn,8);
            cgiFormStringNoNewlines("c3_warn",c3_warn,8);
            cgiFormStringNoNewlines("c2_warn",c2_warn,8);
            cgiFormStringNoNewlines("c1_warn",c1_warn,8);
            cgiFormStringNoNewlines("a3_warn_l",a3_warn_l,8);
            cgiFormStringNoNewlines("a2_warn_l",a2_warn_l,8);
            cgiFormStringNoNewlines("a1_warn_l",a1_warn_l,8);
            cgiFormStringNoNewlines("b3_warn_l",b3_warn_l,8);
            cgiFormStringNoNewlines("b2_warn_l",b2_warn_l,8);
            cgiFormStringNoNewlines("b1_warn_l",b1_warn_l,8);
            cgiFormStringNoNewlines("c3_warn_l",c3_warn_l,8);
            cgiFormStringNoNewlines("c2_warn_l",c2_warn_l,8);
            cgiFormStringNoNewlines("c1_warn_l",c1_warn_l,8);
          
            if(strcmp(ip1_tmp,ip1)||strcmp(ip2_tmp,ip2))  
                                        change_ip = 1;
            //do save xml
       
                
        }// have get the data 
        
        
        
        // 使用cgic接口，输出文档类型
        cgiHeaderContentType("text/html;charset=utf-8\r\n\r\n");
       // TMPL_write("/www/htdocs/power.html",0,0,mainList,cgiOut,cgiOut);
        
        /*
        if(change_ip)
            {
                pos = 0 ;
                //fp =    fopen( "/etc/network/interfaces", "w+" ); //change ip configure
                pos += sprintf(&ip_set_buf[pos], "auto lo\niface lo inet loopback\n");
                pos += sprintf(&ip_set_buf[pos], "auto eth0\n#iface eth0 inet dhcp\niface eth0 inet static\n"); 
                pos += sprintf(&ip_set_buf[pos], "address  %s\n",ip1); 
                pos += sprintf(&ip_set_buf[pos], "netmask %s\n",mask1); 
                pos += sprintf(&ip_set_buf[pos], "gateway  %s\n",gateway1); 
                
                pos += sprintf(&ip_set_buf[pos], "auto eth1\n#iface eth1 inet dhcp\niface eth1 inet static\n"); 
                pos += sprintf(&ip_set_buf[pos], "address  %s\n",ip2); 
                pos += sprintf(&ip_set_buf[pos], "netmask %s\n",mask2); 
                pos += sprintf(&ip_set_buf[pos], "gateway  %s\n",gateway2); 
             
                //fputs(ip_set_buf, fp);
                
                sprintf(ip1_tmp,"ifconfig eth0 %s netmask  %s\n",ip1,mask1);
                sprintf(ip2_tmp,"ifconfig eth1 %s netmask  %s\n",ip2,mask2);
              
                //system(ip1_tmp);
               
               // system(ip2_tmp);
                close(fp);
            }
        */

    return 0;
}
