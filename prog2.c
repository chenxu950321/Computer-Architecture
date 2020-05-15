#include "types.h"
#include "stat.h"
#include "user.h"
int main(int argc, char *argv[])
{
  set(20);
  int i,k;
  const int loop = 43000;
  for (i = 0; i < loop; i++)
  {
    asm("nop");
    for (k = 0; k < loop; k++) asm("nop");
    //if (i % 1000 == 0) printInfo();
  }
  //printInfo();
  exit();
}
