	.text
	.globl	sort


	# Function sort
	# Arguments:
	#   %rdi -- base address of the array
	#   %rsi -- number of elements in the array
	#   %rax -- temp
	#   sort the elements of the array


# Rachit Rawat
# Bubble Sort - O(N^2)


sort:
	movq $0, %r12 # i = 0
	movq %rsi, %r8 # %r8 = %rsi
	subq $1, %r8   # %r8 = %r8 - 1 ( %r8 =  length - 1)	

outerloop:	
	cmp %rsi, %r12 # i ? n
	je outerloopdone

	movq $0, %r13 # j = 0
	movq $0, %rax # temp = 0

innerloop:
	cmp %r8, %r13 # j ? n - 1
	je innerloopdone

	# compute address of a[j] = value at a + 8*j
	movq %r13, %r14  # %r14 = j
	imulq $8, %r14   # %r14 = 8*j
	addq %rdi, %r14  # %r14 = 8*j + a

	# make a copy of %r14
	movq %r14, %r15
		
	# compute address of a[j+1]
	addq $8, %r15    # %r15 = %r14 + 8
	# %rcx = a[j+1]
	movq (%r15), %rcx

	addq $1, %r13	# j = j + 1		
		
	# max	
	cmp (%r14), %rcx   # if a[j+1] < a[j]
	jl swap

	jmp innerloop

swap:
	movq (%r14), %rax	# temp = a[j]
	movq %rcx, (%r14)	# a[j] = a[j+1]
	movq %rax, (%r15)	# a[j+1] = temp
	jmp innerloop
	
innerloopdone:
	addq $1, %r12	# i = i + 1
	jmp outerloop

outerloopdone:		
	ret


