.globl idt_flush			# export as symbol for C
idt_flush:
	movl 4(%esp), %eax		# Get the pointer to the IDT from stack, passed as a parameter.
	lidt (%eax)				# Load the IDT pointer.
	ret
