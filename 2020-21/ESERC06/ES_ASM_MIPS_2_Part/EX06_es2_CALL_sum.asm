#---------------
# Description: EX06_es2_CALL_sum.asm
#---------------
.data:
x:    .word    0
y:    .word    0

.text
main:
  la    $s0, x
  li    $s1, 10
  sw    $s1, ($s0)


#Caller prolog:
  add    $a0, $zero, $s1 # x
  add    $a1, $zero, 20
  jal    sum

#save in Y:
  la    $s0, y
  sw    $v0, ($s0)


#printf: sys call: selettore: $v0 = 1, arg $a0

 move $a0, $v0 # save Y
 li $v0,1
 syscall

li $v0,10 # selettore syscall
main_:   syscall




sum:
  add $v0, $a0, $a1
jr     $ra

