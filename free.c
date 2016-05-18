/*
** check.c for  in /home/baptiste/rendu/marvin_heraud_b
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Fri May 13 22:16:55 2016
** Last update Wed May 18 09:01:51 2016 
*/

#include "gen.h"

int	free_tab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i] != NULL)
    free(tab[i]);
  free(tab);
  return (1);
}

int	free_two_tab(char **tab1, char **tab2)
{
  free_tab(tab1);
  free_tab(tab2);
  return (1);
}
