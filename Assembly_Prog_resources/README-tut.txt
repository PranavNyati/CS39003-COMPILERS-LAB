=================
Lec01: Warming up
=================

1. Registration
===============

 - scoreboard: https://tc.gtisc.gatech.edu/cs6265/2016/submit/handin.py
 - piazza:     https://piazza.com/gatech/fall2016/cs6265aq

Did you get an api-key through email? The api-key is essentially your
identity for this class.

2. Environment setup
====================

 - https://tc.gtisc.gatech.edu/cs6265/2016/rules.html

3. IOLI-crackme
===============

7 binaries are provided. The goal is very simple: find a password that
each binary accepts. Before tacking this week's challenges, you will
be learned how to use GDB, how to read x86 assembly and hacker's mindset!

We highly recommend to tackle crackme binaries first (at least upto 0x05)
before jumping into the "bomblab". In bomblab, if you make a mistake
(i.e., exploding the bomb), you will get some point deducted.

In this tutorial, we will walk together to solve two binaries.

3.1. crackme0x00
----------------

    $ ./crackme0x00
    IOLI Crackme Level 0x00
    Password: 1234
    Invalid Password!

 3.1.1. Where to start?

   There are many ways to start: 1) reading the whole binary first
   (e.g., try "objdump -d crackme0x00"); 2) starting with a gdb sessionn
   (e.g., "gdb ./crackme0x00") and setting a breakpoint on a well-known
   entry (e.g., luckily main() is exposed, try "nm crackme0x00"); 3)
   run ./crackme0x00 first (waiting on the "Password" prompt) and attach
   it to gdb (e.g.,  "gdb -p $(pgrep crackme0x00)"); 4) or just running
   with gdb then press "C-c" (i.e., sending a SIGINT signal).

 3.1.2. Let's take 4)

    $ gdb ./crackme0x00
    Reading symbols from ./crackme0x00...(no debugging symbols found)...done.
    (gdb) r

    ; [r]un: run a program, please check "help run"

    Starting program: /home/vagrant/cs6265/lab01/IOLI-crackme/crackme0x00
    IOLI Crackme Level 0x00
    Password: ^C

    ; press ctrl+C (^C) to send a signal to stop the process

    Program received signal SIGINT, Interrupt.
    0xf7fd8d09 in __kernel_vsyscall ()
    (gdb) bt
    #0  0xf7fd8d09 in __kernel_vsyscall ()
    #1  0xf7ea7153 in __read_nocancel () from /usr/lib32/libc.so.6
    #2  0xf7e3a74f in __GI__IO_file_underflow () from /usr/lib32/libc.so.6
    #3  0xf7e3b89b in __GI__IO_default_uflow () from /usr/lib32/libc.so.6
    #4  0xf7e1f06f in __GI__IO_vfscanf () from /usr/lib32/libc.so.6
    #5  0xf7e2aaf5 in scanf () from /usr/lib32/libc.so.6
    #6  0x0804845b in main ()

    ; [bt]: print backtrace (e.g., stack frames). Again, don't forget
    ; to check "help bt"

    (gdb) tbreak *0x0804845b
    Temporary breakpoint 1 at 0x804845b

    ; set a (temporary) breakpoint (help b, tb, rb) to the call site (next)
    ; of the scanf(), which is potentially the most interesting part.

    (gdb) c
    Continuing.
    aaaaaaaaaaaaaaaaaaaaaaaa

    ; [c]ontinue to run the process, type "aaaaaaaaaaaaaa" (inject a random input)

    Temporary breakpoint 1, 0x0804845b in main ()

    ; ok, it hits the breakpoint, let check the context
    ; [disas]semble: dump the assembly code in the current scope

    (gdb) disas
        Dump of assembler code for function main:
        0x08048414 <+0>:     push   ebp
        0x08048415 <+1>:     mov    ebp,esp
        0x08048417 <+3>:     sub    esp,0x28
        0x0804841a <+6>:     and    esp,0xfffffff0
        0x0804841d <+9>:     mov    eax,0x0
        0x08048422 <+14>:    add    eax,0xf
        0x08048425 <+17>:    add    eax,0xf
        0x08048428 <+20>:    shr    eax,0x4
        0x0804842b <+23>:    shl    eax,0x4
        0x0804842e <+26>:    sub    esp,eax
        0x08048430 <+28>:    mov    DWORD PTR [esp],0x8048568
        0x08048437 <+35>:    call   0x8048340 <printf@plt>
        0x0804843c <+40>:    mov    DWORD PTR [esp],0x8048581
        0x08048443 <+47>:    call   0x8048340 <printf@plt>
        0x08048448 <+52>:    lea    eax,[ebp-0x18]
        0x0804844b <+55>:    mov    DWORD PTR [esp+0x4],eax
        0x0804844f <+59>:    mov    DWORD PTR [esp],0x804858c
        0x08048456 <+66>:    call   0x8048330 <scanf@plt>
     => 0x0804845b <+71>:    lea    eax,[ebp-0x18]
        0x0804845e <+74>:    mov    DWORD PTR [esp+0x4],0x804858f
        0x08048466 <+82>:    mov    DWORD PTR [esp],eax
        0x08048469 <+85>:    call   0x8048350 <strcmp@plt>
        0x0804846e <+90>:    test   eax,eax
        0x08048470 <+92>:    je     0x8048480 <main+108>
        0x08048472 <+94>:    mov    DWORD PTR [esp],0x8048596
        0x08048479 <+101>:   call   0x8048340 <printf@plt>
        0x0804847e <+106>:   jmp    0x804848c <main+120>
        0x08048480 <+108>:   mov    DWORD PTR [esp],0x80485a9
        0x08048487 <+115>:   call   0x8048340 <printf@plt>
        0x0804848c <+120>:   mov    eax,0x0
        0x08048491 <+125>:   leave
        0x08048492 <+126>:   ret
        End of assembler dump.

    ; please try reading (and understating the code)

    ; 0x08048448 <+52>:    lea    eax,[ebp-0x18]
    ; 0x0804844b <+55>:    mov    DWORD PTR [esp+0x4],eax
    ; 0x0804844f <+59>:    mov    DWORD PTR [esp],0x804858c
    ; 0x08048456 <+66>:    call   0x8048330 <scanf@plt>
    ;  -> scanf("%s", buf), by the way that's the size of buf?

    (gdb) x/1s 0x804858c
    0x804858c:      "%s"

    ; this is your input
    (gdb) x/1s $ebp-0x18
    0xffffc4d0:     'a' <repeats 24 times>

    ; please learn about the e[x]amine command ("help x"), which is
    ; one of the most versatile commands in gdb

    ; 0x0804845b <+71>:    lea    eax,[ebp-0x18]
    ; 0x0804845e <+74>:    mov    DWORD PTR [esp+0x4],0x804858f
    ; 0x08048466 <+82>:    mov    DWORD PTR [esp],eax
    ; 0x08048469 <+85>:    call   0x8048350 <strcmp@plt>
    ;  -> strcmp(buf, "250382")

    (gdb) x/1s 0x804858f
    0x804858f:      "250382"

    ; 0x0804846e <+90>:    test   eax,eax
    ; 0x08048470 <+92>:    je     0x8048480 <main+108>
    ; 0x08048472 <+94>:    mov    DWORD PTR [esp],0x8048596
    ; 0x08048479 <+101>:   call   0x8048340 <printf@plt>
    ; 0x08048480 <+108>:   mov    DWORD PTR [esp],0x80485a9
    ; 0x08048487 <+115>:   call   0x8048340 <printf@plt>

    ; if (!strcmp(buf, "250382")) {
    ;    printf("Password OK :)\n")
    ; } else {
    ;    printf("Invalid Password!\n");
    ; }

    (gdb) x/1s 0x8048596
    0x8048596:      "Invalid Password!\n"
    (gdb) x/1s 0x80485a9
    0x80485a9:      "Password OK :)\n"

So, try the password we found? Does it work?

3.2. crackme0x01
----------------

Let's go fast on this binary. Please take similar steps from
crackme0x00 and reach to this place.

    (gdb) disas
    Dump of assembler code for function main:
        0x080483e4 <+0>:     push   ebp
        0x080483e5 <+1>:     mov    ebp,esp
        0x080483e7 <+3>:     sub    esp,0x18
        0x080483ea <+6>:     and    esp,0xfffffff0
        0x080483ed <+9>:     mov    eax,0x0
        0x080483f2 <+14>:    add    eax,0xf
        0x080483f5 <+17>:    add    eax,0xf
        0x080483f8 <+20>:    shr    eax,0x4
        0x080483fb <+23>:    shl    eax,0x4
        0x080483fe <+26>:    sub    esp,eax
        0x08048400 <+28>:    mov    DWORD PTR [esp],0x8048528
        0x08048407 <+35>:    call   0x804831c <printf@plt>
        0x0804840c <+40>:    mov    DWORD PTR [esp],0x8048541
        0x08048413 <+47>:    call   0x804831c <printf@plt>
        0x08048418 <+52>:    lea    eax,[ebp-0x4]
        0x0804841b <+55>:    mov    DWORD PTR [esp+0x4],eax
        0x0804841f <+59>:    mov    DWORD PTR [esp],0x804854c
        0x08048426 <+66>:    call   0x804830c <scanf@plt>

    ; what's scanf() doing (i.e., what's the value of 0x804854c)?

     => 0x0804842b <+71>:    cmp    DWORD PTR [ebp-0x4],0x149a

    ; it our input with 0x149a!

        0x08048432 <+78>:    je     0x8048442 <main+94>
        0x08048434 <+80>:    mov    DWORD PTR [esp],0x804854f
        0x0804843b <+87>:    call   0x804831c <printf@plt>
        0x08048440 <+92>:    jmp    0x804844e <main+106>
        0x08048442 <+94>:    mov    DWORD PTR [esp],0x8048562
        0x08048449 <+101>:   call   0x804831c <printf@plt>
        0x0804844e <+106>:   mov    eax,0x0
        0x08048453 <+111>:   leave
        0x08048454 <+112>:   ret
        End of assembler dump.

So, try the password we found? Does it work? Great. Please explore all
crackme binaries and if you think you are ready, please start bomblab!

Don't forget TAs are here to help you. Feel free to ask any question!