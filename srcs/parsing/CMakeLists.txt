# This file add the sources in the directory to the executable specified with
# the add_executable command
target_sources(printf
				PRIVATE
					format_parsing.c
					specifiers.c
					flags.c
					width.c
					precision.c
					length.c
			)
