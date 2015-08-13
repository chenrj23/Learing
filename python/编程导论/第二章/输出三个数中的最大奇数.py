# -*- coding: cp936 -*-
x, y, z = 1, 2, 4
if x%2 != 0  and y%2 != 0 and z%2 !=0:
    if x > y and x > z:
        print 'x is biggest odd'
    elif y > z:
        print 'y is biggest odd'
    else:
        print 'z is biggest odd'
elif x%2 != 0 and y%2 == 0 and z%2 ==0:
    print 'x is biggest odd'
elif y%2 != 0 and x%2 == 0 and z%2 ==0:
    print 'y is biggest odd'
elif z%2 != 0 and y%2 == 0 and x%2 ==0:
    print 'z is biggest odd'
elif x%2 != 0 and y%2 != 0 and z%2 ==0:
    if x > y :
        print 'x is biggest odd'
    else:
        print 'y is biggest odd'
elif x%2 != 0 and y%2 == 0 and z%2 !=0:
    if x > z :
        print 'x is biggest odd'
    else:
        print 'z is biggest odd'
elif x%2 == 0 and y%2 != 0 and z%2 !=0:
    if y > z :
        print 'y is biggest odd'
    else:
        print 'z is biggest odd'
else:
    print "no odd number"
