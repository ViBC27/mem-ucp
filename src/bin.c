#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 
#include <sys/wait.h> 

void father(char argv[], char cpu_info[], char memory_info[], int i)
{

  // The increase happens every second. The process of displaying the requested information is limited to ten seconds/times.
  if(i == 10) return; 
  else
  {

    // The clock function is being used to measure time.
    clock_t start, end;
    int time = 1000; // Time in milliseconds.

    end = (time/1000) * CLOCKS_PER_SEC;
    start = clock();
    
    // The while is enabled until a second passes. After that, the information requested by the user is displayed.
    while((clock() - start) < end){}; 

    if(strcmp(argv, "ucp") == 0)
      system(cpu_info); // Enter in the terminal what is contained in the string cpu_info.

    else
      system(memory_info); // Enter in the terminal what is contained in the string memory_info.

    start = clock();
    father(argv, cpu_info, memory_info, i + 1);

  }
}

void child(char argv[], char cpu_info[], char memory_info[])
{

  // Checks if the user input argument matches one of the two available options.

  if(strcmp(argv, "ucp") == 0)
    for(;;){}

  else
  {

    for(;;)
    {

      // The clock function is being used to measure time.
      clock_t start, end;
      int time = 1000; // Time in milliseconds.

      end = (time/1000) * CLOCKS_PER_SEC;
      start = clock();

      // Here it makes successive dynamic memory allocations for a period of one second.
      while((clock() - start) < end)
        malloc(sizeof(long double) * 10);
    }
  }
}

int main(int argc, char *argv[])
{


  // Checks if input arguments are valid.
  if(strcmp(argv[1], "ucp") != 0 && strcmp(argv[1], "ucp-mem") != 0)
    printf("Invalid command!\n");
 
  else
  {

    if(strcmp(argv[1], "ucp") == 0) printf("\tCPU(%%)\n");
    else printf("\tMEMORY\n");

    // Creation of a new process. 
    pid_t pid = fork();

    // Storage of commands to access information from memory and cpu.
    char cpu_info[50], memory_info[50];
    sprintf(cpu_info, "ps -p %d -o %%cpu | grep -v CPU", pid);
    sprintf(memory_info, "pmap %d | grep -i total", pid);
     
    //Command storage to kill process.
    char kill_command[25];
    sprintf(kill_command, "kill -9 %d", pid);

    if(pid == 0)
    {
     
      // Code area of the child process - new process.
      child(argv[1], cpu_info, memory_info);

    }

    else if(pid > 0)
    {

      // Code area of the father process.
      father(argv[1], cpu_info, memory_info, 0);
      printf("Sucess!\n"); // End of software.    
      system(kill_command); // Command to kill the process.

    }

    else printf("Error!\n"); // If the creation of the new failed process.
  }

  return 0;
}

// For more information visit my repository https://github.com/ViBC27/ucp-mem
