	.file	"quick.c"
	.text
	.section	.rodata
.LC1:
	.string	"|%d|%5d|%-5d|%5.3d|\n"
.LC2:
	.string	"|%10.3f|%10.3e|%-10g|\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$40, -8(%rbp)
	movss	.LC0(%rip), %xmm0
	movss	%xmm0, -4(%rbp)
	movl	-8(%rbp), %esi
	movl	-8(%rbp), %ecx
	movl	-8(%rbp), %edx
	movl	-8(%rbp), %eax
	movl	%esi, %r8d
	movl	%eax, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	pxor	%xmm1, %xmm1
	cvtss2sd	-4(%rbp), %xmm1
	pxor	%xmm0, %xmm0
	cvtss2sd	-4(%rbp), %xmm0
	pxor	%xmm3, %xmm3
	cvtss2sd	-4(%rbp), %xmm3
	movq	%xmm3, %rax
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$3, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC0:
	.long	1146211697
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
