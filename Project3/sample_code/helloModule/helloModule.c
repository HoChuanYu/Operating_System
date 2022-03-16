#include <linux/module.h>
#include <linux/kernel.h>

static int studentId = 12345;	//Change with your Student ID without leading 0

static int initialize(void)
{
	printk(KERN_INFO "[%d] : Function [%s] - Hello from OS Project 03!\n", studentId,__func__);
	return 0;
}

static void clean_exit(void){
	printk(KERN_INFO "[%d] : Function [%s] - Unloading module. Goodbye from OS Project 03!\n", studentId,__func__);
}

module_init(initialize);
module_exit(clean_exit);
