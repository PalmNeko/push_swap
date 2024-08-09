# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    checker.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 23:41:56 by marvin            #+#    #+#              #
#    Updated: 2024/08/09 18:21:29 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
CC = cc
SRC = \
	./checker_main_bonus.c \
	./algorithm/ps_push_to_a_until.c \
	./algorithm/ps_push_to_b_until.c \
	./algorithm/ps_push_to_target_at_sorted_place.c \
	./algorithm/ps_push_to_target_at_sorted_place_until_remaind.c \
	./algorithm/ps_quick_sort.c \
	./algorithm/ps_rotate_target_to_right_order.c \
	./algorithm/ps_sort_between_3and5.c \
	./algorithm/ps_sort_to_serial_number_only_top_three.c \
	./algorithm/ps_swap_target_stack_if_needed.c \
	./algorithm/ps_turk_sort.c \
	./calculators/ps_calc_rotate_cost.c \
	./calculators/ps_convert_min_pos.c \
	./calculators/ps_get_func_get_insert_pos.c \
	./calculators/ps_get_insert_pos_asc.c \
	./calculators/ps_get_insert_pos_desc.c \
	./calculators/ps_get_max_value.c \
	./calculators/ps_get_min_value.c \
	./calculators/ps_get_other_target.c \
	./calculators/ps_get_target_command.c \
	./calculators/ps_get_target_size.c \
	./calculators/ps_get_target_stack.c \
	./calculators/ps_get_value.c \
	./controllers/ps_append_cmdlst.c \
	./controllers/ps_clone_cmdlst.c \
	./controllers/ps_clone_ps.c \
	./controllers/ps_clone_stack.c \
	./controllers/ps_destroy_cmldlst.c \
	./controllers/ps_destroy_command.c \
	./controllers/ps_destroy_ps.c \
	./controllers/ps_destroy_stack.c \
	./controllers/ps_get_cmdlst.c \
	./controllers/ps_get_stack.c \
	./controllers/ps_new_cmdlst.c \
	./controllers/ps_new_command.c \
	./controllers/ps_new_ps.c \
	./controllers/ps_new_stack.c \
	./controllers/ps_pa.c \
	./controllers/ps_pb.c \
	./controllers/ps_pop_stack.c \
	./controllers/ps_push_stack.c \
	./controllers/ps_ra.c \
	./controllers/ps_rb.c \
	./controllers/ps_rr.c \
	./controllers/ps_rra.c \
	./controllers/ps_rrb.c \
	./controllers/ps_rrr.c \
	./controllers/ps_sa.c \
	./controllers/ps_sb.c \
	./controllers/ps_ss.c \
	./controllers/ps_swap_stack.c \
	./logics/ps_compress_cmdlst.c \
	./logics/ps_main.c \
	./logics/ps_print_cmdlst.c \
	./logics/ps_print_error.c \
	./logics/ps_print_ps.c \
	./logics/ps_push_swap_sort.c \
	./modules/ps_at.c \
	./modules/ps_compress_command.c \
	./modules/ps_compress_commands.c \
	./modules/ps_push_target_until.c \
	./modules/ps_renumber.c \
	./modules/ps_rotate_two_stack.c \
	./modules/ps_rotate_two_way.c \
	./modules/ps_run_sort_seq.c \
	./modules/ps_run_to_times.c \
	./modules/ps_str_to_int_array.c \
	./modules/ps_swap_target.c \
	./validators/ps_validate_is_sorted.c \
	./validators/ps_validate_no_duplicates.c

OBJS = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)
CACHE_DIR = cache
CFLAGS += -g -O0 -fsanitize=leak -Wall -Werror -Wextra -MP -MMD -I. -I./Libft

LIBFT_DIR ?= Libft
LIBFT = libft.a
LIBS += $(LIBFT_DIR)/$(LIBFT)
LDLIBS += -l ft
LDFLAGS += -L $(LIBFT_DIR)

all: $(NAME)

clean:
	rm -rf $(CACHE_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

show:
	@printf "%s\n \t%s\n" "SRC" "$(SRC)"
	@printf "%s\n \t%s\n" "OBJS" "$(OBJS)"
	@printf "%s\n \t%s\n" "DEPS" "$(DEPS)"
	@printf "%s\n \t%s\n" "CFLAGS" "$(CFLAGS)"
	@printf "%s\n \t%s\n" "LDFLAGS" "$(LDFLAGS)"
	@printf "%s\n \t%s\n" "LIBS" "$(LIBS)"

-include $(addprefix $(CACHE_DIR)/,$(DEPS))

$(NAME): $(LIBS) $(addprefix $(CACHE_DIR)/,$(OBJS))
	$(CC) $(LDFLAGS) -o $@ $(filter %.o,$^) $(LDLIBS)

$(CACHE_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -MF $(CACHE_DIR)/$*.d -o $@ -c $<

$(LIBFT_DIR)/$(LIBFT): $(LIBFT_DIR)
	make -C "$(LIBFT_DIR)"

$(LIBFT_DIR):
	git clone https://github.com/PalmNeko/Libft
