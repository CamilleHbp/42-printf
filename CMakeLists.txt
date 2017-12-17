# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/17 09:32:52 by cbaillat          #+#    #+#              #
#    Updated: 2017/12/17 09:36:24 by cbaillat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################ this CMakeLists is the project top level list #################
# it calls all the CMakeLists for the library, and the one for the main program

# specify the minimum version for cmake
cmake_minimum_required (VERSION 3.9)

# project's name
project (printf)

# enable c language
enable_language (C)

# project version
set (VERSION_MAJOR 0)
set (VERSION_MINOR 1)
set (VERSION_PATCH 0)

# guard against in-source builds and bad build-type strings
include (safeguards)

# set ccompiler flags for GNU
if (CMAKE_C_COMPILER_ID MATCHES GNU OR CMAKE_C_COMPILER_ID MATCHES CLANG)
    set(CMAKE_C_FLAGS         "${CMAKE_C_FLAGS} -Wall -Werror -Wextra"
    set(CMAKE_C_FLAGS_DEBUG   "-O0 -g3")
    set(CMAKE_C_FLAGS_RELEASE "")
endif ()

# add the main program and the library folders
add_subdirectory (srcs)
add_subdirectory (libft)
