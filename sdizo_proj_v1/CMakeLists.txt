cmake_minimum_required(VERSION 3.24)
project(sdizo_proj_v1)

set(CMAKE_CXX_STANDARD 11)

add_executable(sdizo_proj_v1 application/main.cpp tablica_dym/Array.cpp tablica_dym/Array.h kopiec_bin/Heap.cpp kopiec_bin/Heap.h kopiec_bin/Heap.h lista_dwu/Node.cpp lista_dwu/Node.h lista_dwu/DoubleList.cpp lista_dwu/DoubleList.h bst_tree/BST.cpp bst_tree/BST.h bst_tree/BST.h bst_tree/BST_Node.cpp bst_tree/BST_Node.h black_and_red_tree/RBT.cpp black_and_red_tree/RBT.h black_and_red_tree/RB_Node.cpp black_and_red_tree/RB_Node.h black_and_red_tree/RB_Node.cpp tests/Test_array.cpp tests/Test_array.h tests/Test_list.cpp tests/Test_list.h tests/Test_heap.cpp tests/Test_heap.h tests/Test_heap.h tests/Test_bst.cpp tests/Test_bst.h tests/Test_bst.h tests/Test_rbt.cpp tests/Test_rbt.h tests/Test_rbt.h)
