int main(){
    key_t key = ftok("control.c", 'R');
    int sem = semget(key, 1, IPC_EXCL);
    if (semctl(sem, 0, GETVAL)){
      struct sembuf * sb_down;
      sb.sem_num = 0;
      sb.sem_op = -1;
      semop(sem, 1, sb_down);
    printf("Last line of the story: %s\n", );
    printf("Enter the next line of the story!:\n");
    char * next_line[256];
    scanf("%s", &next_line);
    int file = open("story.txt", O_WRONLY);
    write(file, next_line, 256);
    int shm = shmget(key, 256, IPC_EXCL);
    shmat(shm, )
  }
