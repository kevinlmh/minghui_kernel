#include <stdint.h>
#include "common.h"
#include "terminal.h"

void kernel_main() {
	terminal_clear();
	terminal_write("Hello\tKernel\tWorld!\n");
	while(1);
}
