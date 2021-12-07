start:      lodd on:
            stod 4095
            stod 4093
            loco str1:
            push
            call writestr:
            insp 1
            call readint:
            stod binum1:
            loco str1:
            push
            call writestr:
            insp 1
            call readint:
            stod binum2:
            lodd binum1:
            push
            lodd binum2:
            push
            call addints:
            insp 2
            stod sum:
            jpos prtsum:
            loco str3:
            push
            call writestr:
            insp 1
            halt
prtsum:     loco str2:
            push
            call writestr:
            insp 1
            lodd sum:
            push
            call writeint:
            insp 1
            halt

on:         8
mask:       10
nl:         10
cr:         13
numoff:     48
cn1:        -1
c1:         1
c10:        10
c255:       255
nxtchr:     0
binum1:     0
binum2:     0
sum:        0
temp:       0
lpcnt:      0
pstr:       0
psum:       asum:
str1:       "PLEASE ENTER AN INTEGER BETWEEN 1 AND 32767"
str2:       "THE SUM OF THESE TWO INTEGERS IS:"
str3:       "OVERFLOW, NO SUM POSSIBLE"
asum:       0
            0
            0
            0
            0
