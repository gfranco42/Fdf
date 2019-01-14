# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/09 13:44:17 by mverdier          #+#    #+#              #
#    Updated: 2019/01/14 16:27:11 by gfranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors.

ORANGE =	\033[1;33m   #It is actually Yellow, but i changed yellow to orange.

GREEN =		\033[1;32m

RED =		\033[1;31m

RES =		\033[0m

#------------------------------------------------------------------------------#

NAME = 		fdf

SRCDIR =	./srcs

INCDIR =	./includes

OBJDIR =	./objs

SRC =		main.c draw.c event_colors.c event_rot1.c event_rot2.c	\
			event_sounds.c event_zoom.c fill.c get_points_pos.c		\
			init_rot.c key_display.c manipulate.c projection.c		\
			rotate.c stock.c trace.c

INC =		fdf.h

SRCS =		$(SRC:%=$(SRCDIR)/%)

OBJS =		$(SRC:%.c=$(OBJDIR)/%.o)

INCS =		$(INC:%=$(INCDIR)/%)

LIBDIR =	./libft

LIBNAME =	libft.a

LIB =		$(LIBDIR)/$(LIBNAME)

LIBINC =	$(LIBDIR)

#------------------------------------------------------------------------------#

CC =		clang

CFLAGS =	-Wall			\
			-Wextra			\
			-Werror			\
			-g

INCFLAGS =	-I $(INCDIR)			\
			-I $(LIBINC)			\
			-I /usr/local/include

LFLAGS =	-L $(LIBDIR) -l$(LIBNAME:lib%.a=%)	\
			-L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

FLAGS =		$(CFLAGS)		\
			$(INCFLAGS)

#------------------------------------------------------------------------------#
# Primary rules

all:
	@$(MAKE) -C $(LIBDIR)
	@$(MAKE) $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) printname
	@printf "%-15s%s\n" Linking $@
	@$(CC) -o $@ $^ $(LFLAGS)
	@printf "$(GREEN)"
	@echo "Compilation done !"
	@printf "$(RES)"

$(OBJS): $(INCS) $(LIB)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(MAKE) printname
	@printf "%-15s%s\n" Compiling $@
	@$(CC) $(FLAGS) -o $@ -c $<

printname:
	@printf "$(ORANGE)"
	@printf "[%-15s " "$(NAME)]"
	@printf "$(RES)"

clean:
	@$(MAKE) printname
	@echo Suppressing obj files
	@printf "$(RED)"
	rm -rf $(OBJS)
	@rm -rf $(OBJDIR)
	@printf "$(RES)"

fclean: clean
	@$(MAKE) printname
	@echo Suppressing $(NAME)
	@printf "$(RED)"
	rm -rf $(NAME)
	@printf "$(RES)"

re: fclean
	@$(MAKE) all

#------------------------------------------------------------------------------#
# List of all my optionnals but usefull rules.

NORM = `norminette $(SRCS) $(INCS) | grep -B1 Error | cat`

no:
	@$(MAKE) printname
	@echo "Passage de la norminette :"
	@if [ "$(NORM)" == "`echo ""`" ];									\
		then															\
			echo "$(GREEN)Tous les fichiers sont a la norme !$(RES)";	\
		else															\
			echo "$(RED)$(NORM)$(RES)";									\
	fi

check: no

git:	# A rule to make git add easier
	@$(MAKE) printname
	@echo Adding files to git repository
	@printf "$(GREEN)"
	git add $(SRCS) $(INCS) Makefile
	git status
	@printf "$(RES)"

.PHONY: all clean re fclean git no check
