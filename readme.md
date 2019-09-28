## A simple C program for Caesar's cipher
After calling the program write "e" for encryption or "d" for decryption, followed by the number of positions to move each letter. Then give sentences to encrypt or decrypt until EOF. 
Compile and run:
```
$ gcc -o cipher caesar_cipher.c
$ ./cipher
```
Example 1: 
```
$ ./cipher
e12
hello world1!
tqxxa iadxp3!
```
Example 2: 
```
$ ./cipher
d12
tqxxa iadxp3!
hello world1!
```
