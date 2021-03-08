
#include <linux/ktime.h>
//#include <linux/timekeeping.h>

static unsigned long read_current_us(void)
{
	struct timespec now;
	getnstimeofday(&now);
	return (now.tv_sec * 1000000) + (now.tv_nsec/1000);
}
