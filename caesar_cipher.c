#include <stdio.h>

// encrypt a character by moving it 'shift' positions to right in the same ascii
// 'zone' (A-Z or a-z or 0-9)
int encrypt_char(int ch, int start, int end, int shift) {
    // range of the ascii zone that character is allowed to be shifted in
    int range = end - start + 1;
    int new_ch = ch + shift % range;
    // if new character is out of the zone, shift it from the start of the zone
    // by the number of positions that were over the zone
    int extra = new_ch - end;
    if (extra > 0) {
        new_ch = start - 1 + extra;
    }
    return new_ch;
}

// decrypt a character by moving it 'shift' positions to the left in the same
// ascii 'zone' (A-Z or a-z or 0-9)
int decrypt_char(int ch, int start, int end, int shift) {
    // range of the ascii zone that character is allowed to be shifted in
    int range = end - start + 1;
    int new_ch = ch - shift % range;
    // if new character is out of the zone, shift it from the end of the zone
    // by the number of positions that were under the zone
    int extra = start - new_ch;
    if (extra > 0) {
        new_ch = end + 1 - extra;
    }
    return new_ch;
}

// based on the ascii zone of the character, call function (encrypt_char,
// decrypt_char)
void call_function_by_zone(int ch, int shift, int (*f)(int, int, int, int)) {
    if (ch <= '9' && ch >= '0') {
        putchar((*f)(ch, '0', '9', shift));
    } else if (ch <= 'Z' && ch >= 'A') {
        putchar((*f)(ch, 'A', 'Z', shift));
    } else if (ch <= 'z' && ch >= 'a') {
        putchar((*f)(ch, 'a', 'z', shift));
    } else if (ch != '\n')  // if ch is a symbol
        putchar(ch);
    else
        printf("\n");
}

int main(void) {
    int num, shift = 0, flag, new_ch, ch, npos;
    // e for encryption, d for decryption
    int crypt = getchar();
    // get number of positions for every letter to be right shifted
    while ((num = getchar()) != '\n') {
        shift = shift * 10 + num - '0';
    }
    if (crypt == 'e') {  // encryption
        while ((ch = getchar()) != EOF) {
            call_function_by_zone(ch, shift, encrypt_char);
        }
    } else if (crypt == 'd') {  // decryption
        while ((ch = getchar()) != EOF) {
            call_function_by_zone(ch, shift, decrypt_char);
        }
    } else {
        printf("Wrong input format.\n");
    }
    return 0;
}
