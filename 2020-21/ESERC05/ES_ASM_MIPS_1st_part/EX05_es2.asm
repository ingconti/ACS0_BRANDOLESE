#---------------------------
# Program    :
# Written by : ingconti
# Date       :
# Description: EX05_es2.asm:
#using memory and addresses
#---------------------------
.data
A:    .word    21

.text
    la    $s0, A
    lw    $s1, ($s0)
    addi  $s1, $s1, -5
    sw    $s1, ($s0)

