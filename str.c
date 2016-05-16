/*
** str.c for  in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Mon May 16 13:11:00 2016
** Last update Mon May 16 13:39:59 2016 
*/

#include "gen.h"

char	*format_str(char *str)
{
  char	*tmp;
  char	**cut;
  int	i = -1, len_tmp = 0, nb_elm, len;

  len  = strlen(str);
  if ((tmp = malloc(sizeof(char) * (len + 4))) == NULL)
    return (NULL);
  memset(tmp, '\0', len + 4);
  if ((cut = strtowordtab(str, '(')) == NULL)
    return (NULL);
  if ((cut = strtowordtab(cut[0], ' ')) == NULL)
    return (NULL);
  nb_elm = count_tab(cut);
  while (++i < nb_elm)
    {
      if (i + 1 != nb_elm)
	  len_tmp += strlen(cut[i]) + 1;
    }
  len_tmp -= 1;
  strncat(tmp, str, len_tmp);
  strcat(tmp, "\t\t");
  strcat(tmp, &(str[len_tmp]));
  strcat(tmp, ";");
  free(str);
  return (tmp);
}

char	*get_name_file(char *name)
{
  char	*tmp;
  int	len;

  len = strlen(name);
  if ((tmp = malloc(sizeof(char) * (len + 10))) == NULL)
    return (NULL);
  memset(tmp, '\0', len + 10);
  return (tmp);
}
