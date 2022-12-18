.section	.rodata
.LC0:
	.string "Enter the value of a: \n"
.LC1:
	.string "Enter the value of b: \n"
.LC2:
	.string "\n"
.LC3:
	.string "The GCD of "
.LC4:
	.string " and "
.LC5:
	.string " is: "
.LC6:
	.string "\n"
.LC7:
	.string "TEST 4 COMPLETED\n"
# printStr: 
# printInt: 
# readInt: 
# gcd: 

	.text
	.globl	gcd
	.type	gcd, @function
gcd:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp
# t0 = 0
	movl	$0, -4(%rbp)
# t1 = 1
	movl	$1, -8(%rbp)
# if b == t0 goto .L0
	movl	24(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jne	.L3
	jmp	.L0
.L3:
# t1 = 0
	movl	$0, -8(%rbp)
# goto .L1
	jmp	.L1
# goto .L2
	jmp	.L2
# return a
.L0:
	movq	16(%rbp), %rax
	leave
	ret
# goto .L2
	jmp	.L2
# t2 = a % b
.L1:
	movl	16(%rbp), %eax
	cltd
	idivl	24(%rbp)
	movl	%edx, -16(%rbp)
# param b
# param t2
# t3 = call gcd, 2
	movq	-16(%rbp), %rax
	pushq	%rax
	movq	%rax, %rsi
	movq	24(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	gcd
	movq	%rax, -20(%rbp)
	addq	$8, %rsp
# return t3
	movq	-20(%rbp), %rax
	leave
	ret
# goto .L2
	jmp	.L2
# function gcd ends
.L2:
	leave
	ret
	.size	gcd, .-gcd
# main: 

	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$144, %rsp
# param .LC0
# t4 = call printStr, 1
	movq	$.LC0, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -28(%rbp)
	addq	$4, %rsp
# t5 = &err
	leaq	-16(%rbp), %rax
	movq	%rax, -36(%rbp)
# param t5
# t6 = call readInt, 1
	movq	-36(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	readInt
	movq	%rax, -40(%rbp)
	addq	$4, %rsp
# a = t6
	movl	-40(%rbp), %eax
	movl	%eax, -4(%rbp)
# param .LC1
# t7 = call printStr, 1
	movq	$.LC1, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -48(%rbp)
	addq	$4, %rsp
# t8 = &err
	leaq	-16(%rbp), %rax
	movq	%rax, -52(%rbp)
# param t8
# t9 = call readInt, 1
	movq	-52(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	readInt
	movq	%rax, -56(%rbp)
	addq	$4, %rsp
# b = t9
	movl	-56(%rbp), %eax
	movl	%eax, -8(%rbp)
# param a
# param b
# t10 = call gcd, 2
	movq	-8(%rbp), %rax
	pushq	%rax
	movq	%rax, %rsi
	movq	-4(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	gcd
	movq	%rax, -64(%rbp)
	addq	$8, %rsp
# gcd_val = t10
	movl	-64(%rbp), %eax
	movl	%eax, -12(%rbp)
# param .LC2
# t11 = call printStr, 1
	movq	$.LC2, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -72(%rbp)
	addq	$4, %rsp
# param .LC3
# t12 = call printStr, 1
	movq	$.LC3, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -80(%rbp)
	addq	$4, %rsp
# param a
# t13 = call printInt, 1
	movq	-4(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printInt
	movq	%rax, -88(%rbp)
	addq	$4, %rsp
# param .LC4
# t14 = call printStr, 1
	movq	$.LC4, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -96(%rbp)
	addq	$4, %rsp
# param b
# t15 = call printInt, 1
	movq	-8(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printInt
	movq	%rax, -100(%rbp)
	addq	$4, %rsp
# param .LC5
# t16 = call printStr, 1
	movq	$.LC5, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -108(%rbp)
	addq	$4, %rsp
# param gcd_val
# t17 = call printInt, 1
	movq	-12(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printInt
	movq	%rax, -112(%rbp)
	addq	$4, %rsp
# param .LC6
# t18 = call printStr, 1
	movq	$.LC6, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -120(%rbp)
	addq	$4, %rsp
# param .LC7
# t19 = call printStr, 1
	movq	$.LC7, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -128(%rbp)
	addq	$4, %rsp
# t20 = 0
	movl	$0, -132(%rbp)
# return t20
	movq	-132(%rbp), %rax
	leave
	ret
# function main ends
	leave
	ret
	.size	main, .-main
