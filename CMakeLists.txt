cmake_minimum_required(VERSION 3.16)
project(proje_mrjack C)

set(CMAKE_C_STANDARD 99)

add_executable(proje_mrjack main.c zamin_funcs.c zamin_funcs.h linked_list.c linked_list.h)
