#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int hold;
  
  for(int i = 1; i<argc; i++){
    if(i == argc - 1){
      if(i == 1){
	hold = dup(0);
      }
      int return_code = fork();
      if (return_code == 0) {
      	dup2(hold,0);
	execlp(argv[i], argv[i], NULL);
      } else if (return_code > 0) {
	int pid = return_code;
	int status = 0;
 	waitpid(pid, &status, 0);
	if(pid == -1){
	  perror("error");
	  exit(EXIT_FAILURE);
	}
	if(WIFEXITED(status)){
	  if(errno != 0){
	    exit(errno);
	  }
	}
      } else {
	printf("Child process creation error! \n");
      }
     
    }
    int fds[2];
    pipe(fds);
    int return_code = fork();
    if(return_code == 0){
      if(i == 1){
	dup2(fds[1],1);
	close(fds[1]);
	close(fds[0]);
	execlp(argv[i],argv[i], NULL);
	/*}else if(i == argc-1){
	dup2(fds[0],0);
	close(fds[0]);
	close(fds[1]);
	execlp(argv[i],argv[i], NULL);*/
      }else{
	dup2(fds[1],1);
	dup2(hold,0);
	close(fds[0]);
        close(fds[1]);
	execlp(argv[i],argv[i],NULL);
      }
    }else if(return_code > 0){
      int pid = return_code;
      int status = 0;
      waitpid(pid, &status, 0);
      if(pid == -1){
	perror("error");
	exit(EXIT_FAILURE);
      }
      if(WIFEXITED(status)){
	if(errno != 0){
	  exit(errno);
	}
      }
      close(fds[1]);
      hold = dup(fds[0]);
      close(fds[0]);
      
    }else{
      printf("oooh owie ouch ouchy. No good, uh uh. Big bad boo boo in to opowating systowm\n");
      perror("fork");
      exit(EXIT_FAILURE);
    }
  }
    
  return 0;
}

