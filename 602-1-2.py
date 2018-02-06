602-1-2
# AUTHOR JiahaoCHEN tobychen@bu.edu
# AUTHOR YueSUN yuesun@bu.edu
# AUTHOR YuningQIU qiuyn@bu.edu
# AUTHOR XinranZHANG zhangxr@bu.edu

X=int(input("Enter an X:"))
Y=int(input("Enter a Y:"))

X_F=1
Y_F=1

for i in range(X):
    X_F=X*X_F
    X-=1
    
for i in range(Y):
    Y_F=Y*Y_F
    Y-=1

Z=X_F-Y_F

A=1
a=0
while A<Z:
    A=10*A
    a+=1

B=Z.bit_length()/8
b=B

while b>0:
    b-=1

if b==0:
    c=B
else:
    c=int(B)+1


'''
B=1
b=0
while B<Z:
    B=(2**8)**b
    b+=1
'''

print(Z)
print(a)
print(c)
