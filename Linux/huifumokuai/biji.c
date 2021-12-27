100 /**
101  * module_param - typesafe helper for a module/cmdline parameter
102  * @value: the variable to alter, and exposed parameter name.
103  * @type: the type of the parameter
104  * @perm: visibility in sysfs.
105  *
106  * @value becomes the module parameter, or (prefixed by KBUILD_MODNAME and a
107  * ".") the kernel commandline parameter.  Note that - is changed to _, so
108  * the user can use "foo-bar=1" even for variable "foo_bar".
109  *
110  * @perm is 0 if the the variable is not to appear in sysfs, or 0444
111  * for world-readable, 0644 for root-writable, etc.  Note that if it
112  * is writable, you may need to use kernel_param_lock() around
113  * accesses (esp. charp, which can be kfreed when it changes).
114  *
115  * The @type is simply pasted to refer to a param_ops_##type and a
116  * param_check_##type: for convenience many standard types are provided but
117  * you can create your own by defining those variables.
118  *
119  * Standard types are:
120  *  byte, short, ushort, int, uint, long, ulong
121  *  charp: a character pointer
122  *  bool: a bool, values 0/1, y/n, Y/N.
123  *  invbool: the above, only sense-reversed (N = true).
124  */
125 #define module_param(name, type, perm)              

�ں˴���
1��ֱ�Ӵ���
2������ģ���ʱ�򴫲� sudo insmod hello.ko hello=100
3��ͨ��ֱ�Ӹ��ļ����� echo 100 >/sys/module/hello/parameters/hello

 32 /* One for each parameter, describing how to use it.  Some files do
 33    multiple of these per line, so can't just use MODULE_INFO. */
 34 #define MODULE_PARM_DESC(_parm, desc) \
 35     __MODULE_INFO(parm, _parm, #_parm ":" desc)

1��ģ�����������ڶ�ģ����Ϣ����
����modinfo �鿴ģ����Ϣ

���� byte�������ַ�  charp�����ַ����м䲻���пո�

415 /**
416  * module_param_array - a parameter which is an array of some type
417  * @name: the name of the array variable
418  * @type: the type, as per module_param()
419  * @nump: optional pointer filled in with the number written
420  * @perm: visibility in sysfs
421  *
422  * Input and output are as comma-separated values.  Commas inside values
423  * don't work properly (eg. an array of charp).
424  *
425  * ARRAY_SIZE(@name) is used to determine the number of elements in the
426  * array, so the definition must be visible.
427  */
428 #define module_param_array(name, type, nump, perm)      \
429     module_param_array_named(name, name, type, nump, perm)
430
��������
nump ����һ�������ĵ�ַ ���������Ա�ĸ���

EXPORT_SYMBOL_GPL
�������ű�
����ǰ����ǰ��ģ�����󣬰�Module.symvers���ű��ƶ�������ģ���·��

������ں˻����� ���ں˶���Ŀ¼������Module.symvers �Ͳ���Ҫ������

bzImage

hexdump �鿴/dev/ Ŀ¼���豸�ļ��ϱ���ֵ




298 /**
299  * __unregister_chrdev - unregister and destroy a cdev
300  * @major: major device number
301  * @baseminor: first of the range of minor numbers
302  * @count: the number of minor numbers this cdev is occupying
303  * @name: name of this range of devices
304  *
305  * Unregister and destroy the cdev occupying the region described by
306  * @major, @baseminor and @count.  This function undoes what
307  * __register_chrdev() did.
308  */
309 void __unregister_chrdev(unsigned int major, unsigned int baseminor,
310              unsigned int count, const char *name)
311 {
312     struct char_device_struct *cd;
313
314     cd = __unregister_chrdev_region(major, baseminor, count);
315     if (cd && cd->cdev)
316         cdev_del(cd->cdev);
317     kfree(cd);
318 }


2344 static inline int register_chrdev(unsigned int major, const char *name,
2345                   const struct file_operations *fops)
2346 {
2347     return __register_chrdev(major, 0, 256, name, fops);
2348 }
2349
ע���ַ��豸����
major >0 ���豸��   =0 ϵͳ�Զ�����
name cat /proc/devices �鿴�ַ��豸����������  ���� �豸�ڵ������ ������
fops ���������ṹ���ָ��

2350 static inline void unregister_chrdev(unsigned int major, const char *name)
2351 {
2352     __unregister_chrdev(major, 0, 256, name);
2353 }

ע���ַ��豸����


set tags = /hmoe/linux/kernel/linux-4.14/tags   ������ǰ����

static inline unsigned long __must_check copy_from_user(void *to, const void __user *from, unsigned long n)
{
	if (access_ok(VERIFY_READ, from, n))
		n = __copy_from_user(to, from, n);
	else /* security hole - plug it */
		memset(to, 0, n);
	return n;
}
�����ݴ��û��ռ�copy���ں˿ռ�  write

static inline unsigned long __must_check copy_to_user(void __user *to, const void *from, unsigned long n)
�����ݴ��ں˿ռ�copy���û��ռ� read

to�� from �����׵�ַ




