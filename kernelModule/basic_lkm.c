#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

int basic_init(void)
{
  printk(KERN_EMERG"Kernel Module Loaded\n");
  return 0;
}

void basic_exit(void)
{
  printk(KERN_EMERG"Kernel Module Removed\n");
}

module_init(basic_init);
module_exit(basic_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Basic Kernel Module");
MODULE_AUTHOR("NIRJHAR");
