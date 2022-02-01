#include <stdio.h>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int printColorMap(void (*fpPrintToConsole)(const ColorPair* colorPair)) {
    int i = 0, j = 0;
    for(i = 0; i < colorPair.numberOfMajorColors; i++) {
        for(j = 0; j < colorPair.numberOfMinorColors; j++) {
           fpPrintToConsole(colorPair);
        }
    }
    return i * j;
}

void printToConsole(const ColorPair* colorPair ){
    
     printf("%d | %s | %s\n", colorPair.numberOfMajorColors * 5 + colorPair.numberOfMinorColors, majorColor[colorPair.numberOfMajorColors], minorColor[colorPair.numberOfMinorColors]);
    
}

// stub
int numberOfMajorColors =
    sizeof(majorColor) / sizeof(majorColor[0]);
int numberOfMinorColors =
    sizeof(minorColor) / sizeof(minorColor[0]);
typedef struct {
    int PairNumber = 0 
    char MajorColorNames[15];
    char MinorColorNames[15];
    numberOfMajorColors;
    numberOfMinorColors;
} ColorPair;


void stubPrintToConsole(const ColorPair* colorPair ){
 ColorPair.PairNumber++;
 MajorColorNames[colorPair->majorColor],
 MinorColorNames[colorPair->minorColor];
    
}



int main() {
    int result = printColorMap(stubPrintToConsole(const ColorPair* colorPair));
    assert(ColorPair.PairName == result);
    printf("All is well (maybe!)\n");
    return 0;
}
