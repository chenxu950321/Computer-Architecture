#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"
#include "x86.h"
#include "thread.h"

struct lock_t lock;

void thread_create(void *(*start_routine)(void*), void *arg){
    void *stack = malloc(PGSIZE * 2);
    //stack += PGSIZE;
    if ((uint)stack % PGSIZE)
        stack += (2 * PGSIZE - (uint)stack % PGSIZE);
    int id = 0;
    //stack -= PGSIZE;
    id = clone(stack, PGSIZE * 2);
    if (id == 0){
        (*start_routine)(arg);
        free(stack);
        exit();
    }  
}

void lock_init(struct lock_t *lk){
     lk->locked = 0;
}

void lock_acquire(struct lock_t *lk){
    while(xchg(&lk->locked, 1) != 0) ;
}

void lock_release(struct lock_t *lk){
    xchg(&lk->locked, 0);
}
