.section	.rodata
.LC0:
	.string "\nEnter the size of an integer array: (size less than 40)\n"
.LC1:
	.string "\nEnter the elements of the array one by one, in seperate lines\n"
.LC2:
	.string "\nLargest possible sum of a contiguous subarray  of the given array is: "
.LC3:
	.string "\n"
.LC4:
	.string "TEST 3 COMPLETED\n"
# printStr: 
# printInt: 
# readInt: 
# maxSubArraySum: 

	.text
	.globl	maxSubArraySum
	.type	maxSubArraySum, @function
maxSubArraySum:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$80, %rsp
# t0 = 99999
	movl	$99999, -4(%rbp)
# t1 = -t0
	movl	-4(%rbp), %eax
	negl	%eax
	movl	%eax, -8(%rbp)
# max_sum = t1
	movl	-8(%rbp), %eax
	movl	%eax, -12(%rbp)
# t2 = 0
	movl	$0, -16(%rbp)
# current_max = t2
	movl	-16(%rbp), %eax
	movl	%eax, -20(%rbp)
# t3 = 0
	movl	$0, -28(%rbp)
# i = t3
	movl	-28(%rbp), %eax
	movl	%eax, -24(%rbp)
# t4 = 1
.L2:
	movl	$1, -32(%rbp)
# if i < size goto .L0
	movl	-24(%rbp), %eax
	cmpl	24(%rbp), %eax
	jge	.L12
	jmp	.L0
.L12:
# t4 = 0
	movl	$0, -32(%rbp)
# goto .L1
	jmp	.L1
# goto .L1
	jmp	.L1
# t5 = i
.L6:
	movl	-24(%rbp), %eax
	movl	%eax, -36(%rbp)
# i = i + 1
	movl	-24(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -24(%rbp)
# goto .L2
	jmp	.L2
# t6 = 0
.L0:
	movl	$0, -40(%rbp)
# t7 = i
	movl	-24(%rbp), %eax
	movl	%eax, -44(%rbp)
# t7 = t7 * 4
	movl	-44(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -44(%rbp)
# t6 = t7
	movl	-44(%rbp), %eax
	movl	%eax, -40(%rbp)
# t8 = arr[t6]
	movl	-40(%rbp), %edx
cltq
	movq	16(%rbp), %rdi
	addq	%rdi, %rdx
	movq	(%rdx) ,%rax
	movq	%rax, -48(%rbp)
# t9 = current_max + t8
	movl	-20(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -52(%rbp)
# current_max = t9
	movl	-52(%rbp), %eax
	movl	%eax, -20(%rbp)
# t10 = 1
	movl	$1, -56(%rbp)
# if max_sum < current_max goto .L3
	movl	-12(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jge	.L13
	jmp	.L3
.L13:
# t10 = 0
	movl	$0, -56(%rbp)
# goto .L4
	jmp	.L4
# goto .L4
	jmp	.L4
# max_sum = current_max
.L3:
	movl	-20(%rbp), %eax
	movl	%eax, -12(%rbp)
# goto .L4
	jmp	.L4
# t11 = 0
.L4:
	movl	$0, -60(%rbp)
# t12 = 1
	movl	$1, -64(%rbp)
# if current_max < t11 goto .L5
	movl	-20(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jge	.L14
	jmp	.L5
.L14:
# t12 = 0
	movl	$0, -64(%rbp)
# goto .L6
	jmp	.L6
# goto .L7
	jmp	.L7
# t13 = 0
.L5:
	movl	$0, -68(%rbp)
# current_max = t13
	movl	-68(%rbp), %eax
	movl	%eax, -20(%rbp)
# goto .L6
	jmp	.L6
# goto .L6
.L7:
	jmp	.L6
# return max_sum
.L1:
	movq	-12(%rbp), %rax
	leave
	ret
# function maxSubArraySum ends
	leave
	ret
	.size	maxSubArraySum, .-maxSubArraySum
# main: 

	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$304, %rsp
# t14 = 40
	movl	$40, -16(%rbp)
# param .LC0
# t15 = call printStr, 1
	movq	$.LC0, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -188(%rbp)
	addq	$4, %rsp
# t16 = &err
	leaq	-12(%rbp), %rax
	movq	%rax, -196(%rbp)
# param t16
# t17 = call readInt, 1
	movq	-196(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	readInt
	movq	%rax, -200(%rbp)
	addq	$4, %rsp
# n = t17
	movl	-200(%rbp), %eax
	movl	%eax, -4(%rbp)
# param .LC1
# t18 = call printStr, 1
	movq	$.LC1, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -208(%rbp)
	addq	$4, %rsp
# t19 = 0
	movl	$0, -212(%rbp)
# i = t19
	movl	-212(%rbp), %eax
	movl	%eax, -8(%rbp)
# t20 = 1
.L10:
	movl	$1, -216(%rbp)
# if i < n goto .L8
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jge	.L15
	jmp	.L8
.L15:
# t20 = 0
	movl	$0, -216(%rbp)
# goto .L9
	jmp	.L9
# goto .L9
	jmp	.L9
# t21 = i
.L11:
	movl	-8(%rbp), %eax
	movl	%eax, -220(%rbp)
# i = i + 1
	movl	-8(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -8(%rbp)
# goto .L10
	jmp	.L10
# t22 = 0
.L8:
	movl	$0, -224(%rbp)
# t23 = i
	movl	-8(%rbp), %eax
	movl	%eax, -228(%rbp)
# t23 = t23 * 4
	movl	-228(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -228(%rbp)
# t22 = t23
	movl	-228(%rbp), %eax
	movl	%eax, -224(%rbp)
# t24 = &err
	leaq	-12(%rbp), %rax
	movq	%rax, -232(%rbp)
# param t24
# t25 = call readInt, 1
	movq	-232(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	readInt
	movq	%rax, -236(%rbp)
	addq	$4, %rsp
# arr[t22] = t25
	movl	-224(%rbp), %edx
	movl	-236(%rbp), %eax
cltq
	movl	%eax, -176(%rbp,%rdx,1)
# goto .L11
	jmp	.L11
# param arr
.L9:
# param n
# t27 = call maxSubArraySum, 2
	movq	-4(%rbp), %rax
	pushq	%rax
	movq	%rax, %rsi
	leaq	-176(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	maxSubArraySum
	movq	%rax, -252(%rbp)
	addq	$8, %rsp
# sum = t27
	movl	-252(%rbp), %eax
	movl	%eax, -240(%rbp)
# param .LC2
# t28 = call printStr, 1
	movq	$.LC2, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -260(%rbp)
	addq	$4, %rsp
# param sum
# t29 = call printInt, 1
	movq	-240(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printInt
	movq	%rax, -268(%rbp)
	addq	$4, %rsp
# param .LC3
# t30 = call printStr, 1
	movq	$.LC3, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -276(%rbp)
	addq	$4, %rsp
# param .LC4
# t31 = call printStr, 1
	movq	$.LC4, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -284(%rbp)
	addq	$4, %rsp
# t32 = 0
	movl	$0, -288(%rbp)
# return t32
	movq	-288(%rbp), %rax
	leave
	ret
# function main ends
	leave
	ret
	.size	main, .-main
