#include <stdio.h>
#include <assert.h>


char size(int cms, void (*fpPrintToConsole)()) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
        fpPrintToConsole();
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
        fpPrintToConsole();
    } else if(cms > 42 && cms < 47) {
        sizeName = 'L';
       fpPrintToConsole();
    }else{
        sizeName = 'Z'; //size not available
        fpPrintToConsole();
    }
    return sizeName;
}

void printToConsoleAvailableSize(){
 printf(" Tshirt size available \n");
}
void printToConsoleUnavailableSize(){
 printf(" Tshirt size not available\n");
}

//stubs
struct {
    int availableSizeCount = 0;
    int unavailableSizeCount = 0;
}Count;


void stubprintToConsoleForAvailableSize(){
   Count.availableSizeCount++;
}

void stubprintToConsoleForUnvailableSize(){
   Count.unavailableSizeCount++;
}

int main() {
    size(38, stubprintToConsole);
    assert(Count.availableSizeCount ==1);
    size(48, stubprintToConsole);
    assert(Count.unavailableSizeCount ==1);
    return 0;
}
