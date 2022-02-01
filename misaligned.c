#include <stdio.h>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int printColorMap(void (*fpPrintToConsole)(int majorColorIndex, int minorColorIndex)) {
    int i = 0, j = 0;
    for(i = 0; i < majorColorIndex; i++) {
        for(j = 0; j < minorColorIndex; j++) {
           fpPrintToConsole(i,j);
        }
    }
    return i * j;
}

void printToConsole(int majorColorIndex , int minorColorIndex ){
    
     printf("%d | %s | %s\n", majorColorIndex * 5 + minorColorIndex, majorColor[majorColorIndex], minorColor[minorColorIndex]);
    
}

// stub

typedef struct {
    int PairNumber = 0 
    char majorColor[];
    char minorColor[];
} ColorPair;


void stubPrintToConsole(int numberOfMajorColors, int numberOfMinorColors ){
 ColorPair.PairNumber++;
}



int main() {
    int result = printColorMap(stubPrintToConsole(5, 5));
    assert(ColorPair.PairName == result);
    printf("All is well (maybe!)\n");
    return 0;
}
