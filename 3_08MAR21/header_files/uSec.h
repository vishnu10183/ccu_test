//#define _POSIX_C_SOURCE 199309L
#define _POSIX_C_SOURCE 200809L
//#include <linux/time.h>
#include <linux/ktime.h>
#include <linux/timekeeping.h>
#include <linux/kernel.h>

static unsigned long read_current_us(void)
{
	struct timespec now;
	getnstimeofday(&now);
	return (now.tv_sec * 1000000) + (now.tv_nsec/1000);
}
