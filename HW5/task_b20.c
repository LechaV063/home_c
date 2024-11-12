#include <stdio.h>

// Проверить число на простоту.

int main(int argv, char **argc)
{
    int userNumber, simple=1;
    scanf("%d", &userNumber);
    if(userNumber == 1) {
        printf("NO\n");
        return 0;
    }
    for (int i=2; i<userNumber; i++) {
        if(userNumber%i == 0 && userNumber/i >0)
        {
            simple = 0;
            break;
        } 
    }
    simple ? printf("YES\n") : printf("NO\n");
    return 0;
}