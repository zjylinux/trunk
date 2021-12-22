#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/completion.h>

int add (int a,int b)
{
	return a+b;
}

static int __init hello_init(void)
{
	printk("%d,%s,%s11111111111111111\n",__LINE__,__FILE__,__func__);
	return 0;
	}
	
static void __exit hello_exit(void)
{
	printk("%d,%s,%s222222222222222222222\n",__LINE__,__FILE__,__func__);
	}

EXPORT_SYMBOL_GPL(add);
module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
