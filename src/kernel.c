#include <stdint.h>
#include "common.h"
#include "terminal.h"

void kernel_main() {
	terminal_clear();
	terminal_write("Hello\tKernel\tWorld!\n");
	terminal_write_rainbow("I am a rainbow string.\n");
	while(1);
}
