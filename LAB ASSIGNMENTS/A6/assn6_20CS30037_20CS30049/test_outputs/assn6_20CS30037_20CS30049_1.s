	.globl	glbl_idx
	.data
	.align	4
	.type	glbl_idx, @object
	.size	glbl_idx, 4
glbl_idx:
	.long	0
.section	.rodata
.LC0:
	.string "Enter 15 array elements in ascending order in seperate lines:\n"
.LC1:
	.string "The array elements taken as user input are: \n"
.LC2:
	.string " "
.LC3:
	.string "\n"
.LC4:
	.string "Enter the number to search for in the array: \n"
.LC5:
	.string "The given key is not present in the array.\n"
.LC6:
	.string "The given key is present in the arrray at index: "
.LC7:
	.string "\n"
.LC8:
	.string "TEST 1 COMPLETED\n"
# t0 = 0
# glbl_idx = t0
# t1 = 100
# MAX_ARR_SIZE = t1
# printStr: 
# printInt: 
# readInt: 
# binarySearch: 

	.text
	.globl	binarySearch
	.type	binarySearch, @function
binarySearch:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$80, %rsp
# t2 = 1
.L5:
	movl	$1, -4(%rbp)
# if left <= right goto .L0
	movl	32(%rbp), %eax
	cmpl	40(%rbp), %eax
	jg	.L20
	jmp	.L0
.L20:
# t2 = 0
	movl	$0, -4(%rbp)
# goto .L1
	jmp	.L1
# goto .L1
	jmp	.L1
# t3 = left + right
.L0:
	movl	32(%rbp), %eax
	movl	40(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -8(%rbp)
# t4 = 2
	movl	$2, -12(%rbp)
# t5 = t3 / t4
	movl	-8(%rbp), %eax
	cltd
	idivl	-12(%rbp)
	movl	%eax, -16(%rbp)
# mid = t5
	movl	-16(%rbp), %eax
	movl	%eax, -20(%rbp)
# t6 = 0
	movl	$0, -24(%rbp)
# t7 = mid
	movl	-20(%rbp), %eax
	movl	%eax, -28(%rbp)
# t7 = t7 * 4
	movl	-28(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -28(%rbp)
# t6 = t7
	movl	-28(%rbp), %eax
	movl	%eax, -24(%rbp)
# t8 = int_arr[t6]
	movl	-24(%rbp), %edx
cltq
	movq	16(%rbp), %rdi
	addq	%rdi, %rdx
	movq	(%rdx) ,%rax
	movq	%rax, -32(%rbp)
# t9 = 1
	movl	$1, -36(%rbp)
# if t8 == key goto .L2
	movl	-32(%rbp), %eax
	cmpl	24(%rbp), %eax
	jne	.L21
	jmp	.L2
.L21:
# t9 = 0
	movl	$0, -36(%rbp)
# goto .L3
	jmp	.L3
# goto .L4
	jmp	.L4
# return mid
.L2:
	movq	-20(%rbp), %rax
	leave
	ret
# goto .L5
	jmp	.L5
# t10 = 0
.L3:
	movl	$0, -40(%rbp)
# t11 = mid
	movl	-20(%rbp), %eax
	movl	%eax, -44(%rbp)
# t11 = t11 * 4
	movl	-44(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -44(%rbp)
# t10 = t11
	movl	-44(%rbp), %eax
	movl	%eax, -40(%rbp)
# t12 = int_arr[t10]
	movl	-40(%rbp), %edx
cltq
	movq	16(%rbp), %rdi
	addq	%rdi, %rdx
	movq	(%rdx) ,%rax
	movq	%rax, -48(%rbp)
# t13 = 1
	movl	$1, -52(%rbp)
# if t12 < key goto .L6
	movl	-48(%rbp), %eax
	cmpl	24(%rbp), %eax
	jge	.L22
	jmp	.L6
.L22:
# t13 = 0
	movl	$0, -52(%rbp)
# goto .L7
	jmp	.L7
# goto .L8
	jmp	.L8
# t14 = 1
.L6:
	movl	$1, -56(%rbp)
# t15 = mid + t14
	movl	-20(%rbp), %eax
	movl	-56(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -60(%rbp)
# left = t15
	movl	-60(%rbp), %eax
	movl	%eax, 32(%rbp)
# goto .L5
	jmp	.L5
# t16 = 1
.L7:
	movl	$1, -64(%rbp)
# t17 = mid - t16
	movl	-20(%rbp), %edx
	movl	-64(%rbp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -68(%rbp)
# right = t17
	movl	-68(%rbp), %eax
	movl	%eax, 40(%rbp)
# goto .L5
	jmp	.L5
# goto .L5
.L8:
	jmp	.L5
# goto .L5
.L4:
	jmp	.L5
# t18 = 1
.L1:
	movl	$1, -72(%rbp)
# t19 = -t18
	movl	-72(%rbp), %eax
	negl	%eax
	movl	%eax, -76(%rbp)
# return t19
	movq	-76(%rbp), %rax
	leave
	ret
# function binarySearch ends
	leave
	ret
	.size	binarySearch, .-binarySearch
# main: 

	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$304, %rsp
# t20 = 2
	movl	$2, -8(%rbp)
# glbl_idx = t20
	movl	-8(%rbp), %eax
	movl	%eax, glbl_idx(%rip)
# t21 = 15
	movl	$15, -12(%rbp)
# param .LC0
# t22 = call printStr, 1
	movq	$.LC0, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -96(%rbp)
	addq	$4, %rsp
# t23 = 0
	movl	$0, -100(%rbp)
# i = t23
	movl	-100(%rbp), %eax
	movl	%eax, -76(%rbp)
# t24 = 15
.L11:
	movl	$15, -104(%rbp)
# t25 = 1
	movl	$1, -108(%rbp)
# if i < t24 goto .L9
	movl	-76(%rbp), %eax
	cmpl	-104(%rbp), %eax
	jge	.L23
	jmp	.L9
.L23:
# t25 = 0
	movl	$0, -108(%rbp)
# goto .L10
	jmp	.L10
# goto .L10
	jmp	.L10
# t26 = i
.L12:
	movl	-76(%rbp), %eax
	movl	%eax, -112(%rbp)
# i = i + 1
	movl	-76(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -76(%rbp)
# goto .L11
	jmp	.L11
# t27 = 0
.L9:
	movl	$0, -116(%rbp)
# t28 = i
	movl	-76(%rbp), %eax
	movl	%eax, -120(%rbp)
# t28 = t28 * 4
	movl	-120(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -120(%rbp)
# t27 = t28
	movl	-120(%rbp), %eax
	movl	%eax, -116(%rbp)
# t29 = &err
	leaq	-84(%rbp), %rax
	movq	%rax, -128(%rbp)
# param t29
# t30 = call readInt, 1
	movq	-128(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	readInt
	movq	%rax, -132(%rbp)
	addq	$4, %rsp
# arr_1[t27] = t30
	movl	-116(%rbp), %edx
	movl	-132(%rbp), %eax
cltq
	movl	%eax, -72(%rbp,%rdx,1)
# goto .L12
	jmp	.L12
# param .LC1
.L10:
# t31 = call printStr, 1
	movq	$.LC1, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -140(%rbp)
	addq	$4, %rsp
# t32 = 0
	movl	$0, -144(%rbp)
# i = t32
	movl	-144(%rbp), %eax
	movl	%eax, -76(%rbp)
# t33 = 15
.L15:
	movl	$15, -148(%rbp)
# t34 = 1
	movl	$1, -152(%rbp)
# if i < t33 goto .L13
	movl	-76(%rbp), %eax
	cmpl	-148(%rbp), %eax
	jge	.L24
	jmp	.L13
.L24:
# t34 = 0
	movl	$0, -152(%rbp)
# goto .L14
	jmp	.L14
# goto .L14
	jmp	.L14
# t35 = i
.L16:
	movl	-76(%rbp), %eax
	movl	%eax, -156(%rbp)
# i = i + 1
	movl	-76(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -76(%rbp)
# goto .L15
	jmp	.L15
# t36 = 0
.L13:
	movl	$0, -164(%rbp)
# t37 = i
	movl	-76(%rbp), %eax
	movl	%eax, -168(%rbp)
# t37 = t37 * 4
	movl	-168(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -168(%rbp)
# t36 = t37
	movl	-168(%rbp), %eax
	movl	%eax, -164(%rbp)
# t38 = arr_1[t36]
	movl	-164(%rbp), %edx
cltq
	movl	-72(%rbp,%rdx,1), %eax
	movl	%eax, -172(%rbp)
# param t38
# t39 = call printInt, 1
	movq	-172(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printInt
	movq	%rax, -176(%rbp)
	addq	$4, %rsp
# param .LC2
# t40 = call printStr, 1
	movq	$.LC2, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -184(%rbp)
	addq	$4, %rsp
# goto .L16
	jmp	.L16
# param .LC3
.L14:
# t41 = call printStr, 1
	movq	$.LC3, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -192(%rbp)
	addq	$4, %rsp
# param .LC4
# t42 = call printStr, 1
	movq	$.LC4, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -204(%rbp)
	addq	$4, %rsp
# t43 = &err
	leaq	-84(%rbp), %rax
	movq	%rax, -208(%rbp)
# param t43
# t44 = call readInt, 1
	movq	-208(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	readInt
	movq	%rax, -212(%rbp)
	addq	$4, %rsp
# my_key = t44
	movl	-212(%rbp), %eax
	movl	%eax, -196(%rbp)
# t45 = 0
	movl	$0, -216(%rbp)
# t46 = 9
	movl	$9, -220(%rbp)
# start = t45
	movl	-216(%rbp), %eax
	movl	%eax, -224(%rbp)
# end = t46
	movl	-220(%rbp), %eax
	movl	%eax, -228(%rbp)
# param arr_1
# param my_key
# param start
# param end
# t48 = call binarySearch, 4
	movq	-228(%rbp), %rax
	pushq	%rax
	movq	%rax, %rcx
	movq	-224(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdx
	movq	-196(%rbp), %rax
	pushq	%rax
	movq	%rax, %rsi
	leaq	-72(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	binarySearch
	movq	%rax, -240(%rbp)
	addq	$16, %rsp
# key_idx = t48
	movl	-240(%rbp), %eax
	movl	%eax, -244(%rbp)
# t49 = 1
	movl	$1, -248(%rbp)
# t50 = -t49
	movl	-248(%rbp), %eax
	negl	%eax
	movl	%eax, -252(%rbp)
# t51 = 1
	movl	$1, -256(%rbp)
# if key_idx == t50 goto .L17
	movl	-244(%rbp), %eax
	cmpl	-252(%rbp), %eax
	jne	.L25
	jmp	.L17
.L25:
# t51 = 0
	movl	$0, -256(%rbp)
# goto .L18
	jmp	.L18
# goto .L19
	jmp	.L19
# param .LC5
.L17:
# t52 = call printStr, 1
	movq	$.LC5, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -264(%rbp)
	addq	$4, %rsp
# goto .L19
	jmp	.L19
# param .LC6
.L18:
# t53 = call printStr, 1
	movq	$.LC6, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -272(%rbp)
	addq	$4, %rsp
# param key_idx
# t54 = call printInt, 1
	movq	-244(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printInt
	movq	%rax, -276(%rbp)
	addq	$4, %rsp
# goto .L19
	jmp	.L19
# param .LC7
.L19:
# t55 = call printStr, 1
	movq	$.LC7, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -284(%rbp)
	addq	$4, %rsp
# param .LC8
# t56 = call printStr, 1
	movq	$.LC8, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -292(%rbp)
	addq	$4, %rsp
# t57 = 0
	movl	$0, -296(%rbp)
# return t57
	movq	-296(%rbp), %rax
	leave
	ret
# function main ends
	leave
	ret
	.size	main, .-main
