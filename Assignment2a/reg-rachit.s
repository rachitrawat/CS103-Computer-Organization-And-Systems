	.text
	.globl	max


	# Function max
	# Arguments:
	#   %rdi -- base address of the array
	#   %rsi -- number of elements in the array
	# Return:
	#   %rax -- max of the elements of the array

	# Rachit Rawat

max:

	movq $0, %rax # max = 0
	movq $0, %r12 # i = 0

loop:	
	cmp %rsi, %r12 # i ? n
	je done

	# compute a[i] = value at a + 8*i
	movq %r12, %r14  # r14 = i
	imulq $8, %r14   # r14 = 8*i
	addq %rdi, %r14  # r14 = 8*i + a
	
	# max	
	cmp (%r14), %rax
	cmovl (%r14), %rax # if max < a[i], max = a[i]

	addq $1, %r12	# i = i + 1
	jmp loop

done:		
	ret

	
