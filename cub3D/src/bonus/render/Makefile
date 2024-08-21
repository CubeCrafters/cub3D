ifndef TOPDIR
	TOPDIR = $(abspath ../../../)
endif
ifndef SRCDIR
	SRCDIR = $(abspath ../)
endif

NAME := render.a
HEAD := render_bonus.h \
		matrix_bonus.h \

SRCS :=	matrix_bonus.c \
		ray_bonus.c \
		ray_calc_bonus.c \
		ray_utils_bonus.c \

LDLIBS := -lft

include $(TOPDIR)/include_make/Variable.mk
include $(TOPDIR)/include_make/Link.mk
include $(TOPDIR)/include_make/Recipe_subsrc.mk