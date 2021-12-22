#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/completion.h>

int hello = 10;
module_param(hello,int,0664);
MODULE_PARM_DESC(hello,"this is a int");

char hello_byte = 100;
module_param(hello_byte,byte,0664);
MODULE_PARM_DESC(hello_byte,"this is a byte");

char *hello_charp = "hello word";
module_param(hello_charp,charp,0664);
MODULE_PARM_DESC(hello_charp,"this is a hello_charp");

int num;
unsigned int hello_array[20] = {0};
module_param_array(hello_array, uint, &num, 0664);
MODULE_PARM_DESC(hello_array,"this is a hello_array");

static int __init hello_init(void)
{
	int i;
	printk("hello=%d\n",hello);
	printk("hello_byte=%d\n",hello_byte);
	printk("hello_charp=%s\n",hello_charp);
	for(i=0;i<num;i++)
	printk("hello_array[%d]=%d\n",i,hello_array[i]);
	printk("%d,%s,%s11111111111111111\n",__LINE__,__FILE__,__func__);

	return 0;
	}
	
static void __exit hello_exit(void)
{
	printk("%d,%s,%s222222222222222222222\n",__LINE__,__FILE__,__func__);
	}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("zhang jiao yang");