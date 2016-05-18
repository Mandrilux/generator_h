/*
** space.c for  in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Mon May 16 10:53:42 2016
** Last update Wed May 18 09:02:25 2016 
*/

#include "gen.h"

char    *init_str_2(char *str)
{
  char  *str_2;

  if ((str_2 = malloc(sizeof(char) * (strlen(str) + 1))) == NULL)
    return (NULL);
  memset(str_2, 0, strlen(str) + 1);
  return (str_2);
}

char    *rostring(char *str)
{
  int   i;
  int   j;
  char  *str_2;

  str_2 = init_str_2(str);
  i = 0;
  j = 0;
  while ((str[i] == ' ' || str[i] == '\t') && str[i++] != '\0');
  while (str[i] != '\0')
    {
      if ((str[i] == '\t' || str[i] == ' ')
          && (str[i + 1] != '\t' && str[i + 1] != ' ')
	  && str[i + 1] != '\0')
	str_2[j++] = ' ';
      else if (str[i] != ' ' && str[i] != '\t')
	str_2[j++] = str[i];
      i++;
    }
  str_2[j] = '\0';
  return (str_2);
}
