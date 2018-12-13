#include <stdio.h>
#include <sys.shm.h>
#include <sys.ipc.h>
#include <sys.types.h>
#include <sys/types.h>
#include <sys.sem.h>
// define keys ftok?

// union semun {
//                int              val;    /* Value for SETVAL */
//                struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
//                unsigned short  *array;  /* Array for GETALL, SETALL */
//                struct seminfo  *__buf;  /* Buffer for IPC_INFO
//                                            (Linux-specific) */
//            };

int main(){
  // take command line arg
  // char * arg = malloc(2);
  // scanf("%s", &arg);
  if(strcmp(arg, "-c")){ // creating story
    int shm = shmget(/*key*/, 256, IPC_CREAT | IPC_EXCL);
    int sem = semget(/*key*/, 1, IPC_CREAT | IPC_EXCL);
    semctl(sem, 0, SETVAL, )
    char * file_path = malloc(256);
    strcat(file_path, getcwd());
    strcat(file_path, "story.txt");
    open(file_path, O_CREAT | O_RDWR | O_TRUNC);
  }
}
