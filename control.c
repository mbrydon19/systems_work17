#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                (Linux-specific) */
};

int main( int argc, char *argv[]){
  char * arg = argv[1];
  key_t key = ftok("control.c", 'R');
  int shm = shmget(key, 256, 0644 | IPC_CREAT);
  int sem = semget(key, 1, 0644 | IPC_CREAT);

  if(!strcmp(arg, "-c")){ // creating story
    semctl(sem, 0, SETVAL, 1);
    open("story.txt", O_CREAT | O_RDWR | O_TRUNC);
    printf("Created the semaphore and shared memory.\n");
  }

  if(!strcmp(arg, "-r")){ //removing story
      if (semctl(sem, 0, GETVAL)) { //waiing for semahpore to be open
        shmctl(shm, IPC_RMID, NULL);
        semctl(sem, 0, IPC_RMID);
        int f = open("story.txt", O_RDONLY);
        char content[256];
        read(f, content, 256);
        printf("The story:\n%s\n\n", content);
        remove("story.txt");
        printf("Removed the semaphore, the story, and the shared memory.\n");
      }
  }

  if(!strcmp(arg, "-v")){ //viewing story
      int f = open("story.txt", O_RDONLY);
      char content[256];
      read(f, content, 256);
      printf("The story:\n%s\n\n", content);
  }

}
