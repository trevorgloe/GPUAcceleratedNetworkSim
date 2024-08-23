# try to load the dynamically linked library

import ctypes

testlib = ctypes.CDLL("out/build/gcc/libgraph_fcn.so")

myint = testlib.test_print()

print(myint)