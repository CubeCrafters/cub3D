ifndef TOPDIR
	TOPDIR = $(abspath ../../../)
endif
ifndef SRCDIR
	SRCDIR = $(abspath ../)
endif

NAME := parser.a
HEAD := parser_bonus.h
SRCS := cd_gnl_bonus.c \
		identifiers_bonus.c \
		parser_util_bonus.c \
		read_arg_bonus.c \
		valid_info_bonus.c \

LDLIBS := -lft

include $(TOPDIR)/include_make/Variable.mk
include $(TOPDIR)/include_make/Link.mk
include $(TOPDIR)/include_make/Recipe_subsrc.mk
