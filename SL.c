#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct{
  char dname[10], fname[10][10];
  int fcnt;
}dir;
int main() {
  int i,n;
  char f[10];
  char a[10];
  dir.fcnt=0;
  printf("Enter directory name :\n");
  scanf("%s",dir.dname);
  while(1) {
    printf("choose an option :\n1.Create file\n2.Delete file\n3.Search file\n4.Display\n5.Exit\n");
    scanf("%d",&n);
    switch (n) {
      case 1:
      {
      printf("Enter the file name:\n");
      scanf("%s",f);
      for(i=0;i<dir.fcnt;i++)
      {
		if(strcmp(f,dir.fname[i])==0)
		{
			printf("file %s already exists",f);
			break;
		}
      }
      if(i==dir.fcnt)
	strcpy(dir.fname[dir.fcnt],f);
      dir.fcnt++;
      break;
      }

     case 2:
      {
      printf("Enter the file name:\n");
      scanf("%s",f);
      for( i = 0;i<dir.fcnt;i++)
      {
		if(strcmp(f,dir.fname[i])==0)
		{
			printf("file %s is deleted",f);
			strcpy(dir.fname[i],dir.fname[dir.fcnt-1]);
			break;
		}
      }
   		if(i==dir.fcnt)
		{
			printf("file %s is not found",f);
		}
		else
			dir.fcnt--;
		break;
      }
      case 3:
      {
      printf("Enter the file name:");
      scanf("%s",f);
      for(i = 0; i<dir.fcnt; i++)
      {
        if (strcmp(f,dir.fname[i])==0)
	{
		printf("file %s is found",f);
		break;
        }
      }
	if(i==dir.fcnt)
	printf("File Not Found !");
      break;
      }
      case 4:
      {
      // if(dir.fcnt==0)
      printf("Directory\tFiles\n");

      for (i = 0; i <dir.fcnt; i++) {
        printf("\t%s\n",dir.fname[i]);
      }
      break;
      }
      case 5:printf("\nexiting.......\n");
      exit(0);
      default:
	printf("Invalid Input\n");
    }
  }
}
