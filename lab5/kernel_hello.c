#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
//#include <sys/utsname.h>

static int __init init_hello(void) {
	printk("[COMP3120] : HELLO, KERNEL\n");
	printk("User name : JungJe\n");
	printk("Kernel Version : Linux ubuntu 4.10.0-28-generic #32~16.04.2-Ubuntu SMP Thu Jul 20 10:19:48 UTC 2017 x86_64 x86_64 x86_64 GNU/Linux");
	return 0;
}

static void __exit exit_hello(void) {
	printk("[COMP3120] : GOOOBYE, KERNEL\n");
}

module_init(init_hello);
module_exit(exit_hello);
MODULE_LICENSE("GPL");
