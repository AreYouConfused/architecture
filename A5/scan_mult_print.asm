start:  lodd on:        
        stod 4095
        call xbsywt:    
        loco str1:      
        call nextw:     
        lodd on:        
        stod 4093
bgndig: call rbsywt:    
        lodd 4092       
        subd numoff:    
        push            
nxtdig: call rbsywt:
        lodd 4092       
        stod nxtchr:    
        subd nl:
        jzer endnum:    
        mult 10         
        lodd nxtchr:    
        subd numoff:    
        addl 0          
        stol 0
        jump nxtdig:
endnum: lodd numptr:    
        popi            
        addd c1:        
        stod numptr:
        lodd numcnt:    
        jzer addnu:    
        subd c1:
        stod numcnt:
        jump start:     
addnu:  lodd binum1:    
        addd binum2:
        jneg oflow:    
        stod sum:       
        stod temp:      

strgen: lodd c10:       
        push
        lodd temp:
        push
        div             
        lodd lpcnt:
        addd c1:        
        stod lpcnt:
        lodl 1          
        addd numoff:    
        push            
        lodd psum:      
        popi            
        addd c1:        
        stod psum:
        lodl 0          
        jzer strgend:      
        stod temp:      
        jump strgen:
strgend:
        call xbsywt:    
        loco str2:
        call nextw:

prntnm: lodd lpcnt:     
        jzer done:
        subd c1:
        stod lpcnt:
        lodd psum:
        subd c1:        
        stod psum:
        pshi            
        call xbsywt:
        pop             
        stod 4094       
        jump prntnm:
done:   lodd cr:        
        stod 4094
        call xbsywt:
        lodd nl:
        stod 4094
        loco 0
        halt

oflow:  call xbsywt:    
        loco str3:
        call nextw:
        lodd cn1:
        halt

nextw:  pshi            
        addd c1:        
        stod pstr:
        lodl 0          
        jzer crnl:      
        stod 4094       
        subd c255:
        jneg crnl:      
        pop             
        rshift 8        
        push            
        call xbsywt:
        pop             
        stod 4094       
        call xbsywt:
        lodd pstr:      
        jump nextw:
xbsywt: lodd 4095       
        subd mask:      
        addd c1:        
        stod pstr:
        lodl 0          
        jzer crnl:      
        stod 4094       
        subd c255:
        jneg crnl:      
        pop             
        rshift 8        
        push            
        call xbsywt:
        pop             
        stod 4094       
        call xbsywt:
        lodd pstr:      
        jump nextw:
crnl:   insp 1
        lodd cr:
        stod 4094       
        call xbsywt:
        lodd nl:
        stod 4094       
        call xbsywt:
        retn
xbsywt: lodd 4095       
        subd mask:      
        jneg xbsywt:
        retn   
rbsywt: lodd 4093       
        subd mask:      
        jneg rbsywt:
        retn
on:     8               
mask:   10
nl:     10
cr:     13
cn1:    -1
c1:     1
c10:    10
c255:   255
pstr:   0
numoff: 48
nxtchr: 0
numptr: binum1:
binum1: 0
binum2: 0
numcnt: 1
sum:    0               
temp:   0
lpcnt:  0
psum:   asum:
str1:   "PLEASE ENTER AN INTEGER BETWEEN 1 AND 32767"
str2:   "THE SUM OF THESE TWO INTEGERS IS:"
str3:   "OVERFLOW, NO SUM POSSIBLE"
asum:   0               
        jneg xbsywt:
        retn   
rbsywt: lodd 4093       
        subd mask:      
        jneg rbsywt:
        retn
on:     8               
mask:   10
nl:     10
cr:     13
cn1:    -1
c1:     1
c10:    10
c255:   255
pstr:   0
numoff: 48
nxtchr: 0
numptr: binum1:
binum1: 0
binum2: 0
numcnt: 1
sum:    0               
temp:   0
lpcnt:  0
psum:   asum:
str1:   "PLEASE ENTER AN INTEGER BETWEEN 1 AND 32767"
str2:   "THE SUM OF THESE TWO INTEGERS IS:"
str3:   "OVERFLOW, NO SUM POSSIBLE"
asum:   0               
