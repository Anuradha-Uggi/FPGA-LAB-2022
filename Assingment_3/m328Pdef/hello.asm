

.include "m328Pdef.inc"

Start:
	ldi r17, 0b11000011 ; identifying input pins 10,11,12,13
	out DDRB,r17		; declaring pins as input
	ldi r17, 0b11111111 ;
	out PORTB,r17		; activating internal pullup for pins 10,11,12,13  
	in r17,PINB
	
	ldi r20,0b00000010
	rcall loopr
	
	ldi r21,0b00000001
	and r21,r17 ;s
	lsr r17
	ldi r22,0b00000001
	and r22,r17 ;r
	lsr r17
	ldi r23,0b00000001
	and r23,r17 ;q
	lsr r17
	ldi r24,0b00000001
	and r24,r17 ;p

	ldi r25,0b00000001
	ldi r26,0b00000001

	eor r26,r24     ;p'
	eor r25,r23     ;q'
	and r26,r25    	;p'q'
	ldi r25,0b00000001
	eor r25,r21     ;s'
	and r25,r22     ;rs'
	or r26,r25      ;p'q'+rs'
	ldi r25,0b00000001
	eor r25,r24     ;p'
	and r25,r21     ;p's
	ldi r17,0b00000001
        and r17,r23     ;q
        and r17,r22     ;qr
	or r17,r25      ;p's+qr

	or r26,r17      ;p'q'+rs'+p's+qr=X

	ldi r25,0b00000001
	eor r25,r24     ;p'
        ldi r27,0b00000001
	eor r27,r23     ;q'
	and r25,r27     ;p'q'
	ldi r27,0b00000001
	eor r25,r27     ;(p'q')'
	ldi r27,0b00000001
	eor r27,r21     ;s'
	and r27,r24     ;ps'
	ldi r28,0b00000001
	eor r28,r27     ;(ps')'
	and r25,r28     ;(p'q')'(ps')'

	ldi r27,0b00000001
	eor r27,r24     ;p'
	and r27,r21     ;p's
	ldi r28,0b00000001
	eor r27,r28     ;(p's)'
	and r28,r23     ;q
	and r28,r22     ;qr
        ldi r29,0b00000001
	eor r28,r29     ;(qr)'

	and r27,r28     ;(p's)'(qr)'
	and r25,r27     ;(p'q')(ps')'(p's)'(qr)'=a
	ldi r28,0b00000001
	eor r25,r28     ;a'=Y
        eor r26,r25     ;XY
	ldi r24,0b00000001
	eor r26,r24
	rcall loopl

	ldi r16, 0b00111100 ;identifying output pins 2,3,4,5
	out DDRD,r16		;declaring pins as output
	out PORTD,r26		;writing output to pins 2,3,4,5
	

	rjmp Start

loopr:	lsr r17
	dec r20
	brne loopr
	ret

loopl:	lsl r26
	dec r20
	brne loopl
	ret  
