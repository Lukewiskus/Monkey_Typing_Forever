#include "controller.h"
#define NUM_CORES 2
int main(int argc, char *argv[]) {

    int monkeyPid[NUM_CORES+1]; // array to store children's PIDs
    int currentMonkeyPid;
	char args[2];
    mkdir("output",0777);
	for(int i = 0; i < NUM_CORES; i++){
		if ((currentMonkeyPid = fork())) { 
			//in parent, store pid
			monkeyPid[i] = currentMonkeyPid; 	
		if(currentMonkeyPid == -1){
			//error
			printf("error in forking mapper, errno: %d", errno);
			return 0;
		}
		} else {
            printf("in child\n");
			//in child, call mappers
			sprintf(args, "%d", i);
			execl("./monkey", "monkey", args, NULL);
			// printf("error in exec call on Mapper %d", errno);	

		}
        sleep(1);
	}
    for(int i = 0; i < NUM_CORES; i++){
		while(waitpid(monkeyPid[i],NULL,0) > 0);
		if(errno == -1){
			printf("Error waiting for mappers, errno: %d",errno);
		}
	}
   


}