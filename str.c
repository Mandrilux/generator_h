/*
** str.c for  in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Mon May 16 13:11:00 2016
** Last update Mon May 16 13:16:24 2016 
*/

#include "gen.h"

char	*format_str(char *str)
{
  int	len;
  char	*tmp;

  len  = strlen(str);
  if ((tmp = malloc(sizeof(char) * (len + 4))) == NULL)
    return (NULL);
  memset(tmp, '\0', len + 4);
  strcat(tmp, str);
  strcat(tmp, ";");
  free(str);
  return (tmp);
}
