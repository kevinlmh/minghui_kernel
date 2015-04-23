
# this macro is pretty simple
# It defines a label for the interrupt number.
# It clears all maskabel interrupts (entering critical section)
# pushes the constant '0' to the stack (eg, the error code)
# pushes the interrupt number to the stack
# jumps to the common interrupt handler.

.extern isr_handler

# Our common stub for all interrupts which will prepare us
# to enter a C function to handle the interrupt.
.globl isr_common_stub
isr_common_stub:
	pusha 			# Pushes all registers to stack -- save while we change the data segment register
	movw %ds, %ax	# Move data segment register to eax
	push %eax		# Push eax (data segment reg) to the stack
	# Load the kernel data segment descriptor
	movw $0x10, %ax
	movw %ax, %ds
	movw %ax, %es
	movw %ax, %fs
	movw %ax, %gs
	# Jump to C and handle the interrupt
	call isr_handler
	# Restore original data segment descriptor
	pop %ebx
	movw %bx, %ds
	movw %bx, %es
	movw %bx, %fs
	movw %bx, %gs
	# Pop all registers -- restore previous registers
	popa
	# Cleans up pushed error code and pushed interrupt number 
	addl $8, %esp
	# Re-enable interrupts
	sti
	# Return to where we were when interrupt was called
	iret

# Interrupts 0-18
#
#
# 0 - Division by zero exception
# 1 - Debug exception
# 2 - Non maskable interrupt
# 3 - Breakpoint exception
# 4 - 'Into detected overflow'
# 5 - Out of bounds exception
# 6 - Invalid opcode exception
# 7 - No coprocessor exception
# 8 - Double fault (pushes an error code)
# 9 - Coprocessor segment overrun
# 10 - Bad TSS (pushes an error code)
# 11 - Segment not present (pushes an error code)
# 12 - Stack fault (pushes an error code)
# 13 - General protection fault (pushes an error code)
# 14 - Page fault (pushes an error code)
# 15 - Unknown interrupt exception
# 16 - Coprocessor fault
# 17 - Alignment check exception
# 18 - Machine check exception
# 19-31 - Reserved

.globl isr0;
isr0:
	cli;
	push $0;
	push $0;
	jmp isr_common_stub;

.globl isr1;
isr1:
	cli;
	push $0;
	push $1;
	jmp isr_common_stub;

.globl isr2;
isr2:
	cli;
	push $0;
	push $2;
	jmp isr_common_stub;

.globl isr3;
isr3:
	cli;
	push $0;
	push $3;
	jmp isr_common_stub;

.globl isr4;
isr4:
	cli;
	push $0;
	push $4;
	jmp isr_common_stub;

.globl isr5;
isr5:
	cli;
	push $0;
	push $5;
	jmp isr_common_stub;

.globl isr6;
isr6:
	cli;
	push $0;
	push $6;
	jmp isr_common_stub;

.globl isr7;
isr7:
	cli;
	push $0;
	push $7;
	jmp isr_common_stub;

.globl isr8;
isr8:
	cli;
	push $8;
	jmp isr_common_stub;

.globl isr9;
isr9:
	cli;
	push $0;
	push $9;
	jmp isr_common_stub;

.globl isr10;
isr10:
	cli;
	push $10;
	jmp isr_common_stub;

.globl isr11;
isr11:
	cli;
	push $11;
	jmp isr_common_stub;

.globl isr12;
isr12:
	cli;
	push $12;
	jmp isr_common_stub;

.globl isr13;
isr13:
	cli;
	push $13;
	jmp isr_common_stub;

.globl isr14;
isr14:
	cli;
	push $14;
	jmp isr_common_stub;

.globl isr15;
isr15:
	cli;
	push $0;
	push $15;
	jmp isr_common_stub;

.globl isr16;
isr16:
	cli;
	push $0;
	push $16;
	jmp isr_common_stub;

.globl isr17;
isr17:
	cli;
	push $0;
	push $17;
	jmp isr_common_stub;

.globl isr18;
isr18:
	cli;
	push $0;
	push $18;
	jmp isr_common_stub;



.globl isr19;
isr19:
	cli;
	push $0;
	push $19;
	jmp isr_common_stub;

.globl isr20;
isr20:
	cli;
	push $0;
	push $20;
	jmp isr_common_stub;

.globl isr21;
isr21:
	cli;
	push $0;
	push $21;
	jmp isr_common_stub;

.globl isr22;
isr22:
	cli;
	push $0;
	push $22;
	jmp isr_common_stub;

.globl isr23;
isr23:
	cli;
	push $0;
	push $23;
	jmp isr_common_stub;

.globl isr24;
isr24:
	cli;
	push $0;
	push $24;
	jmp isr_common_stub;

.globl isr25;
isr25:
	cli;
	push $0;
	push $25;
	jmp isr_common_stub;

.globl isr26;
isr26:
	cli;
	push $0;
	push $26;
	jmp isr_common_stub;

.globl isr27;
isr27:
	cli;
	push $0;
	push $27;
	jmp isr_common_stub;

.globl isr28;
isr28:
	cli;
	push $0;
	push $28;
	jmp isr_common_stub;

.globl isr29;
isr29:
	cli;
	push $0;
	push $29;
	jmp isr_common_stub;

.globl isr30;
isr30:
	cli;
	push $0;
	push $30;
	jmp isr_common_stub;

.globl isr31;
isr31:
	cli;
	push $0;
	push $31;
	jmp isr_common_stub;



# In isr.c
.extern irq_handler

# This is our common IRQ stub. It saves the processor state, sets
# up for kernel mode segments, calls the C-level fault handler,
# and finally restores the stack frame.
.globl irq_common_stub
irq_common_stub:
    pusha					# Pushes edi,esi,ebp,esp,ebx,edx,ecx,eax

    movw %dx, %ax			# Lower 16-bits of eax = ds.
    push %eax				# save the data segment descriptor

    movw $0x10, %ax			#load the kernel data segment descriptor
    movw %ax, %ds
    movw %ax, %es
    movw %ax, %fs
    movw %ax, %gs

    call irq_handler

    pop %ebx					# reload the original data segment descriptor
    movw %bx, %ds
    movw %bx, %es
    movw %bx, %fs
    movw %bx, %gs

    popa           				# Pops edi,esi,ebp...
    addl $8, %esp 				# Cleans up the pushed error code and pushed ISR number
    sti
    iret           				# pops 5 things at once: CS, EIP, EFLAGS, SS, and ESP


.global irq0
irq0:
	cli
	pushl $0
	pushl $32
	jmp irq_common_stub

.global irq1
irq1:
	cli
	push $0
	push $33
	jmp irq_common_stub

.global irq2
irq2:
	cli
	push $0
	push $34
	jmp irq_common_stub

.global irq3
irq3:
	cli
	push $0
	push $35
	jmp irq_common_stub

.global irq4
irq4:
	cli
	push $0
	push $36
	jmp irq_common_stub

.global irq5
irq5:
	cli
	push $0
	push $37
	jmp irq_common_stub

.global irq6
irq6:
	cli
	push $0
	push $38
	jmp irq_common_stub

.global irq7
irq7:
	cli
	push $0
	push $39
	jmp irq_common_stub

.global irq8
irq8:
	cli
	push $0
	push $40
	jmp irq_common_stub

.global irq9
irq9:
	cli
	push $0
	push $41
	jmp irq_common_stub

.global irq10
irq10:
	cli
	push $0
	push $42
	jmp irq_common_stub

.global irq11
irq11:
	cli
	push $0
	push $43
	jmp irq_common_stub

.global irq12
irq12:
	cli
	push $0
	push $44
	jmp irq_common_stub

.global irq13
irq13:
	cli
	push $0
	push $45
	jmp irq_common_stub

.global irq14
irq14:
	cli
	push $0
	push $46
	jmp irq_common_stub

.global irq15
irq15:
	cli
	push $0
	push $47
	jmp irq_common_stub
