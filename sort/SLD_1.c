#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct dir{
  char dname[10];
  char fname[10][10];
  int fcnt;
};
int main() {
  int i,n;
  char fn[10];
  struct  dir f;
  char dir[10];
  int pos = 0;
  printf("Enter directory name :\n");
  scanf("%s",dir);
  do {
    printf("choose an option :\n1.Create file\n2.Delete file\n3.Search file\n4.Display\n5.Exit\n");
    scanf("%d",&n);
    switch (n) {
      case 1:
      printf("Enter the file name:\n");
      scanf("%s",f.fname[pos]);
      pos++;
      printf("%s created !\n",f.fname[pos]);
      break;
      case 2:
      printf("Enter the file name:\n");
      scanf("%s",fn);
      int i = 0;
      while (i<pos){
        if (f.fname[pos] == fn) {
          printf("File Found\n");
          while (i<pos) {
          strcpy(f.fname[i],f.fname[i+1]);
            i++;
          }
          strcpy(f.fname[i],"\0");
          pos--;
          printf("File Deleted\n");
          }
          i++;
        }
        break;
      case 3:
      printf("Enter the file name:");
      scanf("%s",fn);
      for(i = 0; i<pos; i++)
      {
        if (f.fname[i] == fn) {
          printf("File found !");
          break;
        }
      }printf("File Not Found !");
      break;
      case 4:
      printf("Directory\tFiles\n");
      printf("%s",dir);
      for (i = 0; i < pos; i++) {
        printf("\t%s\n",f.fname[i]);
      }
      break;
      case 5:printf("\nBye !\n");
      exit(0);
      default: printf("Invalid Input\n");
    }
  } while(1);
  return 0;
}
