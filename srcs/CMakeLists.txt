# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/16 17:36:31 by cbaillat          #+#    #+#              #
#    Updated: 2017/12/17 10:38:41 by cbaillat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
# build executable.
# all sources are added in their specific folders using target_sources
add_executable (
	printf
		main.c
		ft_printf.c
)

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
	target_include_directories (
		printf
			PUBLIC
				"${PROJECT_SOURCE_DIR}/libft/srcs"
	)
	add_subdirectory (libft)
	set (LIBRARIES ${LIBRARIES} libft)
endif (USE_LIBFT)
################################################################################
