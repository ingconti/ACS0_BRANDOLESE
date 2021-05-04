	.data
	.text
main:	addi	$a0, $zero, 20
	jal	fattoriale
 
    move $a0, $v0 # call printf
    li $v0,1
    syscall

	add 	$s0, $v0, $zero
	addi	$v0, $zero, 10
	syscall

fattoriale:
	addi	$sp, $sp, -8
	sw	$ra, 4($sp)
	sw	$a0, 0($sp)
	slti	$t0, $a0, 1
	beq	$t0, $zero, L1
	addi	$v0, $zero, 1
	addi	$sp, $sp, 8
	jr	$ra
L1:	addi	$a0, $a0, -1
	jal 	fattoriale
	lw	$a0, 0($sp)
	lw	$ra, 4($sp)
	addi	$sp, $sp, 8
	mul	$v0, $a0, $v0
	jr	$ra
