#include "test.h"
#include "monitor.h"
#include "descriptor_tables.h"
#include "timer.h"
#include "paging.h"
#include "kheap.h"
#include "multiboot.h"
#include "fs.h"
#include "initrd.h"

extern placement_address;
extern tick;

void test_interrupt() {
    asm volatile("int $0x3");
    asm volatile("int $0x4");
}

void test_pit() {
	asm volatile("sti");
    init_timer(50);
}

void test_page_fault() {
    uint32_t *ptr = (uint32_t*)0xA0000000;
    uint32_t do_page_fault = *ptr;
}

void test_heap() {
    uint32_t a = kmalloc(8);
    initialise_paging();
    uint32_t b = kmalloc(8);
    uint32_t c = kmalloc(8);
    monitor_write("a: ");
    monitor_write_hex(a);
    monitor_write(", b: ");
    monitor_write_hex(b);
    monitor_write("\nc: ");
    monitor_write_hex(c);

    kfree(c);
    kfree(b);
    uint32_t d = kmalloc(12);
    monitor_write(", d: ");
    monitor_write_hex(d);
    monitor_write('\n');

    debug_print();
}

void test_initrd(struct multiboot *mboot_ptr) {
	// Find the location of our initial ramdisk.
    ASSERT(mboot_ptr->mods_count > 0);
    uint32_t initrd_location = *((uint32_t*)mboot_ptr->mods_addr);
    uint32_t initrd_end = *(uint32_t*)(mboot_ptr->mods_addr+4);
    // Don't trample our module with placement accesses, please!
    placement_address = initrd_end;

    // Start paging.
    initialise_paging();

    // Initialise the initial ramdisk, and set it as the filesystem root.
    fs_root = initialise_initrd(initrd_location);

    // list the contents of /
    int i = 0;
    struct dirent *node = 0;
    while ( (node = readdir_fs(fs_root, i)) != 0)
    {
        monitor_write("Found file ");
        monitor_write(node->name);
        fs_node_t *fsnode = finddir_fs(fs_root, node->name);

        if ((fsnode->flags&0x7) == FS_DIRECTORY) {
            monitor_write("\n\t(directory)\n");
        } else {
            monitor_write("\n\t contents: \"");
            char buf[256];
            uint32_t sz = read_fs(fsnode, 0, 256, buf);
            int j;
            for (j = 0; j < sz; j++)
                monitor_put(buf[j]);
            
            monitor_write("\"\n");
        }
        i++;
    }
}

static void sunnyday(registers_t regs) {
	monitor_write("Today is a sunny day.\n");
}

void test_sunnyday() {
    register_interrupt_handler(3, &sunnyday);
	asm volatile("int $0x3");
}

static void output_tick() {
	monitor_write("Tick: ");
    monitor_write_dec(tick);
    monitor_write("\n");
}

void test_output_tick() {
	asm volatile("sti");
    init_timer(50);
    register_interrupt_handler(4, &output_tick);
    int i;
    for (i = 0; i < 100000000; i++);
	asm volatile("int $0x4");
}
