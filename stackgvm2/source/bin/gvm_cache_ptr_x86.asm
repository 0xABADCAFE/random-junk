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
	ja	.L345
.L380:
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
	addl	$4, %ebx
	addl	$1, %esi
	leal	0(%ebp,%eax,4), %edx
	movzbl	-2(%ebx), %eax
	vmovss	(%ecx,%eax,4), %xmm0
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	vmulss	(%edx), %xmm0, %xmm1
	movsbl	3(%eax), %eax
	leal	(%edi,%eax,4), %eax
	vmovss	%xmm1, (%eax)
	vmulss	4(%edx), %xmm0, %xmm1
	vmovss	%xmm1, 4(%eax)
	vmulss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	cmpb	$-21, (%ebx)
	jbe	.L380
.L345:
	movl	$2, %eax
	jmp	.L370
	.p2align 4,,10
	.p2align 3
.L238:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	2(%ebx), %ecx
	addl	$4, %ebx
	movsbl	1(%eax), %edx
	movsbl	3(%eax), %eax
	vmovss	0(%ebp,%ecx,4), %xmm0
	leal	(%edi,%edx,4), %edx
	leal	(%edi,%eax,4), %eax
	vmulss	(%edx), %xmm0, %xmm1
	vmovss	%xmm1, (%eax)
	vmulss	4(%edx), %xmm0, %xmm1
	vmovss	%xmm1, 4(%eax)
	vmulss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L237:
	movzbl	1(%ebx), %eax
	movl	8(%esp), %ecx
	addl	$4, %ebx
	leal	0(%ebp,%eax,4), %edx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %eax
	vmovss	(%edi,%eax,4), %xmm0
	movzbl	-1(%ebx), %eax
	vmulss	(%edx), %xmm0, %xmm1
	leal	(%ecx,%eax,4), %eax
	vmovss	%xmm1, (%eax)
	vmulss	4(%edx), %xmm0, %xmm1
	vmovss	%xmm1, 4(%eax)
	vmulss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L236:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %eax
	leal	(%edi,%edx,4), %edx
	vmovss	(%edi,%eax,4), %xmm0
	movzbl	-1(%ebx), %eax
	vmulss	(%edx), %xmm0, %xmm1
	leal	0(%ebp,%eax,4), %eax
	vmovss	%xmm1, (%eax)
	vmulss	4(%edx), %xmm0, %xmm1
	vmovss	%xmm1, 4(%eax)
	vmulss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L235:
	movzbl	1(%ebx), %eax
	addl	$4, %ebx
	leal	0(%ebp,%eax,4), %edx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %ecx
	movsbl	3(%eax), %eax
	vmovss	(%edi,%ecx,4), %xmm0
	leal	(%edi,%eax,4), %eax
	vmulss	(%edx), %xmm0, %xmm1
	vmovss	%xmm1, (%eax)
	vmulss	4(%edx), %xmm0, %xmm1
	vmovss	%xmm1, 4(%eax)
	vmulss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L234:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %ecx
	movsbl	3(%eax), %eax
	leal	(%edi,%edx,4), %edx
	vmovss	(%edi,%ecx,4), %xmm0
	leal	(%edi,%eax,4), %eax
	vmulss	(%edx), %xmm0, %xmm1
	vmovss	%xmm1, (%eax)
	vmulss	4(%edx), %xmm0, %xmm1
	vmovss	%xmm1, 4(%eax)
	vmulss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L233:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	3(%ebx), %ecx
	addl	$4, %ebx
	movsbl	1(%eax), %eax
	leal	(%edi,%eax,4), %edx
	movzbl	-2(%ebx), %eax
	vmovss	8(%edx), %xmm0
	vmovss	4(%edx), %xmm7
	leal	0(%ebp,%eax,4), %eax
	movl	%eax, 12(%esp)
	movl	8(%esp), %eax
	leal	(%eax,%ecx,4), %ecx
	movl	12(%esp), %eax
	vmulss	4(%eax), %xmm0, %xmm0
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
	vfmsub231ss	4(%eax), %xmm5, %xmm0
	vmovss	%xmm0, 8(%ecx)
	jmp	.L2
.L232:
	movzbl	1(%ebx), %eax
	movl	8(%esp), %ecx
	addl	$4, %ebx
	leal	0(%ebp,%eax,4), %edx
	movzbl	-2(%ebx), %eax
	vmovss	8(%edx), %xmm0
	vmovss	4(%edx), %xmm4
	leal	(%ecx,%eax,4), %eax
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	vmulss	4(%eax), %xmm0, %xmm0
	movsbl	3(%ecx), %ecx
	leal	(%edi,%ecx,4), %ecx
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
	vfmsub231ss	4(%eax), %xmm6, %xmm0
	vmovss	%xmm0, 8(%ecx)
	jmp	.L2
.L231:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movsbl	1(%ecx), %eax
	movsbl	3(%ecx), %ecx
	leal	(%edi,%eax,4), %edx
	movzbl	-2(%ebx), %eax
	leal	(%edi,%ecx,4), %ecx
	vmovss	8(%edx), %xmm0
	vmovss	4(%edx), %xmm5
	leal	0(%ebp,%eax,4), %eax
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
	vfmsub231ss	4(%eax), %xmm7, %xmm0
	vmovss	%xmm0, 8(%ecx)
	jmp	.L2
.L230:
	movzbl	1(%ebx), %eax
	movzbl	3(%ebx), %ecx
	addl	$4, %ebx
	leal	0(%ebp,%eax,4), %edx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	vmovss	8(%edx), %xmm0
	movsbl	2(%eax), %eax
	vmovss	4(%edx), %xmm6
	leal	(%edi,%eax,4), %eax
	movl	%eax, 12(%esp)
	movl	8(%esp), %eax
	leal	(%eax,%ecx,4), %ecx
	movl	12(%esp), %eax
	vmulss	4(%eax), %xmm0, %xmm0
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
	vfmsub231ss	4(%eax), %xmm4, %xmm0
	vmovss	%xmm0, 8(%ecx)
	jmp	.L2
.L229:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	3(%ebx), %ecx
	addl	$4, %ebx
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %eax
	leal	0(%ebp,%ecx,4), %ecx
	leal	(%edi,%edx,4), %edx
	leal	(%edi,%eax,4), %eax
	vmovss	8(%edx), %xmm0
	vmulss	4(%eax), %xmm0, %xmm0
	vmovss	4(%edx), %xmm7
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
	vfmsub231ss	4(%eax), %xmm5, %xmm0
	vmovss	%xmm0, 8(%ecx)
	jmp	.L2
.L228:
	movzbl	1(%ebx), %eax
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	leal	0(%ebp,%eax,4), %edx
	movsbl	2(%ecx), %eax
	movsbl	3(%ecx), %ecx
	vmovss	8(%edx), %xmm0
	vmovss	4(%edx), %xmm4
	leal	(%edi,%eax,4), %eax
	leal	(%edi,%ecx,4), %ecx
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
	vfmsub231ss	4(%eax), %xmm6, %xmm0
	vmovss	%xmm0, 8(%ecx)
	jmp	.L2
.L227:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movsbl	1(%ecx), %eax
	leal	(%edi,%eax,4), %edx
	movsbl	2(%ecx), %eax
	movsbl	3(%ecx), %ecx
	vmovss	8(%edx), %xmm0
	vmovss	4(%edx), %xmm5
	leal	(%edi,%eax,4), %eax
	leal	(%edi,%ecx,4), %ecx
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
	vfmsub231ss	4(%eax), %xmm7, %xmm0
	vmovss	%xmm0, 8(%ecx)
	jmp	.L2
.L226:
	movzbl	1(%ebx), %eax
	movzbl	3(%ebx), %ecx
	addl	$4, %ebx
	leal	0(%ebp,%eax,4), %edx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	vmovss	4(%edx), %xmm0
	movsbl	2(%eax), %eax
	vmovss	(%edx), %xmm7
	vmovss	8(%edx), %xmm4
	leal	(%edi,%eax,4), %eax
	vmulss	4(%eax), %xmm0, %xmm0
	vfmadd231ss	(%eax), %xmm7, %xmm0
	vfmadd231ss	8(%eax), %xmm4, %xmm0
	movl	8(%esp), %eax
	vmovss	%xmm0, (%eax,%ecx,4)
	jmp	.L2
.L225:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	3(%ebx), %ecx
	addl	$4, %ebx
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %eax
	leal	(%edi,%edx,4), %edx
	leal	(%edi,%eax,4), %eax
	vmovss	4(%edx), %xmm0
	vmulss	4(%eax), %xmm0, %xmm0
	vmovss	(%edx), %xmm5
	vmovss	8(%edx), %xmm6
	vfmadd231ss	(%eax), %xmm5, %xmm0
	vfmadd231ss	8(%eax), %xmm6, %xmm0
	vmovss	%xmm0, 0(%ebp,%ecx,4)
	jmp	.L2
.L224:
	movzbl	1(%ebx), %eax
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	leal	0(%ebp,%eax,4), %edx
	movsbl	2(%ecx), %eax
	movsbl	3(%ecx), %ecx
	vmovss	4(%edx), %xmm0
	vmovss	(%edx), %xmm7
	leal	(%edi,%eax,4), %eax
	vmovss	8(%edx), %xmm4
	vmulss	4(%eax), %xmm0, %xmm0
	vfmadd231ss	(%eax), %xmm7, %xmm0
	vfmadd231ss	8(%eax), %xmm4, %xmm0
	vmovss	%xmm0, (%edi,%ecx,4)
	jmp	.L2
.L223:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	addl	$4, %ebx
	movsbl	1(%ecx), %eax
	leal	(%edi,%eax,4), %edx
	movsbl	2(%ecx), %eax
	movsbl	3(%ecx), %ecx
	vmovss	4(%edx), %xmm0
	vmovss	(%edx), %xmm5
	leal	(%edi,%eax,4), %eax
	vmovss	8(%edx), %xmm6
	vmulss	4(%eax), %xmm0, %xmm0
	vfmadd231ss	(%eax), %xmm5, %xmm0
	vfmadd231ss	8(%eax), %xmm6, %xmm0
	vmovss	%xmm0, (%edi,%ecx,4)
	jmp	.L2
.L222:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	1(%eax), %eax
	leal	(%edi,%eax,4), %ecx
	movzbl	-2(%ebx), %eax
	vmovss	(%ecx), %xmm0
	leal	0(%ebp,%eax,4), %edx
	movzbl	-1(%ebx), %eax
	movl	%edx, 12(%esp)
	movl	8(%esp), %edx
	leal	(%edx,%eax,4), %eax
	movl	12(%esp), %edx
	vsubss	(%edx), %xmm0, %xmm0
	vmovss	%xmm0, (%eax)
	vmovss	4(%ecx), %xmm0
	vsubss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%ecx), %xmm0
	vsubss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L221:
	movzbl	1(%ebx), %eax
	movl	8(%esp), %edx
	addl	$4, %ebx
	leal	0(%ebp,%eax,4), %ecx
	movzbl	-2(%ebx), %eax
	vmovss	(%ecx), %xmm0
	leal	(%edx,%eax,4), %edx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	vsubss	(%edx), %xmm0, %xmm0
	movsbl	3(%eax), %eax
	leal	(%edi,%eax,4), %eax
	vmovss	%xmm0, (%eax)
	vmovss	4(%ecx), %xmm0
	vsubss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%ecx), %xmm0
	vsubss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L220:
	movzbl	2(%ebx), %eax
	addl	$4, %ebx
	leal	0(%ebp,%eax,4), %edx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %ecx
	movsbl	3(%eax), %eax
	leal	(%edi,%ecx,4), %ecx
	leal	(%edi,%eax,4), %eax
	vmovss	(%ecx), %xmm0
	vsubss	(%edx), %xmm0, %xmm0
	vmovss	%xmm0, (%eax)
	vmovss	4(%ecx), %xmm0
	vsubss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%ecx), %xmm0
	vsubss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L219:
	movzbl	1(%ebx), %eax
	addl	$4, %ebx
	leal	0(%ebp,%eax,4), %ecx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	vmovss	(%ecx), %xmm0
	movsbl	2(%eax), %eax
	leal	(%edi,%eax,4), %edx
	movzbl	-1(%ebx), %eax
	movl	%edx, 12(%esp)
	movl	8(%esp), %edx
	leal	(%edx,%eax,4), %eax
	movl	12(%esp), %edx
	vsubss	(%edx), %xmm0, %xmm0
	vmovss	%xmm0, (%eax)
	vmovss	4(%ecx), %xmm0
	vsubss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%ecx), %xmm0
	vsubss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L218:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %eax
	leal	(%edi,%edx,4), %ecx
	leal	(%edi,%eax,4), %edx
	movzbl	-1(%ebx), %eax
	vmovss	(%ecx), %xmm0
	vsubss	(%edx), %xmm0, %xmm0
	leal	0(%ebp,%eax,4), %eax
	vmovss	%xmm0, (%eax)
	vmovss	4(%ecx), %xmm0
	vsubss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%ecx), %xmm0
	vsubss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L217:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movsbl	2(%eax), %edx
	movsbl	3(%eax), %eax
	leal	0(%ebp,%ecx,4), %ecx
	vmovss	(%ecx), %xmm0
	leal	(%edi,%edx,4), %edx
	leal	(%edi,%eax,4), %eax
	vsubss	(%edx), %xmm0, %xmm0
	vmovss	%xmm0, (%eax)
	vmovss	4(%ecx), %xmm0
	vsubss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%ecx), %xmm0
	vsubss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L216:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	1(%eax), %edx
	leal	(%edi,%edx,4), %ecx
	movsbl	2(%eax), %edx
	movsbl	3(%eax), %eax
	vmovss	(%ecx), %xmm0
	leal	(%edi,%edx,4), %edx
	leal	(%edi,%eax,4), %eax
	vsubss	(%edx), %xmm0, %xmm0
	vmovss	%xmm0, (%eax)
	vmovss	4(%ecx), %xmm0
	vsubss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%ecx), %xmm0
	vsubss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L215:
	movzbl	1(%ebx), %eax
	addl	$4, %ebx
	leal	0(%ebp,%eax,4), %ecx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	vmovss	(%ecx), %xmm0
	movsbl	2(%eax), %eax
	leal	(%edi,%eax,4), %edx
	movzbl	-1(%ebx), %eax
	movl	%edx, 12(%esp)
	movl	8(%esp), %edx
	leal	(%edx,%eax,4), %eax
	movl	12(%esp), %edx
	vaddss	(%edx), %xmm0, %xmm0
	vmovss	%xmm0, (%eax)
	vmovss	4(%ecx), %xmm0
	vaddss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%ecx), %xmm0
	vaddss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L214:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %eax
	leal	(%edi,%edx,4), %ecx
	leal	(%edi,%eax,4), %edx
	movzbl	-1(%ebx), %eax
	vmovss	(%ecx), %xmm0
	vaddss	(%edx), %xmm0, %xmm0
	leal	0(%ebp,%eax,4), %eax
	vmovss	%xmm0, (%eax)
	vmovss	4(%ecx), %xmm0
	vaddss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%ecx), %xmm0
	vaddss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L213:
	movzbl	1(%ebx), %eax
	addl	$4, %ebx
	leal	0(%ebp,%eax,4), %ecx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	vmovss	(%ecx), %xmm0
	movsbl	2(%eax), %edx
	movsbl	3(%eax), %eax
	leal	(%edi,%edx,4), %edx
	leal	(%edi,%eax,4), %eax
	vaddss	(%edx), %xmm0, %xmm0
	vmovss	%xmm0, (%eax)
	vmovss	4(%ecx), %xmm0
	vaddss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%ecx), %xmm0
	vaddss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L212:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	1(%eax), %edx
	leal	(%edi,%edx,4), %ecx
	movsbl	2(%eax), %edx
	movsbl	3(%eax), %eax
	vmovss	(%ecx), %xmm0
	leal	(%edi,%edx,4), %edx
	leal	(%edi,%eax,4), %eax
	vaddss	(%edx), %xmm0, %xmm0
	vmovss	%xmm0, (%eax)
	vmovss	4(%ecx), %xmm0
	vaddss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%ecx), %xmm0
	vaddss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L211:
	movzbl	1(%ebx), %eax
	movzbl	2(%ebx), %edx
	movl	8(%esp), %ecx
	leal	0(%ebp,%eax,4), %eax
	leal	(%ecx,%edx,4), %edx
	vmovss	4(%eax), %xmm2
	vmulss	%xmm2, %xmm2, %xmm2
	vmovss	(%eax), %xmm1
	vmovss	8(%eax), %xmm0
	vfmadd132ss	%xmm1, %xmm2, %xmm1
	vfmadd132ss	%xmm0, %xmm1, %xmm0
	vsqrtss	%xmm0, %xmm1, %xmm1
	vucomiss	%xmm1, %xmm1
	jp	.L381
.L343:
	vmovss	%xmm1, (%edx)
	addl	$3, %ebx
	jmp	.L2
.L210:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	2(%ebx), %edx
	movsbl	1(%eax), %eax
	leal	0(%ebp,%edx,4), %edx
	leal	(%edi,%eax,4), %eax
	vmovss	4(%eax), %xmm2
	vmulss	%xmm2, %xmm2, %xmm2
	vmovss	(%eax), %xmm1
	vmovss	8(%eax), %xmm0
	vfmadd132ss	%xmm1, %xmm2, %xmm1
	vfmadd132ss	%xmm0, %xmm1, %xmm0
	vsqrtss	%xmm0, %xmm1, %xmm1
	vucomiss	%xmm1, %xmm1
	jp	.L382
.L341:
	vmovss	%xmm1, (%edx)
	addl	$3, %ebx
	jmp	.L2
.L209:
	movzbl	1(%ebx), %eax
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	movsbl	2(%edx), %edx
	leal	0(%ebp,%eax,4), %eax
	vmovss	4(%eax), %xmm2
	vmulss	%xmm2, %xmm2, %xmm2
	vmovss	(%eax), %xmm1
	vmovss	8(%eax), %xmm0
	leal	(%edi,%edx,4), %edx
	vfmadd132ss	%xmm1, %xmm2, %xmm1
	vfmadd132ss	%xmm0, %xmm1, %xmm0
	vsqrtss	%xmm0, %xmm1, %xmm1
	vucomiss	%xmm1, %xmm1
	jp	.L383
.L339:
	vmovss	%xmm1, (%edx)
	addl	$3, %ebx
	jmp	.L2
.L208:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	movsbl	1(%edx), %eax
	movsbl	2(%edx), %edx
	leal	(%edi,%eax,4), %eax
	leal	(%edi,%edx,4), %edx
	vmovss	4(%eax), %xmm2
	vmulss	%xmm2, %xmm2, %xmm2
	vmovss	(%eax), %xmm1
	vmovss	8(%eax), %xmm0
	vfmadd132ss	%xmm1, %xmm2, %xmm1
	vfmadd132ss	%xmm0, %xmm1, %xmm0
	vsqrtss	%xmm0, %xmm1, %xmm1
	vucomiss	%xmm1, %xmm1
	jp	.L384
.L337:
	vmovss	%xmm1, (%edx)
	addl	$3, %ebx
	jmp	.L2
.L207:
	movzbl	1(%ebx), %eax
	movzbl	2(%ebx), %edx
	movl	8(%esp), %ecx
	leal	0(%ebp,%eax,4), %eax
	leal	(%ecx,%edx,4), %edx
	vmovss	4(%eax), %xmm0
	vmulss	%xmm0, %xmm0, %xmm0
	vmovss	(%eax), %xmm1
	vmovss	8(%eax), %xmm2
	vfmadd231ss	%xmm1, %xmm1, %xmm0
	vfmadd132ss	%xmm2, %xmm0, %xmm2
	vsqrtss	%xmm2, %xmm3, %xmm3
	vucomiss	%xmm3, %xmm3
	jp	.L385
.L335:
	vmovss	.LC2, %xmm0
	addl	$3, %ebx
	vdivss	%xmm3, %xmm0, %xmm0
	vmulss	%xmm0, %xmm1, %xmm1
	vmovss	%xmm1, (%edx)
	vmulss	4(%eax), %xmm0, %xmm1
	vmovss	%xmm1, 4(%edx)
	vmulss	8(%eax), %xmm0, %xmm0
	vmovss	%xmm0, 8(%edx)
	jmp	.L2
.L206:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	2(%ebx), %edx
	movsbl	1(%eax), %eax
	leal	0(%ebp,%edx,4), %edx
	leal	(%edi,%eax,4), %eax
	vmovss	4(%eax), %xmm0
	vmulss	%xmm0, %xmm0, %xmm0
	vmovss	(%eax), %xmm1
	vmovss	8(%eax), %xmm2
	vfmadd231ss	%xmm1, %xmm1, %xmm0
	vfmadd132ss	%xmm2, %xmm0, %xmm2
	vsqrtss	%xmm2, %xmm3, %xmm3
	vucomiss	%xmm3, %xmm3
	jp	.L386
.L333:
	vmovss	.LC2, %xmm0
	addl	$3, %ebx
	vdivss	%xmm3, %xmm0, %xmm0
	vmulss	%xmm0, %xmm1, %xmm1
	vmovss	%xmm1, (%edx)
	vmulss	4(%eax), %xmm0, %xmm1
	vmovss	%xmm1, 4(%edx)
	vmulss	8(%eax), %xmm0, %xmm0
	vmovss	%xmm0, 8(%edx)
	jmp	.L2
.L205:
	movzbl	1(%ebx), %eax
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	movsbl	2(%edx), %edx
	leal	0(%ebp,%eax,4), %eax
	vmovss	4(%eax), %xmm0
	vmulss	%xmm0, %xmm0, %xmm0
	vmovss	(%eax), %xmm1
	vmovss	8(%eax), %xmm2
	leal	(%edi,%edx,4), %edx
	vfmadd231ss	%xmm1, %xmm1, %xmm0
	vfmadd132ss	%xmm2, %xmm0, %xmm2
	vsqrtss	%xmm2, %xmm3, %xmm3
	vucomiss	%xmm3, %xmm3
	jp	.L387
.L331:
	vmovss	.LC2, %xmm0
	addl	$3, %ebx
	vdivss	%xmm3, %xmm0, %xmm0
	vmulss	%xmm0, %xmm1, %xmm1
	vmovss	%xmm1, (%edx)
	vmulss	4(%eax), %xmm0, %xmm1
	vmovss	%xmm1, 4(%edx)
	vmulss	8(%eax), %xmm0, %xmm0
	vmovss	%xmm0, 8(%edx)
	jmp	.L2
.L204:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	movsbl	1(%edx), %eax
	movsbl	2(%edx), %edx
	leal	(%edi,%eax,4), %eax
	leal	(%edi,%edx,4), %edx
	vmovss	4(%eax), %xmm0
	vmulss	%xmm0, %xmm0, %xmm0
	vmovss	(%eax), %xmm1
	vmovss	8(%eax), %xmm2
	vfmadd231ss	%xmm1, %xmm1, %xmm0
	vfmadd132ss	%xmm2, %xmm0, %xmm2
	vsqrtss	%xmm2, %xmm3, %xmm3
	vucomiss	%xmm3, %xmm3
	jp	.L388
.L329:
	vmovss	.LC2, %xmm0
	addl	$3, %ebx
	vdivss	%xmm3, %xmm0, %xmm0
	vmulss	%xmm0, %xmm1, %xmm1
	vmovss	%xmm1, (%edx)
	vmulss	4(%eax), %xmm0, %xmm1
	vmovss	%xmm1, 4(%edx)
	vmulss	8(%eax), %xmm0, %xmm0
	vmovss	%xmm0, 8(%edx)
	jmp	.L2
.L203:
	movzbl	1(%ebx), %eax
	movl	8(%esp), %ecx
	addl	$3, %ebx
	leal	0(%ebp,%eax,4), %edx
	movzbl	-1(%ebx), %eax
	vmovss	(%edx), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	leal	(%ecx,%eax,4), %eax
	vmovss	%xmm0, (%eax)
	vmovss	4(%edx), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%edx), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L202:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movsbl	1(%eax), %eax
	leal	(%edi,%eax,4), %edx
	movzbl	-1(%ebx), %eax
	vmovss	(%edx), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	leal	0(%ebp,%eax,4), %eax
	vmovss	%xmm0, (%eax)
	vmovss	4(%edx), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%edx), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L201:
	movzbl	1(%ebx), %eax
	addl	$3, %ebx
	leal	0(%ebp,%eax,4), %edx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	vmovss	(%edx), %xmm0
	movsbl	2(%eax), %eax
	vxorps	.LC3, %xmm0, %xmm0
	leal	(%edi,%eax,4), %eax
	vmovss	%xmm0, (%eax)
	vmovss	4(%edx), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%edx), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L200:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %eax
	leal	(%edi,%edx,4), %edx
	leal	(%edi,%eax,4), %eax
	vmovss	(%edx), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, (%eax)
	vmovss	4(%edx), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%edx), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L199:
	movzbl	1(%ebx), %eax
	movl	8(%esp), %ecx
	addl	$3, %ebx
	leal	0(%ebp,%eax,4), %edx
	movzbl	-1(%ebx), %eax
	leal	(%ecx,%eax,4), %eax
	movl	(%edx), %ecx
	movl	%ecx, (%eax)
	movl	4(%edx), %ecx
	movl	%ecx, 4(%eax)
	movl	8(%edx), %edx
	movl	%edx, 8(%eax)
	jmp	.L2
.L198:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movsbl	1(%eax), %eax
	leal	(%edi,%eax,4), %edx
	movzbl	-1(%ebx), %eax
	movl	(%edx), %ecx
	leal	0(%ebp,%eax,4), %eax
	movl	%ecx, (%eax)
	movl	4(%edx), %ecx
	movl	%ecx, 4(%eax)
	movl	8(%edx), %edx
	movl	%edx, 8(%eax)
	jmp	.L2
.L197:
	movzbl	1(%ebx), %eax
	addl	$3, %ebx
	leal	0(%ebp,%eax,4), %edx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movl	(%edx), %ecx
	movsbl	2(%eax), %eax
	leal	(%edi,%eax,4), %eax
	movl	%ecx, (%eax)
	movl	4(%edx), %ecx
	movl	%ecx, 4(%eax)
	movl	8(%edx), %edx
	movl	%edx, 8(%eax)
	jmp	.L2
.L196:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %eax
	leal	(%edi,%edx,4), %edx
	leal	(%edi,%eax,4), %eax
	movl	(%edx), %ecx
	movl	%ecx, (%eax)
	movl	4(%edx), %ecx
	movl	%ecx, 4(%eax)
	movl	8(%edx), %edx
	movl	%edx, 8(%eax)
	jmp	.L2
.L195:
	movzbl	1(%ebx), %eax
	movzbl	2(%ebx), %edx
	movl	8(%esp), %ecx
	leal	0(%ebp,%eax,4), %eax
	leal	(%ecx,%edx,4), %edx
	movl	(%eax), %ecx
	cmpl	%ecx, (%edx)
	je	.L389
.L327:
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
	je	.L390
.L325:
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L193:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %eax
	leal	(%edi,%edx,4), %edx
	leal	(%edi,%eax,4), %eax
	movl	(%edx), %ecx
	cmpl	%ecx, (%eax)
	je	.L391
.L323:
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L192:
	movzbl	1(%ebx), %eax
	movzbl	2(%ebx), %edx
	movl	8(%esp), %ecx
	leal	0(%ebp,%eax,4), %eax
	leal	(%ecx,%edx,4), %edx
	movl	(%eax), %ecx
	cmpl	%ecx, (%edx)
	je	.L392
.L322:
	addl	$5, %ebx
	jmp	.L2
.L191:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	movzbl	1(%ebx), %eax
	movsbl	2(%edx), %edx
	leal	0(%ebp,%eax,4), %eax
	movl	(%eax), %ecx
	leal	(%edi,%edx,4), %edx
	cmpl	%ecx, (%edx)
	je	.L393
.L321:
	addl	$5, %ebx
	jmp	.L2
.L190:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %eax
	leal	(%edi,%edx,4), %edx
	leal	(%edi,%eax,4), %eax
	movl	(%edx), %ecx
	cmpl	%ecx, (%eax)
	je	.L394
.L320:
	addl	$5, %ebx
	jmp	.L2
.L189:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %eax
	leal	(%edi,%eax,4), %edx
	movl	%edx, 20(%esp)
	call	rand
	vxorps	%xmm2, %xmm2, %xmm2
	vmovss	.LC4, %xmm5
	vcvtsi2ss	%eax, %xmm2, %xmm2
	vfmadd132ss	.LC1, %xmm5, %xmm2
	vmovss	%xmm2, 16(%esp)
	call	rand
	vxorps	%xmm1, %xmm1, %xmm1
	vmovss	.LC4, %xmm6
	vcvtsi2ss	%eax, %xmm1, %xmm1
	vfmadd132ss	.LC1, %xmm6, %xmm1
	vmovss	%xmm1, 12(%esp)
	call	rand
	vmovss	12(%esp), %xmm1
	vmulss	%xmm1, %xmm1, %xmm3
	vmovss	.LC4, %xmm7
	vxorps	%xmm0, %xmm0, %xmm0
	movl	20(%esp), %edx
	vmovss	16(%esp), %xmm2
	vcvtsi2ss	%eax, %xmm0, %xmm0
	vfmadd231ss	%xmm2, %xmm2, %xmm3
	vfmadd132ss	.LC1, %xmm7, %xmm0
	vfmadd231ss	%xmm0, %xmm0, %xmm3
	vsqrtss	%xmm3, %xmm4, %xmm4
	vucomiss	%xmm4, %xmm4
	jp	.L395
.L318:
	vmovss	.LC2, %xmm3
	addl	$2, %ebx
	vdivss	%xmm4, %xmm3, %xmm3
	vmulss	%xmm3, %xmm2, %xmm2
	vmulss	%xmm3, %xmm1, %xmm1
	vmulss	%xmm3, %xmm0, %xmm0
	vmovss	%xmm2, (%edx)
	vmovss	%xmm1, 4(%edx)
	vmovss	%xmm0, 8(%edx)
	jmp	.L2
.L188:
	movzbl	1(%ebx), %eax
	movl	8(%esp), %ecx
	addl	$4, %ebx
	vmovss	0(%ebp,%eax,4), %xmm0
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %edx
	movzbl	-1(%ebx), %eax
	vminss	(%edi,%edx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%ecx,%eax,4)
	jmp	.L2
.L187:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	1(%eax), %edx
	vmovss	(%edi,%edx,4), %xmm0
	movsbl	2(%eax), %edx
	movzbl	-3(%ebx), %eax
	vminss	(%edi,%edx,4), %xmm0, %xmm0
	vmovss	%xmm0, 0(%ebp,%eax,4)
	jmp	.L2
.L186:
	movzbl	1(%ebx), %eax
	addl	$4, %ebx
	vmovss	0(%ebp,%eax,4), %xmm0
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %edx
	movsbl	3(%eax), %eax
	vminss	(%edi,%edx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L185:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	1(%eax), %edx
	vmovss	(%edi,%edx,4), %xmm0
	movsbl	2(%eax), %edx
	movsbl	3(%eax), %eax
	vminss	(%edi,%edx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L184:
	movzbl	1(%ebx), %eax
	movl	8(%esp), %ecx
	addl	$4, %ebx
	vmovss	0(%ebp,%eax,4), %xmm0
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %edx
	movzbl	-1(%ebx), %eax
	vmaxss	(%edi,%edx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%ecx,%eax,4)
	jmp	.L2
.L183:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	1(%eax), %edx
	vmovss	(%edi,%edx,4), %xmm0
	movsbl	2(%eax), %edx
	movzbl	-3(%ebx), %eax
	vmaxss	(%edi,%edx,4), %xmm0, %xmm0
	vmovss	%xmm0, 0(%ebp,%eax,4)
	jmp	.L2
.L182:
	movzbl	1(%ebx), %eax
	addl	$4, %ebx
	vmovss	0(%ebp,%eax,4), %xmm0
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %edx
	movsbl	3(%eax), %eax
	vmaxss	(%edi,%edx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L181:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	1(%eax), %edx
	vmovss	(%edi,%edx,4), %xmm0
	movsbl	2(%eax), %edx
	movsbl	3(%eax), %eax
	vmaxss	(%edi,%edx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L180:
	movzbl	3(%ebx), %eax
	movl	8(%esp), %ecx
	subl	$8, %esp
	.cfi_def_cfa_offset 72
	movzbl	2(%ebx), %edx
	addl	$4, %ebx
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
	movl	28(%esp), %edx
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movl	%edx, (%eax)
	jmp	.L2
.L179:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	subl	$8, %esp
	.cfi_def_cfa_offset 72
	movzbl	2(%ebx), %edx
	addl	$4, %ebx
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
	movl	28(%esp), %edx
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movl	%edx, (%eax)
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
	movl	28(%esp), %eax
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movl	%eax, (%edx)
	jmp	.L2
.L177:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	movzbl	3(%ebx), %eax
	subl	$8, %esp
	.cfi_def_cfa_offset 72
	movl	16(%esp), %ecx
	addl	$4, %ebx
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
	movl	28(%esp), %edx
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movl	%edx, (%eax)
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
	movl	28(%esp), %eax
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movl	%eax, (%edx)
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
	movl	28(%esp), %eax
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movl	%eax, (%edx)
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
	movl	28(%esp), %eax
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movl	%eax, (%edx)
	jmp	.L2
.L173:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	movzbl	3(%ebx), %eax
	addl	$4, %ebx
	movsbl	1(%edx), %ecx
	movzbl	-2(%ebx), %edx
	vmovss	(%edi,%ecx,4), %xmm0
	movl	8(%esp), %ecx
	vdivss	0(%ebp,%edx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%ecx,%eax,4)
	jmp	.L2
.L172:
	movzbl	1(%ebx), %ecx
	movzbl	2(%ebx), %edx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	vmovss	0(%ebp,%ecx,4), %xmm0
	movl	8(%esp), %ecx
	movsbl	3(%eax), %eax
	vdivss	(%ecx,%edx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L171:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movsbl	3(%eax), %edx
	movsbl	2(%eax), %eax
	vmovss	0(%ebp,%ecx,4), %xmm0
	vdivss	(%edi,%eax,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edi,%edx,4)
	jmp	.L2
.L170:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movzbl	-1(%ebx), %eax
	movsbl	2(%edx), %edx
	vmovss	0(%ebp,%ecx,4), %xmm0
	movl	8(%esp), %ecx
	vdivss	(%edi,%edx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%ecx,%eax,4)
	jmp	.L2
.L169:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	3(%ebx), %edx
	addl	$4, %ebx
	movsbl	1(%eax), %ecx
	movsbl	2(%eax), %eax
	vmovss	(%edi,%ecx,4), %xmm0
	vdivss	(%edi,%eax,4), %xmm0, %xmm0
	vmovss	%xmm0, 0(%ebp,%edx,4)
	jmp	.L2
.L168:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movsbl	3(%eax), %edx
	movsbl	2(%eax), %eax
	vmovss	0(%ebp,%ecx,4), %xmm0
	vdivss	(%edi,%eax,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edi,%edx,4)
	jmp	.L2
.L167:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	1(%eax), %ecx
	movsbl	3(%eax), %edx
	movsbl	2(%eax), %eax
	vmovss	(%edi,%ecx,4), %xmm0
	vdivss	(%edi,%eax,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edi,%edx,4)
	jmp	.L2
.L166:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	movzbl	3(%ebx), %eax
	addl	$4, %ebx
	movsbl	2(%edx), %ecx
	movzbl	-3(%ebx), %edx
	vmovss	(%edi,%ecx,4), %xmm0
	movl	8(%esp), %ecx
	vmulss	0(%ebp,%edx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%ecx,%eax,4)
	jmp	.L2
.L165:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	3(%ebx), %edx
	addl	$4, %ebx
	movsbl	1(%eax), %ecx
	movsbl	2(%eax), %eax
	vmovss	(%edi,%ecx,4), %xmm0
	vmulss	(%edi,%eax,4), %xmm0, %xmm0
	vmovss	%xmm0, 0(%ebp,%edx,4)
	jmp	.L2
.L164:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movsbl	3(%eax), %edx
	movsbl	2(%eax), %eax
	vmovss	0(%ebp,%ecx,4), %xmm0
	vmulss	(%edi,%eax,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edi,%edx,4)
	jmp	.L2
.L163:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	1(%eax), %ecx
	movsbl	3(%eax), %edx
	movsbl	2(%eax), %eax
	vmovss	(%edi,%ecx,4), %xmm0
	vmulss	(%edi,%eax,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edi,%edx,4)
	jmp	.L2
.L162:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	movzbl	3(%ebx), %eax
	addl	$4, %ebx
	movsbl	1(%edx), %ecx
	movzbl	-2(%ebx), %edx
	vmovss	(%edi,%ecx,4), %xmm0
	movl	8(%esp), %ecx
	vsubss	0(%ebp,%edx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%ecx,%eax,4)
	jmp	.L2
.L161:
	movzbl	1(%ebx), %ecx
	movzbl	2(%ebx), %edx
	addl	$4, %ebx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	vmovss	0(%ebp,%ecx,4), %xmm0
	movl	8(%esp), %ecx
	movsbl	3(%eax), %eax
	vsubss	(%ecx,%edx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L160:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	1(%eax), %ecx
	movsbl	3(%eax), %edx
	movzbl	-3(%ebx), %eax
	vmovss	(%edi,%ecx,4), %xmm0
	vsubss	0(%ebp,%eax,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edi,%edx,4)
	jmp	.L2
.L159:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movzbl	-1(%ebx), %eax
	movsbl	2(%edx), %edx
	vmovss	0(%ebp,%ecx,4), %xmm0
	movl	8(%esp), %ecx
	vsubss	(%edi,%edx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%ecx,%eax,4)
	jmp	.L2
.L158:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	3(%ebx), %edx
	addl	$4, %ebx
	movsbl	1(%eax), %ecx
	movsbl	2(%eax), %eax
	vmovss	(%edi,%ecx,4), %xmm0
	vsubss	(%edi,%eax,4), %xmm0, %xmm0
	vmovss	%xmm0, 0(%ebp,%edx,4)
	jmp	.L2
.L157:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movsbl	3(%eax), %edx
	movsbl	2(%eax), %eax
	vmovss	0(%ebp,%ecx,4), %xmm0
	vsubss	(%edi,%eax,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edi,%edx,4)
	jmp	.L2
.L156:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	1(%eax), %ecx
	movsbl	3(%eax), %edx
	movsbl	2(%eax), %eax
	vmovss	(%edi,%ecx,4), %xmm0
	vsubss	(%edi,%eax,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edi,%edx,4)
	jmp	.L2
.L155:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	movzbl	3(%ebx), %eax
	addl	$4, %ebx
	movsbl	2(%edx), %ecx
	movzbl	-3(%ebx), %edx
	vmovss	(%edi,%ecx,4), %xmm0
	movl	8(%esp), %ecx
	vaddss	0(%ebp,%edx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%ecx,%eax,4)
	jmp	.L2
.L154:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	3(%ebx), %edx
	addl	$4, %ebx
	movsbl	1(%eax), %ecx
	movsbl	2(%eax), %eax
	vmovss	(%edi,%ecx,4), %xmm0
	vaddss	(%edi,%eax,4), %xmm0, %xmm0
	vmovss	%xmm0, 0(%ebp,%edx,4)
	jmp	.L2
.L153:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movsbl	3(%eax), %edx
	movsbl	2(%eax), %eax
	vmovss	0(%ebp,%ecx,4), %xmm0
	vaddss	(%edi,%eax,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edi,%edx,4)
	jmp	.L2
.L152:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	1(%eax), %ecx
	movsbl	3(%eax), %edx
	movsbl	2(%eax), %eax
	vmovss	(%edi,%ecx,4), %xmm0
	vaddss	(%edi,%eax,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edi,%edx,4)
	jmp	.L2
.L151:
	movzbl	1(%ebx), %edx
	movzbl	2(%ebx), %eax
	addl	$3, %ebx
	movl	8(%esp), %ecx
	vmovss	0(%ebp,%edx,4), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, (%ecx,%eax,4)
	jmp	.L2
.L150:
	movl	_ZN3GVM11Interpreter14programCounterE, %edx
	movzbl	2(%ebx), %eax
	addl	$3, %ebx
	movsbl	1(%edx), %edx
	vmovss	(%edi,%edx,4), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, 0(%ebp,%eax,4)
	jmp	.L2
.L149:
	movzbl	1(%ebx), %edx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movsbl	2(%eax), %eax
	vmovss	0(%ebp,%edx,4), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L148:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movsbl	2(%eax), %edx
	movsbl	1(%eax), %eax
	vmovss	(%edi,%eax,4), %xmm0
	vxorps	.LC3, %xmm0, %xmm0
	vmovss	%xmm0, (%edi,%edx,4)
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
	movl	28(%esp), %eax
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movl	%eax, (%edx)
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
	movl	12(%esp), %edx
	movsbl	2(%eax), %eax
	movl	%edx, (%edi,%eax,4)
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
	movl	12(%esp), %edx
	movsbl	2(%eax), %eax
	movl	%edx, (%edi,%eax,4)
	jmp	.L2
.L144:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	vmovss	.LC2, %xmm1
	addl	$3, %ebx
	movsbl	1(%eax), %edx
	movsbl	2(%eax), %eax
	vmovss	(%edi,%edx,4), %xmm0
	vmulss	%xmm0, %xmm0, %xmm0
	vdivss	%xmm0, %xmm1, %xmm0
	vmovss	%xmm0, (%edi,%eax,4)
	jmp	.L2
.L143:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %edx
	movsbl	1(%eax), %eax
	vsqrtss	(%edi,%eax,4), %xmm0, %xmm0
	vucomiss	%xmm0, %xmm0
	leal	(%edi,%edx,4), %edx
	jp	.L396
.L308:
	vmovss	%xmm0, (%edx)
	addl	$3, %ebx
	jmp	.L2
.L142:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	vmovss	.LC2, %xmm0
	addl	$3, %ebx
	movsbl	2(%eax), %edx
	movsbl	1(%eax), %eax
	vdivss	(%edi,%eax,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edi,%edx,4)
	jmp	.L2
.L141:
	movzbl	1(%ebx), %edx
	movzbl	2(%ebx), %eax
	movl	8(%esp), %ecx
	vmovss	0(%ebp,%edx,4), %xmm0
	vucomiss	(%ecx,%eax,4), %xmm0
	jbe	.L369
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
	vmovss	(%edi,%edx,4), %xmm0
	vucomiss	0(%ebp,%eax,4), %xmm0
	jbe	.L368
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
	vmovss	0(%ebp,%edx,4), %xmm0
	vucomiss	(%edi,%eax,4), %xmm0
	jbe	.L367
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
	vmovss	(%edi,%edx,4), %xmm0
	vucomiss	(%edi,%eax,4), %xmm0
	jbe	.L366
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
	vmovss	0(%ebp,%edx,4), %xmm0
	vucomiss	(%ecx,%eax,4), %xmm0
	jb	.L365
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
	vmovss	(%edi,%edx,4), %xmm0
	vucomiss	0(%ebp,%eax,4), %xmm0
	jb	.L364
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
	vmovss	0(%ebp,%edx,4), %xmm0
	vucomiss	(%edi,%eax,4), %xmm0
	jb	.L363
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
	vmovss	(%edi,%edx,4), %xmm0
	vucomiss	(%edi,%eax,4), %xmm0
	jb	.L362
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
	vxorps	%xmm0, %xmm0, %xmm0
	movl	12(%esp), %edx
	vcvtsi2ss	%eax, %xmm0, %xmm0
	vmulss	.LC1, %xmm0, %xmm0
	vmovss	%xmm0, (%edx)
	jmp	.L2
.L132:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	3(%ebx), %edx
	movsbl	2(%eax), %ecx
	movzbl	1(%ebx), %eax
	movl	0(%ebp,%eax,4), %eax
	cmpl	%eax, (%edi,%ecx,4)
	cmovle	(%edi,%ecx,4), %eax
	movl	8(%esp), %ecx
	addl	$4, %ebx
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
	movl	8(%esp), %ecx
	addl	$4, %ebx
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
	movzbl	1(%ebx), %eax
	addl	$4, %ebx
	movzbl	-1(%ebx), %edx
	movsbl	2(%ecx), %ecx
	movl	0(%ebp,%eax,4), %eax
	movl	(%edi,%ecx,4), %ecx
	shrx	%ecx, %eax, %eax
	movl	8(%esp), %ecx
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L123:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	movzbl	3(%ebx), %edx
	addl	$4, %ebx
	movsbl	1(%ecx), %eax
	movsbl	2(%ecx), %ecx
	movl	(%edi,%eax,4), %eax
	movl	(%edi,%ecx,4), %ecx
	shrx	%ecx, %eax, %eax
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L122:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	movzbl	1(%ebx), %eax
	addl	$4, %ebx
	movsbl	3(%ecx), %edx
	movsbl	2(%ecx), %ecx
	movl	0(%ebp,%eax,4), %eax
	movl	(%edi,%ecx,4), %ecx
	shrx	%ecx, %eax, %eax
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
	shrx	%ecx, %eax, %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L120:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	movzbl	1(%ebx), %eax
	addl	$4, %ebx
	movzbl	-1(%ebx), %edx
	movsbl	2(%ecx), %ecx
	movl	0(%ebp,%eax,4), %eax
	movl	(%edi,%ecx,4), %ecx
	shlx	%ecx, %eax, %eax
	movl	8(%esp), %ecx
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L119:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	movzbl	3(%ebx), %edx
	addl	$4, %ebx
	movsbl	1(%ecx), %eax
	movsbl	2(%ecx), %ecx
	movl	(%edi,%eax,4), %eax
	movl	(%edi,%ecx,4), %ecx
	shlx	%ecx, %eax, %eax
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L118:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	movzbl	1(%ebx), %eax
	addl	$4, %ebx
	movsbl	3(%ecx), %edx
	movsbl	2(%ecx), %ecx
	movl	0(%ebp,%eax,4), %eax
	movl	(%edi,%ecx,4), %ecx
	shlx	%ecx, %eax, %eax
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
	shlx	%ecx, %eax, %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L116:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movzbl	-1(%ebx), %edx
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %eax
	xorl	0(%ebp,%ecx,4), %eax
	movl	8(%esp), %ecx
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L115:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	movzbl	3(%ebx), %edx
	addl	$4, %ebx
	movsbl	1(%ecx), %eax
	movsbl	2(%ecx), %ecx
	movl	(%edi,%eax,4), %eax
	xorl	(%edi,%ecx,4), %eax
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L114:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	movzbl	1(%ebx), %eax
	addl	$4, %ebx
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
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movzbl	-1(%ebx), %edx
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %eax
	orl	0(%ebp,%ecx,4), %eax
	movl	8(%esp), %ecx
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L111:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	movzbl	3(%ebx), %edx
	addl	$4, %ebx
	movsbl	1(%ecx), %eax
	movsbl	2(%ecx), %ecx
	movl	(%edi,%eax,4), %eax
	orl	(%edi,%ecx,4), %eax
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L110:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	movzbl	1(%ebx), %eax
	addl	$4, %ebx
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
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movzbl	-1(%ebx), %edx
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %eax
	andl	0(%ebp,%ecx,4), %eax
	movl	8(%esp), %ecx
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L107:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	movzbl	3(%ebx), %edx
	addl	$4, %ebx
	movsbl	1(%ecx), %eax
	movsbl	2(%ecx), %ecx
	movl	(%edi,%eax,4), %eax
	andl	(%edi,%ecx,4), %eax
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L106:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	movzbl	1(%ebx), %eax
	addl	$4, %ebx
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
	je	.L374
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
	je	.L374
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
	je	.L374
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	3(%eax), %edx
	movsbl	1(%eax), %eax
	movl	(%edi,%eax,4), %eax
	movl	%edx, 12(%esp)
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
	je	.L374
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
	je	.L374
	movsbl	1(%eax), %eax
	movzbl	3(%ebx), %edx
	addl	$4, %ebx
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
	je	.L374
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
	je	.L374
	movsbl	3(%eax), %edx
	movsbl	1(%eax), %eax
	addl	$4, %ebx
	movl	(%edi,%eax,4), %eax
	movl	%edx, 12(%esp)
	cltd
	idivl	%ecx
	movl	12(%esp), %eax
	movl	%edx, (%edi,%eax,4)
	jmp	.L2
.L97:
	movzbl	2(%ebx), %eax
	movl	0(%ebp,%eax,4), %ecx
	testl	%ecx, %ecx
	je	.L374
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
	je	.L374
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
	je	.L374
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$4, %ebx
	movsbl	3(%eax), %edx
	movsbl	1(%eax), %eax
	movl	(%edi,%eax,4), %eax
	movl	%edx, 12(%esp)
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
	je	.L374
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
	je	.L374
	movsbl	1(%eax), %eax
	movzbl	3(%ebx), %edx
	addl	$4, %ebx
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
	je	.L374
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
	je	.L374
	movsbl	3(%eax), %edx
	movsbl	1(%eax), %eax
	addl	$4, %ebx
	movl	(%edi,%eax,4), %eax
	movl	%edx, 12(%esp)
	cltd
	idivl	%ecx
	movl	12(%esp), %edx
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L90:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movzbl	-1(%ebx), %edx
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %eax
	imull	0(%ebp,%ecx,4), %eax
	movl	8(%esp), %ecx
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L89:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	movzbl	3(%ebx), %edx
	addl	$4, %ebx
	movsbl	1(%ecx), %eax
	movsbl	2(%ecx), %ecx
	movl	(%edi,%eax,4), %eax
	imull	(%edi,%ecx,4), %eax
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L88:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	movzbl	1(%ebx), %eax
	addl	$4, %ebx
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
	movzbl	2(%ebx), %ecx
	addl	$4, %ebx
	movzbl	-1(%ebx), %edx
	movsbl	1(%eax), %eax
	movl	(%edi,%eax,4), %eax
	subl	0(%ebp,%ecx,4), %eax
	movl	8(%esp), %ecx
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L85:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movl	8(%esp), %edx
	addl	$4, %ebx
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
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
	movsbl	3(%eax), %edx
	movsbl	1(%eax), %eax
	movl	(%edi,%eax,4), %eax
	subl	0(%ebp,%ecx,4), %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L83:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	movzbl	1(%ebx), %eax
	addl	$4, %ebx
	movzbl	-1(%ebx), %edx
	movsbl	2(%ecx), %ecx
	movl	0(%ebp,%eax,4), %eax
	subl	(%edi,%ecx,4), %eax
	movl	8(%esp), %ecx
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L82:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	movzbl	3(%ebx), %edx
	addl	$4, %ebx
	movsbl	1(%ecx), %eax
	movsbl	2(%ecx), %ecx
	movl	(%edi,%eax,4), %eax
	subl	(%edi,%ecx,4), %eax
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L81:
	movl	_ZN3GVM11Interpreter14programCounterE, %ecx
	movzbl	1(%ebx), %eax
	addl	$4, %ebx
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
	movzbl	3(%ebx), %edx
	addl	$4, %ebx
	movsbl	2(%eax), %ecx
	movzbl	-3(%ebx), %eax
	movl	0(%ebp,%eax,4), %eax
	addl	(%edi,%ecx,4), %eax
	movl	8(%esp), %ecx
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L78:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	3(%ebx), %edx
	addl	$4, %ebx
	movsbl	1(%eax), %ecx
	movsbl	2(%eax), %eax
	movl	(%edi,%eax,4), %eax
	addl	(%edi,%ecx,4), %eax
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L77:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	1(%ebx), %ecx
	addl	$4, %ebx
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
	movzbl	2(%ebx), %edx
	addl	$3, %ebx
	movl	8(%esp), %ecx
	movl	0(%ebp,%eax,4), %eax
	negl	%eax
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L74:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	2(%ebx), %edx
	addl	$3, %ebx
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
	movzbl	2(%ebx), %edx
	addl	$3, %ebx
	movl	8(%esp), %ecx
	movl	0(%ebp,%eax,4), %eax
	notl	%eax
	movl	%eax, (%ecx,%edx,4)
	jmp	.L2
.L70:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	2(%ebx), %edx
	addl	$3, %ebx
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
	movzbl	2(%ebx), %edx
	movzbl	1(%ebx), %ecx
	movl	$1, %eax
	shlx	%ecx, %eax, %eax
	testl	%eax, 0(%ebp,%edx,4)
	jne	.L277
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
	shlx	%ecx, %eax, %eax
	testl	%eax, (%edi,%edx,4)
	jne	.L276
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L65:
	movzbl	2(%ebx), %edx
	movzbl	1(%ebx), %ecx
	movl	$1, %eax
	shlx	%ecx, %eax, %eax
	testl	%eax, 0(%ebp,%edx,4)
	je	.L275
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
	shlx	%ecx, %eax, %eax
	testl	%eax, (%edi,%edx,4)
	je	.L274
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L63:
	movzbl	1(%ebx), %ecx
	movzbl	2(%ebx), %edx
	movl	$-2, %eax
	addl	$3, %ebx
	roll	%cl, %eax
	andl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L62:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	1(%ebx), %ecx
	addl	$3, %ebx
	movsbl	2(%eax), %edx
	movl	$-2, %eax
	roll	%cl, %eax
	andl	%eax, (%edi,%edx,4)
	jmp	.L2
.L61:
	movzbl	1(%ebx), %ecx
	movzbl	2(%ebx), %edx
	movl	$1, %eax
	addl	$3, %ebx
	shlx	%ecx, %eax, %eax
	orl	%eax, 0(%ebp,%edx,4)
	jmp	.L2
.L60:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	1(%ebx), %ecx
	addl	$3, %ebx
	movsbl	2(%eax), %edx
	movl	$1, %eax
	shlx	%ecx, %eax, %eax
	orl	%eax, (%edi,%edx,4)
	jmp	.L2
.L59:
	movzbl	2(%ebx), %eax
	movsbl	1(%ebx), %edx
	addl	$3, %ebx
	movl	8(%esp), %ecx
	movl	%edx, (%ecx,%eax,4)
	jmp	.L2
.L58:
	movzbl	2(%ebx), %eax
	movsbl	1(%ebx), %edx
	addl	$3, %ebx
	movl	%edx, 0(%ebp,%eax,4)
	jmp	.L2
.L57:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%ebx), %edx
	addl	$3, %ebx
	movsbl	2(%eax), %eax
	movl	%edx, (%edi,%eax,4)
	jmp	.L2
.L56:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	1(%eax), %eax
	leal	(%edi,%eax,4), %edx
	subl	$1, (%edx)
	js	.L273
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
	je	.L272
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
	jle	.L271
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
	jle	.L270
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
	jle	.L269
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
	jle	.L268
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
	jl	.L267
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
	jl	.L266
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
	jl	.L265
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
	jl	.L264
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L46:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	vxorps	%xmm0, %xmm0, %xmm0
	addl	$3, %ebx
	movsbl	2(%eax), %edx
	movsbl	1(%eax), %eax
	vcvtsi2ss	(%edi,%eax,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edi,%edx,4)
	jmp	.L2
.L45:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	addl	$3, %ebx
	movsbl	2(%eax), %edx
	movsbl	1(%eax), %eax
	vcvttss2si	(%edi,%eax,4), %eax
	movl	%eax, (%edi,%edx,4)
	jmp	.L2
.L44:
	movzbl	1(%ebx), %eax
	movl	8(%esp), %ecx
	addl	$3, %ebx
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
	movl	8(%esp), %ecx
	addl	$3, %ebx
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
	movl	8(%esp), %ecx
	addl	$2, %ebx
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
	movzbl	3(%ebx), %edx
	addl	$4, %ebx
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
	movzbl	3(%ebx), %edx
	addl	$4, %ebx
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
	testw	%ax, %ax
	movzwl	%ax, %edx
	je	.L376
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
	testw	%ax, %ax
	movzwl	%ax, %edx
	je	.L376
	movl	_ZN3GVM11Interpreter9dataTableE, %eax
	addl	$3, %ebx
	movl	(%eax,%edx,4), %ebp
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	%ebp, 4(%eax)
	jmp	.L2
.L28:
	movzwl	1(%ebx), %eax
	rolw	$8, %ax
	testw	%ax, %ax
	movzwl	%ax, %edx
	je	.L376
	movl	_ZN3GVM11Interpreter9dataTableE, %eax
	movl	8(%esp), %ecx
	addl	$4, %ebx
	movl	(%eax,%edx,4), %edx
	movzbl	-1(%ebx), %eax
	movl	%edx, (%ecx,%eax,4)
	jmp	.L2
.L27:
	movzwl	1(%ebx), %eax
	rolw	$8, %ax
	testw	%ax, %ax
	movzwl	%ax, %edx
	je	.L376
	movl	_ZN3GVM11Interpreter9dataTableE, %eax
	addl	$4, %ebx
	movl	(%eax,%edx,4), %edx
	movzbl	-1(%ebx), %eax
	movl	%edx, 0(%ebp,%eax,4)
	jmp	.L2
.L26:
	movzwl	1(%ebx), %eax
	rolw	$8, %ax
	testw	%ax, %ax
	movzwl	%ax, %edx
	je	.L376
	movl	_ZN3GVM11Interpreter9dataTableE, %eax
	addl	$4, %ebx
	movl	(%eax,%edx,4), %edx
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	3(%eax), %eax
	movl	%edx, (%edi,%eax,4)
	jmp	.L2
.L25:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	1(%ebx), %edx
	addl	$3, %ebx
	movl	8(%esp), %ecx
	movsbl	2(%eax), %eax
	leal	(%ecx,%edx,4), %edx
	movl	%edx, (%edi,%eax,4)
	jmp	.L2
.L24:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	1(%ebx), %edx
	addl	$3, %ebx
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
	movzbl	1(%ebx), %edx
	movzbl	2(%ebx), %eax
	movl	8(%esp), %ecx
	movl	(%ecx,%eax,4), %eax
	cmpl	%eax, 0(%ebp,%edx,4)
	je	.L397
	addl	$5, %ebx
	jmp	.L2
.L21:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movzbl	2(%ebx), %edx
	movsbl	1(%eax), %eax
	movl	(%edi,%eax,4), %eax
	cmpl	%eax, 0(%ebp,%edx,4)
	je	.L398
	addl	$5, %ebx
	jmp	.L2
.L20:
	movl	_ZN3GVM11Interpreter14programCounterE, %eax
	movsbl	2(%eax), %edx
	movsbl	1(%eax), %eax
	movl	(%edi,%eax,4), %eax
	cmpl	%eax, (%edi,%edx,4)
	je	.L399
	addl	$5, %ebx
	jmp	.L2
.L19:
	movzbl	2(%ebx), %eax
	movl	0(%ebp,%eax,4), %eax
	testl	%eax, %eax
	je	.L255
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
	je	.L254
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
	jne	.L253
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
	jne	.L252
	movzbl	2(%ebx), %eax
	movzbl	3(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L15:
	movzbl	1(%ebx), %eax
	movl	8(%esp), %ecx
	movl	(%ecx,%eax,4), %eax
	testl	%eax, %eax
	movl	%eax, 8(%esp)
	je	.L400
	addl	$3, %ebx
	jmp	.L2
.L14:
	movzbl	1(%ebx), %eax
	movl	0(%ebp,%eax,4), %ebp
	testl	%ebp, %ebp
	je	.L401
	addl	$3, %ebx
	jmp	.L2
.L13:
	call	_ZN3GVM11Interpreter12exitFunctionEv
	testl	%eax, %eax
	jne	.L402
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	movl	4(%eax), %ebp
	movl	8(%eax), %eax
	movl	%eax, 8(%esp)
	jmp	.L2
.L12:
	movzbl	1(%ebx), %eax
	movzbl	2(%ebx), %edx
	subl	$12, %esp
	.cfi_def_cfa_offset 76
	sall	$8, %eax
	orl	%edx, %eax
	movzwl	%ax, %eax
	pushl	%eax
	.cfi_def_cfa_offset 80
	call	_ZN3GVM11Interpreter18invokeHostFunctionEt
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	testl	%eax, %eax
	jne	.L378
	addl	$3, %ebx
	jmp	.L2
.L11:
	movzbl	2(%ebx), %eax
	movl	0(%ebp,%eax,4), %eax
	movl	%eax, %edx
	andl	$-1073741824, %edx
	cmpl	$-2147483648, %edx
	jne	.L375
	subl	$8, %esp
	.cfi_def_cfa_offset 72
	movzwl	%ax, %eax
	pushl	%eax
	.cfi_def_cfa_offset 76
	leal	3(%ebx), %eax
	pushl	%eax
	.cfi_def_cfa_offset 80
	call	_ZN3GVM11Interpreter13enterFunctionEPKht
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	testl	%eax, %eax
	jne	.L378
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
	jne	.L375
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
	testl	%eax, %eax
	jne	.L378
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	movl	4(%eax), %ebp
	movl	8(%eax), %eax
	movl	%eax, 8(%esp)
	jmp	.L2
.L9:
	movzbl	1(%ebx), %eax
	movzbl	2(%ebx), %edx
	subl	$8, %esp
	.cfi_def_cfa_offset 72
	sall	$8, %eax
	orl	%edx, %eax
	movzwl	%ax, %eax
	pushl	%eax
	.cfi_def_cfa_offset 76
	leal	3(%ebx), %eax
	pushl	%eax
	.cfi_def_cfa_offset 80
	call	_ZN3GVM11Interpreter13enterFunctionEPKht
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	testl	%eax, %eax
	jne	.L378
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	movl	4(%eax), %ebp
	movl	8(%eax), %eax
	movl	%eax, 8(%esp)
	jmp	.L2
.L8:
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
	testl	%eax, %eax
	jne	.L378
	movl	_ZN3GVM11Interpreter9callStackE, %eax
	movl	_ZN3GVM11Interpreter10frameStackE, %edi
	movl	4(%eax), %ebp
	movl	8(%eax), %eax
	movl	%eax, 8(%esp)
	jmp	.L2
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
.L370:
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
	addl	$4, %ebx
	movsbl	1(%eax), %eax
	leal	(%edi,%eax,4), %edx
	movzbl	-2(%ebx), %eax
	vmovss	0(%ebp,%eax,4), %xmm0
	movzbl	-1(%ebx), %eax
	vmulss	(%edx), %xmm0, %xmm1
	leal	(%ecx,%eax,4), %eax
	vmovss	%xmm1, (%eax)
	vmulss	4(%edx), %xmm0, %xmm1
	vmovss	%xmm1, 4(%eax)
	vmulss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L2
.L252:
	addl	$4, %ebx
	jmp	.L2
.L253:
	addl	$5, %ebx
	jmp	.L2
.L254:
	addl	$4, %ebx
	jmp	.L2
.L255:
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
	addl	$5, %ebx
	jmp	.L2
.L271:
	addl	$5, %ebx
	jmp	.L2
.L272:
	addl	$4, %ebx
	jmp	.L2
.L274:
	addl	$3, %ebx
	jmp	.L2
.L275:
	addl	$3, %ebx
	jmp	.L2
.L276:
	addl	$3, %ebx
	jmp	.L2
.L277:
	addl	$3, %ebx
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
.L365:
	addl	$5, %ebx
	jmp	.L2
.L366:
	addl	$5, %ebx
	jmp	.L2
.L367:
	addl	$5, %ebx
	jmp	.L2
.L368:
	addl	$5, %ebx
	jmp	.L2
.L369:
	addl	$5, %ebx
	jmp	.L2
.L374:
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	movl	$10, %eax
	jmp	.L370
.L399:
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L398:
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L397:
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L394:
	movl	4(%edx), %ecx
	cmpl	%ecx, 4(%eax)
	jne	.L320
	movl	8(%edx), %ecx
	cmpl	%ecx, 8(%eax)
	jne	.L320
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L393:
	movl	4(%eax), %ecx
	cmpl	%ecx, 4(%edx)
	jne	.L321
	movl	8(%eax), %eax
	cmpl	%eax, 8(%edx)
	jne	.L321
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L392:
	movl	4(%eax), %ecx
	cmpl	%ecx, 4(%edx)
	jne	.L322
	movl	8(%eax), %eax
	cmpl	%eax, 8(%edx)
	jne	.L322
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L391:
	movl	4(%edx), %ecx
	cmpl	%ecx, 4(%eax)
	jne	.L323
	movl	8(%edx), %ecx
	cmpl	%ecx, 8(%eax)
	jne	.L323
	addl	$5, %ebx
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L390:
	movl	4(%eax), %ecx
	cmpl	%ecx, 4(%edx)
	jne	.L325
	movl	8(%eax), %eax
	cmpl	%eax, 8(%edx)
	jne	.L325
	addl	$5, %ebx
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L389:
	movl	4(%eax), %ecx
	cmpl	%ecx, 4(%edx)
	jne	.L327
	movl	8(%eax), %eax
	cmpl	%eax, 8(%edx)
	jne	.L327
	addl	$5, %ebx
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L273:
	addl	$4, %ebx
	jmp	.L2
.L400:
	movzbl	3(%ebx), %eax
	movzbl	4(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L401:
	movzbl	2(%ebx), %eax
	movzbl	3(%ebx), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cwtl
	addl	%eax, %ebx
	jmp	.L2
.L378:
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	jmp	.L370
.L376:
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	movl	$9, %eax
	jmp	.L370
.L375:
	movl	%ebx, _ZN3GVM11Interpreter14programCounterE
	movl	$7, %eax
	jmp	.L370
.L402:
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
	jmp	.L370
.L383:
	movl	%edx, 16(%esp)
	subl	$16, %esp
	.cfi_def_cfa_offset 80
	vmovss	%xmm0, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	fstps	12(%esp)
	movl	16(%esp), %edx
	vmovss	12(%esp), %xmm1
	jmp	.L339
.L382:
	movl	%edx, 16(%esp)
	subl	$16, %esp
	.cfi_def_cfa_offset 80
	vmovss	%xmm0, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	fstps	12(%esp)
	movl	16(%esp), %edx
	vmovss	12(%esp), %xmm1
	jmp	.L341
.L384:
	movl	%edx, 16(%esp)
	subl	$16, %esp
	.cfi_def_cfa_offset 80
	vmovss	%xmm0, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	fstps	12(%esp)
	movl	16(%esp), %edx
	vmovss	12(%esp), %xmm1
	jmp	.L337
.L385:
	movl	%edx, 20(%esp)
	movl	%eax, 16(%esp)
	subl	$16, %esp
	.cfi_def_cfa_offset 80
	vmovss	%xmm2, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movl	16(%esp), %eax
	fstps	12(%esp)
	movl	20(%esp), %edx
	vmovss	12(%esp), %xmm3
	vmovss	(%eax), %xmm1
	jmp	.L335
.L386:
	movl	%edx, 20(%esp)
	movl	%eax, 16(%esp)
	subl	$16, %esp
	.cfi_def_cfa_offset 80
	vmovss	%xmm2, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movl	16(%esp), %eax
	fstps	12(%esp)
	movl	20(%esp), %edx
	vmovss	12(%esp), %xmm3
	vmovss	(%eax), %xmm1
	jmp	.L333
.L395:
	vmovss	%xmm0, 28(%esp)
	movl	%edx, 16(%esp)
	subl	$16, %esp
	.cfi_def_cfa_offset 80
	vmovss	%xmm1, 40(%esp)
	vmovss	%xmm2, 36(%esp)
	vmovss	%xmm3, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	fstps	12(%esp)
	movl	16(%esp), %edx
	vmovss	28(%esp), %xmm0
	vmovss	12(%esp), %xmm4
	vmovss	24(%esp), %xmm1
	vmovss	20(%esp), %xmm2
	jmp	.L318
.L396:
	movl	%edx, 16(%esp)
	subl	$12, %esp
	.cfi_def_cfa_offset 76
	pushl	(%edi,%eax,4)
	.cfi_def_cfa_offset 80
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	fstps	12(%esp)
	movl	16(%esp), %edx
	vmovss	12(%esp), %xmm0
	jmp	.L308
.L387:
	movl	%edx, 20(%esp)
	movl	%eax, 16(%esp)
	subl	$16, %esp
	.cfi_def_cfa_offset 80
	vmovss	%xmm2, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movl	16(%esp), %eax
	fstps	12(%esp)
	movl	20(%esp), %edx
	vmovss	12(%esp), %xmm3
	vmovss	(%eax), %xmm1
	jmp	.L331
.L388:
	movl	%edx, 20(%esp)
	movl	%eax, 16(%esp)
	subl	$16, %esp
	.cfi_def_cfa_offset 80
	vmovss	%xmm2, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	movl	16(%esp), %eax
	fstps	12(%esp)
	movl	20(%esp), %edx
	vmovss	12(%esp), %xmm3
	vmovss	(%eax), %xmm1
	jmp	.L329
.L381:
	movl	%edx, 16(%esp)
	subl	$16, %esp
	.cfi_def_cfa_offset 80
	vmovss	%xmm0, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	fstps	12(%esp)
	movl	16(%esp), %edx
	vmovss	12(%esp), %xmm1
	jmp	.L343
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
