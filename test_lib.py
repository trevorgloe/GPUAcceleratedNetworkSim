## python script to test the c bindings and the library

import ctypes
import networkx as nx
import numpy as np

class TestStruct(ctypes.Structure):
    _fields_ = [("array", (ctypes.c_int * 4) * 30)]
    

# testlib = ctypes.CDLL("out/build/gcc/libgans_fnc.so")
testlib = ctypes.CDLL("out/build/gcc/libgraph.so")

# connects = [2,3,4,5,6,7]
connects = [[1,2], [1,3], [2,1], [3,1], [3,4], [4,2]]
connects_ctypes = np.ctypeslib.ndpointer(dtype=int, ndim=2, flags="C")
# connects_ctypes = (ctypes.c_int * len(connects)*2) (*connects)
nodes = [1,2,3,4]
nodes_ctypes = (ctypes.c_int * len(nodes)) (*nodes)
name = 'test';
# name_ctypes = (ctypes.c_char * len(name)) (*name)
# print(len(name))
# testlib.testHooks.restype = ctypes.c_char_p
testlib.testHooks.argtypes = [ctypes.c_char_p, ctypes.c_int, connects_ctypes]
testlib.testHooks(ctypes.create_string_buffer(b'test'), 4, ctypes.byref(connects))


# testlib.createGraph.argtypes = [ctypes.c_char_p, ctypes.c_int, ctypes.c_int, connects_ctypes, ctypes.c_int, ctypes.c_int]
# testlib.createGraph('test', ctypes.byref(nodes), 4, ctypes.byref(connects), )
# name_ctypes = (ctypes.c_char) (ctypes.addressof(ctypes.create_string_buffer(4)))
# testlib.createGraph.argtypes(ctypes.c_char_p, ctypes.c_int, ctypes.c_int, ctypes.c_int, ctypes.c_int, ctypes.c_int)
# testlib.createGraph.restype = None
# graph_ptr = testlib.createGraph(name, ctypes.byref(nodes_ctypes), len(nodes), ctypes.byref(connects_ctypes), len(connects), 0)
# print(connects_ctypes)




# node_obj = testlib.create_node(1,connects_ctypes)
# node_ptr = testlib.create_node(1,connects_ctypes, 6)
# print("pointer to node object: " + str(node_ptr))
# index = testlib.get_index(node_ptr)
# print("node index: " + str(index))
# connects_size = testlib.get_connects_size(node_ptr)
# print(connects_size)
# # new_connects = [0,0,0,0,0]
# new_connects = [0] * connects_size
# print("before function call: ")
# new_connects_ctypes = (ctypes.c_int * len(new_connects)) (*new_connects)
# for i in range(len(new_connects_ctypes)):
#     print(new_connects_ctypes[i])

# testlib.get_connects_vector(node_ptr, new_connects_ctypes)
# # print(new_connects_ctypes[0])
# print("length of array: " + str(len(new_connects_ctypes)))
# print("After function call: ")
# for i in range(len(new_connects_ctypes)):
#     print(new_connects_ctypes[i])
# # for i in new_connects_ctypes.contents():
#     # print(i)

# # f.restype = ctypes.POINTER(ctypes.c_int * 10)
# # print [i for i in f().contents] # output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

# # try propogating the node
# testlib.extern_propogate_node(node_ptr)
# new_val = testlib.get_val(node_ptr)
# new_val_float = ctypes.cast(new_val,ctypes.c_float)
# print("new val: " + str(new_val))