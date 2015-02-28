#include <stdint.h>
#include "common.h"
#include "terminal.h"

void kernel_main() {
	terminal_clear();
	terminal_write("Hello Kernel World!\n");
	while(1);
}
