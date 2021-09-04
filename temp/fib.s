	.file	"fib.c"
	.text
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "%d\12\0"
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB13:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	andl	$-16, %esp
	subl	$16, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	call	___main
	.p2align 4,,10
L3:
	movl	$1, %esi
	xorl	%ebx, %ebx
L2:
	movl	%ebx, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	leal	(%ebx,%esi), %eax
	movl	%esi, %ebx
	cmpl	$254, %esi
	jg	L3
	movl	%eax, %esi
	jmp	L2
	.cfi_endproc
LFE13:
	.ident	"GCC: (i686-posix-dwarf-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
