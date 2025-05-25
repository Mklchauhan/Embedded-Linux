/***************************************************************************//**
*  \file       helloworld.c
*
*  \details    Hello world driver with the Arguments
*
*  \author     Embdos
*
* *******************************************************************************/
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

#define DRIVER_TAG "[helloworld]"
 
int varTitu, arr_Titu[4];
char *nameTitu;
int cb_Titu = 0;
 
module_param(varTitu, int, S_IRUSR|S_IWUSR);                      //integer value
module_param(nameTitu, charp, S_IRUSR|S_IWUSR);                     //String
module_param_array(arr_Titu, int, NULL, S_IRUSR|S_IWUSR);      //Array of integers
 
/*----------------------Module_param_cb()--------------------------------*/
int notify_param(const char *val, const struct kernel_param *kp)
{
        int res = param_set_int(val, kp); // Use helper for write variable
        if(res==0) {
                pr_info(DRIVER_TAG"Call back function called...\n");
                pr_info(DRIVER_TAG"New value of cb_Titu = %d\n", cb_Titu);
                return 0;
        }
        return -1;
}
 
const struct kernel_param_ops my_param_ops = 
{
        .set = &notify_param, // Use our setter ...
        .get = &param_get_int, // .. and standard getter
};
 
module_param_cb(cb_Titu, &my_param_ops, &cb_Titu, S_IRUGO|S_IWUSR );
/*-------------------------------------------------------------------------*/

/*
** Module init function
*/
static int __init hello_world_init(void)
{
        int i;
        pr_info(DRIVER_TAG"varTitu = %d  \n", varTitu);
        pr_info(DRIVER_TAG"cb_Titu = %d  \n", cb_Titu);
        pr_info(DRIVER_TAG"nameTitu = %s \n", nameTitu);
        for (i = 0; i < (sizeof arr_Titu / sizeof (int)); i++) {
                pr_info(DRIVER_TAG"Arr_value[%d] = %d\n", i, arr_Titu[i]);
        }
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
 
module_init(hello_world_init);
module_exit(hello_world_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mukul Chauhan");
MODULE_DESCRIPTION("Hello world driver with the Arguments");
MODULE_VERSION("1.0.0");