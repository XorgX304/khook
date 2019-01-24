#include <linux/kernel.h>
#include <linux/module.h>

#include "engine/engine.h"
#include "engine/engine.c"

#include <linux/moduleloader.h>

KHOOK(module_alloc);
static void *khook_module_alloc(unsigned long size)
{
	void *ret = 0;

	dump_stack();

	KHOOK_GET(module_alloc);
	ret = KHOOK_ORIGIN(module_alloc, size);
	printk("%s(%lu) = %p\n", __func__, size, ret);
	KHOOK_PUT(module_alloc);

	return ret;
}

////////////////////////////////////////////////////////////////////////////////

int init_module(void)
{
	return khook_init();
}

void cleanup_module(void)
{
	khook_cleanup();
}

MODULE_LICENSE("GPL");
