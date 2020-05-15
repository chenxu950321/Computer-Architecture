#include "types.h"
#include "stat.h"
#include "user.h"
#include "thread.h"
#define DEBUG 0

struct lock_t* lock;
//number of pass
static int pass = 0;
// number of thread 
static int numofthread;

static int MAXpass;
static int turn = 0;
void* frisbee();

void* frisbee(void* arg){
    int pidnum = (int)arg;
    while(pass < MAXpass){
        lock_acquire(lock);
        if (pass == MAXpass){
            sleep(1);
            break;
        }
        if (numofthread == 0) break;
        if (pidnum == turn){
            pass++;
            printf(2, "pass number no:%d, thread %d is passing the token to ",pass, pidnum);  
            turn = pidnum + 1;
            if (turn == numofthread) turn = 0;           
            printf(2, "thread %d\n", turn);
            sleep(1);
            lock_release(lock);
            sleep(1);
        }
        else{
            printf(1, "this is not a valid pid\n");
            lock_release(lock);
            sleep(1);
        }
    }
    lock_release(lock);
    exit();
}

int main ( int argc, char* argv []){
    if (argc != 3){
        printf(1, "Usage: frisbee #ofThread #ofPass");
        exit();
    }
    numofthread = atoi(argv[1]);
    MAXpass = atoi(argv[2]);

    int i = 0;
    lock_init(lock);
    for (i = 0; i < numofthread; i++){
        thread_create(frisbee, (void *)i);
    }
    for (i = 0; i < numofthread; i++){
        wait();
    }
    printf(1, "\nSimulation of Frisbee game has finished, %d rounds were played in total\n", MAXpass);
    exit();
}

    
