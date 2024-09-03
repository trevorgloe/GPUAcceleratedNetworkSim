## python script to test the c bindings and the library

import ctypes
import networkx as nx

testlib = ctypes.CDLL("out/build/gcc/libgans_fnc.so")

node_obj = testlib.create_node(1,[2,3,4])