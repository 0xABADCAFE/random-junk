	.file	"gvm_run.cpp"
	.section	.rodata.str1.4,"aMS",@progbits,1
	.align 4
.LC0:
	.string	"\nExecuted: %d instructions total.\n"
	.section	.text.unlikely,"ax",@progbits
	.align 2
.LCOLDB5:
	.text
.LHOTB5:
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
	movl	$-1, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	_ZN3GVM11Interpreter14programCounterE, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	movl	4(%eax), %ebp
	movl	8(%eax), %eax
	movl	%eax, 8(%esp)
	.p2align 4,,10
	.p2align 3
.L2:
	addl	$1, %esi
	cmpb	$-21, (%ebx)
	ja	.L340
.L376:
	movzbl	(%ebx), %eax
	jmp	*.L5(,%eax,4)
	.section	.rodata
	.align 4
	.align 4
.L5:
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
	.long	.L240
	.text
.L239:
	movzbl	1(%ebx), %eax
	movl	8(%esp), %ecx
	leal	0(%ebp,%eax,4), %edx
	movzbl	2(%ebx), %eax
	movss	(%ecx,%eax,4), %xmm0
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	3(%eax), %eax
	leal	(%edi,%eax,4), %eax
	.p2align 4,,10
	.p2align 3
.L339:
	movss	(%edx), %xmm1
	addl	$4, %ebx
	addl	$1, %esi
	mulss	%xmm0, %xmm1
	movss	%xmm1, (%eax)
	movss	4(%edx), %xmm1
	mulss	%xmm0, %xmm1
	movss	%xmm1, 4(%eax)
	mulss	8(%edx), %xmm0
	movss	%xmm0, 8(%eax)
	cmpb	$-21, (%ebx)
	jbe	.L376
.L340:
	movl	$2, %eax
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L238:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	2(%ebx), %ecx
	movsbl	1(%eax), %edx
	movsbl	3(%eax), %eax
	movss	0(%ebp,%ecx,4), %xmm0
	leal	(%edi,%edx,4), %edx
	leal	(%edi,%eax,4), %eax
	jmp	.L339
.L237:
	movzbl	1(%ebx), %eax
	movl	8(%esp), %ecx
	leal	0(%ebp,%eax,4), %edx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %eax
	movss	(%edi,%eax,4), %xmm0
	movzbl	3(%ebx), %eax
	leal	(%ecx,%eax,4), %eax
	jmp	.L339
.L236:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %eax
	leal	(%edi,%edx,4), %edx
	movss	(%edi,%eax,4), %xmm0
	movzbl	3(%ebx), %eax
	leal	0(%ebp,%eax,4), %eax
	jmp	.L339
.L235:
	movzbl	1(%ebx), %eax
	leal	0(%ebp,%eax,4), %edx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %ecx
	movsbl	3(%eax), %eax
	movss	(%edi,%ecx,4), %xmm0
	leal	(%edi,%eax,4), %eax
	jmp	.L339
.L234:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %ecx
	movsbl	3(%eax), %eax
	leal	(%edi,%edx,4), %edx
	movss	(%edi,%ecx,4), %xmm0
	leal	(%edi,%eax,4), %eax
	jmp	.L339
.L233:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %eax
	leal	(%edi,%eax,4), %edx
	movzbl	2(%ebx), %eax
	leal	0(%ebp,%eax,4), %eax
.L370:
	movl	%eax, 12(%esp)
	movzbl	3(%ebx), %ecx
	movl	8(%esp), %eax
	leal	(%eax,%ecx,4), %ecx
	movl	12(%esp), %eax
.L338:
	movss	4(%edx), %xmm0
	addl	$4, %ebx
	mulss	8(%eax), %xmm0
	movss	8(%edx), %xmm1
	mulss	4(%eax), %xmm1
	subss	%xmm1, %xmm0
	movss	%xmm0, (%ecx)
	movss	8(%edx), %xmm0
	movss	(%edx), %xmm1
	mulss	(%eax), %xmm0
	mulss	8(%eax), %xmm1
	subss	%xmm1, %xmm0
	movss	%xmm0, 4(%ecx)
	movss	(%edx), %xmm0
	movss	4(%edx), %xmm1
	mulss	4(%eax), %xmm0
	mulss	(%eax), %xmm1
	subss	%xmm1, %xmm0
	movss	%xmm0, 8(%ecx)
	jmp	.L2
.L232:
	movzbl	1(%ebx), %eax
	movl	8(%esp), %ecx
	leal	0(%ebp,%eax,4), %edx
	movzbl	2(%ebx), %eax
	leal	(%ecx,%eax,4), %eax
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	movl	%eax, 12(%esp)
	movsbl	3(%ecx), %ecx
	leal	(%edi,%ecx,4), %ecx
	jmp	.L338
.L231:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	movsbl	1(%ecx), %eax
	leal	(%edi,%eax,4), %edx
	movzbl	2(%ebx), %eax
	leal	0(%ebp,%eax,4), %eax
	movl	%eax, 12(%esp)
	movsbl	3(%ecx), %ecx
	leal	(%edi,%ecx,4), %ecx
	jmp	.L338
.L230:
	movzbl	1(%ebx), %eax
	leal	0(%ebp,%eax,4), %edx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %eax
	leal	(%edi,%eax,4), %eax
	jmp	.L370
.L229:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	3(%ebx), %ecx
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %eax
	leal	0(%ebp,%ecx,4), %ecx
	leal	(%edi,%edx,4), %edx
	leal	(%edi,%eax,4), %eax
	movl	%eax, 12(%esp)
	jmp	.L338
.L228:
	movzbl	1(%ebx), %eax
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	leal	0(%ebp,%eax,4), %edx
.L369:
	movsbl	2(%ecx), %eax
	leal	(%edi,%eax,4), %eax
	movl	%eax, 12(%esp)
	movsbl	3(%ecx), %ecx
	leal	(%edi,%ecx,4), %ecx
	jmp	.L338
.L227:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	movsbl	1(%ecx), %eax
	leal	(%edi,%eax,4), %edx
	jmp	.L369
.L226:
	movzbl	1(%ebx), %eax
	addl	$4, %ebx
	leal	0(%ebp,%eax,4), %ecx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movss	(%ecx), %xmm1
	movss	8(%ecx), %xmm0
	movsbl	2(%eax), %eax
	leal	(%edi,%eax,4), %edx
	movzbl	-1(%ebx), %eax
	movss	(%edx), %xmm2
	mulss	8(%edx), %xmm0
	mulss	%xmm1, %xmm2
	movss	4(%ecx), %xmm1
	mulss	4(%edx), %xmm1
	movl	8(%esp), %ecx
	addss	%xmm1, %xmm2
	addss	%xmm2, %xmm0
	movss	%xmm0, (%ecx,%eax,4)
	jmp	.L2
.L225:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %eax
	leal	(%edi,%edx,4), %ecx
	leal	(%edi,%eax,4), %edx
	movss	(%ecx), %xmm1
	movss	(%edx), %xmm2
	movss	8(%ecx), %xmm0
	mulss	%xmm1, %xmm2
	movss	4(%ecx), %xmm1
	mulss	4(%edx), %xmm1
	mulss	8(%edx), %xmm0
	movzbl	-1(%ebx), %eax
	addss	%xmm1, %xmm2
	addss	%xmm2, %xmm0
	movss	%xmm0, 0(%ebp,%eax,4)
	jmp	.L2
.L224:
	movzbl	1(%ebx), %eax
	addl	$4, %ebx
	leal	0(%ebp,%eax,4), %ecx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movss	(%ecx), %xmm1
	movss	8(%ecx), %xmm0
	movsbl	2(%eax), %edx
	movsbl	3(%eax), %eax
	leal	(%edi,%edx,4), %edx
	movss	(%edx), %xmm2
	mulss	8(%edx), %xmm0
	mulss	%xmm1, %xmm2
	movss	4(%ecx), %xmm1
	mulss	4(%edx), %xmm1
	addss	%xmm1, %xmm2
	addss	%xmm2, %xmm0
	movss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L223:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	1(%eax), %edx
	leal	(%edi,%edx,4), %ecx
	movsbl	2(%eax), %edx
	movss	(%ecx), %xmm1
	movss	8(%ecx), %xmm0
	movsbl	3(%eax), %eax
	leal	(%edi,%edx,4), %edx
	movss	(%edx), %xmm2
	mulss	8(%edx), %xmm0
	mulss	%xmm1, %xmm2
	movss	4(%ecx), %xmm1
	mulss	4(%edx), %xmm1
	addss	%xmm1, %xmm2
	addss	%xmm2, %xmm0
	movss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L222:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %eax
	leal	(%edi,%eax,4), %ecx
	movzbl	2(%ebx), %eax
	leal	0(%ebp,%eax,4), %eax
.L368:
	movl	%eax, 12(%esp)
	movl	8(%esp), %edx
	movzbl	3(%ebx), %eax
	leal	(%edx,%eax,4), %eax
	movl	12(%esp), %edx
.L337:
	movss	(%ecx), %xmm0
	addl	$4, %ebx
	subss	(%edx), %xmm0
	movss	%xmm0, (%eax)
	movss	4(%ecx), %xmm0
	subss	4(%edx), %xmm0
	movss	%xmm0, 4(%eax)
	movss	8(%ecx), %xmm0
	subss	8(%edx), %xmm0
	movss	%xmm0, 8(%eax)
	jmp	.L2
.L221:
	movzbl	1(%ebx), %eax
	movl	8(%esp), %edx
	leal	0(%ebp,%eax,4), %ecx
	movzbl	2(%ebx), %eax
	leal	(%edx,%eax,4), %eax
	movl	%eax, 12(%esp)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movl	12(%esp), %edx
	movsbl	3(%eax), %eax
	leal	(%edi,%eax,4), %eax
	jmp	.L337
.L220:
	movzbl	2(%ebx), %eax
	leal	0(%ebp,%eax,4), %eax
	movl	%eax, 12(%esp)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movl	12(%esp), %edx
	movsbl	1(%eax), %ecx
	movsbl	3(%eax), %eax
	leal	(%edi,%ecx,4), %ecx
	leal	(%edi,%eax,4), %eax
	jmp	.L337
.L219:
	movzbl	1(%ebx), %eax
	leal	0(%ebp,%eax,4), %ecx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %eax
	leal	(%edi,%eax,4), %eax
	jmp	.L368
.L218:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %eax
	leal	(%edi,%edx,4), %ecx
	leal	(%edi,%eax,4), %eax
	movl	%eax, 12(%esp)
	movzbl	3(%ebx), %eax
	movl	12(%esp), %edx
	leal	0(%ebp,%eax,4), %eax
	jmp	.L337
.L217:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %edx
	movsbl	3(%eax), %eax
	leal	(%edi,%edx,4), %ecx
	movl	%ecx, 12(%esp)
	movzbl	1(%ebx), %ecx
	leal	(%edi,%eax,4), %eax
	movl	12(%esp), %edx
	leal	0(%ebp,%ecx,4), %ecx
	jmp	.L337
.L216:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %edx
	leal	(%edi,%edx,4), %ecx
	movsbl	2(%eax), %edx
	movsbl	3(%eax), %eax
	leal	(%edi,%edx,4), %edx
	movl	%edx, 12(%esp)
	leal	(%edi,%eax,4), %eax
	jmp	.L337
.L215:
	movzbl	1(%ebx), %eax
	movl	8(%esp), %edx
	leal	0(%ebp,%eax,4), %ecx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %eax
	leal	(%edi,%eax,4), %eax
	movl	%eax, 12(%esp)
	movzbl	3(%ebx), %eax
	leal	(%edx,%eax,4), %eax
	movl	12(%esp), %edx
.L336:
	movss	(%ecx), %xmm0
	addl	$4, %ebx
	addss	(%edx), %xmm0
	movss	%xmm0, (%eax)
	movss	4(%ecx), %xmm0
	addss	4(%edx), %xmm0
	movss	%xmm0, 4(%eax)
	movss	8(%ecx), %xmm0
	addss	8(%edx), %xmm0
	movss	%xmm0, 8(%eax)
	jmp	.L2
.L214:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %eax
	leal	(%edi,%edx,4), %ecx
	leal	(%edi,%eax,4), %eax
	movl	%eax, 12(%esp)
	movzbl	3(%ebx), %eax
	movl	12(%esp), %edx
	leal	0(%ebp,%eax,4), %eax
	jmp	.L336
.L213:
	movzbl	1(%ebx), %eax
	leal	0(%ebp,%eax,4), %ecx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
.L367:
	movsbl	2(%eax), %edx
	leal	(%edi,%edx,4), %edx
	movl	%edx, 12(%esp)
	movsbl	3(%eax), %eax
	leal	(%edi,%eax,4), %eax
	jmp	.L336
.L212:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %edx
	leal	(%edi,%edx,4), %ecx
	jmp	.L367
.L211:
	movzbl	1(%ebx), %eax
	movzbl	2(%ebx), %edx
	movl	8(%esp), %ecx
	leal	0(%ebp,%eax,4), %eax
	movss	(%eax), %xmm2
	movss	4(%eax), %xmm1
	leal	(%ecx,%edx,4), %edx
	mulss	%xmm2, %xmm2
	movss	8(%eax), %xmm0
	mulss	%xmm1, %xmm1
	mulss	%xmm0, %xmm0
	addss	%xmm2, %xmm1
	addss	%xmm1, %xmm0
	sqrtss	%xmm0, %xmm1
	ucomiss	%xmm1, %xmm1
	jp	.L377
.L334:
	movss	%xmm1, (%edx)
	addl	$3, %ebx
	jmp	.L2
.L210:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	2(%ebx), %edx
	movsbl	1(%eax), %eax
	leal	0(%ebp,%edx,4), %edx
	leal	(%edi,%eax,4), %eax
	movss	(%eax), %xmm2
	movss	4(%eax), %xmm1
	mulss	%xmm2, %xmm2
	movss	8(%eax), %xmm0
	mulss	%xmm1, %xmm1
	mulss	%xmm0, %xmm0
	addss	%xmm2, %xmm1
	addss	%xmm1, %xmm0
	sqrtss	%xmm0, %xmm1
	ucomiss	%xmm1, %xmm1
	jp	.L378
.L332:
	movss	%xmm1, (%edx)
	addl	$3, %ebx
	jmp	.L2
.L209:
	movzbl	1(%ebx), %eax
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	leal	0(%ebp,%eax,4), %eax
	movss	(%eax), %xmm2
	movss	4(%eax), %xmm1
	mulss	%xmm2, %xmm2
	movss	8(%eax), %xmm0
	mulss	%xmm1, %xmm1
	movsbl	2(%edx), %edx
	mulss	%xmm0, %xmm0
	addss	%xmm2, %xmm1
	leal	(%edi,%edx,4), %edx
	addss	%xmm1, %xmm0
	sqrtss	%xmm0, %xmm1
	ucomiss	%xmm1, %xmm1
	jp	.L379
.L330:
	movss	%xmm1, (%edx)
	addl	$3, %ebx
	jmp	.L2
.L208:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	movsbl	1(%edx), %eax
	movsbl	2(%edx), %edx
	leal	(%edi,%eax,4), %eax
	movss	(%eax), %xmm2
	leal	(%edi,%edx,4), %edx
	movss	4(%eax), %xmm1
	mulss	%xmm2, %xmm2
	movss	8(%eax), %xmm0
	mulss	%xmm1, %xmm1
	mulss	%xmm0, %xmm0
	addss	%xmm2, %xmm1
	addss	%xmm1, %xmm0
	sqrtss	%xmm0, %xmm1
	ucomiss	%xmm1, %xmm1
	jp	.L380
.L328:
	movss	%xmm1, (%edx)
	addl	$3, %ebx
	jmp	.L2
.L207:
	movzbl	1(%ebx), %eax
	movzbl	2(%ebx), %edx
	movl	8(%esp), %ecx
	leal	0(%ebp,%eax,4), %eax
	leal	(%ecx,%edx,4), %edx
.L325:
	movss	(%eax), %xmm2
	movss	4(%eax), %xmm1
	movaps	%xmm2, %xmm3
	movss	8(%eax), %xmm0
	mulss	%xmm2, %xmm3
	mulss	%xmm1, %xmm1
	mulss	%xmm0, %xmm0
	addss	%xmm3, %xmm1
	addss	%xmm1, %xmm0
	sqrtss	%xmm0, %xmm1
	ucomiss	%xmm1, %xmm1
	jp	.L381
.L326:
	movss	.LC2, %xmm0
	addl	$3, %ebx
	divss	%xmm1, %xmm0
	mulss	%xmm0, %xmm2
	movss	%xmm2, (%edx)
	movss	4(%eax), %xmm1
	mulss	%xmm0, %xmm1
	movss	%xmm1, 4(%edx)
	mulss	8(%eax), %xmm0
	movss	%xmm0, 8(%edx)
	jmp	.L2
.L206:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	2(%ebx), %edx
	movsbl	1(%eax), %eax
	leal	0(%ebp,%edx,4), %edx
	leal	(%edi,%eax,4), %eax
	jmp	.L325
.L205:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	movzbl	1(%ebx), %eax
	movsbl	2(%edx), %edx
	leal	0(%ebp,%eax,4), %eax
	leal	(%edi,%edx,4), %edx
	jmp	.L325
.L204:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	movsbl	1(%edx), %eax
	movsbl	2(%edx), %edx
	leal	(%edi,%eax,4), %eax
	leal	(%edi,%edx,4), %edx
	jmp	.L325
.L203:
	movzbl	1(%ebx), %eax
	movl	8(%esp), %ecx
	leal	0(%ebp,%eax,4), %edx
	movzbl	2(%ebx), %eax
	leal	(%ecx,%eax,4), %eax
.L324:
	movss	(%edx), %xmm0
	addl	$3, %ebx
	xorps	.LC3, %xmm0
	movss	%xmm0, (%eax)
	movss	4(%edx), %xmm0
	xorps	.LC3, %xmm0
	movss	%xmm0, 4(%eax)
	movss	8(%edx), %xmm0
	xorps	.LC3, %xmm0
	movss	%xmm0, 8(%eax)
	jmp	.L2
.L202:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %eax
	leal	(%edi,%eax,4), %edx
	movzbl	2(%ebx), %eax
	leal	0(%ebp,%eax,4), %eax
	jmp	.L324
.L201:
	movzbl	1(%ebx), %eax
	leal	0(%ebp,%eax,4), %edx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %eax
	leal	(%edi,%eax,4), %eax
	jmp	.L324
.L200:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %eax
	leal	(%edi,%edx,4), %edx
	leal	(%edi,%eax,4), %eax
	jmp	.L324
.L199:
	movzbl	1(%ebx), %eax
	movl	8(%esp), %ecx
	leal	0(%ebp,%eax,4), %edx
	movzbl	2(%ebx), %eax
	leal	(%ecx,%eax,4), %eax
.L323:
	movl	(%edx), %ecx
	addl	$3, %ebx
	movl	%ecx, (%eax)
	movl	4(%edx), %ecx
	movl	%ecx, 4(%eax)
	movl	8(%edx), %edx
	movl	%edx, 8(%eax)
	jmp	.L2
.L198:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %eax
	leal	(%edi,%eax,4), %edx
	movzbl	2(%ebx), %eax
	leal	0(%ebp,%eax,4), %eax
	jmp	.L323
.L197:
	movzbl	1(%ebx), %eax
	leal	0(%ebp,%eax,4), %edx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %eax
	leal	(%edi,%eax,4), %eax
	jmp	.L323
.L196:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %eax
	leal	(%edi,%edx,4), %edx
	leal	(%edi,%eax,4), %eax
	jmp	.L323
.L195:
	movzbl	1(%ebx), %eax
	movzbl	2(%ebx), %edx
	movl	8(%esp), %ecx
	leal	0(%ebp,%eax,4), %eax
	leal	(%ecx,%edx,4), %edx
.L320:
	movl	(%eax), %ecx
	cmpl	%ecx, (%edx)
	je	.L382
.L321:
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L194:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	movzbl	1(%ebx), %eax
	movsbl	2(%edx), %edx
	leal	0(%ebp,%eax,4), %eax
	movl	(%eax), %ecx
	leal	(%edi,%edx,4), %edx
	cmpl	%ecx, (%edx)
	jne	.L321
.L382:
	movl	4(%eax), %ecx
	cmpl	%ecx, 4(%edx)
	jne	.L321
	movl	8(%eax), %eax
	cmpl	%eax, 8(%edx)
	jne	.L321
	addl	$5, %ebx
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L162:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	addl	$4, %ebx
	movzbl	-1(%ebx), %eax
	movsbl	1(%edx), %ecx
	movzbl	-2(%ebx), %edx
	movss	(%edi,%ecx,4), %xmm0
	movl	8(%esp), %ecx
	subss	0(%ebp,%edx,4), %xmm0
	movss	%xmm0, (%ecx,%eax,4)
	jmp	.L2
.L161:
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	-2(%ebx), %edx
	movss	0(%ebp,%ecx,4), %xmm0
	movl	8(%esp), %ecx
	movsbl	3(%eax), %eax
	subss	(%ecx,%edx,4), %xmm0
	movss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L160:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	addl	$4, %ebx
	movsbl	1(%edx), %ecx
	movsbl	3(%edx), %eax
	movzbl	-3(%ebx), %edx
	movss	(%edi,%ecx,4), %xmm0
	subss	0(%ebp,%edx,4), %xmm0
	movss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L159:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	addl	$4, %ebx
	movzbl	-3(%ebx), %ecx
	movzbl	-1(%ebx), %eax
	movsbl	2(%edx), %edx
	movss	0(%ebp,%ecx,4), %xmm0
	movl	8(%esp), %ecx
	subss	(%edi,%edx,4), %xmm0
	movss	%xmm0, (%ecx,%eax,4)
	jmp	.L2
.L158:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	addl	$4, %ebx
	movzbl	-1(%ebx), %eax
	movsbl	1(%edx), %ecx
	movsbl	2(%edx), %edx
	movss	(%edi,%ecx,4), %xmm0
	subss	(%edi,%edx,4), %xmm0
	movss	%xmm0, 0(%ebp,%eax,4)
	jmp	.L2
.L157:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	addl	$4, %ebx
	movzbl	-3(%ebx), %ecx
	movsbl	3(%edx), %eax
	movsbl	2(%edx), %edx
	movss	0(%ebp,%ecx,4), %xmm0
	subss	(%edi,%edx,4), %xmm0
	movss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L156:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	addl	$4, %ebx
	movsbl	1(%edx), %ecx
	movsbl	3(%edx), %eax
	movsbl	2(%edx), %edx
	movss	(%edi,%ecx,4), %xmm0
	subss	(%edi,%edx,4), %xmm0
	movss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L155:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	addl	$4, %ebx
	movzbl	-1(%ebx), %eax
	movsbl	2(%edx), %ecx
	movzbl	-3(%ebx), %edx
	movss	(%edi,%ecx,4), %xmm0
	movl	8(%esp), %ecx
	addss	0(%ebp,%edx,4), %xmm0
	movss	%xmm0, (%ecx,%eax,4)
	jmp	.L2
.L154:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	addl	$4, %ebx
	movzbl	-1(%ebx), %eax
	movsbl	1(%edx), %ecx
	movsbl	2(%edx), %edx
	movss	(%edi,%ecx,4), %xmm0
	addss	(%edi,%edx,4), %xmm0
	movss	%xmm0, 0(%ebp,%eax,4)
	jmp	.L2
.L153:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	addl	$4, %ebx
	movzbl	-3(%ebx), %ecx
	movsbl	3(%edx), %eax
	movsbl	2(%edx), %edx
	movss	0(%ebp,%ecx,4), %xmm0
	addss	(%edi,%edx,4), %xmm0
	movss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L152:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	addl	$4, %ebx
	movsbl	1(%edx), %ecx
	movsbl	3(%edx), %eax
	movsbl	2(%edx), %edx
	movss	(%edi,%ecx,4), %xmm0
	addss	(%edi,%edx,4), %xmm0
	movss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L151:
	movzbl	1(%ebx), %edx
	addl	$3, %ebx
	movzbl	-1(%ebx), %eax
	movl	8(%esp), %ecx
	movss	0(%ebp,%edx,4), %xmm0
	xorps	.LC3, %xmm0
	movss	%xmm0, (%ecx,%eax,4)
	jmp	.L2
.L150:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	addl	$3, %ebx
	movzbl	-1(%ebx), %eax
	movsbl	1(%edx), %edx
	movss	(%edi,%edx,4), %xmm0
	xorps	.LC3, %xmm0
	movss	%xmm0, 0(%ebp,%eax,4)
	jmp	.L2
.L149:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movzbl	-2(%ebx), %edx
	movsbl	2(%eax), %eax
	movss	0(%ebp,%edx,4), %xmm0
	xorps	.LC3, %xmm0
	movss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L148:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	addl	$3, %ebx
	movsbl	2(%edx), %eax
	movsbl	1(%edx), %edx
	movss	(%edi,%edx,4), %xmm0
	xorps	.LC3, %xmm0
	movss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L147:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	subl	$12, %esp
	.cfi_def_cfa_offset 76
	addl	$3, %ebx
	movsbl	2(%eax), %edx
	movsbl	1(%eax), %eax
	leal	(%edi,%edx,4), %edx
	movl	%edx, 28(%esp)
	pushl	(%edi,%eax,4)
	.cfi_def_cfa_offset 80
	call	acosf
	movl	32(%esp), %edx
	fstps	28(%esp)
	movss	28(%esp), %xmm0
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movss	%xmm0, (%edx)
	jmp	.L2
.L146:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	subl	$12, %esp
	.cfi_def_cfa_offset 76
	addl	$3, %ebx
	movsbl	1(%eax), %edx
	movl	%eax, 28(%esp)
	pushl	(%edi,%edx,4)
	.cfi_def_cfa_offset 80
	call	cosf
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movl	16(%esp), %eax
	fstps	12(%esp)
	movss	12(%esp), %xmm0
	movsbl	2(%eax), %eax
	movss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L145:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	subl	$12, %esp
	.cfi_def_cfa_offset 76
	addl	$3, %ebx
	movsbl	1(%eax), %edx
	movl	%eax, 28(%esp)
	pushl	(%edi,%edx,4)
	.cfi_def_cfa_offset 80
	call	sinf
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movl	16(%esp), %eax
	fstps	12(%esp)
	movss	12(%esp), %xmm0
	movsbl	2(%eax), %eax
	movss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L144:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movss	.LC2, %xmm1
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %eax
	movss	(%edi,%edx,4), %xmm0
	mulss	%xmm0, %xmm0
	divss	%xmm0, %xmm1
	movss	%xmm1, (%edi,%eax,4)
	jmp	.L2
.L143:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %edx
	movsbl	1(%eax), %eax
	leal	(%edi,%edx,4), %edx
	sqrtss	(%edi,%eax,4), %xmm0
	ucomiss	%xmm0, %xmm0
	jp	.L383
.L306:
	movss	%xmm0, (%edx)
	addl	$3, %ebx
	jmp	.L2
.L142:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movss	.LC2, %xmm0
	movsbl	2(%eax), %edx
	movsbl	1(%eax), %eax
	divss	(%edi,%eax,4), %xmm0
	movss	%xmm0, (%edi,%edx,4)
	jmp	.L2
.L141:
	movzbl	1(%ebx), %edx
	movzbl	2(%ebx), %eax
	movl	8(%esp), %ecx
	movss	0(%ebp,%edx,4), %xmm0
	ucomiss	(%ecx,%eax,4), %xmm0
	jbe	.L364
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L140:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %edx
	movzbl	2(%ebx), %eax
	movss	(%edi,%edx,4), %xmm0
	ucomiss	0(%ebp,%eax,4), %xmm0
	jbe	.L363
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L139:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	1(%ebx), %edx
	movsbl	2(%eax), %eax
	movss	0(%ebp,%edx,4), %xmm0
	ucomiss	(%edi,%eax,4), %xmm0
	jbe	.L362
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L138:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %eax
	movss	(%edi,%edx,4), %xmm0
	ucomiss	(%edi,%eax,4), %xmm0
	jbe	.L361
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L137:
	movzbl	1(%ebx), %edx
	movzbl	2(%ebx), %eax
	movl	8(%esp), %ecx
	movss	0(%ebp,%edx,4), %xmm0
	ucomiss	(%ecx,%eax,4), %xmm0
	jb	.L360
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L136:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %edx
	movzbl	2(%ebx), %eax
	movss	(%edi,%edx,4), %xmm0
	ucomiss	0(%ebp,%eax,4), %xmm0
	jb	.L359
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L135:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	1(%ebx), %edx
	movsbl	2(%eax), %eax
	movss	0(%ebp,%edx,4), %xmm0
	ucomiss	(%edi,%eax,4), %xmm0
	jb	.L358
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L134:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %eax
	movss	(%edi,%edx,4), %xmm0
	ucomiss	(%edi,%eax,4), %xmm0
	jb	.L357
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L133:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$2, %ebx
	movsbl	1(%eax), %eax
	leal	(%edi,%eax,4), %edx
	movl	%edx, 12(%esp)
	call	rand
	pxor	%xmm0, %xmm0
	movl	12(%esp), %edx
	cvtsi2ss	%eax, %xmm0
	mulss	.LC1, %xmm0
	movss	%xmm0, (%edx)
	jmp	.L2
.L132:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	3(%ebx), %edx
	movsbl	2(%eax), %ecx
	movzbl	1(%ebx), %eax
	movl	0(%ebp,%eax,4), %eax
	cmpl	%eax, (%edi,%ecx,4)
	cmovle	(%edi,%ecx,4), %eax
	addl	$4, %ebx
	movl	8(%esp), %ecx
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L131:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	1(%ebx), %edx
	movsbl	1(%eax), %ecx
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %eax
	cmpl	%eax, (%edi,%ecx,4)
	cmovle	(%edi,%ecx,4), %eax
	addl	$4, %ebx
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L178:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	subl	$8, %esp
	.cfi_def_cfa_offset 72
	addl	$4, %ebx
	movsbl	3(%eax), %edx
	movsbl	2(%eax), %eax
	leal	(%edi,%edx,4), %edx
	movl	%edx, 24(%esp)
	pushl	(%edi,%eax,4)
	.cfi_def_cfa_offset 76
	movzbl	-3(%ebx), %eax
	pushl	0(%ebp,%eax,4)
	.cfi_def_cfa_offset 80
	call	fmodf
	movl	32(%esp), %edx
	fstps	28(%esp)
	movss	28(%esp), %xmm0
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movss	%xmm0, (%edx)
	jmp	.L2
.L177:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	subl	$8, %esp
	.cfi_def_cfa_offset 72
	addl	$4, %ebx
	movl	16(%esp), %ecx
	movzbl	-1(%ebx), %eax
	movsbl	2(%edx), %edx
	leal	(%ecx,%eax,4), %eax
	movl	%eax, 24(%esp)
	pushl	(%edi,%edx,4)
	.cfi_def_cfa_offset 76
	movzbl	-3(%ebx), %edx
	pushl	0(%ebp,%edx,4)
	.cfi_def_cfa_offset 80
	call	fmodf
	movl	32(%esp), %eax
	fstps	28(%esp)
	movss	28(%esp), %xmm0
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movss	%xmm0, (%eax)
	jmp	.L2
.L176:
	movzbl	3(%ebx), %eax
	subl	$8, %esp
	.cfi_def_cfa_offset 72
	addl	$4, %ebx
	leal	0(%ebp,%eax,4), %edx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movl	%edx, 24(%esp)
	movsbl	2(%eax), %ecx
	pushl	(%edi,%ecx,4)
	.cfi_def_cfa_offset 76
	movsbl	1(%eax), %eax
	pushl	(%edi,%eax,4)
	.cfi_def_cfa_offset 80
	call	fmodf
	movl	32(%esp), %edx
	fstps	28(%esp)
	movss	28(%esp), %xmm0
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movss	%xmm0, (%edx)
	jmp	.L2
.L175:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	subl	$8, %esp
	.cfi_def_cfa_offset 72
	addl	$4, %ebx
	movsbl	3(%eax), %edx
	movsbl	2(%eax), %eax
	leal	(%edi,%edx,4), %edx
	movl	%edx, 24(%esp)
	pushl	(%edi,%eax,4)
	.cfi_def_cfa_offset 76
	movzbl	-3(%ebx), %eax
	pushl	0(%ebp,%eax,4)
	.cfi_def_cfa_offset 80
	call	fmodf
	movl	32(%esp), %edx
	fstps	28(%esp)
	movss	28(%esp), %xmm0
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movss	%xmm0, (%edx)
	jmp	.L2
.L174:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	subl	$8, %esp
	.cfi_def_cfa_offset 72
	addl	$4, %ebx
	movsbl	3(%eax), %edx
	movsbl	2(%eax), %ecx
	leal	(%edi,%edx,4), %edx
	movl	%edx, 24(%esp)
	pushl	(%edi,%ecx,4)
	.cfi_def_cfa_offset 76
	movsbl	1(%eax), %eax
	pushl	(%edi,%eax,4)
	.cfi_def_cfa_offset 80
	call	fmodf
	movl	32(%esp), %edx
	fstps	28(%esp)
	movss	28(%esp), %xmm0
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movss	%xmm0, (%edx)
	jmp	.L2
.L173:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	addl	$4, %ebx
	movzbl	-1(%ebx), %eax
	movsbl	1(%edx), %ecx
	movzbl	-2(%ebx), %edx
	movss	(%edi,%ecx,4), %xmm0
	movl	8(%esp), %ecx
	divss	0(%ebp,%edx,4), %xmm0
	movss	%xmm0, (%ecx,%eax,4)
	jmp	.L2
.L172:
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	-2(%ebx), %edx
	movss	0(%ebp,%ecx,4), %xmm0
	movsbl	3(%eax), %eax
	movl	8(%esp), %ecx
	divss	(%ecx,%edx,4), %xmm0
	movss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L171:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	addl	$4, %ebx
	movzbl	-3(%ebx), %ecx
	movsbl	3(%edx), %eax
	movsbl	2(%edx), %edx
	movss	0(%ebp,%ecx,4), %xmm0
	divss	(%edi,%edx,4), %xmm0
	movss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L170:
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	movzbl	-1(%ebx), %eax
	movss	0(%ebp,%ecx,4), %xmm0
	movsbl	2(%edx), %edx
	movl	8(%esp), %ecx
	divss	(%edi,%edx,4), %xmm0
	movss	%xmm0, (%ecx,%eax,4)
	jmp	.L2
.L169:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	addl	$4, %ebx
	movzbl	-1(%ebx), %eax
	movsbl	1(%edx), %ecx
	movsbl	2(%edx), %edx
	movss	(%edi,%ecx,4), %xmm0
	divss	(%edi,%edx,4), %xmm0
	movss	%xmm0, 0(%ebp,%eax,4)
	jmp	.L2
.L168:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	addl	$4, %ebx
	movzbl	-3(%ebx), %ecx
	movsbl	3(%edx), %eax
	movsbl	2(%edx), %edx
	movss	0(%ebp,%ecx,4), %xmm0
	divss	(%edi,%edx,4), %xmm0
	movss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L167:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	addl	$4, %ebx
	movsbl	1(%edx), %ecx
	movsbl	3(%edx), %eax
	movsbl	2(%edx), %edx
	movss	(%edi,%ecx,4), %xmm0
	divss	(%edi,%edx,4), %xmm0
	movss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L166:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	addl	$4, %ebx
	movzbl	-1(%ebx), %eax
	movsbl	2(%edx), %ecx
	movzbl	-3(%ebx), %edx
	movss	(%edi,%ecx,4), %xmm0
	movl	8(%esp), %ecx
	mulss	0(%ebp,%edx,4), %xmm0
	movss	%xmm0, (%ecx,%eax,4)
	jmp	.L2
.L165:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	addl	$4, %ebx
	movzbl	-1(%ebx), %eax
	movsbl	1(%edx), %ecx
	movsbl	2(%edx), %edx
	movss	(%edi,%ecx,4), %xmm0
	mulss	(%edi,%edx,4), %xmm0
	movss	%xmm0, 0(%ebp,%eax,4)
	jmp	.L2
.L164:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	addl	$4, %ebx
	movzbl	-3(%ebx), %ecx
	movsbl	3(%edx), %eax
	movsbl	2(%edx), %edx
	movss	0(%ebp,%ecx,4), %xmm0
	mulss	(%edi,%edx,4), %xmm0
	movss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L163:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	addl	$4, %ebx
	movsbl	1(%edx), %ecx
	movsbl	3(%edx), %eax
	movsbl	2(%edx), %edx
	movss	(%edi,%ecx,4), %xmm0
	mulss	(%edi,%edx,4), %xmm0
	movss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L186:
	movzbl	1(%ebx), %eax
	addl	$4, %ebx
	movss	0(%ebp,%eax,4), %xmm0
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %edx
	movsbl	3(%eax), %eax
	minss	(%edi,%edx,4), %xmm0
	movss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L185:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	1(%eax), %edx
	movss	(%edi,%edx,4), %xmm0
	movsbl	2(%eax), %edx
	movsbl	3(%eax), %eax
	minss	(%edi,%edx,4), %xmm0
	movss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L184:
	movzbl	1(%ebx), %eax
	addl	$4, %ebx
	movl	8(%esp), %ecx
	movss	0(%ebp,%eax,4), %xmm0
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %edx
	movzbl	-1(%ebx), %eax
	maxss	(%edi,%edx,4), %xmm0
	movss	%xmm0, (%ecx,%eax,4)
	jmp	.L2
.L183:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	1(%eax), %edx
	movss	(%edi,%edx,4), %xmm0
	movsbl	2(%eax), %edx
	movzbl	-3(%ebx), %eax
	maxss	(%edi,%edx,4), %xmm0
	movss	%xmm0, 0(%ebp,%eax,4)
	jmp	.L2
.L182:
	movzbl	1(%ebx), %eax
	addl	$4, %ebx
	movss	0(%ebp,%eax,4), %xmm0
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %edx
	movsbl	3(%eax), %eax
	maxss	(%edi,%edx,4), %xmm0
	movss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L181:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	1(%eax), %edx
	movss	(%edi,%edx,4), %xmm0
	movsbl	2(%eax), %edx
	movsbl	3(%eax), %eax
	maxss	(%edi,%edx,4), %xmm0
	movss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L180:
	movl	8(%esp), %ecx
	subl	$8, %esp
	.cfi_def_cfa_offset 72
	addl	$4, %ebx
	movzbl	-1(%ebx), %eax
	movzbl	-2(%ebx), %edx
	leal	(%ecx,%eax,4), %eax
	movl	%eax, 24(%esp)
	pushl	0(%ebp,%edx,4)
	.cfi_def_cfa_offset 76
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	movsbl	1(%edx), %edx
	pushl	(%edi,%edx,4)
	.cfi_def_cfa_offset 80
	call	fmodf
	movl	32(%esp), %eax
	fstps	28(%esp)
	movss	28(%esp), %xmm0
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movss	%xmm0, (%eax)
	jmp	.L2
.L179:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	subl	$8, %esp
	.cfi_def_cfa_offset 72
	addl	$4, %ebx
	movzbl	-2(%ebx), %edx
	movsbl	3(%eax), %eax
	leal	(%edi,%eax,4), %eax
	movl	%eax, 24(%esp)
	movl	16(%esp), %eax
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 76
	movzbl	-3(%ebx), %edx
	pushl	0(%ebp,%edx,4)
	.cfi_def_cfa_offset 80
	call	fmodf
	movl	32(%esp), %eax
	fstps	28(%esp)
	movss	28(%esp), %xmm0
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movss	%xmm0, (%eax)
	jmp	.L2
.L190:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	movsbl	1(%edx), %eax
	movsbl	2(%edx), %edx
	leal	(%edi,%eax,4), %eax
	leal	(%edi,%edx,4), %edx
.L318:
	movl	(%eax), %ecx
	cmpl	%ecx, (%edx)
	je	.L384
.L319:
	addl	$5, %ebx
	jmp	.L2
.L189:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %eax
	leal	(%edi,%eax,4), %edx
	movl	%edx, 20(%esp)
	call	rand
	pxor	%xmm3, %xmm3
	cvtsi2ss	%eax, %xmm3
	mulss	.LC1, %xmm3
	subss	.LC2, %xmm3
	movss	%xmm3, 16(%esp)
	call	rand
	pxor	%xmm0, %xmm0
	cvtsi2ss	%eax, %xmm0
	mulss	.LC1, %xmm0
	subss	.LC2, %xmm0
	movss	%xmm0, 12(%esp)
	call	rand
	pxor	%xmm1, %xmm1
	movss	16(%esp), %xmm3
	cvtsi2ss	%eax, %xmm1
	mulss	.LC1, %xmm1
	movss	12(%esp), %xmm0
	movaps	%xmm3, %xmm4
	mulss	%xmm3, %xmm4
	movl	20(%esp), %edx
	movaps	%xmm1, %xmm2
	subss	.LC2, %xmm2
	movaps	%xmm0, %xmm1
	mulss	%xmm0, %xmm1
	addss	%xmm1, %xmm4
	movaps	%xmm2, %xmm1
	mulss	%xmm2, %xmm1
	addss	%xmm1, %xmm4
	sqrtss	%xmm4, %xmm1
	ucomiss	%xmm1, %xmm1
	jp	.L385
.L316:
	movss	.LC2, %xmm5
	addl	$2, %ebx
	divss	%xmm1, %xmm5
	mulss	%xmm5, %xmm3
	movaps	%xmm5, %xmm1
	mulss	%xmm5, %xmm0
	mulss	%xmm2, %xmm1
	movss	%xmm3, (%edx)
	movss	%xmm0, 4(%edx)
	movss	%xmm1, 8(%edx)
	jmp	.L2
.L188:
	movzbl	1(%ebx), %eax
	addl	$4, %ebx
	movl	8(%esp), %ecx
	movss	0(%ebp,%eax,4), %xmm0
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %edx
	movzbl	-1(%ebx), %eax
	minss	(%edi,%edx,4), %xmm0
	movss	%xmm0, (%ecx,%eax,4)
	jmp	.L2
.L187:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	1(%eax), %edx
	movss	(%edi,%edx,4), %xmm0
	movsbl	2(%eax), %edx
	movzbl	-3(%ebx), %eax
	minss	(%edi,%edx,4), %xmm0
	movss	%xmm0, 0(%ebp,%eax,4)
	jmp	.L2
.L192:
	movl	8(%esp), %ecx
	movzbl	1(%ebx), %eax
	movzbl	2(%ebx), %edx
	leal	0(%ebp,%eax,4), %eax
	leal	(%ecx,%edx,4), %edx
	movl	(%eax), %ecx
	cmpl	%ecx, (%edx)
	jne	.L319
.L384:
	movl	4(%eax), %ecx
	cmpl	%ecx, 4(%edx)
	jne	.L319
	movl	8(%eax), %eax
	cmpl	%eax, 8(%edx)
	jne	.L319
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L191:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	movzbl	1(%ebx), %eax
	movsbl	2(%edx), %edx
	leal	0(%ebp,%eax,4), %eax
	leal	(%edi,%edx,4), %edx
	jmp	.L318
.L193:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	movsbl	1(%edx), %eax
	movsbl	2(%edx), %edx
	leal	(%edi,%eax,4), %eax
	leal	(%edi,%edx,4), %edx
	jmp	.L320
.L130:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	1(%ebx), %ecx
	movsbl	3(%eax), %edx
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %eax
	cmpl	%eax, 0(%ebp,%ecx,4)
	cmovle	0(%ebp,%ecx,4), %eax
	addl	$4, %ebx
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L129:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %ecx
	movsbl	3(%eax), %edx
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %eax
	cmpl	%eax, (%edi,%ecx,4)
	cmovle	(%edi,%ecx,4), %eax
	addl	$4, %ebx
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L128:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	3(%ebx), %edx
	movsbl	2(%eax), %ecx
	movzbl	1(%ebx), %eax
	movl	0(%ebp,%eax,4), %eax
	cmpl	%eax, (%edi,%ecx,4)
	cmovge	(%edi,%ecx,4), %eax
	addl	$4, %ebx
	movl	8(%esp), %ecx
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L127:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	1(%ebx), %edx
	movsbl	1(%eax), %ecx
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %eax
	cmpl	%eax, (%edi,%ecx,4)
	cmovge	(%edi,%ecx,4), %eax
	addl	$4, %ebx
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L126:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	1(%ebx), %ecx
	movsbl	3(%eax), %edx
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %eax
	cmpl	%eax, 0(%ebp,%ecx,4)
	cmovge	0(%ebp,%ecx,4), %eax
	addl	$4, %ebx
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L125:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %ecx
	movsbl	3(%eax), %edx
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %eax
	cmpl	%eax, (%edi,%ecx,4)
	cmovge	(%edi,%ecx,4), %eax
	addl	$4, %ebx
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L124:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movzbl	-3(%ebx), %eax
	movzbl	-1(%ebx), %edx
	movsbl	2(%ecx), %ecx
	movl	0(%ebp,%eax,4), %eax
	movl	(%edi,%ecx,4), %ecx
	shrl	%cl, %eax
	movl	8(%esp), %ecx
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L123:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movzbl	-1(%ebx), %edx
	movsbl	1(%ecx), %eax
	movsbl	2(%ecx), %ecx
	movl	(%edi,%eax,4), %eax
	movl	(%edi,%ecx,4), %ecx
	shrl	%cl, %eax
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L122:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movzbl	-3(%ebx), %eax
	movsbl	3(%ecx), %edx
	movsbl	2(%ecx), %ecx
	movl	0(%ebp,%eax,4), %eax
	movl	(%edi,%ecx,4), %ecx
	shrl	%cl, %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L121:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movsbl	1(%ecx), %eax
	movsbl	3(%ecx), %edx
	movsbl	2(%ecx), %ecx
	movl	(%edi,%eax,4), %eax
	movl	(%edi,%ecx,4), %ecx
	shrl	%cl, %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L120:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movzbl	-3(%ebx), %eax
	movzbl	-1(%ebx), %edx
	movsbl	2(%ecx), %ecx
	movl	0(%ebp,%eax,4), %eax
	movl	(%edi,%ecx,4), %ecx
	sall	%cl, %eax
	movl	8(%esp), %ecx
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L119:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movzbl	-1(%ebx), %edx
	movsbl	1(%ecx), %eax
	movsbl	2(%ecx), %ecx
	movl	(%edi,%eax,4), %eax
	movl	(%edi,%ecx,4), %ecx
	sall	%cl, %eax
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L118:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movzbl	-3(%ebx), %eax
	movsbl	3(%ecx), %edx
	movsbl	2(%ecx), %ecx
	movl	0(%ebp,%eax,4), %eax
	movl	(%edi,%ecx,4), %ecx
	sall	%cl, %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L117:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movsbl	1(%ecx), %eax
	movsbl	3(%ecx), %edx
	movsbl	2(%ecx), %ecx
	movl	(%edi,%eax,4), %eax
	movl	(%edi,%ecx,4), %ecx
	sall	%cl, %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L116:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %ecx
	movzbl	-1(%ebx), %edx
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %eax
	xorl	0(%ebp,%ecx,4), %eax
	movl	8(%esp), %ecx
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L115:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movzbl	-1(%ebx), %edx
	movsbl	1(%ecx), %eax
	movsbl	2(%ecx), %ecx
	movl	(%edi,%eax,4), %eax
	xorl	(%edi,%ecx,4), %eax
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L114:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movzbl	-3(%ebx), %eax
	movsbl	3(%ecx), %edx
	movsbl	2(%ecx), %ecx
	movl	0(%ebp,%eax,4), %eax
	xorl	(%edi,%ecx,4), %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L113:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movsbl	1(%ecx), %eax
	movsbl	3(%ecx), %edx
	movsbl	2(%ecx), %ecx
	movl	(%edi,%eax,4), %eax
	xorl	(%edi,%ecx,4), %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L112:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %ecx
	movzbl	-1(%ebx), %edx
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %eax
	orl	0(%ebp,%ecx,4), %eax
	movl	8(%esp), %ecx
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L111:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movzbl	-1(%ebx), %edx
	movsbl	1(%ecx), %eax
	movsbl	2(%ecx), %ecx
	movl	(%edi,%eax,4), %eax
	orl	(%edi,%ecx,4), %eax
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L110:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movzbl	-3(%ebx), %eax
	movsbl	3(%ecx), %edx
	movsbl	2(%ecx), %ecx
	movl	0(%ebp,%eax,4), %eax
	orl	(%edi,%ecx,4), %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L109:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movsbl	1(%ecx), %eax
	movsbl	3(%ecx), %edx
	movsbl	2(%ecx), %ecx
	movl	(%edi,%eax,4), %eax
	orl	(%edi,%ecx,4), %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L108:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %ecx
	movzbl	-1(%ebx), %edx
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %eax
	andl	0(%ebp,%ecx,4), %eax
	movl	8(%esp), %ecx
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L107:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movzbl	-1(%ebx), %edx
	movsbl	1(%ecx), %eax
	movsbl	2(%ecx), %ecx
	movl	(%edi,%eax,4), %eax
	andl	(%edi,%ecx,4), %eax
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L106:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movzbl	-3(%ebx), %eax
	movsbl	3(%ecx), %edx
	movsbl	2(%ecx), %ecx
	movl	0(%ebp,%eax,4), %eax
	andl	(%edi,%ecx,4), %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L105:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movsbl	1(%ecx), %eax
	movsbl	3(%ecx), %edx
	movsbl	2(%ecx), %ecx
	movl	(%edi,%eax,4), %eax
	andl	(%edi,%ecx,4), %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L104:
	movzbl	2(%ebx), %eax
	movl	0(%ebp,%eax,4), %ecx
	testl	%ecx, %ecx
	je	.L373
	movzbl	3(%ebx), %eax
	addl	$4, %ebx
	movl	%eax, 12(%esp)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %eax
	movl	(%edi,%eax,4), %eax
	cltd
	idivl	%ecx
	movl	8(%esp), %ecx
	movl	12(%esp), %eax
	movl	%edx, (%ecx,%eax,4)
	jmp	.L2
.L103:
	movzbl	2(%ebx), %eax
	movl	8(%esp), %ecx
	movl	(%ecx,%eax,4), %ecx
	testl	%ecx, %ecx
	je	.L373
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	3(%eax), %eax
	movl	%eax, 12(%esp)
	movzbl	-3(%ebx), %eax
	movl	0(%ebp,%eax,4), %eax
	cltd
	idivl	%ecx
	movl	12(%esp), %eax
	movl	%edx, (%edi,%eax,4)
	jmp	.L2
.L102:
	movzbl	2(%ebx), %eax
	movl	0(%ebp,%eax,4), %ecx
	testl	%ecx, %ecx
	je	.L373
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	3(%eax), %edx
	movsbl	1(%eax), %eax
	movl	%edx, 12(%esp)
	movl	(%edi,%eax,4), %eax
	cltd
	idivl	%ecx
	movl	12(%esp), %eax
	movl	%edx, (%edi,%eax,4)
	jmp	.L2
.L101:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %ecx
	testl	%ecx, %ecx
	je	.L373
	movzbl	3(%ebx), %eax
	addl	$4, %ebx
	movl	%eax, 12(%esp)
	movzbl	-3(%ebx), %eax
	movl	0(%ebp,%eax,4), %eax
	cltd
	idivl	%ecx
	movl	8(%esp), %ecx
	movl	12(%esp), %eax
	movl	%edx, (%ecx,%eax,4)
	jmp	.L2
.L100:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %edx
	movl	(%edi,%edx,4), %ecx
	testl	%ecx, %ecx
	je	.L373
	movsbl	1(%eax), %eax
	addl	$4, %ebx
	movzbl	-1(%ebx), %edx
	movl	(%edi,%eax,4), %eax
	movl	%edx, 12(%esp)
	cltd
	idivl	%ecx
	movl	12(%esp), %eax
	movl	%edx, 0(%ebp,%eax,4)
	jmp	.L2
.L99:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %edx
	movl	(%edi,%edx,4), %ecx
	testl	%ecx, %ecx
	je	.L373
	movsbl	3(%eax), %eax
	addl	$4, %ebx
	movl	%eax, 12(%esp)
	movzbl	-3(%ebx), %eax
	movl	0(%ebp,%eax,4), %eax
	cltd
	idivl	%ecx
	movl	12(%esp), %eax
	movl	%edx, (%edi,%eax,4)
	jmp	.L2
.L98:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %edx
	movl	(%edi,%edx,4), %ecx
	testl	%ecx, %ecx
	je	.L373
	movsbl	3(%eax), %edx
	addl	$4, %ebx
	movsbl	1(%eax), %eax
	movl	%edx, 12(%esp)
	movl	(%edi,%eax,4), %eax
	cltd
	idivl	%ecx
	movl	12(%esp), %eax
	movl	%edx, (%edi,%eax,4)
	jmp	.L2
.L97:
	movzbl	2(%ebx), %eax
	movl	0(%ebp,%eax,4), %ecx
	testl	%ecx, %ecx
	je	.L373
	movzbl	3(%ebx), %eax
	addl	$4, %ebx
	movl	%eax, 12(%esp)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %eax
	movl	(%edi,%eax,4), %eax
	cltd
	idivl	%ecx
	movl	8(%esp), %edx
	movl	12(%esp), %ecx
	movl	%eax, (%edx,%ecx,4)
	jmp	.L2
.L96:
	movzbl	2(%ebx), %eax
	movl	8(%esp), %ecx
	movl	(%ecx,%eax,4), %ecx
	testl	%ecx, %ecx
	je	.L373
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	3(%eax), %eax
	movl	%eax, 12(%esp)
	movzbl	-3(%ebx), %eax
	movl	0(%ebp,%eax,4), %eax
	cltd
	idivl	%ecx
	movl	12(%esp), %ecx
	movl	%eax, (%edi,%ecx,4)
	jmp	.L2
.L95:
	movzbl	2(%ebx), %eax
	movl	0(%ebp,%eax,4), %ecx
	testl	%ecx, %ecx
	je	.L373
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	3(%eax), %edx
	movsbl	1(%eax), %eax
	movl	%edx, 12(%esp)
	movl	(%edi,%eax,4), %eax
	cltd
	idivl	%ecx
	movl	12(%esp), %edx
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L94:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %ecx
	testl	%ecx, %ecx
	je	.L373
	movzbl	3(%ebx), %eax
	addl	$4, %ebx
	movl	%eax, 12(%esp)
	movzbl	-3(%ebx), %eax
	movl	0(%ebp,%eax,4), %eax
	cltd
	idivl	%ecx
	movl	8(%esp), %edx
	movl	12(%esp), %ecx
	movl	%eax, (%edx,%ecx,4)
	jmp	.L2
.L93:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %edx
	movl	(%edi,%edx,4), %ecx
	testl	%ecx, %ecx
	je	.L373
	movsbl	1(%eax), %eax
	addl	$4, %ebx
	movzbl	-1(%ebx), %edx
	movl	(%edi,%eax,4), %eax
	movl	%edx, 12(%esp)
	cltd
	idivl	%ecx
	movl	12(%esp), %edx
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L92:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %edx
	movl	(%edi,%edx,4), %ecx
	testl	%ecx, %ecx
	je	.L373
	movsbl	3(%eax), %eax
	addl	$4, %ebx
	movl	%eax, 12(%esp)
	movzbl	-3(%ebx), %eax
	movl	0(%ebp,%eax,4), %eax
	cltd
	idivl	%ecx
	movl	12(%esp), %ecx
	movl	%eax, (%edi,%ecx,4)
	jmp	.L2
.L91:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %edx
	movl	(%edi,%edx,4), %ecx
	testl	%ecx, %ecx
	je	.L373
	movsbl	3(%eax), %edx
	addl	$4, %ebx
	movsbl	1(%eax), %eax
	movl	%edx, 12(%esp)
	movl	(%edi,%eax,4), %eax
	cltd
	idivl	%ecx
	movl	12(%esp), %edx
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L90:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %ecx
	movzbl	-1(%ebx), %edx
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %eax
	imull	0(%ebp,%ecx,4), %eax
	movl	8(%esp), %ecx
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L89:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movzbl	-1(%ebx), %edx
	movsbl	1(%ecx), %eax
	movsbl	2(%ecx), %ecx
	movl	(%edi,%eax,4), %eax
	imull	(%edi,%ecx,4), %eax
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L88:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movzbl	-3(%ebx), %eax
	movsbl	3(%ecx), %edx
	movsbl	2(%ecx), %ecx
	movl	0(%ebp,%eax,4), %eax
	imull	(%edi,%ecx,4), %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L87:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movsbl	1(%ecx), %eax
	movsbl	3(%ecx), %edx
	movsbl	2(%ecx), %ecx
	movl	(%edi,%eax,4), %eax
	imull	(%edi,%ecx,4), %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L86:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movzbl	-2(%ebx), %ecx
	movzbl	-1(%ebx), %edx
	movsbl	1(%eax), %eax
	movl	(%edi,%eax,4), %eax
	subl	0(%ebp,%ecx,4), %eax
	movl	8(%esp), %ecx
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L85:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movl	8(%esp), %edx
	movsbl	3(%eax), %ecx
	movzbl	-3(%ebx), %eax
	movl	%ecx, 12(%esp)
	movzbl	-2(%ebx), %ecx
	movl	0(%ebp,%eax,4), %eax
	subl	(%edx,%ecx,4), %eax
	movl	12(%esp), %ecx
	movl	%eax, (%edi,%ecx,4)
	jmp	.L2
.L84:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %ecx
	movsbl	3(%eax), %edx
	movsbl	1(%eax), %eax
	movl	(%edi,%eax,4), %eax
	subl	0(%ebp,%ecx,4), %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L83:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movzbl	-3(%ebx), %eax
	movzbl	-1(%ebx), %edx
	movsbl	2(%ecx), %ecx
	movl	0(%ebp,%eax,4), %eax
	subl	(%edi,%ecx,4), %eax
	movl	8(%esp), %ecx
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L82:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movzbl	-1(%ebx), %edx
	movsbl	1(%ecx), %eax
	movsbl	2(%ecx), %ecx
	movl	(%edi,%eax,4), %eax
	subl	(%edi,%ecx,4), %eax
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L81:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movzbl	-3(%ebx), %eax
	movsbl	3(%ecx), %edx
	movsbl	2(%ecx), %ecx
	movl	0(%ebp,%eax,4), %eax
	subl	(%edi,%ecx,4), %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L80:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movsbl	1(%ecx), %eax
	movsbl	3(%ecx), %edx
	movsbl	2(%ecx), %ecx
	movl	(%edi,%eax,4), %eax
	subl	(%edi,%ecx,4), %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L79:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movzbl	-1(%ebx), %edx
	movsbl	2(%eax), %ecx
	movzbl	-3(%ebx), %eax
	movl	0(%ebp,%eax,4), %eax
	addl	(%edi,%ecx,4), %eax
	movl	8(%esp), %ecx
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L78:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movzbl	-1(%ebx), %edx
	movsbl	1(%eax), %ecx
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %eax
	addl	(%edi,%ecx,4), %eax
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L77:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %ecx
	movsbl	3(%eax), %edx
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %eax
	addl	0(%ebp,%ecx,4), %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L76:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	1(%eax), %ecx
	movsbl	3(%eax), %edx
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %eax
	addl	(%edi,%ecx,4), %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L75:
	movzbl	1(%ebx), %eax
	addl	$3, %ebx
	movzbl	-1(%ebx), %edx
	movl	8(%esp), %ecx
	movl	0(%ebp,%eax,4), %eax
	negl	%eax
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L74:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movzbl	-1(%ebx), %edx
	movsbl	1(%eax), %eax
	movl	(%edi,%eax,4), %eax
	negl	%eax
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L73:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movsbl	2(%eax), %edx
	movzbl	-2(%ebx), %eax
	movl	0(%ebp,%eax,4), %eax
	negl	%eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L72:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movsbl	2(%eax), %edx
	movsbl	1(%eax), %eax
	movl	(%edi,%eax,4), %eax
	negl	%eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L71:
	movzbl	1(%ebx), %eax
	addl	$3, %ebx
	movzbl	-1(%ebx), %edx
	movl	8(%esp), %ecx
	movl	0(%ebp,%eax,4), %eax
	notl	%eax
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L70:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movzbl	-1(%ebx), %edx
	movsbl	1(%eax), %eax
	movl	(%edi,%eax,4), %eax
	notl	%eax
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L69:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movsbl	2(%eax), %edx
	movzbl	-2(%ebx), %eax
	movl	0(%ebp,%eax,4), %eax
	notl	%eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L68:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movsbl	2(%eax), %edx
	movsbl	1(%eax), %eax
	movl	(%edi,%eax,4), %eax
	notl	%eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L67:
	movzbl	1(%ebx), %ecx
	movl	$1, %eax
	movzbl	2(%ebx), %edx
	sall	%cl, %eax
	testl	%eax, 0(%ebp,%edx,4)
	jne	.L275
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L66:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	1(%ebx), %ecx
	movsbl	2(%eax), %edx
	movl	$1, %eax
	sall	%cl, %eax
	testl	%eax, (%edi,%edx,4)
	jne	.L274
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L65:
	movzbl	1(%ebx), %ecx
	movl	$1, %eax
	movzbl	2(%ebx), %edx
	sall	%cl, %eax
	testl	%eax, 0(%ebp,%edx,4)
	je	.L273
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L64:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	1(%ebx), %ecx
	movsbl	2(%eax), %edx
	movl	$1, %eax
	sall	%cl, %eax
	testl	%eax, (%edi,%edx,4)
	je	.L272
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L63:
	movzbl	1(%ebx), %ecx
	movl	$-2, %eax
	addl	$3, %ebx
	movzbl	-1(%ebx), %edx
	roll	%cl, %eax
	andl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L62:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movzbl	-2(%ebx), %ecx
	movsbl	2(%eax), %edx
	movl	$-2, %eax
	roll	%cl, %eax
	andl	%eax, (%edi,%edx,4)
	jmp	.L2
.L61:
	movzbl	1(%ebx), %ecx
	movl	$1, %eax
	addl	$3, %ebx
	movzbl	-1(%ebx), %edx
	sall	%cl, %eax
	orl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L60:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movzbl	-2(%ebx), %ecx
	movsbl	2(%eax), %edx
	movl	$1, %eax
	sall	%cl, %eax
	orl	%eax, (%edi,%edx,4)
	jmp	.L2
.L59:
	movzbl	2(%ebx), %eax
	addl	$3, %ebx
	movsbl	-2(%ebx), %edx
	movl	8(%esp), %ecx
	movl	%edx, (%ecx,%eax,4)
	jmp	.L2
.L58:
	movzbl	2(%ebx), %eax
	addl	$3, %ebx
	movsbl	-2(%ebx), %edx
	movl	%edx, 0(%ebp,%eax,4)
	jmp	.L2
.L57:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movsbl	-2(%ebx), %edx
	movsbl	2(%eax), %eax
	movl	%edx, (%edi,%eax,4)
	jmp	.L2
.L56:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %eax
	leal	(%edi,%eax,4), %edx
	subl	$1, (%edx)
	js	.L271
	movzbl	2(%ebx), %eax
	movzbl	3(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L55:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %eax
	leal	(%edi,%eax,4), %edx
	subl	$1, (%edx)
	je	.L270
	movzbl	2(%ebx), %eax
	movzbl	3(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L54:
	movzbl	1(%ebx), %edx
	movzbl	2(%ebx), %eax
	movl	8(%esp), %ecx
	movl	(%ecx,%eax,4), %eax
	cmpl	%eax, 0(%ebp,%edx,4)
	jle	.L269
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L53:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %edx
	movzbl	2(%ebx), %eax
	movl	0(%ebp,%eax,4), %eax
	cmpl	%eax, (%edi,%edx,4)
	jle	.L268
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L52:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	1(%ebx), %edx
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %eax
	cmpl	%eax, 0(%ebp,%edx,4)
	jle	.L267
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L51:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %eax
	cmpl	%eax, (%edi,%edx,4)
	jle	.L266
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L50:
	movzbl	1(%ebx), %edx
	movzbl	2(%ebx), %eax
	movl	8(%esp), %ecx
	movl	(%ecx,%eax,4), %eax
	cmpl	%eax, 0(%ebp,%edx,4)
	jl	.L265
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L49:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %edx
	movzbl	2(%ebx), %eax
	movl	0(%ebp,%eax,4), %eax
	cmpl	%eax, (%edi,%edx,4)
	jl	.L264
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L48:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	1(%ebx), %edx
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %eax
	cmpl	%eax, 0(%ebp,%edx,4)
	jl	.L263
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L47:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %eax
	cmpl	%eax, (%edi,%edx,4)
	jl	.L262
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L46:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	pxor	%xmm0, %xmm0
	addl	$3, %ebx
	movsbl	2(%eax), %edx
	movsbl	1(%eax), %eax
	cvtsi2ss	(%edi,%eax,4), %xmm0
	movss	%xmm0, (%edi,%edx,4)
	jmp	.L2
.L45:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movsbl	2(%eax), %edx
	movsbl	1(%eax), %eax
	cvttss2si	(%edi,%eax,4), %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L44:
	movzbl	1(%ebx), %eax
	addl	$3, %ebx
	movl	8(%esp), %ecx
	movl	0(%ebp,%eax,4), %edx
	movzbl	-1(%ebx), %eax
	movl	%edx, (%ecx,%eax,4)
	jmp	.L2
.L43:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movsbl	1(%eax), %eax
	movl	(%edi,%eax,4), %edx
	movzbl	-1(%ebx), %eax
	movl	%edx, 0(%ebp,%eax,4)
	jmp	.L2
.L42:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movsbl	1(%eax), %eax
	movl	(%edi,%eax,4), %edx
	movzbl	-1(%ebx), %eax
	movl	%edx, 0(%ebp,%eax,4)
	jmp	.L2
.L41:
	movzbl	1(%ebx), %eax
	addl	$3, %ebx
	movl	8(%esp), %ecx
	movl	(%ecx,%eax,4), %edx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %eax
	movl	%edx, (%edi,%eax,4)
	jmp	.L2
.L40:
	movzbl	1(%ebx), %eax
	addl	$3, %ebx
	movl	0(%ebp,%eax,4), %edx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %eax
	movl	%edx, (%edi,%eax,4)
	jmp	.L2
.L39:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %eax
	movl	(%edi,%edx,4), %edx
	movl	%edx, (%edi,%eax,4)
	jmp	.L2
.L38:
	addl	$3, %ebx
	jmp	.L2
.L37:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$2, %ebx
	movl	8(%esp), %ecx
	movsbl	1(%eax), %eax
	movl	%ecx, (%edi,%eax,4)
	jmp	.L2
.L36:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$2, %ebx
	movsbl	1(%eax), %eax
	movl	%ebp, (%edi,%eax,4)
	jmp	.L2
.L35:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$2, %ebx
	movsbl	1(%eax), %eax
	leal	(%edi,%eax,4), %eax
	movl	%eax, %ecx
	movl	%eax, 8(%esp)
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	%ecx, 8(%eax)
	jmp	.L2
.L34:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$2, %ebx
	movsbl	1(%eax), %eax
	leal	(%edi,%eax,4), %ebp
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	%ebp, 4(%eax)
	jmp	.L2
.L33:
	movzbl	2(%ebx), %eax
	addl	$4, %ebx
	movzbl	-1(%ebx), %edx
	orl	$-2147483648, %eax
	movl	%eax, %ecx
	movzbl	-3(%ebx), %eax
	sall	$8, %eax
	orl	%ecx, %eax
	movl	8(%esp), %ecx
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L32:
	movzbl	1(%ebx), %eax
	addl	$4, %ebx
	movzbl	-1(%ebx), %edx
	sall	$8, %eax
	movl	%eax, %ecx
	movzbl	-2(%ebx), %eax
	orl	$-2147483648, %eax
	orl	%ecx, %eax
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L31:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	3(%eax), %edx
	movzbl	-3(%ebx), %eax
	sall	$8, %eax
	movl	%eax, %ecx
	movzbl	-2(%ebx), %eax
	orl	$-2147483648, %eax
	orl	%ecx, %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L30:
	movzwl	1(%ebx), %eax
	rolw	$8, %ax
	movzwl	%ax, %edx
	testw	%ax, %ax
	je	.L374
	movl	_ZN3GVM11Interpreter9dataTableE, %eax
	addl	$3, %ebx
	movl	(%eax,%edx,4), %eax
	movl	%eax, %ecx
	movl	%eax, 8(%esp)
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	%ecx, 8(%eax)
	jmp	.L2
.L29:
	movzwl	1(%ebx), %eax
	rolw	$8, %ax
	movzwl	%ax, %edx
	testw	%ax, %ax
	je	.L374
	movl	_ZN3GVM11Interpreter9dataTableE, %eax
	addl	$3, %ebx
	movl	(%eax,%edx,4), %ebp
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	%ebp, 4(%eax)
	jmp	.L2
.L28:
	movzwl	1(%ebx), %eax
	rolw	$8, %ax
	movzwl	%ax, %edx
	testw	%ax, %ax
	je	.L374
	movl	_ZN3GVM11Interpreter9dataTableE, %eax
	addl	$4, %ebx
	movl	8(%esp), %ecx
	movl	(%eax,%edx,4), %edx
	movzbl	-1(%ebx), %eax
	movl	%edx, (%ecx,%eax,4)
	jmp	.L2
.L27:
	movzwl	1(%ebx), %eax
	rolw	$8, %ax
	movzwl	%ax, %edx
	testw	%ax, %ax
	je	.L374
	movl	_ZN3GVM11Interpreter9dataTableE, %eax
	addl	$4, %ebx
	movl	(%eax,%edx,4), %edx
	movzbl	-1(%ebx), %eax
	movl	%edx, 0(%ebp,%eax,4)
	jmp	.L2
.L26:
	movzwl	1(%ebx), %eax
	rolw	$8, %ax
	movzwl	%ax, %edx
	testw	%ax, %ax
	je	.L374
	movl	_ZN3GVM11Interpreter9dataTableE, %eax
	addl	$4, %ebx
	movl	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	3(%eax), %eax
	movl	%edx, (%edi,%eax,4)
	jmp	.L2
.L25:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movzbl	-2(%ebx), %edx
	movl	8(%esp), %ecx
	movsbl	2(%eax), %eax
	leal	(%ecx,%edx,4), %edx
	movl	%edx, (%edi,%eax,4)
	jmp	.L2
.L24:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movzbl	-2(%ebx), %edx
	movsbl	2(%eax), %eax
	leal	0(%ebp,%edx,4), %edx
	movl	%edx, (%edi,%eax,4)
	jmp	.L2
.L23:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movsbl	2(%eax), %edx
	movsbl	1(%eax), %eax
	leal	(%edi,%eax,4), %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L22:
	movzbl	2(%ebx), %eax
	movl	8(%esp), %ecx
	movzbl	1(%ebx), %edx
	movl	(%ecx,%eax,4), %eax
	cmpl	%eax, 0(%ebp,%edx,4)
	je	.L386
	addl	$5, %ebx
	jmp	.L2
.L21:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	2(%ebx), %edx
	movsbl	1(%eax), %eax
	movl	(%edi,%eax,4), %eax
	cmpl	%eax, 0(%ebp,%edx,4)
	je	.L387
	addl	$5, %ebx
	jmp	.L2
.L20:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %edx
	movsbl	1(%eax), %eax
	movl	(%edi,%eax,4), %eax
	cmpl	%eax, (%edi,%edx,4)
	je	.L388
	addl	$5, %ebx
	jmp	.L2
.L19:
	movzbl	2(%ebx), %eax
	movl	0(%ebp,%eax,4), %eax
	testl	%eax, %eax
	je	.L253
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L18:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %eax
	movl	(%edi,%eax,4), %edx
	testl	%edx, %edx
	je	.L252
	movzbl	2(%ebx), %eax
	movzbl	3(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L17:
	movzbl	2(%ebx), %eax
	movl	0(%ebp,%eax,4), %ecx
	testl	%ecx, %ecx
	jne	.L251
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L16:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %eax
	movl	(%edi,%eax,4), %eax
	testl	%eax, %eax
	jne	.L250
	movzbl	2(%ebx), %eax
	movzbl	3(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L15:
	movl	8(%esp), %ecx
	movzbl	1(%ebx), %eax
	movl	(%ecx,%eax,4), %eax
	movl	%eax, 8(%esp)
	testl	%eax, %eax
	je	.L389
	addl	$3, %ebx
	jmp	.L2
.L14:
	movzbl	1(%ebx), %eax
	movl	0(%ebp,%eax,4), %ebp
	testl	%ebp, %ebp
	je	.L390
	addl	$3, %ebx
	jmp	.L2
.L13:
	call	_ZN3GVM11Interpreter12exitFunctionEv
	testl	%eax, %eax
	jne	.L391
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	movl	4(%eax), %ebp
	movl	8(%eax), %eax
	movl	%eax, 8(%esp)
	jmp	.L2
.L12:
	movzbl	1(%ebx), %eax
	subl	$12, %esp
	.cfi_def_cfa_offset 76
	movzbl	2(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	movzwl	%ax, %eax
	pushl	%eax
	.cfi_def_cfa_offset 80
	call	_ZN3GVM11Interpreter18invokeHostFunctionEt
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	testl	%eax, %eax
	jne	.L372
	addl	$3, %ebx
	jmp	.L2
.L11:
	movzbl	2(%ebx), %eax
	movl	0(%ebp,%eax,4), %eax
	movl	%eax, %edx
	andl	$-1073741824, %edx
	cmpl	$-2147483648, %edx
	jne	.L371
	subl	$8, %esp
	.cfi_def_cfa_offset 72
.L366:
	movzwl	%ax, %eax
	pushl	%eax
	.cfi_def_cfa_offset 76
	leal	3(%ebx), %eax
	pushl	%eax
	.cfi_def_cfa_offset 80
	call	_ZN3GVM11Interpreter13enterFunctionEPKht
	addl	$16, %esp
	.cfi_def_cfa_offset 64
.L242:
	testl	%eax, %eax
	jne	.L372
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	movl	4(%eax), %ebp
	movl	8(%eax), %eax
	movl	%eax, 8(%esp)
	jmp	.L2
.L10:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %eax
	movl	(%edi,%eax,4), %eax
	movl	%eax, %edx
	andl	$-1073741824, %edx
	cmpl	$-2147483648, %edx
	jne	.L371
	subl	$8, %esp
	.cfi_def_cfa_offset 72
	movzwl	%ax, %eax
	pushl	%eax
	.cfi_def_cfa_offset 76
	leal	2(%ebx), %eax
	pushl	%eax
	.cfi_def_cfa_offset 80
	call	_ZN3GVM11Interpreter13enterFunctionEPKht
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	jmp	.L242
.L9:
	movzbl	1(%ebx), %eax
	subl	$8, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 72
	movzbl	2(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	jmp	.L366
.L8:
	.cfi_restore_state
	movzbl	1(%ebx), %eax
	subl	$4, %esp
	.cfi_def_cfa_offset 68
	pushl	%eax
	.cfi_def_cfa_offset 72
	movzbl	2(%ebx), %eax
	movzbl	3(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	pushl	%eax
	.cfi_def_cfa_offset 76
	leal	4(%ebx), %eax
	pushl	%eax
	.cfi_def_cfa_offset 80
	call	_ZN3GVM11Interpreter12enterClosureEPKhsh
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	jmp	.L242
.L7:
	movzbl	1(%ebx), %eax
	movzbl	2(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L6:
	movsbl	1(%ebx), %eax
	addl	%eax, %ebx
	jmp	.L2
.L4:
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	movl	$2, %eax
.L3:
	addl	$44, %esp
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
.L240:
	.cfi_restore_state
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movl	8(%esp), %ecx
	movsbl	1(%eax), %eax
	leal	(%edi,%eax,4), %edx
	movzbl	2(%ebx), %eax
	movss	0(%ebp,%eax,4), %xmm0
	movzbl	3(%ebx), %eax
	leal	(%ecx,%eax,4), %eax
	jmp	.L339
.L250:
	addl	$4, %ebx
	jmp	.L2
.L251:
	addl	$5, %ebx
	jmp	.L2
.L252:
	addl	$4, %ebx
	jmp	.L2
.L253:
	addl	$5, %ebx
	jmp	.L2
.L262:
	addl	$5, %ebx
	jmp	.L2
.L263:
	addl	$5, %ebx
	jmp	.L2
.L264:
	addl	$5, %ebx
	jmp	.L2
.L265:
	addl	$5, %ebx
	jmp	.L2
.L266:
	addl	$5, %ebx
	jmp	.L2
.L267:
	addl	$5, %ebx
	jmp	.L2
.L268:
	addl	$5, %ebx
	jmp	.L2
.L269:
	addl	$5, %ebx
	jmp	.L2
.L270:
	addl	$4, %ebx
	jmp	.L2
.L272:
	addl	$3, %ebx
	jmp	.L2
.L273:
	addl	$3, %ebx
	jmp	.L2
.L274:
	addl	$3, %ebx
	jmp	.L2
.L275:
	addl	$3, %ebx
	jmp	.L2
.L357:
	addl	$5, %ebx
	jmp	.L2
.L358:
	addl	$5, %ebx
	jmp	.L2
.L359:
	addl	$5, %ebx
	jmp	.L2
.L360:
	addl	$5, %ebx
	jmp	.L2
.L361:
	addl	$5, %ebx
	jmp	.L2
.L362:
	addl	$5, %ebx
	jmp	.L2
.L363:
	addl	$5, %ebx
	jmp	.L2
.L364:
	addl	$5, %ebx
	jmp	.L2
.L373:
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	movl	$10, %eax
	jmp	.L3
.L387:
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L386:
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L388:
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L271:
	addl	$4, %ebx
	jmp	.L2
.L389:
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L390:
	movzbl	2(%ebx), %eax
	movzbl	3(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L374:
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	movl	$9, %eax
	jmp	.L3
.L372:
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L3
.L381:
	movl	%edx, 20(%esp)
	subl	$16, %esp
	.cfi_def_cfa_offset 80
	movl	%eax, 32(%esp)
	movss	%xmm0, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movl	16(%esp), %eax
	fstps	12(%esp)
	movl	20(%esp), %edx
	movss	12(%esp), %xmm1
	movss	(%eax), %xmm2
	jmp	.L326
.L371:
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	movl	$7, %eax
	jmp	.L3
.L391:
	subl	$4, %esp
	.cfi_def_cfa_offset 68
	movl	%eax, %edi
	pushl	%esi
	.cfi_def_cfa_offset 72
	pushl	$.LC0
	.cfi_def_cfa_offset 76
	pushl	$1
	.cfi_def_cfa_offset 80
	call	__printf_chk
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movl	%edi, %eax
	jmp	.L3
.L377:
	movl	%edx, 16(%esp)
	subl	$16, %esp
	.cfi_def_cfa_offset 80
	movss	%xmm0, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movl	16(%esp), %edx
	fstps	12(%esp)
	movss	12(%esp), %xmm1
	jmp	.L334
.L378:
	movl	%edx, 16(%esp)
	subl	$16, %esp
	.cfi_def_cfa_offset 80
	movss	%xmm0, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movl	16(%esp), %edx
	fstps	12(%esp)
	movss	12(%esp), %xmm1
	jmp	.L332
.L379:
	movl	%edx, 16(%esp)
	subl	$16, %esp
	.cfi_def_cfa_offset 80
	movss	%xmm0, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movl	16(%esp), %edx
	fstps	12(%esp)
	movss	12(%esp), %xmm1
	jmp	.L330
.L380:
	movl	%edx, 16(%esp)
	subl	$16, %esp
	.cfi_def_cfa_offset 80
	movss	%xmm0, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movl	16(%esp), %edx
	fstps	12(%esp)
	movss	12(%esp), %xmm1
	jmp	.L328
.L383:
	movl	%edx, 16(%esp)
	subl	$12, %esp
	.cfi_def_cfa_offset 76
	pushl	(%edi,%eax,4)
	.cfi_def_cfa_offset 80
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movl	16(%esp), %edx
	fstps	12(%esp)
	movss	12(%esp), %xmm0
	jmp	.L306
.L385:
	movss	%xmm2, 28(%esp)
	subl	$16, %esp
	.cfi_def_cfa_offset 80
	movss	%xmm0, 40(%esp)
	movss	%xmm3, 36(%esp)
	movl	%edx, 32(%esp)
	movss	%xmm4, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movl	16(%esp), %edx
	fstps	12(%esp)
	movss	28(%esp), %xmm2
	movss	12(%esp), %xmm1
	movss	24(%esp), %xmm0
	movss	20(%esp), %xmm3
	jmp	.L316
	.cfi_endproc
.LFE149:
	.size	_ZN3GVM11Interpreter3runEv, .-_ZN3GVM11Interpreter3runEv
	.section	.text.unlikely
.LCOLDE5:
	.text
.LHOTE5:
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
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
