#---------------
# Description: EX05_es6_DO.asm
#---------------

 .data
.text
addi        $s0, $zero, 3
do_while:   sgt  $s1, $s0, $zero
beq         $s1, $zero, end
addi        $s0, $s0, -1
b           do_while
end:

