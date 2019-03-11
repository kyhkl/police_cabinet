#include <stdio.h>
#include <stdlib.h> // exit(0)
#include <sqlite3.h>
#include <pthread.h>//cannot create thread
#include <dlfcn.h>//undefined 
static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int main(int argc, char* argv[])
{
  
  char *array[3]  = {"./main", "hello", "world"};       

    if (argc < 2)
    {  
        printf("error!\n");
        printf("./main str\n");
        return -1;
    }
 
    printf("The first string of your command is:%s\n", argv[0]);
    printf("The second string of your command is:%s\n", argv[1]);
    printf("The third string of your command is:%s\n", argv[2]); 
    
    if (!strcmp(argv[0], array[0])) 
    {
        printf("The first command execute successfully!\n");    
    } 
    if (!strcmp(argv[1], array[1]))
    {
        printf("The second command execute successfully!\n");    
    } 
    if (!strcmp(argv[2], array[2]))
    {
        printf("The third command execute successfully!\n");
    }
 
    return 0;


}
