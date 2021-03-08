// Tutorial: https://embetronicx.com/tutorials/microcontrollers/raspberry-pi/gpio-linux-device-driver-using-raspberry-pi/

/****************************************************************************************************
*																									                                                  *
*	File Name		  :	driver_ultraS_1.c														                                      *
*	Created on 	  :	05-MARCH-2021                                                                     *
* Updated on    :	08-MARCH-2021 															                                      *
*	Topic			    :	Ultrasonic Sensor driver using Linux Kernel			                                  *
*	Source Code	  :	https://github.com/Embetronicx/Tutorials/tree/master/Linux/Device_Driver	        *
* Author        :	EmbeTronicX																                      	                *
*	Tested on		  :	Raspberry Pi 4	( RaspberryPi OS	)						                                    *
*	Linux Version	:	Linux raspberrypi 5.10.20-v7l+												                            *
* 																								                                                  *
* UPDATES:                                                                                          *
*     - HC-SR04 program                                                                             *
*																									                                                  *
****************************************************************************************************/


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

#include "deviceFile_opr.h"
#include "uSec.h"

// GPIO macros
#define TRIG  22
#define ECHO  27


// Global Variables
unsigned long uSeconds = 0;



// IRQ number
unsigned int GPIO_irqNumber;

// Interrupt handler ( raising edge ) 
static irqreturn_t gpio_irq_handler( int irq, void *dev_id ) 
{
		static unsigned long flags = 0;

		uSeconds = jiffies; // start duration value


		local_irq_save(flags);
		
		
		pr_info("Trigger Occurred : %d ", uSeconds );
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
 
 
 
 
 
 
 
static int __init etx_driver_init(void)
{
		int ret = setpriority();
		if( ret == -1 )
			pr_err("[ERROR] Could not set priority\n");
			
		/*Allocating Major number*/
		if( alloc_chrdev_region( &dev, 0, 1, "etx_Dev") < 0 ) {
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
		if( dev_class = class_create(THIS_MODULE,"etx_class")  == NULL ){
			pr_err("Cannot create the struct class\n");
			goto r_class;
		}

		/*Creating device*/
		if(  device_create( dev_class, NULL, dev, NULL, "etx_device" )  == NULL  ){
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
		
		
		pr_info("...Done!!!\n");
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
MODULE_VERSION("1.0.1");
