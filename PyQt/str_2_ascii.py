'''
Created on Oct 18, 2018

@author: srwle
'''

def str2ascii(in_str):
    ret=''
    if isinstance(in_str, str):
        for c in in_str:
            ret += hex(ord(c))
        return ret
    else:
        return None


def testmain():
    print(str2ascii('1234'))

if __name__ == '__main__':
    testmain()