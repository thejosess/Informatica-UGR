	.file	"msum.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	movq	%rsp, %rdx
	movl	$3, %esi
	movl	$2, %edi
	call	sumstore@PLT
	movl	(%rsp), %eax
	movq	8(%rsp), %rcx
	xorq	%fs:40, %rcx
	jne	.L4
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L4:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	plus
	.type	plus, @function
plus:
.LFB1:
	.cfi_startproc
	leaq	(%rdi,%rsi), %rax
	ret
	.cfi_endproc
.LFE1:
	.size	plus, .-plus
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
