#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <string.h>
#include <fcntl.h>


union semun {
    int  val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                    (Linux-specific) */
};

int main( int argc, char *argv[]){
  char * arg = argv[1];
  key_t key = ftok("control.c", 'R');
  if(!strcmp(arg, "-c")){ // creating story
    int shm = shmget(key, 256, 0644 | IPC_CREAT | IPC_EXCL);
    int sem = semget(key, 1, 0644 | IPC_CREAT | IPC_EXCL);
    semctl(sem, 0, SETVAL, 1);
    char * file_path;
    strcat(file_path, getcwd());
    strcat(file_path, "story.txt");
    open(file_path, O_CREAT | O_RDWR | O_TRUNC);
  }
}