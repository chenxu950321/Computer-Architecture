

#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char **argv)
{
  if (argc != 2){
    printf(1 ,"wrong argument\n");
    exit();
  }
  int choice = atoi(argv[1]);
  int count = info(choice);
  if (count != -2 && count != -1){
    if (choice == 1)
      printf(1, "the total count of running processes in the system is: %d\n",count);
    if (choice == 2)
      printf(1, "the total count of system calls created by the cucrrent process is: %d\n", count);
    if (choice == 3)
      printf(1, "the num of memory pages which the current process is using is: %d\n",count);
    exit();
  }
  printf(1, "error..\n");
  exit();
}
