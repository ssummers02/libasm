section	.text
extern	_ft_strlen
extern	_malloc
extern	_ft_strcpy
global	_ft_strdup

_ft_strdup:
	push	rdi
	call	_ft_strlen
	mov	rdi, rax
	inc	rdi
	call	_malloc
	pop	rsi
	test	rax, rax
	jz	return
	mov	rdi, rax
	call	_ft_strcpy
	ret
return:
	ret
	
