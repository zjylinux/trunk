#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/completion.h>

extern int add(int a, int b);

static int __init hello_init(void)
{
	//int sum;
	printk("sum=%d\n",(add(10,30)));
	return 0;
	}
	
static void __exit hello_exit(void)
{
	printk("%d,%s,%s222222222222222222222\n",__LINE__,__FILE__,__func__);
	}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
