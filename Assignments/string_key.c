#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Write a function that takes in a binary string and returns the equivalent
decoded text (the text is ASCII encoded).

Each 8 bits on the binary string represent 1 character on the ASCII table.

The input string will always be a valid binary string.

Characters can be in the range from "00000000" to "11111111" (inclusive)

Note: In the case of an empty binary string your function should return an empty
string
*/

// return a dynamically allocated, free-able C-string
char *binary_to_string(const char *binary) {
  int len = strlen(binary) / 8;
  char *ascii = malloc(len + 1);
  for (int i = 0; i < len; i++) {
    char *substr = malloc(8);
    strncpy(substr, binary + 8 * i, 8);
    ascii[i] = strtol(substr, NULL, 2);
  }
  ascii[len] = '\0';
  return ascii;
}

void compare(char *result, char truth[], int len) {
  for (int i = 0; i < len; i++) {
    assert(result[i] == truth[i]);
  }
}

int main(int argc, char const *argv[]) {
  char *result;
  char truth[256];

  sprintf(truth, "%s", "Hello");
  result = binary_to_string("0100100001100101011011000110110001101111");

  sprintf(truth, "%s", "1011");
  result = binary_to_string("00110001001100000011000100110001");

  sprintf(truth, "%s", "!!you can do this!!");
  result = binary_to_string(
      "001000010010000101111001011011110111010100100000011000110110000101101110"
      "001000000110010001101111001000000111010001101000011010010111001100100001"
      "00100001");

  return 0;
}