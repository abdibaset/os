	.arch armv8.5-a
	.build_version macos,  15, 0
	.text
	.align	2
	.globl _sum
_sum:
LFB0:
	add	w0, w0, w1
	adrp	x2, _accum@PAGE
	ldr	w1, [x2, #_accum@PAGEOFF]
	add	w1, w1, w0
	str	w1, [x2, #_accum@PAGEOFF]
	ret
LFE0:
	.globl _accum
	.zerofill __DATA,__common,_accum,4,2
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x3
	.ascii "zR\0"
	.uleb128 0x1
	.sleb128 -8
	.uleb128 0x1e
	.uleb128 0x1
	.byte	0x10
	.byte	0xc
	.uleb128 0x1f
	.uleb128 0
	.align	3
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB0-.
	.set L$set$2,LFE0-LFB0
	.quad L$set$2
	.uleb128 0
	.align	3
LEFDE1:
	.ident	"GCC: (Homebrew GCC 15.1.0) 15.1.0"
	.subsections_via_symbols
