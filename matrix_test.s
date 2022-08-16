	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 3
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	stp	x28, x27, [sp, #-32]!           ; 16-byte Folded Spill
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	sub	sp, sp, #992
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w27, -24
	.cfi_offset w28, -32
	add	x8, sp, #480
	str	x8, [sp, #256]                  ; 8-byte Folded Spill
	adrp	x8, __ZNSt3__14coutE@GOTPAGE
	ldr	x8, [x8, __ZNSt3__14coutE@GOTPAGEOFF]
	str	x8, [sp, #320]                  ; 8-byte Folded Spill
	adrp	x8, __ZNSt3__19boolalphaERNS_8ios_baseE@GOTPAGE
	ldr	x8, [x8, __ZNSt3__19boolalphaERNS_8ios_baseE@GOTPAGEOFF]
	str	x8, [sp, #120]                  ; 8-byte Folded Spill
	mov	w8, #0
	str	w8, [sp, #336]                  ; 4-byte Folded Spill
	stur	wzr, [x29, #-20]
	sub	x0, x29, #56
	str	x0, [sp, #248]                  ; 8-byte Folded Spill
	mov	x2, #2
	str	x2, [sp, #288]                  ; 8-byte Folded Spill
	mov	x1, x2
	mov	w3, #1
	str	w3, [sp, #300]                  ; 4-byte Folded Spill
	bl	__ZN3phy6matrixIfEC1Emmi
	ldr	x0, [sp, #320]                  ; 8-byte Folded Reload
	adrp	x1, l_.str@PAGE
	add	x1, x1, l_.str@PAGEOFF
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x0, [sp, #248]                  ; 8-byte Folded Reload
	bl	__ZN3phy6matrixIfE6mprintEv
	ldr	x2, [sp, #288]                  ; 8-byte Folded Reload
	ldr	w3, [sp, #300]                  ; 4-byte Folded Reload
	sub	x0, x29, #88
	str	x0, [sp, #8]                    ; 8-byte Folded Spill
	mov	x1, #3
	str	x1, [sp, #112]                  ; 8-byte Folded Spill
	bl	__ZN3phy6matrixIfEC1Emmi
	ldr	x0, [sp, #320]                  ; 8-byte Folded Reload
	adrp	x1, l_.str.1@PAGE
	add	x1, x1, l_.str.1@PAGEOFF
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x0, [sp, #8]                    ; 8-byte Folded Reload
	bl	__ZN3phy6matrixIfE6mprintEv
	ldr	w3, [sp, #336]                  ; 4-byte Folded Reload
	sub	x0, x29, #120
	str	x0, [sp, #16]                   ; 8-byte Folded Spill
	mov	x1, #1
	str	x1, [sp, #312]                  ; 8-byte Folded Spill
	mov	x2, #4
	bl	__ZN3phy6matrixIfEC1Emmi
	ldr	x0, [sp, #320]                  ; 8-byte Folded Reload
	adrp	x1, l_.str.2@PAGE
	add	x1, x1, l_.str.2@PAGEOFF
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	bl	__ZN3phy6matrixIfE6mprintEv
	ldr	x2, [sp, #288]                  ; 8-byte Folded Reload
	ldr	w3, [sp, #336]                  ; 4-byte Folded Reload
	sub	x0, x29, #160
	str	x0, [sp, #168]                  ; 8-byte Folded Spill
	mov	x1, x2
	bl	__ZN3phy6matrixIfEC1Emmi
	ldr	x0, [sp, #320]                  ; 8-byte Folded Reload
	adrp	x1, l_.str.3@PAGE
	add	x1, x1, l_.str.3@PAGEOFF
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x1, [sp, #288]                  ; 8-byte Folded Reload
	sub	x8, x29, #192
	str	x8, [sp, #24]                   ; 8-byte Folded Spill
	mov	x0, x1
	bl	__ZN3phy6matrixIfE8identityEmm
	ldr	x8, [sp, #24]                   ; 8-byte Folded Reload
	ldr	x0, [sp, #168]                  ; 8-byte Folded Reload
	ldr	x9, [sp, #256]                  ; 8-byte Folded Reload
	ldr	q0, [x9, #336]
	str	q0, [x9, #368]
	ldur	q0, [x8, #12]
	stur	q0, [x0, #12]
	bl	__ZN3phy6matrixIfE6mprintEv
	ldr	x2, [sp, #288]                  ; 8-byte Folded Reload
	ldr	w3, [sp, #300]                  ; 4-byte Folded Reload
	sub	x0, x29, #224
	str	x0, [sp, #152]                  ; 8-byte Folded Spill
	mov	x1, x2
	bl	__ZN3phy6matrixIfEC1Emmi
	ldr	x0, [sp, #320]                  ; 8-byte Folded Reload
	adrp	x1, l_.str.4@PAGE
	add	x1, x1, l_.str.4@PAGEOFF
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x2, [sp, #288]                  ; 8-byte Folded Reload
	ldr	x0, [sp, #248]                  ; 8-byte Folded Reload
	sub	x8, x29, #256
	str	x8, [sp, #32]                   ; 8-byte Folded Spill
	mov	x1, x2
	bl	__ZN3phy6matrixIfE9transposeEmm
	ldr	x8, [sp, #32]                   ; 8-byte Folded Reload
	ldr	x0, [sp, #152]                  ; 8-byte Folded Reload
	ldr	x9, [sp, #256]                  ; 8-byte Folded Reload
	ldr	q0, [x9, #272]
	str	q0, [x9, #304]
	ldur	q0, [x8, #12]
	stur	q0, [x0, #12]
	bl	__ZN3phy6matrixIfE6mprintEv
	ldr	x0, [sp, #320]                  ; 8-byte Folded Reload
	adrp	x1, l_.str.5@PAGE
	add	x1, x1, l_.str.5@PAGEOFF
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	mov	x1, x0
	ldr	x0, [sp, #248]                  ; 8-byte Folded Reload
	str	x1, [sp, #40]                   ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE3minIfEEfv
	ldr	x0, [sp, #40]                   ; 8-byte Folded Reload
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEf
	adrp	x1, l_.str.6@PAGE
	add	x1, x1, l_.str.6@PAGEOFF
	str	x1, [sp, #144]                  ; 8-byte Folded Spill
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x0, [sp, #320]                  ; 8-byte Folded Reload
	adrp	x1, l_.str.7@PAGE
	add	x1, x1, l_.str.7@PAGEOFF
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	mov	x1, x0
	ldr	x0, [sp, #248]                  ; 8-byte Folded Reload
	str	x1, [sp, #48]                   ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE3maxIfEEfv
	ldr	x0, [sp, #48]                   ; 8-byte Folded Reload
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEf
	ldr	x1, [sp, #144]                  ; 8-byte Folded Reload
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x0, [sp, #320]                  ; 8-byte Folded Reload
	adrp	x1, l_.str.8@PAGE
	add	x1, x1, l_.str.8@PAGEOFF
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	mov	x1, x0
	ldr	x0, [sp, #248]                  ; 8-byte Folded Reload
	str	x1, [sp, #56]                   ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE3sumIfEET_v
	ldr	x0, [sp, #56]                   ; 8-byte Folded Reload
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEf
	ldr	x1, [sp, #144]                  ; 8-byte Folded Reload
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x0, [sp, #320]                  ; 8-byte Folded Reload
	adrp	x1, l_.str.9@PAGE
	add	x1, x1, l_.str.9@PAGEOFF
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	mov	x1, x0
	ldr	x0, [sp, #248]                  ; 8-byte Folded Reload
	str	x1, [sp, #64]                   ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4prodIfEET_v
	ldr	x0, [sp, #64]                   ; 8-byte Folded Reload
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEf
	ldr	x1, [sp, #144]                  ; 8-byte Folded Reload
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x0, [sp, #320]                  ; 8-byte Folded Reload
	adrp	x1, l_.str.10@PAGE
	add	x1, x1, l_.str.10@PAGEOFF
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	mov	x1, x0
	ldr	x0, [sp, #248]                  ; 8-byte Folded Reload
	str	x1, [sp, #72]                   ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4meanIfEET_v
	ldr	x0, [sp, #72]                   ; 8-byte Folded Reload
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEf
	ldr	x1, [sp, #144]                  ; 8-byte Folded Reload
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x1, [sp, #120]                  ; 8-byte Folded Reload
	ldr	x0, [sp, #320]                  ; 8-byte Folded Reload
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEPFRNS_8ios_baseES5_E
	adrp	x1, l_.str.11@PAGE
	add	x1, x1, l_.str.11@PAGEOFF
	str	x1, [sp, #128]                  ; 8-byte Folded Spill
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x1, [sp, #152]                  ; 8-byte Folded Reload
	mov	x2, x0
	ldr	x0, [sp, #248]                  ; 8-byte Folded Reload
	str	x2, [sp, #80]                   ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfEeqERKS1_
	mov	x8, x0
	ldr	x0, [sp, #80]                   ; 8-byte Folded Reload
	and	w1, w8, #0x1
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEb
	ldr	x1, [sp, #144]                  ; 8-byte Folded Reload
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x1, [sp, #120]                  ; 8-byte Folded Reload
	ldr	x0, [sp, #320]                  ; 8-byte Folded Reload
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEPFRNS_8ios_baseES5_E
	ldr	x1, [sp, #128]                  ; 8-byte Folded Reload
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x1, [sp, #248]                  ; 8-byte Folded Reload
	str	x0, [sp, #88]                   ; 8-byte Folded Spill
	mov	x0, x1
	bl	__ZNK3phy6matrixIfEeqERKS1_
	mov	x8, x0
	ldr	x0, [sp, #88]                   ; 8-byte Folded Reload
	and	w1, w8, #0x1
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEb
	ldr	x1, [sp, #144]                  ; 8-byte Folded Reload
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x1, [sp, #120]                  ; 8-byte Folded Reload
	ldr	x0, [sp, #320]                  ; 8-byte Folded Reload
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEPFRNS_8ios_baseES5_E
	ldr	x1, [sp, #128]                  ; 8-byte Folded Reload
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x1, [sp, #152]                  ; 8-byte Folded Reload
	mov	x2, x0
	ldr	x0, [sp, #248]                  ; 8-byte Folded Reload
	str	x2, [sp, #96]                   ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfEneERKS1_
	mov	x8, x0
	ldr	x0, [sp, #96]                   ; 8-byte Folded Reload
	and	w1, w8, #0x1
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEb
	ldr	x1, [sp, #144]                  ; 8-byte Folded Reload
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x1, [sp, #120]                  ; 8-byte Folded Reload
	ldr	x0, [sp, #320]                  ; 8-byte Folded Reload
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEPFRNS_8ios_baseES5_E
	ldr	x1, [sp, #128]                  ; 8-byte Folded Reload
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x1, [sp, #248]                  ; 8-byte Folded Reload
	str	x0, [sp, #104]                  ; 8-byte Folded Spill
	mov	x0, x1
	bl	__ZNK3phy6matrixIfEneERKS1_
	mov	x8, x0
	ldr	x0, [sp, #104]                  ; 8-byte Folded Reload
	and	w1, w8, #0x1
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEb
	ldr	x1, [sp, #144]                  ; 8-byte Folded Reload
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x2, [sp, #112]                  ; 8-byte Folded Reload
	ldr	w3, [sp, #336]                  ; 4-byte Folded Reload
	add	x0, sp, #720
	str	x0, [sp, #232]                  ; 8-byte Folded Spill
	mov	x1, x2
	bl	__ZN3phy6matrixIfEC1Emmi
	ldr	x0, [sp, #320]                  ; 8-byte Folded Reload
	ldr	x1, [sp, #120]                  ; 8-byte Folded Reload
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEPFRNS_8ios_baseES5_E
	ldr	x1, [sp, #128]                  ; 8-byte Folded Reload
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x1, [sp, #232]                  ; 8-byte Folded Reload
	mov	x2, x0
	ldr	x0, [sp, #248]                  ; 8-byte Folded Reload
	str	x2, [sp, #136]                  ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfEeqERKS1_
	mov	x8, x0
	ldr	x0, [sp, #136]                  ; 8-byte Folded Reload
	and	w1, w8, #0x1
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEb
	ldr	x1, [sp, #144]                  ; 8-byte Folded Reload
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x2, [sp, #288]                  ; 8-byte Folded Reload
	ldr	w3, [sp, #300]                  ; 4-byte Folded Reload
	add	x0, sp, #688
	str	x0, [sp, #216]                  ; 8-byte Folded Spill
	mov	x1, x2
	bl	__ZN3phy6matrixIfEC1Emmi
	ldr	x0, [sp, #248]                  ; 8-byte Folded Reload
	ldr	x1, [sp, #152]                  ; 8-byte Folded Reload
	add	x8, sp, #656
	str	x8, [sp, #160]                  ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfEplERKS1_
	ldr	x9, [sp, #160]                  ; 8-byte Folded Reload
	ldr	x8, [sp, #216]                  ; 8-byte Folded Reload
	ldr	x10, [sp, #256]                 ; 8-byte Folded Reload
	ldr	x0, [sp, #320]                  ; 8-byte Folded Reload
	ldr	q0, [x10, #176]
	str	q0, [x10, #208]
	ldur	q0, [x9, #12]
	stur	q0, [x8, #12]
	adrp	x1, l_.str.12@PAGE
	add	x1, x1, l_.str.12@PAGEOFF
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x0, [sp, #216]                  ; 8-byte Folded Reload
	bl	__ZN3phy6matrixIfE6mprintEv
	ldr	x1, [sp, #168]                  ; 8-byte Folded Reload
	ldr	x0, [sp, #248]                  ; 8-byte Folded Reload
	add	x8, sp, #624
	str	x8, [sp, #176]                  ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfEmiERKS1_
	ldr	x9, [sp, #176]                  ; 8-byte Folded Reload
	ldr	x8, [sp, #216]                  ; 8-byte Folded Reload
	ldr	x10, [sp, #256]                 ; 8-byte Folded Reload
	ldr	x0, [sp, #320]                  ; 8-byte Folded Reload
	ldr	q0, [x10, #144]
	str	q0, [x10, #208]
	ldur	q0, [x9, #12]
	stur	q0, [x8, #12]
	adrp	x1, l_.str.13@PAGE
	add	x1, x1, l_.str.13@PAGEOFF
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x0, [sp, #216]                  ; 8-byte Folded Reload
	bl	__ZN3phy6matrixIfE6mprintEv
	ldr	x0, [sp, #248]                  ; 8-byte Folded Reload
	add	x1, sp, #620
	str	x1, [sp, #192]                  ; 8-byte Folded Spill
	fmov	s0, #5.00000000
	str	s0, [sp, #620]
	add	x8, sp, #584
	str	x8, [sp, #184]                  ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfEmlERKf
	ldr	x9, [sp, #184]                  ; 8-byte Folded Reload
	ldr	x8, [sp, #216]                  ; 8-byte Folded Reload
	ldr	x10, [sp, #256]                 ; 8-byte Folded Reload
	ldr	x0, [sp, #320]                  ; 8-byte Folded Reload
	ldur	q0, [x10, #104]
	str	q0, [x10, #208]
	ldur	q0, [x9, #12]
	stur	q0, [x8, #12]
	adrp	x1, l_.str.14@PAGE
	add	x1, x1, l_.str.14@PAGEOFF
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x0, [sp, #216]                  ; 8-byte Folded Reload
	bl	__ZN3phy6matrixIfE6mprintEv
	ldr	x1, [sp, #192]                  ; 8-byte Folded Reload
	ldr	x0, [sp, #216]                  ; 8-byte Folded Reload
	add	x8, sp, #552
	str	x8, [sp, #200]                  ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfEdvERKf
	ldr	x9, [sp, #200]                  ; 8-byte Folded Reload
	ldr	x8, [sp, #216]                  ; 8-byte Folded Reload
	ldr	x10, [sp, #256]                 ; 8-byte Folded Reload
	ldr	x0, [sp, #320]                  ; 8-byte Folded Reload
	ldur	q0, [x10, #72]
	str	q0, [x10, #208]
	ldur	q0, [x9, #12]
	stur	q0, [x8, #12]
	adrp	x1, l_.str.15@PAGE
	add	x1, x1, l_.str.15@PAGEOFF
	str	x1, [sp, #224]                  ; 8-byte Folded Spill
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x0, [sp, #216]                  ; 8-byte Folded Reload
	bl	__ZN3phy6matrixIfE6mprintEv
	ldr	x0, [sp, #216]                  ; 8-byte Folded Reload
	add	x1, sp, #516
	movi	d0, #0000000000000000
	str	s0, [sp, #516]
	add	x8, sp, #520
	str	x8, [sp, #208]                  ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfEdvERKf
	ldr	x9, [sp, #208]                  ; 8-byte Folded Reload
	ldr	x8, [sp, #216]                  ; 8-byte Folded Reload
	ldr	x1, [sp, #224]                  ; 8-byte Folded Reload
	ldr	x10, [sp, #256]                 ; 8-byte Folded Reload
	ldr	x0, [sp, #320]                  ; 8-byte Folded Reload
	ldur	q0, [x10, #40]
	str	q0, [x10, #208]
	ldur	q0, [x9, #12]
	stur	q0, [x8, #12]
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x2, [sp, #288]                  ; 8-byte Folded Reload
	ldr	w3, [sp, #336]                  ; 4-byte Folded Reload
	add	x0, sp, #480
	str	x0, [sp, #272]                  ; 8-byte Folded Spill
	mov	x1, x2
	bl	__ZN3phy6matrixIfEC1Emmi
	ldr	x0, [sp, #320]                  ; 8-byte Folded Reload
	adrp	x1, l_.str.16@PAGE
	add	x1, x1, l_.str.16@PAGEOFF
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x1, [sp, #232]                  ; 8-byte Folded Reload
	ldr	x0, [sp, #248]                  ; 8-byte Folded Reload
	add	x8, sp, #448
	str	x8, [sp, #240]                  ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfEmlERKS1_
	ldr	x9, [sp, #240]                  ; 8-byte Folded Reload
	ldr	x1, [sp, #248]                  ; 8-byte Folded Reload
	ldr	x10, [sp, #256]                 ; 8-byte Folded Reload
	ldr	x8, [sp, #272]                  ; 8-byte Folded Reload
	ldr	q0, [sp, #448]
	str	q0, [x10]
	ldur	q0, [x9, #12]
	stur	q0, [x8, #12]
	add	x8, sp, #416
	str	x8, [sp, #264]                  ; 8-byte Folded Spill
	mov	x0, x1
	bl	__ZNK3phy6matrixIfEmlERKS1_
	ldr	x9, [sp, #256]                  ; 8-byte Folded Reload
	ldr	x8, [sp, #264]                  ; 8-byte Folded Reload
	ldr	x0, [sp, #272]                  ; 8-byte Folded Reload
	ldr	q0, [sp, #416]
	str	q0, [x9]
	ldur	q0, [x8, #12]
	stur	q0, [x0, #12]
	bl	__ZN3phy6matrixIfE6mprintEv
	ldr	x2, [sp, #288]                  ; 8-byte Folded Reload
	ldr	w3, [sp, #300]                  ; 4-byte Folded Reload
	add	x0, sp, #384
	str	x0, [sp, #280]                  ; 8-byte Folded Spill
	mov	x1, x2
	bl	__ZN3phy6matrixIiEC1Emmi
	ldr	x0, [sp, #280]                  ; 8-byte Folded Reload
	ldr	x1, [sp, #312]                  ; 8-byte Folded Reload
	mov	x2, #0
	bl	__ZN3phy6matrixIiEclEmm
	mov	x8, x0
	ldr	x0, [sp, #320]                  ; 8-byte Folded Reload
	ldr	w8, [x8]
	str	w8, [sp, #380]
	ldr	w1, [sp, #380]
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEi
	adrp	x1, __ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_@GOTPAGE
	ldr	x1, [x1, __ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_@GOTPAGEOFF]
	str	x1, [sp, #328]                  ; 8-byte Folded Spill
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEPFRS3_S4_E
	ldr	x2, [sp, #288]                  ; 8-byte Folded Reload
	ldr	w3, [sp, #300]                  ; 4-byte Folded Reload
	add	x0, sp, #344
	str	x0, [sp, #304]                  ; 8-byte Folded Spill
	mov	x1, x2
	bl	__ZN3phy6matrixIiEC1Emmi
	ldr	x0, [sp, #304]                  ; 8-byte Folded Reload
	ldr	x2, [sp, #312]                  ; 8-byte Folded Reload
	mov	x1, x2
	bl	__ZNK3phy6matrixIiEclEmm
	mov	x8, x0
	ldr	x0, [sp, #320]                  ; 8-byte Folded Reload
	ldr	w8, [x8]
	str	w8, [sp, #340]
	ldr	w1, [sp, #340]
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEi
	ldr	x1, [sp, #328]                  ; 8-byte Folded Reload
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEPFRS3_S4_E
	ldr	w0, [sp, #336]                  ; 4-byte Folded Reload
	add	sp, sp, #992
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	ldp	x28, x27, [sp], #32             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZN3phy6matrixIfEC1Emmi        ; -- Begin function _ZN3phy6matrixIfEC1Emmi
	.weak_def_can_be_hidden	__ZN3phy6matrixIfEC1Emmi
	.p2align	2
__ZN3phy6matrixIfEC1Emmi:               ; @_ZN3phy6matrixIfEC1Emmi
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	x1, [x29, #-16]
	str	x2, [sp, #24]
	str	w3, [sp, #20]
	ldur	x0, [x29, #-8]
	str	x0, [sp, #8]                    ; 8-byte Folded Spill
	ldur	x1, [x29, #-16]
	ldr	x2, [sp, #24]
	ldr	w3, [sp, #20]
	bl	__ZN3phy6matrixIfEC2Emmi
	ldr	x0, [sp, #8]                    ; 8-byte Folded Reload
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc ; -- Begin function _ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	.weak_definition	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	.p2align	2
__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc: ; @_ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	str	x1, [sp, #16]
	ldur	x8, [x29, #-8]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	ldr	x8, [sp, #16]
	str	x8, [sp]                        ; 8-byte Folded Spill
	ldr	x0, [sp, #16]
	bl	__ZNSt3__111char_traitsIcE6lengthEPKc
	ldr	x1, [sp]                        ; 8-byte Folded Reload
	mov	x2, x0
	ldr	x0, [sp, #8]                    ; 8-byte Folded Reload
	bl	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZN3phy6matrixIfE6mprintEv     ; -- Begin function _ZN3phy6matrixIfE6mprintEv
	.weak_definition	__ZN3phy6matrixIfE6mprintEv
	.p2align	2
__ZN3phy6matrixIfE6mprintEv:            ; @_ZN3phy6matrixIfE6mprintEv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	ldur	x8, [x29, #-8]
	str	x8, [sp, #24]                   ; 8-byte Folded Spill
	stur	wzr, [x29, #-12]
	b	LBB3_1
LBB3_1:                                 ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB3_3 Depth 2
	ldr	x0, [sp, #24]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-12]
	str	x8, [sp, #16]                   ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4rowsEv
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB3_8
	b	LBB3_2
LBB3_2:                                 ;   in Loop: Header=BB3_1 Depth=1
	stur	wzr, [x29, #-16]
	b	LBB3_3
LBB3_3:                                 ;   Parent Loop BB3_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	x0, [sp, #24]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-16]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB3_6
	b	LBB3_4
LBB3_4:                                 ;   in Loop: Header=BB3_3 Depth=2
	ldr	x8, [sp, #24]                   ; 8-byte Folded Reload
	ldr	x8, [x8]
	ldursw	x9, [x29, #-12]
	ldr	x8, [x8, x9, lsl #3]
	ldursw	x9, [x29, #-16]
	ldr	s0, [x8, x9, lsl #2]
	adrp	x0, __ZNSt3__14coutE@GOTPAGE
	ldr	x0, [x0, __ZNSt3__14coutE@GOTPAGEOFF]
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEf
	mov	w1, #32
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_c
	b	LBB3_5
LBB3_5:                                 ;   in Loop: Header=BB3_3 Depth=2
	ldur	w8, [x29, #-16]
	add	w8, w8, #1
	stur	w8, [x29, #-16]
	b	LBB3_3
LBB3_6:                                 ;   in Loop: Header=BB3_1 Depth=1
	adrp	x0, __ZNSt3__14coutE@GOTPAGE
	ldr	x0, [x0, __ZNSt3__14coutE@GOTPAGEOFF]
	mov	w1, #10
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_c
	b	LBB3_7
LBB3_7:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldur	w8, [x29, #-12]
	add	w8, w8, #1
	stur	w8, [x29, #-12]
	b	LBB3_1
LBB3_8:
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZN3phy6matrixIfE8identityEmm  ; -- Begin function _ZN3phy6matrixIfE8identityEmm
	.weak_definition	__ZN3phy6matrixIfE8identityEmm
	.p2align	2
__ZN3phy6matrixIfE8identityEmm:         ; @_ZN3phy6matrixIfE8identityEmm
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x8, [sp, #16]                   ; 8-byte Folded Spill
	mov	x8, x0
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	stur	x8, [x29, #-8]
	stur	x1, [x29, #-16]
	ldur	x1, [x29, #-8]
	ldur	x2, [x29, #-16]
	mov	w3, #0
	bl	__ZN3phy6matrixIfEC1Emmi
	stur	wzr, [x29, #-20]
	b	LBB4_1
LBB4_1:                                 ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB4_3 Depth 2
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-20]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4rowsEv
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB4_11
	b	LBB4_2
LBB4_2:                                 ;   in Loop: Header=BB4_1 Depth=1
	str	wzr, [sp, #24]
	b	LBB4_3
LBB4_3:                                 ;   Parent Loop BB4_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	ldrsw	x8, [sp, #24]
	str	x8, [sp]                        ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB4_9
	b	LBB4_4
LBB4_4:                                 ;   in Loop: Header=BB4_3 Depth=2
	ldur	w8, [x29, #-20]
	ldr	w9, [sp, #24]
	subs	w8, w8, w9
	b.ne	LBB4_6
	b	LBB4_5
LBB4_5:                                 ;   in Loop: Header=BB4_3 Depth=2
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	ldr	x8, [x8]
	ldursw	x9, [x29, #-20]
	ldr	x8, [x8, x9, lsl #3]
	ldrsw	x9, [sp, #24]
	fmov	s0, #1.00000000
	str	s0, [x8, x9, lsl #2]
	b	LBB4_7
LBB4_6:                                 ;   in Loop: Header=BB4_3 Depth=2
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	ldr	x8, [x8]
	ldursw	x9, [x29, #-20]
	ldr	x8, [x8, x9, lsl #3]
	ldrsw	x9, [sp, #24]
	movi	d0, #0000000000000000
	str	s0, [x8, x9, lsl #2]
	b	LBB4_7
LBB4_7:                                 ;   in Loop: Header=BB4_3 Depth=2
	b	LBB4_8
LBB4_8:                                 ;   in Loop: Header=BB4_3 Depth=2
	ldr	w8, [sp, #24]
	add	w8, w8, #1
	str	w8, [sp, #24]
	b	LBB4_3
LBB4_9:                                 ;   in Loop: Header=BB4_1 Depth=1
	b	LBB4_10
LBB4_10:                                ;   in Loop: Header=BB4_1 Depth=1
	ldur	w8, [x29, #-20]
	add	w8, w8, #1
	stur	w8, [x29, #-20]
	b	LBB4_1
LBB4_11:
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZN3phy6matrixIfE9transposeEmm ; -- Begin function _ZN3phy6matrixIfE9transposeEmm
	.weak_definition	__ZN3phy6matrixIfE9transposeEmm
	.p2align	2
__ZN3phy6matrixIfE9transposeEmm:        ; @_ZN3phy6matrixIfE9transposeEmm
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #80
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x8, [sp, #16]                   ; 8-byte Folded Spill
	mov	x8, x0
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	stur	x8, [x29, #-8]
	stur	x1, [x29, #-16]
	stur	x2, [x29, #-24]
	ldur	x8, [x29, #-8]
	str	x8, [sp, #24]                   ; 8-byte Folded Spill
	ldur	x1, [x29, #-16]
	ldur	x2, [x29, #-24]
	mov	w3, #0
	bl	__ZN3phy6matrixIfEC1Emmi
	stur	wzr, [x29, #-28]
	b	LBB5_1
LBB5_1:                                 ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB5_3 Depth 2
	ldr	x0, [sp, #24]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-28]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4rowsEv
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB5_8
	b	LBB5_2
LBB5_2:                                 ;   in Loop: Header=BB5_1 Depth=1
	str	wzr, [sp, #32]
	b	LBB5_3
LBB5_3:                                 ;   Parent Loop BB5_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	x0, [sp, #24]                   ; 8-byte Folded Reload
	ldrsw	x8, [sp, #32]
	str	x8, [sp]                        ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB5_6
	b	LBB5_4
LBB5_4:                                 ;   in Loop: Header=BB5_3 Depth=2
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	ldr	x9, [sp, #24]                   ; 8-byte Folded Reload
	ldr	x9, [x9]
	ldrsw	x10, [sp, #32]
	ldr	x9, [x9, x10, lsl #3]
	ldursw	x10, [x29, #-28]
	ldr	s0, [x9, x10, lsl #2]
	ldr	x8, [x8]
	ldursw	x9, [x29, #-28]
	ldr	x8, [x8, x9, lsl #3]
	ldrsw	x9, [sp, #32]
	str	s0, [x8, x9, lsl #2]
	b	LBB5_5
LBB5_5:                                 ;   in Loop: Header=BB5_3 Depth=2
	ldr	w8, [sp, #32]
	add	w8, w8, #1
	str	w8, [sp, #32]
	b	LBB5_3
LBB5_6:                                 ;   in Loop: Header=BB5_1 Depth=1
	b	LBB5_7
LBB5_7:                                 ;   in Loop: Header=BB5_1 Depth=1
	ldur	w8, [x29, #-28]
	add	w8, w8, #1
	stur	w8, [x29, #-28]
	b	LBB5_1
LBB5_8:
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZNK3phy6matrixIfE3minIfEEfv   ; -- Begin function _ZNK3phy6matrixIfE3minIfEEfv
	.weak_definition	__ZNK3phy6matrixIfE3minIfEEfv
	.p2align	2
__ZNK3phy6matrixIfE3minIfEEfv:          ; @_ZNK3phy6matrixIfE3minIfEEfv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	ldur	x8, [x29, #-8]
	str	x8, [sp, #16]                   ; 8-byte Folded Spill
	mov	w8, #15360
	movk	w8, #17948, lsl #16
	fmov	s0, w8
	stur	s0, [x29, #-12]
	stur	wzr, [x29, #-16]
	b	LBB6_1
LBB6_1:                                 ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB6_3 Depth 2
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-16]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4rowsEv
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB6_10
	b	LBB6_2
LBB6_2:                                 ;   in Loop: Header=BB6_1 Depth=1
	stur	wzr, [x29, #-20]
	b	LBB6_3
LBB6_3:                                 ;   Parent Loop BB6_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-20]
	str	x8, [sp]                        ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB6_8
	b	LBB6_4
LBB6_4:                                 ;   in Loop: Header=BB6_3 Depth=2
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	ldur	s0, [x29, #-12]
	ldr	x8, [x8]
	ldursw	x9, [x29, #-16]
	ldr	x8, [x8, x9, lsl #3]
	ldursw	x9, [x29, #-20]
	ldr	s1, [x8, x9, lsl #2]
	fcmp	s0, s1
	b.le	LBB6_6
	b	LBB6_5
LBB6_5:                                 ;   in Loop: Header=BB6_3 Depth=2
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	ldr	x8, [x8]
	ldursw	x9, [x29, #-16]
	ldr	x8, [x8, x9, lsl #3]
	ldursw	x9, [x29, #-20]
	ldr	s0, [x8, x9, lsl #2]
	stur	s0, [x29, #-12]
	b	LBB6_6
LBB6_6:                                 ;   in Loop: Header=BB6_3 Depth=2
	b	LBB6_7
LBB6_7:                                 ;   in Loop: Header=BB6_3 Depth=2
	ldur	w8, [x29, #-20]
	add	w8, w8, #1
	stur	w8, [x29, #-20]
	b	LBB6_3
LBB6_8:                                 ;   in Loop: Header=BB6_1 Depth=1
	b	LBB6_9
LBB6_9:                                 ;   in Loop: Header=BB6_1 Depth=1
	ldur	w8, [x29, #-16]
	add	w8, w8, #1
	stur	w8, [x29, #-16]
	b	LBB6_1
LBB6_10:
	ldur	s0, [x29, #-12]
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZNK3phy6matrixIfE3maxIfEEfv   ; -- Begin function _ZNK3phy6matrixIfE3maxIfEEfv
	.weak_definition	__ZNK3phy6matrixIfE3maxIfEEfv
	.p2align	2
__ZNK3phy6matrixIfE3maxIfEEfv:          ; @_ZNK3phy6matrixIfE3maxIfEEfv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	ldur	x8, [x29, #-8]
	str	x8, [sp, #16]                   ; 8-byte Folded Spill
	movi	d0, #0000000000000000
	stur	s0, [x29, #-12]
	stur	wzr, [x29, #-16]
	b	LBB7_1
LBB7_1:                                 ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB7_3 Depth 2
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-16]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4rowsEv
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB7_10
	b	LBB7_2
LBB7_2:                                 ;   in Loop: Header=BB7_1 Depth=1
	stur	wzr, [x29, #-20]
	b	LBB7_3
LBB7_3:                                 ;   Parent Loop BB7_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-20]
	str	x8, [sp]                        ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB7_8
	b	LBB7_4
LBB7_4:                                 ;   in Loop: Header=BB7_3 Depth=2
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	ldur	s0, [x29, #-12]
	ldr	x8, [x8]
	ldursw	x9, [x29, #-16]
	ldr	x8, [x8, x9, lsl #3]
	ldursw	x9, [x29, #-20]
	ldr	s1, [x8, x9, lsl #2]
	fcmp	s0, s1
	b.pl	LBB7_6
	b	LBB7_5
LBB7_5:                                 ;   in Loop: Header=BB7_3 Depth=2
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	ldr	x8, [x8]
	ldursw	x9, [x29, #-16]
	ldr	x8, [x8, x9, lsl #3]
	ldursw	x9, [x29, #-20]
	ldr	s0, [x8, x9, lsl #2]
	stur	s0, [x29, #-12]
	b	LBB7_6
LBB7_6:                                 ;   in Loop: Header=BB7_3 Depth=2
	b	LBB7_7
LBB7_7:                                 ;   in Loop: Header=BB7_3 Depth=2
	ldur	w8, [x29, #-20]
	add	w8, w8, #1
	stur	w8, [x29, #-20]
	b	LBB7_3
LBB7_8:                                 ;   in Loop: Header=BB7_1 Depth=1
	b	LBB7_9
LBB7_9:                                 ;   in Loop: Header=BB7_1 Depth=1
	ldur	w8, [x29, #-16]
	add	w8, w8, #1
	stur	w8, [x29, #-16]
	b	LBB7_1
LBB7_10:
	ldur	s0, [x29, #-12]
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZNK3phy6matrixIfE3sumIfEET_v  ; -- Begin function _ZNK3phy6matrixIfE3sumIfEET_v
	.weak_definition	__ZNK3phy6matrixIfE3sumIfEET_v
	.p2align	2
__ZNK3phy6matrixIfE3sumIfEET_v:         ; @_ZNK3phy6matrixIfE3sumIfEET_v
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	ldur	x8, [x29, #-8]
	str	x8, [sp, #16]                   ; 8-byte Folded Spill
	movi	d0, #0000000000000000
	stur	s0, [x29, #-12]
	stur	wzr, [x29, #-16]
	b	LBB8_1
LBB8_1:                                 ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB8_3 Depth 2
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-16]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4rowsEv
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB8_8
	b	LBB8_2
LBB8_2:                                 ;   in Loop: Header=BB8_1 Depth=1
	stur	wzr, [x29, #-20]
	b	LBB8_3
LBB8_3:                                 ;   Parent Loop BB8_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-20]
	str	x8, [sp]                        ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB8_6
	b	LBB8_4
LBB8_4:                                 ;   in Loop: Header=BB8_3 Depth=2
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	ldr	x8, [x8]
	ldursw	x9, [x29, #-16]
	ldr	x8, [x8, x9, lsl #3]
	ldursw	x9, [x29, #-20]
	ldr	s1, [x8, x9, lsl #2]
	ldur	s0, [x29, #-12]
	fadd	s0, s0, s1
	stur	s0, [x29, #-12]
	b	LBB8_5
LBB8_5:                                 ;   in Loop: Header=BB8_3 Depth=2
	ldur	w8, [x29, #-20]
	add	w8, w8, #1
	stur	w8, [x29, #-20]
	b	LBB8_3
LBB8_6:                                 ;   in Loop: Header=BB8_1 Depth=1
	b	LBB8_7
LBB8_7:                                 ;   in Loop: Header=BB8_1 Depth=1
	ldur	w8, [x29, #-16]
	add	w8, w8, #1
	stur	w8, [x29, #-16]
	b	LBB8_1
LBB8_8:
	ldur	s0, [x29, #-12]
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZNK3phy6matrixIfE4prodIfEET_v ; -- Begin function _ZNK3phy6matrixIfE4prodIfEET_v
	.weak_definition	__ZNK3phy6matrixIfE4prodIfEET_v
	.p2align	2
__ZNK3phy6matrixIfE4prodIfEET_v:        ; @_ZNK3phy6matrixIfE4prodIfEET_v
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	ldur	x8, [x29, #-8]
	str	x8, [sp, #16]                   ; 8-byte Folded Spill
	movi	d0, #0000000000000000
	stur	s0, [x29, #-12]
	stur	wzr, [x29, #-16]
	b	LBB9_1
LBB9_1:                                 ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB9_3 Depth 2
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-16]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4rowsEv
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB9_8
	b	LBB9_2
LBB9_2:                                 ;   in Loop: Header=BB9_1 Depth=1
	stur	wzr, [x29, #-20]
	b	LBB9_3
LBB9_3:                                 ;   Parent Loop BB9_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-20]
	str	x8, [sp]                        ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB9_6
	b	LBB9_4
LBB9_4:                                 ;   in Loop: Header=BB9_3 Depth=2
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	ldr	x8, [x8]
	ldursw	x9, [x29, #-16]
	ldr	x8, [x8, x9, lsl #3]
	ldursw	x9, [x29, #-20]
	ldr	s1, [x8, x9, lsl #2]
	ldur	s0, [x29, #-12]
	fmul	s0, s0, s1
	stur	s0, [x29, #-12]
	b	LBB9_5
LBB9_5:                                 ;   in Loop: Header=BB9_3 Depth=2
	ldur	w8, [x29, #-20]
	add	w8, w8, #1
	stur	w8, [x29, #-20]
	b	LBB9_3
LBB9_6:                                 ;   in Loop: Header=BB9_1 Depth=1
	b	LBB9_7
LBB9_7:                                 ;   in Loop: Header=BB9_1 Depth=1
	ldur	w8, [x29, #-16]
	add	w8, w8, #1
	stur	w8, [x29, #-16]
	b	LBB9_1
LBB9_8:
	ldur	s0, [x29, #-12]
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZNK3phy6matrixIfE4meanIfEET_v ; -- Begin function _ZNK3phy6matrixIfE4meanIfEET_v
	.weak_definition	__ZNK3phy6matrixIfE4meanIfEET_v
	.p2align	2
__ZNK3phy6matrixIfE4meanIfEET_v:        ; @_ZNK3phy6matrixIfE4meanIfEET_v
Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception0
; %bb.0:
	sub	sp, sp, #80
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	ldur	x0, [x29, #-8]
	str	x0, [sp, #24]                   ; 8-byte Folded Spill
	movi	d0, #0000000000000000
	stur	s0, [x29, #-12]
	bl	__ZNK3phy6matrixIfE4rowsEv
	cbz	x0, LBB10_2
	b	LBB10_1
LBB10_1:
	ldr	x0, [sp, #24]                   ; 8-byte Folded Reload
	bl	__ZNK3phy6matrixIfE4colsEv
	cbnz	x0, LBB10_8
	b	LBB10_2
LBB10_2:
	mov	x0, #4
	bl	___cxa_allocate_exception
	mov	w8, #-1
	str	w8, [x0]
Ltmp0:
	adrp	x1, __ZTIi@GOTPAGE
	ldr	x1, [x1, __ZTIi@GOTPAGEOFF]
	mov	x2, #0
	bl	___cxa_throw
Ltmp1:
	b	LBB10_11
LBB10_3:
Ltmp2:
	mov	x8, x1
	stur	x0, [x29, #-24]
	stur	w8, [x29, #-28]
	b	LBB10_4
LBB10_4:
	ldur	w8, [x29, #-28]
	subs	w8, w8, #1
	b.ne	LBB10_10
	b	LBB10_5
LBB10_5:
	ldur	x0, [x29, #-24]
	bl	___cxa_begin_catch
	ldr	w8, [x0]
	str	w8, [sp, #32]
Ltmp3:
	adrp	x0, __ZNSt3__14coutE@GOTPAGE
	ldr	x0, [x0, __ZNSt3__14coutE@GOTPAGEOFF]
	adrp	x1, l_.str.17@PAGE
	add	x1, x1, l_.str.17@PAGEOFF
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
Ltmp4:
	b	LBB10_6
LBB10_6:
	bl	___cxa_end_catch
	b	LBB10_7
LBB10_7:
	ldr	x0, [sp, #24]                   ; 8-byte Folded Reload
	bl	__ZNK3phy6matrixIfE3sumIfEET_v
	ldr	x0, [sp, #24]                   ; 8-byte Folded Reload
	str	s0, [sp, #12]                   ; 4-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4rowsEv
	mov	x8, x0
	ldr	x0, [sp, #24]                   ; 8-byte Folded Reload
	str	x8, [sp, #16]                   ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	s0, [sp, #12]                   ; 4-byte Folded Reload
	mov	x8, x0
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	mul	x8, x0, x8
	ucvtf	s1, x8
	fdiv	s0, s0, s1
	stur	s0, [x29, #-12]
	ldur	s0, [x29, #-12]
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
LBB10_8:
	b	LBB10_7
LBB10_9:
Ltmp5:
	mov	x8, x1
	stur	x0, [x29, #-24]
	stur	w8, [x29, #-28]
	bl	___cxa_end_catch
	b	LBB10_10
LBB10_10:
	ldur	x0, [x29, #-24]
	bl	__Unwind_Resume
LBB10_11:
Lfunc_end0:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table10:
Lexception0:
	.byte	255                             ; @LPStart Encoding = omit
	.byte	155                             ; @TType Encoding = indirect pcrel sdata4
	.uleb128 Lttbase0-Lttbaseref0
Lttbaseref0:
	.byte	1                               ; Call site Encoding = uleb128
	.uleb128 Lcst_end0-Lcst_begin0
Lcst_begin0:
	.uleb128 Lfunc_begin0-Lfunc_begin0      ; >> Call Site 1 <<
	.uleb128 Ltmp0-Lfunc_begin0             ;   Call between Lfunc_begin0 and Ltmp0
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp0-Lfunc_begin0             ; >> Call Site 2 <<
	.uleb128 Ltmp1-Ltmp0                    ;   Call between Ltmp0 and Ltmp1
	.uleb128 Ltmp2-Lfunc_begin0             ;     jumps to Ltmp2
	.byte	1                               ;   On action: 1
	.uleb128 Ltmp1-Lfunc_begin0             ; >> Call Site 3 <<
	.uleb128 Ltmp3-Ltmp1                    ;   Call between Ltmp1 and Ltmp3
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp3-Lfunc_begin0             ; >> Call Site 4 <<
	.uleb128 Ltmp4-Ltmp3                    ;   Call between Ltmp3 and Ltmp4
	.uleb128 Ltmp5-Lfunc_begin0             ;     jumps to Ltmp5
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp4-Lfunc_begin0             ; >> Call Site 5 <<
	.uleb128 Lfunc_end0-Ltmp4               ;   Call between Ltmp4 and Lfunc_end0
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
Lcst_end0:
	.byte	1                               ; >> Action Record 1 <<
                                        ;   Catch TypeInfo 1
	.byte	0                               ;   No further actions
	.p2align	2
                                        ; >> Catch TypeInfos <<
Ltmp6:                                  ; TypeInfo 1
	.long	__ZTIi@GOT-Ltmp6
Lttbase0:
	.p2align	2
                                        ; -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.p2align	2                               ; -- Begin function _ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEPFRNS_8ios_baseES5_E
__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEPFRNS_8ios_baseES5_E: ; @_ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEPFRNS_8ios_baseES5_E
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	str	x1, [sp, #16]
	ldur	x9, [x29, #-8]
	str	x9, [sp, #8]                    ; 8-byte Folded Spill
	ldr	x8, [sp, #16]
	ldr	x10, [x9]
	ldur	x10, [x10, #-24]
	add	x0, x9, x10
	blr	x8
	ldr	x0, [sp, #8]                    ; 8-byte Folded Reload
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZNSt3__19boolalphaERNS_8ios_baseE ; -- Begin function _ZNSt3__19boolalphaERNS_8ios_baseE
	.weak_definition	__ZNSt3__19boolalphaERNS_8ios_baseE
	.p2align	2
__ZNSt3__19boolalphaERNS_8ios_baseE:    ; @_ZNSt3__19boolalphaERNS_8ios_baseE
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	mov	w1, #1
	bl	__ZNSt3__18ios_base4setfEj
	ldr	x0, [sp, #8]
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZNK3phy6matrixIfEeqERKS1_     ; -- Begin function _ZNK3phy6matrixIfEeqERKS1_
	.weak_definition	__ZNK3phy6matrixIfEeqERKS1_
	.p2align	2
__ZNK3phy6matrixIfEeqERKS1_:            ; @_ZNK3phy6matrixIfEeqERKS1_
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #96
	stp	x29, x30, [sp, #80]             ; 16-byte Folded Spill
	add	x29, sp, #80
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-16]
	stur	x1, [x29, #-24]
	ldur	x8, [x29, #-16]
	str	x8, [sp, #32]                   ; 8-byte Folded Spill
	ldur	x0, [x29, #-24]
	bl	__ZNK3phy6matrixIfE4rowsEv
	str	x0, [sp, #24]                   ; 8-byte Folded Spill
	ldur	x0, [x29, #-24]
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	x1, [sp, #24]                   ; 8-byte Folded Reload
	mov	x2, x0
	ldr	x0, [sp, #32]                   ; 8-byte Folded Reload
	bl	__ZNK3phy6matrixIfE11compareSizeEmm
	mov	w8, #1
	sturb	w8, [x29, #-25]
	stur	wzr, [x29, #-32]
	b	LBB13_1
LBB13_1:                                ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB13_3 Depth 2
	ldr	x0, [sp, #32]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-32]
	str	x8, [sp, #16]                   ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4rowsEv
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB13_10
	b	LBB13_2
LBB13_2:                                ;   in Loop: Header=BB13_1 Depth=1
	stur	wzr, [x29, #-36]
	b	LBB13_3
LBB13_3:                                ;   Parent Loop BB13_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	x0, [sp, #32]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-36]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB13_8
	b	LBB13_4
LBB13_4:                                ;   in Loop: Header=BB13_3 Depth=2
	ldr	x8, [sp, #32]                   ; 8-byte Folded Reload
	ldur	x9, [x29, #-24]
	ldr	x9, [x9]
	ldursw	x10, [x29, #-32]
	ldr	x9, [x9, x10, lsl #3]
	ldursw	x10, [x29, #-36]
	ldr	s0, [x9, x10, lsl #2]
	ldr	x8, [x8]
	ldursw	x9, [x29, #-32]
	ldr	x8, [x8, x9, lsl #3]
	ldursw	x9, [x29, #-36]
	ldr	s1, [x8, x9, lsl #2]
	fcmp	s0, s1
	b.eq	LBB13_6
	b	LBB13_5
LBB13_5:
	mov	w8, #0
	and	w8, w8, #0x1
	and	w8, w8, #0x1
	sturb	w8, [x29, #-1]
	b	LBB13_11
LBB13_6:                                ;   in Loop: Header=BB13_3 Depth=2
	b	LBB13_7
LBB13_7:                                ;   in Loop: Header=BB13_3 Depth=2
	ldur	w8, [x29, #-36]
	add	w8, w8, #1
	stur	w8, [x29, #-36]
	b	LBB13_3
LBB13_8:                                ;   in Loop: Header=BB13_1 Depth=1
	b	LBB13_9
LBB13_9:                                ;   in Loop: Header=BB13_1 Depth=1
	ldur	w8, [x29, #-32]
	add	w8, w8, #1
	stur	w8, [x29, #-32]
	b	LBB13_1
LBB13_10:
	ldurb	w8, [x29, #-25]
	and	w8, w8, #0x1
	and	w8, w8, #0x1
	sturb	w8, [x29, #-1]
	b	LBB13_11
LBB13_11:
	ldurb	w8, [x29, #-1]
	and	w0, w8, #0x1
	ldp	x29, x30, [sp, #80]             ; 16-byte Folded Reload
	add	sp, sp, #96
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZNK3phy6matrixIfEneERKS1_     ; -- Begin function _ZNK3phy6matrixIfEneERKS1_
	.weak_definition	__ZNK3phy6matrixIfEneERKS1_
	.p2align	2
__ZNK3phy6matrixIfEneERKS1_:            ; @_ZNK3phy6matrixIfEneERKS1_
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #96
	stp	x29, x30, [sp, #80]             ; 16-byte Folded Spill
	add	x29, sp, #80
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-16]
	stur	x1, [x29, #-24]
	ldur	x8, [x29, #-16]
	str	x8, [sp, #32]                   ; 8-byte Folded Spill
	ldur	x0, [x29, #-24]
	bl	__ZNK3phy6matrixIfE4rowsEv
	str	x0, [sp, #24]                   ; 8-byte Folded Spill
	ldur	x0, [x29, #-24]
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	x1, [sp, #24]                   ; 8-byte Folded Reload
	mov	x2, x0
	ldr	x0, [sp, #32]                   ; 8-byte Folded Reload
	bl	__ZNK3phy6matrixIfE11compareSizeEmm
	mov	w8, #1
	sturb	w8, [x29, #-25]
	stur	wzr, [x29, #-32]
	b	LBB14_1
LBB14_1:                                ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB14_3 Depth 2
	ldr	x0, [sp, #32]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-32]
	str	x8, [sp, #16]                   ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4rowsEv
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB14_10
	b	LBB14_2
LBB14_2:                                ;   in Loop: Header=BB14_1 Depth=1
	stur	wzr, [x29, #-36]
	b	LBB14_3
LBB14_3:                                ;   Parent Loop BB14_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	x0, [sp, #32]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-36]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB14_8
	b	LBB14_4
LBB14_4:                                ;   in Loop: Header=BB14_3 Depth=2
	ldr	x8, [sp, #32]                   ; 8-byte Folded Reload
	ldur	x9, [x29, #-24]
	ldr	x9, [x9]
	ldursw	x10, [x29, #-32]
	ldr	x9, [x9, x10, lsl #3]
	ldursw	x10, [x29, #-36]
	ldr	s0, [x9, x10, lsl #2]
	ldr	x8, [x8]
	ldursw	x9, [x29, #-32]
	ldr	x8, [x8, x9, lsl #3]
	ldursw	x9, [x29, #-36]
	ldr	s1, [x8, x9, lsl #2]
	fcmp	s0, s1
	b.eq	LBB14_6
	b	LBB14_5
LBB14_5:
	ldurb	w8, [x29, #-25]
	and	w8, w8, #0x1
	and	w8, w8, #0x1
	sturb	w8, [x29, #-1]
	b	LBB14_11
LBB14_6:                                ;   in Loop: Header=BB14_3 Depth=2
	b	LBB14_7
LBB14_7:                                ;   in Loop: Header=BB14_3 Depth=2
	ldur	w8, [x29, #-36]
	add	w8, w8, #1
	stur	w8, [x29, #-36]
	b	LBB14_3
LBB14_8:                                ;   in Loop: Header=BB14_1 Depth=1
	b	LBB14_9
LBB14_9:                                ;   in Loop: Header=BB14_1 Depth=1
	ldur	w8, [x29, #-32]
	add	w8, w8, #1
	stur	w8, [x29, #-32]
	b	LBB14_1
LBB14_10:
	mov	w8, #0
	and	w8, w8, #0x1
	and	w8, w8, #0x1
	sturb	w8, [x29, #-1]
	b	LBB14_11
LBB14_11:
	ldurb	w8, [x29, #-1]
	and	w0, w8, #0x1
	ldp	x29, x30, [sp, #80]             ; 16-byte Folded Reload
	add	sp, sp, #96
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZNK3phy6matrixIfEplERKS1_     ; -- Begin function _ZNK3phy6matrixIfEplERKS1_
	.weak_definition	__ZNK3phy6matrixIfEplERKS1_
	.p2align	2
__ZNK3phy6matrixIfEplERKS1_:            ; @_ZNK3phy6matrixIfEplERKS1_
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #80
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x8, [sp, #32]                   ; 8-byte Folded Spill
	stur	x0, [x29, #-8]
	stur	x1, [x29, #-16]
	ldur	x0, [x29, #-8]
	str	x0, [sp, #16]                   ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4rowsEv
	mov	x1, x0
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	str	x1, [sp, #24]                   ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	x1, [sp, #24]                   ; 8-byte Folded Reload
	mov	x2, x0
	ldr	x0, [sp, #32]                   ; 8-byte Folded Reload
	mov	w3, #0
	bl	__ZN3phy6matrixIfEC1Emmi
	stur	wzr, [x29, #-20]
	b	LBB15_1
LBB15_1:                                ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB15_3 Depth 2
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-20]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4rowsEv
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB15_8
	b	LBB15_2
LBB15_2:                                ;   in Loop: Header=BB15_1 Depth=1
	stur	wzr, [x29, #-24]
	b	LBB15_3
LBB15_3:                                ;   Parent Loop BB15_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-24]
	str	x8, [sp]                        ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB15_6
	b	LBB15_4
LBB15_4:                                ;   in Loop: Header=BB15_3 Depth=2
	ldr	x8, [sp, #32]                   ; 8-byte Folded Reload
	ldr	x9, [sp, #16]                   ; 8-byte Folded Reload
	ldr	x9, [x9]
	ldursw	x10, [x29, #-20]
	ldr	x9, [x9, x10, lsl #3]
	ldursw	x10, [x29, #-24]
	ldr	s0, [x9, x10, lsl #2]
	ldur	x9, [x29, #-16]
	ldr	x9, [x9]
	ldursw	x10, [x29, #-20]
	ldr	x9, [x9, x10, lsl #3]
	ldursw	x10, [x29, #-24]
	ldr	s1, [x9, x10, lsl #2]
	fadd	s0, s0, s1
	ldr	x8, [x8]
	ldursw	x9, [x29, #-20]
	ldr	x8, [x8, x9, lsl #3]
	ldursw	x9, [x29, #-24]
	str	s0, [x8, x9, lsl #2]
	b	LBB15_5
LBB15_5:                                ;   in Loop: Header=BB15_3 Depth=2
	ldur	w8, [x29, #-24]
	add	w8, w8, #1
	stur	w8, [x29, #-24]
	b	LBB15_3
LBB15_6:                                ;   in Loop: Header=BB15_1 Depth=1
	b	LBB15_7
LBB15_7:                                ;   in Loop: Header=BB15_1 Depth=1
	ldur	w8, [x29, #-20]
	add	w8, w8, #1
	stur	w8, [x29, #-20]
	b	LBB15_1
LBB15_8:
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZNK3phy6matrixIfEmiERKS1_     ; -- Begin function _ZNK3phy6matrixIfEmiERKS1_
	.weak_definition	__ZNK3phy6matrixIfEmiERKS1_
	.p2align	2
__ZNK3phy6matrixIfEmiERKS1_:            ; @_ZNK3phy6matrixIfEmiERKS1_
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #80
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x8, [sp, #32]                   ; 8-byte Folded Spill
	stur	x0, [x29, #-8]
	stur	x1, [x29, #-16]
	ldur	x0, [x29, #-8]
	str	x0, [sp, #16]                   ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4rowsEv
	mov	x1, x0
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	str	x1, [sp, #24]                   ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	x1, [sp, #24]                   ; 8-byte Folded Reload
	mov	x2, x0
	ldr	x0, [sp, #32]                   ; 8-byte Folded Reload
	mov	w3, #0
	bl	__ZN3phy6matrixIfEC1Emmi
	stur	wzr, [x29, #-20]
	b	LBB16_1
LBB16_1:                                ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB16_3 Depth 2
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-20]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4rowsEv
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB16_8
	b	LBB16_2
LBB16_2:                                ;   in Loop: Header=BB16_1 Depth=1
	stur	wzr, [x29, #-24]
	b	LBB16_3
LBB16_3:                                ;   Parent Loop BB16_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-24]
	str	x8, [sp]                        ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB16_6
	b	LBB16_4
LBB16_4:                                ;   in Loop: Header=BB16_3 Depth=2
	ldr	x8, [sp, #32]                   ; 8-byte Folded Reload
	ldr	x9, [sp, #16]                   ; 8-byte Folded Reload
	ldr	x9, [x9]
	ldursw	x10, [x29, #-20]
	ldr	x9, [x9, x10, lsl #3]
	ldursw	x10, [x29, #-24]
	ldr	s0, [x9, x10, lsl #2]
	ldur	x9, [x29, #-16]
	ldr	x9, [x9]
	ldursw	x10, [x29, #-20]
	ldr	x9, [x9, x10, lsl #3]
	ldursw	x10, [x29, #-24]
	ldr	s1, [x9, x10, lsl #2]
	fsub	s0, s0, s1
	ldr	x8, [x8]
	ldursw	x9, [x29, #-20]
	ldr	x8, [x8, x9, lsl #3]
	ldursw	x9, [x29, #-24]
	str	s0, [x8, x9, lsl #2]
	b	LBB16_5
LBB16_5:                                ;   in Loop: Header=BB16_3 Depth=2
	ldur	w8, [x29, #-24]
	add	w8, w8, #1
	stur	w8, [x29, #-24]
	b	LBB16_3
LBB16_6:                                ;   in Loop: Header=BB16_1 Depth=1
	b	LBB16_7
LBB16_7:                                ;   in Loop: Header=BB16_1 Depth=1
	ldur	w8, [x29, #-20]
	add	w8, w8, #1
	stur	w8, [x29, #-20]
	b	LBB16_1
LBB16_8:
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZNK3phy6matrixIfEmlERKf       ; -- Begin function _ZNK3phy6matrixIfEmlERKf
	.weak_definition	__ZNK3phy6matrixIfEmlERKf
	.p2align	2
__ZNK3phy6matrixIfEmlERKf:              ; @_ZNK3phy6matrixIfEmlERKf
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #80
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x8, [sp, #32]                   ; 8-byte Folded Spill
	stur	x0, [x29, #-8]
	stur	x1, [x29, #-16]
	ldur	x0, [x29, #-8]
	str	x0, [sp, #16]                   ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4rowsEv
	mov	x1, x0
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	str	x1, [sp, #24]                   ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	x1, [sp, #24]                   ; 8-byte Folded Reload
	mov	x2, x0
	ldr	x0, [sp, #32]                   ; 8-byte Folded Reload
	mov	w3, #0
	bl	__ZN3phy6matrixIfEC1Emmi
	stur	wzr, [x29, #-20]
	b	LBB17_1
LBB17_1:                                ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB17_3 Depth 2
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-20]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4rowsEv
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB17_8
	b	LBB17_2
LBB17_2:                                ;   in Loop: Header=BB17_1 Depth=1
	stur	wzr, [x29, #-24]
	b	LBB17_3
LBB17_3:                                ;   Parent Loop BB17_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-24]
	str	x8, [sp]                        ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB17_6
	b	LBB17_4
LBB17_4:                                ;   in Loop: Header=BB17_3 Depth=2
	ldr	x8, [sp, #32]                   ; 8-byte Folded Reload
	ldr	x9, [sp, #16]                   ; 8-byte Folded Reload
	ldr	x9, [x9]
	ldursw	x10, [x29, #-20]
	ldr	x9, [x9, x10, lsl #3]
	ldursw	x10, [x29, #-24]
	ldr	s0, [x9, x10, lsl #2]
	ldur	x9, [x29, #-16]
	ldr	s1, [x9]
	fmul	s0, s0, s1
	ldr	x8, [x8]
	ldursw	x9, [x29, #-20]
	ldr	x8, [x8, x9, lsl #3]
	ldursw	x9, [x29, #-24]
	str	s0, [x8, x9, lsl #2]
	b	LBB17_5
LBB17_5:                                ;   in Loop: Header=BB17_3 Depth=2
	ldur	w8, [x29, #-24]
	add	w8, w8, #1
	stur	w8, [x29, #-24]
	b	LBB17_3
LBB17_6:                                ;   in Loop: Header=BB17_1 Depth=1
	b	LBB17_7
LBB17_7:                                ;   in Loop: Header=BB17_1 Depth=1
	ldur	w8, [x29, #-20]
	add	w8, w8, #1
	stur	w8, [x29, #-20]
	b	LBB17_1
LBB17_8:
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZNK3phy6matrixIfEdvERKf       ; -- Begin function _ZNK3phy6matrixIfEdvERKf
	.weak_definition	__ZNK3phy6matrixIfEdvERKf
	.p2align	2
__ZNK3phy6matrixIfEdvERKf:              ; @_ZNK3phy6matrixIfEdvERKf
Lfunc_begin1:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception1
; %bb.0:
	sub	sp, sp, #96
	stp	x29, x30, [sp, #80]             ; 16-byte Folded Spill
	add	x29, sp, #80
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x8, [sp, #24]                   ; 8-byte Folded Spill
	stur	x0, [x29, #-8]
	stur	x1, [x29, #-16]
	ldur	x8, [x29, #-8]
	str	x8, [sp, #32]                   ; 8-byte Folded Spill
	ldur	x8, [x29, #-16]
	ldr	s0, [x8]
	fcmp	s0, #0.0
	b.ne	LBB18_7
	b	LBB18_1
LBB18_1:
	mov	x0, #4
	bl	___cxa_allocate_exception
	mov	w8, #-1
	str	w8, [x0]
Ltmp9:
	adrp	x1, __ZTIi@GOTPAGE
	ldr	x1, [x1, __ZTIi@GOTPAGEOFF]
	mov	x2, #0
	bl	___cxa_throw
Ltmp10:
	b	LBB18_19
LBB18_2:
Ltmp11:
	mov	x8, x1
	stur	x0, [x29, #-24]
	stur	w8, [x29, #-28]
	b	LBB18_3
LBB18_3:
	ldur	w8, [x29, #-28]
	subs	w8, w8, #1
	b.ne	LBB18_18
	b	LBB18_4
LBB18_4:
	ldur	x0, [x29, #-24]
	bl	___cxa_begin_catch
	ldr	w8, [x0]
	str	w8, [sp, #40]
Ltmp12:
	adrp	x0, __ZNSt3__14coutE@GOTPAGE
	ldr	x0, [x0, __ZNSt3__14coutE@GOTPAGEOFF]
	adrp	x1, l_.str.19@PAGE
	add	x1, x1, l_.str.19@PAGEOFF
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
Ltmp13:
	b	LBB18_5
LBB18_5:
	bl	___cxa_end_catch
	b	LBB18_6
LBB18_6:
	ldp	x29, x30, [sp, #80]             ; 16-byte Folded Reload
	add	sp, sp, #96
	ret
LBB18_7:
	ldr	x0, [sp, #32]                   ; 8-byte Folded Reload
	bl	__ZNK3phy6matrixIfE4rowsEv
	mov	x1, x0
	ldr	x0, [sp, #32]                   ; 8-byte Folded Reload
	str	x1, [sp, #16]                   ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	x1, [sp, #16]                   ; 8-byte Folded Reload
	mov	x2, x0
	ldr	x0, [sp, #24]                   ; 8-byte Folded Reload
Ltmp7:
	mov	w3, #0
	bl	__ZN3phy6matrixIfEC1Emmi
Ltmp8:
	b	LBB18_8
LBB18_8:
	stur	wzr, [x29, #-32]
	b	LBB18_9
LBB18_9:                                ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB18_11 Depth 2
	ldr	x0, [sp, #32]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-32]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4rowsEv
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB18_16
	b	LBB18_10
LBB18_10:                               ;   in Loop: Header=BB18_9 Depth=1
	stur	wzr, [x29, #-36]
	b	LBB18_11
LBB18_11:                               ;   Parent Loop BB18_9 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	x0, [sp, #32]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-36]
	str	x8, [sp]                        ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB18_14
	b	LBB18_12
LBB18_12:                               ;   in Loop: Header=BB18_11 Depth=2
	ldr	x8, [sp, #24]                   ; 8-byte Folded Reload
	ldr	x9, [sp, #32]                   ; 8-byte Folded Reload
	ldr	x9, [x9]
	ldursw	x10, [x29, #-32]
	ldr	x9, [x9, x10, lsl #3]
	ldursw	x10, [x29, #-36]
	ldr	s0, [x9, x10, lsl #2]
	ldur	x9, [x29, #-16]
	ldr	s1, [x9]
	fdiv	s0, s0, s1
	ldr	x8, [x8]
	ldursw	x9, [x29, #-32]
	ldr	x8, [x8, x9, lsl #3]
	ldursw	x9, [x29, #-36]
	str	s0, [x8, x9, lsl #2]
	b	LBB18_13
LBB18_13:                               ;   in Loop: Header=BB18_11 Depth=2
	ldur	w8, [x29, #-36]
	add	w8, w8, #1
	stur	w8, [x29, #-36]
	b	LBB18_11
LBB18_14:                               ;   in Loop: Header=BB18_9 Depth=1
	b	LBB18_15
LBB18_15:                               ;   in Loop: Header=BB18_9 Depth=1
	ldur	w8, [x29, #-32]
	add	w8, w8, #1
	stur	w8, [x29, #-32]
	b	LBB18_9
LBB18_16:
	b	LBB18_6
LBB18_17:
Ltmp14:
	mov	x8, x1
	stur	x0, [x29, #-24]
	stur	w8, [x29, #-28]
	bl	___cxa_end_catch
	b	LBB18_18
LBB18_18:
	ldur	x0, [x29, #-24]
	bl	__Unwind_Resume
LBB18_19:
Lfunc_end1:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table18:
Lexception1:
	.byte	255                             ; @LPStart Encoding = omit
	.byte	155                             ; @TType Encoding = indirect pcrel sdata4
	.uleb128 Lttbase1-Lttbaseref1
Lttbaseref1:
	.byte	1                               ; Call site Encoding = uleb128
	.uleb128 Lcst_end1-Lcst_begin1
Lcst_begin1:
	.uleb128 Lfunc_begin1-Lfunc_begin1      ; >> Call Site 1 <<
	.uleb128 Ltmp9-Lfunc_begin1             ;   Call between Lfunc_begin1 and Ltmp9
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp9-Lfunc_begin1             ; >> Call Site 2 <<
	.uleb128 Ltmp10-Ltmp9                   ;   Call between Ltmp9 and Ltmp10
	.uleb128 Ltmp11-Lfunc_begin1            ;     jumps to Ltmp11
	.byte	1                               ;   On action: 1
	.uleb128 Ltmp10-Lfunc_begin1            ; >> Call Site 3 <<
	.uleb128 Ltmp12-Ltmp10                  ;   Call between Ltmp10 and Ltmp12
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp12-Lfunc_begin1            ; >> Call Site 4 <<
	.uleb128 Ltmp13-Ltmp12                  ;   Call between Ltmp12 and Ltmp13
	.uleb128 Ltmp14-Lfunc_begin1            ;     jumps to Ltmp14
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp13-Lfunc_begin1            ; >> Call Site 5 <<
	.uleb128 Ltmp7-Ltmp13                   ;   Call between Ltmp13 and Ltmp7
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp7-Lfunc_begin1             ; >> Call Site 6 <<
	.uleb128 Ltmp8-Ltmp7                    ;   Call between Ltmp7 and Ltmp8
	.uleb128 Ltmp11-Lfunc_begin1            ;     jumps to Ltmp11
	.byte	1                               ;   On action: 1
	.uleb128 Ltmp8-Lfunc_begin1             ; >> Call Site 7 <<
	.uleb128 Lfunc_end1-Ltmp8               ;   Call between Ltmp8 and Lfunc_end1
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
Lcst_end1:
	.byte	1                               ; >> Action Record 1 <<
                                        ;   Catch TypeInfo 1
	.byte	0                               ;   No further actions
	.p2align	2
                                        ; >> Catch TypeInfos <<
Ltmp15:                                 ; TypeInfo 1
	.long	__ZTIi@GOT-Ltmp15
Lttbase1:
	.p2align	2
                                        ; -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNK3phy6matrixIfEmlERKS1_     ; -- Begin function _ZNK3phy6matrixIfEmlERKS1_
	.weak_definition	__ZNK3phy6matrixIfEmlERKS1_
	.p2align	2
__ZNK3phy6matrixIfEmlERKS1_:            ; @_ZNK3phy6matrixIfEmlERKS1_
Lfunc_begin2:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception2
; %bb.0:
	sub	sp, sp, #128
	stp	x29, x30, [sp, #112]            ; 16-byte Folded Spill
	add	x29, sp, #112
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x8, [sp, #40]                   ; 8-byte Folded Spill
	stur	x0, [x29, #-8]
	stur	x1, [x29, #-16]
	ldur	x0, [x29, #-8]
	str	x0, [sp, #48]                   ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4colsEv
	str	x0, [sp, #56]                   ; 8-byte Folded Spill
	ldur	x0, [x29, #-16]
	bl	__ZNK3phy6matrixIfE4rowsEv
	mov	x8, x0
	ldr	x0, [sp, #56]                   ; 8-byte Folded Reload
	subs	x8, x0, x8
	b.eq	LBB19_7
	b	LBB19_1
LBB19_1:
	mov	x0, #4
	bl	___cxa_allocate_exception
	mov	w8, #-1
	str	w8, [x0]
Ltmp18:
	adrp	x1, __ZTIi@GOTPAGE
	ldr	x1, [x1, __ZTIi@GOTPAGEOFF]
	mov	x2, #0
	bl	___cxa_throw
Ltmp19:
	b	LBB19_23
LBB19_2:
Ltmp20:
	mov	x8, x1
	stur	x0, [x29, #-24]
	stur	w8, [x29, #-28]
	b	LBB19_3
LBB19_3:
	ldur	w8, [x29, #-28]
	subs	w8, w8, #1
	b.ne	LBB19_22
	b	LBB19_4
LBB19_4:
	ldur	x0, [x29, #-24]
	bl	___cxa_begin_catch
	ldr	w8, [x0]
	stur	w8, [x29, #-44]
Ltmp21:
	adrp	x0, __ZNSt3__14coutE@GOTPAGE
	ldr	x0, [x0, __ZNSt3__14coutE@GOTPAGEOFF]
	adrp	x1, l_.str.20@PAGE
	add	x1, x1, l_.str.20@PAGEOFF
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
Ltmp22:
	b	LBB19_5
LBB19_5:
	bl	___cxa_end_catch
	b	LBB19_6
LBB19_6:
	ldp	x29, x30, [sp, #112]            ; 16-byte Folded Reload
	add	sp, sp, #128
	ret
LBB19_7:
	ldr	x0, [sp, #48]                   ; 8-byte Folded Reload
	bl	__ZNK3phy6matrixIfE4rowsEv
	str	x0, [sp, #32]                   ; 8-byte Folded Spill
	ldur	x0, [x29, #-16]
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	x1, [sp, #32]                   ; 8-byte Folded Reload
	mov	x2, x0
	ldr	x0, [sp, #40]                   ; 8-byte Folded Reload
Ltmp16:
	mov	w3, #0
	bl	__ZN3phy6matrixIfEC1Emmi
Ltmp17:
	b	LBB19_8
LBB19_8:
	stur	wzr, [x29, #-32]
	b	LBB19_9
LBB19_9:                                ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB19_11 Depth 2
                                        ;       Child Loop BB19_13 Depth 3
	ldr	x0, [sp, #48]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-32]
	str	x8, [sp, #24]                   ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4rowsEv
	ldr	x8, [sp, #24]                   ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB19_20
	b	LBB19_10
LBB19_10:                               ;   in Loop: Header=BB19_9 Depth=1
	stur	wzr, [x29, #-36]
	b	LBB19_11
LBB19_11:                               ;   Parent Loop BB19_9 Depth=1
                                        ; =>  This Loop Header: Depth=2
                                        ;       Child Loop BB19_13 Depth 3
	ldursw	x8, [x29, #-36]
	str	x8, [sp, #16]                   ; 8-byte Folded Spill
	ldur	x0, [x29, #-16]
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB19_18
	b	LBB19_12
LBB19_12:                               ;   in Loop: Header=BB19_11 Depth=2
	stur	wzr, [x29, #-40]
	b	LBB19_13
LBB19_13:                               ;   Parent Loop BB19_9 Depth=1
                                        ;     Parent Loop BB19_11 Depth=2
                                        ; =>    This Inner Loop Header: Depth=3
	ldr	x0, [sp, #48]                   ; 8-byte Folded Reload
	ldursw	x8, [x29, #-40]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hs	LBB19_16
	b	LBB19_14
LBB19_14:                               ;   in Loop: Header=BB19_13 Depth=3
	ldr	x8, [sp, #40]                   ; 8-byte Folded Reload
	ldr	x9, [sp, #48]                   ; 8-byte Folded Reload
	ldr	x9, [x9]
	ldursw	x10, [x29, #-32]
	ldr	x9, [x9, x10, lsl #3]
	ldursw	x10, [x29, #-40]
	ldr	s0, [x9, x10, lsl #2]
	ldur	x9, [x29, #-16]
	ldr	x9, [x9]
	ldursw	x10, [x29, #-40]
	ldr	x9, [x9, x10, lsl #3]
	ldursw	x10, [x29, #-36]
	ldr	s1, [x9, x10, lsl #2]
	fmul	s1, s0, s1
	ldr	x8, [x8]
	ldursw	x9, [x29, #-32]
	ldr	x8, [x8, x9, lsl #3]
	ldursw	x9, [x29, #-36]
	add	x8, x8, x9, lsl #2
	ldr	s0, [x8]
	fadd	s0, s0, s1
	str	s0, [x8]
	b	LBB19_15
LBB19_15:                               ;   in Loop: Header=BB19_13 Depth=3
	ldur	w8, [x29, #-40]
	add	w8, w8, #1
	stur	w8, [x29, #-40]
	b	LBB19_13
LBB19_16:                               ;   in Loop: Header=BB19_11 Depth=2
	b	LBB19_17
LBB19_17:                               ;   in Loop: Header=BB19_11 Depth=2
	ldur	w8, [x29, #-36]
	add	w8, w8, #1
	stur	w8, [x29, #-36]
	b	LBB19_11
LBB19_18:                               ;   in Loop: Header=BB19_9 Depth=1
	b	LBB19_19
LBB19_19:                               ;   in Loop: Header=BB19_9 Depth=1
	ldur	w8, [x29, #-32]
	add	w8, w8, #1
	stur	w8, [x29, #-32]
	b	LBB19_9
LBB19_20:
	b	LBB19_6
LBB19_21:
Ltmp23:
	mov	x8, x1
	stur	x0, [x29, #-24]
	stur	w8, [x29, #-28]
	bl	___cxa_end_catch
	b	LBB19_22
LBB19_22:
	ldur	x0, [x29, #-24]
	bl	__Unwind_Resume
LBB19_23:
Lfunc_end2:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table19:
Lexception2:
	.byte	255                             ; @LPStart Encoding = omit
	.byte	155                             ; @TType Encoding = indirect pcrel sdata4
	.uleb128 Lttbase2-Lttbaseref2
Lttbaseref2:
	.byte	1                               ; Call site Encoding = uleb128
	.uleb128 Lcst_end2-Lcst_begin2
Lcst_begin2:
	.uleb128 Lfunc_begin2-Lfunc_begin2      ; >> Call Site 1 <<
	.uleb128 Ltmp18-Lfunc_begin2            ;   Call between Lfunc_begin2 and Ltmp18
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp18-Lfunc_begin2            ; >> Call Site 2 <<
	.uleb128 Ltmp19-Ltmp18                  ;   Call between Ltmp18 and Ltmp19
	.uleb128 Ltmp20-Lfunc_begin2            ;     jumps to Ltmp20
	.byte	1                               ;   On action: 1
	.uleb128 Ltmp19-Lfunc_begin2            ; >> Call Site 3 <<
	.uleb128 Ltmp21-Ltmp19                  ;   Call between Ltmp19 and Ltmp21
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp21-Lfunc_begin2            ; >> Call Site 4 <<
	.uleb128 Ltmp22-Ltmp21                  ;   Call between Ltmp21 and Ltmp22
	.uleb128 Ltmp23-Lfunc_begin2            ;     jumps to Ltmp23
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp22-Lfunc_begin2            ; >> Call Site 5 <<
	.uleb128 Ltmp16-Ltmp22                  ;   Call between Ltmp22 and Ltmp16
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp16-Lfunc_begin2            ; >> Call Site 6 <<
	.uleb128 Ltmp17-Ltmp16                  ;   Call between Ltmp16 and Ltmp17
	.uleb128 Ltmp20-Lfunc_begin2            ;     jumps to Ltmp20
	.byte	1                               ;   On action: 1
	.uleb128 Ltmp17-Lfunc_begin2            ; >> Call Site 7 <<
	.uleb128 Lfunc_end2-Ltmp17              ;   Call between Ltmp17 and Lfunc_end2
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
Lcst_end2:
	.byte	1                               ; >> Action Record 1 <<
                                        ;   Catch TypeInfo 1
	.byte	0                               ;   No further actions
	.p2align	2
                                        ; >> Catch TypeInfos <<
Ltmp24:                                 ; TypeInfo 1
	.long	__ZTIi@GOT-Ltmp24
Lttbase2:
	.p2align	2
                                        ; -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN3phy6matrixIiEC1Emmi        ; -- Begin function _ZN3phy6matrixIiEC1Emmi
	.weak_def_can_be_hidden	__ZN3phy6matrixIiEC1Emmi
	.p2align	2
__ZN3phy6matrixIiEC1Emmi:               ; @_ZN3phy6matrixIiEC1Emmi
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	x1, [x29, #-16]
	str	x2, [sp, #24]
	str	w3, [sp, #20]
	ldur	x0, [x29, #-8]
	str	x0, [sp, #8]                    ; 8-byte Folded Spill
	ldur	x1, [x29, #-16]
	ldr	x2, [sp, #24]
	ldr	w3, [sp, #20]
	bl	__ZN3phy6matrixIiEC2Emmi
	ldr	x0, [sp, #8]                    ; 8-byte Folded Reload
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZN3phy6matrixIiEclEmm         ; -- Begin function _ZN3phy6matrixIiEclEmm
	.weak_definition	__ZN3phy6matrixIiEclEmm
	.p2align	2
__ZN3phy6matrixIiEclEmm:                ; @_ZN3phy6matrixIiEclEmm
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	str	x1, [sp, #16]
	str	x2, [sp, #8]
	ldur	x8, [x29, #-8]
	str	x8, [sp]                        ; 8-byte Folded Spill
	adrp	x0, __ZNSt3__14coutE@GOTPAGE
	ldr	x0, [x0, __ZNSt3__14coutE@GOTPAGEOFF]
	adrp	x1, l_.str.21@PAGE
	add	x1, x1, l_.str.21@PAGEOFF
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	ldr	x8, [x8]
	ldr	x9, [sp, #16]
	ldr	x8, [x8, x9, lsl #3]
	ldr	x9, [sp, #8]
	add	x0, x8, x9, lsl #2
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEPFRS3_S4_E
__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEPFRS3_S4_E: ; @_ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEPFRS3_S4_E
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	str	x1, [sp]
	ldr	x0, [sp, #8]
	ldr	x8, [sp]
	blr	x8
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_ ; -- Begin function _ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
	.weak_definition	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
	.p2align	2
__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_: ; @_ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	ldr	x8, [sp, #8]
	str	x8, [sp]                        ; 8-byte Folded Spill
	ldr	x8, [sp, #8]
	ldr	x9, [x8]
	ldur	x9, [x9, #-24]
	add	x0, x8, x9
	mov	w1, #10
	bl	__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenEc
	mov	x8, x0
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	sxtb	w1, w8
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE3putEc
	ldr	x0, [sp, #8]
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE5flushEv
	ldr	x0, [sp, #8]
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZNK3phy6matrixIiEclEmm        ; -- Begin function _ZNK3phy6matrixIiEclEmm
	.weak_definition	__ZNK3phy6matrixIiEclEmm
	.p2align	2
__ZNK3phy6matrixIiEclEmm:               ; @_ZNK3phy6matrixIiEclEmm
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	str	x1, [sp, #16]
	str	x2, [sp, #8]
	ldur	x8, [x29, #-8]
	str	x8, [sp]                        ; 8-byte Folded Spill
	adrp	x0, __ZNSt3__14coutE@GOTPAGE
	ldr	x0, [x0, __ZNSt3__14coutE@GOTPAGEOFF]
	adrp	x1, l_.str.22@PAGE
	add	x1, x1, l_.str.22@PAGEOFF
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	ldr	x8, [x8]
	ldr	x9, [sp, #16]
	ldr	x8, [x8, x9, lsl #3]
	ldr	x9, [sp, #8]
	add	x0, x8, x9, lsl #2
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNSt3__18ios_base4setfEj
__ZNSt3__18ios_base4setfEj:             ; @_ZNSt3__18ios_base4setfEj
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	str	w1, [sp, #4]
	ldr	x9, [sp, #8]
	ldr	w8, [x9, #8]
	str	w8, [sp]
	ldr	w10, [sp, #4]
	ldr	w8, [x9, #8]
	orr	w8, w8, w10
	str	w8, [x9, #8]
	ldr	w0, [sp]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZN3phy6matrixIfEC2Emmi        ; -- Begin function _ZN3phy6matrixIfEC2Emmi
	.weak_def_can_be_hidden	__ZN3phy6matrixIfEC2Emmi
	.p2align	2
__ZN3phy6matrixIfEC2Emmi:               ; @_ZN3phy6matrixIfEC2Emmi
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #80
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-16]
	stur	x1, [x29, #-24]
	str	x2, [sp, #32]
	str	w3, [sp, #28]
	ldur	x9, [x29, #-16]
	str	x9, [sp]                        ; 8-byte Folded Spill
	mov	x8, x9
	stur	x8, [x29, #-8]
	ldur	x8, [x29, #-24]
	str	x8, [x9, #8]
	ldr	x8, [sp, #32]
	str	x8, [x9, #16]
	ldr	w8, [sp, #28]
	str	w8, [x9, #24]
	ldur	x8, [x29, #-24]
	mov	x10, #8
	umulh	x9, x8, x10
	mul	x8, x8, x10
	subs	x9, x9, #0
	csinv	x0, x8, xzr, eq
	bl	__Znam
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	str	x0, [x8]
	str	wzr, [sp, #24]
	b	LBB26_1
LBB26_1:                                ; =>This Inner Loop Header: Depth=1
	ldrsw	x8, [sp, #24]
	ldur	x9, [x29, #-24]
	subs	x8, x8, x9
	b.hs	LBB26_4
	b	LBB26_2
LBB26_2:                                ;   in Loop: Header=BB26_1 Depth=1
	ldr	x8, [sp, #32]
	mov	x10, #4
	umulh	x9, x8, x10
	mul	x8, x8, x10
	subs	x9, x9, #0
	csinv	x0, x8, xzr, eq
	bl	__Znam
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	ldr	x8, [x8]
	ldrsw	x9, [sp, #24]
	str	x0, [x8, x9, lsl #3]
	b	LBB26_3
LBB26_3:                                ;   in Loop: Header=BB26_1 Depth=1
	ldr	w8, [sp, #24]
	add	w8, w8, #1
	str	w8, [sp, #24]
	b	LBB26_1
LBB26_4:
	str	wzr, [sp, #20]
	str	wzr, [sp, #16]
	b	LBB26_5
LBB26_5:                                ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB26_7 Depth 2
	ldrsw	x8, [sp, #16]
	ldur	x9, [x29, #-24]
	subs	x8, x8, x9
	b.hs	LBB26_15
	b	LBB26_6
LBB26_6:                                ;   in Loop: Header=BB26_5 Depth=1
	str	wzr, [sp, #12]
	b	LBB26_7
LBB26_7:                                ;   Parent Loop BB26_5 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldrsw	x8, [sp, #12]
	ldr	x9, [sp, #32]
	subs	x8, x8, x9
	b.hs	LBB26_13
	b	LBB26_8
LBB26_8:                                ;   in Loop: Header=BB26_7 Depth=2
	ldr	w8, [sp, #28]
	cbnz	w8, LBB26_10
	b	LBB26_9
LBB26_9:                                ;   in Loop: Header=BB26_7 Depth=2
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	ldr	x8, [x8]
	ldrsw	x9, [sp, #16]
	ldr	x8, [x8, x9, lsl #3]
	ldrsw	x9, [sp, #12]
	movi	d0, #0000000000000000
	str	s0, [x8, x9, lsl #2]
	b	LBB26_11
LBB26_10:                               ;   in Loop: Header=BB26_7 Depth=2
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	ldr	s0, [sp, #20]
	fmov	w9, s0
	add	w9, w9, #1
	str	w9, [sp, #20]
	scvtf	s0, s0
	ldr	x8, [x8]
	ldrsw	x9, [sp, #16]
	ldr	x8, [x8, x9, lsl #3]
	ldrsw	x9, [sp, #12]
	str	s0, [x8, x9, lsl #2]
	b	LBB26_11
LBB26_11:                               ;   in Loop: Header=BB26_7 Depth=2
	b	LBB26_12
LBB26_12:                               ;   in Loop: Header=BB26_7 Depth=2
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	b	LBB26_7
LBB26_13:                               ;   in Loop: Header=BB26_5 Depth=1
	b	LBB26_14
LBB26_14:                               ;   in Loop: Header=BB26_5 Depth=1
	ldr	w8, [sp, #16]
	add	w8, w8, #1
	str	w8, [sp, #16]
	b	LBB26_5
LBB26_15:
	ldur	x0, [x29, #-8]
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m ; -- Begin function _ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	.weak_definition	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	.p2align	2
__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m: ; @_ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
Lfunc_begin3:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception3
; %bb.0:
	sub	sp, sp, #160
	stp	x29, x30, [sp, #144]            ; 16-byte Folded Spill
	add	x29, sp, #144
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	x1, [x29, #-16]
	stur	x2, [x29, #-24]
	ldur	x1, [x29, #-8]
Ltmp26:
	sub	x0, x29, #40
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_
Ltmp27:
	b	LBB27_1
LBB27_1:
Ltmp28:
	sub	x0, x29, #40
	bl	__ZNKSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentrycvbEv
	str	w0, [sp, #68]                   ; 4-byte Folded Spill
Ltmp29:
	b	LBB27_2
LBB27_2:
	ldr	w8, [sp, #68]                   ; 4-byte Folded Reload
	tbz	w8, #0, LBB27_15
	b	LBB27_3
LBB27_3:
	ldur	x1, [x29, #-8]
	add	x0, sp, #72
	bl	__ZNSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEEC1ERNS_13basic_ostreamIcS2_EE
	ldur	x8, [x29, #-16]
	str	x8, [sp, #56]                   ; 8-byte Folded Spill
	ldur	x8, [x29, #-8]
	ldr	x9, [x8]
	ldur	x9, [x9, #-24]
	add	x0, x8, x9
Ltmp30:
	bl	__ZNKSt3__18ios_base5flagsEv
	str	w0, [sp, #64]                   ; 4-byte Folded Spill
Ltmp31:
	b	LBB27_4
LBB27_4:
	ldr	w8, [sp, #64]                   ; 4-byte Folded Reload
	mov	w9, #176
	and	w8, w8, w9
	subs	w8, w8, #32
	b.ne	LBB27_6
	b	LBB27_5
LBB27_5:
	ldur	x8, [x29, #-16]
	ldur	x9, [x29, #-24]
	add	x8, x8, x9
	str	x8, [sp, #48]                   ; 8-byte Folded Spill
	b	LBB27_7
LBB27_6:
	ldur	x8, [x29, #-16]
	str	x8, [sp, #48]                   ; 8-byte Folded Spill
	b	LBB27_7
LBB27_7:
	ldr	x8, [sp, #48]                   ; 8-byte Folded Reload
	str	x8, [sp, #16]                   ; 8-byte Folded Spill
	ldur	x8, [x29, #-16]
	ldur	x9, [x29, #-24]
	add	x8, x8, x9
	str	x8, [sp, #24]                   ; 8-byte Folded Spill
	ldur	x8, [x29, #-8]
	ldr	x9, [x8]
	ldur	x9, [x9, #-24]
	add	x8, x8, x9
	str	x8, [sp, #32]                   ; 8-byte Folded Spill
	ldur	x8, [x29, #-8]
	ldr	x9, [x8]
	ldur	x9, [x9, #-24]
	add	x0, x8, x9
Ltmp32:
	bl	__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE4fillEv
	str	w0, [sp, #44]                   ; 4-byte Folded Spill
Ltmp33:
	b	LBB27_8
LBB27_8:
	ldr	w8, [sp, #44]                   ; 4-byte Folded Reload
	ldr	x4, [sp, #32]                   ; 8-byte Folded Reload
	ldr	x3, [sp, #24]                   ; 8-byte Folded Reload
	ldr	x2, [sp, #16]                   ; 8-byte Folded Reload
	ldr	x1, [sp, #56]                   ; 8-byte Folded Reload
	ldr	x0, [sp, #72]
Ltmp34:
	sxtb	w5, w8
	bl	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
	str	x0, [sp, #8]                    ; 8-byte Folded Spill
Ltmp35:
	b	LBB27_9
LBB27_9:
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	sub	x0, x29, #64
	stur	x8, [x29, #-64]
	bl	__ZNKSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEE6failedEv
	tbz	w0, #0, LBB27_14
	b	LBB27_10
LBB27_10:
	ldur	x8, [x29, #-8]
	ldr	x9, [x8]
	ldur	x9, [x9, #-24]
	add	x0, x8, x9
Ltmp36:
	mov	w1, #5
	bl	__ZNSt3__19basic_iosIcNS_11char_traitsIcEEE8setstateEj
Ltmp37:
	b	LBB27_11
LBB27_11:
	b	LBB27_14
LBB27_12:
Ltmp43:
	mov	x8, x1
	stur	x0, [x29, #-48]
	stur	w8, [x29, #-52]
	b	LBB27_18
LBB27_13:
Ltmp38:
	mov	x8, x1
	stur	x0, [x29, #-48]
	stur	w8, [x29, #-52]
Ltmp39:
	sub	x0, x29, #40
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev
Ltmp40:
	b	LBB27_17
LBB27_14:
	b	LBB27_15
LBB27_15:
Ltmp41:
	sub	x0, x29, #40
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev
Ltmp42:
	b	LBB27_16
LBB27_16:
	b	LBB27_20
LBB27_17:
	b	LBB27_18
LBB27_18:
	ldur	x0, [x29, #-48]
	bl	___cxa_begin_catch
	ldur	x8, [x29, #-8]
	ldr	x9, [x8]
	ldur	x9, [x9, #-24]
	add	x0, x8, x9
Ltmp44:
	bl	__ZNSt3__18ios_base33__set_badbit_and_consider_rethrowEv
Ltmp45:
	b	LBB27_19
LBB27_19:
	bl	___cxa_end_catch
	b	LBB27_20
LBB27_20:
	ldur	x0, [x29, #-8]
	ldp	x29, x30, [sp, #144]            ; 16-byte Folded Reload
	add	sp, sp, #160
	ret
LBB27_21:
Ltmp46:
	mov	x8, x1
	stur	x0, [x29, #-48]
	stur	w8, [x29, #-52]
Ltmp47:
	bl	___cxa_end_catch
Ltmp48:
	b	LBB27_22
LBB27_22:
	b	LBB27_23
LBB27_23:
	ldur	x0, [x29, #-48]
	bl	__Unwind_Resume
LBB27_24:
Ltmp49:
	bl	___clang_call_terminate
Lfunc_end3:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table27:
Lexception3:
	.byte	255                             ; @LPStart Encoding = omit
	.byte	155                             ; @TType Encoding = indirect pcrel sdata4
	.uleb128 Lttbase3-Lttbaseref3
Lttbaseref3:
	.byte	1                               ; Call site Encoding = uleb128
	.uleb128 Lcst_end3-Lcst_begin3
Lcst_begin3:
	.uleb128 Ltmp26-Lfunc_begin3            ; >> Call Site 1 <<
	.uleb128 Ltmp27-Ltmp26                  ;   Call between Ltmp26 and Ltmp27
	.uleb128 Ltmp43-Lfunc_begin3            ;     jumps to Ltmp43
	.byte	1                               ;   On action: 1
	.uleb128 Ltmp28-Lfunc_begin3            ; >> Call Site 2 <<
	.uleb128 Ltmp37-Ltmp28                  ;   Call between Ltmp28 and Ltmp37
	.uleb128 Ltmp38-Lfunc_begin3            ;     jumps to Ltmp38
	.byte	1                               ;   On action: 1
	.uleb128 Ltmp39-Lfunc_begin3            ; >> Call Site 3 <<
	.uleb128 Ltmp40-Ltmp39                  ;   Call between Ltmp39 and Ltmp40
	.uleb128 Ltmp49-Lfunc_begin3            ;     jumps to Ltmp49
	.byte	1                               ;   On action: 1
	.uleb128 Ltmp41-Lfunc_begin3            ; >> Call Site 4 <<
	.uleb128 Ltmp42-Ltmp41                  ;   Call between Ltmp41 and Ltmp42
	.uleb128 Ltmp43-Lfunc_begin3            ;     jumps to Ltmp43
	.byte	1                               ;   On action: 1
	.uleb128 Ltmp42-Lfunc_begin3            ; >> Call Site 5 <<
	.uleb128 Ltmp44-Ltmp42                  ;   Call between Ltmp42 and Ltmp44
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp44-Lfunc_begin3            ; >> Call Site 6 <<
	.uleb128 Ltmp45-Ltmp44                  ;   Call between Ltmp44 and Ltmp45
	.uleb128 Ltmp46-Lfunc_begin3            ;     jumps to Ltmp46
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp45-Lfunc_begin3            ; >> Call Site 7 <<
	.uleb128 Ltmp47-Ltmp45                  ;   Call between Ltmp45 and Ltmp47
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp47-Lfunc_begin3            ; >> Call Site 8 <<
	.uleb128 Ltmp48-Ltmp47                  ;   Call between Ltmp47 and Ltmp48
	.uleb128 Ltmp49-Lfunc_begin3            ;     jumps to Ltmp49
	.byte	1                               ;   On action: 1
	.uleb128 Ltmp48-Lfunc_begin3            ; >> Call Site 9 <<
	.uleb128 Lfunc_end3-Ltmp48              ;   Call between Ltmp48 and Lfunc_end3
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
Lcst_end3:
	.byte	1                               ; >> Action Record 1 <<
                                        ;   Catch TypeInfo 1
	.byte	0                               ;   No further actions
	.p2align	2
                                        ; >> Catch TypeInfos <<
	.long	0                               ; TypeInfo 1
Lttbase3:
	.p2align	2
                                        ; -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__111char_traitsIcE6lengthEPKc ; -- Begin function _ZNSt3__111char_traitsIcE6lengthEPKc
	.weak_definition	__ZNSt3__111char_traitsIcE6lengthEPKc
	.p2align	2
__ZNSt3__111char_traitsIcE6lengthEPKc:  ; @_ZNSt3__111char_traitsIcE6lengthEPKc
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	bl	_strlen
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNKSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentrycvbEv
__ZNKSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentrycvbEv: ; @_ZNKSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentrycvbEv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	ldr	x8, [sp, #8]
	ldrb	w8, [x8]
	and	w0, w8, #0x1
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.private_extern	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_ ; -- Begin function _ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
	.globl	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
	.weak_definition	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
	.p2align	2
__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_: ; @_ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
Lfunc_begin4:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception4
; %bb.0:
	sub	sp, sp, #224
	stp	x29, x30, [sp, #208]            ; 16-byte Folded Spill
	add	x29, sp, #208
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-16]
	stur	x1, [x29, #-24]
	stur	x2, [x29, #-32]
	stur	x3, [x29, #-40]
	stur	x4, [x29, #-48]
	sturb	w5, [x29, #-49]
	ldur	x8, [x29, #-16]
	str	x8, [sp, #40]                   ; 8-byte Folded Spill
	bl	__ZNSt3__1L15__get_nullptr_tEv
	mov	x8, x0
	sub	x0, x29, #64
	stur	x8, [x29, #-64]
	bl	__ZNKSt3__19nullptr_tcvPT_INS_15basic_streambufIcNS_11char_traitsIcEEEEEEv
	ldr	x8, [sp, #40]                   ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.ne	LBB30_2
	b	LBB30_1
LBB30_1:
	ldur	x8, [x29, #-16]
	stur	x8, [x29, #-8]
	b	LBB30_26
LBB30_2:
	ldur	x8, [x29, #-40]
	ldur	x9, [x29, #-24]
	subs	x8, x8, x9
	stur	x8, [x29, #-72]
	ldur	x0, [x29, #-48]
	bl	__ZNKSt3__18ios_base5widthEv
	stur	x0, [x29, #-80]
	ldur	x8, [x29, #-80]
	ldur	x9, [x29, #-72]
	subs	x8, x8, x9
	b.le	LBB30_4
	b	LBB30_3
LBB30_3:
	ldur	x9, [x29, #-72]
	ldur	x8, [x29, #-80]
	subs	x8, x8, x9
	stur	x8, [x29, #-80]
	b	LBB30_5
LBB30_4:
	stur	xzr, [x29, #-80]
	b	LBB30_5
LBB30_5:
	ldur	x8, [x29, #-32]
	ldur	x9, [x29, #-24]
	subs	x8, x8, x9
	stur	x8, [x29, #-88]
	ldur	x8, [x29, #-88]
	subs	x8, x8, #0
	b.le	LBB30_9
	b	LBB30_6
LBB30_6:
	ldur	x0, [x29, #-16]
	ldur	x1, [x29, #-24]
	ldur	x2, [x29, #-88]
	bl	__ZNSt3__115basic_streambufIcNS_11char_traitsIcEEE5sputnEPKcl
	ldur	x8, [x29, #-88]
	subs	x8, x0, x8
	b.eq	LBB30_8
	b	LBB30_7
LBB30_7:
	bl	__ZNSt3__1L15__get_nullptr_tEv
	mov	x8, x0
	sub	x0, x29, #96
	stur	x8, [x29, #-96]
	bl	__ZNKSt3__19nullptr_tcvPT_INS_15basic_streambufIcNS_11char_traitsIcEEEEEEv
	stur	x0, [x29, #-16]
	ldur	x8, [x29, #-16]
	stur	x8, [x29, #-8]
	b	LBB30_26
LBB30_8:
	b	LBB30_9
LBB30_9:
	ldur	x8, [x29, #-80]
	subs	x8, x8, #0
	b.le	LBB30_21
	b	LBB30_10
LBB30_10:
	ldur	x1, [x29, #-80]
	ldursb	w2, [x29, #-49]
	add	x0, sp, #88
	str	x0, [sp, #16]                   ; 8-byte Folded Spill
	bl	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1Emc
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	ldur	x8, [x29, #-16]
	str	x8, [sp, #24]                   ; 8-byte Folded Spill
	bl	__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4dataEv
	mov	x1, x0
	ldr	x0, [sp, #24]                   ; 8-byte Folded Reload
	ldur	x2, [x29, #-80]
Ltmp51:
	bl	__ZNSt3__115basic_streambufIcNS_11char_traitsIcEEE5sputnEPKcl
	str	x0, [sp, #32]                   ; 8-byte Folded Spill
Ltmp52:
	b	LBB30_11
LBB30_11:
	ldr	x8, [sp, #32]                   ; 8-byte Folded Reload
	ldur	x9, [x29, #-80]
	subs	x8, x8, x9
	b.eq	LBB30_16
	b	LBB30_12
LBB30_12:
Ltmp53:
	bl	__ZNSt3__1L15__get_nullptr_tEv
	str	x0, [sp, #8]                    ; 8-byte Folded Spill
Ltmp54:
	b	LBB30_13
LBB30_13:
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	add	x0, sp, #64
	str	x8, [sp, #64]
Ltmp55:
	bl	__ZNKSt3__19nullptr_tcvPT_INS_15basic_streambufIcNS_11char_traitsIcEEEEEEv
	str	x0, [sp]                        ; 8-byte Folded Spill
Ltmp56:
	b	LBB30_14
LBB30_14:
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	stur	x8, [x29, #-16]
	ldur	x8, [x29, #-16]
	stur	x8, [x29, #-8]
	mov	w8, #1
	str	w8, [sp, #60]
	b	LBB30_17
LBB30_15:
Ltmp57:
	mov	x8, x1
	str	x0, [sp, #80]
	str	w8, [sp, #76]
Ltmp58:
	add	x0, sp, #88
	bl	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev
Ltmp59:
	b	LBB30_20
LBB30_16:
	str	wzr, [sp, #60]
	b	LBB30_17
LBB30_17:
	add	x0, sp, #88
	bl	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev
	ldr	w8, [sp, #60]
	cbz	w8, LBB30_19
	b	LBB30_18
LBB30_18:
	b	LBB30_26
LBB30_19:
	b	LBB30_21
LBB30_20:
	b	LBB30_27
LBB30_21:
	ldur	x8, [x29, #-40]
	ldur	x9, [x29, #-32]
	subs	x8, x8, x9
	stur	x8, [x29, #-88]
	ldur	x8, [x29, #-88]
	subs	x8, x8, #0
	b.le	LBB30_25
	b	LBB30_22
LBB30_22:
	ldur	x0, [x29, #-16]
	ldur	x1, [x29, #-32]
	ldur	x2, [x29, #-88]
	bl	__ZNSt3__115basic_streambufIcNS_11char_traitsIcEEE5sputnEPKcl
	ldur	x8, [x29, #-88]
	subs	x8, x0, x8
	b.eq	LBB30_24
	b	LBB30_23
LBB30_23:
	bl	__ZNSt3__1L15__get_nullptr_tEv
	mov	x8, x0
	add	x0, sp, #48
	str	x8, [sp, #48]
	bl	__ZNKSt3__19nullptr_tcvPT_INS_15basic_streambufIcNS_11char_traitsIcEEEEEEv
	stur	x0, [x29, #-16]
	ldur	x8, [x29, #-16]
	stur	x8, [x29, #-8]
	b	LBB30_26
LBB30_24:
	b	LBB30_25
LBB30_25:
	ldur	x0, [x29, #-48]
	mov	x1, #0
	bl	__ZNSt3__18ios_base5widthEl
	ldur	x8, [x29, #-16]
	stur	x8, [x29, #-8]
	b	LBB30_26
LBB30_26:
	ldur	x0, [x29, #-8]
	ldp	x29, x30, [sp, #208]            ; 16-byte Folded Reload
	add	sp, sp, #224
	ret
LBB30_27:
	ldr	x0, [sp, #80]
	bl	__Unwind_Resume
LBB30_28:
Ltmp60:
	bl	___clang_call_terminate
; %bb.29:
Lfunc_end4:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table30:
Lexception4:
	.byte	255                             ; @LPStart Encoding = omit
	.byte	155                             ; @TType Encoding = indirect pcrel sdata4
	.uleb128 Lttbase4-Lttbaseref4
Lttbaseref4:
	.byte	1                               ; Call site Encoding = uleb128
	.uleb128 Lcst_end4-Lcst_begin4
Lcst_begin4:
	.uleb128 Lfunc_begin4-Lfunc_begin4      ; >> Call Site 1 <<
	.uleb128 Ltmp51-Lfunc_begin4            ;   Call between Lfunc_begin4 and Ltmp51
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp51-Lfunc_begin4            ; >> Call Site 2 <<
	.uleb128 Ltmp56-Ltmp51                  ;   Call between Ltmp51 and Ltmp56
	.uleb128 Ltmp57-Lfunc_begin4            ;     jumps to Ltmp57
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp58-Lfunc_begin4            ; >> Call Site 3 <<
	.uleb128 Ltmp59-Ltmp58                  ;   Call between Ltmp58 and Ltmp59
	.uleb128 Ltmp60-Lfunc_begin4            ;     jumps to Ltmp60
	.byte	1                               ;   On action: 1
	.uleb128 Ltmp59-Lfunc_begin4            ; >> Call Site 4 <<
	.uleb128 Lfunc_end4-Ltmp59              ;   Call between Ltmp59 and Lfunc_end4
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
Lcst_end4:
	.byte	1                               ; >> Action Record 1 <<
                                        ;   Catch TypeInfo 1
	.byte	0                               ;   No further actions
	.p2align	2
                                        ; >> Catch TypeInfos <<
	.long	0                               ; TypeInfo 1
Lttbase4:
	.p2align	2
                                        ; -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.p2align	2                               ; -- Begin function _ZNSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEEC1ERNS_13basic_ostreamIcS2_EE
__ZNSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEEC1ERNS_13basic_ostreamIcS2_EE: ; @_ZNSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEEC1ERNS_13basic_ostreamIcS2_EE
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	str	x1, [sp, #16]
	ldur	x0, [x29, #-8]
	str	x0, [sp, #8]                    ; 8-byte Folded Spill
	ldr	x1, [sp, #16]
	bl	__ZNSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEEC2ERNS_13basic_ostreamIcS2_EE
	ldr	x0, [sp, #8]                    ; 8-byte Folded Reload
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNKSt3__18ios_base5flagsEv
__ZNKSt3__18ios_base5flagsEv:           ; @_ZNKSt3__18ios_base5flagsEv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	ldr	x8, [sp, #8]
	ldr	w0, [x8, #8]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE4fillEv
__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE4fillEv: ; @_ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE4fillEv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	ldr	x8, [sp, #8]
	str	x8, [sp]                        ; 8-byte Folded Spill
	bl	__ZNSt3__111char_traitsIcE3eofEv
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	ldr	w1, [x8, #144]
	bl	__ZNSt3__111char_traitsIcE11eq_int_typeEii
	tbz	w0, #0, LBB33_2
	b	LBB33_1
LBB33_1:
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	mov	w1, #32
	bl	__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenEc
	ldr	x9, [sp]                        ; 8-byte Folded Reload
	sxtb	w8, w0
	str	w8, [x9, #144]
	b	LBB33_2
LBB33_2:
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	ldr	w8, [x8, #144]
	sxtb	w0, w8
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNKSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEE6failedEv
__ZNKSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEE6failedEv: ; @_ZNKSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEE6failedEv
Lfunc_begin5:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception5
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	ldur	x8, [x29, #-8]
	ldr	x8, [x8]
	str	x8, [sp]                        ; 8-byte Folded Spill
Ltmp62:
	bl	__ZNSt3__1L15__get_nullptr_tEv
	str	x0, [sp, #8]                    ; 8-byte Folded Spill
Ltmp63:
	b	LBB34_1
LBB34_1:
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	sub	x0, x29, #16
	stur	x8, [x29, #-16]
	bl	__ZNKSt3__19nullptr_tcvPT_INS_15basic_streambufIcNS_11char_traitsIcEEEEEEv
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	subs	x8, x8, x0
	cset	w8, eq
	and	w0, w8, #0x1
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
LBB34_2:
Ltmp64:
	mov	x8, x1
	str	x0, [sp, #24]
	str	w8, [sp, #20]
	b	LBB34_3
LBB34_3:
	ldr	x0, [sp, #24]
	bl	___cxa_call_unexpected
Lfunc_end5:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table34:
Lexception5:
	.byte	255                             ; @LPStart Encoding = omit
	.byte	155                             ; @TType Encoding = indirect pcrel sdata4
	.uleb128 Lttbase5-Lttbaseref5
Lttbaseref5:
	.byte	1                               ; Call site Encoding = uleb128
	.uleb128 Lcst_end5-Lcst_begin5
Lcst_begin5:
	.uleb128 Ltmp62-Lfunc_begin5            ; >> Call Site 1 <<
	.uleb128 Ltmp63-Ltmp62                  ;   Call between Ltmp62 and Ltmp63
	.uleb128 Ltmp64-Lfunc_begin5            ;     jumps to Ltmp64
	.byte	1                               ;   On action: 1
	.uleb128 Ltmp63-Lfunc_begin5            ; >> Call Site 2 <<
	.uleb128 Lfunc_end5-Ltmp63              ;   Call between Ltmp63 and Lfunc_end5
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
Lcst_end5:
	.byte	127                             ; >> Action Record 1 <<
                                        ;   Filter TypeInfo -1
	.byte	0                               ;   No further actions
	.p2align	2
Lttbase5:
                                        ; >> Filter TypeInfos <<
	.byte	0
	.p2align	2
                                        ; -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.p2align	2                               ; -- Begin function _ZNSt3__19basic_iosIcNS_11char_traitsIcEEE8setstateEj
__ZNSt3__19basic_iosIcNS_11char_traitsIcEEE8setstateEj: ; @_ZNSt3__19basic_iosIcNS_11char_traitsIcEEE8setstateEj
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	str	w1, [sp, #4]
	ldr	x0, [sp, #8]
	ldr	w1, [sp, #4]
	bl	__ZNSt3__18ios_base8setstateEj
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.private_extern	___clang_call_terminate ; -- Begin function __clang_call_terminate
	.globl	___clang_call_terminate
	.weak_definition	___clang_call_terminate
	.p2align	2
___clang_call_terminate:                ; @__clang_call_terminate
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	bl	___cxa_begin_catch
	bl	__ZSt9terminatev
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNSt3__1L15__get_nullptr_tEv
__ZNSt3__1L15__get_nullptr_tEv:         ; @_ZNSt3__1L15__get_nullptr_tEv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	add	x0, sp, #8
	mov	x1, #-1
	bl	__ZNSt3__19nullptr_tC1EMNS0_5__natEi
	ldr	x0, [sp, #8]
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNKSt3__19nullptr_tcvPT_INS_15basic_streambufIcNS_11char_traitsIcEEEEEEv
__ZNKSt3__19nullptr_tcvPT_INS_15basic_streambufIcNS_11char_traitsIcEEEEEEv: ; @_ZNKSt3__19nullptr_tcvPT_INS_15basic_streambufIcNS_11char_traitsIcEEEEEEv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	mov	x0, #0
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNKSt3__18ios_base5widthEv
__ZNKSt3__18ios_base5widthEv:           ; @_ZNKSt3__18ios_base5widthEv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	ldr	x8, [sp, #8]
	ldr	x0, [x8, #24]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNSt3__115basic_streambufIcNS_11char_traitsIcEEE5sputnEPKcl
__ZNSt3__115basic_streambufIcNS_11char_traitsIcEEE5sputnEPKcl: ; @_ZNSt3__115basic_streambufIcNS_11char_traitsIcEEE5sputnEPKcl
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	str	x1, [sp, #16]
	str	x2, [sp, #8]
	ldur	x0, [x29, #-8]
	ldr	x1, [sp, #16]
	ldr	x2, [sp, #8]
	ldr	x8, [x0]
	ldr	x8, [x8, #96]
	blr	x8
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1Emc
__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1Emc: ; @_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1Emc
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	str	x1, [sp, #16]
	strb	w2, [sp, #15]
	ldur	x0, [x29, #-8]
	str	x0, [sp]                        ; 8-byte Folded Spill
	ldr	x1, [sp, #16]
	ldrsb	w2, [sp, #15]
	bl	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2Emc
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4dataEv
__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4dataEv: ; @_ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4dataEv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	bl	__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE13__get_pointerEv
	bl	__ZNSt3__1L12__to_addressIKcEEPT_S3_
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNSt3__18ios_base5widthEl
__ZNSt3__18ios_base5widthEl:            ; @_ZNSt3__18ios_base5widthEl
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	str	x0, [sp, #24]
	str	x1, [sp, #16]
	ldr	x9, [sp, #24]
	ldr	x8, [x9, #24]
	str	x8, [sp, #8]
	ldr	x8, [sp, #16]
	str	x8, [x9, #24]
	ldr	x0, [sp, #8]
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNSt3__19nullptr_tC1EMNS0_5__natEi
__ZNSt3__19nullptr_tC1EMNS0_5__natEi:   ; @_ZNSt3__19nullptr_tC1EMNS0_5__natEi
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	str	x1, [sp, #16]
	ldur	x0, [x29, #-8]
	str	x0, [sp, #8]                    ; 8-byte Folded Spill
	ldr	x1, [sp, #16]
	bl	__ZNSt3__19nullptr_tC2EMNS0_5__natEi
	ldr	x0, [sp, #8]                    ; 8-byte Folded Reload
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNSt3__19nullptr_tC2EMNS0_5__natEi
__ZNSt3__19nullptr_tC2EMNS0_5__natEi:   ; @_ZNSt3__19nullptr_tC2EMNS0_5__natEi
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	str	x1, [sp]
	ldr	x0, [sp, #8]
                                        ; kill: def $x8 killed $xzr
	str	xzr, [x0]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2Emc
__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2Emc: ; @_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2Emc
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	str	x1, [sp, #16]
	strb	w2, [sp, #15]
	ldur	x0, [x29, #-8]
	str	x0, [sp]                        ; 8-byte Folded Spill
	add	x1, sp, #14
	add	x2, sp, #13
	bl	__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_EC1INS_18__default_init_tagESA_EEOT_OT0_
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	ldr	x1, [sp, #16]
	ldrsb	w2, [sp, #15]
	bl	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEmc
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_EC1INS_18__default_init_tagESA_EEOT_OT0_
__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_EC1INS_18__default_init_tagESA_EEOT_OT0_: ; @_ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_EC1INS_18__default_init_tagESA_EEOT_OT0_
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	str	x1, [sp, #16]
	str	x2, [sp, #8]
	ldur	x0, [x29, #-8]
	str	x0, [sp]                        ; 8-byte Folded Spill
	ldr	x1, [sp, #16]
	ldr	x2, [sp, #8]
	bl	__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_EC2INS_18__default_init_tagESA_EEOT_OT0_
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_EC2INS_18__default_init_tagESA_EEOT_OT0_
__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_EC2INS_18__default_init_tagESA_EEOT_OT0_: ; @_ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_EC2INS_18__default_init_tagESA_EEOT_OT0_
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	x1, [x29, #-16]
	str	x2, [sp, #24]
	ldur	x8, [x29, #-8]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	ldur	x0, [x29, #-16]
	bl	__ZNSt3__1L7forwardINS_18__default_init_tagEEEOT_RNS_16remove_referenceIS2_E4typeE
	ldr	x0, [sp, #8]                    ; 8-byte Folded Reload
	bl	__ZNSt3__122__compressed_pair_elemINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repELi0ELb0EEC2ENS_18__default_init_tagE
	ldr	x0, [sp, #24]
	bl	__ZNSt3__1L7forwardINS_18__default_init_tagEEEOT_RNS_16remove_referenceIS2_E4typeE
	ldr	x0, [sp, #8]                    ; 8-byte Folded Reload
	bl	__ZNSt3__122__compressed_pair_elemINS_9allocatorIcEELi1ELb1EEC2ENS_18__default_init_tagE
	ldr	x0, [sp, #8]                    ; 8-byte Folded Reload
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNSt3__1L7forwardINS_18__default_init_tagEEEOT_RNS_16remove_referenceIS2_E4typeE
__ZNSt3__1L7forwardINS_18__default_init_tagEEEOT_RNS_16remove_referenceIS2_E4typeE: ; @_ZNSt3__1L7forwardINS_18__default_init_tagEEEOT_RNS_16remove_referenceIS2_E4typeE
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNSt3__122__compressed_pair_elemINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repELi0ELb0EEC2ENS_18__default_init_tagE
__ZNSt3__122__compressed_pair_elemINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repELi0ELb0EEC2ENS_18__default_init_tagE: ; @_ZNSt3__122__compressed_pair_elemINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repELi0ELb0EEC2ENS_18__default_init_tagE
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp]
	ldr	x0, [sp]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNSt3__122__compressed_pair_elemINS_9allocatorIcEELi1ELb1EEC2ENS_18__default_init_tagE
__ZNSt3__122__compressed_pair_elemINS_9allocatorIcEELi1ELb1EEC2ENS_18__default_init_tagE: ; @_ZNSt3__122__compressed_pair_elemINS_9allocatorIcEELi1ELb1EEC2ENS_18__default_init_tagE
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #16]
	ldr	x0, [sp, #16]
	str	x0, [sp, #8]                    ; 8-byte Folded Spill
	bl	__ZNSt3__19allocatorIcEC2Ev
	ldr	x0, [sp, #8]                    ; 8-byte Folded Reload
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNSt3__19allocatorIcEC2Ev
__ZNSt3__19allocatorIcEC2Ev:            ; @_ZNSt3__19allocatorIcEC2Ev
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	str	x0, [sp]                        ; 8-byte Folded Spill
	bl	__ZNSt3__116__non_trivial_ifILb1ENS_9allocatorIcEEEC2Ev
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNSt3__116__non_trivial_ifILb1ENS_9allocatorIcEEEC2Ev
__ZNSt3__116__non_trivial_ifILb1ENS_9allocatorIcEEEC2Ev: ; @_ZNSt3__116__non_trivial_ifILb1ENS_9allocatorIcEEEC2Ev
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNSt3__1L12__to_addressIKcEEPT_S3_
__ZNSt3__1L12__to_addressIKcEEPT_S3_:   ; @_ZNSt3__1L12__to_addressIKcEEPT_S3_
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE13__get_pointerEv
__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE13__get_pointerEv: ; @_ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE13__get_pointerEv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	ldur	x0, [x29, #-8]
	str	x0, [sp, #16]                   ; 8-byte Folded Spill
	bl	__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9__is_longEv
	tbz	w0, #0, LBB55_2
	b	LBB55_1
LBB55_1:
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	bl	__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE18__get_long_pointerEv
	str	x0, [sp, #8]                    ; 8-byte Folded Spill
	b	LBB55_3
LBB55_2:
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	bl	__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE19__get_short_pointerEv
	str	x0, [sp, #8]                    ; 8-byte Folded Spill
	b	LBB55_3
LBB55_3:
	ldr	x0, [sp, #8]                    ; 8-byte Folded Reload
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9__is_longEv
__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9__is_longEv: ; @_ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9__is_longEv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	bl	__ZNKSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv
	ldrb	w8, [x0, #23]
                                        ; kill: def $x8 killed $w8
	ands	x8, x8, #0x80
	cset	w8, ne
	and	w0, w8, #0x1
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE18__get_long_pointerEv
__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE18__get_long_pointerEv: ; @_ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE18__get_long_pointerEv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	bl	__ZNKSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv
	ldr	x0, [x0]
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE19__get_short_pointerEv
__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE19__get_short_pointerEv: ; @_ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE19__get_short_pointerEv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	bl	__ZNKSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv
	bl	__ZNSt3__114pointer_traitsIPKcE10pointer_toERS1_
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNKSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv
__ZNKSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv: ; @_ZNKSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	bl	__ZNKSt3__122__compressed_pair_elemINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repELi0ELb0EE5__getEv
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNKSt3__122__compressed_pair_elemINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repELi0ELb0EE5__getEv
__ZNKSt3__122__compressed_pair_elemINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repELi0ELb0EE5__getEv: ; @_ZNKSt3__122__compressed_pair_elemINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repELi0ELb0EE5__getEv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNSt3__114pointer_traitsIPKcE10pointer_toERS1_
__ZNSt3__114pointer_traitsIPKcE10pointer_toERS1_: ; @_ZNSt3__114pointer_traitsIPKcE10pointer_toERS1_
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	bl	__ZNSt3__1L9addressofIKcEEPT_RS2_
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNSt3__1L9addressofIKcEEPT_RS2_
__ZNSt3__1L9addressofIKcEEPT_RS2_:      ; @_ZNSt3__1L9addressofIKcEEPT_RS2_
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEEC2ERNS_13basic_ostreamIcS2_EE
__ZNSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEEC2ERNS_13basic_ostreamIcS2_EE: ; @_ZNSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEEC2ERNS_13basic_ostreamIcS2_EE
Lfunc_begin6:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception6
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	x1, [x29, #-16]
	ldur	x8, [x29, #-8]
	str	x8, [sp]                        ; 8-byte Folded Spill
	ldur	x8, [x29, #-16]
	ldr	x9, [x8]
	ldur	x9, [x9, #-24]
	add	x0, x8, x9
Ltmp75:
	bl	__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5rdbufEv
	str	x0, [sp, #8]                    ; 8-byte Folded Spill
Ltmp76:
	b	LBB63_1
LBB63_1:
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	str	x8, [x0]
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
LBB63_2:
Ltmp77:
	mov	x8, x1
	str	x0, [sp, #24]
	str	w8, [sp, #20]
	b	LBB63_3
LBB63_3:
	ldr	x0, [sp, #24]
	bl	___cxa_call_unexpected
Lfunc_end6:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table63:
Lexception6:
	.byte	255                             ; @LPStart Encoding = omit
	.byte	155                             ; @TType Encoding = indirect pcrel sdata4
	.uleb128 Lttbase6-Lttbaseref6
Lttbaseref6:
	.byte	1                               ; Call site Encoding = uleb128
	.uleb128 Lcst_end6-Lcst_begin6
Lcst_begin6:
	.uleb128 Ltmp75-Lfunc_begin6            ; >> Call Site 1 <<
	.uleb128 Ltmp76-Ltmp75                  ;   Call between Ltmp75 and Ltmp76
	.uleb128 Ltmp77-Lfunc_begin6            ;     jumps to Ltmp77
	.byte	1                               ;   On action: 1
	.uleb128 Ltmp76-Lfunc_begin6            ; >> Call Site 2 <<
	.uleb128 Lfunc_end6-Ltmp76              ;   Call between Ltmp76 and Lfunc_end6
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
Lcst_end6:
	.byte	127                             ; >> Action Record 1 <<
                                        ;   Filter TypeInfo -1
	.byte	0                               ;   No further actions
	.p2align	2
Lttbase6:
                                        ; >> Filter TypeInfos <<
	.byte	0
	.p2align	2
                                        ; -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.p2align	2                               ; -- Begin function _ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5rdbufEv
__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5rdbufEv: ; @_ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5rdbufEv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	bl	__ZNKSt3__18ios_base5rdbufEv
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNKSt3__18ios_base5rdbufEv
__ZNKSt3__18ios_base5rdbufEv:           ; @_ZNKSt3__18ios_base5rdbufEv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	ldr	x8, [sp, #8]
	ldr	x0, [x8, #40]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZNSt3__111char_traitsIcE11eq_int_typeEii ; -- Begin function _ZNSt3__111char_traitsIcE11eq_int_typeEii
	.weak_definition	__ZNSt3__111char_traitsIcE11eq_int_typeEii
	.p2align	2
__ZNSt3__111char_traitsIcE11eq_int_typeEii: ; @_ZNSt3__111char_traitsIcE11eq_int_typeEii
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	w0, [sp, #12]
	str	w1, [sp, #8]
	ldr	w8, [sp, #12]
	ldr	w9, [sp, #8]
	subs	w8, w8, w9
	cset	w8, eq
	and	w0, w8, #0x1
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZNSt3__111char_traitsIcE3eofEv ; -- Begin function _ZNSt3__111char_traitsIcE3eofEv
	.weak_definition	__ZNSt3__111char_traitsIcE3eofEv
	.p2align	2
__ZNSt3__111char_traitsIcE3eofEv:       ; @_ZNSt3__111char_traitsIcE3eofEv
	.cfi_startproc
; %bb.0:
	mov	w0, #-1
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenEc
__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenEc: ; @_ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenEc
Lfunc_begin7:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception7
; %bb.0:
	sub	sp, sp, #80
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	sturb	w1, [x29, #-9]
	ldur	x0, [x29, #-8]
	sub	x8, x29, #24
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	bl	__ZNKSt3__18ios_base6getlocEv
	ldr	x0, [sp, #8]                    ; 8-byte Folded Reload
Ltmp80:
	bl	__ZNSt3__1L9use_facetINS_5ctypeIcEEEERKT_RKNS_6localeE
	str	x0, [sp, #16]                   ; 8-byte Folded Spill
Ltmp81:
	b	LBB68_1
LBB68_1:
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	ldursb	w1, [x29, #-9]
Ltmp82:
	bl	__ZNKSt3__15ctypeIcE5widenEc
	str	w0, [sp, #4]                    ; 4-byte Folded Spill
Ltmp83:
	b	LBB68_2
LBB68_2:
	sub	x0, x29, #24
	bl	__ZNSt3__16localeD1Ev
	ldr	w8, [sp, #4]                    ; 4-byte Folded Reload
	sxtb	w0, w8
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
LBB68_3:
Ltmp84:
	mov	x8, x1
	str	x0, [sp, #32]
	str	w8, [sp, #28]
Ltmp85:
	sub	x0, x29, #24
	bl	__ZNSt3__16localeD1Ev
Ltmp86:
	b	LBB68_4
LBB68_4:
	b	LBB68_5
LBB68_5:
	ldr	x0, [sp, #32]
	bl	__Unwind_Resume
LBB68_6:
Ltmp87:
	bl	___clang_call_terminate
Lfunc_end7:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table68:
Lexception7:
	.byte	255                             ; @LPStart Encoding = omit
	.byte	155                             ; @TType Encoding = indirect pcrel sdata4
	.uleb128 Lttbase7-Lttbaseref7
Lttbaseref7:
	.byte	1                               ; Call site Encoding = uleb128
	.uleb128 Lcst_end7-Lcst_begin7
Lcst_begin7:
	.uleb128 Lfunc_begin7-Lfunc_begin7      ; >> Call Site 1 <<
	.uleb128 Ltmp80-Lfunc_begin7            ;   Call between Lfunc_begin7 and Ltmp80
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp80-Lfunc_begin7            ; >> Call Site 2 <<
	.uleb128 Ltmp83-Ltmp80                  ;   Call between Ltmp80 and Ltmp83
	.uleb128 Ltmp84-Lfunc_begin7            ;     jumps to Ltmp84
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp83-Lfunc_begin7            ; >> Call Site 3 <<
	.uleb128 Ltmp85-Ltmp83                  ;   Call between Ltmp83 and Ltmp85
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp85-Lfunc_begin7            ; >> Call Site 4 <<
	.uleb128 Ltmp86-Ltmp85                  ;   Call between Ltmp85 and Ltmp86
	.uleb128 Ltmp87-Lfunc_begin7            ;     jumps to Ltmp87
	.byte	1                               ;   On action: 1
	.uleb128 Ltmp86-Lfunc_begin7            ; >> Call Site 5 <<
	.uleb128 Lfunc_end7-Ltmp86              ;   Call between Ltmp86 and Lfunc_end7
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
Lcst_end7:
	.byte	1                               ; >> Action Record 1 <<
                                        ;   Catch TypeInfo 1
	.byte	0                               ;   No further actions
	.p2align	2
                                        ; >> Catch TypeInfos <<
	.long	0                               ; TypeInfo 1
Lttbase7:
	.p2align	2
                                        ; -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.p2align	2                               ; -- Begin function _ZNSt3__1L9use_facetINS_5ctypeIcEEEERKT_RKNS_6localeE
__ZNSt3__1L9use_facetINS_5ctypeIcEEEERKT_RKNS_6localeE: ; @_ZNSt3__1L9use_facetINS_5ctypeIcEEEERKT_RKNS_6localeE
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	adrp	x1, __ZNSt3__15ctypeIcE2idE@GOTPAGE
	ldr	x1, [x1, __ZNSt3__15ctypeIcE2idE@GOTPAGEOFF]
	bl	__ZNKSt3__16locale9use_facetERNS0_2idE
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNKSt3__15ctypeIcE5widenEc
__ZNKSt3__15ctypeIcE5widenEc:           ; @_ZNKSt3__15ctypeIcE5widenEc
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	strb	w1, [sp, #7]
	ldr	x0, [sp, #8]
	ldrsb	w1, [sp, #7]
	ldr	x8, [x0]
	ldr	x8, [x8, #56]
	blr	x8
	sxtb	w0, w0
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _ZNSt3__18ios_base8setstateEj
__ZNSt3__18ios_base8setstateEj:         ; @_ZNSt3__18ios_base8setstateEj
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	str	w1, [sp, #4]
	ldr	x0, [sp, #8]
	ldr	w8, [x0, #32]
	ldr	w9, [sp, #4]
	orr	w1, w8, w9
	bl	__ZNSt3__18ios_base5clearEj
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZNK3phy6matrixIfE4rowsEv      ; -- Begin function _ZNK3phy6matrixIfE4rowsEv
	.weak_definition	__ZNK3phy6matrixIfE4rowsEv
	.p2align	2
__ZNK3phy6matrixIfE4rowsEv:             ; @_ZNK3phy6matrixIfE4rowsEv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	ldr	x8, [sp, #8]
	ldr	x0, [x8, #8]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZNK3phy6matrixIfE4colsEv      ; -- Begin function _ZNK3phy6matrixIfE4colsEv
	.weak_definition	__ZNK3phy6matrixIfE4colsEv
	.p2align	2
__ZNK3phy6matrixIfE4colsEv:             ; @_ZNK3phy6matrixIfE4colsEv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	ldr	x8, [sp, #8]
	ldr	x0, [x8, #16]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_c ; -- Begin function _ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_c
	.weak_definition	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_c
	.p2align	2
__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_c: ; @_ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_c
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	x8, x1
	str	x0, [sp, #8]
	add	x1, sp, #7
	strb	w8, [sp, #7]
	ldr	x0, [sp, #8]
	mov	x2, #1
	bl	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZNK3phy6matrixIfE11compareSizeEmm ; -- Begin function _ZNK3phy6matrixIfE11compareSizeEmm
	.weak_definition	__ZNK3phy6matrixIfE11compareSizeEmm
	.p2align	2
__ZNK3phy6matrixIfE11compareSizeEmm:    ; @_ZNK3phy6matrixIfE11compareSizeEmm
Lfunc_begin8:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception8
; %bb.0:
	sub	sp, sp, #80
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-16]
	stur	x1, [x29, #-24]
	str	x2, [sp, #32]
	ldur	x0, [x29, #-16]
	str	x0, [sp]                        ; 8-byte Folded Spill
	mov	w8, #1
	strb	w8, [sp, #31]
	bl	__ZNK3phy6matrixIfE4rowsEv
	ldur	x8, [x29, #-24]
	subs	x8, x0, x8
	b.ne	LBB75_2
	b	LBB75_1
LBB75_1:
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	bl	__ZNK3phy6matrixIfE4colsEv
	ldr	x8, [sp, #32]
	subs	x8, x0, x8
	b.eq	LBB75_7
	b	LBB75_2
LBB75_2:
	mov	x0, #4
	bl	___cxa_allocate_exception
	mov	w8, #-1
	str	w8, [x0]
Ltmp90:
	adrp	x1, __ZTIi@GOTPAGE
	ldr	x1, [x1, __ZTIi@GOTPAGEOFF]
	mov	x2, #0
	bl	___cxa_throw
Ltmp91:
	b	LBB75_11
LBB75_3:
Ltmp92:
	mov	x8, x1
	str	x0, [sp, #16]
	str	w8, [sp, #12]
	b	LBB75_4
LBB75_4:
	ldr	w8, [sp, #12]
	subs	w8, w8, #1
	b.ne	LBB75_10
	b	LBB75_5
LBB75_5:
	ldr	x0, [sp, #16]
	bl	___cxa_begin_catch
	ldr	w8, [x0]
	str	w8, [sp, #8]
Ltmp93:
	adrp	x0, __ZNSt3__14coutE@GOTPAGE
	ldr	x0, [x0, __ZNSt3__14coutE@GOTPAGEOFF]
	adrp	x1, l_.str.18@PAGE
	add	x1, x1, l_.str.18@PAGEOFF
	bl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
Ltmp94:
	b	LBB75_6
LBB75_6:
	mov	w8, #0
	and	w8, w8, #0x1
	and	w8, w8, #0x1
	sturb	w8, [x29, #-1]
	bl	___cxa_end_catch
	b	LBB75_9
LBB75_7:
	ldrb	w8, [sp, #31]
	and	w8, w8, #0x1
	and	w8, w8, #0x1
	sturb	w8, [x29, #-1]
	b	LBB75_9
LBB75_8:
Ltmp95:
	mov	x8, x1
	str	x0, [sp, #16]
	str	w8, [sp, #12]
	bl	___cxa_end_catch
	b	LBB75_10
LBB75_9:
	ldurb	w8, [x29, #-1]
	and	w0, w8, #0x1
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
LBB75_10:
	ldr	x0, [sp, #16]
	bl	__Unwind_Resume
LBB75_11:
Lfunc_end8:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table75:
Lexception8:
	.byte	255                             ; @LPStart Encoding = omit
	.byte	155                             ; @TType Encoding = indirect pcrel sdata4
	.uleb128 Lttbase8-Lttbaseref8
Lttbaseref8:
	.byte	1                               ; Call site Encoding = uleb128
	.uleb128 Lcst_end8-Lcst_begin8
Lcst_begin8:
	.uleb128 Lfunc_begin8-Lfunc_begin8      ; >> Call Site 1 <<
	.uleb128 Ltmp90-Lfunc_begin8            ;   Call between Lfunc_begin8 and Ltmp90
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp90-Lfunc_begin8            ; >> Call Site 2 <<
	.uleb128 Ltmp91-Ltmp90                  ;   Call between Ltmp90 and Ltmp91
	.uleb128 Ltmp92-Lfunc_begin8            ;     jumps to Ltmp92
	.byte	1                               ;   On action: 1
	.uleb128 Ltmp91-Lfunc_begin8            ; >> Call Site 3 <<
	.uleb128 Ltmp93-Ltmp91                  ;   Call between Ltmp91 and Ltmp93
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp93-Lfunc_begin8            ; >> Call Site 4 <<
	.uleb128 Ltmp94-Ltmp93                  ;   Call between Ltmp93 and Ltmp94
	.uleb128 Ltmp95-Lfunc_begin8            ;     jumps to Ltmp95
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp94-Lfunc_begin8            ; >> Call Site 5 <<
	.uleb128 Lfunc_end8-Ltmp94              ;   Call between Ltmp94 and Lfunc_end8
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
Lcst_end8:
	.byte	1                               ; >> Action Record 1 <<
                                        ;   Catch TypeInfo 1
	.byte	0                               ;   No further actions
	.p2align	2
                                        ; >> Catch TypeInfos <<
Ltmp96:                                 ; TypeInfo 1
	.long	__ZTIi@GOT-Ltmp96
Lttbase8:
	.p2align	2
                                        ; -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN3phy6matrixIiEC2Emmi        ; -- Begin function _ZN3phy6matrixIiEC2Emmi
	.weak_def_can_be_hidden	__ZN3phy6matrixIiEC2Emmi
	.p2align	2
__ZN3phy6matrixIiEC2Emmi:               ; @_ZN3phy6matrixIiEC2Emmi
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #80
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-16]
	stur	x1, [x29, #-24]
	str	x2, [sp, #32]
	str	w3, [sp, #28]
	ldur	x9, [x29, #-16]
	str	x9, [sp]                        ; 8-byte Folded Spill
	mov	x8, x9
	stur	x8, [x29, #-8]
	ldur	x8, [x29, #-24]
	str	x8, [x9, #8]
	ldr	x8, [sp, #32]
	str	x8, [x9, #16]
	ldr	w8, [sp, #28]
	str	w8, [x9, #24]
	ldur	x8, [x29, #-24]
	mov	x10, #8
	umulh	x9, x8, x10
	mul	x8, x8, x10
	subs	x9, x9, #0
	csinv	x0, x8, xzr, eq
	bl	__Znam
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	str	x0, [x8]
	str	wzr, [sp, #24]
	b	LBB76_1
LBB76_1:                                ; =>This Inner Loop Header: Depth=1
	ldrsw	x8, [sp, #24]
	ldur	x9, [x29, #-24]
	subs	x8, x8, x9
	b.hs	LBB76_4
	b	LBB76_2
LBB76_2:                                ;   in Loop: Header=BB76_1 Depth=1
	ldr	x8, [sp, #32]
	mov	x10, #4
	umulh	x9, x8, x10
	mul	x8, x8, x10
	subs	x9, x9, #0
	csinv	x0, x8, xzr, eq
	bl	__Znam
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	ldr	x8, [x8]
	ldrsw	x9, [sp, #24]
	str	x0, [x8, x9, lsl #3]
	b	LBB76_3
LBB76_3:                                ;   in Loop: Header=BB76_1 Depth=1
	ldr	w8, [sp, #24]
	add	w8, w8, #1
	str	w8, [sp, #24]
	b	LBB76_1
LBB76_4:
	str	wzr, [sp, #20]
	str	wzr, [sp, #16]
	b	LBB76_5
LBB76_5:                                ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB76_7 Depth 2
	ldrsw	x8, [sp, #16]
	ldur	x9, [x29, #-24]
	subs	x8, x8, x9
	b.hs	LBB76_15
	b	LBB76_6
LBB76_6:                                ;   in Loop: Header=BB76_5 Depth=1
	str	wzr, [sp, #12]
	b	LBB76_7
LBB76_7:                                ;   Parent Loop BB76_5 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldrsw	x8, [sp, #12]
	ldr	x9, [sp, #32]
	subs	x8, x8, x9
	b.hs	LBB76_13
	b	LBB76_8
LBB76_8:                                ;   in Loop: Header=BB76_7 Depth=2
	ldr	w8, [sp, #28]
	cbnz	w8, LBB76_10
	b	LBB76_9
LBB76_9:                                ;   in Loop: Header=BB76_7 Depth=2
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	ldr	x8, [x8]
	ldrsw	x9, [sp, #16]
	ldr	x9, [x8, x9, lsl #3]
	ldrsw	x10, [sp, #12]
	mov	w8, #0
	str	w8, [x9, x10, lsl #2]
	b	LBB76_11
LBB76_10:                               ;   in Loop: Header=BB76_7 Depth=2
	ldr	x9, [sp]                        ; 8-byte Folded Reload
	ldr	w8, [sp, #20]
	add	w10, w8, #1
	str	w10, [sp, #20]
	ldr	x9, [x9]
	ldrsw	x10, [sp, #16]
	ldr	x9, [x9, x10, lsl #3]
	ldrsw	x10, [sp, #12]
	str	w8, [x9, x10, lsl #2]
	b	LBB76_11
LBB76_11:                               ;   in Loop: Header=BB76_7 Depth=2
	b	LBB76_12
LBB76_12:                               ;   in Loop: Header=BB76_7 Depth=2
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	b	LBB76_7
LBB76_13:                               ;   in Loop: Header=BB76_5 Depth=1
	b	LBB76_14
LBB76_14:                               ;   in Loop: Header=BB76_5 Depth=1
	ldr	w8, [sp, #16]
	add	w8, w8, #1
	str	w8, [sp, #16]
	b	LBB76_5
LBB76_15:
	ldur	x0, [x29, #-8]
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"2x2 matrix\n"

l_.str.1:                               ; @.str.1
	.asciz	"3x2 matrix\n"

l_.str.2:                               ; @.str.2
	.asciz	"1x4 matrix\n"

l_.str.3:                               ; @.str.3
	.asciz	"identity\n"

l_.str.4:                               ; @.str.4
	.asciz	"transpose\n"

l_.str.5:                               ; @.str.5
	.asciz	"min:"

l_.str.6:                               ; @.str.6
	.asciz	"\n"

l_.str.7:                               ; @.str.7
	.asciz	"max:"

l_.str.8:                               ; @.str.8
	.asciz	"sum:"

l_.str.9:                               ; @.str.9
	.asciz	"prod:"

l_.str.10:                              ; @.str.10
	.asciz	"mean:"

l_.str.11:                              ; @.str.11
	.asciz	"result:"

l_.str.12:                              ; @.str.12
	.asciz	"[ + op]\n"

l_.str.13:                              ; @.str.13
	.asciz	"[ - op]\n"

l_.str.14:                              ; @.str.14
	.asciz	"[ * op(scalar)]\n"

l_.str.15:                              ; @.str.15
	.asciz	"[ / op(scalar)]\n"

l_.str.16:                              ; @.str.16
	.asciz	"matrix multiplication\n"

l_.str.17:                              ; @.str.17
	.asciz	"cannot calculate (no coefficients)"

l_.str.18:                              ; @.str.18
	.asciz	"cannot prooceed operation (size is differenct)"

l_.str.19:                              ; @.str.19
	.asciz	"divide by 0 \n"

l_.str.20:                              ; @.str.20
	.asciz	"cannot calculate(size is not fit)\n"

l_.str.21:                              ; @.str.21
	.asciz	"without const \n"

l_.str.22:                              ; @.str.22
	.asciz	"const \n"

.subsections_via_symbols
