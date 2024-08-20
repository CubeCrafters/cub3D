ifndef TOPDIR
	TOPDIR = $(abspath ../../)
endif
ifndef SRCDIR
	SRCDIR = $(abspath ./)
endif

NAME := cub3D
SRCS := main.c	\
		init.c	\

# SRCS(in SRCDIR) ------
DIRS := parser \
		render	\
		utils	\

SUBS := $(addsuffix .a,$(DIRS))

# LIBRARYS -------------
LDLIBS := -lft -L./mlx -lmlx -framework OpenGL -framework AppKit

include $(TOPDIR)/include_make/Variable.mk
include $(TOPDIR)/include_make/Link.mk
include $(TOPDIR)/include_make/Recipe_src.mk
