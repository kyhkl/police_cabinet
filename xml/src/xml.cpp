#include <iostream>
#include <stdio.h>
#include <stdlib.h> // exit(0)
#include <pthread.h>//cannot create thread
#include <string.h>
#include <dlfcn.h>//undefined 
#include "cgic.h"              // cgic库的头文件
#include "ctemplate.h"         // libctemplate库的头文件
#include "tinyxml2.h"
#define XML_OK 0
#define XML_FILE_NOT_FOUND -1
#define XML_VALUE_NOT_FIND -2

using namespace std;
using namespace tinyxml2;
char cross_road_name[64]="莲花路香梅路路口";
char device_id[32]="SZ0755003";
char ip1[16]="192.168.3.89";
char mask1[16]="255.255.252.0";
char gateway1[16]="192.168.3.254";
char ip2[16]="192.168.3.89";
char mask2[16]="255.255.252.0";
char gateway2[16]="192.168.3.254";
char a3_define[24]="A3定义";
char a2_define[24]="A3定义";
char a1_define[24]="A3定义";
char b3_define[24]="A3定义";
char b2_define[24]="A3定义";
char b1_define[24]="A3定义";
char c3_define[24]="A3定义";
char c2_define[24]="A3定义";
char c1_define[24]="A3定义";
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

char ip_old[16]="192.168.1.89";
//char ip2_old[16];
char change_ip = 0;



/*
 * 
 * name: main已经定义在cgic.c中，在main函数中会调用cgiMain
 * @param None
 * @return None
 * 
 */
int cgiMain()
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
	    /*
            cgiFormStringNoNewlines("ip2",ip2,16);
            cgiFormStringNoNewlines("mask2",mask2,16);
            cgiFormStringNoNewlines("gateway2",gateway2,16);
            */
            cgiFormStringNoNewlines("a3_define",a3_define,24);
            cgiFormStringNoNewlines("a2_define",a2_define,24);
            cgiFormStringNoNewlines("a1_define",a1_define,24);
            cgiFormStringNoNewlines("b3_define",b3_define,24);
            cgiFormStringNoNewlines("b2_define",b2_define,24);
            cgiFormStringNoNewlines("b1_define",b1_define,24);
            cgiFormStringNoNewlines("c3_define",c3_define,24);
            cgiFormStringNoNewlines("c2_define",c2_define,24);
            cgiFormStringNoNewlines("c1_define",c1_define,24);
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
	    
/*************************************************   update_xml  **************************************************/
            XMLDocument doc;
        
            doc.LoadFile( "/etc/sysconf.xml" );
    
            XMLElement* root = doc.RootElement();// get the doucument root node
	
/*************************************************   set equipment Id and Name  **************************************************/
            XMLElement* equipment = root->FirstChildElement ("equipment");
            
            XMLElement* equipment_index;
            
            equipment_index = equipment->FirstChildElement ("EquipID");
            
            equipment_index->SetText(device_id); 
            
            equipment_index = equipment_index->NextSiblingElement ("EquipName");
            
            equipment_index->SetText(cross_road_name); 
    
/*************************************************   set system_network  Attribute  ***********************************************/
            XMLElement* system_network = root->FirstChildElement ("system-network");
            
        
            system_network->SetAttribute("ip",ip1);
         
            system_network->SetAttribute("ip_mask",mask1);
         
            system_network->SetAttribute("gateway",gateway1);
     
/*************************************************  set cur_des  Attribute and Text ****************************************************/     
   
           XMLElement* syscong = root->FirstChildElement ("syscong");
       
           XMLElement* cur_des = syscong->FirstChildElement ("cur_des");
           
           XMLElement* cur_des_index;
           
           cur_des_index   = cur_des->FirstChildElement ("cur_one_des");
           cur_des_index->SetAttribute("th_hold_h",a1_warn);
           cur_des_index->SetAttribute("th_hold_l",a1_warn_l);
           cur_des_index->SetText(a3_define);
       
           cur_des_index  = cur_des_index->NextSiblingElement ("cur_two_des");
           cur_des_index->SetAttribute("th_hold_h",a2_warn);
           cur_des_index->SetAttribute("th_hold_l",a2_warn_l);
           cur_des_index->SetText(a2_define);
           
           cur_des_index  = cur_des_index->NextSiblingElement ("cur_three_des");
           cur_des_index->SetAttribute("th_hold_h",a3_warn);
           cur_des_index->SetAttribute("th_hold_l",a3_warn_l);
           cur_des_index->SetText(a1_define);
           
           cur_des_index  = cur_des_index->NextSiblingElement ("cur_four_des");
           cur_des_index->SetAttribute("th_hold_h",b1_warn);
           cur_des_index->SetAttribute("th_hold_l",b1_warn_l);
           cur_des_index->SetText(b3_define);
           
           cur_des_index  = cur_des_index->NextSiblingElement ("cur_five_des");
           cur_des_index->SetAttribute("th_hold_h",b2_warn);
           cur_des_index->SetAttribute("th_hold_l",b2_warn_l);
           cur_des_index->SetText(b2_define);
           
           cur_des_index  = cur_des_index->NextSiblingElement ("cur_six_des");
           cur_des_index->SetAttribute("th_hold_h",b3_warn);
           cur_des_index->SetAttribute("th_hold_l",b3_warn_l);
           cur_des_index->SetText(b1_define);
           
           cur_des_index  = cur_des_index->NextSiblingElement ("cur_seven_des");
           cur_des_index->SetAttribute("th_hold_h",c1_warn);
           cur_des_index->SetAttribute("th_hold_l",c1_warn_l);
           cur_des_index->SetText(c3_define);
           
           cur_des_index  = cur_des_index->NextSiblingElement ("cur_eight_des");
           cur_des_index->SetAttribute("th_hold_h",c2_warn);
           cur_des_index->SetAttribute("th_hold_l",c2_warn_l);
           cur_des_index->SetText(c2_define);
           
           cur_des_index  = cur_des_index->NextSiblingElement ("cur_nine_des");
           cur_des_index->SetAttribute("th_hold_h",c3_warn);
           cur_des_index->SetAttribute("th_hold_l",c3_warn_l);
           cur_des_index->SetText(c1_define);
      
/***************************  Save File ***************************************************************************************/
       if(doc.SaveFile("/etc/sysconf.xml",false)==XML_SUCCESS )
       {
        //printf("save file successfully\n");
       }
/***************************  set ip ***************************************************************************************/       
            if(strcmp(ip_old,ip1)!=0) 
                {
                    change_ip = 1;
                }
           
        }// 
        
        // 使用cgic接口，输出文档类型
        cgiHeaderContentType("text/html;charset=utf-8\r\n\r\n");
       
        TMPL_write("power.html",0,0,mainList,cgiOut,cgiOut);
        
        if(change_ip)
            {
                FILE* fp  ;
                pos = 0 ;
                fp =    fopen( "/etc/network/interfaces", "w+" ); //change ip configure
                pos += sprintf(&ip_set_buf[pos], "auto lo\niface lo inet loopback\n");
                pos += sprintf(&ip_set_buf[pos], "auto eth0\n#iface eth0 inet dhcp\niface eth0 inet static\n"); 
                pos += sprintf(&ip_set_buf[pos], "address  %s\n",ip1); 
                pos += sprintf(&ip_set_buf[pos], "netmask %s\n",mask1); 
                pos += sprintf(&ip_set_buf[pos], "gateway  %s\n",gateway1); 
                
               // pos += sprintf(&ip_set_buf[pos], "auto eth1\n#iface eth1 inet dhcp\niface eth1 inet static\n"); 
               // pos += sprintf(&ip_set_buf[pos], "address  %s\n",ip2); 
               // pos += sprintf(&ip_set_buf[pos], "netmask %s\n",mask2); 
               // pos += sprintf(&ip_set_buf[pos], "gateway  %s\n",gateway2); 
                fputs(ip_set_buf, fp);
            
                //sprintf(ip1_tmp,"ifconfig eth0 %s netmask  %s\n",ip1,mask1);
                // sprintf(ip2_tmp,"ifconfig eth1 %s netmask  %s\n",ip2,mask2);
                //system(ip1_tmp);
                // system(ip2_tmp);
                fclose(fp);
            }
        

    return 0;
}
