/*
** errors2.c for  in /home/daelomin/rendu/PSU/PSU_2015_minishell1
**
** Made by Arnould Jean-Michel
** Login   <daelomin@epitech.net>
**
** Started on  Sun Jan 31 22:55:36 2016 Arnould Jean-Michel
** Last update Sun Jun  5 18:33:46 2016 ARNOULD Jean-Michel
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
#include "function.h"

int	argument(char **tab, char ***env)
{
  int	b;

  b = argument2(tab, env);
  return (b);
}

void	error_seg(int child, char **tab)
{
  int	i;

  if (WIFSIGNALED(child))
    {
      if (WTERMSIG(child) == SIGSEGV)
	{
	  my_printf("[1]\tSegmentation Fault (core dumped) ");
	  i = 0;
	  while (tab[i])
	    my_printf("%s ", tab[i++]);
	  my_printf("\n");
	}
      else if (WCOREDUMP(child))
	{
	  my_printf("[1]\t(core dumped) ");
	  i = 0;
	  while (tab[i])
	    my_printf("%s ", tab[i++]);
	  my_printf("\n");
	}
    }
}

int	is_good(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] < ' ' && str[i] != '\t')
	return (0);
      i++;
    }
  return (1);
}

int	is_exec(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '/')
	return (1);
      ++i;
    }
  return (0);
}
