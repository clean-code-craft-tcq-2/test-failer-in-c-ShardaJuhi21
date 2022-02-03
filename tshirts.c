#include <stdio.h>
#include <assert.h>


char size(int cms, void (*fpPrintToConsole)(char)) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
        fpPrintToConsole(sizeName);
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
        fpPrintToConsole(sizeName);
    } else if(cms > 42 && cms < 47) {
        sizeName = 'L';
       fpPrintToConsole(sizeName);
    }else{
        sizeName = 'Z'; //size not available
        fpPrintToConsole(sizeName);
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

char SizeName;
void stubprintToConsoleForAvailableSize(char sizeName){
   SizeName = sizeName;
   Count.availableSizeCount++;
}

void stubprintToConsoleForUnvailableSize(char sizeName){
    SizeName = sizeName;
   Count.unavailableSizeCount++;
}

int main() {
    size(38, stubprintToConsoleForAvailableSize);
    assert(Count.availableSizeCount ==1);
    size(48, stubprintToConsoleForUnvailableSize);
    assert(Count.unavailableSizeCount ==1);
    return 0;
}
