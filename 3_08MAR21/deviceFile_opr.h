 
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
