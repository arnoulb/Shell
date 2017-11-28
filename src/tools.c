/*
** tools.c for  in /home/daelomin/rendu/PSU/PSU_2015_minishell1
**
** Made by Arnould Jean-Michel
** Login   <daelomin@epitech.net>
**
** Started on  Sat Jan 23 11:26:43 2016 Arnould Jean-Michel
** Last update Fri Jun  3 13:29:10 2016 ARNOULD Jean-Michel
*/

#include <stdlib.h>
#include "my.h"
#include "function.h"

int	is_same(char *str, char *str2)
{
  int	i;

  i = 0;
  if (my_strlen(str) != my_strlen(str2))
    return (0);
  while (str[i] && str2[i])
    {
      if (str[i] != str2[i])
	return (0);
      ++i;
    }
  return (1);
}

int	replace(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] && str2[i])
    {
      if (str1[i] != str2[i])
	return (0);
      ++i;
    }
  return (1);
}

int	is_valid(char *str)
{
  int	i;
  int	test;
  int	test2;

  i = 0;
  test = 0;
  test2 = 0;
  while (str[i])
    {
      if (str[i] == '-')
	++test;
      if (str[i] == '.')
	++test2;
      ++i;
    }
  if (test > 1 || test2 > 0)
    return (0);
  else
    return (1);
}

void	my_exit(char **tab, char **env)
{
  int	i;

  if (my_str_isnum(tab[1]) && is_valid(tab[1]) && tab[2] == NULL)
    {
      i = my_getnbr(tab[1]);
      free_all(tab, env);
      exit(i % 256);
    }
  else
    {
      my_printf("exit: Expression Syntax.\n");
      return ;
    }
}

char	*concat(char *str, char *str2)
{
  int	i;
  int	j;
  char	*tmp;

  if (str == 0 || str2 == 0)
    return (NULL);
  i = 0;
  j = 0;
  tmp = malloc(sizeof (char) * (my_strlen(str) + my_strlen(str2) + 1));
  while (str[i])
    {
      tmp[j] = str[i];
      i++;
      j++;
    }
  i = 0;
  while (str2[i])
    {
      tmp[j] = str2[i];
      i++;
      j++;
    }
  tmp[j] = 0;
  return (tmp);
}
