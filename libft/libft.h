/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelle <amelle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:01:06 by Avandeve          #+#    #+#             */
/*   Updated: 2024/07/03 18:16:19 by amelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdarg.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_checkspaces(char c);
int		ft_checkdigits(char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *nptr);
int		ft_lstsize(t_list *lst);
int		ft_checkspaces(char c);
int		ft_checkdigits(char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_free(char **words_array, int count);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void	*dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nbemb, size_t size);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_free(char **words_array, int count);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
t_list	*ft_lstnew(void	*content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *));

//Functions for printf
int		ft_printf(const char *format, int fd, ...);
int		check_format(va_list ap, const char c, int fd);
int		ft_countdigits_hex(unsigned int nb, char c);
int		ft_countdigits_unsigned(unsigned int nb);
int		ft_countdigits_ptraddress(void *ptr);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_countdigits(int nb);
void	ft_putnbr(int nb);
void	ft_putusnbr(unsigned int nb);
void	ft_puthex(unsigned int nb, char c);
void	ft_puthexupper(int nb);
void	ft_putptraddress(unsigned long ptr);

//Functions for GNL
/*
char	*get_next_line(int fd);
char	*read_file(int fd, char *reading_buf, char *stash);
char	*separate_line(char *buf);
char	*ft_substr2(char *s, int start, int len);
char	*ft_strchr2(char *s, char c);
size_t	ft_strlen(char const *str);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strjoin2(char const *s1, char const *s2);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
*/

#endif
