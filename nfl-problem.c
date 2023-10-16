#include <stdio.h>

void findCombinations(int score) {
    int TD, FG, Safety;
    
    for (TD = 0; TD * 6 <= score; TD++) {
        for (FG = 0; FG * 3 <= score; FG++) {
            for (Safety = 0; Safety * 2 <= score; Safety++) {
                if ((TD * 6 + FG * 3 + Safety * 2) == score) {
                    printf("%d TD + %d 3pt FG + %d Safety\n", TD, FG, Safety);
                }
            }
        }
    }
}

int main() {
    int score;
    
    while (1) {
        printf("Enter the NFL score (Enter 0 or 1 to STOP): ");
        scanf("%d", &score);
        
        if (score <= 1) {
            break;
        }
        
        printf("Possible combinations of scoring plays:\n");
        findCombinations(score);
    }
    
    return 0;
}
