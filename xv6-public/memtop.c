#include "types.h"
#include "user.h"

int
main(int argc, char *argv[]){
  int mm_av = memtop();
  printf(1, "available memory: %d\n", mm_av);
  exit();
}
