#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int get_word(char *buf, int buf_size, FILE *fp)
{
	int len;
	int ch;
  /*跳过读取空白部分*/
	while((ch = getc(fp)) != EOF && !isalpha(ch))
		;
	if(ch == EOF)
		return EOF;
		
  /*此时ch中保存了单词的初始字符。*/
	len = 0;
	do {
		buf[len++] = ch;
		if(len >= buf_size)            //读取的单词长度不超过256
		{
			printf("word too long.\n");
			exit(1);
		}
	} while((ch = getc(fp)) != EOF && isalpha(ch));

	buf[len] = '\0';
	return len;
}


int main()
{
	char buf[256];
	FILE *fp = fopen ("D:\\Documents\\Desktop\\求职之路\\test.txt", "r");

    while(get_word(buf,256,fp) != EOF)
		printf("%s\n", buf);

	return 0;
}
