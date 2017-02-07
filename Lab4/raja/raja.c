#include<linux/kernel.h>
asmlinkage long sys_raja(void)
{
	printk("raja\n");
	return 0;
}
