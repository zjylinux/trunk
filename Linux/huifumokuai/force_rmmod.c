#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/completion.h>



static int __init force_init(void)
{
	complete((struct completion *)0000000000000000);
	printk("%d,%s,%s11111111111111111\n",__LINE__,__FILE__,__func__);
	return 0;
	}
	
static void __exit force_exit(void)
{
	printk("%d,%s,%s222222222222222222222\n",__LINE__,__FILE__,__func__);
	}

module_init(force_init);
module_exit(force_exit);
MODULE_LICENSE("Dual BSD/GPL");
