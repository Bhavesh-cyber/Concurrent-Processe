
#include <sys/types.h>
#include <unistd.h>
#include <iostream> 
#include <cstdlib>
#include <csignal>
using namespace std;

void process2(void){
    int counter = 0; // counter variable
    int cycle = 0; // cycle counter

    while(true){ // forever loop

        counter--;  // increment

        if(counter % 3 == 0){
        std::cout << "Cycle number:" << (cycle + 1) << " - " << counter <<" is a multiple of 3\n";
        }
        else{
             std::cout << "Cycle number " << cycle << "\n";
        }
        cycle++;
        sleep(1); // 1 sleep
    }
}
int main(void){
    signal(SIGTERM, [](int){ 
        cout << "\nProcess2 PID: " << getpid() << endl; 
        exit(0); 
    });
    signal(SIGINT, [](int){ 
        cout << "\nProcess2 PID: " << getpid() << endl; 
        exit(0); 
    });

    pid_t pid = fork();

    if( pid == -1){
        exit(EXIT_FAILURE);
    }
    else if( pid > 0){
        process2();
     }
     else{
        return 0;
     }
}
