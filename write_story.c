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
    sb_down->sem_num = 0;
    sb_down->sem_op = -1;
    semop(sem, sb_down, 1);
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
    char * str = shmat(shm, (void *)0, 0);
    strcpy(str, *next_line);
    //up the semaphore
    struct sembuf * sb_up;
    sb_up->sem_num = 0;
    sb_up->sem_op = 1;
    semop(sem, sb_up, 1);
  }
}
