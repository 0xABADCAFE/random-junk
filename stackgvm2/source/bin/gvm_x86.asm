	.file	"gvm_run.cpp"
	.section	.rodata.str1.4,"aMS",@progbits,1
	.align 4
.LC0:
	.string	"\nExecuted: %d instructions total.\n"
	.section	.text.unlikely,"ax",@progbits
	.align 2
.LCOLDB6:
	.text
.LHOTB6:
	.align 2
	.p2align 4,,15
	.globl	_ZN3GVM11Interpreter3runEv
	.type	_ZN3GVM11Interpreter3runEv, @function
_ZN3GVM11Interpreter3runEv:
.LFB149:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$-1, %esi
	subl	$28, %esp
	.cfi_def_cfa_offset 48
	movl	_ZN3GVM11Interpreter14programCounterE, %ebx
	.p2align 4,,10
	.p2align 3
.L2:
	addl	$1, %esi
	cmpb	$-21, (%ebx)
	ja	.L327
.L390:
	movzbl	(%ebx), %eax
	jmp	*.L5(,%eax,4)
	.section	.rodata
	.align 4
	.align 4
.L5:
	.long	.L327
	.long	.L4
	.long	.L6
	.long	.L7
	.long	.L8
	.long	.L9
	.long	.L10
	.long	.L11
	.long	.L12
	.long	.L13
	.long	.L14
	.long	.L15
	.long	.L16
	.long	.L17
	.long	.L18
	.long	.L19
	.long	.L20
	.long	.L21
	.long	.L22
	.long	.L23
	.long	.L24
	.long	.L25
	.long	.L26
	.long	.L27
	.long	.L28
	.long	.L29
	.long	.L30
	.long	.L31
	.long	.L32
	.long	.L33
	.long	.L34
	.long	.L35
	.long	.L36
	.long	.L37
	.long	.L38
	.long	.L39
	.long	.L40
	.long	.L41
	.long	.L42
	.long	.L43
	.long	.L44
	.long	.L45
	.long	.L46
	.long	.L47
	.long	.L48
	.long	.L49
	.long	.L50
	.long	.L51
	.long	.L52
	.long	.L53
	.long	.L54
	.long	.L55
	.long	.L56
	.long	.L57
	.long	.L58
	.long	.L59
	.long	.L60
	.long	.L61
	.long	.L62
	.long	.L63
	.long	.L64
	.long	.L65
	.long	.L66
	.long	.L67
	.long	.L68
	.long	.L69
	.long	.L70
	.long	.L71
	.long	.L72
	.long	.L73
	.long	.L74
	.long	.L75
	.long	.L76
	.long	.L77
	.long	.L78
	.long	.L79
	.long	.L80
	.long	.L81
	.long	.L82
	.long	.L83
	.long	.L84
	.long	.L85
	.long	.L86
	.long	.L87
	.long	.L88
	.long	.L89
	.long	.L90
	.long	.L91
	.long	.L92
	.long	.L93
	.long	.L94
	.long	.L95
	.long	.L96
	.long	.L97
	.long	.L98
	.long	.L99
	.long	.L100
	.long	.L101
	.long	.L102
	.long	.L103
	.long	.L104
	.long	.L105
	.long	.L106
	.long	.L107
	.long	.L108
	.long	.L109
	.long	.L110
	.long	.L111
	.long	.L112
	.long	.L113
	.long	.L114
	.long	.L115
	.long	.L116
	.long	.L117
	.long	.L118
	.long	.L119
	.long	.L120
	.long	.L121
	.long	.L122
	.long	.L123
	.long	.L124
	.long	.L125
	.long	.L126
	.long	.L127
	.long	.L128
	.long	.L129
	.long	.L130
	.long	.L131
	.long	.L132
	.long	.L133
	.long	.L134
	.long	.L135
	.long	.L136
	.long	.L137
	.long	.L138
	.long	.L139
	.long	.L140
	.long	.L141
	.long	.L142
	.long	.L143
	.long	.L144
	.long	.L145
	.long	.L146
	.long	.L147
	.long	.L148
	.long	.L149
	.long	.L150
	.long	.L151
	.long	.L152
	.long	.L153
	.long	.L154
	.long	.L155
	.long	.L156
	.long	.L157
	.long	.L158
	.long	.L159
	.long	.L160
	.long	.L161
	.long	.L162
	.long	.L163
	.long	.L164
	.long	.L165
	.long	.L166
	.long	.L167
	.long	.L168
	.long	.L169
	.long	.L170
	.long	.L171
	.long	.L172
	.long	.L173
	.long	.L174
	.long	.L175
	.long	.L176
	.long	.L177
	.long	.L178
	.long	.L179
	.long	.L180
	.long	.L181
	.long	.L182
	.long	.L183
	.long	.L184
	.long	.L185
	.long	.L186
	.long	.L187
	.long	.L188
	.long	.L189
	.long	.L190
	.long	.L191
	.long	.L192
	.long	.L193
	.long	.L194
	.long	.L195
	.long	.L196
	.long	.L197
	.long	.L198
	.long	.L199
	.long	.L200
	.long	.L201
	.long	.L202
	.long	.L203
	.long	.L204
	.long	.L205
	.long	.L206
	.long	.L207
	.long	.L208
	.long	.L209
	.long	.L210
	.long	.L211
	.long	.L212
	.long	.L213
	.long	.L214
	.long	.L215
	.long	.L216
	.long	.L217
	.long	.L218
	.long	.L219
	.long	.L220
	.long	.L221
	.long	.L222
	.long	.L223
	.long	.L224
	.long	.L225
	.long	.L226
	.long	.L227
	.long	.L228
	.long	.L229
	.long	.L230
	.long	.L231
	.long	.L232
	.long	.L233
	.long	.L234
	.long	.L235
	.long	.L236
	.long	.L237
	.long	.L238
	.long	.L239
	.text
.L238:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	addl	$1, %esi
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	leal	(%edx,%ecx,4), %edx
	movzbl	-2(%ebx), %ecx
	vmovss	(%eax,%ecx,4), %xmm0
	movsbl	-1(%ebx), %ecx
	vmulss	(%edx), %xmm0, %xmm1
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%ecx,4), %eax
	vmovss	%xmm1, (%eax)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vmulss	4(%edx), %xmm0, %xmm1
	vmovss	%xmm1, 4(%eax)
	vmulss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	cmpb	$-21, (%ebx)
	jbe	.L390
.L327:
	movl	$2, %eax
.L387:
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
.L237:
	.cfi_restore_state
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	movsbl	1(%ebx), %edx
	addl	$4, %ebx
	movzbl	-2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	4(%ecx), %ecx
	leal	(%eax,%edx,4), %edx
	vmovss	(%ecx,%edi,4), %xmm0
	movsbl	-1(%ebx), %ecx
	vmulss	(%edx), %xmm0, %xmm1
	leal	(%eax,%ecx,4), %eax
	vmovss	%xmm1, (%eax)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vmulss	4(%edx), %xmm0, %xmm1
	vmovss	%xmm1, 4(%eax)
	vmulss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L236:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	leal	(%edx,%ecx,4), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	vmovss	(%ecx,%edi,4), %xmm0
	movzbl	-1(%ebx), %ecx
	vmulss	(%edx), %xmm0, %xmm1
	leal	(%eax,%ecx,4), %eax
	vmovss	%xmm1, (%eax)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vmulss	4(%edx), %xmm0, %xmm1
	vmovss	%xmm1, 4(%eax)
	vmulss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L235:
	movsbl	2(%ebx), %ecx
	movsbl	1(%ebx), %edx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	vmovss	(%eax,%ecx,4), %xmm0
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	-1(%ebx), %ecx
	vmulss	(%edx), %xmm0, %xmm1
	movl	4(%eax), %eax
	leal	(%eax,%ecx,4), %eax
	vmovss	%xmm1, (%eax)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vmulss	4(%edx), %xmm0, %xmm1
	vmovss	%xmm1, 4(%eax)
	vmulss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L234:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	addl	$4, %ebx
	movsbl	-2(%ebx), %ecx
	movl	4(%eax), %eax
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	vmovss	(%eax,%ecx,4), %xmm0
	movsbl	-1(%ebx), %ecx
	vmulss	(%edx), %xmm0, %xmm1
	leal	(%eax,%ecx,4), %eax
	vmovss	%xmm1, (%eax)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vmulss	4(%edx), %xmm0, %xmm1
	vmovss	%xmm1, 4(%eax)
	vmulss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L233:
	movsbl	1(%ebx), %edx
	movsbl	2(%ebx), %ecx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%edx,4), %edx
	vmovss	(%eax,%ecx,4), %xmm0
	movsbl	-1(%ebx), %ecx
	vmulss	(%edx), %xmm0, %xmm1
	leal	(%eax,%ecx,4), %eax
	vmovss	%xmm1, (%eax)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vmulss	4(%edx), %xmm0, %xmm1
	vmovss	%xmm1, 4(%eax)
	vmulss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L232:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	movzbl	-2(%ebx), %edi
	leal	(%eax,%edx,4), %edx
	movl	4(%ecx), %eax
	movl	8(%ecx), %ecx
	vmovss	8(%edx), %xmm0
	leal	(%eax,%edi,4), %eax
	movzbl	-1(%ebx), %edi
	vmovss	4(%edx), %xmm7
	vmulss	4(%eax), %xmm0, %xmm0
	leal	(%ecx,%edi,4), %ecx
	vfmsub231ss	8(%eax), %xmm7, %xmm0
	vmovss	%xmm0, (%ecx)
	vmovss	(%edx), %xmm0
	vmulss	8(%eax), %xmm0, %xmm0
	vmovss	8(%edx), %xmm4
	vfmsub231ss	(%eax), %xmm4, %xmm0
	vmovss	%xmm0, 4(%ecx)
	vmovss	4(%edx), %xmm0
	vmulss	(%eax), %xmm0, %xmm0
	vmovss	(%edx), %xmm5
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vfmsub231ss	4(%eax), %xmm5, %xmm0
	vmovss	%xmm0, 8(%ecx)
	jmp	.L2
.L231:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movsbl	-1(%ebx), %edi
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	leal	(%edx,%ecx,4), %edx
	movzbl	-2(%ebx), %ecx
	vmovss	8(%edx), %xmm0
	vmovss	4(%edx), %xmm4
	leal	(%eax,%ecx,4), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	vmulss	4(%eax), %xmm0, %xmm0
	leal	(%ecx,%edi,4), %ecx
	vfmsub231ss	8(%eax), %xmm4, %xmm0
	vmovss	%xmm0, (%ecx)
	vmovss	(%edx), %xmm0
	vmulss	8(%eax), %xmm0, %xmm0
	vmovss	8(%edx), %xmm5
	vfmsub231ss	(%eax), %xmm5, %xmm0
	vmovss	%xmm0, 4(%ecx)
	vmovss	4(%edx), %xmm0
	vmulss	(%eax), %xmm0, %xmm0
	vmovss	(%edx), %xmm6
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vfmsub231ss	4(%eax), %xmm6, %xmm0
	vmovss	%xmm0, 8(%ecx)
	jmp	.L2
.L230:
	movsbl	1(%ebx), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	addl	$4, %ebx
	movzbl	-2(%ebx), %edi
	leal	(%ecx,%eax,4), %edx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	vmovss	8(%edx), %xmm0
	movl	4(%eax), %eax
	vmovss	4(%edx), %xmm5
	leal	(%eax,%edi,4), %eax
	movsbl	-1(%ebx), %edi
	vmulss	4(%eax), %xmm0, %xmm0
	leal	(%ecx,%edi,4), %ecx
	vfmsub231ss	8(%eax), %xmm5, %xmm0
	vmovss	%xmm0, (%ecx)
	vmovss	(%edx), %xmm0
	vmulss	8(%eax), %xmm0, %xmm0
	vmovss	8(%edx), %xmm6
	vfmsub231ss	(%eax), %xmm6, %xmm0
	vmovss	%xmm0, 4(%ecx)
	vmovss	4(%edx), %xmm0
	vmulss	(%eax), %xmm0, %xmm0
	vmovss	(%edx), %xmm7
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vfmsub231ss	4(%eax), %xmm7, %xmm0
	vmovss	%xmm0, 8(%ecx)
	jmp	.L2
.L229:
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	movzbl	1(%ebx), %edx
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
	movl	4(%ecx), %eax
	movl	8(%ecx), %ecx
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	vmovss	8(%edx), %xmm0
	leal	(%eax,%edi,4), %eax
	movzbl	-1(%ebx), %edi
	vmovss	4(%edx), %xmm6
	vmulss	4(%eax), %xmm0, %xmm0
	leal	(%ecx,%edi,4), %ecx
	vfmsub231ss	8(%eax), %xmm6, %xmm0
	vmovss	%xmm0, (%ecx)
	vmovss	(%edx), %xmm0
	vmulss	8(%eax), %xmm0, %xmm0
	vmovss	8(%edx), %xmm7
	vfmsub231ss	(%eax), %xmm7, %xmm0
	vmovss	%xmm0, 4(%ecx)
	vmovss	4(%edx), %xmm0
	vmulss	(%eax), %xmm0, %xmm0
	vmovss	(%edx), %xmm4
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vfmsub231ss	4(%eax), %xmm4, %xmm0
	vmovss	%xmm0, 8(%ecx)
	jmp	.L2
.L228:
	movsbl	1(%ebx), %edx
	movsbl	2(%ebx), %ecx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movzbl	-1(%ebx), %edi
	leal	(%eax,%edx,4), %edx
	leal	(%eax,%ecx,4), %eax
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	vmovss	8(%edx), %xmm0
	vmulss	4(%eax), %xmm0, %xmm0
	movl	4(%ecx), %ecx
	vmovss	4(%edx), %xmm7
	leal	(%ecx,%edi,4), %ecx
	vfmsub231ss	8(%eax), %xmm7, %xmm0
	vmovss	%xmm0, (%ecx)
	vmovss	(%edx), %xmm0
	vmulss	8(%eax), %xmm0, %xmm0
	vmovss	8(%edx), %xmm4
	vfmsub231ss	(%eax), %xmm4, %xmm0
	vmovss	%xmm0, 4(%ecx)
	vmovss	4(%edx), %xmm0
	vmulss	(%eax), %xmm0, %xmm0
	vmovss	(%edx), %xmm5
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vfmsub231ss	4(%eax), %xmm5, %xmm0
	vmovss	%xmm0, 8(%ecx)
	jmp	.L2
.L227:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movsbl	-1(%ebx), %edi
	movl	4(%eax), %eax
	leal	(%eax,%edx,4), %edx
	movsbl	-2(%ebx), %eax
	vmovss	8(%edx), %xmm0
	vmovss	4(%edx), %xmm4
	leal	(%ecx,%eax,4), %eax
	leal	(%ecx,%edi,4), %ecx
	vmulss	4(%eax), %xmm0, %xmm0
	vfmsub231ss	8(%eax), %xmm4, %xmm0
	vmovss	%xmm0, (%ecx)
	vmovss	(%edx), %xmm0
	vmulss	8(%eax), %xmm0, %xmm0
	vmovss	8(%edx), %xmm5
	vfmsub231ss	(%eax), %xmm5, %xmm0
	vmovss	%xmm0, 4(%ecx)
	vmovss	4(%edx), %xmm0
	vmulss	(%eax), %xmm0, %xmm0
	vmovss	(%edx), %xmm6
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vfmsub231ss	4(%eax), %xmm6, %xmm0
	vmovss	%xmm0, 8(%ecx)
	jmp	.L2
.L226:
	movsbl	1(%ebx), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	addl	$4, %ebx
	movsbl	-1(%ebx), %edi
	leal	(%ecx,%eax,4), %edx
	movsbl	-2(%ebx), %eax
	vmovss	8(%edx), %xmm0
	vmovss	4(%edx), %xmm5
	leal	(%ecx,%eax,4), %eax
	leal	(%ecx,%edi,4), %ecx
	vmulss	4(%eax), %xmm0, %xmm0
	vfmsub231ss	8(%eax), %xmm5, %xmm0
	vmovss	%xmm0, (%ecx)
	vmovss	(%edx), %xmm0
	vmulss	8(%eax), %xmm0, %xmm0
	vmovss	8(%edx), %xmm6
	vfmsub231ss	(%eax), %xmm6, %xmm0
	vmovss	%xmm0, 4(%ecx)
	vmovss	4(%edx), %xmm0
	vmulss	(%eax), %xmm0, %xmm0
	vmovss	(%edx), %xmm7
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vfmsub231ss	4(%eax), %xmm7, %xmm0
	vmovss	%xmm0, 8(%ecx)
	jmp	.L2
.L225:
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	movzbl	1(%ebx), %edx
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
	movl	4(%ecx), %eax
	movl	8(%ecx), %ecx
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	vmovss	4(%edx), %xmm0
	leal	(%eax,%edi,4), %eax
	movzbl	-1(%ebx), %edi
	vmovss	(%edx), %xmm7
	vmulss	4(%eax), %xmm0, %xmm0
	vmovss	8(%edx), %xmm4
	vfmadd231ss	(%eax), %xmm7, %xmm0
	vfmadd231ss	8(%eax), %xmm4, %xmm0
	vmovss	%xmm0, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L224:
	movsbl	1(%ebx), %edx
	movsbl	2(%ebx), %ecx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movzbl	-1(%ebx), %edi
	leal	(%eax,%edx,4), %edx
	leal	(%eax,%ecx,4), %eax
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	vmovss	4(%edx), %xmm0
	vmulss	4(%eax), %xmm0, %xmm0
	movl	4(%ecx), %ecx
	vmovss	(%edx), %xmm5
	vmovss	8(%edx), %xmm6
	vfmadd231ss	(%eax), %xmm5, %xmm0
	vfmadd231ss	8(%eax), %xmm6, %xmm0
	vmovss	%xmm0, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L223:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movsbl	-1(%ebx), %edi
	movl	4(%eax), %eax
	leal	(%eax,%edx,4), %edx
	movsbl	-2(%ebx), %eax
	vmovss	4(%edx), %xmm0
	vmovss	(%edx), %xmm7
	leal	(%ecx,%eax,4), %eax
	vmovss	8(%edx), %xmm4
	vmulss	4(%eax), %xmm0, %xmm0
	vfmadd231ss	(%eax), %xmm7, %xmm0
	vfmadd231ss	8(%eax), %xmm4, %xmm0
	vmovss	%xmm0, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L222:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	addl	$4, %ebx
	movsbl	-1(%ebx), %edi
	leal	(%eax,%edx,4), %ecx
	movsbl	-2(%ebx), %edx
	vmovss	4(%ecx), %xmm0
	vmovss	(%ecx), %xmm5
	leal	(%eax,%edx,4), %edx
	vmovss	8(%ecx), %xmm6
	vmulss	4(%edx), %xmm0, %xmm0
	vfmadd231ss	(%edx), %xmm5, %xmm0
	vfmadd231ss	8(%edx), %xmm6, %xmm0
	vmovss	%xmm0, (%eax,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L221:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	addl	$4, %ebx
	movzbl	-2(%ebx), %edi
	leal	(%eax,%edx,4), %ecx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	vmovss	(%ecx), %xmm0
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	leal	(%edx,%edi,4), %edx
	movzbl	-1(%ebx), %edi
	vsubss	(%edx), %xmm0, %xmm0
	leal	(%eax,%edi,4), %eax
	vmovss	%xmm0, (%eax)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vmovss	4(%ecx), %xmm0
	vsubss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%ecx), %xmm0
	vsubss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L220:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movsbl	-1(%ebx), %edi
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	leal	(%edx,%ecx,4), %ecx
	movzbl	-2(%ebx), %edx
	vmovss	(%ecx), %xmm0
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	vsubss	(%edx), %xmm0, %xmm0
	leal	(%eax,%edi,4), %eax
	vmovss	%xmm0, (%eax)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vmovss	4(%ecx), %xmm0
	vsubss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%ecx), %xmm0
	vsubss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L219:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	2(%ebx), %edx
	addl	$4, %ebx
	movsbl	-3(%ebx), %ecx
	movsbl	-1(%ebx), %edi
	movl	4(%eax), %eax
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%ecx,4), %ecx
	leal	(%eax,%edi,4), %eax
	vmovss	(%ecx), %xmm0
	vsubss	(%edx), %xmm0, %xmm0
	vmovss	%xmm0, (%eax)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vmovss	4(%ecx), %xmm0
	vsubss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%ecx), %xmm0
	vsubss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L218:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	leal	(%edx,%ecx,4), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	vmovss	(%ecx), %xmm0
	leal	(%edx,%edi,4), %edx
	movzbl	-1(%ebx), %edi
	vsubss	(%edx), %xmm0, %xmm0
	leal	(%eax,%edi,4), %eax
	vmovss	%xmm0, (%eax)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vmovss	4(%ecx), %xmm0
	vsubss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%ecx), %xmm0
	vsubss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L217:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	addl	$4, %ebx
	movzbl	-1(%ebx), %edi
	leal	(%eax,%edx,4), %ecx
	movsbl	-2(%ebx), %edx
	vmovss	(%ecx), %xmm0
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	vsubss	(%edx), %xmm0, %xmm0
	movl	4(%eax), %eax
	leal	(%eax,%edi,4), %eax
	vmovss	%xmm0, (%eax)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vmovss	4(%ecx), %xmm0
	vsubss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%ecx), %xmm0
	vsubss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L216:
	movsbl	3(%ebx), %ecx
	movsbl	2(%ebx), %edx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movzbl	-3(%ebx), %edi
	leal	(%eax,%edx,4), %edx
	leal	(%eax,%ecx,4), %eax
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	movl	4(%ecx), %ecx
	leal	(%ecx,%edi,4), %ecx
	vmovss	(%ecx), %xmm0
	vsubss	(%edx), %xmm0, %xmm0
	vmovss	%xmm0, (%eax)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vmovss	4(%ecx), %xmm0
	vsubss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%ecx), %xmm0
	vsubss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L215:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	addl	$4, %ebx
	movsbl	-1(%ebx), %edi
	leal	(%eax,%edx,4), %ecx
	movsbl	-2(%ebx), %edx
	vmovss	(%ecx), %xmm0
	leal	(%eax,%edx,4), %edx
	leal	(%eax,%edi,4), %eax
	vsubss	(%edx), %xmm0, %xmm0
	vmovss	%xmm0, (%eax)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vmovss	4(%ecx), %xmm0
	vsubss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%ecx), %xmm0
	vsubss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L214:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	leal	(%edx,%ecx,4), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	vmovss	(%ecx), %xmm0
	leal	(%edx,%edi,4), %edx
	movzbl	-1(%ebx), %edi
	vaddss	(%edx), %xmm0, %xmm0
	leal	(%eax,%edi,4), %eax
	vmovss	%xmm0, (%eax)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vmovss	4(%ecx), %xmm0
	vaddss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%ecx), %xmm0
	vaddss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L213:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	addl	$4, %ebx
	movzbl	-1(%ebx), %edi
	leal	(%eax,%edx,4), %ecx
	movsbl	-2(%ebx), %edx
	vmovss	(%ecx), %xmm0
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	vaddss	(%edx), %xmm0, %xmm0
	movl	4(%eax), %eax
	leal	(%eax,%edi,4), %eax
	vmovss	%xmm0, (%eax)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vmovss	4(%ecx), %xmm0
	vaddss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%ecx), %xmm0
	vaddss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L212:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	addl	$4, %ebx
	movsbl	-1(%ebx), %edi
	movl	4(%eax), %eax
	leal	(%eax,%edx,4), %ecx
	movsbl	-2(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	vmovss	(%ecx), %xmm0
	leal	(%eax,%edx,4), %edx
	leal	(%eax,%edi,4), %eax
	vaddss	(%edx), %xmm0, %xmm0
	vmovss	%xmm0, (%eax)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vmovss	4(%ecx), %xmm0
	vaddss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%ecx), %xmm0
	vaddss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L211:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	addl	$4, %ebx
	movsbl	-1(%ebx), %edi
	leal	(%eax,%edx,4), %ecx
	movsbl	-2(%ebx), %edx
	vmovss	(%ecx), %xmm0
	leal	(%eax,%edx,4), %edx
	leal	(%eax,%edi,4), %eax
	vaddss	(%edx), %xmm0, %xmm0
	vmovss	%xmm0, (%eax)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vmovss	4(%ecx), %xmm0
	vaddss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%ecx), %xmm0
	vaddss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L210:
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	movzbl	1(%ebx), %ecx
	movl	4(%edx), %eax
	movl	8(%edx), %edx
	leal	(%eax,%ecx,4), %eax
	movzbl	2(%ebx), %ecx
	vmovss	4(%eax), %xmm2
	vmulss	%xmm2, %xmm2, %xmm2
	vmovss	(%eax), %xmm1
	vmovss	8(%eax), %xmm0
	leal	(%edx,%ecx,4), %ebx
	vfmadd132ss	%xmm1, %xmm2, %xmm1
	vfmadd132ss	%xmm0, %xmm1, %xmm0
	vsqrtss	%xmm0, %xmm1, %xmm1
	vucomiss	%xmm1, %xmm1
	jp	.L391
.L325:
	vmovss	%xmm1, (%ebx)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	3(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L209:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movzbl	2(%ebx), %ecx
	leal	(%eax,%edx,4), %eax
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	vmovss	4(%eax), %xmm2
	vmulss	%xmm2, %xmm2, %xmm2
	vmovss	(%eax), %xmm1
	vmovss	8(%eax), %xmm0
	movl	4(%edx), %edx
	vfmadd132ss	%xmm1, %xmm2, %xmm1
	vfmadd132ss	%xmm0, %xmm1, %xmm0
	vsqrtss	%xmm0, %xmm1, %xmm1
	vucomiss	%xmm1, %xmm1
	leal	(%edx,%ecx,4), %ebx
	jp	.L392
.L323:
	vmovss	%xmm1, (%ebx)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	3(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L208:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	movsbl	2(%ebx), %ecx
	movl	4(%eax), %eax
	leal	(%eax,%edx,4), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	vmovss	4(%eax), %xmm2
	vmulss	%xmm2, %xmm2, %xmm2
	vmovss	(%eax), %xmm1
	vmovss	8(%eax), %xmm0
	leal	(%edx,%ecx,4), %ebx
	vfmadd132ss	%xmm1, %xmm2, %xmm1
	vfmadd132ss	%xmm0, %xmm1, %xmm0
	vsqrtss	%xmm0, %xmm1, %xmm1
	vucomiss	%xmm1, %xmm1
	jp	.L393
.L321:
	vmovss	%xmm1, (%ebx)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	3(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L207:
	movsbl	1(%ebx), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movsbl	2(%ebx), %ecx
	leal	(%edx,%eax,4), %eax
	leal	(%edx,%ecx,4), %ebx
	vmovss	4(%eax), %xmm2
	vmulss	%xmm2, %xmm2, %xmm2
	vmovss	(%eax), %xmm1
	vmovss	8(%eax), %xmm0
	vfmadd132ss	%xmm1, %xmm2, %xmm1
	vfmadd132ss	%xmm0, %xmm1, %xmm0
	vsqrtss	%xmm0, %xmm1, %xmm1
	vucomiss	%xmm1, %xmm1
	jp	.L394
.L319:
	vmovss	%xmm1, (%ebx)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	3(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L206:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	leal	(%edx,%ecx,4), %edi
	movzbl	2(%ebx), %edx
	vmovss	4(%edi), %xmm0
	vmulss	%xmm0, %xmm0, %xmm0
	vmovss	(%edi), %xmm1
	vmovss	8(%edi), %xmm2
	leal	(%eax,%edx,4), %ebx
	vfmadd231ss	%xmm1, %xmm1, %xmm0
	vfmadd132ss	%xmm2, %xmm0, %xmm2
	vsqrtss	%xmm2, %xmm3, %xmm3
	vucomiss	%xmm3, %xmm3
	jp	.L395
.L317:
	vmovss	.LC2, %xmm0
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	vdivss	%xmm3, %xmm0, %xmm0
	vmulss	%xmm0, %xmm1, %xmm1
	vmovss	%xmm1, (%ebx)
	vmulss	4(%edi), %xmm0, %xmm1
	vmovss	%xmm1, 4(%ebx)
	vmulss	8(%edi), %xmm0, %xmm0
	vmovss	%xmm0, 8(%ebx)
	leal	3(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L205:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%edx,4), %edi
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	2(%ebx), %edx
	vmovss	4(%edi), %xmm0
	vmulss	%xmm0, %xmm0, %xmm0
	vmovss	(%edi), %xmm1
	vmovss	8(%edi), %xmm2
	movl	4(%eax), %eax
	vfmadd231ss	%xmm1, %xmm1, %xmm0
	vfmadd132ss	%xmm2, %xmm0, %xmm2
	vsqrtss	%xmm2, %xmm3, %xmm3
	vucomiss	%xmm3, %xmm3
	leal	(%eax,%edx,4), %ebx
	jp	.L396
.L315:
	vmovss	.LC2, %xmm0
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	vdivss	%xmm3, %xmm0, %xmm0
	vmulss	%xmm0, %xmm1, %xmm1
	vmovss	%xmm1, (%ebx)
	vmulss	4(%edi), %xmm0, %xmm1
	vmovss	%xmm1, 4(%ebx)
	vmulss	8(%edi), %xmm0, %xmm0
	vmovss	%xmm0, 8(%ebx)
	leal	3(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L204:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	movl	4(%eax), %eax
	leal	(%eax,%edx,4), %edi
	movsbl	2(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	vmovss	4(%edi), %xmm0
	vmulss	%xmm0, %xmm0, %xmm0
	vmovss	(%edi), %xmm1
	vmovss	8(%edi), %xmm2
	leal	(%eax,%edx,4), %ebx
	vfmadd231ss	%xmm1, %xmm1, %xmm0
	vfmadd132ss	%xmm2, %xmm0, %xmm2
	vsqrtss	%xmm2, %xmm3, %xmm3
	vucomiss	%xmm3, %xmm3
	jp	.L397
.L313:
	vmovss	.LC2, %xmm0
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	vdivss	%xmm3, %xmm0, %xmm0
	vmulss	%xmm0, %xmm1, %xmm1
	vmovss	%xmm1, (%ebx)
	vmulss	4(%edi), %xmm0, %xmm1
	vmovss	%xmm1, 4(%ebx)
	vmulss	8(%edi), %xmm0, %xmm0
	vmovss	%xmm0, 8(%ebx)
	leal	3(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L203:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%edx,4), %edi
	movsbl	2(%ebx), %edx
	vmovss	4(%edi), %xmm0
	vmulss	%xmm0, %xmm0, %xmm0
	vmovss	(%edi), %xmm1
	vmovss	8(%edi), %xmm2
	leal	(%eax,%edx,4), %ebx
	vfmadd231ss	%xmm1, %xmm1, %xmm0
	vfmadd132ss	%xmm2, %xmm0, %xmm2
	vsqrtss	%xmm2, %xmm3, %xmm3
	vucomiss	%xmm3, %xmm3
	jp	.L398
.L311:
	vmovss	.LC2, %xmm0
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	vdivss	%xmm3, %xmm0, %xmm0
	vmulss	%xmm0, %xmm1, %xmm1
	vmovss	%xmm1, (%ebx)
	vmulss	4(%edi), %xmm0, %xmm1
	vmovss	%xmm1, 4(%ebx)
	vmulss	8(%edi), %xmm0, %xmm0
	vmovss	%xmm0, 8(%ebx)
	leal	3(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L202:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	addl	$3, %ebx
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	leal	(%edx,%ecx,4), %edx
	movzbl	-1(%ebx), %ecx
	vmovss	(%edx), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	leal	(%eax,%ecx,4), %eax
	vmovss	%xmm0, (%eax)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vmovss	4(%edx), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%edx), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L201:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	addl	$3, %ebx
	movzbl	-1(%ebx), %ecx
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	vmovss	(%edx), %xmm0
	movl	4(%eax), %eax
	vxorps	.LC3, %xmm0, %xmm0
	leal	(%eax,%ecx,4), %eax
	vmovss	%xmm0, (%eax)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vmovss	4(%edx), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%edx), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L200:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	addl	$3, %ebx
	movsbl	-1(%ebx), %ecx
	movl	4(%eax), %eax
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	vmovss	(%edx), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	leal	(%eax,%ecx,4), %eax
	vmovss	%xmm0, (%eax)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vmovss	4(%edx), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%edx), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L199:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	addl	$3, %ebx
	movsbl	-1(%ebx), %ecx
	leal	(%eax,%edx,4), %edx
	leal	(%eax,%ecx,4), %eax
	vmovss	(%edx), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, (%eax)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vmovss	4(%edx), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%edx), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L198:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	addl	$3, %ebx
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	leal	(%edx,%ecx,4), %edx
	movzbl	-1(%ebx), %ecx
	leal	(%eax,%ecx,4), %eax
	movl	(%edx), %ecx
	movl	%ecx, (%eax)
	movl	4(%edx), %ecx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	movl	%ecx, 4(%eax)
	movl	8(%edx), %edx
	movl	%edx, 8(%eax)
	jmp	.L2
.L197:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	addl	$3, %ebx
	movzbl	-1(%ebx), %ecx
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	4(%eax), %eax
	leal	(%eax,%ecx,4), %eax
	movl	(%edx), %ecx
	movl	%ecx, (%eax)
	movl	4(%edx), %ecx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	movl	%ecx, 4(%eax)
	movl	8(%edx), %edx
	movl	%edx, 8(%eax)
	jmp	.L2
.L196:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	addl	$3, %ebx
	movsbl	-1(%ebx), %ecx
	movl	4(%eax), %eax
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%ecx,4), %eax
	movl	(%edx), %ecx
	movl	%ecx, (%eax)
	movl	4(%edx), %ecx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	movl	%ecx, 4(%eax)
	movl	8(%edx), %edx
	movl	%edx, 8(%eax)
	jmp	.L2
.L195:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	addl	$3, %ebx
	movsbl	-1(%ebx), %ecx
	leal	(%eax,%edx,4), %edx
	leal	(%eax,%ecx,4), %eax
	movl	(%edx), %ecx
	movl	%ecx, (%eax)
	movl	4(%edx), %ecx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	movl	%ecx, 4(%eax)
	movl	8(%edx), %edx
	movl	%edx, 8(%eax)
	jmp	.L2
.L194:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	leal	(%edx,%ecx,4), %edx
	movzbl	2(%ebx), %ecx
	movl	(%edx), %edi
	leal	(%eax,%ecx,4), %eax
	cmpl	%edi, (%eax)
	je	.L399
.L309:
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L193:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	movsbl	2(%ebx), %ecx
	movl	4(%eax), %eax
	leal	(%eax,%edx,4), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movl	(%eax), %edi
	leal	(%edx,%ecx,4), %edx
	cmpl	%edi, (%edx)
	je	.L400
.L307:
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L192:
	movsbl	1(%ebx), %edx
	movsbl	2(%ebx), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%edx,4), %edx
	leal	(%eax,%ecx,4), %eax
	movl	(%edx), %edi
	cmpl	%edi, (%eax)
	je	.L401
.L305:
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L191:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	leal	(%edx,%ecx,4), %edx
	movzbl	2(%ebx), %ecx
	movl	(%edx), %edi
	leal	(%eax,%ecx,4), %eax
	cmpl	%edi, (%eax)
	je	.L402
.L304:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L190:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	movsbl	2(%ebx), %ecx
	movl	4(%eax), %eax
	leal	(%eax,%edx,4), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movl	(%eax), %edi
	leal	(%edx,%ecx,4), %edx
	cmpl	%edi, (%edx)
	je	.L403
.L303:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L189:
	movsbl	1(%ebx), %edx
	movsbl	2(%ebx), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%edx,4), %edx
	leal	(%eax,%ecx,4), %eax
	movl	(%edx), %edi
	cmpl	%edi, (%eax)
	je	.L404
.L302:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L188:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%edx,4), %ebx
	call	rand
	vxorps	%xmm2, %xmm2, %xmm2
	vmovss	.LC4, %xmm5
	vcvtsi2ss	%eax, %xmm2, %xmm2
	vfmadd132ss	.LC1, %xmm5, %xmm2
	vmovss	%xmm2, 4(%esp)
	call	rand
	vxorps	%xmm1, %xmm1, %xmm1
	vmovss	.LC4, %xmm6
	vcvtsi2ss	%eax, %xmm1, %xmm1
	vfmadd132ss	.LC1, %xmm6, %xmm1
	vmovss	%xmm1, (%esp)
	call	rand
	vmovss	(%esp), %xmm1
	vmulss	%xmm1, %xmm1, %xmm3
	vmovss	.LC4, %xmm7
	vxorps	%xmm0, %xmm0, %xmm0
	vmovss	4(%esp), %xmm2
	vcvtsi2ss	%eax, %xmm0, %xmm0
	vfmadd231ss	%xmm2, %xmm2, %xmm3
	vfmadd132ss	.LC1, %xmm7, %xmm0
	vfmadd231ss	%xmm0, %xmm0, %xmm3
	vsqrtss	%xmm3, %xmm4, %xmm4
	vucomiss	%xmm4, %xmm4
	jp	.L405
.L300:
	vmovss	.LC2, %xmm3
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	vdivss	%xmm4, %xmm3, %xmm3
	vmulss	%xmm3, %xmm2, %xmm2
	vmulss	%xmm3, %xmm1, %xmm1
	vmulss	%xmm3, %xmm0, %xmm0
	vmovss	%xmm2, (%ebx)
	vmovss	%xmm1, 4(%ebx)
	vmovss	%xmm0, 8(%ebx)
	leal	2(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L187:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	vmovss	(%edx,%ecx,4), %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movzbl	-1(%ebx), %edx
	vminss	(%ecx,%edi,4), %xmm0, %xmm0
	vmovss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L186:
	movsbl	1(%ebx), %ecx
	movsbl	2(%ebx), %edi
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	vmovss	(%edx,%ecx,4), %xmm0
	movzbl	%cl, %eax
	vminss	(%edx,%edi,4), %xmm0, %xmm0
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	movl	4(%ecx), %ecx
	vmovss	%xmm0, (%ecx,%eax,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L185:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	addl	$4, %ebx
	movsbl	-2(%ebx), %ecx
	movl	4(%eax), %eax
	vmovss	(%eax,%edx,4), %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edx
	vminss	(%eax,%ecx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L184:
	movsbl	1(%ebx), %edx
	movsbl	2(%ebx), %ecx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	vmovss	(%eax,%edx,4), %xmm0
	movsbl	-1(%ebx), %edx
	vminss	(%eax,%ecx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L183:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	vmovss	(%edx,%ecx,4), %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movzbl	-1(%ebx), %edx
	vmaxss	(%ecx,%edi,4), %xmm0, %xmm0
	vmovss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L182:
	movsbl	1(%ebx), %ecx
	movsbl	2(%ebx), %edi
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	vmovss	(%edx,%ecx,4), %xmm0
	movzbl	%cl, %eax
	vmaxss	(%edx,%edi,4), %xmm0, %xmm0
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	movl	4(%ecx), %ecx
	vmovss	%xmm0, (%ecx,%eax,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L181:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	addl	$4, %ebx
	movsbl	-2(%ebx), %ecx
	movl	4(%eax), %eax
	vmovss	(%eax,%edx,4), %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edx
	vmaxss	(%eax,%ecx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L180:
	movsbl	1(%ebx), %edx
	movsbl	2(%ebx), %ecx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	vmovss	(%eax,%edx,4), %xmm0
	movsbl	-1(%ebx), %edx
	vmaxss	(%eax,%ecx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L179:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	3(%ebx), %ecx
	subl	$8, %esp
	.cfi_def_cfa_offset 56
	movl	8(%eax), %edx
	movl	4(%eax), %eax
	leal	(%edx,%ecx,4), %edi
	movzbl	2(%ebx), %edx
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 60
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 64
	call	fmodf
	fstps	16(%esp)
	movl	16(%esp), %eax
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movl	%eax, (%edi)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	4(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L178:
	movsbl	3(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	subl	$8, %esp
	.cfi_def_cfa_offset 56
	movzbl	2(%ebx), %ecx
	leal	(%eax,%edx,4), %edi
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	8(%eax), %edx
	movl	4(%eax), %eax
	pushl	(%edx,%ecx,4)
	.cfi_def_cfa_offset 60
	movzbl	1(%ebx), %edx
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 64
	call	fmodf
	fstps	16(%esp)
	movl	16(%esp), %eax
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movl	%eax, (%edi)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	4(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L177:
	movsbl	3(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	subl	$8, %esp
	.cfi_def_cfa_offset 56
	leal	(%eax,%edx,4), %edi
	movsbl	2(%ebx), %edx
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 60
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	movl	4(%eax), %eax
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 64
	call	fmodf
	fstps	16(%esp)
	movl	16(%esp), %eax
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movl	%eax, (%edi)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	4(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L176:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	3(%ebx), %ecx
	subl	$8, %esp
	.cfi_def_cfa_offset 56
	movl	8(%eax), %edx
	movl	4(%eax), %eax
	leal	(%edx,%ecx,4), %edi
	movsbl	2(%ebx), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	pushl	(%edx,%ecx,4)
	.cfi_def_cfa_offset 60
	movzbl	1(%ebx), %edx
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 64
	call	fmodf
	fstps	16(%esp)
	movl	16(%esp), %eax
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movl	%eax, (%edi)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	4(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L175:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	3(%ebx), %edx
	subl	$8, %esp
	.cfi_def_cfa_offset 56
	movl	4(%eax), %eax
	leal	(%eax,%edx,4), %edi
	movsbl	2(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 60
	movsbl	1(%ebx), %edx
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 64
	call	fmodf
	fstps	16(%esp)
	movl	16(%esp), %eax
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movl	%eax, (%edi)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	4(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L174:
	movsbl	3(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	subl	$8, %esp
	.cfi_def_cfa_offset 56
	leal	(%eax,%edx,4), %edi
	movsbl	2(%ebx), %edx
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 60
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	movl	4(%eax), %eax
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 64
	call	fmodf
	fstps	16(%esp)
	movl	16(%esp), %eax
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movl	%eax, (%edi)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	4(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L173:
	movsbl	3(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	subl	$8, %esp
	.cfi_def_cfa_offset 56
	leal	(%eax,%edx,4), %edi
	movsbl	2(%ebx), %edx
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 60
	movsbl	1(%ebx), %edx
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 64
	call	fmodf
	fstps	16(%esp)
	movl	16(%esp), %eax
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movl	%eax, (%edi)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	4(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L172:
	movzbl	3(%ebx), %eax
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	addl	$4, %ebx
	movsbl	-3(%ebx), %ebp
	movzbl	-2(%ebx), %ecx
	movl	8(%edx), %edi
	movl	4(%edx), %edx
	movl	%eax, (%esp)
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	vmovss	(%eax,%ebp,4), %xmm0
	movl	(%esp), %eax
	vdivss	(%edx,%ecx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edi,%eax,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L171:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ebp
	addl	$4, %ebx
	movzbl	-2(%ebx), %ecx
	movsbl	-1(%ebx), %edx
	movl	4(%eax), %edi
	movl	8(%eax), %eax
	vmovss	(%edi,%ebp,4), %xmm0
	vdivss	(%eax,%ecx,4), %xmm0, %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	vmovss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L170:
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	movzbl	1(%ebx), %ebp
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edx
	movl	4(%ecx), %edi
	movsbl	-2(%ebx), %ecx
	vmovss	(%edi,%ebp,4), %xmm0
	vdivss	(%eax,%ecx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L169:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ebp
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
	movzbl	-1(%ebx), %ecx
	movl	8(%eax), %edx
	movl	4(%eax), %eax
	vmovss	(%eax,%ebp,4), %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	vdivss	(%eax,%edi,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L168:
	movsbl	1(%ebx), %ebp
	movsbl	2(%ebx), %edi
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	movzbl	-1(%ebx), %ecx
	vmovss	(%eax,%ebp,4), %xmm0
	movl	4(%edx), %edx
	vdivss	(%eax,%edi,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L167:
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	movzbl	1(%ebx), %ebp
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edx
	movl	4(%ecx), %edi
	movsbl	-2(%ebx), %ecx
	vmovss	(%edi,%ebp,4), %xmm0
	vdivss	(%eax,%ecx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L166:
	movsbl	1(%ebx), %edi
	movsbl	2(%ebx), %ecx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edx
	vmovss	(%eax,%edi,4), %xmm0
	vdivss	(%eax,%ecx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L165:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ebp
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
	movzbl	-1(%ebx), %ecx
	movl	8(%eax), %edx
	movl	4(%eax), %eax
	vmovss	(%eax,%ebp,4), %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	vmulss	(%eax,%edi,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L164:
	movsbl	1(%ebx), %ebp
	movsbl	2(%ebx), %edi
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	movzbl	-1(%ebx), %ecx
	vmovss	(%eax,%ebp,4), %xmm0
	movl	4(%edx), %edx
	vmulss	(%eax,%edi,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L163:
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	movzbl	1(%ebx), %ebp
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edx
	movl	4(%ecx), %edi
	movsbl	-2(%ebx), %ecx
	vmovss	(%edi,%ebp,4), %xmm0
	vmulss	(%eax,%ecx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L162:
	movsbl	1(%ebx), %edi
	movsbl	2(%ebx), %ecx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edx
	vmovss	(%eax,%edi,4), %xmm0
	vmulss	(%eax,%ecx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L161:
	movzbl	3(%ebx), %eax
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	addl	$4, %ebx
	movsbl	-3(%ebx), %ebp
	movzbl	-2(%ebx), %ecx
	movl	8(%edx), %edi
	movl	4(%edx), %edx
	movl	%eax, (%esp)
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	vmovss	(%eax,%ebp,4), %xmm0
	movl	(%esp), %eax
	vsubss	(%edx,%ecx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edi,%eax,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L160:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ebp
	addl	$4, %ebx
	movzbl	-2(%ebx), %ecx
	movsbl	-1(%ebx), %edx
	movl	4(%eax), %edi
	movl	8(%eax), %eax
	vmovss	(%edi,%ebp,4), %xmm0
	vsubss	(%eax,%ecx,4), %xmm0, %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	vmovss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L159:
	movsbl	1(%ebx), %ebp
	movl	_ZN3GVM11Interpreter9callStackE, %edi
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movsbl	-1(%ebx), %ecx
	movl	4(%edi), %edi
	movl	%ebp, %eax
	vmovss	(%edx,%ebp,4), %xmm0
	movzbl	%al, %eax
	vsubss	(%edi,%eax,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L158:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ebp
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
	movzbl	-1(%ebx), %ecx
	movl	8(%eax), %edx
	movl	4(%eax), %eax
	vmovss	(%eax,%ebp,4), %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	vsubss	(%eax,%edi,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L157:
	movsbl	1(%ebx), %ebp
	movsbl	2(%ebx), %edi
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	movzbl	-1(%ebx), %ecx
	vmovss	(%eax,%ebp,4), %xmm0
	movl	4(%edx), %edx
	vsubss	(%eax,%edi,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L156:
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	movzbl	1(%ebx), %ebp
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edx
	movl	4(%ecx), %edi
	movsbl	-2(%ebx), %ecx
	vmovss	(%edi,%ebp,4), %xmm0
	vsubss	(%eax,%ecx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L155:
	movsbl	1(%ebx), %edi
	movsbl	2(%ebx), %ecx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edx
	vmovss	(%eax,%edi,4), %xmm0
	vsubss	(%eax,%ecx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L154:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ebp
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
	movzbl	-1(%ebx), %ecx
	movl	8(%eax), %edx
	movl	4(%eax), %eax
	vmovss	(%eax,%ebp,4), %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	vaddss	(%eax,%edi,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L153:
	movsbl	1(%ebx), %ebp
	movsbl	2(%ebx), %edi
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	movzbl	-1(%ebx), %ecx
	vmovss	(%eax,%ebp,4), %xmm0
	movl	4(%edx), %edx
	vaddss	(%eax,%edi,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L152:
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	movzbl	1(%ebx), %ebp
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edx
	movl	4(%ecx), %edi
	movsbl	-2(%ebx), %ecx
	vmovss	(%edi,%ebp,4), %xmm0
	vaddss	(%eax,%ecx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L151:
	movsbl	1(%ebx), %edi
	movsbl	2(%ebx), %ecx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edx
	vmovss	(%eax,%edi,4), %xmm0
	vaddss	(%eax,%ecx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L150:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edi
	addl	$3, %ebx
	movzbl	-1(%ebx), %ecx
	movl	8(%eax), %edx
	movl	4(%eax), %eax
	vmovss	(%eax,%edi,4), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L149:
	movsbl	1(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	addl	$3, %ebx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	-1(%ebx), %edx
	vmovss	(%ecx,%edi,4), %xmm0
	movl	4(%eax), %eax
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L148:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	addl	$3, %ebx
	movsbl	-1(%ebx), %edx
	movl	4(%eax), %eax
	vmovss	(%eax,%ecx,4), %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L147:
	movsbl	1(%ebx), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	addl	$3, %ebx
	movsbl	-1(%ebx), %edx
	vmovss	(%eax,%ecx,4), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L146:
	movsbl	2(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	leal	(%eax,%edx,4), %edi
	movsbl	1(%ebx), %edx
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 64
	call	acosf
	fstps	16(%esp)
	movl	16(%esp), %eax
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movl	%eax, (%edi)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	3(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L145:
	movsbl	1(%ebx), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	addl	$3, %ebx
	pushl	(%edi,%eax,4)
	.cfi_def_cfa_offset 64
	call	cosf
	movsbl	-1(%ebx), %eax
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	movl	(%esp), %edx
	movl	%edx, (%edi,%eax,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L144:
	movsbl	1(%ebx), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	addl	$3, %ebx
	pushl	(%edi,%eax,4)
	.cfi_def_cfa_offset 64
	call	sinf
	movsbl	-1(%ebx), %eax
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	movl	(%esp), %edx
	movl	%edx, (%edi,%eax,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L143:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	addl	$3, %ebx
	vmovss	.LC2, %xmm1
	vmovss	(%eax,%edx,4), %xmm0
	movsbl	-1(%ebx), %edx
	vmulss	%xmm0, %xmm0, %xmm0
	vdivss	%xmm0, %xmm1, %xmm0
	vmovss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L142:
	movsbl	2(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%edx,4), %edi
	movsbl	1(%ebx), %edx
	vsqrtss	(%eax,%edx,4), %xmm0, %xmm0
	vucomiss	%xmm0, %xmm0
	jp	.L406
.L282:
	vmovss	%xmm0, (%edi)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	3(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L141:
	movsbl	1(%ebx), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	addl	$3, %ebx
	vmovss	.LC2, %xmm0
	movsbl	-1(%ebx), %edx
	vdivss	(%eax,%ecx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L140:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edi
	movzbl	2(%ebx), %edx
	movl	4(%eax), %ecx
	movl	8(%eax), %eax
	vmovss	(%ecx,%edi,4), %xmm0
	vucomiss	(%eax,%edx,4), %xmm0
	jbe	.L386
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L139:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movsbl	1(%ebx), %edi
	movzbl	2(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movl	4(%eax), %eax
	vmovss	(%ecx,%edi,4), %xmm0
	vucomiss	(%eax,%edx,4), %xmm0
	jbe	.L385
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L138:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	movsbl	2(%ebx), %edx
	movl	4(%eax), %eax
	vmovss	(%eax,%ecx,4), %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	vucomiss	(%eax,%edx,4), %xmm0
	jbe	.L384
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L137:
	movsbl	1(%ebx), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	2(%ebx), %edx
	vmovss	(%eax,%ecx,4), %xmm0
	vucomiss	(%eax,%edx,4), %xmm0
	jbe	.L383
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L136:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edi
	movzbl	2(%ebx), %edx
	movl	4(%eax), %ecx
	movl	8(%eax), %eax
	vmovss	(%ecx,%edi,4), %xmm0
	vucomiss	(%eax,%edx,4), %xmm0
	jb	.L382
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L135:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movsbl	1(%ebx), %edi
	movzbl	2(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movl	4(%eax), %eax
	vmovss	(%ecx,%edi,4), %xmm0
	vucomiss	(%eax,%edx,4), %xmm0
	jb	.L381
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L134:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	movsbl	2(%ebx), %edx
	movl	4(%eax), %eax
	vmovss	(%eax,%ecx,4), %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	vucomiss	(%eax,%edx,4), %xmm0
	jb	.L380
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L133:
	movsbl	1(%ebx), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	2(%ebx), %edx
	vmovss	(%eax,%ecx,4), %xmm0
	vucomiss	(%eax,%edx,4), %xmm0
	jb	.L379
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L132:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%edx,4), %ebx
	call	rand
	vxorps	%xmm0, %xmm0, %xmm0
	vcvtsi2ss	%eax, %xmm0, %xmm0
	vmulss	.LC1, %xmm0, %xmm0
	vmovss	%xmm0, (%ebx)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	2(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L131:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	movsbl	2(%ebx), %ebp
	movzbl	3(%ebx), %ecx
	movl	8(%eax), %edi
	movl	4(%eax), %eax
	movl	%edi, (%esp)
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	movl	(%edi,%ebp,4), %edi
	cmpl	%edi, (%eax,%edx,4)
	cmovle	(%eax,%edx,4), %edi
	movl	(%esp), %eax
	addl	$4, %ebx
	movl	%edi, (%eax,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L130:
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	movzbl	1(%ebx), %ebp
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movl	4(%ecx), %edi
	movsbl	2(%ebx), %ecx
	movl	%ebp, %eax
	movsbl	%al, %eax
	movl	(%edx,%eax,4), %eax
	cmpl	%eax, (%edx,%ecx,4)
	cmovle	(%edx,%ecx,4), %eax
	addl	$4, %ebx
	movl	%eax, (%edi,%ebp,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L129:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ebp
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movsbl	3(%ebx), %edi
	movl	4(%eax), %ecx
	movsbl	2(%ebx), %eax
	movl	(%edx,%eax,4), %eax
	cmpl	%eax, (%ecx,%ebp,4)
	cmovle	(%ecx,%ebp,4), %eax
	addl	$4, %ebx
	movl	%eax, (%edx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L128:
	movsbl	1(%ebx), %ecx
	movsbl	2(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	3(%ebx), %edi
	movl	(%eax,%edx,4), %edx
	cmpl	%edx, (%eax,%ecx,4)
	cmovle	(%eax,%ecx,4), %edx
	addl	$4, %ebx
	movl	%edx, (%eax,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L127:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	movsbl	2(%ebx), %ebp
	movzbl	3(%ebx), %ecx
	movl	8(%eax), %edi
	movl	4(%eax), %eax
	movl	%edi, (%esp)
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	movl	(%edi,%ebp,4), %edi
	cmpl	%edi, (%eax,%edx,4)
	cmovge	(%eax,%edx,4), %edi
	movl	(%esp), %eax
	addl	$4, %ebx
	movl	%edi, (%eax,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L126:
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	movzbl	1(%ebx), %ebp
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movl	4(%ecx), %edi
	movsbl	2(%ebx), %ecx
	movl	%ebp, %eax
	movsbl	%al, %eax
	movl	(%edx,%eax,4), %eax
	cmpl	%eax, (%edx,%ecx,4)
	cmovge	(%edx,%ecx,4), %eax
	addl	$4, %ebx
	movl	%eax, (%edi,%ebp,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L125:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ebp
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movsbl	3(%ebx), %edi
	movl	4(%eax), %ecx
	movsbl	2(%ebx), %eax
	movl	(%edx,%eax,4), %eax
	cmpl	%eax, (%ecx,%ebp,4)
	cmovge	(%ecx,%ebp,4), %eax
	addl	$4, %ebx
	movl	%eax, (%edx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L124:
	movsbl	1(%ebx), %ecx
	movsbl	2(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	3(%ebx), %edi
	movl	(%eax,%edx,4), %edx
	cmpl	%edx, (%eax,%ecx,4)
	cmovge	(%eax,%ecx,4), %edx
	addl	$4, %ebx
	movl	%edx, (%eax,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L123:
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movsbl	-2(%ebx), %ebp
	movzbl	-1(%ebx), %eax
	movl	8(%edx), %edi
	movl	4(%edx), %edx
	movl	%edi, (%esp)
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	movl	(%edx,%ecx,4), %edx
	movl	(%edi,%ebp,4), %edi
	shrx	%edi, %edx, %edx
	movl	(%esp), %edi
	movl	%edx, (%edi,%eax,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L122:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movsbl	2(%ebx), %ebp
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movzbl	-1(%ebx), %edi
	movl	4(%eax), %ecx
	movsbl	-3(%ebx), %eax
	movl	(%edx,%ebp,4), %ebp
	movl	(%edx,%eax,4), %eax
	shrx	%ebp, %eax, %eax
	movl	%eax, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L121:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ebp
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movsbl	-1(%ebx), %ecx
	movl	4(%eax), %eax
	movl	(%edx,%edi,4), %edi
	movl	(%eax,%ebp,4), %eax
	shrx	%edi, %eax, %eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L120:
	movsbl	1(%ebx), %edx
	movsbl	2(%ebx), %edi
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %ecx
	movl	(%eax,%edi,4), %edi
	movl	(%eax,%edx,4), %edx
	shrx	%edi, %edx, %edx
	movl	%edx, (%eax,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L119:
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movsbl	-2(%ebx), %ebp
	movzbl	-1(%ebx), %eax
	movl	8(%edx), %edi
	movl	4(%edx), %edx
	movl	%edi, (%esp)
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	movl	(%edx,%ecx,4), %edx
	movl	(%edi,%ebp,4), %edi
	shlx	%edi, %edx, %edx
	movl	(%esp), %edi
	movl	%edx, (%edi,%eax,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L118:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movsbl	2(%ebx), %ebp
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movzbl	-1(%ebx), %edi
	movl	4(%eax), %ecx
	movsbl	-3(%ebx), %eax
	movl	(%edx,%ebp,4), %ebp
	movl	(%edx,%eax,4), %eax
	shlx	%ebp, %eax, %eax
	movl	%eax, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L117:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ebp
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movsbl	-1(%ebx), %ecx
	movl	4(%eax), %eax
	movl	(%edx,%edi,4), %edi
	movl	(%eax,%ebp,4), %eax
	shlx	%edi, %eax, %eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L116:
	movsbl	1(%ebx), %edx
	movsbl	2(%ebx), %edi
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %ecx
	movl	(%eax,%edi,4), %edi
	movl	(%eax,%edx,4), %edx
	shlx	%edi, %edx, %edx
	movl	%edx, (%eax,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L115:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edi
	addl	$4, %ebx
	movsbl	-2(%ebx), %ebp
	movzbl	-1(%ebx), %ecx
	movl	8(%eax), %edx
	movl	4(%eax), %eax
	movl	(%eax,%edi,4), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	xorl	(%edi,%ebp,4), %eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L114:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movsbl	2(%ebx), %ebp
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movzbl	-1(%ebx), %edi
	movl	4(%eax), %ecx
	movsbl	-3(%ebx), %eax
	movl	(%edx,%eax,4), %eax
	xorl	(%edx,%ebp,4), %eax
	movl	%eax, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L113:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ebp
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movsbl	-1(%ebx), %ecx
	movl	4(%eax), %eax
	movl	(%eax,%ebp,4), %eax
	xorl	(%edx,%edi,4), %eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L112:
	movsbl	1(%ebx), %edx
	movsbl	2(%ebx), %edi
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %ecx
	movl	(%eax,%edx,4), %edx
	xorl	(%eax,%edi,4), %edx
	movl	%edx, (%eax,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L111:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edi
	addl	$4, %ebx
	movsbl	-2(%ebx), %ebp
	movzbl	-1(%ebx), %ecx
	movl	8(%eax), %edx
	movl	4(%eax), %eax
	movl	(%eax,%edi,4), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	orl	(%edi,%ebp,4), %eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L110:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movsbl	2(%ebx), %ebp
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movzbl	-1(%ebx), %edi
	movl	4(%eax), %ecx
	movsbl	-3(%ebx), %eax
	movl	(%edx,%eax,4), %eax
	orl	(%edx,%ebp,4), %eax
	movl	%eax, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L109:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ebp
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movsbl	-1(%ebx), %ecx
	movl	4(%eax), %eax
	movl	(%eax,%ebp,4), %eax
	orl	(%edx,%edi,4), %eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L108:
	movsbl	1(%ebx), %edx
	movsbl	2(%ebx), %edi
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %ecx
	movl	(%eax,%edx,4), %edx
	orl	(%eax,%edi,4), %edx
	movl	%edx, (%eax,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L107:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edi
	addl	$4, %ebx
	movsbl	-2(%ebx), %ebp
	movzbl	-1(%ebx), %ecx
	movl	8(%eax), %edx
	movl	4(%eax), %eax
	movl	(%eax,%edi,4), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	andl	(%edi,%ebp,4), %eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L106:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movsbl	2(%ebx), %ebp
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movzbl	-1(%ebx), %edi
	movl	4(%eax), %ecx
	movsbl	-3(%ebx), %eax
	movl	(%edx,%eax,4), %eax
	andl	(%edx,%ebp,4), %eax
	movl	%eax, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L105:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ebp
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movsbl	-1(%ebx), %ecx
	movl	4(%eax), %eax
	movl	(%eax,%ebp,4), %eax
	andl	(%edx,%edi,4), %eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L104:
	movsbl	1(%ebx), %edx
	movsbl	2(%ebx), %edi
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %ecx
	movl	(%eax,%edx,4), %edx
	andl	(%eax,%edi,4), %edx
	movl	%edx, (%eax,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L103:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	2(%ebx), %ecx
	movl	4(%eax), %edx
	movl	(%edx,%ecx,4), %ebp
	testl	%ebp, %ebp
	je	.L353
	movsbl	1(%ebx), %edx
	movl	8(%eax), %ecx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movzbl	-1(%ebx), %edi
	movl	(%eax,%edx,4), %eax
	cltd
	idivl	%ebp
	movl	%edx, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L102:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	2(%ebx), %ecx
	movl	8(%eax), %edx
	movl	(%edx,%ecx,4), %edi
	testl	%edi, %edi
	je	.L353
	movzbl	1(%ebx), %edx
	movl	4(%eax), %eax
	addl	$4, %ebx
	movsbl	-1(%ebx), %ecx
	movl	(%eax,%edx,4), %eax
	cltd
	idivl	%edi
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	%edx, (%eax,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L101:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	2(%ebx), %edx
	movl	4(%eax), %eax
	movl	(%eax,%edx,4), %ebp
	testl	%ebp, %ebp
	je	.L353
	movsbl	1(%ebx), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	addl	$4, %ebx
	movsbl	-1(%ebx), %edi
	movl	(%ecx,%eax,4), %eax
	cltd
	idivl	%ebp
	movl	%edx, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L100:
	movsbl	2(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	(%eax,%edx,4), %ebp
	testl	%ebp, %ebp
	je	.L353
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	addl	$4, %ebx
	movzbl	-1(%ebx), %edi
	movl	8(%eax), %ecx
	movl	4(%eax), %eax
	movl	(%eax,%edx,4), %eax
	cltd
	idivl	%ebp
	movl	%edx, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L99:
	movsbl	2(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	(%eax,%edx,4), %ebp
	testl	%ebp, %ebp
	je	.L353
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	movzbl	3(%ebx), %edi
	addl	$4, %ebx
	movl	4(%edx), %ecx
	movsbl	-3(%ebx), %edx
	movl	(%eax,%edx,4), %eax
	cltd
	idivl	%ebp
	movl	%edx, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L98:
	movsbl	2(%ebx), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movl	(%ecx,%eax,4), %ebp
	testl	%ebp, %ebp
	je	.L353
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	addl	$4, %ebx
	movsbl	-1(%ebx), %edi
	movl	4(%eax), %eax
	movl	(%eax,%edx,4), %eax
	cltd
	idivl	%ebp
	movl	%edx, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L97:
	movsbl	2(%ebx), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movl	(%ecx,%eax,4), %ebp
	testl	%ebp, %ebp
	je	.L353
	movsbl	1(%ebx), %eax
	movsbl	3(%ebx), %edi
	addl	$4, %ebx
	movl	(%ecx,%eax,4), %eax
	cltd
	idivl	%ebp
	movl	%edx, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L96:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	2(%ebx), %ecx
	movl	4(%eax), %edx
	movl	(%edx,%ecx,4), %ebp
	testl	%ebp, %ebp
	je	.L353
	movsbl	1(%ebx), %edx
	movl	8(%eax), %ecx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movzbl	-1(%ebx), %edi
	movl	(%eax,%edx,4), %eax
	cltd
	idivl	%ebp
	movl	%eax, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L95:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	2(%ebx), %ecx
	movl	8(%eax), %edx
	movl	(%edx,%ecx,4), %edi
	testl	%edi, %edi
	je	.L353
	movzbl	1(%ebx), %edx
	movl	4(%eax), %eax
	addl	$4, %ebx
	movsbl	-1(%ebx), %ecx
	movl	(%eax,%edx,4), %eax
	cltd
	idivl	%edi
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L94:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	2(%ebx), %edx
	movl	4(%eax), %eax
	movl	(%eax,%edx,4), %ebp
	testl	%ebp, %ebp
	je	.L353
	movsbl	1(%ebx), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	addl	$4, %ebx
	movsbl	-1(%ebx), %edi
	movl	(%ecx,%eax,4), %eax
	cltd
	idivl	%ebp
	movl	%eax, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L93:
	movsbl	2(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	(%eax,%edx,4), %ebp
	testl	%ebp, %ebp
	je	.L353
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	addl	$4, %ebx
	movzbl	-1(%ebx), %edi
	movl	8(%eax), %ecx
	movl	4(%eax), %eax
	movl	(%eax,%edx,4), %eax
	cltd
	idivl	%ebp
	movl	%eax, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L92:
	movsbl	2(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	(%eax,%edx,4), %ebp
	testl	%ebp, %ebp
	je	.L353
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	movzbl	3(%ebx), %edi
	addl	$4, %ebx
	movl	4(%edx), %ecx
	movsbl	-3(%ebx), %edx
	movl	(%eax,%edx,4), %eax
	cltd
	idivl	%ebp
	movl	%eax, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L91:
	movsbl	2(%ebx), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movl	(%ecx,%eax,4), %ebp
	testl	%ebp, %ebp
	je	.L353
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	addl	$4, %ebx
	movsbl	-1(%ebx), %edi
	movl	4(%eax), %eax
	movl	(%eax,%edx,4), %eax
	cltd
	idivl	%ebp
	movl	%eax, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L90:
	movsbl	2(%ebx), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movl	(%ecx,%eax,4), %ebp
	testl	%ebp, %ebp
	je	.L353
	movsbl	1(%ebx), %eax
	movsbl	3(%ebx), %edi
	addl	$4, %ebx
	movl	(%ecx,%eax,4), %eax
	cltd
	idivl	%ebp
	movl	%eax, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L89:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edi
	addl	$4, %ebx
	movsbl	-2(%ebx), %ebp
	movzbl	-1(%ebx), %ecx
	movl	8(%eax), %edx
	movl	4(%eax), %eax
	movl	(%eax,%edi,4), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	imull	(%edi,%ebp,4), %eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L88:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movsbl	2(%ebx), %ebp
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movzbl	-1(%ebx), %edi
	movl	4(%eax), %ecx
	movsbl	-3(%ebx), %eax
	movl	(%edx,%eax,4), %eax
	imull	(%edx,%ebp,4), %eax
	movl	%eax, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L87:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ebp
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movsbl	-1(%ebx), %ecx
	movl	4(%eax), %eax
	movl	(%eax,%ebp,4), %eax
	imull	(%edx,%edi,4), %eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L86:
	movsbl	1(%ebx), %edx
	movsbl	2(%ebx), %edi
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %ecx
	movl	(%eax,%edx,4), %edx
	imull	(%eax,%edi,4), %edx
	movl	%edx, (%eax,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L85:
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	movsbl	1(%ebx), %ebp
	addl	$4, %ebx
	movzbl	-2(%ebx), %ecx
	movzbl	-1(%ebx), %eax
	movl	8(%edx), %edi
	movl	4(%edx), %edx
	movl	%edi, (%esp)
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	movl	(%edi,%ebp,4), %edi
	subl	(%edx,%ecx,4), %edi
	movl	%edi, %edx
	movl	(%esp), %edi
	movl	%edx, (%edi,%eax,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L84:
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	movzbl	1(%ebx), %ebp
	addl	$4, %ebx
	movzbl	-2(%ebx), %edi
	movsbl	-1(%ebx), %edx
	movl	4(%ecx), %eax
	movl	8(%ecx), %ecx
	movl	(%eax,%ebp,4), %eax
	subl	(%ecx,%edi,4), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movl	%eax, (%ecx,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L83:
	movsbl	1(%ebx), %ebp
	movl	_ZN3GVM11Interpreter9callStackE, %edi
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movsbl	-1(%ebx), %ecx
	movl	4(%edi), %edi
	movl	%ebp, %eax
	movl	(%edx,%ebp,4), %ebp
	movzbl	%al, %eax
	subl	(%edi,%eax,4), %ebp
	movl	%ebp, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L82:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edi
	addl	$4, %ebx
	movsbl	-2(%ebx), %ebp
	movzbl	-1(%ebx), %ecx
	movl	8(%eax), %edx
	movl	4(%eax), %eax
	movl	(%eax,%edi,4), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	subl	(%edi,%ebp,4), %eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L81:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movsbl	2(%ebx), %ebp
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movzbl	-1(%ebx), %edi
	movl	4(%eax), %ecx
	movsbl	-3(%ebx), %eax
	movl	(%edx,%eax,4), %eax
	subl	(%edx,%ebp,4), %eax
	movl	%eax, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L80:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ebp
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movsbl	-1(%ebx), %ecx
	movl	4(%eax), %eax
	movl	(%eax,%ebp,4), %eax
	subl	(%edx,%edi,4), %eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L79:
	movsbl	1(%ebx), %edx
	movsbl	2(%ebx), %edi
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %ecx
	movl	(%eax,%edx,4), %edx
	subl	(%eax,%edi,4), %edx
	movl	%edx, (%eax,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L78:
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movsbl	-2(%ebx), %ebp
	movzbl	-1(%ebx), %eax
	movl	8(%edx), %edi
	movl	4(%edx), %edx
	movl	%edi, (%esp)
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	movl	(%edi,%ebp,4), %edi
	addl	(%edx,%ecx,4), %edi
	movl	%edi, %edx
	movl	(%esp), %edi
	movl	%edx, (%edi,%eax,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L77:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movsbl	1(%ebx), %ebp
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movzbl	-1(%ebx), %edi
	movl	4(%eax), %ecx
	movsbl	-2(%ebx), %eax
	movl	(%edx,%eax,4), %eax
	addl	(%edx,%ebp,4), %eax
	movl	%eax, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L76:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ebp
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movsbl	-1(%ebx), %ecx
	movl	4(%eax), %edi
	movsbl	-2(%ebx), %eax
	movl	(%edx,%eax,4), %eax
	addl	(%edi,%ebp,4), %eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L75:
	movsbl	1(%ebx), %edi
	movsbl	2(%ebx), %edx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %ecx
	movl	(%eax,%edx,4), %edx
	addl	(%eax,%edi,4), %edx
	movl	%edx, (%eax,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L74:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edi
	addl	$3, %ebx
	movzbl	-1(%ebx), %ecx
	movl	8(%eax), %edx
	movl	4(%eax), %eax
	movl	(%eax,%edi,4), %eax
	negl	%eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L73:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movsbl	1(%ebx), %edi
	addl	$3, %ebx
	movzbl	-1(%ebx), %ecx
	movl	4(%eax), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	(%eax,%edi,4), %eax
	negl	%eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L72:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	addl	$3, %ebx
	movsbl	-1(%ebx), %ecx
	movl	4(%eax), %eax
	movl	(%eax,%edx,4), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	negl	%eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L71:
	movsbl	1(%ebx), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	addl	$3, %ebx
	movsbl	-1(%ebx), %ecx
	movl	(%edx,%eax,4), %eax
	negl	%eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L70:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edi
	addl	$3, %ebx
	movzbl	-1(%ebx), %ecx
	movl	8(%eax), %edx
	movl	4(%eax), %eax
	movl	(%eax,%edi,4), %eax
	notl	%eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L69:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movsbl	1(%ebx), %edi
	addl	$3, %ebx
	movzbl	-1(%ebx), %ecx
	movl	4(%eax), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	(%eax,%edi,4), %eax
	notl	%eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L68:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	addl	$3, %ebx
	movsbl	-1(%ebx), %ecx
	movl	4(%eax), %eax
	movl	(%eax,%edx,4), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	notl	%eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L67:
	movsbl	1(%ebx), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	addl	$3, %ebx
	movsbl	-1(%ebx), %ecx
	movl	(%edx,%eax,4), %eax
	notl	%eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L66:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	2(%ebx), %ecx
	movzbl	1(%ebx), %edi
	movl	4(%eax), %edx
	movl	$1, %eax
	shlx	%edi, %eax, %eax
	testl	%eax, (%edx,%ecx,4)
	jne	.L265
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L65:
	movzbl	1(%ebx), %edx
	movsbl	2(%ebx), %ecx
	movl	$1, %eax
	shlx	%edx, %eax, %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	testl	%eax, (%edx,%ecx,4)
	jne	.L264
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L64:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	2(%ebx), %ecx
	movzbl	1(%ebx), %edi
	movl	4(%eax), %edx
	movl	$1, %eax
	shlx	%edi, %eax, %eax
	testl	%eax, (%edx,%ecx,4)
	je	.L263
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L63:
	movzbl	1(%ebx), %edx
	movsbl	2(%ebx), %ecx
	movl	$1, %eax
	shlx	%edx, %eax, %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	testl	%eax, (%edx,%ecx,4)
	je	.L262
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L62:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	addl	$3, %ebx
	movzbl	-1(%ebx), %edi
	movl	4(%eax), %edx
	movl	$-2, %eax
	roll	%cl, %eax
	andl	%eax, (%edx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L61:
	movzbl	1(%ebx), %ecx
	movsbl	2(%ebx), %edi
	movl	$-2, %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	addl	$3, %ebx
	roll	%cl, %eax
	andl	%eax, (%edx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L60:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edi
	addl	$3, %ebx
	movzbl	-1(%ebx), %ecx
	movl	4(%eax), %edx
	movl	$1, %eax
	shlx	%edi, %eax, %eax
	orl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L59:
	movzbl	1(%ebx), %edi
	movsbl	2(%ebx), %ecx
	movl	$1, %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	addl	$3, %ebx
	shlx	%edi, %eax, %eax
	orl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L58:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	2(%ebx), %edx
	addl	$3, %ebx
	movsbl	-2(%ebx), %ecx
	movl	8(%eax), %eax
	movl	%ecx, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L57:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	2(%ebx), %edx
	addl	$3, %ebx
	movsbl	-2(%ebx), %ecx
	movl	4(%eax), %eax
	movl	%ecx, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L56:
	movsbl	2(%ebx), %edx
	movsbl	1(%ebx), %ecx
	addl	$3, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	%ecx, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L55:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%edx,4), %edx
	subl	$1, (%edx)
	js	.L261
	movzbl	2(%ebx), %eax
	movzbl	3(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L54:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%edx,4), %edx
	subl	$1, (%edx)
	je	.L260
	movzbl	2(%ebx), %eax
	movzbl	3(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L53:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edi
	movzbl	2(%ebx), %edx
	movl	4(%eax), %ecx
	movl	8(%eax), %eax
	movl	(%eax,%edx,4), %eax
	cmpl	%eax, (%ecx,%edi,4)
	jle	.L259
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L52:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movsbl	1(%ebx), %edi
	movzbl	2(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movl	4(%eax), %eax
	movl	(%eax,%edx,4), %eax
	cmpl	%eax, (%ecx,%edi,4)
	jle	.L258
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L51:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edi
	movsbl	2(%ebx), %edx
	movl	4(%eax), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	(%eax,%edx,4), %eax
	cmpl	%eax, (%ecx,%edi,4)
	jle	.L257
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L50:
	movsbl	1(%ebx), %ecx
	movsbl	2(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	(%eax,%edx,4), %edi
	cmpl	%edi, (%eax,%ecx,4)
	jle	.L256
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L49:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edi
	movzbl	2(%ebx), %edx
	movl	4(%eax), %ecx
	movl	8(%eax), %eax
	movl	(%eax,%edx,4), %eax
	cmpl	%eax, (%ecx,%edi,4)
	jl	.L255
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L48:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movsbl	1(%ebx), %edi
	movzbl	2(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movl	4(%eax), %eax
	movl	(%eax,%edx,4), %eax
	cmpl	%eax, (%ecx,%edi,4)
	jl	.L254
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L47:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edi
	movsbl	2(%ebx), %edx
	movl	4(%eax), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	(%eax,%edx,4), %eax
	cmpl	%eax, (%ecx,%edi,4)
	jl	.L253
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L46:
	movsbl	1(%ebx), %ecx
	movsbl	2(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	(%eax,%edx,4), %edi
	cmpl	%edi, (%eax,%ecx,4)
	jl	.L252
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L45:
	movsbl	1(%ebx), %ecx
	movsbl	2(%ebx), %edx
	addl	$3, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	vxorps	%xmm0, %xmm0, %xmm0
	vcvtsi2ss	(%eax,%ecx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L44:
	movsbl	1(%ebx), %ecx
	movsbl	2(%ebx), %edx
	addl	$3, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	vcvttss2si	(%eax,%ecx,4), %ecx
	movl	%ecx, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L43:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	addl	$3, %ebx
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	movl	(%edx,%ecx,4), %ecx
	movzbl	-1(%ebx), %edx
	movl	%ecx, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L42:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	addl	$3, %ebx
	movl	(%eax,%edx,4), %ecx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	-1(%ebx), %edx
	movl	4(%eax), %eax
	movl	%ecx, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L41:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	addl	$3, %ebx
	movl	(%eax,%edx,4), %ecx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	-1(%ebx), %edx
	movl	4(%eax), %eax
	movl	%ecx, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L40:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	addl	$3, %ebx
	movl	8(%eax), %eax
	movl	(%eax,%edx,4), %ecx
	movsbl	-1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	%ecx, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L39:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	addl	$3, %ebx
	movl	4(%eax), %eax
	movl	(%eax,%edx,4), %ecx
	movsbl	-1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	%ecx, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L38:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	addl	$3, %ebx
	movl	(%eax,%edx,4), %ecx
	movsbl	-1(%ebx), %edx
	movl	%ecx, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L37:
	addl	$3, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L36:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movsbl	1(%ebx), %edx
	movl	8(%eax), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	%ecx, (%eax,%edx,4)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	2(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L35:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movsbl	1(%ebx), %edx
	movl	4(%eax), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	%ecx, (%eax,%edx,4)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	2(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L34:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	addl	$2, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	%edx, 8(%eax)
	jmp	.L2
.L33:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	addl	$2, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	%edx, 4(%eax)
	jmp	.L2
.L32:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	addl	$4, %ebx
	movzbl	-1(%ebx), %edi
	movl	8(%eax), %ecx
	movzbl	-2(%ebx), %eax
	orl	$-2147483648, %eax
	movl	%eax, %ebp
	movl	%edx, %eax
	sall	$8, %eax
	orl	%ebp, %eax
	movl	%eax, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L31:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	3(%ebx), %ecx
	addl	$4, %ebx
	movl	4(%eax), %edx
	movzbl	-3(%ebx), %eax
	sall	$8, %eax
	movl	%eax, %edi
	movzbl	-2(%ebx), %eax
	orl	$-2147483648, %eax
	orl	%edi, %eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L30:
	movzbl	1(%ebx), %eax
	movsbl	3(%ebx), %ecx
	addl	$4, %ebx
	sall	$8, %eax
	movl	%eax, %edx
	movzbl	-2(%ebx), %eax
	orl	$-2147483648, %eax
	orl	%edx, %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L29:
	movzwl	1(%ebx), %eax
	rolw	$8, %ax
	testw	%ax, %ax
	movzwl	%ax, %edx
	je	.L339
	movl	_ZN3GVM11Interpreter9dataTableE, %eax
	addl	$3, %ebx
	movl	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	movl	%edx, 8(%eax)
	jmp	.L2
.L28:
	movzwl	1(%ebx), %eax
	rolw	$8, %ax
	testw	%ax, %ax
	movzwl	%ax, %edx
	je	.L339
	movl	_ZN3GVM11Interpreter9dataTableE, %eax
	addl	$3, %ebx
	movl	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	movl	%edx, 4(%eax)
	jmp	.L2
.L27:
	movzwl	1(%ebx), %eax
	rolw	$8, %ax
	testw	%ax, %ax
	movzwl	%ax, %edx
	je	.L339
	movl	_ZN3GVM11Interpreter9dataTableE, %eax
	movl	(%eax,%edx,4), %ecx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	3(%ebx), %edx
	movl	8(%eax), %eax
	movl	%ecx, (%eax,%edx,4)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	4(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L26:
	movzwl	1(%ebx), %eax
	rolw	$8, %ax
	testw	%ax, %ax
	movzwl	%ax, %edx
	je	.L339
	movl	_ZN3GVM11Interpreter9dataTableE, %eax
	movl	(%eax,%edx,4), %ecx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	3(%ebx), %edx
	movl	4(%eax), %eax
	movl	%ecx, (%eax,%edx,4)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	4(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L25:
	movzwl	1(%ebx), %eax
	rolw	$8, %ax
	testw	%ax, %ax
	movzwl	%ax, %edx
	je	.L339
	movl	_ZN3GVM11Interpreter9dataTableE, %eax
	movl	(%eax,%edx,4), %ecx
	movsbl	3(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	%ecx, (%eax,%edx,4)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	4(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L24:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	movsbl	2(%ebx), %edx
	movl	8(%eax), %eax
	leal	(%eax,%ecx,4), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	%ecx, (%eax,%edx,4)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	3(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L23:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	movsbl	2(%ebx), %edx
	movl	4(%eax), %eax
	leal	(%eax,%ecx,4), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	%ecx, (%eax,%edx,4)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	3(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L22:
	movsbl	1(%ebx), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	2(%ebx), %edx
	leal	(%eax,%ecx,4), %ecx
	movl	%ecx, (%eax,%edx,4)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	3(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L21:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edi
	movzbl	2(%ebx), %edx
	movl	4(%eax), %ecx
	movl	8(%eax), %eax
	movl	(%eax,%edx,4), %eax
	cmpl	%eax, (%ecx,%edi,4)
	je	.L407
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L20:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	2(%ebx), %edi
	movsbl	1(%ebx), %edx
	movl	4(%eax), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	(%eax,%edx,4), %eax
	cmpl	%eax, (%ecx,%edi,4)
	je	.L408
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L19:
	movsbl	2(%ebx), %ecx
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	(%eax,%edx,4), %edi
	cmpl	%edi, (%eax,%ecx,4)
	je	.L409
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L18:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	2(%ebx), %edx
	movl	4(%eax), %eax
	movl	(%eax,%edx,4), %eax
	testl	%eax, %eax
	je	.L248
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L17:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	(%eax,%edx,4), %edx
	testl	%edx, %edx
	je	.L247
	movzbl	2(%ebx), %eax
	movzbl	3(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L16:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	2(%ebx), %edx
	movl	4(%eax), %eax
	movl	(%eax,%edx,4), %ecx
	testl	%ecx, %ecx
	jne	.L246
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L15:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	(%eax,%edx,4), %edi
	testl	%edi, %edi
	jne	.L245
	movzbl	2(%ebx), %eax
	movzbl	3(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L14:
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	movzbl	1(%ebx), %ecx
	movl	8(%edx), %eax
	movl	(%eax,%ecx,4), %eax
	testl	%eax, %eax
	movl	%eax, 8(%edx)
	je	.L410
	addl	$3, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L13:
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	movzbl	1(%ebx), %ecx
	movl	4(%edx), %eax
	movl	(%eax,%ecx,4), %eax
	testl	%eax, %eax
	movl	%eax, 4(%edx)
	je	.L411
	addl	$3, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L12:
	call	_ZN3GVM11Interpreter12exitFunctionEv
	testl	%eax, %eax
	jne	.L242
	movl	_ZN3GVM11Interpreter14programCounterE, %ebx
	jmp	.L2
.L11:
	movzbl	1(%ebx), %eax
	movzbl	2(%ebx), %edx
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	sall	$8, %eax
	orl	%edx, %eax
	movzwl	%ax, %eax
	pushl	%eax
	.cfi_def_cfa_offset 64
	call	_ZN3GVM11Interpreter18invokeHostFunctionEt
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	testl	%eax, %eax
	jne	.L387
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	3(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L10:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	2(%ebx), %edx
	movl	4(%eax), %eax
	movl	(%eax,%edx,4), %eax
	movl	%eax, %edx
	andl	$-1073741824, %edx
	cmpl	$-2147483648, %edx
	jne	.L332
	subl	$8, %esp
	.cfi_def_cfa_offset 56
	movzwl	%ax, %eax
	addl	$3, %ebx
	pushl	%eax
	.cfi_def_cfa_offset 60
	pushl	%ebx
	.cfi_def_cfa_offset 64
	call	_ZN3GVM11Interpreter13enterFunctionEPKht
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	testl	%eax, %eax
	jne	.L387
	movl	_ZN3GVM11Interpreter14programCounterE, %ebx
	jmp	.L2
.L6:
	movzbl	1(%ebx), %eax
	movzbl	2(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L4:
	movsbl	1(%ebx), %eax
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L8:
	movzbl	1(%ebx), %eax
	movzbl	2(%ebx), %edx
	subl	$8, %esp
	.cfi_def_cfa_offset 56
	addl	$3, %ebx
	sall	$8, %eax
	orl	%edx, %eax
	movzwl	%ax, %eax
	pushl	%eax
	.cfi_def_cfa_offset 60
	pushl	%ebx
	.cfi_def_cfa_offset 64
	call	_ZN3GVM11Interpreter13enterFunctionEPKht
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	testl	%eax, %eax
	jne	.L387
	movl	_ZN3GVM11Interpreter14programCounterE, %ebx
	jmp	.L2
.L9:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	(%eax,%edx,4), %eax
	movl	%eax, %edx
	andl	$-1073741824, %edx
	cmpl	$-2147483648, %edx
	jne	.L332
	subl	$8, %esp
	.cfi_def_cfa_offset 56
	movzwl	%ax, %eax
	addl	$2, %ebx
	pushl	%eax
	.cfi_def_cfa_offset 60
	pushl	%ebx
	.cfi_def_cfa_offset 64
	call	_ZN3GVM11Interpreter13enterFunctionEPKht
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	testl	%eax, %eax
	jne	.L387
	movl	_ZN3GVM11Interpreter14programCounterE, %ebx
	jmp	.L2
.L7:
	movzbl	1(%ebx), %eax
	subl	$4, %esp
	.cfi_def_cfa_offset 52
	addl	$4, %ebx
	pushl	%eax
	.cfi_def_cfa_offset 56
	movzbl	-2(%ebx), %eax
	movzbl	-1(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	pushl	%eax
	.cfi_def_cfa_offset 60
	pushl	%ebx
	.cfi_def_cfa_offset 64
	call	_ZN3GVM11Interpreter12enterClosureEPKhsh
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	testl	%eax, %eax
	jne	.L387
	movl	_ZN3GVM11Interpreter14programCounterE, %ebx
	jmp	.L2
.L239:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	addl	$4, %ebx
	movzbl	-2(%ebx), %edi
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	4(%eax), %ecx
	movl	8(%eax), %eax
	vmovss	(%ecx,%edi,4), %xmm0
	movzbl	-1(%ebx), %ecx
	vmulss	(%edx), %xmm0, %xmm1
	leal	(%eax,%ecx,4), %eax
	vmovss	%xmm1, (%eax)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	vmulss	4(%edx), %xmm0, %xmm1
	vmovss	%xmm1, 4(%eax)
	vmulss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L245:
	addl	$4, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L246:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L247:
	addl	$4, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L248:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L252:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L253:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L254:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L255:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L256:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L257:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L258:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L259:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L260:
	addl	$4, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L262:
	addl	$3, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L263:
	addl	$3, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L264:
	addl	$3, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L265:
	addl	$3, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L379:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L380:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L381:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L382:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L383:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L384:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L385:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L386:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L353:
	movl	$10, %eax
	jmp	.L387
.L409:
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L408:
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L407:
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L404:
	movl	4(%edx), %edi
	cmpl	%edi, 4(%eax)
	jne	.L302
	movl	8(%edx), %edi
	cmpl	%edi, 8(%eax)
	jne	.L302
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L403:
	movl	4(%eax), %edi
	cmpl	%edi, 4(%edx)
	jne	.L303
	movl	8(%eax), %eax
	cmpl	%eax, 8(%edx)
	jne	.L303
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L402:
	movl	4(%edx), %edi
	cmpl	%edi, 4(%eax)
	jne	.L304
	movl	8(%edx), %edi
	cmpl	%edi, 8(%eax)
	jne	.L304
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L401:
	movl	4(%edx), %edi
	cmpl	%edi, 4(%eax)
	jne	.L305
	movl	8(%edx), %edi
	cmpl	%edi, 8(%eax)
	jne	.L305
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L400:
	movl	4(%eax), %edi
	cmpl	%edi, 4(%edx)
	jne	.L307
	movl	8(%eax), %eax
	cmpl	%eax, 8(%edx)
	jne	.L307
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L399:
	movl	4(%edx), %edi
	cmpl	%edi, 4(%eax)
	jne	.L309
	movl	8(%edx), %edi
	cmpl	%edi, 8(%eax)
	jne	.L309
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L261:
	addl	$4, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L410:
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L411:
	movzbl	2(%ebx), %eax
	movzbl	3(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L339:
	movl	$9, %eax
	jmp	.L387
.L332:
	movl	$7, %eax
	jmp	.L387
.L242:
	subl	$4, %esp
	.cfi_def_cfa_offset 52
	movl	%eax, %ebx
	pushl	%esi
	.cfi_def_cfa_offset 56
	pushl	$.LC0
	.cfi_def_cfa_offset 60
	pushl	$1
	.cfi_def_cfa_offset 64
	call	__printf_chk
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movl	%ebx, %eax
	jmp	.L387
.L392:
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	vmovss	%xmm0, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	vmovss	(%esp), %xmm1
	jmp	.L323
.L393:
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	vmovss	%xmm0, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	vmovss	(%esp), %xmm1
	jmp	.L321
.L391:
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	vmovss	%xmm0, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	vmovss	(%esp), %xmm1
	jmp	.L325
.L406:
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 64
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	vmovss	(%esp), %xmm0
	jmp	.L282
.L398:
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	vmovss	%xmm2, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	vmovss	(%edi), %xmm1
	vmovss	(%esp), %xmm3
	jmp	.L311
.L405:
	vmovss	%xmm0, 12(%esp)
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	vmovss	%xmm1, 24(%esp)
	vmovss	%xmm3, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	vmovss	12(%esp), %xmm0
	vmovss	(%esp), %xmm4
	vmovss	8(%esp), %xmm1
	vmovss	4(%esp), %xmm2
	jmp	.L300
.L394:
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	vmovss	%xmm0, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	vmovss	(%esp), %xmm1
	jmp	.L319
.L395:
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	vmovss	%xmm2, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	vmovss	(%edi), %xmm1
	vmovss	(%esp), %xmm3
	jmp	.L317
.L396:
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	vmovss	%xmm2, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	vmovss	(%edi), %xmm1
	vmovss	(%esp), %xmm3
	jmp	.L315
.L397:
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	vmovss	%xmm2, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	vmovss	(%edi), %xmm1
	vmovss	(%esp), %xmm3
	jmp	.L313
	.cfi_endproc
.LFE149:
	.size	_ZN3GVM11Interpreter3runEv, .-_ZN3GVM11Interpreter3runEv
	.section	.text.unlikely
.LCOLDE6:
	.text
.LHOTE6:
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC1:
	.long	805306368
	.align 4
.LC2:
	.long	1065353216
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC3:
	.long	2147483648
	.long	0
	.long	0
	.long	0
	.section	.rodata.cst4
	.align 4
.LC4:
	.long	3212836864
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
