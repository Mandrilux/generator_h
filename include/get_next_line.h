/*
** get_next_line.h for  in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Mon May 16 11:31:25 2016
** Last update Tue May 17 19:04:58 2016 
*/

#ifndef _GETNEXTLINE_H_
#define _GETNEXTLINE_H_

#ifndef READ_SIZE
#define READ_SIZE (100)
#endif


void    init(int *nb2, int *nb);
char	*m_realoc(char *s, int fillback, char *buff, int *start);
char	*get_next_line(const int fd);

#endif
