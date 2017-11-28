/*
** redirection2.c for  in /home/daelomin/rendu/PSU/PSU_2015_42sh
**
** Made by ARNOULD Jean-Michel
** Login   <daelomin@epitech.net>
**
** Started on  Fri Jun  3 21:19:21 2016 ARNOULD Jean-Michel
** Last update Tue Jun  7 18:08:19 2016 ARNOULD Jean-Michel
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"
#include "function.h"

int	is_redir_left(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i])
    {
      if (is_same(tab[i], "<" )|| is_same(tab[i], "<<"))
	return (1);
    }
  return (0);
}

int	is_redir(char **tab)
{
  int	i;
  int	value;
  i = -1;
  while (tab[++i])
    {
      if (is_same(tab[i], "<" )|| is_same(tab[i], "<<"))
	return (1);
      if (is_same(tab[i], ">") || is_same(tab[i], ">>"))
	return (1);
    }
  return (0);
}

void	redir_lol(char **cmd)
{
  int	i;
  int	test;

  i = -1;
  test = 1;
  while (cmd[++i] && test)
    {
      if (is_same(cmd[i], ">") || is_same(cmd[i], ">>")
	  || is_same(cmd[i], "<") || is_same(cmd[i], "<<"))
	test = 0;
    }
  cmd[i - 1] = 0;
}

int	is_redir_right(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i])
    {
      if (is_same(tab[i], ">") || is_same(tab[i], ">>"))
	return (1);
    }
  return (0);
}
