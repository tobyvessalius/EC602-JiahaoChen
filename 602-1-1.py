602-1-1
# AUTHOR JiahaoCHEN tobychen@bu.edu
# AUTHOR YueSUN yuesun@bu.edu
# AUTHOR YuningQIU qiuyn@bu.edu
# AUTHOR XinranZHANG zhangxr@bu.edu

Table = "{:<6} {:<22} {:<22} {:<22}"

print(Table.format('Bytes','Largest Unsigned Int','Minimum Signed Int','Maximum Signed Int'))

for i in range(1,5):
    print(Table.format(i, 2**(8*i)-1, int((-2**(8*i)/2)), int((2**(8*i)/2-1))))


