#include <termios.h>
#include <termcap.h>
#include <unistd.h> /* write */
#include <stdlib.h> /* getenv */
#include <stdio.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/stat.h>>
#include <fcntl.h>
#include <unistd.h>

int tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void sig_handler(int signo)
{
	char			buffer[2048];
	struct			termios	term;
	char			read_char[4] = {0};

	if (signo == SIGCONT)
	{
		tcgetattr(0, &term);
		term.c_lflag &= ~(ECHO); /* prevents a char from being output when pressed*/
		term.c_lflag &= ~(ICANON); /* each char is treated independently */
		tcsetattr(0, 0, &term);
		tputs(tgetstr("ti", NULL), 1, tputs_putchar);
	}
}


int main(void)
{
	char			buffer[2048];
	struct			termios	term;
	char			read_char[4] = {0};
	int				fd;
	int				sigstop = SIGSTOP;

	signal(SIGCONT, sig_handler);
	fd = open(ttyname(0), O_RDONLY);
	if (tgetent(buffer, getenv("TERM")) < 1)
		return (-1);
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON); /* each char is treated independently */
	term.c_lflag &= ~(ECHO); /* prevents a char from being output when pressed*/
	tcsetattr(0, 0, &term);
	tputs(tgetstr("ti", NULL), 1, tputs_putchar);
	tputs(tgetstr("mr", NULL), 1, tputs_putchar); /* turns on reverse video */
	write(1, "reverse video", 13);
	tputs(tgetstr("me", NULL), 1, tputs_putchar); /* turns off all */
	tputs(tgetstr("do", NULL), 1, tputs_putchar); /* cursor down one line */
	write(1, "normal", 7);
	tputs(tgetstr("do", NULL), 1, tputs_putchar); /* cursor down one line */
	while (1)
	{
		read(0, read_char, 3);
		if (is_rtn(read_char))
		{
			//term.c_lflag = (ICANON | ECHO);
			tcsetattr(0, 0, &term); /* back to default values */
			tputs(tgetstr("te", NULL), 1, tputs_putchar);
			return (1);
		}
		if (is_arrow(read_char))
			printf("Todo\n");
		else
			printf("%d %d %d\n", read_char[0], read_char[1], read_char[2]);
	}
	return (0);
}

int	is_rtn(char *buf)
{
	return (buf[0] == 10);
}

int	is_arrow(char *buf)
{
	int	rslt;
	if (buf[0] != 27 || buf[1] != 91)
		return (0);
	if (buf[2] == 65)
		return (1);
	if (buf[2] == 66)
		return (2);
	if (buf[2] == 67)
		return (3);
	if (buf[2] == 68)
		return (4);
	else
		return (0);
}

int	is_bgreq(char *buf)
{
	if (buf[0] == 26)
		return (1);
	else
		return (0);
}

