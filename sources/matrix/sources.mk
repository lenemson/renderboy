# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibanez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/22 14:53:37 by jibanez           #+#    #+#              #
#    Updated: 2015/05/23 13:57:26 by jibanez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MATRIX = matrix_product.c \
		 mult_matrix_vector.c \
		 mult_matrix_vertex.c \
		 get_trans_matrix.c \
		 get_scale_matrix.c \
		 get_identity_matrix.c \
		 get_rot_matrix.c

OBJ += $(MATRIX:.c=.o)

$(OBJDIR)/%.o: $(MATRIXDIR)/%.c
	$(COMPIL)
	$(INFO)
