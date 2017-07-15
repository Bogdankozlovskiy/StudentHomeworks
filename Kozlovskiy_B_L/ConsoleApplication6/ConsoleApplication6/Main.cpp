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
	int dig;
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

void printatribut(int digit)
{
	union coding codigit;
	codigit.dig = digit;
	if (codigit.bytes.bold)
		printf("<b>\n");//������ ����� ��/���
	if (codigit.bytes.italic)
		printf("<i>\n");//������ ��/���
	if (codigit.bytes.underline)
		printf("<ins>\n");//������������� ��/���
	switch (codigit.bytes.hralign)
	{
	case(1):
		printf("<hr align=\"left\">\n");//������������ �����
		break;
	case(2):
		printf("<hr align=\"center\">\n");//������������ �� ������
		break;
	case(3):
		printf("<hr align=\"right\">\n");//������������ ������
		break;
	case(4):
		printf("<hr align=\"justify\">\n");//������ ������������
		break;
	default:
		break;
	}
	printf("Size-%d\n", codigit.bytes.sto);//������ ������
}

int main()
{
	PrintHTML1("ololo", 7);
	union coding magicdigit=create(100,justify,underline_on,italic_on,bold_on);
	printatribut(magicdigit.dig);
	return 0;
}