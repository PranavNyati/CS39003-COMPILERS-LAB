	.file	"asgn1.c"          # name of the source file from which the assembly code is generated
	
	.text                      # executable code is stored in the .text section
	
	.section	.rodata        # refers to the read-only data section
	.align 8                   # aligns the data to 8-byte boundary 

.LC0:                          # LC0 is a local label that references the address of the read-only string of 1st printf of main
	.string	"Enter the string (all lowrer case): "
.LC1:                          # Local label to refer to the address of the read-only string "%s"
	.string	"%s"
.LC2:                          # refers to the address of string "Length of the string: %d\n"
	.string	"Length of the string: %d\n"
	.align 8                   # aligns the data to 8-byte boundary
.LC3:                          # refers to the address of string for 3rd printf of main
	.string	"The string in descending order: %s\n"
	

	.text                      # executable code is stored in the .text section
	
	.globl	main               # .globl main means that main function is globally visible in the executable code
	.type	main, @function    # tells the assembler that main is a function

main:
.LFB0:                         # LFB0 local label indicates the start of the function main (LFB is the Function Begin Label)
	.cfi_startproc
	endbr64
	pushq	%rbp               # saves the caller's value for the base pointer into callee function's stack frame (i.e. here in the stack frame of the main function)
	        
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp         # saves the current stack pointer value in %rbp; this allows the callee function to refer to local variables and caller function's arguments
	.cfi_def_cfa_register 6
	subq	$80, %rsp          # allocate 80 bytes of stack space for the local variables of main 
	
	movq	%fs:40, %rax       # the next 3 instructions perform a stack guard check; value at fs:40 --> rax
	movq	%rax, -8(%rbp)     # value at rax --> to address -8(%rbp)
	xorl	%eax, %eax         # (eax = xor of eax with eax) xor of the same values (both in eax) is 0, which means we are safe to execute the next instruction, 
	                           # otherwise, we move to a special function that indicates that stack is corrupted 

	leaq	.LC0(%rip), %rdi   # load address of string referenced by LC0 into  'rdi' (as rdi stores the 1st argument to the printf function)
							   # (here the %rip indicates that the relative address of the string is to be used) 
	movl	$0, %eax           # load value 0 into 'eax' 
	call	printf@PLT         # call to invoke printf 
	
	leaq	-64(%rbp), %rax    	# address rbp-64 (essentially the address 64 lower than the address stored in rbp) loaded into 'rax'
								# (address rbp-64 points to address of the str char array)
	
	movq	%rax, %rsi          # value of rax (pointer to the str char array) -->  'rsi' (rsi stores the 2nd argument to the scanf function)
	
	leaq	.LC1(%rip), %rdi     # load address of LC1 f-string into 'rdi' (rdi stores 1st arg to scanf)
	movl	$0, %eax             # load value 0 into 'eax'
	call	__isoc99_scanf@PLT   # invoke scanf to take the input string and store in str (1st arg -> format specifier %s , 2nd argument -> pointer to str)
	
	leaq	-64(%rbp), %rax      # after taking input string, address of the array str (rbp-64) --> move to 'rax' 
	movq	%rax, %rdi           # address value stored in rax (of the str array) -->  'rdi' (rdi stores the 1st arg to the function length invoked next)
	
	call	length               # call to invoke the length function
	
	movl	%eax, -68(%rbp)      # eax stores the return val of the previous length function call, which is moved to the address -68(%rbp) , so address -68(%rbp) is of variable 'len'
	movl	-68(%rbp), %eax      # value stored in the address -68(%rbp) (variable 'len') --> eax 
	movl	%eax, %esi           # value stored in the eax in prev instruction --> esi (esi stores the 2nd argument to the next printf call, which is len)
	
	leaq	.LC2(%rip), %rdi     # load address of LC2 f-string into 'rdi' (1st arg to the 2nd printf in main)
	movl	$0, %eax             # load value 0 into 'eax'
	call	printf@PLT           # invoke printf to print the length of the input string
	
	leaq	-32(%rbp), %rdx      # address -32(%rbp) loaded into rdx' (stores the 3rd arg to sort function , which is the pointer to the dest array)
	                             # thus, address -32(%rbp) is the address of the dest array
	movl	-68(%rbp), %ecx      # value stored in the address -68(%rbp) (this address is of variable 'len') --> ecx 
	
	leaq	-64(%rbp), %rax      # address -64(%rbp) (address of the str array) --> 'rax' 
	movl	%ecx, %esi           # value (of variable 'len) in ecx --> esi ( esi - stores the 2nd arg to the sort call)
	movq	%rax, %rdi           # value in rax --> rdi (rdi stores the 1st arg to function sort - pointer to the str array)
	
	call	sort                 # call to invoke the sort function 
	
	leaq	-32(%rbp), %rax      # address -32(%rbp) (address of the dest array) -->  'rax'
	movq	%rax, %rsi           # address value in rax --> rsi (rsi stores the 2rd argument to the printf call below)
	
	leaq	.LC3(%rip), %rdi     # address of the string referenced by the label LC3 -->  'rdi'
	movl	$0, %eax             # load value 0 into 'eax'
	call	printf@PLT           # invoke the printf function (1st argument -> string referenced by the label LC3, 2nd argument ->ptr to dest array)
	
	movl	$0, %eax             # load value 0 in 'eax' (return value of the main)
	
	movq	-8(%rbp), %rcx       # the next 4 instructions perform a stack guard check; value stored in the address -8(%rbp) --> 'rcx' 
	xorq	%fs:40, %rcx         # xor (fs:40 , rcx) --> 'rcx'
	je	.L3                      # if xor of the values == 0, then jump to the label .L3 (means that the stack is not corrupted)
	                               
	call	__stack_chk_fail@PLT # if xor != 0, means the stack is corrupted, so a call to __stack_chk_fail is made 

.L3:                            
	leave                       # leave - pops the return address of the caller from the callee stack and jumps to it 
	.cfi_def_cfa 7, 8           
	ret                         # return from the main function
	.cfi_endproc

.LFE0:                          # LFE0 local label indicates the end of the function main (LFE is the Function End Label)
	.size	main, .-main        # the .size directive tells the size of the function main in bytes
	                            # size of the function MAIN = .(current address of the instruction) - main (address of the starting point of the function MAIN)
	
	.globl	length              # length function is globally visible in the executable code
	.type	length, @function   # length is a function

length:
.LFB1:                          # LFB1 indicates the start of function length
	.cfi_startproc
	endbr64
	
	pushq	%rbp                # saves the caller's value for the base pointer into callee function's stack frame 
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	
	movq	%rsp, %rbp          # saves the current stack pointer value into the base pointer of the stack frame of the callee function 
	.cfi_def_cfa_register 6
	
	movq	%rdi, -24(%rbp)     # rdi (has 1st arg to function length - the ptr/address to str array) ->  address rbp-24 
								# so, the address of 0th char of str array is stored at rbp-24 in the stack frame of the length function

	movl	$0, -4(%rbp)        # set value at address -4(%rbp) to 0 (sets i = 0) 
	jmp	.L5                     # unconditional jump to the label L5

.L6:                           
	addl	$1, -4(%rbp)        # increment the counter i by 1

.L5:
	movl	-4(%rbp), %eax      # current i (stored in the address-4(%rbp)) --> 'eax' 
	movslq	%eax, %rdx          # movslq extends 32 bit value in eax to 64 bit value in rdx while preserving the sign value
	
	movq	-24(%rbp), %rax     # value at address rbp-24 (address of 0th position of str array) --> 'rax' 
	addq	%rdx, %rax          # rax <--- rax + rdx (rax has address of 0th char of str, rdx has value i); thus rax now stores address of str[i]
	movzbl	(%rax), %eax        # byte value at address in rax (i.e., value of str[i]) --> 'eax' with 0-extending byte to long
	
	testb	%al, %al            # al is used to access the least significant byte of eax register; 
								# testb is the bitwise AND between al and itself (so if %al is null, then only the AND with itself is '\0')

	jne	.L6                     # if str[i] != '\0' then jump to the label L6 
	
	movl	-4(%rbp), %eax      # if str[i] == '\0', then move the current value of i (at address rbp-4) to eax 
								# (this value of i is string length and is moved to eax as this is the return value of the length function
	
	popq	%rbp                # # pop the base pointer from the callee stack and return to the caller function
	
	.cfi_def_cfa 7, 8
	ret                         # return from the function length
	.cfi_endproc

.LFE1:                          # LFE1 local label indicates the end of the function length 
	.size	length, .-length    # size of the function LENGTH (calculated similar to that for main)
	

	.globl	sort                # sort function is globally visible in the executable code
	.type	sort, @function     # sort is a function

sort:
.LFB2:                          # start of the function sort
	.cfi_startproc
	endbr64
	pushq	%rbp                # saves the caller's value for the base pointer into callee function's stack frame 
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp          # saves the current stack pointer value into the base pointer of the stack frame of the callee function 
	.cfi_def_cfa_register 6
	
	subq	$48, %rsp			# allocate stack space for the local variables of sort function
	movq	%rdi, -24(%rbp)     # value at rdi (1st arg to sort function - the address of str array) --> address rbp-24 
	
	movl	%esi, -28(%rbp)     # esi (stored 2nd arg of sort - the string length) -> address rbp-28 
	                            # so, the string length is stored at address rbp-28 
	
	movq	%rdx, -40(%rbp)     # rdx (stored 3rd arg of sort - address of dest array) -> address rbp-40 
	                            
	movl	$0, -8(%rbp)        # address rbp -8 (stores i for this function ) -> set to 0
	jmp	.L9                     # unconditional jump to the label L9

.L13:
	movl	$0, -4(%rbp)        # address rbp-4 (stores j in the sort function) -> set to 0
	jmp	.L10                    # unconditional jump to the label L10
.L12:
	movl	-8(%rbp), %eax      # value of i (stored at rbp - 8) -> 'eax' 
	movslq	%eax, %rdx          # movslq extends 32 bit value in 'eax' to 64 bit value in 'rdx' while preserving the sign value (now rdx contains the value of i)
	movq	-24(%rbp), %rax     # value at address rbp -24 (address of str array)  -> 'rax'
	addq	%rdx, %rax          # rax <--- rax + rdx (i.e., rax = rax + i) => rax now stores the address of str[i]
	movzbl	(%rax), %edx        # address stored at 'rax' (of the ith character in str) --> move to 'edx' 
	movl	-4(%rbp), %eax      # value of j (stored at rbp - 4) --> 'eax'
	movslq	%eax, %rcx          # movslq extends 32 bit value in eax to 64 bit in 'rcx' while preserving the sign value (now rcx contains the value of j)
	movq	-24(%rbp), %rax     # value at rbp-24 (address of str array) --> 'rax'
	addq	%rcx, %rax          # rax <--- rax + rcx (i.e., rax = rax + j) => rax now stores the address of str[j]
	movzbl	(%rax), %eax        # address stored at 'rax' (of the jth character in str) --> 'eax'
	cmpb	%al, %dl            # compare the value of str[i] with the value of str[j] 
	jge	.L11                    # if str[i] >= str[j] then jump to the label L11
	
	# if str[i] < str[j] then swap the values of str[i] and str[j] 
	movl	-8(%rbp), %eax      # value of i (stored at rbp - 8) --> to 'eax'
	movslq	%eax, %rdx          # bit extension(32 to 64) with sign preserving (now rdx contains the value of i)
	movq	-24(%rbp), %rax     # value at address rbp-24 (address of str array) -> 'rax'
	addq	%rdx, %rax          # rax <--- rax + rdx (i.e., rax = rax + i) => rax now stores the address of str[i]
	movzbl	(%rax), %eax        # address stored at 'rax' (of the ith character in str) -->  'eax'
	movb	%al, -9(%rbp)       # move the value in str[i] (stored in 'eax') to the address rbp-9 (address rbp-9 stores variable temp)
	
	movl	-4(%rbp), %eax      # move the value of j (stored at rbp - 4) to 'eax'
	movslq	%eax, %rdx          # bit extension(32 to 64) with sign preserving (now rdx contains the value of j)
	movq	-24(%rbp), %rax     # value at address rbp -24 (address of str array) --> to 'rax'
	addq	%rdx, %rax          # rax <--- rax + rdx (i.e., rax = rax + j) => rax now stores the address of the str[j]
	
	movl	-8(%rbp), %edx      # value of i (stored at rbp - 8) -->  'edx'
	movslq	%edx, %rcx          # bit extension(32 to 64) with sign preserving (now rcx contains the value of i)
	movq	-24(%rbp), %rdx     # value at address rbp-24 (address of str array) -->  'rdx'
	addq	%rcx, %rdx          # rdx <--- rdx + rcx (i.e., rdx = rdx + i) => rdx now stores the address of str[i]
	
	movzbl	(%rax), %eax        # address stored at 'rax' (of the jth character in str) --> to 'eax'
	movb	%al, (%rdx)         # move the value of str[j] (stored in 'eax') to the address stored at 'rdx' (i.e., the address of str[i])
	
	movl	-4(%rbp), %eax      # value of j(stored at rbp-4) -> 'eax'
	movslq	%eax, %rdx          # value in eax (value of the counter j) --> rdx (now rdx contains the value of j)
	movq	-24(%rbp), %rax     # value at address rbp-24 (address of str array) --> 'rax'
	addq	%rax, %rdx          # rdx <--- rdx + rax (i.e., rdx = rdx + j) => rdx now stores the address of str[j]
	movzbl	-9(%rbp), %eax      # value at address rbp-9 (address of temp, which currently stores original str[i]) --> 'eax'
	movb	%al, (%rdx)         # move the value in temp (stored in 'eax') to the address stored at 'rdx' (i.e., the address of str[j])

	# after swapping the values of str[i] and str[j], the control moves to label L11
.L11:
	addl	$1, -4(%rbp)          # increment j by 1 (stored at rbp - 4), and continue with label L10 
.L10:                           
	movl	-4(%rbp), %eax        # value of counter j (at address rbp - 4) --> 'eax'
	cmpl	-28(%rbp), %eax       # compare the string length (stored at address rbp-28) with the current j value
	jl	.L12                      # if j < string length, jump to the label L12
	
	addl	$1, -8(%rbp)          # if j >= string length, then end inner for loop and increment i by 1, and continue with label L9

.L9:
	movl	-8(%rbp), %eax        # move the value of i (at rbp -8) to -> 'eax'
	cmpl	-28(%rbp), %eax       # compare the string length (stored at rbp-28) with the current i value
	jl	.L13                      # if i < string length, jump to the label L13
	
	movq	-40(%rbp), %rdx       # if i >= string length, move the value at address rbp-40 (address of dist array) to rdx
								  #	(as rdx stores 3rd arg to the reverse function call below - ptr to dist array)
	
	movl	-28(%rbp), %ecx       # val at address rbp-28 (the length of string str) -->  ecx
	movq	-24(%rbp), %rax       # val at address rbp-24 (pointer to str array) --> rax
	movl	%ecx, %esi            # value at ecx (length of input string) --> esi (esi stores 2nd arg to the reverse)
	movq	%rax, %rdi            # value at rax (pointer to str array) --> rdi (rdi stores 1st arg to the reverse)
	
	call	reverse               # call to reverse function (arg1 -> pointer to str array , arg2 -> length of str, arg3 -> pointer to dist array)
	
	nop                           # nop performs no operation on registers/memory, but is done to align code to 16-byte or 32-byte boundary
	
	leave                         # leave instruction pops the return address from the callee stack and jumps to it 
	.cfi_def_cfa 7, 8
	ret                           # return from the function sort
	.cfi_endproc
.LFE2:                            # end of the function sort
	.size	sort, .-sort          # size of the function SORT (calculated similar to that for main function)
	
	
	.globl	reverse               # reverse function is globally visible in the executable code
	.type	reverse, @function    # reverse is a function

reverse:
.LFB3:                             # start of the function reverse
	.cfi_startproc
	endbr64
	pushq	%rbp                   # saves the caller's value for the base pointer into callee function's stack frame 
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp             # saves the current stack pointer value into the base pointer of the stack frame of the callee function (here, the sort function)
	.cfi_def_cfa_register 6        
	movq	%rdi, -24(%rbp)        # the value of rdi (1st arg to function -> str array) -> rbp-24 ; so rbp-24 stores ptr to str
	movl	%esi, -28(%rbp)        # esi (stores 2nd arg -> string length) -> rbp-28 (rbp-28 stores string length as a local var of reverse function)
	movq	%rdx, -40(%rbp)        # rdx( stores 3rd arg -> dist array) --> address rbp-40
	movl	$0, -8(%rbp)           # address rbp-8 stores the counter i ; here it is set to 0
	jmp	.L15                       # unconditional jump to the label L15
.L20:
	movl	-28(%rbp), %eax        # string length stored at rbp-28 --> 'eax'
	subl	-8(%rbp), %eax         # eax <--- eax - i 
	subl	$1, %eax               # eax <--- eax - 1  (thus, after above 2 steps, eax has the value length - i - 1)
	movl	%eax, -4(%rbp)         # value at eax (length- i-1) --> address rbp-4 (rbp - 4 stores the counter j, and is initialised to length-i-1)
	
	nop                            # no operation; done for code alignment
	
	movl	-28(%rbp), %eax        # string length stored at rbp-28 -->  'eax'
	movl	%eax, %edx             # value at eax (string length) --> 'edx'
	shrl	$31, %edx              # right shift by 31 bits, so edx now stores sign bit of length 
	addl	%edx, %eax             # eax <--- eax + edx 
	sarl	%eax                   # right shift eax by 1 bit (equivalent to eax = eax / 2)
	cmpl	%eax, -4(%rbp)         #  compare length/2 (stored  at eax) with counter j (stored at rbp-4)
	jl	.L18                       # if j < length/2, jump to the label L18
	
	# if j >= length/2:
	movl	-8(%rbp), %eax         #  move value of i (stored at rbp-8) to 'eax'
	cmpl	-4(%rbp), %eax         # compare value at eax (has value of i) with value at rbp-4 (has value of j)
	je	.L23                       # if i == j, jump to the label L23 (break from inner j loop)
	
	# if (i =! j), swap str[i] and str[j]
	movl	-8(%rbp), %eax         # value of i (stored at rbp-8) --> 'eax'
	movslq	%eax, %rdx             # value at eax (the counter i) --> 'rdx'
	movq	-24(%rbp), %rax        # value at address rbp-24 (the str array) --> 'rax'
	addq	%rdx, %rax             # rax <--- rax + rdx (rdx stores current i); rax now stores str[i]
	movzbl	(%rax), %eax           # value stored in rax --> 'eax'
	movb	%al, -9(%rbp)          # move value at eax(value of str[i]) to address rbp-9 (address rbp -9 corresponds to temp variable)
	
	movl	-4(%rbp), %eax         # value at rbp-4 (of counter j) -> 'eax'
	movslq	%eax, %rdx             # value at eax (counter j) -->  'rdx'
	movq	-24(%rbp), %rax        # value at address rbp-24 (the str array) --> 'rax'
	addq	%rdx, %rax             # rax <--- rax + rdx (rdx stores current j); rax now stores address to str[j]
	movl	-8(%rbp), %edx         # value at rbp-8 (of counter i) ->  'edx'
	movslq	%edx, %rcx             # value at edx (counter i) -->  'rcx'
	movq	-24(%rbp), %rdx        # value at address rbp-24 (the str array) --> 'rdx'
	addq	%rcx, %rdx             # rdx <--- rdx + rcx (rcx stores current i); rdx now stores address to str[i]
	movzbl	(%rax), %eax           # rax (stores the address to str[j]) --> 'eax'
	movb	%al, (%rdx)            # value at eax(value of str[j]) --> rdx (address rdx corresponds to str[i])
	
	movl	-4(%rbp), %eax         # value at rbp-4 (of counter j) --> 'eax'
	movslq	%eax, %rdx             # value at eax (counter j) -->  'rdx'
	movq	-24(%rbp), %rax        # value at address rbp-24 (the str array) --> 'rax'
	addq	%rax, %rdx             # rdx <--- rdx + rax (rax stores address to str); rdx now stores address to str[j]
	movzbl	-9(%rbp), %eax         # value at rbp-9 (temp variable) --> 'eax' 
	movb	%al, (%rdx)            # value at eax(the value of str[i] stored in temp) --> rdx (address rdx corresponds to str[j])
	
	jmp	.L18                       # unconditional jump to the label L18
.L23:
	nop                            # no operation, but is done for code alignment, continue with the instructions in label L18
.L18:
	addl	$1, -8(%rbp)           # increment value at rbp-8 (counter i) by 1; continue with instructions in label  15
.L15:
	movl	-28(%rbp), %eax        # value at rbp-28 -> eax (length of the input string)
	movl	%eax, %edx             # value at eax (length of the input string) -> edx
	
	shrl	$31, %edx              # edx is a 32 bit register, and right shift by 31 bits only leaves the sign bit(MSB), hence edx stores the sign bit of the length
	addl	%edx, %eax             # eax = eax + edx (length of the input string)

	sarl	%eax                   # right shift eax by 1 bit (same as dividing value in eax by 2) ; so eax stores length/2
	cmpl	%eax, -8(%rbp)         # compare length/2 (stored in eax) with counter i (stored in rbp-8)
	jl	.L20                       # if i < length/2, then jump to the label L20
	
	movl	$0, -8(%rbp)           # else set value at rbp-8 (value of counter i) to 0 again
	jmp	.L21                       # jump to the label L21
.L22:
	movl	-8(%rbp), %eax         # value at rbp-8 (value of counter i) -> eax
	movslq	%eax, %rdx             # value at eax (value of counter i) -> rdx
	movq	-24(%rbp), %rax        # value at rbp-24 (the str array) -> rax
	addq	%rdx, %rax             # rax <--- rax + rdx (rdx stores current i); rax now stores address to str[i]
	
	movl	-8(%rbp), %edx         # value at rbp-8 (value of counter i) ->  edx
	movslq	%edx, %rcx             # value at edx (value of counter i) ->  rcx
	movq	-40(%rbp), %rdx        # value at rbp-40 (the dist array) ->  rdx
	addq	%rcx, %rdx             # rdx <--- rdx + rcx (rcx stores current i); rdx now stores address to dist[i]
	movzbl	(%rax), %eax           # value at rax (address to str[i]) ->  eax
	movb	%al, (%rdx)            # move value at eax(value of str[i]) to address rdx (rdx corresponds to dist[i]) 
	                               # in prev step, we assign the value of str[i] to dist[i]
	addl	$1, -8(%rbp)           # increment value at rbp-8 (counter i) by 1; then continue with instructions in label 21
.L21:
	movl	-8(%rbp), %eax         # value at rbp-8 (value of counter i) -> move to eax
	cmpl	-28(%rbp), %eax        # compare value at rbp-28 (string length) with value at eax (of counter i)
	jl	.L22                       # if i < length, then jump to the label L22
	
	# if i >= length: 
	movl	-28(%rbp), %eax        # value at rbp-28 (string length) -> eax
	movslq	%eax, %rdx             # value at eax (string length) ->  rdx
	movq	-40(%rbp), %rax        # value at rbp-40 (the dist array) -> rax
	addq	%rdx, %rax             # rax <--- rax + rdx (rdx stores string length); rax now stores address to dist[length]
	movb	$0, (%rax)             # assign the null value ('\0) to address rax (address rax corresponds to dist[length])
	                               # prev instruction is to null terminate the dist array
	nop                            # no operation, but is done for code alignment
	
	popq	%rbp                   # pop the base pointer from the callee stack and return to the caller function
	.cfi_def_cfa 7, 8
	ret                            # return from the function reverse 
	.cfi_endproc
.LFE3:                             # end of the function reverse
	.size	reverse, .-reverse     # size of the function REVERSE (calculated similar to that for main function)
	
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
