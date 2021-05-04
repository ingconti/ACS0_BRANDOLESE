
#---------------
# Program    :
# Written by : ingconti
# Date       :
# Description: EX05_es4_IF_ELSE.asm
#---------------
    .data
    .text
    addi    $s0, $zero, 2
    addi    $s1, $zero, 3
    sgt    $s2, $s0, $s1
    sgt    $s3, $s1, $zero
    and    $s2, $s2, $s3
    beq    $s2, $zero, else
    add    $s4, $s0, $s1
    j    end
else:    sub    $s4, $s0, $s1
end:
