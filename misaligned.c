#include <stdio.h>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

typedef struct {
    int numberOfMajorColors;
    int numberOfMinorColors;
}NumberofColors;

typedef struct{
    char MajorColorNames[15];
    char MinorColorNames[15];

}ColorNames;

typedef struct{
    int PairNumber = 0 ;
    const NumberofColors *numberOfColors;
    const ColorNames *colorNames;

}ColorPair;


static const NumberofColors colors =
{
    .numberOfMajorColors = sizeof(majorColor) / sizeof(majorColor[0]),
    .numberOfMinorColors = sizeof(minorColor) / sizeof(minorColor[0]),
};

// static const NumberofColors colors =
// {
//     .numberOfMajorColors = sizeof(majorColor) / sizeof(majorColor[0]),
//     .numberOfMinorColors = sizeof(minorColor) / sizeof(minorColor[0]),
// };

int printColorMap(void (*fpPrintToConsole)(const ColorPair * const colorpair )) {
    ColorPair  const *colorpairList = colorpair;
    int i = 0, j = 0;
    for(i = 0; i < colorpairList ->NumberofColors.numberOfMajorColors; i++) {
        for(j = 0; j < colorpairList ->NumberofColors.numberOfMinorColors; j++) {
           fpPrintToConsole(colorpairList);
        }
    }
    return i * j;
}

void printToConsole(const ColorPair * const colorpair){
    ColorPair  const *colorpairList = colorpair;
     printf("%d | %s | %s\n", colorpairList ->NumberofColors.numberOfMajorColors * 5  + colorpairList ->NumberofColors.numberOfMinorColors, majorColor[colorpairList ->NumberofColors.numberOfMajorColors], minorColor[colorpairList ->NumberofColors.->numberOfMinorColors]);
    
}

// stub




void stubPrintToConsole(const ColorPair * const colorpair){
 ColorPair  const *colorpairList = colorpair;
    colorpairList.PairNumber++;
//  MajorColorNames[colorPair->majorColor];
//  MinorColorNames[colorPair->minorColor];
    
}



int main() {
    int result = printColorMap(stubPrintToConsole(const ColorPair * const colorpair);
//     assert(ColorPair->PairNumber == result);
    printf("All is well (maybe!)\n");
    return 0;
}
