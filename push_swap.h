/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <melayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:48:34 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/13 18:49:15 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
	int				index;
	struct s_list	*target;
	int				rank;
	int				price;
}					t_list;

typedef struct s_mins
{
	int				min_a;
	int				min_b;
}					t_mins;

void				sort_five(t_list **stack_a, t_list **stack_b);
void				sort_three(t_list **stack_a);
void				sort_me(t_list **sa, t_list **sb);
char				**extract_all_tokens(int ac, char **av);
void				free_tokens(char **tokens);
int					has_number(char *str);
int					count_tokens(int ac, char **av);
char				**ft_free(char **src, int size);
char				**ft_split(char const *s, char c);
int					handel_error(char **str);
char				*ft_strdup(const char *s);
int					is_sorted(t_list *head);
void				rrr(t_list **stack_a, t_list **stack_b);
t_list				*find_less(t_list *stack_b, t_list *stack_a);
void				give_index(t_list *stack);
void				free_stack(t_list **stack);
void				give_rank(t_list *stack_a);
int					ft_lstsize(t_list *lst);
void				give_target(t_list *stack_a, t_list *stack_b);
int					finde_max(t_list *stack);
t_list				*find_min(t_list *stack);
void				give_value(t_list **head, char **str);
t_list				*get_last_stack(t_list **stack);
void				rr(t_list **stack_a, t_list **stack_b);
void				rrb(t_list **stack_b);
void				rra(t_list **stack_a);
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_a, t_list **stack_b);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
#endif
