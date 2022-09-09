cmake_minimum_required(VERSION 3.23)
project(Proyectos_en_C C)

set(CMAKE_C_STANDARD 99)

include_directories(.)
include_directories(Cya)

add_executable(Proyectos_en_C Cya/CajaRegistradora/CajaRegistradora.c Cya/CajaRegistradora/CajaRegistradora.h)
