/*File: exam1_sdi1500151.c */
#include <stdio.h>

int main(void){
	int num,pos=0,flag,crypt,th,ch,npos;
	crypt = getchar();                           //e for encryption, d for decryption
	while ((num = getchar()) != '\n'){
		pos = pos * 10 + num - '0';
	}
	if (crypt == 'e'){                           //encryption
		while((ch = getchar()) != EOF){
			if (ch <= '9' && ch >= '0')
				flag = 1;
			else if (ch >= 'A' && ch <= 'Z')
				flag = 2;
			else if (ch >= 'a' && ch <= 'z')
				flag = 3;
			else
				flag = 0;
			th = ch + pos;
			if ((th <= '9' && th >= '0' && flag == 1) || (th >= 'A' && th <= 'Z' && flag == 2) || (th >= 'a' && th <= 'z' && flag == 3))
				putchar(th);
			else if (flag == 1){
				if (pos >= 10){
					npos = pos % 10;
					th = ch + npos;
					if (th > '9'){
						npos = npos - '9' + ch;
						th = '0' - 1 + npos;
						putchar(th);
					}
					else
						putchar(th);
				}
				else{
					npos = pos - '9' + ch;
					th = '0' - 1 + npos;
					putchar(th);
				}
			}
			else if (flag == 2){
				if (pos >= 26){
					npos = pos % 26;
					th = ch + npos;
					if (th > 'Z'){
						npos = npos - 'Z' + ch;
						th = 'A' - 1 + npos;
						putchar(th);
					}
					else
						putchar(th);
				}
				else{
					npos = pos - 'Z' + ch;
					th = 'A' - 1 + npos;
					putchar(th);
				}
			}
			else if (flag == 3){
				if (pos >= 26){
					npos = pos % 26;
					th = ch + npos;
					if (th > 'z'){
						npos = npos - 'z' + ch;
						th = 'a' - 1 + npos;
						putchar(th);
					}
					else
						putchar(th);
				}
				else{
					npos = pos - 'z' + ch;
					th = 'a' - 1 + npos;
					putchar(th);
				}
			}
			else if (ch != '\n')                    //if ch is a symbol
				putchar(ch);
			else
				printf("\n");
		}
	}
	else{                                           //decryption
		while((ch = getchar()) != EOF){
			if (ch <= '9' && ch >= '0')
				flag = 1;
			else if (ch >= 'A' && ch <= 'Z')
				flag = 2;
			else if (ch >= 'a' && ch <= 'z')
				flag = 3;
			else
				flag = 0;
			th = ch - pos;
			if ((th <= '9' && th >= '0' && flag == 1) || (th >= 'A' && th <= 'Z' && flag == 2) || (th >= 'a' && th <= 'z' && flag == 3))
				putchar(th);
			else if (flag == 1){
				if (pos >= 10){
					npos = pos % 10;
					th = ch - npos;
					if (th < '0'){
						npos = npos - ch + '0';
						th = '9' - npos;
						putchar(th);
					}
					else
						putchar(th);
				}
				else{
					npos = pos - ch + '0';
					th = '9' - npos;
					putchar(th);
				}
			}
			else if (flag == 2){
				if (pos >= 26){
					npos = pos % 26;
					th = ch - npos;
					if (th < 'A'){
						npos = npos - ch + 'A';
						th = 'Z' - npos;
						putchar(th);
					}
					else
						putchar(th);
				}
				else{
					npos = pos - ch + 'A';
					th = 'Z' - npos;
					putchar(th);
				}
			}
			else if (flag == 3){
				if (pos >= 26){
					npos = pos % 26;
					th = ch - npos;
					if (th < 'a'){
						npos = npos - ch + 'a';
						th = 'z' - npos;
						putchar(th);
					}
					else
						putchar(th);
				}
				else{
					npos = pos - ch + 'a';
					th = 'z' - npos;
					putchar(th);
				}
			}
			else if (ch != '\n')
				putchar(ch);
			else
				printf("\n");
		}
	}
	return 0;
}
