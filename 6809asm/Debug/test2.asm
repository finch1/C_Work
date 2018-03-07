	.org $0000	
top	ldaa sze	;get array size
	suba #2		;calc counter
	asra
	staa idx	;set cnt/idx
	
	staa lrg	;set largest
	adda #1		;calc right
	asla
	staa rit	;store right
	ldaa idx	;load idx
	asla		;calc left
	adda #1
	staa lft	;store left

;left child
ltch	ldab sze	;cmp lft to size
	cba			
	bgt rtch	;branch if less
	ldx #arr	;load arr ptr
	ldy #arr	;load arr ptr
	ldab $lft
	abx 
	ldab $lrg
	aby 
	ldaa 0,x	;pt to lft
	ldab 0,y	;pt to lrg
	cba 		;compare conents
	blt rtch
	ldaa $lft
	staa $lrg

;right child
rtch	ldaa rit
	ldab sze	;cmp lft to size
	cba			
	bgt rotch	;branch if less
	ldx #arr	;load arr ptr
	ldy #arr	;load arr ptr
	ldab $rit
	abx 
	ldab $lrg
	aby 
	ldaa 0,x	;pt to right
	ldab 0,y	;pt to lrg
	cba 		;compare conents
	blt rotch
	ldaa $rit
	staa $lrg

rotch ldaa lrg
	ldab idx
	cba
	bne swap
	bra top

swap	ldx #lrg
	ldy #idx
	ldaa 0,x	
	ldab 0,y
	staa 0,y
	stab 0,x	



	.org $00A0
idx .rmb 1
lrg .rmb 1
rit	.rmb 1
lft .rmb 1
sze	.byte 7
arr	.byte 3,4,5,7,2,6,3
	.end
	

