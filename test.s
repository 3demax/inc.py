	.file	"test.c"
	.text
	.p2align 4
	.globl	scheme_entry
	.type	scheme_entry, @function
scheme_entry:
.LFB0:
	.cfi_startproc
	movl	$42, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	scheme_entry, .-scheme_entry
	.ident	"GCC: (GNU) 10.1.0"
	.section	.note.GNU-stack,"",@progbits
