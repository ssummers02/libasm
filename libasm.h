#ifndef LIBASM_H
#define LIBASM_H

# include <string.h>
# include <strings.h>
# include <fcntl.h>
# include <unistd.h>
# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>

char *ft_strdup(const char *s);

ssize_t ft_read(int fd, void *buf, size_t count);

size_t ft_strlen(const char *str);

ssize_t ft_write(int fd, const void *buf, size_t count);

int ft_strcmp(const char *s1, const char *s2);

char *ft_strcpy(char *dest, const char *src);

#endif
