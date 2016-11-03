#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>



int main() {
  int size = 0;

  printf("Statistics for PWD:\n");
  
  DIR *files = opendir(".");
  struct dirent *current;
  struct stat sizes;

  printf("Directories:\n");
  while((current = readdir(files))) {
    if( current->d_type == DT_DIR ) {
      printf("Directory:\t%s\n", current->d_name);
    }
    else {
      printf("%s\n", current->d_name);
      stat(current->d_name, &sizes);
      size += sizes.st_size;
    }
  }
  closedir(files);

  printf("Total size of PWD: %d Bytes\n", size);
  
  return 0;
}
