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
        sizeName = "Z"; //size not available
        fpPrintToConsole();
    }
    return sizeName;
}

void printToConsoleAvailableSize(){
 printf(" Tshirt size available");
}
void printToConsoleUnavailableSize(){
 printf(" Tshirt size not available");
}

void testAvailableTshirtSize( int tshirtSize){
   size(tshirtSize, printToConsoleAvailableSize );
}


void testAvailableTshirtSize( int tshirtSize){
   size(tshirtSize, printToConsoleUnavailableSize );
}

int main() {
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');
    assert(size(48) == 'Z');
    testAvailableTshirtSize( 38);
    testAvailableTshirtSize( 48);
    return 0;
}
