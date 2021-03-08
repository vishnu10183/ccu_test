#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x4766f3ab, "module_layout" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x12fb6301, "cdev_del" },
	{ 0xe171d059, "class_destroy" },
	{ 0xb37ccf3d, "device_destroy" },
	{ 0xfe990052, "gpio_free" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x33ac2be4, "gpiod_to_irq" },
	{ 0x19398ed5, "gpiod_direction_input" },
	{ 0x4652df17, "gpiod_direction_output_raw" },
	{ 0x47229b5c, "gpio_request" },
	{ 0x1b6c45b6, "device_create" },
	{ 0xd74cab92, "__class_create" },
	{ 0x5cefef60, "cdev_add" },
	{ 0x73e61f56, "cdev_init" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x2cfde9a2, "warn_slowpath_fmt" },
	{ 0x5f754e5a, "memset" },
	{ 0xae353d77, "arm_copy_from_user" },
	{ 0x86332725, "__stack_chk_fail" },
	{ 0x51a910c0, "arm_copy_to_user" },
	{ 0x8f678b07, "__stack_chk_guard" },
	{ 0xd697e69a, "trace_hardirqs_on" },
	{ 0xec3d2e1b, "trace_hardirqs_off" },
	{ 0x9cd39344, "gpiod_get_raw_value" },
	{ 0xacd69794, "gpiod_set_raw_value" },
	{ 0x6b1a67d, "gpio_to_desc" },
	{ 0x526c3a6c, "jiffies" },
	{ 0xc5850110, "printk" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C8EA9F5180513FE005EEADB");
