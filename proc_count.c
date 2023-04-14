#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/printk.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>

static int proc_count_show(struct seq_file *m, void *v) {
  int num = 0;
  struct task_struct *t;
  for_each_process(t){
    num=num+1;
  }
  seq_printf(m, "%d\n", num);
  return 0;
}

static int __init proc_count_init(void)
{
        static struct proc_dir_entry* countEntry;
	countEntry = proc_create_single("count",0644, NULL, proc_count_show);
	  //proc_create("count", 0, NULL, &hello_proc_fops);
	pr_info("proc_count: init\n");
	return 0;
}

static void __exit proc_count_exit(void)
{
  remove_proc_entry("count",NULL);
	pr_info("proc_count: exit\n");
}

module_init(proc_count_init);
module_exit(proc_count_exit);

MODULE_AUTHOR("Nathaniel Carman");
MODULE_DESCRIPTION("This module prints the current number of running processes to /proc/count");
MODULE_LICENSE("GPL");
