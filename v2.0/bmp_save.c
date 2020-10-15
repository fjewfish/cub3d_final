#include "main_header_v2.h"

void	ft_bdata(t_aio *s, int fd)
{
	int				i;
	int				j;
	unsigned char	buffer[4];

	i = s->res.map_x * (s->res.map_y - 1);
	while (i >= 0)
	{
		j = 0;
		while (j < s->res.map_x)
		{
			buffer[0] = (unsigned char)(s->img.adr[i] % 256);
			buffer[1] = (unsigned char)(s->img.adr[i] / 256 % 256);
			buffer[2] = (unsigned char)(s->img.adr[i] / 256 / 256 % 256);
			buffer[3] = (unsigned char)(0);
			write(fd, buffer, 4);
			i++;
			j++;
		}
		i -= 2 * s->res.map_x;
	}
}

void	ft_binfo(t_aio *s, int fd)
{
	int				n;
	unsigned char	header[40];

	n = 0;
	while (n < 40)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(40);
	n = s->res.map_x;
	header[4] = (unsigned char)(n % 256);
	header[5] = (unsigned char)(n / 256 % 256);
	header[6] = (unsigned char)(n / 256 / 256 % 256);
	header[7] = (unsigned char)(n / 256 / 256 / 256);
	n = s->res.map_y;
	header[8] = (unsigned char)(n % 256);
	header[9] = (unsigned char)(n / 256 % 256);
	header[10] = (unsigned char)(n / 256 / 256 % 256);
	header[11] = (unsigned char)(n / 256 / 256 / 256);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	write(fd, header, 40);
}

void	ft_bfile(t_aio *s, int fd)
{
	int				n;
	unsigned char	header[14];

	n = 0;
	while (n < 14)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(66);
	header[1] = (unsigned char)(77);
	n = s->res.map_x * s->res.map_y * 3;
	header[2] = (unsigned char)(n % 256);
	header[3] = (unsigned char)(n / 256 % 256);
	header[4] = (unsigned char)(n / 256 / 256 % 256);
	header[5] = (unsigned char)(n / 256 / 256 / 256);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
}

int		ft_bmp_save(t_aio *aio)
{
	int		fd;

	ft_screen(aio);
	fd = open("bitmap.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	ft_bfile(aio, fd);
	ft_binfo(aio, fd);
	ft_bdata(aio, fd);
	close(fd);
	// free(aio->img.ptr);
	// free(aio->img.adr);
	ft_close(aio, 0);
	return (1);
}
