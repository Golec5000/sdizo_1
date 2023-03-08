cmake_minimum_required(VERSION 3.24)
project(sdizo_proj_v1)

set(CMAKE_CXX_STANDARD 11)

add_executable(sdizo_proj_v1 application/main.cpp tablica_dym/TabDym.cpp tablica_dym/TabDym.h kopiec_bin/KopiecBin.cpp kopiec_bin/KopiecBin.h kopiec_bin/KopiecBin.h lista_dwu/Node.cpp lista_dwu/Node.h lista_dwu/DoubleList.cpp lista_dwu/DoubleList.h bst_tree/BST.cpp bst_tree/BST.h bst_tree/BST.h bst_tree/BST_Node.cpp bst_tree/BST_Node.h)
