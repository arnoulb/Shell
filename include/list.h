/*
** list.h for  in /home/arnould_b/rendu/CPE_2015_Pushswap
**
** Made by jean-michel arnould
** Login   <arnould_b@epitech.net>
**
** Started on  Wed Nov 18 15:52:14 2015 jean-michel arnould
** Last update Thu Jan 21 14:06:38 2016 Arnould Jean-Michel
*/

#ifndef LIST_H_
#define LIST_H_

typedef struct	s_list
{
  char		*name;

  struct s_list	*next;
  struct s_list *prev;

} t_list;

void	add_queue(t_list *, char *);
void	add_head(t_list *, char *);
void	delete_elem(t_list *);
t_list	*create_list();
void	my_show_list(t_list *);
void	frend(t_list *);

#endif
