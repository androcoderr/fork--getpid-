  
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int main(){
  pid_t pid = fork();

  if (pid < 0) {
    // hata durumu
    perror("fork failed");
    return 1;
  } else if (pid == 0) {
    // çocuk process
    printf("Çocuk process çalışıyor (PID: %d)\n", getpid());
    sleep(2); // 2 saniye bekle
    printf("Çocuk process sonlanıyor.\n");
  } else {
    // ana process
    printf("Ana process çalışıyor (PID: %d)\n", getpid());
    sleep(5); // 5 saniye bekle
    printf("Ana process sonlanıyor.\n");
  }
  return 0;
}