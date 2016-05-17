/*
** main.c for  in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Mon May 16 10:48:51 2016
** Last update Tue May 17 19:55:07 2016 
*/

#include "gen.h"

int		main(int ac, char **av)
{
  DIR		*rep;
  t_core	*core;
  char		*tmp;

  if (ac == 1)
    tmp = strdup("my.h");
  else
    tmp = av[1];
  if (is_a_header_file(tmp) == -1)
    return (printf("Error : this file is not header file\n"));
  if ((tmp = add_include(tmp)) == NULL)
    return (printf("Error : R.A.M was attacked !\n"));
  if ((core = init_core(av[0], tmp)) == NULL)
    return (printf("Error : R.A.M was attacked !\n"));
  init_all_h(core);
  if (read_h(core, core->name_h) == -1)
    return (EXIT_FAILURE);
  write_def_top(core);
  if (directory_open(core, &rep) == -1)
    return (EXIT_FAILURE);
  display_directory(core, &rep);
  write_def_bottom(core);
  while_not_clean(core);
  printf("[+] Generation %s successful\n", core->name_h);
  return (1);
}

int		directory_open(t_core *core, DIR **rep)
{
  *rep = opendir(".");
  if (*rep == NULL)
    {
      perror(core->name_prog);
      return (-1);
    }
  else
    return (1);
}

int    display_directory(t_core *core, DIR **rep)
{
  struct dirent *ent;

  if (*rep != NULL)
    {
      while ((ent = readdir(*rep)) != NULL)
	{
	  if (strlen(ent->d_name) > 2)
	    {
	      if (strcmp(&(ent->d_name[strlen(ent->d_name) - 2]), TYPE_F) == 0)
		read_file(core, ent->d_name);
	    }
	}
      closedir(*rep);
    }
  return (1);
}
