#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

struct proc_info
{
    int pid;            
    int memsize;          
};


int main(int argc, char *argv[]) 
{
    struct proc_info ptable[NPROC];
    struct proc_info *p;
    int err;

    err = proc_dump(NPROC * sizeof(struct proc_info), &ptable);
    if (err != 0)
        printf(1, "Table doesn't exist!");

    p = &ptable[0];

    while (p != &ptable[NPROC - 1]) 
    {
        if (p->memsize > 0) 
        {
            printf(1, "PID: %d    |   MEMSIZE: %d\n", p->pid, p->memsize);
        }
        p++;
    }

    exit();
}