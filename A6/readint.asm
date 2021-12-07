readint:    call rbsywt:
            lodd 4092
            subd numoff:
            push
nxtdig:     call rbsywt:
            lodd 4092
            stod nxtchr:
            subd nl:
            jzer done:
            mult 10
            lodd nxtchr:
            subd numoff:
            addl 0
            stol 0
            jump nxtdig:
done:       pop
            retn
