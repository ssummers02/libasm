section	.text
global	_ft_write
extern	___error

_ft_write:
	xor	rax, rax
	mov	rax, 0x2000004
	syscall
	jc	.error
	ret

.error:
	push	rax
	call	___error
	pop	rdx
	mov	dword [rax], edx
	mov	rax, -1
	ret