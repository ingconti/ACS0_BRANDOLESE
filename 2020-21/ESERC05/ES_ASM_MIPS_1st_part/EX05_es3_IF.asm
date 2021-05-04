
#-----------------------------------------------------------
# Program    :
# Written by : ingconti
# Date       :
# Description: EX05_es3_IF.asm
#-----------------------------------------------------------
    .data    

    .text
    addi    $s0, $zero, 1
    addi    $s1, $zero, 3
    add    $s0, $s0, $s1
    sgt    $s2, $s0, $s1
    beq    $s2, $zero, end
    add    $s1, $s1, $s0
end:
