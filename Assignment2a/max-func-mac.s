	.section	__TEXT,__text,regular,pure_instructions
	.globl	_max

	# Function max
	# Arguments:
	#   %rdi -- base address of the array
	#   %rsi -- number of elements in the array
	# Return:
	#   %rax -- max of the elements of the array

_max:
	pushq %rbx
	pushq %rbp
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15

	# ====================
	# WRITE YOUR CODE HERE



	

	# ====================
	
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbp
	popq %rbx
	
	retq


