#include <linux/kernel.h>
#include <linux/module.h>

#include "engine/engine.h"
#include "engine/engine.c"

////////////////////////////////////////////////////////////////////////////////
// An example of using KHOOK
////////////////////////////////////////////////////////////////////////////////

KHOOK_EXT(int, devmem_is_allowed, unsigned long);
static int khook_devmem_is_allowed(unsigned long pagenr)
{
	return 1;
}

int init_module(void)
{
	return khook_init();
}

void cleanup_module(void)
{
	khook_cleanup();
}

MODULE_LICENSE("GPL");
