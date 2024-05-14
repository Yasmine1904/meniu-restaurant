cmake_minimum_required(VERSION 3.24)
project(lab9_10POO)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab9_10POO main.cpp entitate.cpp entitate.h repo.h teste.cpp teste.h service.h UI.h RepoFile.cpp RepoFile.h ElementNotFoundException.h InvalidCodeExc.h NrNaturalExc.h)
