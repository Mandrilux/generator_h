/*
1;2802;0c** read.c for  in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Mon May 16 11:19:53 2016
** Last update Mon May 16 13:26:44 2016 
*/

#include "gen.h"

int	check_is_proto(char *str)
{
  int	nb;
  if ((nb = check_parenthesis(str)) != 2)
    return (-1);
  if (str[strlen(str) - 1] == ')')
    {
      if (is_no_op(str) != -1)
	{
	  if (check_not_key_word(str) == 0)
	    return (1);
	  else
	    return (-1);
	}
      else
	return (-1);
    }
  else
    return (-1);
}

int     check_parenthesis(char *str)
{
  int   i;
  int   nb_o;
  int   nb_c;

  nb_o = 0;
  nb_c = 0;
  i = -1;
  while (str[++i] != '\0')
    {
      if (str[i] == '(')
	nb_o++;
      if (str[i] == ')')
	nb_c++;
    }
  if (nb_o != nb_c)
    return (-1);
  else
    return (nb_o + nb_c);
}

int	is_no_op(char *str)
{
  int	i = -1;

  while (str[++i] != '\0')
    {
      if (str[i] == '=')
	return (-1);
    }
  return (1);
}

int	check_not_key_word(char *str)
{
  int	flag = 0;

  if (strstr(str,"while") != NULL)
    flag++;
  else if (strstr(str,"if") != NULL)
    flag++;
  else if (strstr(str,"else") != NULL)
    flag++;
  else if (strstr(str,"else if") != NULL)
    flag++;
  else if (strstr(str,"for") != NULL)
    flag++;
  else if (strstr(str, "case") != NULL)
    flag++;
  else if (strstr(str, "default") != NULL)
    flag++;
  else if (strstr(str, "break") != NULL)
    flag++;
  else
    flag = flag + 0;
  return (flag);
}

int     count_tab(char **tab)
{
  int   i;

  i = -1;
  while (tab[++i] != NULL);
  return (i);
}
