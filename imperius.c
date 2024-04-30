#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h>

struct module_entry {
    struct list_head list;
    char *name; 
    void *address;
};

static LIST_HEAD(module_list);

static void add_entry(char *name, void *address) {
    struct module_entry *mod;
    mod = kmalloc(sizeof(struct module_entry), GFP_KERNEL);
    if (!mod) {
        printk(KERN_ERR "Deu ruimkjkj.\n");
        return;
    }
    mod->name = name;
    mod->address = address;
    list_add_tail(&mod->list, &module_list);
}

static void magick_lol(void) {
    struct module_entry *entry;
    list_for_each_entry(entry, &module_list, list) {
        if (strcmp(entry->name, "module_show") == 0) {

            ((void (*)(void))entry->address)();
            break;
        }
    }
}

static int __init lkm_init(void) {
    add_entry("module_show", (void *)0xffffffffc09fbf); //endereço da função module_show
    magick_lol();

    return 0;
}

static void __exit lkm_exit(void) {
	printk(KERN_INFO "Qlq coisa kkjkjkjk\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("matheuz");
MODULE_DESCRIPTION("Sem descrição kkjkjk");
MODULE_VERSION("1.0");

module_init(lkm_init);
module_exit(lkm_exit);
