#include <stdio.h>
#include <stdlib.h> // exit(0)
#include <sqlite3.h>
#include <pthread.h>//cannot create thread
#include <dlfcn.h>//undefined 
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
static int nocall(void *NotUsed, int argc, char **argv, char **azColName){
   return 0;
}
static int callback(void *NotUsed, int argc, char **argv, char **azColName){
  
  
   memcpy(cross_road_name,argv[1],64);
   memcpy(device_id,argv[2],32);
   memcpy(ip1,argv[3],16);
   memcpy(mask1,argv[4],16);
   memcpy(gateway1,argv[5],16);
   memcpy(ip2,argv[6],16);
   memcpy(mask2,argv[7],16);
   memcpy(gateway2,argv[8],16);
   memcpy(a3_define,argv[9],16);
   memcpy(a2_define,argv[10],16);
   memcpy(a1_define,argv[11],16);
   memcpy(b3_define,argv[12],16);
   memcpy(b2_define,argv[13],16);
   memcpy(b1_define,argv[14],16);
   memcpy(c3_define,argv[15],16);
   memcpy(c2_define,argv[16],16);
   memcpy(c1_define,argv[17],16);
   memcpy(a3_warn,argv[18],8);
   memcpy(a2_warn,argv[19],8);
   memcpy(a1_warn,argv[20],8);
   memcpy(b3_warn,argv[21],8);
   memcpy(b2_warn,argv[22],8);
   memcpy(b1_warn,argv[23],8);
   memcpy(c3_warn,argv[24],8);
   memcpy(c2_warn,argv[25],8);
   memcpy(c1_warn,argv[26],8);
       
}

// main已经定义在cgic.c中，在main函数中会调用cgiMain
int cgiMain(int argc, char **argv)
{
    TMPL_varlist *mainList = 0;
    TMPL_varlist *personList = 0;
    TMPL_varlist *netList = 0;
    TMPL_loop    *loop = 0;
    TMPL_loop    *loop1 = 0;
    FILE *fp = NULL;
    char val_buf[2048];
    int pos = 0;
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char * sql;
   char sql_buf[1024]={0};
   const char* data = "Callback function called";
   
	   rc = sqlite3_open("sql.db", &db);//create sqlite
		if( rc ){
		  fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		  return(0);
		}else{
		  fprintf(stderr, "Opened database successfully\n");
	   }
	   
	   
	
		   
      /* Create SQL statement */
      sql = "create table device_info_t(id,cross_road_name,\
      device_id,ip1,mask1,gateway1,ip2,mask2,gateway2,a3_define,\
      a2_define,a1_define,b3_define,b2_define,b1_define,c3_define,\
      c2_define,c1_define,a3_warn,a2_warn,a1_warn,b3_warn,b2_warn,\
      b1_warn,c3_warn,c2_warn,c1_warn); ";

   /* Execute SQL statement */
	   rc = sqlite3_exec(db, sql, nocall, 0, &zErrMsg);
	   if( rc != SQLITE_OK ){
	   fprintf(stderr, "SQL error: %s\n", zErrMsg);
		  sqlite3_free(zErrMsg);
	   }else{
		  fprintf(stdout, "Table created successfully\n");
	   }  
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
		
		
			//update info
			strcat(sql_buf, "update  device_info_t set  cross_road_name='");
			strcat(sql_buf, cross_road_name);
			strcat(sql_buf,"' ,device_id='");
			strcat(sql_buf, device_id);
			
			strcat(sql_buf,"' ,ip1='");
			strcat(sql_buf, ip1);
			strcat(sql_buf,"' ,mask1='");
			strcat(sql_buf, mask1);
			strcat(sql_buf,"' ,gateway1='");
			strcat(sql_buf, gateway1);
			strcat(sql_buf,"' ,ip2='");
			strcat(sql_buf, ip2);
			strcat(sql_buf,"' ,mask2='");
			strcat(sql_buf, mask2);
			strcat(sql_buf,"' ,gateway2='");
			strcat(sql_buf, gateway2);
			
			strcat(sql_buf,"' ,a3_define='");
			strcat(sql_buf, a3_define);
			strcat(sql_buf,"' ,a2_define='");
			strcat(sql_buf, a2_define);
			strcat(sql_buf,"' ,a1_define='");
			strcat(sql_buf, a1_define);
			
			strcat(sql_buf,"' ,b3_define='");
			strcat(sql_buf, b3_define);
			strcat(sql_buf,"' ,b2_define='");
			strcat(sql_buf, b2_define);
			strcat(sql_buf,"' ,b1_define='");
			strcat(sql_buf, b1_define);
			
			strcat(sql_buf,"' ,c3_define='");
			strcat(sql_buf, c3_define);
			strcat(sql_buf,"' ,c2_define='");
			strcat(sql_buf, c2_define);
			strcat(sql_buf,"' ,c1_define='");
			strcat(sql_buf, c1_define);
			
			strcat(sql_buf,"' ,a3_warn='");
			strcat(sql_buf, a3_warn);
			strcat(sql_buf,"' ,a2_warn='");
			strcat(sql_buf, a2_warn);
			strcat(sql_buf,"' ,a1_warn='");
			strcat(sql_buf, a1_warn);
			
			strcat(sql_buf,"' ,b3_warn='");
			strcat(sql_buf, b3_warn);
			strcat(sql_buf,"' ,b2_warn='");
			strcat(sql_buf, b2_warn);
			strcat(sql_buf,"' ,b1_warn='");
			strcat(sql_buf, b1_warn);
			
			strcat(sql_buf,"' ,c3_warn='");
			strcat(sql_buf, c3_warn);
			strcat(sql_buf,"' ,c2_warn='");
			strcat(sql_buf, c2_warn);
			strcat(sql_buf,"' ,c1_warn='");
			strcat(sql_buf, c1_warn);
			
			
			strcat(sql_buf,"'  where id=1;");
			printf("%s",sql_buf);
			/* Execute SQL statement */
		   rc = sqlite3_exec(db, sql_buf, nocall, (void*)data, &zErrMsg);
		   if( rc != SQLITE_OK ){
			  fprintf(stderr, "SQL error: %s\n", zErrMsg);
			  sqlite3_free(zErrMsg);
		   }else{
			   sql="successfully";
			  fprintf(stdout, "write successfully\n");
		   }    
	}// have get the data 

	sql="select * from device_info_t where id =1;";
	rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
		   if( rc != SQLITE_OK ){
			  fprintf(stderr, "SQL error: %s\n", zErrMsg);
			  sqlite3_free(zErrMsg);
		   }else{
			  fprintf(stdout, "read successfully\n");
		   }
    // 使用cgic接口，输出文档类型
    cgiHeaderContentType("text/html;charset=utf-8");
    // 把两个家族成员的值加到一个TMPL_loop中，用来显示在表格中
    
    
    
    // 所有的值都必须是字符串形式
    personList = TMPL_add_var(0,"addr_name",cross_road_name,"device_id",device_id,0);
    loop = TMPL_add_varlist(loop, personList);
    // 再把这个TMPL_loop嵌到值列表中，名字是“Persons”，要与模板中的名字一样
    mainList = TMPL_add_loop(mainList, "address_name", loop);
    // 把值列表在模块中显示，模块文件的路径根据需要更改
    netList= TMPL_add_var(netList,"a3_define",a3_define,"a2_define",a2_define,0);  
    netList= TMPL_add_var(netList,"a1_define",a1_define,"b3_define",b3_define,0); 
    netList= TMPL_add_var(netList,"b2_define",b2_define,"b1_define",b1_define,0); 
    netList= TMPL_add_var(netList,"c3_define",c3_define,"c2_define",c2_define,0); 
    netList= TMPL_add_var(netList,"c1_define",c1_define,"a3_warn",a3_warn,0); 
    netList= TMPL_add_var(netList,"a2_warn",a2_warn,"a1_warn",a1_warn,0); 
    netList= TMPL_add_var(netList,"b3_warn",b3_warn,"b2_warn",b2_warn,0); 
    netList= TMPL_add_var(netList,"b1_warn",b1_warn,"c3_warn",c3_warn,0); 
    netList= TMPL_add_var(netList,"c2_warn",c2_warn,"c1_warn",c1_warn,0); 
    loop1 = TMPL_add_varlist(loop1, netList);
    
    mainList = TMPL_add_loop(mainList, "define", loop1);
	TMPL_write("/www/htdocs/power.html",0,0,mainList,cgiOut,cgiOut);
    
    fp=fopen( "val.txt", "w+" );
    pos = sprintf(&val_buf[pos], "{\"cross_road_name\":\"%s\",\r\n",cross_road_name);
    pos += sprintf(&val_buf[pos], "\"device_id\":\"%s\",\r\n",device_id);
    pos += sprintf(&val_buf[pos], "\"ip1\":\"%s\",\r\n",ip1);
    pos += sprintf(&val_buf[pos], "\"mask1\":\"%s\",\r\n",mask1);
    pos += sprintf(&val_buf[pos], "\"gateway1\":\"%s\",\r\n",gateway1);
    pos += sprintf(&val_buf[pos], "\"ip2\":\"%s\",\r\n",ip2);
    pos += sprintf(&val_buf[pos], "\"mask2\":\"%s\",\r\n",mask2);
    pos += sprintf(&val_buf[pos], "\"gateway2\":\"%s\",\r\n",gateway2);
    pos += sprintf(&val_buf[pos], "\"a3_define\":\"%s\",\r\n",a3_define);
    pos += sprintf(&val_buf[pos], "\"a2_define\":\"%s\",\r\n",a2_define);
    pos += sprintf(&val_buf[pos], "\"a1_define\":\"%s\",\r\n",a1_define);
    pos += sprintf(&val_buf[pos], "\"b3_define\":\"%s\",\r\n",b3_define);
    pos += sprintf(&val_buf[pos], "\"b2_define\":\"%s\",\r\n",b2_define);
    pos += sprintf(&val_buf[pos], "\"b1_define\":\"%s\",\r\n",b1_define);
    pos += sprintf(&val_buf[pos], "\"c3_define\":\"%s\",\r\n",c3_define);
    pos += sprintf(&val_buf[pos], "\"c2_define\":\"%s\",\r\n",c2_define);
    pos += sprintf(&val_buf[pos], "\"c1_define\":\"%s\",\r\n",c1_define);
    pos += sprintf(&val_buf[pos], "\"a3_warn\":\"%s\",\r\n",a3_warn);
    pos += sprintf(&val_buf[pos], "\"a2_warn\":\"%s\",\r\n",a2_warn);
    pos += sprintf(&val_buf[pos], "\"a1_warn\":\"%s\",\r\n",a1_warn);
    pos += sprintf(&val_buf[pos], "\"b3_warn\":\"%s\",\r\n",b3_warn);
    pos += sprintf(&val_buf[pos], "\"b2_warn\":\"%s\",\r\n",b2_warn);
    pos += sprintf(&val_buf[pos], "\"b1_warn\":\"%s\",\r\n",b1_warn);
    pos += sprintf(&val_buf[pos], "\"c3_warn\":\"%s\",\r\n",c3_warn);
    pos += sprintf(&val_buf[pos], "\"c2_warn\":\"%s\",\r\n",c2_warn);
    pos += sprintf(&val_buf[pos], "\"c1_warn\":\"%s\"\r\n}",c1_warn);
	
     fputs(val_buf, fp);
    
    sqlite3_close(db);//create sqlite
    return 0;
}
