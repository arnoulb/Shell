/*
** compt.c for compt in /home/willai-n/PSU_2015_42sh
**
** Made by Willaime Noah
** Login   <willai-n@epitech.net>
**
** Started on  Sat Jun  4 14:59:08 2016 Willaime Noah
** Last update Sat Jun  4 19:28:58 2016 Willaime Noah
*/

#include <stdlib.h>

int	compt(char *cmd)
{
  int	i;
  int	compteur;

  i = 0;
  compteur = 0;
  while (cmd[i])
    {
      if (cmd[i] == '&' && cmd[i + 1] == '&')
	compteur++;
      else if (cmd[i] == '|' && cmd[i + 1] == '|')
	compteur++;
      i++;
    }
  return (i);
}

char	*how_many(char *cmd)
{
  int	i;
  char	*tab;
  int	a;

  a = 0;
  i = compt(cmd);
  if ((tab = malloc(sizeof (char) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  while (cmd[i])
    {
      if (cmd[i] == '&' && cmd[i + 1] == '&')
	{
	  tab[a] = '&';
	  a++;
	}
      else if (cmd[i] == '|' && cmd[i + 1] == '|')
	{
	  tab[a] = '|';
	  a++;
	}
      i++;
    }
  tab[a] = '\0';
  return (tab);
}
