	.file	"interpreter.cpp"
	.section	.text.unlikely,"ax",@progbits
	.align 2
.LCOLDB5:
	.text
.LHOTB5:
	.align 2
	.p2align 4,,15
	.globl	_ZN3GVM11Interpreter7executeEv
	.type	_ZN3GVM11Interpreter7executeEv, @function
_ZN3GVM11Interpreter7executeEv:
.LFB119:
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
	subl	$28, %esp
	.cfi_def_cfa_offset 48
	movl	48(%esp), %ebp
	movl	80(%ebp), %edi
	movl	$0, 84(%ebp)
	.p2align 4,,10
	.p2align 3
.L3:
	leal	1(%edi), %eax
	leal	2(%edi), %ebx
	movl	%eax, 80(%ebp)
	movl	%eax, 12(%esp)
	movzbl	(%edi), %eax
	movl	%ebx, 80(%ebp)
	movzbl	-1(%ebx), %esi
	movl	%esi, %ecx
	movl	%esi, %edx
	movl	%esi, 4(%esp)
	andl	$15, %ecx
	sarl	$4, %esi
	cmpb	$-76, %al
	movb	%cl, (%esp)
	movl	%esi, %ecx
	movb	%cl, 11(%esp)
	ja	.L4
	jmp	*.L6(,%eax,4)
	.section	.rodata
	.align 4
	.align 4
.L6:
	.long	.L5
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
	.long	.L276
	.long	.L276
	.long	.L276
	.long	.L276
	.long	.L163
	.long	.L164
	.long	.L165
	.long	.L166
	.long	.L167
	.long	.L168
	.long	.L169
	.long	.L170
	.long	.L171
	.long	.L276
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
	.text
.L17:
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movl	4(%esp), %eax
	movzbl	2(%edi), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cmpw	124(%ebp), %ax
	jnb	.L338
	movl	116(%ebp), %edx
	movzwl	%ax, %eax
	movl	(%edx,%eax,4), %eax
	testl	%eax, %eax
	jne	.L339
	movl	$10, 84(%ebp)
.L18:
	movl	88(%ebp), %eax
	cmpl	96(%ebp), %eax
	jbe	.L190
	leal	-4(%eax), %edx
	movl	%edx, 88(%ebp)
	movl	-4(%eax), %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L16:
	leal	3(%edi), %ecx
	movl	4(%esp), %eax
	movl	%ecx, 80(%ebp)
	movzbl	2(%edi), %edx
	sall	$8, %eax
	orl	%edx, %eax
	cmpw	124(%ebp), %ax
	jnb	.L340
	movl	88(%ebp), %edx
	cmpl	100(%ebp), %edx
	jnb	.L185
	leal	4(%edx), %ebx
	movzwl	%ax, %eax
	movl	%ebx, 88(%ebp)
	movl	%ecx, (%edx)
	movl	112(%ebp), %edx
	movl	(%edx,%eax,4), %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L15:
	leal	3(%edi), %edx
	movl	4(%esp), %eax
	movl	%edx, 80(%ebp)
	movzbl	2(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movl	88(%ebp), %eax
	cmpl	100(%ebp), %eax
	jnb	.L185
	leal	4(%eax), %ecx
	movswl	%di, %edi
	movl	%ecx, 88(%ebp)
	movl	%edx, (%eax)
	addl	80(%ebp), %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L14:
	movzbl	2(%edi), %edi
	movl	4(%esp), %eax
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%ebx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L13:
	movsbl	%dl, %edx
	leal	(%ebx,%edx), %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L12:
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movl	0(%ebp,%esi,4), %ecx
	movl	(%ecx,%eax,4), %ebx
	movzbl	(%esp), %eax
	movzbl	3(%edi), %ecx
	movl	%edx, %edi
	movl	0(%ebp,%eax,4), %eax
	movl	%ebx, (%eax,%ecx,4)
	jmp	.L3
.L11:
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%eax, %edi
	movl	0(%ebp,%esi,4), %edx
	movl	(%edx,%ecx,4), %ecx
	movzbl	(%esp), %edx
	movl	%ecx, 0(%ebp,%edx,4)
	jmp	.L3
.L10:
	movzbl	(%esp), %edx
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%eax, %edi
	movl	0(%ebp,%esi,4), %ebx
	movl	0(%ebp,%edx,4), %edx
	movl	%ebx, (%edx,%ecx,4)
	jmp	.L3
.L9:
	movzbl	(%esp), %eax
	movl	0(%ebp,%esi,4), %edx
	movl	%ebx, %edi
	movl	%edx, 0(%ebp,%eax,4)
	jmp	.L3
.L8:
	movzbl	(%esp), %edx
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%eax, %edi
	movl	0(%ebp,%edx,4), %edx
	movl	%esi, (%edx,%ecx,4)
	jmp	.L3
.L7:
	movzbl	(%esp), %eax
	movl	%ebx, %edi
	movl	%esi, 0(%ebp,%eax,4)
	jmp	.L3
.L5:
	movl	12(%esp), %eax
	movl	%eax, 80(%ebp)
	movl	%eax, %edi
	jmp	.L3
.L177:
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	(%esp), %eax
	movzbl	2(%edi), %edx
	movl	0(%ebp,%eax,4), %eax
	leal	(%eax,%edx,4), %ebx
	vmovss	4(%ebx), %xmm1
	vmulss	%xmm1, %xmm1, %xmm3
	vmovss	(%ebx), %xmm2
	vmovss	8(%ebx), %xmm0
	vfmadd231ss	%xmm2, %xmm2, %xmm3
	vfmadd231ss	%xmm0, %xmm0, %xmm3
	vsqrtss	%xmm3, %xmm4, %xmm4
	vucomiss	%xmm4, %xmm4
	jp	.L341
.L266:
	vmovss	.LC3, %xmm3
	movl	80(%ebp), %edi
	vdivss	%xmm4, %xmm3, %xmm3
	vmulss	%xmm3, %xmm2, %xmm2
	vmulss	%xmm3, %xmm1, %xmm1
	vmulss	%xmm3, %xmm0, %xmm0
	vmovss	%xmm2, (%ebx)
	vmovss	%xmm1, 4(%ebx)
	vmovss	%xmm0, 8(%ebx)
	jmp	.L3
.L176:
	vmovss	68(%ebp), %xmm2
	vmulss	%xmm2, %xmm2, %xmm2
	vmovss	64(%ebp), %xmm1
	vmovss	72(%ebp), %xmm0
	vfmadd132ss	%xmm1, %xmm2, %xmm1
	vfmadd132ss	%xmm0, %xmm1, %xmm0
	vsqrtss	%xmm0, %xmm1, %xmm1
	vucomiss	%xmm1, %xmm1
	jp	.L342
.L264:
	movl	80(%ebp), %eax
	vmovss	%xmm1, 76(%ebp)
	leal	-1(%eax), %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L175:
	leal	3(%edi), %eax
	vmovss	68(%ebp), %xmm2
	vmulss	%xmm2, %xmm2, %xmm2
	vmovss	64(%ebp), %xmm1
	movl	%eax, 80(%ebp)
	movzbl	(%esp), %eax
	vmovss	72(%ebp), %xmm0
	movzbl	2(%edi), %edx
	vfmadd132ss	%xmm1, %xmm2, %xmm1
	vfmadd132ss	%xmm0, %xmm1, %xmm0
	vsqrtss	%xmm0, %xmm1, %xmm1
	vucomiss	%xmm1, %xmm1
	movl	0(%ebp,%eax,4), %eax
	leal	(%eax,%edx,4), %ebx
	jp	.L343
.L262:
	vmovss	%xmm1, (%ebx)
	movl	80(%ebp), %edi
	jmp	.L3
.L174:
	vmovss	68(%ebp), %xmm2
	vmulss	%xmm2, %xmm2, %xmm2
	vmovss	64(%ebp), %xmm1
	vmovss	72(%ebp), %xmm0
	vfmadd132ss	%xmm1, %xmm2, %xmm1
	vfmadd132ss	%xmm0, %xmm1, %xmm0
	vsqrtss	%xmm0, %xmm1, %xmm1
	vucomiss	%xmm1, %xmm1
	jp	.L344
.L260:
	movzbl	(%esp), %eax
	vmovss	%xmm1, 0(%ebp,%eax,4)
	movl	80(%ebp), %edi
	jmp	.L3
.L173:
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movl	0(%ebp,%esi,4), %edx
	movzbl	3(%edi), %ecx
	leal	(%edx,%eax,4), %eax
	movzbl	(%esp), %edx
	vmovss	4(%eax), %xmm2
	vmulss	%xmm2, %xmm2, %xmm2
	vmovss	(%eax), %xmm1
	vmovss	8(%eax), %xmm0
	movl	0(%ebp,%edx,4), %edx
	vfmadd132ss	%xmm1, %xmm2, %xmm1
	vfmadd132ss	%xmm0, %xmm1, %xmm0
	vsqrtss	%xmm0, %xmm1, %xmm1
	vucomiss	%xmm1, %xmm1
	leal	(%edx,%ecx,4), %ebx
	jp	.L345
.L258:
	vmovss	%xmm1, (%ebx)
	movl	80(%ebp), %edi
	jmp	.L3
.L172:
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %edx
	movl	0(%ebp,%esi,4), %eax
	leal	(%eax,%edx,4), %eax
	vmovss	4(%eax), %xmm2
	vmulss	%xmm2, %xmm2, %xmm2
	vmovss	(%eax), %xmm1
	vmovss	8(%eax), %xmm0
	vfmadd132ss	%xmm1, %xmm2, %xmm1
	vfmadd132ss	%xmm0, %xmm1, %xmm0
	vsqrtss	%xmm0, %xmm1, %xmm1
	vucomiss	%xmm1, %xmm1
	jp	.L346
.L256:
	movzbl	(%esp), %eax
	vmovss	%xmm1, 0(%ebp,%eax,4)
	movl	80(%ebp), %edi
	jmp	.L3
.L178:
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movl	0(%ebp,%esi,4), %edx
	leal	(%edx,%eax,4), %ebx
	movzbl	(%esp), %eax
	movzbl	3(%edi), %edx
	vmovss	4(%ebx), %xmm0
	vmulss	%xmm0, %xmm0, %xmm0
	vmovss	(%ebx), %xmm1
	vmovss	8(%ebx), %xmm2
	movl	0(%ebp,%eax,4), %eax
	vfmadd231ss	%xmm1, %xmm1, %xmm0
	vfmadd132ss	%xmm2, %xmm0, %xmm2
	vsqrtss	%xmm2, %xmm3, %xmm3
	vucomiss	%xmm3, %xmm3
	leal	(%eax,%edx,4), %esi
	jp	.L347
.L268:
	vmovss	.LC3, %xmm0
	movl	80(%ebp), %edi
	vdivss	%xmm3, %xmm0, %xmm0
	vmulss	%xmm0, %xmm1, %xmm1
	vmovss	%xmm1, (%esi)
	vmulss	4(%ebx), %xmm0, %xmm1
	vmovss	%xmm1, 4(%esi)
	vmulss	8(%ebx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%esi)
	jmp	.L3
.L171:
	leal	3(%edi), %eax
	leal	4(%edi), %ecx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%ecx, 80(%ebp)
	movl	0(%ebp,%esi,4), %edx
	movzbl	3(%edi), %ebx
	movl	%ecx, %edi
	leal	(%edx,%eax,4), %eax
	movzbl	(%esp), %edx
	movl	0(%ebp,%edx,4), %edx
	leal	(%edx,%ebx,4), %edx
	vmovss	(%edx), %xmm0
	vsubss	(%eax), %xmm0, %xmm0
	vmovss	%xmm0, 64(%ebp)
	vmovss	4(%edx), %xmm0
	vsubss	4(%eax), %xmm0, %xmm0
	vmovss	%xmm0, 68(%ebp)
	vmovss	8(%edx), %xmm0
	vsubss	8(%eax), %xmm0, %xmm0
	vmovss	%xmm0, 72(%ebp)
	jmp	.L3
.L170:
	leal	3(%edi), %eax
	leal	4(%edi), %ecx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%ecx, 80(%ebp)
	movl	0(%ebp,%esi,4), %edx
	movzbl	3(%edi), %ebx
	movl	%ecx, %edi
	leal	(%edx,%eax,4), %eax
	movzbl	(%esp), %edx
	movl	0(%ebp,%edx,4), %edx
	leal	(%edx,%ebx,4), %edx
	vmovss	(%edx), %xmm0
	vsubss	(%eax), %xmm0, %xmm0
	vmovss	%xmm0, 64(%ebp)
	vmovss	4(%edx), %xmm0
	vsubss	4(%eax), %xmm0, %xmm0
	vmovss	%xmm0, 68(%ebp)
	vmovss	8(%edx), %xmm0
	vsubss	8(%eax), %xmm0, %xmm0
	vmovss	%xmm0, 72(%ebp)
	jmp	.L3
.L169:
	movzbl	(%esp), %eax
	leal	3(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%edx, %edi
	movl	0(%ebp,%eax,4), %eax
	leal	(%eax,%ecx,4), %eax
	vmovss	(%eax), %xmm0
	vsubss	64(%ebp), %xmm0, %xmm0
	vmovss	%xmm0, (%eax)
	vmovss	4(%eax), %xmm0
	vsubss	68(%ebp), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%eax), %xmm0
	vsubss	72(%ebp), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L3
.L168:
	leal	3(%edi), %edx
	vmovss	64(%ebp), %xmm0
	movl	%edx, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%edx, %edi
	movl	0(%ebp,%esi,4), %eax
	leal	(%eax,%ecx,4), %eax
	vsubss	(%eax), %xmm0, %xmm0
	vmovss	%xmm0, 64(%ebp)
	vmovss	68(%ebp), %xmm0
	vsubss	4(%eax), %xmm0, %xmm0
	vmovss	%xmm0, 68(%ebp)
	vmovss	72(%ebp), %xmm0
	vsubss	8(%eax), %xmm0, %xmm0
	vmovss	%xmm0, 72(%ebp)
	jmp	.L3
.L167:
	leal	3(%edi), %eax
	leal	4(%edi), %ecx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%ecx, 80(%ebp)
	movl	0(%ebp,%esi,4), %edx
	movzbl	3(%edi), %ebx
	movl	%ecx, %edi
	leal	(%edx,%eax,4), %edx
	movzbl	(%esp), %eax
	movl	0(%ebp,%eax,4), %eax
	leal	(%eax,%ebx,4), %eax
	vmovss	(%eax), %xmm0
	vsubss	(%edx), %xmm0, %xmm0
	vmovss	%xmm0, (%eax)
	vmovss	4(%eax), %xmm0
	vsubss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%eax), %xmm0
	vsubss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L3
.L166:
	leal	3(%edi), %eax
	leal	4(%edi), %ecx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%ecx, 80(%ebp)
	movl	0(%ebp,%esi,4), %edx
	movzbl	3(%edi), %ebx
	movl	%ecx, %edi
	leal	(%edx,%eax,4), %eax
	movzbl	(%esp), %edx
	movl	0(%ebp,%edx,4), %edx
	leal	(%edx,%ebx,4), %edx
	vmovss	(%edx), %xmm0
	vaddss	(%eax), %xmm0, %xmm0
	vmovss	%xmm0, 64(%ebp)
	vmovss	4(%edx), %xmm0
	vaddss	4(%eax), %xmm0, %xmm0
	vmovss	%xmm0, 68(%ebp)
	vmovss	8(%edx), %xmm0
	vaddss	8(%eax), %xmm0, %xmm0
	vmovss	%xmm0, 72(%ebp)
	jmp	.L3
.L165:
	movzbl	(%esp), %eax
	leal	3(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%edx, %edi
	movl	0(%ebp,%eax,4), %eax
	leal	(%eax,%ecx,4), %eax
	vmovss	(%eax), %xmm0
	vaddss	64(%ebp), %xmm0, %xmm0
	vmovss	%xmm0, (%eax)
	vmovss	4(%eax), %xmm0
	vaddss	68(%ebp), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%eax), %xmm0
	vaddss	72(%ebp), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L3
.L164:
	leal	3(%edi), %edx
	vmovss	64(%ebp), %xmm0
	movl	%edx, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%edx, %edi
	movl	0(%ebp,%esi,4), %eax
	leal	(%eax,%ecx,4), %eax
	vaddss	(%eax), %xmm0, %xmm0
	vmovss	%xmm0, 64(%ebp)
	vmovss	68(%ebp), %xmm0
	vaddss	4(%eax), %xmm0, %xmm0
	vmovss	%xmm0, 68(%ebp)
	vmovss	72(%ebp), %xmm0
	vaddss	8(%eax), %xmm0, %xmm0
	vmovss	%xmm0, 72(%ebp)
	jmp	.L3
.L163:
	leal	3(%edi), %eax
	leal	4(%edi), %ecx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%ecx, 80(%ebp)
	movl	0(%ebp,%esi,4), %edx
	movzbl	3(%edi), %ebx
	movl	%ecx, %edi
	leal	(%edx,%eax,4), %edx
	movzbl	(%esp), %eax
	movl	0(%ebp,%eax,4), %eax
	leal	(%eax,%ebx,4), %eax
	vmovss	(%eax), %xmm0
	vaddss	(%edx), %xmm0, %xmm0
	vmovss	%xmm0, (%eax)
	vmovss	4(%eax), %xmm0
	vaddss	4(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%eax), %xmm0
	vaddss	8(%edx), %xmm0, %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L3
.L179:
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %edx
	movl	0(%ebp,%esi,4), %eax
	leal	(%eax,%edx,4), %ebx
	vmovss	4(%ebx), %xmm0
	vmulss	%xmm0, %xmm0, %xmm0
	vmovss	(%ebx), %xmm1
	vmovss	8(%ebx), %xmm2
	vfmadd231ss	%xmm1, %xmm1, %xmm0
	vfmadd132ss	%xmm2, %xmm0, %xmm2
	vsqrtss	%xmm2, %xmm3, %xmm3
	vucomiss	%xmm3, %xmm3
	jp	.L348
.L270:
	vmovss	.LC3, %xmm0
	movl	80(%ebp), %edi
	vdivss	%xmm3, %xmm0, %xmm0
	vmulss	%xmm0, %xmm1, %xmm1
	vmovss	%xmm1, 64(%ebp)
	vmulss	4(%ebx), %xmm0, %xmm1
	vmovss	%xmm1, 68(%ebp)
	vmulss	8(%ebx), %xmm0, %xmm0
	vmovss	%xmm0, 72(%ebp)
	jmp	.L3
.L180:
	leal	3(%edi), %eax
	vmovss	68(%ebp), %xmm1
	vmulss	%xmm1, %xmm1, %xmm1
	vmovss	64(%ebp), %xmm0
	movl	%eax, 80(%ebp)
	movzbl	(%esp), %eax
	vmovss	72(%ebp), %xmm2
	movzbl	2(%edi), %edx
	vfmadd231ss	%xmm0, %xmm0, %xmm1
	vfmadd132ss	%xmm2, %xmm1, %xmm2
	vsqrtss	%xmm2, %xmm3, %xmm3
	vucomiss	%xmm3, %xmm3
	movl	0(%ebp,%eax,4), %eax
	leal	(%eax,%edx,4), %ebx
	jp	.L349
.L272:
	vmovss	.LC3, %xmm1
	movl	80(%ebp), %edi
	vdivss	%xmm3, %xmm1, %xmm1
	vmulss	%xmm1, %xmm0, %xmm0
	vmovss	%xmm0, (%ebx)
	vmulss	68(%ebp), %xmm1, %xmm0
	vmovss	%xmm0, 4(%ebx)
	vmulss	72(%ebp), %xmm1, %xmm1
	vmovss	%xmm1, 8(%ebx)
	jmp	.L3
.L181:
	vmovss	68(%ebp), %xmm2
	vmulss	%xmm2, %xmm2, %xmm3
	vmovss	64(%ebp), %xmm0
	vmovss	72(%ebp), %xmm1
	vfmadd231ss	%xmm0, %xmm0, %xmm3
	vfmadd231ss	%xmm1, %xmm1, %xmm3
	vsqrtss	%xmm3, %xmm4, %xmm4
	vucomiss	%xmm4, %xmm4
	jp	.L350
.L274:
	vmovss	.LC3, %xmm3
	movl	80(%ebp), %eax
	vdivss	%xmm4, %xmm3, %xmm3
	leal	-1(%eax), %edi
	movl	%edi, 80(%ebp)
	vmulss	%xmm3, %xmm0, %xmm0
	vmulss	%xmm3, %xmm2, %xmm2
	vmulss	%xmm3, %xmm1, %xmm1
	vmovss	%xmm0, 64(%ebp)
	vmovss	%xmm2, 68(%ebp)
	vmovss	%xmm1, 72(%ebp)
	jmp	.L3
.L276:
	movl	%ebx, %edi
	jmp	.L3
.L162:
	movzbl	(%esp), %eax
	leal	3(%edi), %edx
	vmovss	64(%ebp), %xmm0
	movl	%edx, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%edx, %edi
	movl	0(%ebp,%eax,4), %eax
	leal	(%eax,%ecx,4), %eax
	vmovss	%xmm0, (%eax)
	vmovss	68(%ebp), %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	72(%ebp), %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L3
.L161:
	leal	3(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%edx, %edi
	movl	0(%ebp,%esi,4), %eax
	leal	(%eax,%ecx,4), %eax
	vmovss	(%eax), %xmm0
	vmovss	%xmm0, 64(%ebp)
	vmovss	4(%eax), %xmm0
	vmovss	%xmm0, 68(%ebp)
	vmovss	8(%eax), %xmm0
	vmovss	%xmm0, 72(%ebp)
	jmp	.L3
.L160:
	leal	3(%edi), %eax
	leal	4(%edi), %ecx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%ecx, 80(%ebp)
	movl	0(%ebp,%esi,4), %edx
	movzbl	3(%edi), %ebx
	movl	%ecx, %edi
	leal	(%edx,%eax,4), %edx
	movzbl	(%esp), %eax
	vmovss	(%edx), %xmm0
	movl	0(%ebp,%eax,4), %eax
	leal	(%eax,%ebx,4), %eax
	vmovss	%xmm0, (%eax)
	vmovss	4(%edx), %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	8(%edx), %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L3
.L159:
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%eax, %edi
	movl	0(%ebp,%esi,4), %edx
	vmovss	(%edx,%ecx,4), %xmm0
	vmovss	%xmm0, 64(%ebp)
	vmovss	%xmm0, 68(%ebp)
	vmovss	%xmm0, 72(%ebp)
	jmp	.L3
.L158:
	vmovss	0(%ebp,%esi,4), %xmm0
	movl	%ebx, %edi
	vmovss	%xmm0, 64(%ebp)
	vmovss	%xmm0, 68(%ebp)
	vmovss	%xmm0, 72(%ebp)
	jmp	.L3
.L157:
	movzbl	11(%esp), %eax
	vxorps	%xmm0, %xmm0, %xmm0
	movl	%ebx, %edi
	vcvtsi2ss	%eax, %xmm0, %xmm0
	vmovss	%xmm0, 64(%ebp)
	vmovss	%xmm0, 68(%ebp)
	vmovss	%xmm0, 72(%ebp)
	jmp	.L3
.L156:
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movl	0(%ebp,%esi,4), %ecx
	vmovss	(%ecx,%eax,4), %xmm0
	movzbl	(%esp), %eax
	movzbl	3(%edi), %ecx
	movl	%edx, %edi
	movl	0(%ebp,%eax,4), %eax
	leal	(%eax,%ecx,4), %eax
	vmovss	%xmm0, (%eax)
	vmovss	%xmm0, 4(%eax)
	vmovss	%xmm0, 8(%eax)
	jmp	.L3
.L155:
	movzbl	(%esp), %eax
	leal	3(%edi), %ecx
	movl	%ecx, 80(%ebp)
	movzbl	2(%edi), %edx
	movl	%ecx, %edi
	movl	0(%ebp,%eax,4), %eax
	leal	(%eax,%edx,4), %eax
	leal	0(%ebp,%esi,4), %edx
	vmovss	(%edx), %xmm0
	vmovss	%xmm0, (%eax)
	vmovss	(%edx), %xmm0
	vmovss	%xmm0, 4(%eax)
	vmovss	(%edx), %xmm0
	vmovss	%xmm0, 8(%eax)
	jmp	.L3
.L154:
	movzbl	(%esp), %eax
	leal	3(%edi), %ecx
	vxorps	%xmm0, %xmm0, %xmm0
	movl	%ecx, 80(%ebp)
	movzbl	2(%edi), %edx
	movl	%ecx, %edi
	movl	0(%ebp,%eax,4), %eax
	leal	(%eax,%edx,4), %edx
	movzbl	11(%esp), %eax
	vcvtsi2ss	%eax, %xmm0, %xmm0
	vmovss	%xmm0, (%edx)
	vmovss	%xmm0, 4(%edx)
	vmovss	%xmm0, 8(%edx)
	jmp	.L3
.L153:
	leal	3(%edi), %eax
	leal	4(%edi), %ebx
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%ebx, 80(%ebp)
	movl	0(%ebp,%esi,4), %edx
	pushl	(%edx,%eax,4)
	.cfi_def_cfa_offset 64
	call	tanf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movzbl	(%esp), %eax
	movzbl	3(%edi), %edx
	fstps	4(%esp)
	movl	4(%esp), %ecx
	movl	%ebx, %edi
	movl	0(%ebp,%eax,4), %eax
	movl	%ecx, (%eax,%edx,4)
	jmp	.L3
.L152:
	leal	3(%edi), %ebx
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	movl	%ebx, 80(%ebp)
	movzbl	2(%edi), %edx
	movl	%ebx, %edi
	movl	0(%ebp,%esi,4), %eax
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 64
	call	tanf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movzbl	(%esp), %eax
	fstps	4(%esp)
	movl	4(%esp), %edx
	movl	%edx, 0(%ebp,%eax,4)
	jmp	.L3
.L151:
	leal	3(%edi), %ebx
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	movl	%ebx, 80(%ebp)
	pushl	0(%ebp,%esi,4)
	.cfi_def_cfa_offset 64
	call	tanf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movzbl	(%esp), %eax
	movzbl	2(%edi), %edx
	fstps	4(%esp)
	movl	4(%esp), %ecx
	movl	%ebx, %edi
	movl	0(%ebp,%eax,4), %eax
	movl	%ecx, (%eax,%edx,4)
	jmp	.L3
.L150:
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	pushl	0(%ebp,%esi,4)
	.cfi_def_cfa_offset 64
	movl	%ebx, %edi
	call	tanf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movzbl	(%esp), %eax
	fstps	4(%esp)
	movl	4(%esp), %edx
	movl	%edx, 0(%ebp,%eax,4)
	jmp	.L3
.L149:
	leal	3(%edi), %eax
	leal	4(%edi), %ebx
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%ebx, 80(%ebp)
	movl	0(%ebp,%esi,4), %edx
	pushl	(%edx,%eax,4)
	.cfi_def_cfa_offset 64
	call	cosf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movzbl	(%esp), %eax
	movzbl	3(%edi), %edx
	fstps	4(%esp)
	movl	4(%esp), %ecx
	movl	%ebx, %edi
	movl	0(%ebp,%eax,4), %eax
	movl	%ecx, (%eax,%edx,4)
	jmp	.L3
.L148:
	leal	3(%edi), %ebx
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	movl	%ebx, 80(%ebp)
	movzbl	2(%edi), %edx
	movl	%ebx, %edi
	movl	0(%ebp,%esi,4), %eax
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 64
	call	cosf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movzbl	(%esp), %eax
	fstps	4(%esp)
	movl	4(%esp), %edx
	movl	%edx, 0(%ebp,%eax,4)
	jmp	.L3
.L147:
	leal	3(%edi), %ebx
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	movl	%ebx, 80(%ebp)
	pushl	0(%ebp,%esi,4)
	.cfi_def_cfa_offset 64
	call	cosf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movzbl	(%esp), %eax
	movzbl	2(%edi), %edx
	fstps	4(%esp)
	movl	4(%esp), %ecx
	movl	%ebx, %edi
	movl	0(%ebp,%eax,4), %eax
	movl	%ecx, (%eax,%edx,4)
	jmp	.L3
.L146:
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	pushl	0(%ebp,%esi,4)
	.cfi_def_cfa_offset 64
	movl	%ebx, %edi
	call	cosf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movzbl	(%esp), %eax
	fstps	4(%esp)
	movl	4(%esp), %edx
	movl	%edx, 0(%ebp,%eax,4)
	jmp	.L3
.L145:
	leal	3(%edi), %eax
	leal	4(%edi), %ebx
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%ebx, 80(%ebp)
	movl	0(%ebp,%esi,4), %edx
	pushl	(%edx,%eax,4)
	.cfi_def_cfa_offset 64
	call	sinf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movzbl	(%esp), %eax
	movzbl	3(%edi), %edx
	fstps	4(%esp)
	movl	4(%esp), %ecx
	movl	%ebx, %edi
	movl	0(%ebp,%eax,4), %eax
	movl	%ecx, (%eax,%edx,4)
	jmp	.L3
.L144:
	leal	3(%edi), %ebx
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	movl	%ebx, 80(%ebp)
	movzbl	2(%edi), %edx
	movl	%ebx, %edi
	movl	0(%ebp,%esi,4), %eax
	pushl	(%eax,%edx,4)
	.cfi_def_cfa_offset 64
	call	sinf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movzbl	(%esp), %eax
	fstps	4(%esp)
	movl	4(%esp), %edx
	movl	%edx, 0(%ebp,%eax,4)
	jmp	.L3
.L143:
	leal	3(%edi), %ebx
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	movl	%ebx, 80(%ebp)
	pushl	0(%ebp,%esi,4)
	.cfi_def_cfa_offset 64
	call	sinf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movzbl	(%esp), %eax
	movzbl	2(%edi), %edx
	fstps	4(%esp)
	movl	4(%esp), %ecx
	movl	%ebx, %edi
	movl	0(%ebp,%eax,4), %eax
	movl	%ecx, (%eax,%edx,4)
	jmp	.L3
.L142:
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	pushl	0(%ebp,%esi,4)
	.cfi_def_cfa_offset 64
	movl	%ebx, %edi
	call	sinf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movzbl	(%esp), %eax
	fstps	4(%esp)
	movl	4(%esp), %edx
	movl	%edx, 0(%ebp,%eax,4)
	jmp	.L3
.L141:
	movzbl	(%esp), %ecx
.L182:
	leal	1(%ebx), %eax
	leal	2(%ebx), %edx
	movl	%eax, 80(%ebp)
	movzbl	(%ebx), %eax
	movl	%edx, 80(%ebp)
	movzbl	1(%ebx), %ebx
	movl	0(%ebp,%ecx,4), %edx
	leal	(%edx,%ebx,4), %ebx
	movl	0(%ebp,%esi,4), %edx
	vsqrtss	(%edx,%eax,4), %xmm0, %xmm0
	vucomiss	%xmm0, %xmm0
	jp	.L351
.L254:
	vmovss	%xmm0, (%ebx)
	movl	80(%ebp), %edi
	jmp	.L3
.L140:
	leal	3(%edi), %eax
	movzbl	(%esp), %ecx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	0(%ebp,%esi,4), %edx
	vsqrtss	(%edx,%eax,4), %xmm0, %xmm0
	vucomiss	%xmm0, %xmm0
	jp	.L352
.L252:
	vmovss	%xmm0, 0(%ebp,%ecx,4)
	movl	80(%ebp), %ebx
	jmp	.L182
.L139:
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	(%esp), %eax
	movzbl	2(%edi), %edx
	vsqrtss	0(%ebp,%esi,4), %xmm0, %xmm0
	vucomiss	%xmm0, %xmm0
	movl	0(%ebp,%eax,4), %eax
	leal	(%eax,%edx,4), %ebx
	jp	.L353
.L250:
	vmovss	%xmm0, (%ebx)
	movl	80(%ebp), %edi
	jmp	.L3
.L138:
	vsqrtss	0(%ebp,%esi,4), %xmm0, %xmm0
	vucomiss	%xmm0, %xmm0
	jp	.L354
.L248:
	movzbl	(%esp), %eax
	vmovss	%xmm0, 0(%ebp,%eax,4)
	movl	80(%ebp), %edi
	jmp	.L3
.L137:
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movzbl	(%esp), %edx
	movl	0(%ebp,%esi,4), %ebx
	movzbl	3(%edi), %ecx
	movl	0(%ebp,%edx,4), %edx
	vmovss	(%ebx,%eax,4), %xmm0
	vucomiss	(%edx,%ecx,4), %xmm0
	jbe	.L328
	leal	5(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	4(%edi), %eax
	movzbl	5(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L136:
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	0(%ebp,%esi,4), %edx
	movzbl	(%esp), %eax
	vmovss	(%edx,%ecx,4), %xmm0
	vucomiss	0(%ebp,%eax,4), %xmm0
	jbe	.L327
	leal	4(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %eax
	movzbl	4(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L135:
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	(%esp), %eax
	movzbl	2(%edi), %edx
	vmovss	0(%ebp,%esi,4), %xmm0
	movl	0(%ebp,%eax,4), %eax
	vucomiss	(%eax,%edx,4), %xmm0
	jbe	.L326
	leal	4(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %eax
	movzbl	4(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L134:
	movzbl	(%esp), %eax
	vmovss	0(%ebp,%esi,4), %xmm0
	vucomiss	0(%ebp,%eax,4), %xmm0
	jbe	.L325
	leal	3(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	2(%edi), %eax
	movzbl	3(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L133:
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movzbl	(%esp), %edx
	movl	0(%ebp,%esi,4), %ebx
	movzbl	3(%edi), %ecx
	movl	0(%ebp,%edx,4), %edx
	vmovss	(%ebx,%eax,4), %xmm0
	vucomiss	(%edx,%ecx,4), %xmm0
	jb	.L324
	leal	5(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	4(%edi), %eax
	movzbl	5(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L132:
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	0(%ebp,%esi,4), %edx
	movzbl	(%esp), %eax
	vmovss	(%edx,%ecx,4), %xmm0
	vucomiss	0(%ebp,%eax,4), %xmm0
	jb	.L323
	leal	4(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %eax
	movzbl	4(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L131:
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	(%esp), %eax
	movzbl	2(%edi), %edx
	vmovss	0(%ebp,%esi,4), %xmm0
	movl	0(%ebp,%eax,4), %eax
	vucomiss	(%eax,%edx,4), %xmm0
	jb	.L322
	leal	4(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %eax
	movzbl	4(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L130:
	movzbl	(%esp), %eax
	vmovss	0(%ebp,%esi,4), %xmm0
	vucomiss	0(%ebp,%eax,4), %xmm0
	jb	.L321
	leal	3(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	2(%edi), %eax
	movzbl	3(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L129:
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movzbl	(%esp), %edx
	movl	0(%ebp,%esi,4), %ebx
	movzbl	3(%edi), %ecx
	movl	0(%ebp,%edx,4), %edx
	vmovss	(%ebx,%eax,4), %xmm0
	vsubss	(%edx,%ecx,4), %xmm0, %xmm0
	vucomiss	.LC1, %xmm0
	jb	.L229
	vmovss	.LC2, %xmm1
	vucomiss	%xmm0, %xmm1
	jb	.L229
	leal	5(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	4(%edi), %eax
	movzbl	5(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L128:
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	0(%ebp,%esi,4), %edx
	movzbl	(%esp), %eax
	vmovss	(%edx,%ecx,4), %xmm0
	vsubss	0(%ebp,%eax,4), %xmm0, %xmm0
	vucomiss	.LC1, %xmm0
	jb	.L226
	vmovss	.LC2, %xmm1
	vucomiss	%xmm0, %xmm1
	jb	.L226
	leal	4(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %eax
	movzbl	4(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L127:
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	(%esp), %eax
	movzbl	2(%edi), %edx
	vmovss	0(%ebp,%esi,4), %xmm0
	movl	0(%ebp,%eax,4), %eax
	vsubss	(%eax,%edx,4), %xmm0, %xmm0
	vucomiss	.LC1, %xmm0
	jb	.L223
	vmovss	.LC2, %xmm1
	vucomiss	%xmm0, %xmm1
	jb	.L223
	leal	4(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %eax
	movzbl	4(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L126:
	movzbl	(%esp), %eax
	vmovss	0(%ebp,%esi,4), %xmm0
	vsubss	0(%ebp,%eax,4), %xmm0, %xmm0
	vucomiss	.LC1, %xmm0
	jb	.L220
	vmovss	.LC2, %xmm1
	vucomiss	%xmm0, %xmm1
	jb	.L220
	leal	3(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	2(%edi), %eax
	movzbl	3(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L125:
	movzbl	(%esp), %edx
.L183:
	leal	1(%ebx), %eax
	leal	2(%ebx), %ecx
	subl	$8, %esp
	.cfi_def_cfa_offset 56
	movl	%eax, 80(%ebp)
	movzbl	(%ebx), %eax
	movl	%ecx, 80(%ebp)
	movzbl	1(%ebx), %ecx
	movl	0(%ebp,%edx,4), %edx
	leal	(%edx,%ecx,4), %ebx
	movl	0(%ebp,%esi,4), %edx
	pushl	(%edx,%eax,4)
	.cfi_def_cfa_offset 60
	pushl	(%ebx)
	.cfi_def_cfa_offset 64
	call	fmodf
	fstps	16(%esp)
	movl	16(%esp), %eax
	movl	80(%ebp), %edi
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movl	%eax, (%ebx)
	jmp	.L3
.L124:
	movzbl	(%esp), %edx
	leal	3(%edi), %eax
	subl	$8, %esp
	.cfi_def_cfa_offset 56
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	0(%ebp,%esi,4), %eax
	leal	0(%ebp,%edx,4), %ebx
	movl	%edx, 12(%esp)
	pushl	(%eax,%ecx,4)
	.cfi_def_cfa_offset 60
	pushl	(%ebx)
	.cfi_def_cfa_offset 64
	call	fmodf
	fstps	16(%esp)
	movl	16(%esp), %eax
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movl	4(%esp), %edx
	movl	%eax, (%ebx)
	movl	80(%ebp), %ebx
	jmp	.L183
.L123:
	leal	3(%edi), %eax
	subl	$8, %esp
	.cfi_def_cfa_offset 56
	movl	%eax, 80(%ebp)
	movzbl	8(%esp), %eax
	movzbl	2(%edi), %edx
	movl	0(%ebp,%eax,4), %eax
	pushl	0(%ebp,%esi,4)
	.cfi_def_cfa_offset 60
	leal	(%eax,%edx,4), %ebx
	pushl	(%ebx)
	.cfi_def_cfa_offset 64
	call	fmodf
	fstps	16(%esp)
	movl	16(%esp), %eax
	movl	80(%ebp), %edi
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movl	%eax, (%ebx)
	jmp	.L3
.L122:
	movzbl	(%esp), %eax
	subl	$8, %esp
	.cfi_def_cfa_offset 56
	pushl	0(%ebp,%esi,4)
	.cfi_def_cfa_offset 60
	leal	0(%ebp,%eax,4), %ebx
	pushl	(%ebx)
	.cfi_def_cfa_offset 64
	call	fmodf
	fstps	16(%esp)
	movl	16(%esp), %eax
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	movl	%eax, (%ebx)
	movl	80(%ebp), %edi
	jmp	.L3
.L121:
	movzbl	(%esp), %ecx
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %ebx
	movl	%edx, %edi
	movl	0(%ebp,%ecx,4), %ecx
	leal	(%ecx,%ebx,4), %ecx
	movl	0(%ebp,%esi,4), %ebx
	vmovss	(%ecx), %xmm0
	vdivss	(%ebx,%eax,4), %xmm0, %xmm0
	vmovss	%xmm0, (%ecx)
	jmp	.L3
.L120:
	movzbl	(%esp), %edx
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ebx
	movl	%eax, %edi
	movl	0(%ebp,%esi,4), %ecx
	leal	0(%ebp,%edx,4), %edx
	vmovss	(%edx), %xmm0
	vdivss	(%ecx,%ebx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edx)
	jmp	.L3
.L119:
	movzbl	(%esp), %edx
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%eax, %edi
	movl	0(%ebp,%edx,4), %edx
	leal	(%edx,%ecx,4), %edx
	vmovss	(%edx), %xmm0
	vdivss	0(%ebp,%esi,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edx)
	jmp	.L3
.L118:
	movzbl	(%esp), %eax
	movl	%ebx, %edi
	leal	0(%ebp,%eax,4), %eax
	vmovss	(%eax), %xmm0
	vdivss	0(%ebp,%esi,4), %xmm0, %xmm0
	vmovss	%xmm0, (%eax)
	jmp	.L3
.L117:
	movzbl	(%esp), %ecx
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %ebx
	movl	%edx, %edi
	movl	0(%ebp,%ecx,4), %ecx
	leal	(%ecx,%ebx,4), %ecx
	movl	0(%ebp,%esi,4), %ebx
	vmovss	(%ecx), %xmm0
	vmulss	(%ebx,%eax,4), %xmm0, %xmm0
	vmovss	%xmm0, (%ecx)
	jmp	.L3
.L116:
	movzbl	(%esp), %edx
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ebx
	movl	%eax, %edi
	movl	0(%ebp,%esi,4), %ecx
	leal	0(%ebp,%edx,4), %edx
	vmovss	(%edx), %xmm0
	vmulss	(%ecx,%ebx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edx)
	jmp	.L3
.L115:
	movzbl	(%esp), %edx
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%eax, %edi
	movl	0(%ebp,%edx,4), %edx
	leal	(%edx,%ecx,4), %edx
	vmovss	(%edx), %xmm0
	vmulss	0(%ebp,%esi,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edx)
	jmp	.L3
.L114:
	movzbl	(%esp), %eax
	movl	%ebx, %edi
	leal	0(%ebp,%eax,4), %eax
	vmovss	(%eax), %xmm0
	vmulss	0(%ebp,%esi,4), %xmm0, %xmm0
	vmovss	%xmm0, (%eax)
	jmp	.L3
.L113:
	movzbl	(%esp), %ecx
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %ebx
	movl	%edx, %edi
	movl	0(%ebp,%ecx,4), %ecx
	leal	(%ecx,%ebx,4), %ecx
	movl	0(%ebp,%esi,4), %ebx
	vmovss	(%ecx), %xmm0
	vsubss	(%ebx,%eax,4), %xmm0, %xmm0
	vmovss	%xmm0, (%ecx)
	jmp	.L3
.L112:
	movzbl	(%esp), %edx
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ebx
	movl	%eax, %edi
	movl	0(%ebp,%esi,4), %ecx
	leal	0(%ebp,%edx,4), %edx
	vmovss	(%edx), %xmm0
	vsubss	(%ecx,%ebx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edx)
	jmp	.L3
.L111:
	movzbl	(%esp), %edx
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%eax, %edi
	movl	0(%ebp,%edx,4), %edx
	leal	(%edx,%ecx,4), %edx
	vmovss	(%edx), %xmm0
	vsubss	0(%ebp,%esi,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edx)
	jmp	.L3
.L110:
	movzbl	(%esp), %eax
	movl	%ebx, %edi
	leal	0(%ebp,%eax,4), %eax
	vmovss	(%eax), %xmm0
	vsubss	0(%ebp,%esi,4), %xmm0, %xmm0
	vmovss	%xmm0, (%eax)
	jmp	.L3
.L109:
	movzbl	(%esp), %ecx
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %ebx
	movl	%edx, %edi
	movl	0(%ebp,%ecx,4), %ecx
	leal	(%ecx,%ebx,4), %ecx
	movl	0(%ebp,%esi,4), %ebx
	vmovss	(%ecx), %xmm0
	vaddss	(%ebx,%eax,4), %xmm0, %xmm0
	vmovss	%xmm0, (%ecx)
	jmp	.L3
.L108:
	movzbl	(%esp), %edx
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ebx
	movl	%eax, %edi
	movl	0(%ebp,%esi,4), %ecx
	leal	0(%ebp,%edx,4), %edx
	vmovss	(%edx), %xmm0
	vaddss	(%ecx,%ebx,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edx)
	jmp	.L3
.L107:
	movzbl	(%esp), %edx
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%eax, %edi
	movl	0(%ebp,%edx,4), %edx
	leal	(%edx,%ecx,4), %edx
	vmovss	(%edx), %xmm0
	vaddss	0(%ebp,%esi,4), %xmm0, %xmm0
	vmovss	%xmm0, (%edx)
	jmp	.L3
.L106:
	movzbl	(%esp), %eax
	movl	%ebx, %edi
	leal	0(%ebp,%eax,4), %eax
	vmovss	(%eax), %xmm0
	vaddss	0(%ebp,%esi,4), %xmm0, %xmm0
	vmovss	%xmm0, (%eax)
	jmp	.L3
.L105:
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movzbl	(%esp), %ecx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movl	0(%ebp,%esi,4), %esi
	movzbl	3(%edi), %ebx
	movl	0(%ebp,%ecx,4), %ecx
	movl	%edx, %edi
	vmovss	(%esi,%eax,4), %xmm0
	vxorps	.LC0, %xmm0, %xmm0
	vmovss	%xmm0, (%ecx,%ebx,4)
	jmp	.L3
.L104:
	leal	3(%edi), %eax
	movzbl	(%esp), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ebx
	movl	%eax, %edi
	movl	0(%ebp,%esi,4), %ecx
	vmovss	(%ecx,%ebx,4), %xmm0
	vxorps	.LC0, %xmm0, %xmm0
	vmovss	%xmm0, 0(%ebp,%edx,4)
	jmp	.L3
.L103:
	leal	3(%edi), %eax
	movzbl	(%esp), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%eax, %edi
	vmovss	0(%ebp,%esi,4), %xmm0
	vxorps	.LC0, %xmm0, %xmm0
	movl	0(%ebp,%edx,4), %edx
	vmovss	%xmm0, (%edx,%ecx,4)
	jmp	.L3
.L102:
	vmovss	0(%ebp,%esi,4), %xmm0
	movzbl	(%esp), %eax
	vxorps	.LC0, %xmm0, %xmm0
	movl	%ebx, %edi
	vmovss	%xmm0, 0(%ebp,%eax,4)
	jmp	.L3
.L101:
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movzbl	(%esp), %ecx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movl	0(%ebp,%esi,4), %esi
	movzbl	3(%edi), %ebx
	movl	0(%ebp,%ecx,4), %edi
	movl	(%esi,%eax,4), %eax
	movl	%eax, %ecx
	shrl	%cl, (%edi,%ebx,4)
	movl	%edx, %edi
	jmp	.L3
.L100:
	leal	3(%edi), %eax
	movzbl	(%esp), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ebx
	movl	%eax, %edi
	movl	0(%ebp,%esi,4), %ecx
	movl	(%ecx,%ebx,4), %ecx
	shrl	%cl, 0(%ebp,%edx,4)
	jmp	.L3
.L99:
	movzbl	(%esp), %edx
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %edi
	movl	0(%ebp,%esi,4), %ebx
	movl	0(%ebp,%edx,4), %edx
	movl	%ebx, %ecx
	shrl	%cl, (%edx,%edi,4)
	movl	%eax, %edi
	jmp	.L3
.L98:
	movzbl	(%esp), %eax
	movl	0(%ebp,%esi,4), %ecx
	movl	%ebx, %edi
	shrl	%cl, 0(%ebp,%eax,4)
	jmp	.L3
.L97:
	movzbl	(%esp), %edx
	leal	3(%edi), %eax
	addl	$1, %esi
	movl	%esi, %ecx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ebx
	movl	%eax, %edi
	movl	0(%ebp,%edx,4), %edx
	shrl	%cl, (%edx,%ebx,4)
	jmp	.L3
.L96:
	movzbl	(%esp), %eax
	leal	1(%esi), %ecx
	movl	%ebx, %edi
	shrl	%cl, 0(%ebp,%eax,4)
	jmp	.L3
.L95:
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movzbl	(%esp), %ecx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movl	0(%ebp,%esi,4), %esi
	movzbl	3(%edi), %ebx
	movl	0(%ebp,%ecx,4), %edi
	movl	(%esi,%eax,4), %eax
	movl	%eax, %ecx
	sall	%cl, (%edi,%ebx,4)
	movl	%edx, %edi
	jmp	.L3
.L94:
	leal	3(%edi), %eax
	movzbl	(%esp), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ebx
	movl	%eax, %edi
	movl	0(%ebp,%esi,4), %ecx
	movl	(%ecx,%ebx,4), %ecx
	sall	%cl, 0(%ebp,%edx,4)
	jmp	.L3
.L93:
	movzbl	(%esp), %edx
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %edi
	movl	0(%ebp,%esi,4), %ebx
	movl	0(%ebp,%edx,4), %edx
	movl	%ebx, %ecx
	sall	%cl, (%edx,%edi,4)
	movl	%eax, %edi
	jmp	.L3
.L92:
	movzbl	(%esp), %eax
	movl	0(%ebp,%esi,4), %ecx
	movl	%ebx, %edi
	sall	%cl, 0(%ebp,%eax,4)
	jmp	.L3
.L91:
	movzbl	(%esp), %edx
	leal	3(%edi), %eax
	addl	$1, %esi
	movl	%esi, %ecx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ebx
	movl	%eax, %edi
	movl	0(%ebp,%edx,4), %edx
	sall	%cl, (%edx,%ebx,4)
	jmp	.L3
.L90:
	movzbl	(%esp), %eax
	leal	1(%esi), %ecx
	movl	%ebx, %edi
	sall	%cl, 0(%ebp,%eax,4)
	jmp	.L3
.L89:
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movzbl	(%esp), %ecx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movl	0(%ebp,%esi,4), %esi
	movzbl	3(%edi), %ebx
	movl	0(%ebp,%ecx,4), %ecx
	movl	%edx, %edi
	movl	(%esi,%eax,4), %eax
	notl	%eax
	movl	%eax, (%ecx,%ebx,4)
	jmp	.L3
.L88:
	leal	3(%edi), %edx
	movzbl	(%esp), %ecx
	movl	%edx, 80(%ebp)
	movzbl	2(%edi), %ebx
	movl	%edx, %edi
	movl	0(%ebp,%esi,4), %eax
	movl	(%eax,%ebx,4), %eax
	notl	%eax
	movl	%eax, 0(%ebp,%ecx,4)
	jmp	.L3
.L87:
	movzbl	(%esp), %eax
	leal	3(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	2(%edi), %ebx
	movl	%edx, %edi
	movl	0(%ebp,%eax,4), %ecx
	movl	0(%ebp,%esi,4), %eax
	notl	%eax
	movl	%eax, (%ecx,%ebx,4)
	jmp	.L3
.L86:
	movl	0(%ebp,%esi,4), %eax
	movzbl	(%esp), %edx
	movl	%ebx, %edi
	notl	%eax
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L3
.L85:
	movzbl	(%esp), %ecx
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %ebx
	movl	%edx, %edi
	movl	0(%ebp,%esi,4), %esi
	movl	0(%ebp,%ecx,4), %ecx
	movl	(%esi,%eax,4), %eax
	xorl	%eax, (%ecx,%ebx,4)
	jmp	.L3
.L84:
	leal	3(%edi), %eax
	movzbl	(%esp), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ebx
	movl	%eax, %edi
	movl	0(%ebp,%esi,4), %ecx
	movl	(%ecx,%ebx,4), %ecx
	xorl	%ecx, 0(%ebp,%edx,4)
	jmp	.L3
.L83:
	movzbl	(%esp), %edx
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%eax, %edi
	movl	0(%ebp,%esi,4), %ebx
	movl	0(%ebp,%edx,4), %edx
	xorl	%ebx, (%edx,%ecx,4)
	jmp	.L3
.L82:
	movzbl	(%esp), %eax
	movl	0(%ebp,%esi,4), %edx
	movl	%ebx, %edi
	xorl	%edx, 0(%ebp,%eax,4)
	jmp	.L3
.L81:
	movzbl	(%esp), %ecx
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %ebx
	movl	%edx, %edi
	movl	0(%ebp,%esi,4), %esi
	movl	0(%ebp,%ecx,4), %ecx
	movl	(%esi,%eax,4), %eax
	orl	%eax, (%ecx,%ebx,4)
	jmp	.L3
.L80:
	leal	3(%edi), %eax
	movzbl	(%esp), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ebx
	movl	%eax, %edi
	movl	0(%ebp,%esi,4), %ecx
	movl	(%ecx,%ebx,4), %ecx
	orl	%ecx, 0(%ebp,%edx,4)
	jmp	.L3
.L79:
	movzbl	(%esp), %edx
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%eax, %edi
	movl	0(%ebp,%esi,4), %ebx
	movl	0(%ebp,%edx,4), %edx
	orl	%ebx, (%edx,%ecx,4)
	jmp	.L3
.L78:
	movzbl	(%esp), %eax
	movl	0(%ebp,%esi,4), %edx
	movl	%ebx, %edi
	orl	%edx, 0(%ebp,%eax,4)
	jmp	.L3
.L77:
	movzbl	(%esp), %ecx
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %ebx
	movl	%edx, %edi
	movl	0(%ebp,%esi,4), %esi
	movl	0(%ebp,%ecx,4), %ecx
	movl	(%esi,%eax,4), %eax
	andl	%eax, (%ecx,%ebx,4)
	jmp	.L3
.L76:
	leal	3(%edi), %eax
	movzbl	(%esp), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ebx
	movl	%eax, %edi
	movl	0(%ebp,%esi,4), %ecx
	movl	(%ecx,%ebx,4), %ecx
	andl	%ecx, 0(%ebp,%edx,4)
	jmp	.L3
.L75:
	movzbl	(%esp), %edx
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%eax, %edi
	movl	0(%ebp,%esi,4), %ebx
	movl	0(%ebp,%edx,4), %edx
	andl	%ebx, (%edx,%ecx,4)
	jmp	.L3
.L74:
	movzbl	(%esp), %eax
	movl	0(%ebp,%esi,4), %edx
	movl	%ebx, %edi
	andl	%edx, 0(%ebp,%eax,4)
	jmp	.L3
.L73:
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%edx, 80(%ebp)
	movl	0(%ebp,%esi,4), %ebx
	movzbl	3(%edi), %eax
	movl	(%ebx,%ecx,4), %ebx
	testl	%ebx, %ebx
	je	.L219
	movzbl	(%esp), %ecx
	movl	%edx, %edi
	movl	0(%ebp,%ecx,4), %ecx
	andl	%ebx, (%ecx,%eax,4)
	jmp	.L3
.L72:
	leal	3(%edi), %ecx
	movl	%ecx, 80(%ebp)
	movzbl	2(%edi), %edx
	movl	0(%ebp,%esi,4), %eax
	movl	(%eax,%edx,4), %ebx
	testl	%ebx, %ebx
	je	.L219
	movzbl	(%esp), %eax
	movl	%ecx, %edi
	leal	0(%ebp,%eax,4), %esi
	movl	(%esi), %eax
	cltd
	idivl	%ebx
	movl	%edx, (%esi)
	jmp	.L3
.L71:
	leal	3(%edi), %ecx
	movl	%ecx, 80(%ebp)
	movl	0(%ebp,%esi,4), %ebx
	movzbl	2(%edi), %eax
	testl	%ebx, %ebx
	je	.L219
	movzbl	(%esp), %edx
	movl	%ecx, %edi
	movl	0(%ebp,%edx,4), %edx
	leal	(%edx,%eax,4), %esi
	movl	(%esi), %eax
	cltd
	idivl	%ebx
	movl	%edx, (%esi)
	jmp	.L3
.L70:
	movl	0(%ebp,%esi,4), %ecx
	testl	%ecx, %ecx
	je	.L219
	movzbl	(%esp), %eax
	movl	%ebx, %edi
	leal	0(%ebp,%eax,4), %esi
	movl	(%esi), %eax
	cltd
	idivl	%ecx
	movl	%edx, (%esi)
	jmp	.L3
.L69:
	movzbl	(%esp), %eax
	leal	3(%edi), %ecx
	addl	$2, %esi
	movl	%ecx, 80(%ebp)
	movzbl	2(%edi), %edx
	movl	%ecx, %edi
	movl	0(%ebp,%eax,4), %eax
	leal	(%eax,%edx,4), %ebx
	movl	(%ebx), %eax
	cltd
	idivl	%esi
	movl	%edx, (%ebx)
	jmp	.L3
.L68:
	movzbl	(%esp), %eax
	addl	$2, %esi
	movl	%ebx, %edi
	leal	0(%ebp,%eax,4), %ecx
	movl	(%ecx), %eax
	cltd
	idivl	%esi
	movl	%edx, (%ecx)
	jmp	.L3
.L67:
	leal	3(%edi), %eax
	leal	4(%edi), %ecx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %edx
	movl	%ecx, 80(%ebp)
	movl	0(%ebp,%esi,4), %ebx
	movzbl	3(%edi), %eax
	movl	(%ebx,%edx,4), %ebx
	testl	%ebx, %ebx
	je	.L219
	movzbl	(%esp), %edx
	movl	%ecx, %edi
	movl	0(%ebp,%edx,4), %edx
	leal	(%edx,%eax,4), %esi
	movl	(%esi), %eax
	cltd
	idivl	%ebx
	movl	%eax, (%esi)
	jmp	.L3
.L66:
	leal	3(%edi), %ecx
	movl	%ecx, 80(%ebp)
	movzbl	2(%edi), %edx
	movl	0(%ebp,%esi,4), %eax
	movl	(%eax,%edx,4), %ebx
	testl	%ebx, %ebx
	je	.L219
	movzbl	(%esp), %eax
	movl	%ecx, %edi
	leal	0(%ebp,%eax,4), %esi
	movl	(%esi), %eax
	cltd
	idivl	%ebx
	movl	%eax, (%esi)
	jmp	.L3
.L65:
	leal	3(%edi), %ecx
	movl	%ecx, 80(%ebp)
	movl	0(%ebp,%esi,4), %ebx
	movzbl	2(%edi), %eax
	testl	%ebx, %ebx
	je	.L219
	movzbl	(%esp), %edx
	movl	%ecx, %edi
	movl	0(%ebp,%edx,4), %edx
	leal	(%edx,%eax,4), %esi
	movl	(%esi), %eax
	cltd
	idivl	%ebx
	movl	%eax, (%esi)
	jmp	.L3
.L64:
	movl	0(%ebp,%esi,4), %ecx
	testl	%ecx, %ecx
	je	.L219
	movzbl	(%esp), %eax
	movl	%ebx, %edi
	leal	0(%ebp,%eax,4), %esi
	movl	(%esi), %eax
	cltd
	idivl	%ecx
	movl	%eax, (%esi)
	jmp	.L3
.L63:
	movzbl	(%esp), %eax
	leal	3(%edi), %ecx
	addl	$2, %esi
	movl	%ecx, 80(%ebp)
	movzbl	2(%edi), %edx
	movl	%ecx, %edi
	movl	0(%ebp,%eax,4), %eax
	leal	(%eax,%edx,4), %ebx
	movl	(%ebx), %eax
	cltd
	idivl	%esi
	movl	%eax, (%ebx)
	jmp	.L3
.L62:
	movzbl	(%esp), %eax
	addl	$2, %esi
	movl	%ebx, %edi
	leal	0(%ebp,%eax,4), %ecx
	movl	(%ecx), %eax
	cltd
	idivl	%esi
	movl	%eax, (%ecx)
	jmp	.L3
.L61:
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movl	%eax, 80(%ebp)
	movzbl	(%esp), %eax
	movzbl	2(%edi), %ecx
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %ebx
	movl	0(%ebp,%esi,4), %esi
	movl	%edx, %edi
	movl	0(%ebp,%eax,4), %eax
	leal	(%eax,%ebx,4), %ebx
	movl	(%ebx), %eax
	imull	(%esi,%ecx,4), %eax
	movl	%eax, (%ebx)
	jmp	.L3
.L60:
	leal	3(%edi), %edx
	movzbl	(%esp), %eax
	movl	%edx, 80(%ebp)
	movzbl	2(%edi), %edi
	movl	0(%ebp,%esi,4), %ebx
	leal	0(%ebp,%eax,4), %ecx
	movl	(%ecx), %eax
	imull	(%ebx,%edi,4), %eax
	movl	%edx, %edi
	movl	%eax, (%ecx)
	jmp	.L3
.L59:
	movzbl	(%esp), %eax
	leal	3(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%edx, %edi
	movl	0(%ebp,%eax,4), %eax
	leal	(%eax,%ecx,4), %ecx
	movl	(%ecx), %eax
	imull	0(%ebp,%esi,4), %eax
	movl	%eax, (%ecx)
	jmp	.L3
.L58:
	movzbl	(%esp), %eax
	movl	%ebx, %edi
	leal	0(%ebp,%eax,4), %edx
	movl	(%edx), %eax
	imull	0(%ebp,%esi,4), %eax
	movl	%eax, (%edx)
	jmp	.L3
.L57:
	movzbl	(%esp), %edx
	leal	3(%edi), %eax
	addl	$2, %esi
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%eax, %edi
	movl	0(%ebp,%edx,4), %edx
	leal	(%edx,%ecx,4), %edx
	imull	(%edx), %esi
	movl	%esi, (%edx)
	jmp	.L3
.L56:
	movzbl	(%esp), %eax
	addl	$2, %esi
	movl	%ebx, %edi
	leal	0(%ebp,%eax,4), %eax
	imull	(%eax), %esi
	movl	%esi, (%eax)
	jmp	.L3
.L55:
	movzbl	(%esp), %ecx
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %ebx
	movl	%edx, %edi
	movl	0(%ebp,%esi,4), %esi
	movl	0(%ebp,%ecx,4), %ecx
	movl	(%esi,%eax,4), %eax
	subl	%eax, (%ecx,%ebx,4)
	jmp	.L3
.L54:
	leal	3(%edi), %eax
	movzbl	(%esp), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ebx
	movl	%eax, %edi
	movl	0(%ebp,%esi,4), %ecx
	movl	(%ecx,%ebx,4), %ecx
	subl	%ecx, 0(%ebp,%edx,4)
	jmp	.L3
.L53:
	movzbl	(%esp), %edx
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%eax, %edi
	movl	0(%ebp,%esi,4), %ebx
	movl	0(%ebp,%edx,4), %edx
	subl	%ebx, (%edx,%ecx,4)
	jmp	.L3
.L52:
	movzbl	(%esp), %eax
	movl	0(%ebp,%esi,4), %edx
	movl	%ebx, %edi
	subl	%edx, 0(%ebp,%eax,4)
	jmp	.L3
.L51:
	movzbl	(%esp), %edx
	leal	3(%edi), %eax
	addl	$1, %esi
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%eax, %edi
	movl	0(%ebp,%edx,4), %edx
	subl	%esi, (%edx,%ecx,4)
	jmp	.L3
.L50:
	movzbl	(%esp), %eax
	addl	$1, %esi
	movl	%ebx, %edi
	subl	%esi, 0(%ebp,%eax,4)
	jmp	.L3
.L49:
	movzbl	(%esp), %ecx
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %ebx
	movl	%edx, %edi
	movl	0(%ebp,%esi,4), %esi
	movl	0(%ebp,%ecx,4), %ecx
	movl	(%esi,%eax,4), %eax
	addl	%eax, (%ecx,%ebx,4)
	jmp	.L3
.L48:
	leal	3(%edi), %eax
	movzbl	(%esp), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ebx
	movl	%eax, %edi
	movl	0(%ebp,%esi,4), %ecx
	movl	(%ecx,%ebx,4), %ecx
	addl	%ecx, 0(%ebp,%edx,4)
	jmp	.L3
.L47:
	movzbl	(%esp), %edx
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%eax, %edi
	movl	0(%ebp,%esi,4), %ebx
	movl	0(%ebp,%edx,4), %edx
	addl	%ebx, (%edx,%ecx,4)
	jmp	.L3
.L46:
	movzbl	(%esp), %eax
	movl	0(%ebp,%esi,4), %edx
	movl	%ebx, %edi
	addl	%edx, 0(%ebp,%eax,4)
	jmp	.L3
.L45:
	movzbl	(%esp), %edx
	leal	3(%edi), %eax
	addl	$1, %esi
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %ecx
	movl	%eax, %edi
	movl	0(%ebp,%edx,4), %edx
	addl	%esi, (%edx,%ecx,4)
	jmp	.L3
.L44:
	movzbl	(%esp), %eax
	addl	$1, %esi
	movl	%ebx, %edi
	addl	%esi, 0(%ebp,%eax,4)
	jmp	.L3
.L43:
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movzbl	(%esp), %ecx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movl	0(%ebp,%esi,4), %esi
	movzbl	3(%edi), %ebx
	movl	0(%ebp,%ecx,4), %ecx
	movl	%edx, %edi
	movl	(%esi,%eax,4), %eax
	negl	%eax
	movl	%eax, (%ecx,%ebx,4)
	jmp	.L3
.L42:
	leal	3(%edi), %edx
	movzbl	(%esp), %ecx
	movl	%edx, 80(%ebp)
	movzbl	2(%edi), %ebx
	movl	%edx, %edi
	movl	0(%ebp,%esi,4), %eax
	movl	(%eax,%ebx,4), %eax
	negl	%eax
	movl	%eax, 0(%ebp,%ecx,4)
	jmp	.L3
.L41:
	movzbl	(%esp), %eax
	leal	3(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	2(%edi), %ebx
	movl	%edx, %edi
	movl	0(%ebp,%eax,4), %ecx
	movl	0(%ebp,%esi,4), %eax
	negl	%eax
	movl	%eax, (%ecx,%ebx,4)
	jmp	.L3
.L40:
	movl	0(%ebp,%esi,4), %eax
	movzbl	(%esp), %edx
	movl	%ebx, %edi
	negl	%eax
	movl	%eax, 0(%ebp,%edx,4)
	jmp	.L3
.L39:
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movzbl	(%esp), %edx
	movzbl	3(%edi), %ecx
	movl	0(%ebp,%esi,4), %ebx
	movl	0(%ebp,%edx,4), %edx
	movl	(%edx,%ecx,4), %edx
	cmpl	%edx, (%ebx,%eax,4)
	jle	.L218
	leal	5(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	4(%edi), %eax
	movzbl	5(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L38:
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	(%esp), %eax
	movzbl	2(%edi), %ecx
	movl	0(%ebp,%esi,4), %edx
	movl	0(%ebp,%eax,4), %eax
	cmpl	%eax, (%edx,%ecx,4)
	jle	.L217
	leal	4(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %eax
	movzbl	4(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L37:
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	(%esp), %eax
	movzbl	2(%edi), %edx
	movl	0(%ebp,%eax,4), %eax
	movl	(%eax,%edx,4), %eax
	cmpl	%eax, 0(%ebp,%esi,4)
	jle	.L216
	leal	4(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %eax
	movzbl	4(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L36:
	movzbl	(%esp), %eax
	movl	0(%ebp,%eax,4), %eax
	cmpl	%eax, 0(%ebp,%esi,4)
	jle	.L215
	leal	3(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	2(%edi), %eax
	movzbl	3(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L35:
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movzbl	(%esp), %edx
	movzbl	3(%edi), %ecx
	movl	0(%ebp,%esi,4), %ebx
	movl	0(%ebp,%edx,4), %edx
	movl	(%edx,%ecx,4), %edx
	cmpl	%edx, (%ebx,%eax,4)
	jl	.L214
	leal	5(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	4(%edi), %eax
	movzbl	5(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L34:
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	(%esp), %eax
	movzbl	2(%edi), %ecx
	movl	0(%ebp,%esi,4), %edx
	movl	0(%ebp,%eax,4), %eax
	cmpl	%eax, (%edx,%ecx,4)
	jl	.L213
	leal	4(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %eax
	movzbl	4(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L33:
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	(%esp), %eax
	movzbl	2(%edi), %edx
	movl	0(%ebp,%eax,4), %eax
	movl	(%eax,%edx,4), %eax
	cmpl	%eax, 0(%ebp,%esi,4)
	jl	.L212
	leal	4(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %eax
	movzbl	4(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L32:
	movzbl	(%esp), %eax
	movl	0(%ebp,%eax,4), %eax
	cmpl	%eax, 0(%ebp,%esi,4)
	jl	.L211
	leal	3(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	2(%edi), %eax
	movzbl	3(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L31:
	leal	3(%edi), %eax
	leal	4(%edi), %edx
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %eax
	movl	%edx, 80(%ebp)
	movzbl	(%esp), %edx
	movzbl	3(%edi), %ecx
	movl	0(%ebp,%esi,4), %ebx
	movl	0(%ebp,%edx,4), %edx
	movl	(%edx,%ecx,4), %edx
	cmpl	%edx, (%ebx,%eax,4)
	je	.L355
	addl	$6, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L30:
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	(%esp), %eax
	movzbl	2(%edi), %edx
	movl	0(%ebp,%eax,4), %eax
	movl	(%eax,%edx,4), %eax
	cmpl	%eax, 0(%ebp,%esi,4)
	je	.L356
	addl	$5, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L29:
	movzbl	(%esp), %eax
	movl	0(%ebp,%eax,4), %eax
	cmpl	%eax, 0(%ebp,%esi,4)
	je	.L357
	addl	$4, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L28:
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	(%esp), %eax
	movzbl	2(%edi), %edx
	movl	0(%ebp,%eax,4), %eax
	movl	(%eax,%edx,4), %eax
	testl	%eax, %eax
	je	.L207
	leal	4(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %eax
	movzbl	4(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L27:
	movzbl	(%esp), %eax
	movl	0(%ebp,%eax,4), %edx
	testl	%edx, %edx
	je	.L206
	leal	3(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	2(%edi), %eax
	movzbl	3(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L26:
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	(%esp), %eax
	movzbl	2(%edi), %edx
	movl	0(%ebp,%eax,4), %eax
	movl	(%eax,%edx,4), %ecx
	testl	%ecx, %ecx
	jne	.L205
	leal	4(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %eax
	movzbl	4(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L25:
	movzbl	(%esp), %eax
	movl	0(%ebp,%eax,4), %ebx
	testl	%ebx, %ebx
	jne	.L204
	leal	3(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	2(%edi), %eax
	movzbl	3(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L24:
	leal	3(%edi), %eax
	movl	%eax, 80(%ebp)
	movzbl	2(%edi), %edx
	movl	0(%ebp,%esi,4), %eax
	movl	(%eax,%edx,4), %eax
	movzbl	(%esp), %edx
	testl	%eax, %eax
	movl	%eax, 0(%ebp,%edx,4)
	je	.L203
	leal	4(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %eax
	movzbl	4(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L23:
	movzbl	(%esp), %eax
	leal	0(%ebp,%eax,4), %edx
	subl	$1, (%edx)
	je	.L202
	leal	3(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	2(%edi), %eax
	movzbl	3(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L22:
	movzbl	(%esp), %eax
	movl	0(%ebp,%eax,4), %eax
	cmpl	104(%ebp), %eax
	jb	.L358
	cmpl	108(%ebp), %eax
	jnb	.L200
	movl	%eax, 92(%ebp)
	movl	%ebx, %edi
	jmp	.L3
.L21:
	movl	92(%ebp), %ecx
	leal	4(%ecx,%edx,4), %eax
	cmpl	108(%ebp), %eax
	jnb	.L200
	movzbl	(%esp), %edx
	movl	%ebx, %edi
	movl	%ecx, 0(%ebp,%edx,4)
	movl	%eax, 92(%ebp)
	jmp	.L3
.L20:
	leal	3(%edi), %ecx
	movl	4(%esp), %eax
	leal	60(%ebp), %ebx
	movl	%ecx, 80(%ebp)
	movzbl	2(%edi), %edx
	sall	$8, %eax
	orw	%dx, %ax
	je	.L279
	movl	92(%ebp), %edx
	movl	104(%ebp), %esi
	cmpl	%esi, %edx
	ja	.L197
	jmp	.L200
	.p2align 4,,10
	.p2align 3
.L198:
	subl	$4, %ebx
	cmpl	%esi, %edx
	jbe	.L200
.L197:
	testw	%ax, %ax
	jns	.L198
	leal	-4(%edx), %edi
	movl	-4(%edx), %edx
	subl	$4, %ebx
	movl	%edi, 92(%ebp)
	movl	%edx, 4(%ebx)
	addw	%ax, %ax
	je	.L280
	movl	%edi, %edx
	cmpl	%esi, %edx
	ja	.L197
.L200:
	movl	$6, 84(%ebp)
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
.L19:
	.cfi_restore_state
	leal	3(%edi), %ecx
	movl	4(%esp), %eax
	movl	%ebp, %ebx
	movl	%ecx, 80(%ebp)
	movzbl	2(%edi), %edx
	sall	$8, %eax
	orw	%dx, %ax
	je	.L277
	movl	92(%ebp), %edx
	movl	108(%ebp), %esi
	cmpl	%esi, %edx
	jnb	.L200
	movl	%edx, %edi
	jmp	.L193
	.p2align 4,,10
	.p2align 3
.L359:
	leal	4(%edi), %edx
	addl	$4, %ebx
	movl	%edx, 92(%ebp)
	movl	-4(%ebx), %edx
	movl	%edx, (%edi)
	movzwl	%ax, %edx
	sarl	%edx
	testw	%dx, %dx
	movl	%edx, %eax
	je	.L278
	movl	92(%ebp), %edi
.L195:
	cmpl	%esi, %edi
	jnb	.L200
.L193:
	testb	$1, %al
	jne	.L359
	addl	$4, %ebx
	jmp	.L195
.L4:
	movl	$4, 84(%ebp)
.L186:
.L335:
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
.L339:
	.cfi_restore_state
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	pushl	%ebp
	.cfi_def_cfa_offset 64
	call	*%eax
	movl	80(%ebp), %edi
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	jmp	.L3
.L220:
	addl	$4, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L223:
	addl	$5, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L226:
	addl	$5, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L229:
	addl	$6, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L218:
	addl	$6, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L321:
	addl	$4, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L322:
	addl	$5, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L206:
	addl	$4, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L207:
	addl	$5, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L202:
	addl	$4, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L203:
	addl	$5, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L204:
	addl	$4, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L205:
	addl	$5, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L211:
	addl	$4, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L212:
	addl	$5, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L213:
	addl	$5, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L214:
	addl	$6, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L215:
	addl	$4, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L216:
	addl	$5, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L217:
	addl	$5, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L323:
	addl	$5, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L324:
	addl	$6, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L325:
	addl	$4, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L326:
	addl	$5, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L327:
	addl	$5, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L328:
	addl	$6, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L278:
	movl	%ecx, %edi
	jmp	.L3
.L280:
	movl	%ecx, %edi
	jmp	.L3
.L355:
	leal	5(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	4(%edi), %eax
	movzbl	5(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L357:
	leal	3(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	2(%edi), %eax
	movzbl	3(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L356:
	leal	4(%edi), %edx
	movl	%edx, 80(%ebp)
	movzbl	3(%edi), %eax
	movzbl	4(%edi), %edi
	sall	$8, %eax
	orl	%eax, %edi
	movswl	%di, %edi
	addl	%edx, %edi
	movl	%edi, 80(%ebp)
	jmp	.L3
.L219:
	movl	$5, 84(%ebp)
	jmp	.L335
.L279:
	movl	%ecx, %edi
	jmp	.L3
.L277:
	movl	%ecx, %edi
	jmp	.L3
.L185:
	movl	$8, 84(%ebp)
	jmp	.L335
.L338:
	movl	$13, 84(%ebp)
	jmp	.L335
.L343:
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	vmovss	%xmm0, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	vmovss	(%esp), %xmm1
	jmp	.L262
.L190:
	movl	$2, 84(%ebp)
	jmp	.L335
.L358:
	movl	$7, 84(%ebp)
	jmp	.L335
.L340:
	movl	$11, 84(%ebp)
	jmp	.L335
.L342:
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	vmovss	%xmm0, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	vmovss	(%esp), %xmm1
	jmp	.L264
.L347:
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	vmovss	%xmm2, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	vmovss	(%ebx), %xmm1
	vmovss	(%esp), %xmm3
	jmp	.L268
.L346:
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	vmovss	%xmm0, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	4(%esp)
	vmovss	4(%esp), %xmm1
	jmp	.L256
.L345:
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	vmovss	%xmm0, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	vmovss	(%esp), %xmm1
	jmp	.L258
.L344:
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	vmovss	%xmm0, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	4(%esp)
	vmovss	4(%esp), %xmm1
	jmp	.L260
.L341:
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	vmovss	%xmm3, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	vmovss	(%ebx), %xmm2
	vmovss	(%esp), %xmm4
	vmovss	4(%ebx), %xmm1
	vmovss	8(%ebx), %xmm0
	jmp	.L266
.L354:
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	pushl	0(%ebp,%esi,4)
	.cfi_def_cfa_offset 64
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	4(%esp)
	vmovss	4(%esp), %xmm0
	jmp	.L248
.L353:
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	pushl	0(%ebp,%esi,4)
	.cfi_def_cfa_offset 64
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	vmovss	(%esp), %xmm0
	jmp	.L250
.L352:
	movl	%ecx, 4(%esp)
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	pushl	(%edx,%eax,4)
	.cfi_def_cfa_offset 64
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	movl	4(%esp), %ecx
	vmovss	(%esp), %xmm0
	jmp	.L252
.L351:
	subl	$12, %esp
	.cfi_def_cfa_offset 60
	pushl	(%edx,%eax,4)
	.cfi_def_cfa_offset 64
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	vmovss	(%esp), %xmm0
	jmp	.L254
.L350:
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	vmovss	%xmm3, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	vmovss	64(%ebp), %xmm0
	vmovss	(%esp), %xmm4
	vmovss	68(%ebp), %xmm2
	vmovss	72(%ebp), %xmm1
	jmp	.L274
.L349:
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	vmovss	%xmm2, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	vmovss	64(%ebp), %xmm0
	vmovss	(%esp), %xmm3
	jmp	.L272
.L348:
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	vmovss	%xmm2, (%esp)
	call	sqrtf
	addl	$16, %esp
	.cfi_def_cfa_offset 48
	fstps	(%esp)
	vmovss	(%ebx), %xmm1
	vmovss	(%esp), %xmm3
	jmp	.L270
	.cfi_endproc
.LFE119:
	.size	_ZN3GVM11Interpreter7executeEv, .-_ZN3GVM11Interpreter7executeEv
	.section	.text.unlikely
.LCOLDE5:
	.text
.LHOTE5:
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC0:
	.long	2147483648
	.long	0
	.long	0
	.long	0
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC1:
	.long	3019898880
	.align 4
.LC2:
	.long	872415232
	.align 4
.LC3:
	.long	1065353216
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
