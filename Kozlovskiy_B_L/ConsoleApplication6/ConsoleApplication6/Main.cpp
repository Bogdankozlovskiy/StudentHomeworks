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

int create(char sto,char hralign,bool underline,bool italic,bool bold)
{
	int digit = 0;//����������� �����
	digit = digit | bold;
	digit = digit << 1;
	digit = digit | italic;
	digit = digit << 1;
	digit = digit | underline;
	digit = digit << 3;
	digit = digit | hralign;
	digit = digit << 8;
	digit = digit | sto;
	return digit;
}

void printatribut(int digit)
{
	char sto = digit & 255;
	char HorAlign = digit >> 8 & 7;
	char underline = digit >> 11 & 1;
	char italic = digit >> 12 & 1;
	char bold = digit >> 13 & 1;
	if (bold)
		printf("<b>\n");//������ ����� ��/���
	if (italic)
		printf("<i>\n");//������ ��/���
	if (underline)
		printf("<ins>\n");//������������� ��/���
	switch (HorAlign)
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
	printf("Size-%d\n", sto);//������ ������
}

int main()
{
	PrintHTML1("ololo", 7);
	int magicdigit=create(100,2,1,1,1);
	printatribut(magicdigit);
	return 0;
}