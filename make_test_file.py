filename = 'rootfs/core-cpu1.exe'
import ctypes

class Meh(ctypes.Structure):
    _fields_ = [('value', ctypes.c_uint32)]

val = Meh()

fid = open(filename,'wb')
for i in range( int((1024*1024)*2.9/4)):
    val.value = i + 0xffff
    fid.write(val)
fid.close()

