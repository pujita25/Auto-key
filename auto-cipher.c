#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


FILE *source_file, *destination_file;

//array of strings used to encrypt/decrypt the strings by taking the positions(index) starting from 0-25
int alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

//function to encrypt the given message
void auto_encryption(char *str, char *sec_key, FILE *fp) {
  int string_length = strlen(str);
  int arr_size = sizeof alphabet / sizeof alphabet[0];
  int key_len = strlen(sec_key);
  char sub_string[1000];
  strcat(sec_key, str);
  int sub_string_len = strlen(sec_key) - key_len;
  memcpy(sub_string, &sec_key[0], sub_string_len);
  sub_string[sub_string_len] = '\0';
  
  char encryptMsg[1000];
  encryptMsg[0]='\0';
  for (int i = 0; i < string_length; i++) {
    int main_str_index = 0;
    int sub_str_index = 0;
    char main_chat_pos = str[i];
    char sub_char_pos = sub_string[i];
    for(int idx = 0; idx < arr_size; idx++) {
      if(main_chat_pos == alphabet[idx]) {
        main_str_index = idx;
      }
      if(sub_char_pos == alphabet[idx]) {
        sub_str_index = idx;
      }
    }
   int total = (main_str_index + sub_str_index) % 26;
   strcat(encryptMsg, &alphabet[total]);
  }
  printf("Encrypted the message successfully: %s \n", encryptMsg);
  fputs(encryptMsg, fp);
  
}

void auto_decrypt(char *str, char *sec_key, FILE *fp) {
  int string_length = strlen(str);
  char *currentKey = sec_key;
  char decryptMsg[1000];
  decryptMsg[0]='\0';
int arr_size = sizeof alphabet / sizeof alphabet[0];
  for (int i = 0; i < string_length; i++) {
    int main_str_index = 0;
    int sub_str_index = 0;
    char main_chat_pos = str[i];
    char sub_char_pos = currentKey[i];
    for(int idx = 0; idx < arr_size; idx++) {
      if(main_chat_pos == alphabet[idx]) {
        main_str_index = idx;
      }
      if(sub_char_pos == alphabet[idx]) {
        sub_str_index = idx;
      }
    }
    int total = (main_str_index - sub_str_index) % 26;
    total = (total < 0) ? total + 26 : total;
    strcat(decryptMsg, &alphabet[total]);
    strcat(currentKey, &alphabet[total]);
  }
 printf("Encrypted the message successfully: %s \n", decryptMsg);
  fputs(decryptMsg, fp);
}

int main(int argc, char *argv[])
{
  int secret_key;
  char main_string[1000];
  source_file = fopen(argv[1], "r");
  if (source_file == NULL)
  {
    perror("An error has occurred while opening the input file");
    exit(0);
  }
  fgets(main_string, 1000, source_file);
  destination_file = fopen(argv[2], "w");
  if (destination_file == NULL)
  {
    perror("An error has occurred while opening the output file");
    exit(0);
  }
  secret_key = atoi(argv[4]);
  if (secret_key == 1) {
    auto_encryption(main_string, argv[3], destination_file);
  } else if (secret_key == 0) {
    auto_decrypt(main_string, argv[3], destination_file);
  }
  fclose(source_file);
  fclose(destination_file);
}
