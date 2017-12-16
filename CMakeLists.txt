# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/16 17:36:31 by cbaillat          #+#    #+#              #
#    Updated: 2017/12/16 20:31:20 by cbaillat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

################################################################################
# build executable.
# all sources are added in their specific folders using target_sources
add_executable (printf)

# include headers in the project
target_include_directories (
	printf
	PRIVATE
		"${PROJECT_SOURCE_DIR}/srcs"
		"${PROJECT_SOURCE_DIR}/srcs/parsing"
		"${PROJECT_SOURCE_DIR}/srcs/printing"
)

# add all the sources subdirectories
add_subdirectory (parsing)
add_subdirectory (printing)

# include libraries
target_link_libraries (printf ${LIBRARIES})
################################################################################

################################################################################
# should we use the library? (here for learning purposes)
option (USE_LIBFT
		"Use the libft provided" ON
)
# build library
if (USE_LIBFT)
	target_include_directories (printf
		PRIVATE
			"${PROJECT_SOURCE_DIR}/libft/srcs"
	)
	add_subdirectory (libft)
	set (LIBRARIES ${LIBRARIES} libft)
endif (USE_LIBFT)
################################################################################
