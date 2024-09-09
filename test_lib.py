## python script to test the c bindings and the library

import ctypes
import networkx as nx

testlib = ctypes.CDLL("out/build/gcc/libgans_fnc.so")

connects = [2,3,4,5,6]
connects_ctypes = (ctypes.c_int * len(connects)) (*connects)
# print(connects_ctypes)
# node_obj = testlib.create_node(1,connects_ctypes)
node_ptr = testlib.create_node(1,connects_ctypes)
print("pointer to node object: " + str(node_ptr))
index = testlib.get_index(node_ptr)
print("node index: " + str(index))
connects_size = testlib.get_connects_size(node_ptr)
print(connects_size)
new_connects = [0,0,0,0,0]
print("before function call: ")
new_connects_ctypes = (ctypes.c_int * 5) (*new_connects)
for i in range(len(new_connects_ctypes)):
    print(new_connects_ctypes[i])

testlib.get_connects_vector(node_ptr, new_connects_ctypes)
# print(new_connects_ctypes[0])
print("length of array: " + str(len(new_connects_ctypes)))
print("After function call: ")
for i in range(len(new_connects_ctypes)):
    print(new_connects_ctypes[i])
# for i in new_connects_ctypes.contents():
    # print(i)

# f.restype = ctypes.POINTER(ctypes.c_int * 10)
# print [i for i in f().contents] # output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]