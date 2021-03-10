// Tutorial: https://embetronicx.com/tutorials/microcontrollers/raspberry-pi/gpio-linux-device-driver-using-raspberry-pi/

/********************************************************************************************************
*						                                                  	*
*	File Name	:	driver_ultraS_1.c				                        *
*	Created on 	:	05-MARCH-2021                                                           *
* 	Updated on    	:	09-MARCH-2021 					                        *
*	Topic		:	Ultrasonic Sensor driver using Linux Kernel			        *
*	Source Code	:	https://github.com/Embetronicx/Tutorials/tree/master/Linux/Device_Driver*
* 	Author        	:	EmbeTronicX							       	*
*	Tested on	:	Raspberry Pi 4	( RaspberryPi OS )                                  	*
*	Linux Version	:	Linux raspberrypi 5.10.20-v7l+		        			*
* 							                                     		*
* UPDATES:                                                                                          	*
*     	- udelay( ) and ktime( ).									*
* 	- HC-SR04 program                                                                             	*
*						                                                  	*
********************************************************************************************************/

//#define _BSD_SOURCE
/*
_BSD_SOURCE ||
    (_XOPEN_SOURCE >= 500 ||
        _XOPEN_SOURCE && _XOPEN_SOURCE_EXTENDED) &&
    !(_POSIX_C_SOURCE >= 200809L || _XOPEN_SOURCE >= 700)
*/
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/delay.h>
#include <linux/uaccess.h>  //copy_to/from_user()
#include <linux/gpio.h>     //GPIO
#include <linux/interrupt.h>
//#include <linux/timer.h>
//#include <time.h>
//#include <linux/ktime.h>

//#include <sys/resource.h>
#include <linux/unistd.h> // for getpid()


//#include "deviceFile_opr.h"
//#include "uSec.h"
#include "dht22.h"

// GPIO macros
#define TRIG  22
#define ECHO  27


// Global Variables
unsigned long uSeconds = 0, startClock;



// IRQ number
unsigned int GPIO_irqNumber;



// Interrupt handler ( raising edge ) 
static irqreturn_t gpio_irq_handler( int irq, void *dev_id ) 
{
		static unsigned long flags = 0;
		volatile unsigned int tempC, duration = 0, cm;
		volatile ktime_t start;
		//static float ultraSpeed= 0.0, cm = 0.0; //, tempry;

		local_irq_save(flags);
		

		start = ktime_get();
		
		while( gpio_get_value( ECHO ) != 0 ); // wait till ECHO pin gets LOW
		
		// Calculate duration of ECHO signal
		duration =  (unsigned int) ktime_to_ns(ktime_sub(ktime_get(), start));
		duration /= 1000; // convert nanosecond to microsecond
		pr_info("Duration : %d \n", duration );
	
		// Calculate Distance
		tempC = read_dht_temp('c');
		//ultraSpeed = 331.3 + ( 0.606 * tempC );
		//ultraSpeed = 331.3;
		cm = (unsigned int) ( duration / 20000 ) ;
		cm *= (unsigned int)(331.3 + ( 606 * tempC / 1000 )) ;
		//tempC = cm * 1;
		//cm = 12.2; 
		//pr_alert("Distance (cm) : %.2f \n", cm );
		//pr_info("Distance (cm) : %.2f \n", cm );
		pr_info("Distance (cm) : %d \n", cm );
		//pr_info("Distance (cm) : %d \n", tempC );
		//printk(KERN_INFO"Distance (cm) : %d \n", (int) cm );
		//tempry = cm;
		//pr_info("Distance (cm) : %d \n", tempry );
		//pr_info("Duration : %d \n", duration );
		
		local_irq_restore(flags);
		
		return IRQ_HANDLED;
}




 
dev_t dev = 0;
static struct class *dev_class;
static struct cdev etx_cdev;
 
static int __init etx_driver_init(void);
static void __exit etx_driver_exit(void);
 
 
/*************** Driver functions ******************************/
static int etx_open(struct inode *inode, struct file *file);
static int etx_release(struct inode *inode, struct file *file);
static ssize_t etx_read(struct file *filp, 
                char __user *buf, size_t len,loff_t * off);
static ssize_t etx_write(struct file *filp, 
                const char *buf, size_t len, loff_t * off);
/**************************************************************/

//File operation structure 
static struct file_operations fops =
{
  .owner          = THIS_MODULE,
  .read           = etx_read,
  .write          = etx_write,
  .open           = etx_open,
  .release        = etx_release,
};
 
  
static int etx_open(struct inode *inode, struct file *file)
{
  pr_info("Device File Opened...!!!\n");
  return 0;
}
 
static int etx_release(struct inode *inode, struct file *file)
{
  pr_info("Device File Closed...!!!\n");
  return 0;
}
  
 static ssize_t etx_read(struct file *filp, 
                char __user *buf, size_t len, loff_t *off)
{
  uint8_t gpio_state = 0;
  
  //reading GPIO value
  gpio_state = gpio_get_value(TRIG);
  
  //write to user
  len = 1;
  if( copy_to_user(buf, &gpio_state, len) > 0) {
    pr_err("ERROR: Not all the bytes have been copied to user\n");
  }
  
  pr_info("Read function : TRIG = %d \n", gpio_state);
  
  return 0;
}



static ssize_t etx_write(struct file *filp, 
                const char __user *buf, size_t len, loff_t *off)
{
  uint8_t rec_buf[10] = {0};
  
  if( copy_from_user( rec_buf, buf, len ) > 0) {
    pr_err("ERROR: Not all the bytes have been copied from user\n");
  }
  
  pr_info("Write Function : TRIG Set = %c\n", rec_buf[0]);
  
  if ( rec_buf[0] == '1' ) 
        gpio_set_value(TRIG, 1); // set the GPIO value to HIGH
    else if ( rec_buf[0] == '0' )
        gpio_set_value(TRIG, 0); // set the GPIO value to LOW
    else 
        pr_err("Unknown command : Please provide either 1 or 0 \n");
  
  return len;
}

 
 
 
 
 
static int __init etx_driver_init(void)
{
	/*
		int ret = setpriority();
		if( ret == -1 )
			pr_err("[ERROR] Could not set priority\n");
	*/
		/*Allocating Major number*/
		if( (alloc_chrdev_region( &dev, 0, 1, "etx_Dev")) < 0 ) {
			pr_err("Cannot allocate major number\n");
			goto r_unreg;
		}
		pr_info("Major = %d Minor = %d \n",MAJOR(dev), MINOR(dev));

		/*Creating cdev structure*/
		cdev_init( &etx_cdev, &fops );

		/*Adding character device to the system*/
		if((cdev_add(&etx_cdev,dev,1)) < 0){
			pr_err("Cannot add the device to the system\n");
			goto r_del;
		}

		/*Creating struct class*/
		if( (dev_class = class_create(THIS_MODULE,"etx_class"))  == NULL ){
			pr_err("Cannot create the struct class\n");
			goto r_class;
		}

		/*Creating device*/
		if(  (device_create( dev_class, NULL, dev, NULL, "etx_device" ))  == NULL  ){
			pr_err( "Cannot create the Device \n"); 
			goto r_device;
		}
		
		//Output GPIO configuration
		if( gpio_is_valid(TRIG) == false ){
					pr_err("GPIO %d is not valid\n", TRIG);
					goto r_device;
			}
	 
		if( gpio_request(TRIG,"TRIG")  < 0 ) {
					pr_err("ERROR: GPIO %d request\n", TRIG);
					goto r_TRIG;
			}
		
		gpio_direction_output( TRIG, 0 );
		
		//Input GPIO configuratioin
		if( gpio_is_valid(ECHO) == false ){
					pr_err("GPIO %d is not valid\n", ECHO);
					goto r_ECHO;
			}
		
		if( gpio_request(ECHO,"ECHO") < 0 ){
					pr_err("ERROR: GPIO %d request\n", ECHO);
					goto r_ECHO;
			}
		gpio_direction_input(ECHO);
		

		
		//Get the IRQ number for our GPIO
		GPIO_irqNumber = gpio_to_irq(ECHO);
		pr_info("GPIO_irqNumber = %d\n", GPIO_irqNumber);
		
		if ( request_irq( GPIO_irqNumber,             //IRQ number
				(void *)gpio_irq_handler,   //IRQ handler
				IRQF_TRIGGER_RISING,        //Handler will be called in raising edge
				"etx_device",               //used to identify the device name using this IRQ
				NULL) ) {                    //device id for shared IRQ
			pr_err("my_device: cannot register IRQ ");
			goto r_ECHO;
		}
	 
		pr_info("Device Driver Insert...Done!!!\n");
		pr_info("TRIGGER out...");
		
		gpio_set_value( TRIG, 0); 
		udelay(2);
		gpio_set_value( TRIG, 1); 
		udelay(10);
		gpio_set_value( TRIG, 0); 
		
		//pr_info("...Done!!!\n");
		//startClock = sched_clock();
		return 0;

		// Error Labels
	r_ECHO:
		gpio_free(ECHO);
	r_TRIG:
		gpio_free(TRIG);
	r_device:
		device_destroy(dev_class,dev);
	r_class:
		class_destroy(dev_class);
	r_del:
		cdev_del(&etx_cdev);
	r_unreg:
		unregister_chrdev_region(dev,1);
		
		return -1;
}
 
 
 
 
static void __exit etx_driver_exit(void)
{
  free_irq(GPIO_irqNumber,NULL);
  gpio_free(ECHO);
  gpio_free(TRIG);
  device_destroy(dev_class,dev);
  class_destroy(dev_class);
  cdev_del(&etx_cdev);
  unregister_chrdev_region(dev, 1);
  pr_info("Device Driver Remove...Done!!\n");
}




 
module_init(etx_driver_init);
module_exit(etx_driver_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Aurora-CCU");
MODULE_DESCRIPTION("A HC-SR04 device driver");
MODULE_VERSION("1.1.1");
