/*
** my_str_to_wordtab.c for str_wordtab in /home/willai-n/rendu/PSU_2015_minishell1
**
** Made by Willaime Noah
** Login   <willai-n@epitech.net>
**
** Started on  Fri Jan 22 16:13:23 2016 Willaime Noah
** Last update Sat Jun  4 15:13:09 2016 Willaime Noah
*/

#include <stdlib.h>
#include <string.h>

char	**my_str_to_wordtab2(char *str, char c)
{
  char	**array;
  int	n;
  int	x;
  int	y;

  n = 0;
  x = 0;
  array = malloc(sizeof (char *) * (strlen(str) + 1));
  while (str[n] != '\0')
    {
      if ((array[x] = malloc(sizeof (char) * (strlen(str) + 1))) == NULL)
	return (NULL);
      y = 0;
      while (str[n] == ' ')
	n++;
      while ((str[n] != c || str[n + 1] != c)
	     && (str[n] != '|' || str[n + 1] != '|') && str[n] != '\0')
	array[x][y++] = str[n++];
      array[x][y] = '\0';
      if (str[n] != '\0')
	n += 2;
      x++;
    }
  array[x] = NULL;
  return (array);
}
