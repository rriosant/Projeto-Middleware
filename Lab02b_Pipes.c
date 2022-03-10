#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int value=5;

int main ()
{
  int pipefds[2];
  
  if (pipe(pipefds) ==-1)
  {
    printf("Deu erro");
    return 1;
    
  }
  int pid = fork();

  if (pid ==0){
    close(pipefds[0]);
    printf("Entrei no filho!\n");
    value +=15;
    printf("CHILD: value=%d\n",value);
    write(pipefds[1], &value, sizeof(int));
    close(pipefds[1]);
    
    
    
    
  }
  else if (pid>0){
    wait(NULL);
    close(pipefds[1]);
    int value2;
    read(pipefds[0],&value2, sizeof(int));
    close(pipefds[0]);
    printf("PARENT: value=%d\n", value2);
  }
  return 0;
}