#---------------
# Description: EX05_es5_WHILE.asm
#---------------

.data
.text
addi    $s0, $zero, 3
cond:   sgt  $s1, $s0, $zero
beq     $s1, $zero, end
addi    $s0, $s0, -1
b       cond
end:


