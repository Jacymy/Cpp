#include <pthread.h>
#include <sys/syscall.h>
#include <unistd.h>

#include <iostream>

pthread_mutex_t lock;

int x = 100;
int y = 200;

void *a(void *arg) {
  while (1) {
    pthread_mutex_lock(&lock);
    x -= 50;
    y += 50;
    printf("tid1 = %lu.\n", pthread_self());
    pthread_mutex_unlock(&lock);
    sleep(1);
    break;
  }
  return (void *)0;
}

void *b(void *arg) {
  while (1) {
    pthread_mutex_lock(&lock);
    std::cout << "x + y = " << x + y << std::endl;
    printf("tid2 = %lu.\n", pthread_self());
    pthread_mutex_unlock(&lock);
    sleep(1);
    break;
  }
  return (void *)0;
}

int main(const int argc, const char *argv[]) {
  pthread_t tid1, tid2;
  printf("sub thread:\ntid1 = %lu, tid2 = %lu\n", tid1, tid2);
  pthread_mutex_init(&lock, NULL);

  pthread_create(&tid1, NULL, a, NULL);
  pthread_create(&tid2, NULL, b, NULL);
  printf("tid1 = %lu, tid2 = %lu\n", tid1, tid2);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  printf("main thread:\nid = %lu\n", pthread_self());
  printf("main thread:\nid = %lu\n", syscall(SYS_gettid));
  std::cout << "sub threads have stopped,main thread will exit." << std::endl;
  pthread_mutex_destroy(&lock);

  return 0;
}
