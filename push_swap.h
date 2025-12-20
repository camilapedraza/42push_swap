/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:49:36 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/20 23:34:56 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>
# include <unistd.h>

# define B_INIT_SIZE 2

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_moveset
{
	size_t	cost;
	size_t	a_cost;
	int		a_dir;
	size_t	b_cost;
	int		b_dir;
}	t_moveset;

/* MAIN FUNCTIONS */
char		*parse_input(int n, char **argv);
t_stack		*build_a_stack(char *string, t_stack **a_stack);
void		quit_push_swap(t_stack **a_stack);

/* SORT INSTRUCTIONS */
void		push(t_stack **src, t_stack **dest);
void		rotate(t_stack **stack);
void		reverse_rotate(t_stack **stack);
void		rotate_both(t_stack **stack_1, t_stack **stack_2);
void		reverse_rotate_both(t_stack **stack_1, t_stack **stack_2);

/* FIND NODES */
t_stack		*find_max(t_stack *stack);
t_stack		*find_target(int n, t_stack *stack);
size_t		find_node_position(int n, t_stack *stack);

/* CALCULATE MOVES */
void		init_moveset(t_moveset *moves);
void		find_dest_moves(t_moveset *moves, int d, t_stack *dest);
void		find_src_moves(t_moveset *moves, int s, t_stack *src);
t_moveset	find_cost(int s, t_stack *src, int d, t_stack *dest);
t_moveset	find_best_moves(t_stack **a_stack, t_stack **b_stack);

/* EXECUTE ROTATIONS */
void		sync_rotations(t_stack **src, t_stack **dest, t_moveset *moves);
void		b_rotations(t_stack **dest, t_moveset *moves);
void		a_rotations(t_stack **src, t_moveset *moves);
void		execute_rotations(t_stack **src, t_stack **dest, t_moveset moves);

/* UTILITIES: ALLOCATE MEMORY */
void		*ft_calloc(size_t nmemb, size_t size);

/* UTILITIES: CHECKERS*/
int			is_space(int c);
int			is_digit(int c);
int			is_integer(const char *nptr);
int			is_sorted(t_stack *stack);

/* UTILITIES: STACK OPERATIONS */
void		stack_free(t_stack **stack);
t_stack		*stack_new(int value);
void		stack_add_back(t_stack **stack, t_stack *new);
size_t		stack_size(t_stack *stack);
t_stack		*stack_reverse_find(t_stack *stack, int item);

/* UTILITIES: STRINGS */
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlcpy(char *dst, const char *src, size_t siz);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t siz);

#endif