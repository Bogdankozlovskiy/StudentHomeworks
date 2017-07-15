#include<iostream>
#include <stdio.h>
#include <stdlib.h>

void PrintHTML1(const char* text, int mask)
{
	if (mask & 1)
		printf("<B>");
	if (mask & 2)
		printf("<I>");
	if (mask & 4)
		printf("<U>");
	printf("%s", text);
	if (mask & 4)
		printf("</U>");
	if (mask & 2)
		printf("</I>");
	if (mask & 1)
		printf("</B>\n");
}

union coding 
{
	int cod;
	struct byt
	{
		unsigned char bold : 1;
		unsigned char italic : 1;
		unsigned char underline : 1;
		unsigned char hralign : 3;
		unsigned char sto;
	}bytes;
};

enum hr_align
{
	left = 1,
	center = 2,
	right = 3,
	justify = 4
};

enum {bold_off,bold_on};
enum {italic_off,italic_on};
enum {underline_off,underline_on};

union coding create(char sto,char hralign,bool underline,bool italic,bool bold)
{
	union coding coddigit;
	coddigit.bytes.bold = bold;
	coddigit.bytes.hralign = hralign;
	coddigit.bytes.italic = italic;
	coddigit.bytes.sto = sto;
	coddigit.bytes.underline = underline;
	return coddigit;
}

void printatribut(union coding digit)
{
	if (digit.bytes.bold)
		printf("<b>\n");//жирный стиль да/нет
	if (digit.bytes.italic)
		printf("<i>\n");//наклон да/нет
	if (digit.bytes.underline)
		printf("<ins>\n");//падчеркивание да/нет
	switch (digit.bytes.hralign)
	{
	case(1):
		printf("<hr align=\"left\">\n");//выравнивание слева
		break;
	case(2):
		printf("<hr align=\"center\">\n");//выравнивание по центру
		break;
	case(3):
		printf("<hr align=\"right\">\n");//выравнивание справа
		break;
	case(4):
		printf("<hr align=\"justify\">\n");//другое выравнивание
		break;
	default:
		break;
	}
	printf("Size-%d\n", digit.bytes.sto);//размер шрифта
}

int main()
{
	PrintHTML1("ololo", 7);
	union coding magicdigit=create(100,justify,underline_on,italic_on,bold_on);
	printatribut(magicdigit);
	return 0;
}