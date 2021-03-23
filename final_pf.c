#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int i;
int ret;
int prec;
int width;

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_strlen(char *str)
{
	int l = 0;
	while (str[l])
		l++;
	return (l);
}

int ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int sign = 1;
	int atoi = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		atoi = atoi * 10 + str[i] - 48;
		i++;
	}
	return (atoi * sign);
}

int get_len(int n, int base)
{
	int len = 0;
	if (n <= 0) //inf ou = à 0 !
	{
		n = n * (-1);
		len++;
	}
	while (n > 0)
	{
		n = n / base;
		len ++;
	}
	return (len);
}

void	ft_putnbr_base(int n, char *base)
{
	int size = ft_strlen(base);
	if (n >= size)
		ft_putnbr_base((int)(n / size), base);
	ret += ft_putchar(base[n % size]);
}

int prints(char *str)
{
	int j = 0;
	if (!str)
	{
		if (!(str = malloc(sizeof(char) * 7)))
			return (0);
		str = "(null)";
	}
	int len = ft_strlen(str);
	if (prec != -1)
	{
		if (prec < len)
			len = prec;
	}
	width = width - len; // !!!!!!!!!!
	while (width > 0)
	{
		ret += ft_putchar(' ');
		width--;
	}
	while (str[j] && j < len)
	{
		ret += ft_putchar(str[j]);
		j++;
	}
	return (1);
}

int printx(unsigned long u)
{
	int len = get_len(u, 16);
	char base[17] = "0123456789abcdef";//malloc de 17 !
	width -= prec > 0 ? prec : len;
	prec = prec - len;
	if (u < 0 && prec >= 0)
	{
		prec++;
		width--;
	}
	while (width > 0)
	{
		ret += ft_putchar(' ');
		width--;
	}
	if (u < 0)
	{
		u = u * (-1);
		ret += ft_putchar('-');
	}
	while (prec > 0)
	{
		ret += ft_putchar('0');
		prec--;
	}
	ft_putnbr_base(u, base);
	return (1);
}

int printd(int n)
{
	int len = get_len(n, 10);
	char base[11] = "0123456789"; //malloc de 11 !
	width -= prec > 0 ? prec : len;
	prec = prec - len;
	if (n < 0 && prec >= 0)
	{
		prec++;
		width--;
	}
	while (width > 0)
	{
		ret += ft_putchar(' ');
		width--;
	}
	if (n < 0)
	{
		n = n * (-1);
		ret += ft_putchar('-');
	}
	while (prec > 0)
	{
		ret += ft_putchar('0');
		prec--;
	}
	ft_putnbr_base(n, base);
	return (1);
}

void	parse(va_list ap, char *str)
{
	width = 0;
	prec = -1;
	i++;
	if (ft_isdigit(str[i]))
		width = ft_atoi(str);
	if (str[i] == '.')
	{
		i++;
		if (ft_isdigit(str[i]))
			prec = ft_atoi(str);
		else
			prec = 0;
	}
	if (str[i] == 's')
		i += prints(va_arg(ap, char*));
	if (str[i] == 'x')
		i+= printx(va_arg(ap, unsigned long));
	if (str[i] == 'd')
		i += printd(va_arg(ap, int));
}

int ft_printf(const char *str, ...)
{
	va_list ap;
	i = 0;
	ret = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			parse(ap, (char *)str);
		if (str[i])
			ret += ft_putchar(str[i]);
		else
			break ;
		i++;
	}
	va_end(ap);
	return (ret);
}

int main()
{
	printf(" | ret = %d\n", printf("1)|%s", "1string"));
	printf(" | ret = %d\n", ft_printf("1)|%s", "1string"));

	printf(" | ret = %d\n", printf("2)|%s|", "AYAYA"));
	printf(" | ret = %d\n", ft_printf("2)|%s|", "AYAYA"));

	printf(" | ret = %d\n", printf("3)this string = |%s|", "Sample str"));
	printf(" | ret = %d\n", ft_printf("3)this string = |%s|", "Sample str"));

	printf(" | ret = %d\n", printf("4)string = |%20.8s|", "Sample str"));
	printf(" | ret = %d\n", ft_printf("4)string = |%20.8s|", "Sample str"));

	printf(" | ret = %d\n", printf("5)string = |%20.2s|", NULL));
	printf(" | ret = %d\n", ft_printf("5)string = |%20.2s|", NULL));

	printf(" | ret = %d\n", printf("6)string = |%.s|", NULL));
	printf(" | ret = %d\n", ft_printf("6)string = |%.s|", NULL));

	printf(" | ret = %d\n", printf("7)aaaa%30.20dabcdef", -100));
	printf(" | ret = %d\n", ft_printf("7)aaaa%30.20dabcdef", -100));

	printf(" | ret = %d\n", printf("8)aaaa%.5dabcdef", -100));
	printf(" | ret = %d\n", ft_printf("8)aaaa%.5dabcdef", -100));

	printf(" | ret = %d\n", printf("9)%5d", -123));
	printf(" | ret = %d\n", ft_printf("9)%5d", -123));

	printf(" | ret = %d\n", printf("10)%5d", 0));
	printf(" | ret = %d\n", ft_printf("10)%5d", 0));

	printf(" | ret = %d\n", printf("%5d", 1));
	printf(" | ret = %d\n", ft_printf("%5d", 1));

	printf(" | ret = %d\n", printf("%d", 0));
	printf(" | ret = %d\n", ft_printf("%d", 0));

	printf(" | ret = %d\n", printf("%x", 42));
	printf(" | ret = %d\n", ft_printf("%x", 42));

	printf(" | ret = %d\n", printf("%20.10x", 42));
	printf(" | ret = %d\n", ft_printf("%20.10x", 42));

	printf(" | ret = %d\n", printf("%20.10x", 42981234));
	printf(" | ret = %d\n", ft_printf("%20.10x", 42981234));

	printf(" | ret = %d\n", printf("yo %45"));
	printf(" | ret = %d\n", ft_printf("yo %45"));
	return (1);
}

