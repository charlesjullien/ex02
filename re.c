int get_len(int n, int base)
{
	int len = 0;
	if (n <= 0) // inf OU EGAL !!!!!!!!!!!!!!!!!!
	{
		n = n * (-1);
		len++;
	}
	while (n > 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

int printd(int n)
{
	int len = get_len(n, 10);
	char base[11] = "0123456789";
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
		ret += ft_putchar('-');
		n = n * (-1);
	}
	while (prec > 0)
	{
		ret += ft_putchar('0');
		prec--;
	}
	ft_putnbr_base(n, base);
	return (1);
}

int prints(char *str)
{
	int j = 0;
	if (!str)
	{
		str = malloc(sizeof(char) * 7);
		str = "(null)";
	}
	int len = ft_strlen(str);
	if (prec != -1)
	{
		if (prec < len)
			len = prec;
	}
	width = width - len;
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
