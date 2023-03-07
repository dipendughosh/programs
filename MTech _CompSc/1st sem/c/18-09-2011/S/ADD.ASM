	ifndef	??version
?debug	macro
	endm
$comm	macro	name,dist,size,count
	comm	dist name:BYTE:count*size
	endm
	else
$comm	macro	name,dist,size,count
	comm	dist name[size]:BYTE:count
	endm
	endif
	?debug	S "add.c"
	?debug	C E90C192E3F056164642E63
	?debug	C E90018521815433A5C54435C494E434C5544455C737464696F2E68
	?debug	C E90018521815433A5C54435C494E434C5544455C5F646566732E68
	?debug	C E90018521815433A5C54435C494E434C5544455C5F6E756C6C2E68
	?debug	C E90018521815433A5C54435C494E434C5544455C636F6E696F2E68
_TEXT	segment byte public 'CODE'
_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:_TEXT,ds:DGROUP
_DATA	segment word public 'DATA'
d@	label	byte
d@w	label	word
_DATA	ends
_BSS	segment word public 'BSS'
b@	label	byte
b@w	label	word
_BSS	ends
_TEXT	segment byte public 'CODE'
   ;	
   ;	int main()
   ;	
	assume	cs:_TEXT
_main	proc	near
	push	bp
	mov	bp,sp
	sub	sp,6
   ;	
   ;	{
   ;		int a,b,c;
   ;		
   ;		printf("Enter 1st number :- ");
   ;	
	mov	ax,offset DGROUP:s@
	push	ax
	call	near ptr _printf
	pop	cx
   ;	
   ;		scanf("%d",&a);
   ;	
	lea	ax,word ptr [bp-2]
	push	ax
	mov	ax,offset DGROUP:s@+21
	push	ax
	call	near ptr _scanf
	pop	cx
	pop	cx
   ;	
   ;		
   ;		printf("Enter 2nd number :- ");
   ;	
	mov	ax,offset DGROUP:s@+24
	push	ax
	call	near ptr _printf
	pop	cx
   ;	
   ;		scanf("%d",&b);
   ;	
	lea	ax,word ptr [bp-4]
	push	ax
	mov	ax,offset DGROUP:s@+45
	push	ax
	call	near ptr _scanf
	pop	cx
	pop	cx
   ;	
   ;		
   ;		printf("Processed\n%d + %d = %d",a,b,c);
   ;	
	push	word ptr [bp-6]
	push	word ptr [bp-4]
	push	word ptr [bp-2]
	mov	ax,offset DGROUP:s@+48
	push	ax
	call	near ptr _printf
	add	sp,8
   ;	
   ;		
   ;		return 0;
   ;	
	xor	ax,ax
	jmp	short @1@58
@1@58:
   ;	
   ;	}
   ;	
	mov	sp,bp
	pop	bp
	ret	
_main	endp
	?debug	C E9
_TEXT	ends
_DATA	segment word public 'DATA'
s@	label	byte
	db	'Enter 1st number :- '
	db	0
	db	'%d'
	db	0
	db	'Enter 2nd number :- '
	db	0
	db	'%d'
	db	0
	db	'Processed'
	db	10
	db	'%d + %d = %d'
	db	0
_DATA	ends
_TEXT	segment byte public 'CODE'
_TEXT	ends
	public	_main
	extrn	_scanf:near
	extrn	_printf:near
_s@	equ	s@
	end
