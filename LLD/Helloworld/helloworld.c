/***************************************************************************//**
*  \file       helloworld.c
*
*  \details    Simple hello world driver
*
*  \author     Mukul Chauhan
*
* *******************************************************************************/
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

#define DRIVER_TAG "[helloworld]"
 
/*
** Module Init function
*/
static int __init hello_world_init(void)
{
    pr_info(DRIVER_TAG"Welcome to Embdos\n");
    pr_info(DRIVER_TAG"This is the Simple Module from Embdos\n");
    pr_info(DRIVER_TAG"Kernel Module Inserted Successfully...\n");
    return 0;
}

/*
** Module Exit function
*/
static void __exit hello_world_exit(void)
{
    pr_info(DRIVER_TAG"Kernel Module Removed Successfully...\n");
}

/*
* We need information for-
*                        - Device Driver management
*                        - Memory & Performance 
*                        - Debugging & development -> Make testing easier without rebooting system
*/
module_init(hello_world_init);
module_exit(hello_world_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Embdos <mukulchauhan.eee.91@gmail.com>");
MODULE_DESCRIPTION("A simple hello world driver");
MODULE_VERSION("2:1.0");