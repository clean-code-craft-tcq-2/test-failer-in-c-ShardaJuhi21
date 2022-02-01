#include <stdio.h>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

typedef struct {
    int PairNumber = 0 ;
    char MajorColorNames[15];
    char MinorColorNames[15];
    int numberOfMajorColors;
    int numberOfMinorColors;
} ColorPair;




ColorPair->numberOfMajorColors =
    sizeof(majorColor) / sizeof(majorColor[0]);
ColorPair->numberOfMinorColors =
    sizeof(minorColor) / sizeof(minorColor[0]);

int printColorMap(void (*fpPrintToConsole)(const ColorPair* colorPair)) {
    int i = 0, j = 0;
    for(i = 0; i < ColorPair->numberOfMajorColors; i++) {
        for(j = 0; j < ColorPair->numberOfMinorColors; j++) {
           fpPrintToConsole(colorPair);
        }
    }
    return i * j;
}

void printToConsole(const ColorPair* colorPair ){
    
     printf("%d | %s | %s\n", colorPair->numberOfMajorColors * 5 + colorPair->numberOfMinorColors, majorColor[colorPair->numberOfMajorColors], minorColor[colorPair->numberOfMinorColors]);
    
}

// stub




void stubPrintToConsole(const ColorPair* colorPair ){
 ColorPair->PairNumber++;
//  MajorColorNames[colorPair->majorColor];
//  MinorColorNames[colorPair->minorColor];
    
}



int main() {
    int result = printColorMap(stubPrintToConsole(const ColorPair* colorPair));
    assert(ColorPair->PairNumber == result);
    printf("All is well (maybe!)\n");
    return 0;
}
