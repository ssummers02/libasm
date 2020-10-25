section .text
global	_ft_strcpy

_ft_strcpy:
	mov	rax, rdi
.loop:
	mov	dl, byte [rsi]
	mov	byte [rdi], dl
	test	dl, dl
	jz	return
	inc	rdi
	inc	rsi
	jmp	.loop
return:
	ret
	
