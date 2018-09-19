#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#define N 100

void *thread(void *arg) {
  char *ret;
  printf("Thread # %d\n", arg);
  
  pthread_exit(NULL);
}

main() {
  pthread_t thid;
  void *ret;


  for(int i = 0; i < N; i++){
    pthread_create(&thid, NULL, thread, i);
    printf("Thread # %d created\n", i);

    pthread_join(thid, &ret);
  }
}
