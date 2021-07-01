#include <stdlib.h>

int	ft_strlen(char *str);
int	ft_base_check(char *base);
int	ft_atoi_base(char *str, char *base);

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (1)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
			break ;
		i += 1;
	}
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;

	len = ft_strlen(src);
	dest = (char *) malloc(sizeof(char) * (len + 1));
	if (NULL == dest)
		return (NULL);
	return (ft_strcpy(dest, src));
}

char	*ft_strrev(char *str)
{
	int		len;
	int		i;
	char	tmp;

	len = ft_strlen(str);
	len -= 1;
	i = 0;
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i += 1;
		len -= 1;
	}
	return (str);
}

char	*ft_itoa_base(int nb, char *base, int base_len)
{
	char		nbr_new[35];
	long int	n;
	int			i;
	int			sign;

	n = nb;
	i = 0;
	sign = 1;
	if (n < 0)
	{
		n = -n;
		sign = -1;
	}
	if (n == 0)
		nbr_new[i++] = base[0];
	while (n > 0)
	{
		nbr_new[i++] = base[n % base_len];
		n = n / base_len;
	}
	if (sign == -1)
		nbr_new[i++] = '-';
	nbr_new[i] = '\0';
	return (ft_strdup(nbr_new));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	n;
	int			base_len;
	char		*n_new;

	base_len = ft_base_check(base_to);
	if (ft_base_check(base_from) < 2 || base_len < 2)
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	n_new = ft_itoa_base(n, base_to, base_len);
	return (ft_strrev(n_new));
}
