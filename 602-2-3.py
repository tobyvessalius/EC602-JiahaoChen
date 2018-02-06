602-2-3
# AUTHOR JiahaoCHEN tobychen@bu.edu
# AUTHOR YueSUN yuesun@bu.edu
# AUTHOR YuningQIU qiuyn@bu.edu
# AUTHOR XinranZHANG zhangxr@bu.edu

from math import inf

def number_from_half(s : str):
    """return the number represented by s, a binary16 stored as a 4-character hex number"""
    
    return 0

def main():
    try:
        while(1):
            a = int(input(),16)
            b = bin(a, 10)
    except:
        if not isinstance(a, int):
            raise ValueError('input must be a number);
    """add all binary16 numbers from standard input until a non-number is entered, then print the total.
    Numbers are represented in 4-character hex string format, one per line"""
    


    # hint1: use int(input(),16)
    # hint2: use try: except: to halt


if __name__ == '__main__':
    main()
