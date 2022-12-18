.section	.rodata
.LC0:
	.string "Enter the number of terms n in the fibonacci series: (Keep n < 25)\n"
.LC1:
	.string "\n"
.LC2:
	.string "The first "
.LC3:
	.string " terms of the fibonacci series are: \n"
.LC4:
	.string ", "
.LC5:
	.string "\n"
.LC6:
	.string "TEST 5 COMPLETED\n"
# printStr: 
# printInt: 
# readInt: 
# fibonacci_recur: 
# main: 

	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$400, %rsp
# param .LC0
# t0 = call printStr, 1
	movq	$.LC0, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -24(%rbp)
	addq	$4, %rsp
# t1 = &err
	leaq	-8(%rbp), %rax
	movq	%rax, -32(%rbp)
# param t1
# t2 = call readInt, 1
	movq	-32(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	readInt
	movq	%rax, -36(%rbp)
	addq	$4, %rsp
# n = t2
	movl	-36(%rbp), %eax
	movl	%eax, -4(%rbp)
# t3 = 50
	movl	$50, -40(%rbp)
# t4 = 0
	movl	$0, -244(%rbp)
# i = t4
	movl	-244(%rbp), %eax
	movl	%eax, -12(%rbp)
# t5 = 1
.L2:
	movl	$1, -248(%rbp)
# if i < n goto .L0
	movl	-12(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jge	.L14
	jmp	.L0
.L14:
# t5 = 0
	movl	$0, -248(%rbp)
# goto .L1
	jmp	.L1
# goto .L1
	jmp	.L1
# t6 = i
.L3:
	movl	-12(%rbp), %eax
	movl	%eax, -252(%rbp)
# i = i + 1
	movl	-12(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -12(%rbp)
# goto .L2
	jmp	.L2
# t7 = 0
.L0:
	movl	$0, -256(%rbp)
# t8 = i
	movl	-12(%rbp), %eax
	movl	%eax, -260(%rbp)
# t8 = t8 * 4
	movl	-260(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -260(%rbp)
# t7 = t8
	movl	-260(%rbp), %eax
	movl	%eax, -256(%rbp)
# param i
# t9 = call fibonacci_recur, 1
	movq	-12(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	fibonacci_recur
	movq	%rax, -268(%rbp)
	addq	$4, %rsp
# fib_arr[t7] = t9
	movl	-256(%rbp), %edx
	movl	-268(%rbp), %eax
cltq
	movl	%eax, -240(%rbp,%rdx,1)
# goto .L3
	jmp	.L3
# param .LC1
.L1:
# t10 = call printStr, 1
	movq	$.LC1, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -276(%rbp)
	addq	$4, %rsp
# param .LC2
# t11 = call printStr, 1
	movq	$.LC2, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -284(%rbp)
	addq	$4, %rsp
# param n
# t12 = call printInt, 1
	movq	-4(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printInt
	movq	%rax, -292(%rbp)
	addq	$4, %rsp
# param .LC3
# t13 = call printStr, 1
	movq	$.LC3, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -300(%rbp)
	addq	$4, %rsp
# t14 = 0
	movl	$0, -304(%rbp)
# i = t14
	movl	-304(%rbp), %eax
	movl	%eax, -12(%rbp)
# t15 = 1
.L6:
	movl	$1, -308(%rbp)
# t16 = n - t15
	movl	-4(%rbp), %edx
	movl	-308(%rbp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -312(%rbp)
# t17 = 1
	movl	$1, -316(%rbp)
# if i < t16 goto .L4
	movl	-12(%rbp), %eax
	cmpl	-312(%rbp), %eax
	jge	.L15
	jmp	.L4
.L15:
# t17 = 0
	movl	$0, -316(%rbp)
# goto .L5
	jmp	.L5
# goto .L5
	jmp	.L5
# t18 = i
.L7:
	movl	-12(%rbp), %eax
	movl	%eax, -320(%rbp)
# i = i + 1
	movl	-12(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -12(%rbp)
# goto .L6
	jmp	.L6
# t19 = 0
.L4:
	movl	$0, -324(%rbp)
# t20 = i
	movl	-12(%rbp), %eax
	movl	%eax, -328(%rbp)
# t20 = t20 * 4
	movl	-328(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -328(%rbp)
# t19 = t20
	movl	-328(%rbp), %eax
	movl	%eax, -324(%rbp)
# t21 = fib_arr[t19]
	movl	-324(%rbp), %edx
cltq
	movl	-240(%rbp,%rdx,1), %eax
	movl	%eax, -332(%rbp)
# param t21
# t22 = call printInt, 1
	movq	-332(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printInt
	movq	%rax, -336(%rbp)
	addq	$4, %rsp
# param .LC4
# t23 = call printStr, 1
	movq	$.LC4, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -344(%rbp)
	addq	$4, %rsp
# goto .L7
	jmp	.L7
# t24 = 1
.L5:
	movl	$1, -348(%rbp)
# t25 = n - t24
	movl	-4(%rbp), %edx
	movl	-348(%rbp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -352(%rbp)
# t26 = 0
	movl	$0, -356(%rbp)
# t27 = t25
	movl	-352(%rbp), %eax
	movl	%eax, -360(%rbp)
# t27 = t27 * 4
	movl	-360(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -360(%rbp)
# t26 = t27
	movl	-360(%rbp), %eax
	movl	%eax, -356(%rbp)
# t28 = fib_arr[t26]
	movl	-356(%rbp), %edx
cltq
	movl	-240(%rbp,%rdx,1), %eax
	movl	%eax, -364(%rbp)
# param t28
# t29 = call printInt, 1
	movq	-364(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printInt
	movq	%rax, -368(%rbp)
	addq	$4, %rsp
# param .LC5
# t30 = call printStr, 1
	movq	$.LC5, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -376(%rbp)
	addq	$4, %rsp
# param .LC6
# t31 = call printStr, 1
	movq	$.LC6, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -384(%rbp)
	addq	$4, %rsp
# t32 = 0
	movl	$0, -388(%rbp)
# return t32
	movq	-388(%rbp), %rax
	leave
	ret
# function main ends
	leave
	ret
	.size	main, .-main
# fibonacci_recur: 

	.text
	.globl	fibonacci_recur
	.type	fibonacci_recur, @function
fibonacci_recur:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$64, %rsp
# t33 = 0
	movl	$0, -4(%rbp)
# t34 = 1
	movl	$1, -8(%rbp)
# if n == t33 goto .L8
	movl	16(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jne	.L16
	jmp	.L8
.L16:
# t34 = 0
	movl	$0, -8(%rbp)
# goto .L9
	jmp	.L9
# goto .L10
	jmp	.L10
# t35 = 0
.L8:
	movl	$0, -12(%rbp)
# return t35
	movq	-12(%rbp), %rax
	leave
	ret
# goto .L10
	jmp	.L10
# t36 = 1
.L9:
	movl	$1, -16(%rbp)
# t37 = 1
	movl	$1, -20(%rbp)
# if n == t36 goto .L11
	movl	16(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jne	.L17
	jmp	.L11
.L17:
# t37 = 0
	movl	$0, -20(%rbp)
# goto .L12
	jmp	.L12
# goto .L13
	jmp	.L13
# t38 = 1
.L11:
	movl	$1, -24(%rbp)
# return t38
	movq	-24(%rbp), %rax
	leave
	ret
# goto .L10
	jmp	.L10
# t39 = 1
.L12:
	movl	$1, -32(%rbp)
# t40 = n - t39
	movl	16(%rbp), %edx
	movl	-32(%rbp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -36(%rbp)
# param t40
# t41 = call fibonacci_recur, 1
	movq	-36(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	fibonacci_recur
	movq	%rax, -40(%rbp)
	addq	$4, %rsp
# t42 = 2
	movl	$2, -44(%rbp)
# t43 = n - t42
	movl	16(%rbp), %edx
	movl	-44(%rbp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -48(%rbp)
# param t43
# t44 = call fibonacci_recur, 1
	movq	-48(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	fibonacci_recur
	movq	%rax, -52(%rbp)
	addq	$4, %rsp
# t45 = t41 + t44
	movl	-40(%rbp), %eax
	movl	-52(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -56(%rbp)
# return t45
	movq	-56(%rbp), %rax
	leave
	ret
# goto .L10
	jmp	.L10
# goto .L10
.L13:
	jmp	.L10
# function fibonacci_recur ends
.L10:
	leave
	ret
	.size	fibonacci_recur, .-fibonacci_recur
