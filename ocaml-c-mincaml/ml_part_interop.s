	.text
	.globl min_caml_call_caml_fib
min_caml_call_caml_fib:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%eax
	call	_call_caml_fib
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl min_caml_call_caml_add
min_caml_call_caml_add:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%eax
	call	_call_caml_add
	movl	%ebp, %esp
	popl	%ebp
	ret
