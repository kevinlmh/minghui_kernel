# This will set up our new segment registers. We need to do
# something special in order to set CS. We do what is called a
# far jump. A jump that includes a segment as well as an offset.
# This is declared in C as 'extern void gdt_flush();'

.globl gdt_flush 				# export as symbol for C
gdt_flush:
	movl 4(%esp), %eax			# get the pointer to GDT
	lgdt (%eax)					# load the new GDT pointer
	movw $0x10, %ax				# 0x10 is the offset to the GDT to our data segment
	movw %ax, %ds				# Load all the data segment selectors
	movw %ax, %es
	movw %ax, %fs
	movw %ax, %gs
	movw %ax, %ss
	ljmp $0x08,$flush			# 0x08 is the offset to our code segment: Far jump!
flush:
	ret
	