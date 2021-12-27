#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/completion.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define NAME "myled"

int major;
char kbuf[128]={0};
ssize_t myled_read (struct file *file, char __user *user, size_t size, loff_t *loff)
{
	int ret;
	printk("myled_read\n");
	if (size >sizeof(kbuf)) size = sizeof(kbuf);
	ret = copy_to_user(user,kbuf,size);
	if (ret)
	{
		printk("copy data to user error");
		return -EINVAL;
	}
	return size;
}
ssize_t myled_write (struct file *file, const char __user *user, size_t size, loff_t *loff)
{
	int ret;
	printk("myled_write\n");
	if (size >sizeof(kbuf)) size = sizeof(kbuf);
	ret = copy_from_user(kbuf,user,size);
	if (ret)
	{
		printk("copy data from user error");
		return -EINVAL;
	}
	return size;
}
int myled_open (struct inode *inode, struct file *file)
{
	printk("myled_open\n");
	return 0;
}
int myled_close (struct inode *inode, struct file *filp)
{
	printk("myled_close\n");
	return 0;
}
const struct file_operations fops = {
	.open = myled_open,
	.read = myled_read,
	.write = myled_write,
	.release = myled_close,
	
	};
static int __init hello_init(void)
{
	major=register_chrdev(0, NAME, &fops);
	if (major < 0)
		{
			printk("rejister cdev FAILD major=%d\n",major);
			return major;
			}

	printk("%d,%s,%s11111111111111111\n",__LINE__,__FILE__,__func__);

	return 0;
	}
	
static void __exit hello_exit(void)
{
	unregister_chrdev(major, NAME);
	printk("%d,%s,%s222222222222222222222\n",__LINE__,__FILE__,__func__);
	}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("zhang jiao yang");
