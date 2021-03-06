# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibanez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/03 11:59:13 by jibanez           #+#    #+#              #
#    Updated: 2015/05/29 13:05:47 by jibanez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

# Directories

SRCDIR = sources
OBJDIR = objects
INCDIR = includes

MAINDIR = $(SRCDIR)/main
CAMDIR = $(SRCDIR)/camera
RENDERDIR = $(SRCDIR)/render
VECTORDIR = $(SRCDIR)/vector
MATRIXDIR = $(SRCDIR)/matrix

# Libraries

LIBFT = libft

# Format

GREEN = \x1b[32;01m
ORANGE = \x1b[33;01m
STOP_COLOR = \x1b[0m
OK = $(GREEN)--> [OK]$(STOP_COLOR)
INFO = @echo "Compile $< to $@ $(OK)"

# Compilation / Linking

CC = clang
CFLAGS = -Wall -Wextra -Werror
OFLAGS =
IFLAGS = -I$(INCDIR) -I$(LIBFT)/includes
LFLAGS = -L$(LIBFT) -lft -lm \
		 -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

COMPIL = $(CC) $(CFLAGS) $(OFLAGS) $(IFLAGS) -o $@ -c $<
LINK = $(CC) $(LFLAGS) -o $@ $^

# Include sources.mk

include $(MAINDIR)/sources.mk
include $(CAMDIR)/sources.mk
include $(RENDERDIR)/sources.mk
include $(VECTORDIR)/sources.mk
include $(MATRIXDIR)/sources.mk

POBJ = $(addprefix $(OBJDIR)/, $(OBJ))


# Rules

.PHONY: all clean re fclean libft

all: $(OBJDIR) $(LIBFT) $(NAME)

$(NAME): $(POBJ)
	$(LINK)
	@echo "$(GREEN)--> [Done!] --> ./$@ $(STOP_COLOR)"

$(OBJDIR):
	@mkdir $(OBJDIR)
	@echo "$(ORANGE)Create $(OBJDIR) directory$(STOP_COLOR)"

$(LIBFT):
	make -C $(LIBFT)

clean:
	@$(RM) $(OBJDIR)
	@echo "$(ORANGE)Remove $(OBJDIR) directory$(STOP_COLOR)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(GREEN)--> [Clean!]$(STOP_COLOR)"

re: fclean all
