
#include <sys/types.h>
#include <unistd.h>
#include <iostream> 
#include <cstdlib>
#include <csignal>
using namespace std;

void process1(void){
    int counter = 0; // counter variable

    while(true){ // forever loop
        counter++;  // increment
        if(counter % 3 == 0){
        std::cout << "Cycle number:" << counter << " - " << counter <<" is a multiple of \n";
        }
        else{
             std::cout << "Cycle number " << counter << "\n";
        }
         sleep(1); // 1 sleep
    }
}


int main(void){
    signal(SIGTERM, [](int){ 
        cout << "\nProcess1 PID: " << getpid() << endl; 
        exit(0); 
    });
    signal(SIGINT, [](int){ 
        cout << "\nProcess1 PID: " << getpid() << endl; 
        exit(0); 
    });


    pid_t pid = fork();

    if( pid == -1){
        exit(EXIT_FAILURE);
    }
    else if( pid > 0){
        process1();
    }
    else{
        system("exec ./Process2");
    }
}
