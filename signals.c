#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>

static void sighandler(int signo){
  if (signo == SIGINT){
    char ext_mess[17] = "exited to SIGINT\n";
    int fil = open( "log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644  );
    write(fil, ext_mess, sizeof(ext_mess));
    close(fil);
    exit(1);
  }
  if (signo == SIGUSR1){
    printf("PPID %d\n", getppid());
  }
}

int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  while (1){
    printf("PID %d\n", getpid());
    sleep(1);
  }
  return 0;
}
