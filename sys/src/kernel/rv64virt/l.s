.text
.global _start
_start:
	.cfi_startproc
	.cfi_undefined ra
	.option push
	.option norelax
	la gp, __global_pointer$
	.option pop
	la sp, __kernel_stack_start
	la t0, __bss_start
	la t1, __bss_end
ramZ:
	sd zero, (t0)
	addi t0, t0, 8
	bltu t0, t1, ramZ
	jal zero, main
	.cfi_endproc
	.end
