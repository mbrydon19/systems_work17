#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  key_t key = ftok("control.c", 'R');
  int sem = semget(key, 1, IPC_EXCL);
  if (semctl(sem, 0, GETVAL)){
    //down the semaphore
    struct sembuf * sb_down;
    sb.sem_num = 0;
    sb.sem_op = -1;
    semop(sem, 1, sb_down);
    //get and print last line
    char * last_line[256];
    shmat(key, last_line, 256);
    printf("Last line of the story: %s\n", last_line);
    //asks for next line
    printf("Enter the next line of the story!:\n");
    char * next_line[256];
    scanf("%s", &next_line);
    //write next line to story file
    int file = open("story.txt", O_WRONLY);
    write(file, next_line, 256);
    //put next line into shared memory
    int shm = shmget(key, 256, IPC_EXCL);
    shmat(shm, )
    //up the semaphore
    struct sembuf * sb_up;
    sb.sem_num = 0;
    sb.sem_op = 1;
    semop(sem, 1, sb_up);
  }
