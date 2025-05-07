#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vikash");
MODULE_DESCRIPTION("Hello world kernel module");

static int start(void) {
    int *a = NULL;

    *a = 10;

    return 0;
}

static void end(void) {
    printk("Goodbye\n");
}

module_init(start);
module_exit(end);
