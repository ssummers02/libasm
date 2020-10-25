section .text

global	_ft_strcmp

_ft_strcmp:
	xor	rax, rax
	xor	rdx, rdx
.loop:
	mov	al, byte [rdi]
	mov	dl, byte [rsi]
	sub	rax, rdx
	jnz	return
	test	dl, dl
	jz	return
	inc	rdi
	inc	rsi
	jmp	.loop
return:
	ret