//Akshay Sharma
//MT2024016
// Write a program, call fork and print the parent and child process id.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
    pid = fork();

    if (pid < 0)
    {
        perror("Fork failed\n");
        return 1;
    }
    else if (pid == 0)
    { // current is child
        printf("Child process ID:%d\n", getpid());
        printf("Parent Process Id (from child): %d\n", getppid());
    }
    else
    { // current is parent
        printf("Parent process ID:%d\n", getpid());
        printf("Child process ID (from parent):%d\n", pid);
    }
    return 0;
}

/* output
Parent process ID:93179
Child process ID (from parent):93180
Child process ID:93180
Parent Process Id (from child): 93179*/