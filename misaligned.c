#include <stdio.h>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int printColorMap(void (*fpPrintToConsole)(int, int)) {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
         fpPrintToConsole(i,j);
        }
    }
    return i * j;
}

void printToConsole(int MajorIndex, int MinorIndex){
     printf("%d | %s | %s\n", MajorIndex * 5  + MinorIndex, majorColor[MajorIndex], minorColor[MinorIndex]);
    
}

// stub

static int PairNumber = 0;
static int MajorIndex = 0;
static int MinorIndex = 0;
 void stubPrintToConsole(MajorIndex, MinorIndex){
    MajorIndex++;
    MinorIndex++;
    PairNumber++;
    
}



int main() {
    int localMajorIndex =5;
    int localMinorIndex =5;
    int result = printColorMap(stubPrintToConsole(localMajorIndex, localMinorIndex));
    assert(result ==PairNumber);
    printf("All is well (maybe!)\n");
    return 0;
}
