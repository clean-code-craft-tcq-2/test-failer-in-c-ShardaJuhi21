#include <stdio.h>
#include <assert.h>


char size(int cms, void (*fpPrintToConsole)(char)) {
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

void printToConsoleAvailableSize(char sizeName){
 if(sizeName == 'Z'){
     printf(" Tshirt size available %c\n", sizeName);
 }
   printf(" Tshirt size not available %c\n", sizeName);
}

//stubs
struct {
    int availableSizeCount = 0;
    int unavailableSizeCount = 0;
}Count;


void stubprintToConsoleForAvailableSize(char sizeName){
   Count.availableSizeCount++;
}

void stubprintToConsoleForUnvailableSize(char sizeName){
   Count.unavailableSizeCount++;
}

int main() {
    size(38, stubprintToConsoleForAvailableSize);
    assert(Count.availableSizeCount ==1);
    size(48, stubprintToConsoleForUnvailableSize);
    assert(Count.unavailableSizeCount ==1);
    return 0;
}
