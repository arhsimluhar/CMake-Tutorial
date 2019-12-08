#define the minimum required version for cmake
cmake_minimum_required( VERSION 3.12)

#setting C++ version and other settings
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


#Writing platform specific blocks 

IF(WIN32)
    message("Windows Operating System")
ELSEIF(APPLE)
    message("Apple MacOS")
ELSEIF(UNIX)
    message("Linux Operating system")
    add_definitions(-DFOO)
    add_definitions(-DBAR=\"BAR\")
ENDIF()




#Set Global Property
set_property(GLOBAL PROPERTY fancy "LINUX")


set(source "${CMAKE_CURRENT_SOURCE_DIR}/src")


#Get Only Global Cmake Property 
get_cmake_property(var fancy)
message(STATUS "GLOBAL variable: ${var}")


#Set Project Name and Version 
project(Main VERSION 0.1)




#Setting Author Variable to String "Rahul Mishra"
set(AUTHOR "RAHUL MISHRA")

message( STATUS "Building the libmath project")

#setting header file and statically and dynamically linked libraries that can be included to compile executables and libraries
set (fooinclude "/usr/local/include/" CACHE PATH "path of fooheader")
set (foolib "/usr/local/lib/test.a" CACHE FILEPATH "PATH TO statically linked library FOO")
set (foodll "/usr/local/lib/test.so" CACHE FILEPATH "Path to DLL Foo")

#go build project inside libmath first as our Main project depends on it 
add_subdirectory(libmath)


#go build project hurricane after this 
add_subdirectory(hurricane)

#Copy the runtime resources (such as DLLs , game-assets and text files)
#instead of path you can use Release/Debug, so if the folder doesnt exists
#it will create  build/Release folder and copy the file there.
FILE(COPY externals/res.txt DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/build")


#creating target executable and adding required source files for it
add_executable(Main ${source}/main.cpp)



target_link_libraries(Main PRIVATE libmath hurricane)
target_include_directories(Main PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")


#------------------------------------------------------------------------------------
#   Miscelleneous Operation in CMAKE
#
#------------------------------------------------------------------------------------



#setting up numberical variable
set (START 0)

#Using while loop
while(START LESS 10)
    message(STATUS "Value of start: ${START}")
    #incrementing the value of start by 1
    math(EXPR START "${START} + 1")
endwhile(START LESS 10)

#using foreach to iterate over items provided in the list
foreach(item IN ITEMS foo bar exx dex ber)
    message(STATUS "current item is: ${item}")
endforeach(item IN ITEMS foo bar exx dex ber)

#Using foreach and iterate using range 0 - 10
foreach(idx RANGE 10)
    message(STATUS "Value of idx: ${idx}")
endforeach(idx range 10)

#foreach with RANGE keyword that iterates to 10 with a skip of 2
foreach(idx RANGE 0 10 2)
    message(STATUS "Stepping by 2, Current value ${idx}")
endforeach()
 
#setting string variables value, Text strings can be evaluabled as boolean expressions
#The Values FALSE,OFF, NO or any string that ends with NOTFOUND evaluates to false and everything else to True

set(MY_STRING "YO")

#if example
if(MY_STRING)
    message(STATUS "matches 1")
endif()

#if-else example
if(NOT MY_STRING)
    message(STATUS "matches 1")
else()
    message(STATUS "matches 2")
endif()


#if-elseif-else ladder
if(NOT MY_STRING)
    message(STATUS "matches 2")
elseif(MY_STRING)
    message(STATUS "matches 3")
else()
    message(STATUS "matches 4")
endif()

#using NOT and OR operators in CMAKE
if (NOT MY_STRING OR "TRUE")
message(STATUS "matches 4")
endif()

#set another variable
set (ANOTHER_STRING "GO")

#check string equality, doing arthimetic comparison
if (ANOTHER_STRING STREQUAL MY_STRING)
    message(STATUS "matches 3")
elseif(NOT (1 EQUAL 3))
    message(STATUS "message 5" )
endif()

#cmake list, elements are shown seperated by a semi-colon
set(my_list 1 2 3 4)
message(STATUS "My List: ${my_list}")





# using functions in cmake
function(do_make_good first second third fourth)

    #ARGN will only iterate over the named arguements like (first, second, third, fourth)
    foreach(item IN LISTS ARGN)
        message(STATUS "Aguement value: ${item}")
    endforeach()

    #ARGV iterates over all the named and additional arguements
    foreach(item IN LISTS ARGV)
        message(STATUS "Aguement value: ${item}")
    endforeach()

    #Way use a passed arguement in CMAKE function 
    message(STATUS "Display Ag1: ${first}")
    message(STATUS "Display Ag1: ${second}")
    message(STATUS "Display Ag1: ${third}")
    message(STATUS "Display Ag1: ${fourth}")

 
endfunction()

do_make_good(1 2 3 4 5 6)



#function to increment values
set (start 1)
function(increment value)
    math(EXPR new_value "${${value}} + 1")
    #PARENT_SCOPE is used to override the value in Parent Scope
    set("${value}" "${new_value}" PARENT_SCOPE)
endfunction(increment value)
increment(start)
increment(start)
increment(start)
increment(start)
increment(start)
increment(start)
increment(start)
message(STATUS "final value of start: ${start}")


#function to sum two values and save it to variable
function(sum value a b)
    math(EXPR new_value "${a} + ${b}")
    set(value "${new_value}" PARENT_SCOPE)
endfunction()
sum(value 4 5)
message(STATUS "sum of the numbers after addtion : ${value}")


