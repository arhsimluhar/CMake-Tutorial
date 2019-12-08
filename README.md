# CMake-Tutorial
Learn how to build cross-platform applications using CMake 


# Additional Notes

- The values that the CMake user enters will be saved in the text file CMakeCache.txt as Key-Value pair.
- In **target_link_libraries** you can specify scope (PRIVATE , PUBLIC and INTERFACE)
    - PRIVATE means that folder is included in child scope only
    - PUBLIC means that folder is included in both child and parent scope.
    - INTERFACE means that folder is included in only the parent scope and not it child scope.

- Working with DLLs often requires platform specific actions, which CMake support using the built-in variables **WIN32**, **APPLE** and **UNIX**.


# Advanced Topics
 - **find_package()** : https://cmake.org/cmake/help/latest/command/find_package.html
    There are two modes: MODULE and CONFIG mode.
    - In MODULE mode: Cmake looks for **Find<packagename>.cmake** file and process it.
    - If the MODULE option is not specfied in the above signature, CMake first searches for the package using Module mode. Then, if the package is not found, it searches again using Config mode. A user may set the variable **CMAKE_FIND_PACKAGE_PREFER_CONFIG** to TRUE to direct CMake first search using Config mode before falling back to Module mode.
    

