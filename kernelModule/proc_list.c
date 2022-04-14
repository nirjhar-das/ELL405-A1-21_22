#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>


int procls_init(void){
  struct task_struct *t;
  for_each_process(t){
    if(t->state == TASK_RUNNING)
      printk(KERN_INFO "Command: %s, State: %s, PID: %d\n", t->comm, "Running", t->pid);
    else if(t->state == TASK_INTERRUPTIBLE)
      printk(KERN_INFO "Command: %s, State: %s, PID: %d\n", t->comm, "Interruptible", t->pid);
    else if(t->state == TASK_UNINTERRUPTIBLE)
      printk(KERN_INFO "Command: %s, State: %s, PID: %d\n", t->comm, "Uninterruptible", t->pid);
    else if(t->state == __TASK_STOPPED)
      printk(KERN_INFO "Command: %s, State: %s, PID: %d\n", t->comm, "Stopped", t->pid);
    else if(t->state == __TASK_TRACED)
      printk(KERN_INFO "Command: %s, State: %s, PID: %d\n", t->comm, "Traced", t->pid);
    else
      printk(KERN_INFO "Command: %s, State: %s, PID: %d\n", t->comm, "Unknown", t->pid);
    }
  return 0;
}

void procls_exit(void){
  printk(KERN_INFO "Module exited\n");
}

module_init(procls_init);
module_exit(procls_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Kernel Module to List All Processes");
MODULE_AUTHOR("NIRJHAR");
