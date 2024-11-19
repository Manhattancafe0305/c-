#include <stdio.h>

int main() {
    char input[200] = "";
    int count[26] = { 0 };
    int ch;
    int i = 0;

    while ((ch = getchar())!=EOF) { 
        input[i++] = ch;
    }
    input[i] = 0;

    
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            count[input[i] - 'a']++;
        }
    }
        
  
    printf("입력문자열: %s\n", input);
    for (i = 0; i < 26; i++) {
        printf("%c 출현횟수: %d\n", 'a' + i, count[i]);
    }

    return 0;
}
