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
	subl	$28, %esp
	.cfi_def_cfa_offset 48
	movl	_ZN3GVM11Interpreter14programCounterE, %ebx
	.p2align 4,,10
	.p2align 3
.L2:
	addl	$1, %esi
	cmpb	$-21, (%ebx)
	ja	.L325
.L385:
	movzbl	(%ebx), %eax
	jmp	*.L5(,%eax,4)
	.section	.rodata
	.align 4
	.align 4
.L5:
	.long	.L325
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
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	leal	(%edx,%ecx,4), %edx
	movzbl	2(%ebx), %ecx
	movss	(%eax,%ecx,4), %xmm0
	movsbl	3(%ebx), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%ecx,4), %eax
	.p2align 4,,10
	.p2align 3
.L324:
	movss	(%edx), %xmm1
	addl	$4, %ebx
	addl	$1, %esi
	mulss	%xmm0, %xmm1
	movss	%xmm1, (%eax)
	movss	4(%edx), %xmm1
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	mulss	%xmm0, %xmm1
	movss	%xmm1, 4(%eax)
	mulss	8(%edx), %xmm0
	movss	%xmm0, 8(%eax)
	cmpb	$-21, (%ebx)
	jbe	.L385
.L325:
	movl	$2, %eax
.L3:
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
	movzbl	2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	1(%ebx), %edx
	movl	4(%ecx), %ecx
	leal	(%eax,%edx,4), %edx
	movss	(%ecx,%edi,4), %xmm0
	movsbl	3(%ebx), %ecx
	leal	(%eax,%ecx,4), %eax
	jmp	.L324
.L236:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	movsbl	2(%ebx), %edi
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	leal	(%edx,%ecx,4), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movss	(%ecx,%edi,4), %xmm0
	movzbl	3(%ebx), %ecx
	leal	(%eax,%ecx,4), %eax
	jmp	.L324
.L235:
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	2(%ebx), %ecx
	movsbl	1(%ebx), %edx
	movss	(%eax,%ecx,4), %xmm0
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	3(%ebx), %ecx
	movl	4(%eax), %eax
	leal	(%eax,%ecx,4), %eax
	jmp	.L324
.L234:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	movsbl	2(%ebx), %ecx
	movl	4(%eax), %eax
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movss	(%eax,%ecx,4), %xmm0
	movsbl	3(%ebx), %ecx
	leal	(%eax,%ecx,4), %eax
	jmp	.L324
.L233:
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	2(%ebx), %ecx
	movsbl	1(%ebx), %edx
	movss	(%eax,%ecx,4), %xmm0
	movsbl	3(%ebx), %ecx
	leal	(%eax,%edx,4), %edx
	leal	(%eax,%ecx,4), %eax
	jmp	.L324
.L232:
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	movsbl	1(%ebx), %edx
	movzbl	2(%ebx), %edi
	leal	(%eax,%edx,4), %edx
	movl	4(%ecx), %eax
	movl	8(%ecx), %ecx
	leal	(%eax,%edi,4), %eax
	movzbl	3(%ebx), %edi
	leal	(%ecx,%edi,4), %ecx
	.p2align 4,,10
	.p2align 3
.L323:
	movss	4(%edx), %xmm0
	addl	$4, %ebx
	mulss	8(%eax), %xmm0
	movss	8(%edx), %xmm1
	mulss	4(%eax), %xmm1
	subss	%xmm1, %xmm0
	movss	%xmm0, (%ecx)
	movss	(%edx), %xmm1
	movss	8(%edx), %xmm0
	mulss	8(%eax), %xmm1
	mulss	(%eax), %xmm0
	subss	%xmm1, %xmm0
	movss	%xmm0, 4(%ecx)
	movss	(%edx), %xmm0
	movss	4(%edx), %xmm1
	mulss	4(%eax), %xmm0
	mulss	(%eax), %xmm1
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	subss	%xmm1, %xmm0
	movss	%xmm0, 8(%ecx)
	jmp	.L2
.L231:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	movsbl	3(%ebx), %edi
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	leal	(%edx,%ecx,4), %edx
	movzbl	2(%ebx), %ecx
	leal	(%eax,%ecx,4), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	leal	(%ecx,%edi,4), %ecx
	jmp	.L323
.L230:
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movsbl	1(%ebx), %eax
	movzbl	2(%ebx), %edi
	leal	(%ecx,%eax,4), %edx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	4(%eax), %eax
	leal	(%eax,%edi,4), %eax
	movsbl	3(%ebx), %edi
	leal	(%ecx,%edi,4), %ecx
	jmp	.L323
.L229:
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	movzbl	1(%ebx), %edx
	movsbl	2(%ebx), %edi
	movl	4(%ecx), %eax
	movl	8(%ecx), %ecx
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%edi,4), %eax
	movzbl	3(%ebx), %edi
	leal	(%ecx,%edi,4), %ecx
	jmp	.L323
.L228:
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	2(%ebx), %ecx
	movsbl	1(%ebx), %edx
	movzbl	3(%ebx), %edi
	leal	(%eax,%edx,4), %edx
	leal	(%eax,%ecx,4), %eax
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	movl	4(%ecx), %ecx
	leal	(%ecx,%edi,4), %ecx
	jmp	.L323
.L227:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movsbl	3(%ebx), %edi
	movl	4(%eax), %eax
	leal	(%eax,%edx,4), %edx
	movsbl	2(%ebx), %eax
	leal	(%ecx,%eax,4), %eax
	leal	(%ecx,%edi,4), %ecx
	jmp	.L323
.L226:
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movsbl	1(%ebx), %eax
	movsbl	3(%ebx), %edi
	leal	(%ecx,%eax,4), %edx
	movsbl	2(%ebx), %eax
	leal	(%ecx,%eax,4), %eax
	leal	(%ecx,%edi,4), %ecx
	jmp	.L323
.L225:
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	addl	$4, %ebx
	movzbl	-3(%ebx), %ecx
	movl	4(%edx), %eax
	movl	8(%edx), %edx
	leal	(%eax,%ecx,4), %edi
	movsbl	-2(%ebx), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movss	(%edi), %xmm1
	movss	8(%edi), %xmm0
	leal	(%eax,%ecx,4), %eax
	movzbl	-1(%ebx), %ecx
	movss	(%eax), %xmm2
	mulss	8(%eax), %xmm0
	mulss	%xmm1, %xmm2
	movss	4(%edi), %xmm1
	mulss	4(%eax), %xmm1
	addss	%xmm1, %xmm2
	addss	%xmm2, %xmm0
	movss	%xmm0, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L224:
	movsbl	1(%ebx), %edx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movzbl	-1(%ebx), %ecx
	leal	(%eax,%edx,4), %edi
	movsbl	-2(%ebx), %edx
	movss	(%edi), %xmm1
	movss	8(%edi), %xmm0
	leal	(%eax,%edx,4), %eax
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	movss	(%eax), %xmm2
	mulss	8(%eax), %xmm0
	mulss	%xmm1, %xmm2
	movss	4(%edi), %xmm1
	mulss	4(%eax), %xmm1
	movl	4(%edx), %edx
	addss	%xmm1, %xmm2
	addss	%xmm2, %xmm0
	movss	%xmm0, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L223:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %edx
	movsbl	-1(%ebx), %ecx
	movl	4(%eax), %eax
	leal	(%eax,%edx,4), %edi
	movsbl	-2(%ebx), %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movss	(%edi), %xmm1
	movss	8(%edi), %xmm0
	leal	(%edx,%eax,4), %eax
	movss	(%eax), %xmm2
	mulss	8(%eax), %xmm0
	mulss	%xmm1, %xmm2
	movss	4(%edi), %xmm1
	mulss	4(%eax), %xmm1
	addss	%xmm1, %xmm2
	addss	%xmm2, %xmm0
	movss	%xmm0, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L222:
	movsbl	1(%ebx), %edx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %ecx
	leal	(%eax,%edx,4), %edi
	movsbl	-2(%ebx), %edx
	movss	(%edi), %xmm1
	movss	8(%edi), %xmm0
	leal	(%eax,%edx,4), %edx
	movss	(%edx), %xmm2
	mulss	8(%edx), %xmm0
	mulss	%xmm1, %xmm2
	movss	4(%edi), %xmm1
	mulss	4(%edx), %xmm1
	addss	%xmm1, %xmm2
	addss	%xmm2, %xmm0
	movss	%xmm0, (%eax,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L221:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movzbl	2(%ebx), %edi
	leal	(%eax,%edx,4), %ecx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	leal	(%edx,%edi,4), %edx
	movzbl	3(%ebx), %edi
	leal	(%eax,%edi,4), %eax
	.p2align 4,,10
	.p2align 3
.L322:
	movss	(%ecx), %xmm0
	addl	$4, %ebx
	subss	(%edx), %xmm0
	movss	%xmm0, (%eax)
	movss	4(%ecx), %xmm0
	subss	4(%edx), %xmm0
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	movss	%xmm0, 4(%eax)
	movss	8(%ecx), %xmm0
	subss	8(%edx), %xmm0
	movss	%xmm0, 8(%eax)
	jmp	.L2
.L220:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	movsbl	3(%ebx), %edi
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	leal	(%edx,%ecx,4), %ecx
	movzbl	2(%ebx), %edx
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%edi,4), %eax
	jmp	.L322
.L219:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	2(%ebx), %edx
	movsbl	1(%ebx), %ecx
	movsbl	3(%ebx), %edi
	movl	4(%eax), %eax
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%ecx,4), %ecx
	leal	(%eax,%edi,4), %eax
	jmp	.L322
.L218:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	movsbl	2(%ebx), %edi
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	leal	(%edx,%ecx,4), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	leal	(%edx,%edi,4), %edx
	movzbl	3(%ebx), %edi
	leal	(%eax,%edi,4), %eax
	jmp	.L322
.L217:
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	1(%ebx), %edx
	movzbl	3(%ebx), %edi
	leal	(%eax,%edx,4), %ecx
	movsbl	2(%ebx), %edx
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	4(%eax), %eax
	leal	(%eax,%edi,4), %eax
	jmp	.L322
.L216:
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	3(%ebx), %ecx
	movsbl	2(%ebx), %edx
	movzbl	1(%ebx), %edi
	leal	(%eax,%edx,4), %edx
	leal	(%eax,%ecx,4), %eax
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	movl	4(%ecx), %ecx
	leal	(%ecx,%edi,4), %ecx
	jmp	.L322
.L215:
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	1(%ebx), %edx
	movsbl	3(%ebx), %edi
	leal	(%eax,%edx,4), %ecx
	movsbl	2(%ebx), %edx
	leal	(%eax,%edx,4), %edx
	leal	(%eax,%edi,4), %eax
	jmp	.L322
.L214:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	movsbl	2(%ebx), %edi
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	leal	(%edx,%ecx,4), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	leal	(%edx,%edi,4), %edx
	movzbl	3(%ebx), %edi
	leal	(%eax,%edi,4), %eax
.L321:
	movss	(%ecx), %xmm0
	addl	$4, %ebx
	addss	(%edx), %xmm0
	movss	%xmm0, (%eax)
	movss	4(%ecx), %xmm0
	addss	4(%edx), %xmm0
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	movss	%xmm0, 4(%eax)
	movss	8(%ecx), %xmm0
	addss	8(%edx), %xmm0
	movss	%xmm0, 8(%eax)
	jmp	.L2
.L213:
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	1(%ebx), %edx
	movzbl	3(%ebx), %edi
	leal	(%eax,%edx,4), %ecx
	movsbl	2(%ebx), %edx
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	4(%eax), %eax
	leal	(%eax,%edi,4), %eax
	jmp	.L321
.L212:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	movsbl	3(%ebx), %edi
	movl	4(%eax), %eax
	leal	(%eax,%edx,4), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	2(%ebx), %edx
	leal	(%eax,%edx,4), %edx
	leal	(%eax,%edi,4), %eax
	jmp	.L321
.L211:
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	1(%ebx), %edx
	movsbl	3(%ebx), %edi
	leal	(%eax,%edx,4), %ecx
	movsbl	2(%ebx), %edx
	leal	(%eax,%edx,4), %edx
	leal	(%eax,%edi,4), %eax
	jmp	.L321
.L210:
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	movzbl	1(%ebx), %ecx
	movl	4(%edx), %eax
	movl	8(%edx), %edx
	leal	(%eax,%ecx,4), %eax
	movzbl	2(%ebx), %ecx
	movss	(%eax), %xmm2
	movss	4(%eax), %xmm1
	mulss	%xmm2, %xmm2
	movss	8(%eax), %xmm0
	mulss	%xmm1, %xmm1
	mulss	%xmm0, %xmm0
	leal	(%edx,%ecx,4), %ebx
	addss	%xmm2, %xmm1
	addss	%xmm1, %xmm0
	sqrtss	%xmm0, %xmm1
	ucomiss	%xmm1, %xmm1
	jp	.L386
.L319:
	movss	%xmm1, (%ebx)
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
	movss	(%eax), %xmm2
	movss	4(%eax), %xmm1
	mulss	%xmm2, %xmm2
	movss	8(%eax), %xmm0
	mulss	%xmm1, %xmm1
	movl	4(%edx), %edx
	mulss	%xmm0, %xmm0
	addss	%xmm2, %xmm1
	leal	(%edx,%ecx,4), %ebx
	addss	%xmm1, %xmm0
	sqrtss	%xmm0, %xmm1
	ucomiss	%xmm1, %xmm1
	jp	.L387
.L317:
	movss	%xmm1, (%ebx)
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
	movss	(%eax), %xmm2
	movss	4(%eax), %xmm1
	mulss	%xmm2, %xmm2
	movss	8(%eax), %xmm0
	mulss	%xmm1, %xmm1
	mulss	%xmm0, %xmm0
	leal	(%edx,%ecx,4), %ebx
	addss	%xmm2, %xmm1
	addss	%xmm1, %xmm0
	sqrtss	%xmm0, %xmm1
	ucomiss	%xmm1, %xmm1
	jp	.L388
.L315:
	movss	%xmm1, (%ebx)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	3(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L207:
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movsbl	1(%ebx), %eax
	movsbl	2(%ebx), %ecx
	leal	(%edx,%eax,4), %eax
	movss	(%eax), %xmm2
	leal	(%edx,%ecx,4), %ebx
	movss	4(%eax), %xmm1
	mulss	%xmm2, %xmm2
	movss	8(%eax), %xmm0
	mulss	%xmm1, %xmm1
	mulss	%xmm0, %xmm0
	addss	%xmm2, %xmm1
	addss	%xmm1, %xmm0
	sqrtss	%xmm0, %xmm1
	ucomiss	%xmm1, %xmm1
	jp	.L389
.L313:
	movss	%xmm1, (%ebx)
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
	leal	(%eax,%edx,4), %ebx
.L310:
	movss	(%edi), %xmm2
	movss	4(%edi), %xmm1
	movaps	%xmm2, %xmm3
	movss	8(%edi), %xmm0
	mulss	%xmm2, %xmm3
	mulss	%xmm1, %xmm1
	mulss	%xmm0, %xmm0
	addss	%xmm3, %xmm1
	addss	%xmm1, %xmm0
	sqrtss	%xmm0, %xmm1
	ucomiss	%xmm1, %xmm1
	jp	.L390
.L311:
	movss	.LC2, %xmm0
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	divss	%xmm1, %xmm0
	mulss	%xmm0, %xmm2
	movss	%xmm2, (%ebx)
	movss	4(%edi), %xmm1
	mulss	%xmm0, %xmm1
	movss	%xmm1, 4(%ebx)
	mulss	8(%edi), %xmm0
	movss	%xmm0, 8(%ebx)
	leal	3(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L205:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%edx,4), %edi
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	2(%ebx), %edx
	movl	4(%eax), %eax
	leal	(%eax,%edx,4), %ebx
	jmp	.L310
.L204:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	movl	4(%eax), %eax
	leal	(%eax,%edx,4), %edi
	movsbl	2(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%edx,4), %ebx
	jmp	.L310
.L203:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%edx,4), %edi
	movsbl	2(%ebx), %edx
	leal	(%eax,%edx,4), %ebx
	jmp	.L310
.L202:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	leal	(%edx,%ecx,4), %edx
	movzbl	2(%ebx), %ecx
	leal	(%eax,%ecx,4), %eax
.L309:
	addl	$3, %ebx
	movss	(%edx), %xmm0
	xorps	.LC3, %xmm0
	movss	%xmm0, (%eax)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	movss	4(%edx), %xmm0
	xorps	.LC3, %xmm0
	movss	%xmm0, 4(%eax)
	movss	8(%edx), %xmm0
	xorps	.LC3, %xmm0
	movss	%xmm0, 8(%eax)
	jmp	.L2
.L201:
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	1(%ebx), %edx
	movzbl	2(%ebx), %ecx
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	4(%eax), %eax
	leal	(%eax,%ecx,4), %eax
	jmp	.L309
.L200:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	movsbl	2(%ebx), %ecx
	movl	4(%eax), %eax
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%ecx,4), %eax
	jmp	.L309
.L199:
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	1(%ebx), %edx
	movsbl	2(%ebx), %ecx
	leal	(%eax,%edx,4), %edx
	leal	(%eax,%ecx,4), %eax
	jmp	.L309
.L198:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	leal	(%edx,%ecx,4), %edx
	movzbl	2(%ebx), %ecx
	leal	(%eax,%ecx,4), %eax
.L308:
	movl	(%edx), %ecx
	addl	$3, %ebx
	movl	%ecx, (%eax)
	movl	4(%edx), %ecx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	movl	%ecx, 4(%eax)
	movl	8(%edx), %edx
	movl	%edx, 8(%eax)
	jmp	.L2
.L197:
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	1(%ebx), %edx
	movzbl	2(%ebx), %ecx
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	4(%eax), %eax
	leal	(%eax,%ecx,4), %eax
	jmp	.L308
.L196:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edx
	movsbl	2(%ebx), %ecx
	movl	4(%eax), %eax
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%ecx,4), %eax
	jmp	.L308
.L195:
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	1(%ebx), %edx
	movsbl	2(%ebx), %ecx
	leal	(%eax,%edx,4), %edx
	leal	(%eax,%ecx,4), %eax
	jmp	.L308
.L194:
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	movzbl	1(%ebx), %ecx
	movl	4(%edx), %eax
	movl	8(%edx), %edx
	leal	(%eax,%ecx,4), %eax
	movzbl	2(%ebx), %ecx
	leal	(%edx,%ecx,4), %edx
.L305:
	movl	(%eax), %edi
	cmpl	%edi, (%edx)
	je	.L391
.L306:
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
	jne	.L306
.L391:
	movl	4(%eax), %edi
	cmpl	%edi, 4(%edx)
	jne	.L306
	movl	8(%eax), %eax
	cmpl	%eax, 8(%edx)
	jne	.L306
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L192:
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movsbl	1(%ebx), %eax
	movsbl	2(%ebx), %ecx
	leal	(%edx,%eax,4), %eax
	leal	(%edx,%ecx,4), %edx
	jmp	.L305
.L191:
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	movzbl	1(%ebx), %ecx
	movl	4(%edx), %eax
	movl	8(%edx), %edx
	leal	(%eax,%ecx,4), %eax
	movzbl	2(%ebx), %ecx
	leal	(%edx,%ecx,4), %edx
.L303:
	movl	(%eax), %edi
	cmpl	%edi, (%edx)
	je	.L392
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
	jne	.L304
.L392:
	movl	4(%eax), %edi
	cmpl	%edi, 4(%edx)
	jne	.L304
	movl	8(%eax), %eax
	cmpl	%eax, 8(%edx)
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
.L188:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%edx,4), %ebx
	call	rand
	pxor	%xmm3, %xmm3
	cvtsi2ss	%eax, %xmm3
	mulss	.LC1, %xmm3
	subss	.LC2, %xmm3
	movss	%xmm3, 4(%esp)
	call	rand
	pxor	%xmm0, %xmm0
	cvtsi2ss	%eax, %xmm0
	mulss	.LC1, %xmm0
	subss	.LC2, %xmm0
	movss	%xmm0, (%esp)
	call	rand
	pxor	%xmm1, %xmm1
	movss	4(%esp), %xmm3
	cvtsi2ss	%eax, %xmm1
	mulss	.LC1, %xmm1
	movss	(%esp), %xmm0
	movaps	%xmm3, %xmm4
	mulss	%xmm3, %xmm4
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
	jp	.L393
.L301:
	movss	.LC2, %xmm5
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	divss	%xmm1, %xmm5
	mulss	%xmm5, %xmm3
	movaps	%xmm5, %xmm1
	mulss	%xmm5, %xmm0
	mulss	%xmm2, %xmm1
	movss	%xmm3, (%ebx)
	movss	%xmm0, 4(%ebx)
	movss	%xmm1, 8(%ebx)
	leal	2(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L187:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	movss	(%edx,%ecx,4), %xmm0
	movsbl	-2(%ebx), %ecx
	movzbl	-1(%ebx), %edx
	minss	(%edi,%ecx,4), %xmm0
	movss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L189:
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movsbl	1(%ebx), %eax
	movsbl	2(%ebx), %ecx
	leal	(%edx,%eax,4), %eax
	leal	(%edx,%ecx,4), %edx
	jmp	.L303
.L186:
	movsbl	1(%ebx), %ecx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movsbl	-2(%ebx), %edi
	movzbl	%cl, %eax
	movss	(%edx,%ecx,4), %xmm0
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	minss	(%edx,%edi,4), %xmm0
	movl	4(%ecx), %ecx
	movss	%xmm0, (%ecx,%eax,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L185:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %edx
	movsbl	-2(%ebx), %ecx
	movl	4(%eax), %eax
	movss	(%eax,%edx,4), %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edx
	minss	(%eax,%ecx,4), %xmm0
	movss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L184:
	movsbl	1(%ebx), %edx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-2(%ebx), %ecx
	movss	(%eax,%edx,4), %xmm0
	movsbl	-1(%ebx), %edx
	minss	(%eax,%ecx,4), %xmm0
	movss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L183:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	movss	(%edx,%ecx,4), %xmm0
	movsbl	-2(%ebx), %ecx
	movzbl	-1(%ebx), %edx
	maxss	(%edi,%ecx,4), %xmm0
	movss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L182:
	movsbl	1(%ebx), %ecx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movsbl	-2(%ebx), %edi
	movzbl	%cl, %eax
	movss	(%edx,%ecx,4), %xmm0
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	maxss	(%edx,%edi,4), %xmm0
	movl	4(%ecx), %ecx
	movss	%xmm0, (%ecx,%eax,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L181:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %edx
	movsbl	-2(%ebx), %ecx
	movl	4(%eax), %eax
	movss	(%eax,%edx,4), %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edx
	maxss	(%eax,%ecx,4), %xmm0
	movss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L180:
	movsbl	1(%ebx), %edx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-2(%ebx), %ecx
	movss	(%eax,%edx,4), %xmm0
	movsbl	-1(%ebx), %edx
	maxss	(%eax,%ecx,4), %xmm0
	movss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L179:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	subl	$8, %esp
	.cfi_def_cfa_offset 56
	movzbl	3(%ebx), %ecx
	movl	8(%eax), %edx
	movl	4(%eax), %eax
	leal	(%edx,%ecx,4), %edi
	movzbl	2(%ebx), %edx
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 60
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	1(%ebx), %edx
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 64
	call	fmodf
	fstps	16(%esp)
	movss	16(%esp), %xmm0
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movss	%xmm0, (%edi)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	4(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L178:
	movsbl	3(%ebx), %edx
	subl	$8, %esp
	.cfi_def_cfa_offset 56
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
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
	movss	16(%esp), %xmm0
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movss	%xmm0, (%edi)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	4(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L177:
	movsbl	3(%ebx), %edx
	subl	$8, %esp
	.cfi_def_cfa_offset 56
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
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
	movss	16(%esp), %xmm0
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movss	%xmm0, (%edi)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	4(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L176:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	subl	$8, %esp
	.cfi_def_cfa_offset 56
	movzbl	3(%ebx), %ecx
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
	movss	16(%esp), %xmm0
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movss	%xmm0, (%edi)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	4(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L175:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	subl	$8, %esp
	.cfi_def_cfa_offset 56
	movzbl	3(%ebx), %edx
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
	movss	16(%esp), %xmm0
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movss	%xmm0, (%edi)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	4(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L174:
	movsbl	3(%ebx), %edx
	subl	$8, %esp
	.cfi_def_cfa_offset 56
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
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
	movss	16(%esp), %xmm0
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movss	%xmm0, (%edi)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	4(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L173:
	movsbl	3(%ebx), %edx
	subl	$8, %esp
	.cfi_def_cfa_offset 56
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%edx,4), %edi
	movsbl	2(%ebx), %edx
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 60
	movsbl	1(%ebx), %edx
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 64
	call	fmodf
	fstps	16(%esp)
	movss	16(%esp), %xmm0
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movss	%xmm0, (%edi)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	4(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L172:
	movzbl	3(%ebx), %eax
	addl	$4, %ebx
	movsbl	-3(%ebx), %ebp
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	movzbl	-2(%ebx), %ecx
	movl	%eax, (%esp)
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	8(%edx), %edi
	movl	4(%edx), %edx
	movss	(%eax,%ebp,4), %xmm0
	movl	(%esp), %eax
	divss	(%edx,%ecx,4), %xmm0
	movss	%xmm0, (%edi,%eax,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L171:
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	addl	$4, %ebx
	movzbl	-3(%ebx), %ebp
	movzbl	-2(%ebx), %ecx
	movsbl	-1(%ebx), %eax
	movl	4(%edx), %edi
	movl	8(%edx), %edx
	movss	(%edi,%ebp,4), %xmm0
	divss	(%edx,%ecx,4), %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movss	%xmm0, (%edx,%eax,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L170:
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	addl	$4, %ebx
	movzbl	-3(%ebx), %ebp
	movsbl	-1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	4(%ecx), %edi
	movsbl	-2(%ebx), %ecx
	movss	(%edi,%ebp,4), %xmm0
	divss	(%eax,%ecx,4), %xmm0
	movss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L169:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %ebp
	movsbl	-2(%ebx), %edi
	movzbl	-1(%ebx), %ecx
	movl	8(%eax), %edx
	movl	4(%eax), %eax
	movss	(%eax,%ebp,4), %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	divss	(%eax,%edi,4), %xmm0
	movss	%xmm0, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L168:
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	addl	$4, %ebx
	movsbl	-3(%ebx), %ebp
	movsbl	-2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movzbl	-1(%ebx), %ecx
	movl	4(%edx), %edx
	movss	(%eax,%ebp,4), %xmm0
	divss	(%eax,%edi,4), %xmm0
	movss	%xmm0, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L167:
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	addl	$4, %ebx
	movzbl	-3(%ebx), %ebp
	movsbl	-1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	4(%ecx), %edi
	movsbl	-2(%ebx), %ecx
	movss	(%edi,%ebp,4), %xmm0
	divss	(%eax,%ecx,4), %xmm0
	movss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L166:
	movsbl	1(%ebx), %edi
	addl	$4, %ebx
	movsbl	-2(%ebx), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edx
	movss	(%eax,%edi,4), %xmm0
	divss	(%eax,%ecx,4), %xmm0
	movss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L165:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %ebp
	movsbl	-2(%ebx), %edi
	movzbl	-1(%ebx), %ecx
	movl	8(%eax), %edx
	movl	4(%eax), %eax
	movss	(%eax,%ebp,4), %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	mulss	(%eax,%edi,4), %xmm0
	movss	%xmm0, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L164:
	movsbl	1(%ebx), %ebp
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	movzbl	-1(%ebx), %ecx
	movss	(%eax,%ebp,4), %xmm0
	movl	4(%edx), %edx
	mulss	(%eax,%edi,4), %xmm0
	movss	%xmm0, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L163:
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	addl	$4, %ebx
	movzbl	-3(%ebx), %ebp
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edx
	movl	4(%ecx), %edi
	movsbl	-2(%ebx), %ecx
	movss	(%edi,%ebp,4), %xmm0
	mulss	(%eax,%ecx,4), %xmm0
	movss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L162:
	movsbl	1(%ebx), %edi
	addl	$4, %ebx
	movsbl	-2(%ebx), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edx
	movss	(%eax,%edi,4), %xmm0
	mulss	(%eax,%ecx,4), %xmm0
	movss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L161:
	movzbl	3(%ebx), %eax
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	movsbl	-3(%ebx), %ebp
	movzbl	-2(%ebx), %ecx
	movl	%eax, (%esp)
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	8(%edx), %edi
	movl	4(%edx), %edx
	movss	(%eax,%ebp,4), %xmm0
	movl	(%esp), %eax
	subss	(%edx,%ecx,4), %xmm0
	movss	%xmm0, (%edi,%eax,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L160:
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	addl	$4, %ebx
	movzbl	-3(%ebx), %ebp
	movzbl	-2(%ebx), %ecx
	movsbl	-1(%ebx), %eax
	movl	4(%edx), %edi
	movl	8(%edx), %edx
	movss	(%edi,%ebp,4), %xmm0
	subss	(%edx,%ecx,4), %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movss	%xmm0, (%edx,%eax,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L159:
	movl	_ZN3GVM11Interpreter9callStackE, %edi
	addl	$4, %ebx
	movsbl	-3(%ebx), %ebp
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movsbl	-1(%ebx), %ecx
	movl	4(%edi), %edi
	movl	%ebp, %eax
	movzbl	%al, %eax
	movss	(%edx,%ebp,4), %xmm0
	subss	(%edi,%eax,4), %xmm0
	movss	%xmm0, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L158:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %ebp
	movsbl	-2(%ebx), %edi
	movzbl	-1(%ebx), %ecx
	movl	8(%eax), %edx
	movl	4(%eax), %eax
	movss	(%eax,%ebp,4), %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	subss	(%eax,%edi,4), %xmm0
	movss	%xmm0, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L157:
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	addl	$4, %ebx
	movsbl	-3(%ebx), %ebp
	movsbl	-2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movzbl	-1(%ebx), %ecx
	movl	4(%edx), %edx
	movss	(%eax,%ebp,4), %xmm0
	subss	(%eax,%edi,4), %xmm0
	movss	%xmm0, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L156:
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	addl	$4, %ebx
	movzbl	-3(%ebx), %ebp
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edx
	movl	4(%ecx), %edi
	movsbl	-2(%ebx), %ecx
	movss	(%edi,%ebp,4), %xmm0
	subss	(%eax,%ecx,4), %xmm0
	movss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L155:
	movsbl	1(%ebx), %edi
	addl	$4, %ebx
	movsbl	-2(%ebx), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edx
	movss	(%eax,%edi,4), %xmm0
	subss	(%eax,%ecx,4), %xmm0
	movss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L154:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %ebp
	movsbl	-2(%ebx), %edi
	movzbl	-1(%ebx), %ecx
	movl	8(%eax), %edx
	movl	4(%eax), %eax
	movss	(%eax,%ebp,4), %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	addss	(%eax,%edi,4), %xmm0
	movss	%xmm0, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L153:
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	addl	$4, %ebx
	movsbl	-3(%ebx), %ebp
	movsbl	-2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movzbl	-1(%ebx), %ecx
	movl	4(%edx), %edx
	movss	(%eax,%ebp,4), %xmm0
	addss	(%eax,%edi,4), %xmm0
	movss	%xmm0, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L152:
	movl	_ZN3GVM11Interpreter9callStackE, %ecx
	addl	$4, %ebx
	movzbl	-3(%ebx), %ebp
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edx
	movl	4(%ecx), %edi
	movsbl	-2(%ebx), %ecx
	movss	(%edi,%ebp,4), %xmm0
	addss	(%eax,%ecx,4), %xmm0
	movss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L151:
	movsbl	1(%ebx), %edi
	addl	$4, %ebx
	movsbl	-2(%ebx), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edx
	movss	(%eax,%edi,4), %xmm0
	addss	(%eax,%ecx,4), %xmm0
	movss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L150:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$3, %ebx
	movzbl	-2(%ebx), %edi
	movzbl	-1(%ebx), %ecx
	movl	8(%eax), %edx
	movl	4(%eax), %eax
	movss	(%eax,%edi,4), %xmm0
	xorps	.LC3, %xmm0
	movss	%xmm0, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L149:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$3, %ebx
	movsbl	-2(%ebx), %edi
	movzbl	-1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movl	4(%eax), %eax
	movss	(%ecx,%edi,4), %xmm0
	xorps	.LC3, %xmm0
	movss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L148:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$3, %ebx
	movzbl	-2(%ebx), %ecx
	movsbl	-1(%ebx), %edx
	movl	4(%eax), %eax
	movss	(%eax,%ecx,4), %xmm0
	xorps	.LC3, %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L147:
	movsbl	1(%ebx), %ecx
	addl	$3, %ebx
	movsbl	-1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movss	(%eax,%ecx,4), %xmm0
	xorps	.LC3, %xmm0
	movss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L146:
	movsbl	2(%ebx), %edx
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%edx,4), %edi
	movsbl	1(%ebx), %edx
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 64
	call	acosf
	fstps	16(%esp)
	movss	16(%esp), %xmm0
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movss	%xmm0, (%edi)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	3(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L145:
	movsbl	1(%ebx), %eax
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	addl	$3, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	pushl	(%edi,%eax,4)
	.cfi_def_cfa_offset 64
	call	cosf
	movsbl	-1(%ebx), %eax
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	movss	(%esp), %xmm0
	movss	%xmm0, (%edi,%eax,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L144:
	movsbl	1(%ebx), %eax
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	addl	$3, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	pushl	(%edi,%eax,4)
	.cfi_def_cfa_offset 64
	call	sinf
	movsbl	-1(%ebx), %eax
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	movss	(%esp), %xmm0
	movss	%xmm0, (%edi,%eax,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L143:
	movsbl	1(%ebx), %edx
	addl	$3, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movss	.LC2, %xmm1
	movss	(%eax,%edx,4), %xmm0
	movsbl	-1(%ebx), %edx
	mulss	%xmm0, %xmm0
	divss	%xmm0, %xmm1
	movss	%xmm1, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L142:
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	2(%ebx), %edx
	leal	(%eax,%edx,4), %edi
	movsbl	1(%ebx), %edx
	sqrtss	(%eax,%edx,4), %xmm0
	ucomiss	%xmm0, %xmm0
	jp	.L394
.L283:
	movss	%xmm0, (%edi)
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	leal	3(%eax), %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L141:
	movsbl	1(%ebx), %ecx
	addl	$3, %ebx
	movsbl	-1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movss	.LC2, %xmm0
	divss	(%eax,%ecx,4), %xmm0
	movss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L140:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %edi
	movzbl	2(%ebx), %edx
	movl	4(%eax), %ecx
	movl	8(%eax), %eax
	movss	(%ecx,%edi,4), %xmm0
	ucomiss	(%eax,%edx,4), %xmm0
	jbe	.L381
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
	movss	(%ecx,%edi,4), %xmm0
	ucomiss	(%eax,%edx,4), %xmm0
	jbe	.L380
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
	movss	(%eax,%ecx,4), %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	ucomiss	(%eax,%edx,4), %xmm0
	jbe	.L379
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L137:
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	1(%ebx), %ecx
	movsbl	2(%ebx), %edx
	movss	(%eax,%ecx,4), %xmm0
	ucomiss	(%eax,%edx,4), %xmm0
	jbe	.L378
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
	movss	(%ecx,%edi,4), %xmm0
	ucomiss	(%eax,%edx,4), %xmm0
	jb	.L377
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
	movss	(%ecx,%edi,4), %xmm0
	ucomiss	(%eax,%edx,4), %xmm0
	jb	.L376
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
	movss	(%eax,%ecx,4), %xmm0
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	ucomiss	(%eax,%edx,4), %xmm0
	jb	.L375
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L133:
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	1(%ebx), %ecx
	movsbl	2(%ebx), %edx
	movss	(%eax,%ecx,4), %xmm0
	ucomiss	(%eax,%edx,4), %xmm0
	jb	.L374
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
	pxor	%xmm0, %xmm0
	cvtsi2ss	%eax, %xmm0
	mulss	.LC1, %xmm0
	movss	%xmm0, (%ebx)
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
	addl	$4, %ebx
	movl	(%esp), %eax
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
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	2(%ebx), %edx
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
	addl	$4, %ebx
	movl	(%esp), %eax
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
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	2(%ebx), %edx
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
	addl	$4, %ebx
	movsbl	-2(%ebx), %ebp
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movzbl	-1(%ebx), %eax
	movl	8(%edx), %edi
	movl	4(%edx), %edx
	movl	(%ecx,%ebp,4), %ecx
	movl	%edi, (%esp)
	movzbl	-3(%ebx), %edi
	movl	(%edx,%edi,4), %edx
	movl	(%esp), %edi
	shrl	%cl, %edx
	movl	%edx, (%edi,%eax,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L122:
	movsbl	1(%ebx), %ebp
	addl	$4, %ebx
	movsbl	-2(%ebx), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	movzbl	-1(%ebx), %edi
	movl	(%eax,%ecx,4), %ecx
	movl	(%eax,%ebp,4), %eax
	movl	4(%edx), %edx
	shrl	%cl, %eax
	movl	%eax, (%edx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L121:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %ebp
	movsbl	-2(%ebx), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movl	4(%eax), %eax
	movsbl	-1(%ebx), %edi
	movl	(%edx,%ecx,4), %ecx
	movl	(%eax,%ebp,4), %eax
	shrl	%cl, %eax
	movl	%eax, (%edx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L120:
	movsbl	1(%ebx), %edx
	addl	$4, %ebx
	movsbl	-2(%ebx), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edi
	movl	(%eax,%ecx,4), %ecx
	movl	(%eax,%edx,4), %edx
	shrl	%cl, %edx
	movl	%edx, (%eax,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L119:
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	addl	$4, %ebx
	movsbl	-2(%ebx), %ebp
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movzbl	-1(%ebx), %eax
	movl	8(%edx), %edi
	movl	4(%edx), %edx
	movl	(%ecx,%ebp,4), %ecx
	movl	%edi, (%esp)
	movzbl	-3(%ebx), %edi
	movl	(%edx,%edi,4), %edx
	movl	(%esp), %edi
	sall	%cl, %edx
	movl	%edx, (%edi,%eax,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L118:
	movsbl	1(%ebx), %ebp
	addl	$4, %ebx
	movsbl	-2(%ebx), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	movzbl	-1(%ebx), %edi
	movl	(%eax,%ecx,4), %ecx
	movl	(%eax,%ebp,4), %eax
	movl	4(%edx), %edx
	sall	%cl, %eax
	movl	%eax, (%edx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L117:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %ebp
	movsbl	-2(%ebx), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movl	4(%eax), %eax
	movsbl	-1(%ebx), %edi
	movl	(%edx,%ecx,4), %ecx
	movl	(%eax,%ebp,4), %eax
	sall	%cl, %eax
	movl	%eax, (%edx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L116:
	movsbl	1(%ebx), %edx
	addl	$4, %ebx
	movsbl	-2(%ebx), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edi
	movl	(%eax,%ecx,4), %ecx
	movl	(%eax,%edx,4), %edx
	sall	%cl, %edx
	movl	%edx, (%eax,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L115:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %edi
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
	addl	$4, %ebx
	movsbl	-2(%ebx), %ebp
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
	addl	$4, %ebx
	movzbl	-3(%ebx), %ebp
	movsbl	-2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movl	4(%eax), %eax
	movsbl	-1(%ebx), %ecx
	movl	(%eax,%ebp,4), %eax
	xorl	(%edx,%edi,4), %eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L112:
	movsbl	1(%ebx), %edx
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %ecx
	movl	(%eax,%edx,4), %edx
	xorl	(%eax,%edi,4), %edx
	movl	%edx, (%eax,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L111:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %edi
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
	addl	$4, %ebx
	movsbl	-2(%ebx), %ebp
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
	addl	$4, %ebx
	movzbl	-3(%ebx), %ebp
	movsbl	-2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movl	4(%eax), %eax
	movsbl	-1(%ebx), %ecx
	movl	(%eax,%ebp,4), %eax
	orl	(%edx,%edi,4), %eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L108:
	movsbl	1(%ebx), %edx
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %ecx
	movl	(%eax,%edx,4), %edx
	orl	(%eax,%edi,4), %edx
	movl	%edx, (%eax,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L107:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %edi
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
	addl	$4, %ebx
	movsbl	-2(%ebx), %ebp
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
	addl	$4, %ebx
	movzbl	-3(%ebx), %ebp
	movsbl	-2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movl	4(%eax), %eax
	movsbl	-1(%ebx), %ecx
	movl	(%eax,%ebp,4), %eax
	andl	(%edx,%edi,4), %eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L104:
	movsbl	1(%ebx), %edx
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
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
	je	.L348
	movsbl	1(%ebx), %edx
	addl	$4, %ebx
	movl	8(%eax), %ecx
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
	je	.L348
	movzbl	1(%ebx), %edx
	addl	$4, %ebx
	movl	4(%eax), %eax
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
	je	.L348
	movsbl	1(%ebx), %eax
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
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
	je	.L348
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %edx
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
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	2(%ebx), %edx
	movl	(%eax,%edx,4), %ebp
	testl	%ebp, %ebp
	je	.L348
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	addl	$4, %ebx
	movzbl	-1(%ebx), %edi
	movl	4(%edx), %ecx
	movsbl	-3(%ebx), %edx
	movl	(%eax,%edx,4), %eax
	cltd
	idivl	%ebp
	movl	%edx, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L98:
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movsbl	2(%ebx), %eax
	movl	(%ecx,%eax,4), %ebp
	testl	%ebp, %ebp
	je	.L348
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %edx
	movsbl	-1(%ebx), %edi
	movl	4(%eax), %eax
	movl	(%eax,%edx,4), %eax
	cltd
	idivl	%ebp
	movl	%edx, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L97:
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movsbl	2(%ebx), %eax
	movl	(%ecx,%eax,4), %ebp
	testl	%ebp, %ebp
	je	.L348
	movsbl	1(%ebx), %eax
	addl	$4, %ebx
	movsbl	-1(%ebx), %edi
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
	je	.L348
	movsbl	1(%ebx), %edx
	addl	$4, %ebx
	movl	8(%eax), %ecx
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
	je	.L348
	movzbl	1(%ebx), %edx
	addl	$4, %ebx
	movl	4(%eax), %eax
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
	je	.L348
	movsbl	1(%ebx), %eax
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
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
	je	.L348
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %edx
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
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	2(%ebx), %edx
	movl	(%eax,%edx,4), %ebp
	testl	%ebp, %ebp
	je	.L348
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	addl	$4, %ebx
	movzbl	-1(%ebx), %edi
	movl	4(%edx), %ecx
	movsbl	-3(%ebx), %edx
	movl	(%eax,%edx,4), %eax
	cltd
	idivl	%ebp
	movl	%eax, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L91:
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movsbl	2(%ebx), %eax
	movl	(%ecx,%eax,4), %ebp
	testl	%ebp, %ebp
	je	.L348
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %edx
	movsbl	-1(%ebx), %edi
	movl	4(%eax), %eax
	movl	(%eax,%edx,4), %eax
	cltd
	idivl	%ebp
	movl	%eax, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L90:
	movl	_ZN3GVM11Interpreter10frameStackE, %ecx
	movsbl	2(%ebx), %eax
	movl	(%ecx,%eax,4), %ebp
	testl	%ebp, %ebp
	je	.L348
	movsbl	1(%ebx), %eax
	addl	$4, %ebx
	movsbl	-1(%ebx), %edi
	movl	(%ecx,%eax,4), %eax
	cltd
	idivl	%ebp
	movl	%eax, (%ecx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L89:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %edi
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
	addl	$4, %ebx
	movsbl	-2(%ebx), %ebp
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
	addl	$4, %ebx
	movzbl	-3(%ebx), %ebp
	movsbl	-2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movl	4(%eax), %eax
	movsbl	-1(%ebx), %ecx
	movl	(%eax,%ebp,4), %eax
	imull	(%edx,%edi,4), %eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L86:
	movsbl	1(%ebx), %edx
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %ecx
	movl	(%eax,%edx,4), %edx
	imull	(%eax,%edi,4), %edx
	movl	%edx, (%eax,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L85:
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	addl	$4, %ebx
	movsbl	-3(%ebx), %ebp
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
	addl	$4, %ebx
	movzbl	-3(%ebx), %ebp
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
	movl	_ZN3GVM11Interpreter9callStackE, %edi
	addl	$4, %ebx
	movsbl	-3(%ebx), %ebp
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movsbl	-1(%ebx), %ecx
	movl	4(%edi), %edi
	movl	%ebp, %eax
	movzbl	%al, %eax
	movl	(%edx,%ebp,4), %ebp
	subl	(%edi,%eax,4), %ebp
	movl	%ebp, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L82:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$4, %ebx
	movzbl	-3(%ebx), %edi
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
	addl	$4, %ebx
	movsbl	-2(%ebx), %ebp
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
	addl	$4, %ebx
	movzbl	-3(%ebx), %ebp
	movsbl	-2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movl	4(%eax), %eax
	movsbl	-1(%ebx), %ecx
	movl	(%eax,%ebp,4), %eax
	subl	(%edx,%edi,4), %eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L79:
	movsbl	1(%ebx), %edx
	addl	$4, %ebx
	movsbl	-2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %ecx
	movl	(%eax,%edx,4), %edx
	subl	(%eax,%edi,4), %edx
	movl	%edx, (%eax,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L78:
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	addl	$4, %ebx
	movzbl	-3(%ebx), %ecx
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
	addl	$4, %ebx
	movsbl	-3(%ebx), %ebp
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
	addl	$4, %ebx
	movzbl	-3(%ebx), %ebp
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
	addl	$4, %ebx
	movsbl	-2(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %ecx
	movl	(%eax,%edx,4), %edx
	addl	(%eax,%edi,4), %edx
	movl	%edx, (%eax,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L74:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$3, %ebx
	movzbl	-2(%ebx), %edi
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
	addl	$3, %ebx
	movsbl	-2(%ebx), %edi
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
	addl	$3, %ebx
	movzbl	-2(%ebx), %edx
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
	addl	$3, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movsbl	-1(%ebx), %ecx
	movl	(%edx,%eax,4), %eax
	negl	%eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L70:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$3, %ebx
	movzbl	-2(%ebx), %edi
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
	addl	$3, %ebx
	movsbl	-2(%ebx), %edi
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
	addl	$3, %ebx
	movzbl	-2(%ebx), %edx
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
	addl	$3, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	movsbl	-1(%ebx), %ecx
	movl	(%edx,%eax,4), %eax
	notl	%eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L66:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	1(%ebx), %ecx
	movzbl	2(%ebx), %edi
	movl	4(%eax), %edx
	movl	$1, %eax
	sall	%cl, %eax
	testl	%eax, (%edx,%edi,4)
	jne	.L266
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L65:
	movzbl	1(%ebx), %ecx
	movl	$1, %eax
	movsbl	2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	sall	%cl, %eax
	testl	%eax, (%edx,%edi,4)
	jne	.L265
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
	movzbl	1(%ebx), %ecx
	movzbl	2(%ebx), %edi
	movl	4(%eax), %edx
	movl	$1, %eax
	sall	%cl, %eax
	testl	%eax, (%edx,%edi,4)
	je	.L264
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L63:
	movzbl	1(%ebx), %ecx
	movl	$1, %eax
	movsbl	2(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	sall	%cl, %eax
	testl	%eax, (%edx,%edi,4)
	je	.L263
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
	addl	$3, %ebx
	movzbl	-2(%ebx), %ecx
	movzbl	-1(%ebx), %edi
	movl	4(%eax), %edx
	movl	$-2, %eax
	roll	%cl, %eax
	andl	%eax, (%edx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L61:
	movzbl	1(%ebx), %ecx
	movl	$-2, %eax
	addl	$3, %ebx
	movsbl	-1(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	roll	%cl, %eax
	andl	%eax, (%edx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L60:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$3, %ebx
	movzbl	-2(%ebx), %ecx
	movzbl	-1(%ebx), %edi
	movl	4(%eax), %edx
	movl	$1, %eax
	sall	%cl, %eax
	orl	%eax, (%edx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L59:
	movzbl	1(%ebx), %ecx
	movl	$1, %eax
	addl	$3, %ebx
	movsbl	-1(%ebx), %edi
	movl	_ZN3GVM11Interpreter10frameStackE, %edx
	sall	%cl, %eax
	orl	%eax, (%edx,%edi,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L58:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$3, %ebx
	movzbl	-1(%ebx), %edx
	movsbl	-2(%ebx), %ecx
	movl	8(%eax), %eax
	movl	%ecx, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L57:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$3, %ebx
	movzbl	-1(%ebx), %edx
	movsbl	-2(%ebx), %ecx
	movl	4(%eax), %eax
	movl	%ecx, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L56:
	movsbl	2(%ebx), %edx
	addl	$3, %ebx
	movsbl	-2(%ebx), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	%ecx, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L55:
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	leal	(%eax,%edx,4), %edx
	subl	$1, (%edx)
	js	.L262
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
	je	.L261
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
	jle	.L260
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
	jle	.L259
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
	jle	.L258
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L50:
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	1(%ebx), %ecx
	movsbl	2(%ebx), %edx
	movl	(%eax,%edx,4), %edi
	cmpl	%edi, (%eax,%ecx,4)
	jle	.L257
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
	jl	.L256
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
	jl	.L255
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
	jl	.L254
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L46:
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	1(%ebx), %ecx
	movsbl	2(%ebx), %edx
	movl	(%eax,%edx,4), %edi
	cmpl	%edi, (%eax,%ecx,4)
	jl	.L253
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
	pxor	%xmm0, %xmm0
	addl	$3, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edx
	cvtsi2ss	(%eax,%ecx,4), %xmm0
	movss	%xmm0, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L44:
	movsbl	1(%ebx), %ecx
	addl	$3, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	-1(%ebx), %edx
	cvttss2si	(%eax,%ecx,4), %ecx
	movl	%ecx, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L43:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$3, %ebx
	movzbl	-2(%ebx), %ecx
	movl	4(%eax), %edx
	movl	8(%eax), %eax
	movl	(%edx,%ecx,4), %ecx
	movzbl	-1(%ebx), %edx
	movl	%ecx, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L42:
	movsbl	1(%ebx), %edx
	addl	$3, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	(%eax,%edx,4), %ecx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	-1(%ebx), %edx
	movl	4(%eax), %eax
	movl	%ecx, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L41:
	movsbl	1(%ebx), %edx
	addl	$3, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	(%eax,%edx,4), %ecx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	-1(%ebx), %edx
	movl	4(%eax), %eax
	movl	%ecx, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L40:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$3, %ebx
	movzbl	-2(%ebx), %edx
	movl	8(%eax), %eax
	movl	(%eax,%edx,4), %ecx
	movsbl	-1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	%ecx, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L39:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$3, %ebx
	movzbl	-2(%ebx), %edx
	movl	4(%eax), %eax
	movl	(%eax,%edx,4), %ecx
	movsbl	-1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	%ecx, (%eax,%edx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L38:
	movsbl	1(%ebx), %edx
	addl	$3, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
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
	addl	$2, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	%edx, 8(%eax)
	jmp	.L2
.L33:
	movsbl	1(%ebx), %edx
	addl	$2, %ebx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	%edx, 4(%eax)
	jmp	.L2
.L32:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$4, %ebx
	movzbl	-1(%ebx), %ecx
	movl	8(%eax), %edx
	movzbl	-2(%ebx), %eax
	orl	$-2147483648, %eax
	movl	%eax, %edi
	movzbl	-3(%ebx), %eax
	sall	$8, %eax
	orl	%edi, %eax
	movl	%eax, (%edx,%ecx,4)
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L31:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	addl	$4, %ebx
	movzbl	-1(%ebx), %ecx
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
	addl	$4, %ebx
	movsbl	-1(%ebx), %ecx
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
	movzwl	%ax, %edx
	testw	%ax, %ax
	je	.L334
	movl	_ZN3GVM11Interpreter9dataTableE, %eax
	addl	$3, %ebx
	movl	(%eax,%edx,4), %edx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	%edx, 8(%eax)
	jmp	.L2
.L28:
	movzwl	1(%ebx), %eax
	rolw	$8, %ax
	movzwl	%ax, %edx
	testw	%ax, %ax
	je	.L334
	movl	_ZN3GVM11Interpreter9dataTableE, %eax
	addl	$3, %ebx
	movl	(%eax,%edx,4), %edx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	%edx, 4(%eax)
	jmp	.L2
.L27:
	movzwl	1(%ebx), %eax
	rolw	$8, %ax
	movzwl	%ax, %edx
	testw	%ax, %ax
	je	.L334
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
	movzwl	%ax, %edx
	testw	%ax, %ax
	je	.L334
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
	movzwl	%ax, %edx
	testw	%ax, %ax
	je	.L334
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
	movzbl	2(%ebx), %edx
	movzbl	1(%ebx), %edi
	movl	4(%eax), %ecx
	movl	8(%eax), %eax
	movl	(%eax,%edx,4), %eax
	cmpl	%eax, (%ecx,%edi,4)
	je	.L395
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L20:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movsbl	1(%ebx), %edx
	movzbl	2(%ebx), %edi
	movl	4(%eax), %ecx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	(%eax,%edx,4), %eax
	cmpl	%eax, (%ecx,%edi,4)
	je	.L396
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L19:
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	1(%ebx), %edx
	movsbl	2(%ebx), %ecx
	movl	(%eax,%edx,4), %edi
	cmpl	%edi, (%eax,%ecx,4)
	je	.L397
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L18:
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movzbl	2(%ebx), %edx
	movl	4(%eax), %eax
	movl	(%eax,%edx,4), %eax
	testl	%eax, %eax
	je	.L249
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
	je	.L248
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
	jne	.L247
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
	jne	.L246
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
	movl	%eax, 8(%edx)
	testl	%eax, %eax
	je	.L398
	addl	$3, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L13:
	movl	_ZN3GVM11Interpreter9callStackE, %edx
	movzbl	1(%ebx), %ecx
	movl	4(%edx), %eax
	movl	(%eax,%ecx,4), %eax
	movl	%eax, 4(%edx)
	testl	%eax, %eax
	je	.L399
	addl	$3, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L12:
	call	_ZN3GVM11Interpreter12exitFunctionEv
	testl	%eax, %eax
	jne	.L243
	movl	_ZN3GVM11Interpreter14programCounterE, %ebx
	jmp	.L2
.L11:
	movzbl	1(%ebx), %eax
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	movzbl	2(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	movzwl	%ax, %eax
	pushl	%eax
	.cfi_def_cfa_offset 64
	call	_ZN3GVM11Interpreter18invokeHostFunctionEt
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	testl	%eax, %eax
	jne	.L3
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
	jne	.L327
	subl	$8, %esp
	.cfi_def_cfa_offset 56
.L383:
	movzwl	%ax, %eax
	addl	$3, %ebx
	pushl	%eax
	.cfi_def_cfa_offset 60
	pushl	%ebx
	.cfi_def_cfa_offset 64
	call	_ZN3GVM11Interpreter13enterFunctionEPKht
	addl	$16, %esp
	.cfi_def_cfa_offset 48
.L241:
	testl	%eax, %eax
	jne	.L3
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
	subl	$8, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	movzbl	2(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	jmp	.L383
.L9:
	.cfi_restore_state
	movsbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movl	(%eax,%edx,4), %eax
	movl	%eax, %edx
	andl	$-1073741824, %edx
	cmpl	$-2147483648, %edx
	jne	.L327
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
	jmp	.L241
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
	jmp	.L241
.L239:
	movl	_ZN3GVM11Interpreter10frameStackE, %eax
	movsbl	1(%ebx), %edx
	movzbl	2(%ebx), %edi
	leal	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	4(%eax), %ecx
	movl	8(%eax), %eax
	movss	(%ecx,%edi,4), %xmm0
	movzbl	3(%ebx), %ecx
	leal	(%eax,%ecx,4), %eax
	jmp	.L324
.L246:
	addl	$4, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L247:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L248:
	addl	$4, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L249:
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
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L261:
	addl	$4, %ebx
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
.L266:
	addl	$3, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L374:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L375:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L376:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L377:
	addl	$5, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L378:
	addl	$5, %ebx
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
.L348:
	movl	$10, %eax
	jmp	.L3
.L397:
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L396:
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L395:
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L262:
	addl	$4, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L398:
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L399:
	movzbl	2(%ebx), %eax
	movzbl	3(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L2
.L334:
	movl	$9, %eax
	jmp	.L3
.L327:
	movl	$7, %eax
	jmp	.L3
.L390:
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	movss	%xmm0, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movss	(%edi), %xmm2
	fstps	(%esp)
	movss	(%esp), %xmm1
	jmp	.L311
.L243:
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
	jmp	.L3
.L388:
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	movss	%xmm0, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	movss	(%esp), %xmm1
	jmp	.L315
.L389:
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	movss	%xmm0, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	movss	(%esp), %xmm1
	jmp	.L313
.L386:
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	movss	%xmm0, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	movss	(%esp), %xmm1
	jmp	.L319
.L387:
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	movss	%xmm0, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	movss	(%esp), %xmm1
	jmp	.L317
.L394:
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 64
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	movss	(%esp), %xmm0
	jmp	.L283
.L393:
	movss	%xmm2, 12(%esp)
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	movss	%xmm0, 24(%esp)
	movss	%xmm4, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movss	12(%esp), %xmm2
	fstps	(%esp)
	movss	8(%esp), %xmm0
	movss	(%esp), %xmm1
	movss	4(%esp), %xmm3
	jmp	.L301
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
