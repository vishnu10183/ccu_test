
/*
 * Program Created on 05-MAR-2021
 * 
 * Running as Linux Module or Kernel Driver
 * Controlling GPIO using linux timer
 * 
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/timer.h>

// #define GPIO_BASE	0x20200000
#define GPIO_BASE	0xf2200000
#define BLOCK_SIZE	4096


// GPIO Macros for GPIO-4
#define INP_GPIO_04(b)	*(volatile unsigned int *)(0x00000000+b) &= (unsigned int)0xFFFF8FFF
#define OUT_GPIO_04(b)	*(volatile unsigned int *)(0x00000000+b) |= (unsigned int)0x00001000

#define GPIO_SET_04(b)	*(volatile unsigned int *)(0x0000001C+b) |= 0x10
#define GPIO_CLR_04(b)	*(volatile unsigned int *)(0x00000028+b) |= 0x10


struct timer_list led_timer;
char kbledstatus = 0;
int status = 0;


/* ******************* MAIN FUNCTIONS ************ */

static void hello_timer( unsigned long ptr ){
	printk( " Jiffies + Hz = %ld + %d\n ", jiffies, HZ );
	if( status )
		GPIO_CLR_04( GPIO_BASE );
	else
		GPIO_SET_04( GPIO_BASE );
	status = 1 - status; // Toggle Status
	
	led_timer.expires = jiffies + HZ;
	add_timer( &led_timer );
	
}

static int hello_init(void){
	printk( "Hello, LED World!\n" );
	OUT_GPIO_04( GPIO_BASE );
	
	init_timer( &led_timer );
	
	led_timer.function = hello_timer;
	led_timer.data = (unsigned long) &kbledstatus;
	led_timer.expires = jiffies + HZ;
	add_timer( &led_timer );
	
	return 0;
}

static void hello_exit(void){
	GPIO_CLR_04( GPIO_BASE );
	del_timer( &led_timer );
	printk( "Thank You. See You Later!\n" );
}


module_init( hello_init );
module_exit( hello_exit );

MODULE_LICENSE("GPL");
MODULE_AUTHOR("VishnuM");
MODULE_DESCRIPTION("SAMPLE: Raspberry Pi 4B+ driver");
MODULE_VERSION( "0.0" );
