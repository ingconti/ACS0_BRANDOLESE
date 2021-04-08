
#-----------------------------------------------------------
# Program    :
# Written by : ingconti
# Date       :
# Description: EX05_es1.asm
#-----------------------------------------------------------
    .data
    .word    10, 11, 12
    
    .text
    addi   $s0, $zero, 2
    addi   $s1, $s0,   5
    mul    $s2, $s1, $s0
    add    $s2, $s2, $s0
    sub    $s3, $s2, $s1
