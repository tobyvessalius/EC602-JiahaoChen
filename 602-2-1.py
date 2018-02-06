602-2-1
# AUTHOR JiahaoCHEN tobychen@bu.edu
# AUTHOR YueSUN yuesun@bu.edu
# AUTHOR YuningQIU qiuyn@bu.edu
# AUTHOR XinranZHANG zhangxr@bu.edu


bit = 10**40
byte = bit/8
tb = byte/(1024**4)

tb_max = tb*1.1
tb_min = tb*0.9

print("%.1e" %(tb))
print("%.1e" %(tb_max))
print("%.1e" %(tb_min))