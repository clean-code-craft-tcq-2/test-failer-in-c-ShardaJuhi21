#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;
 int FailureCount = 0;
int networkAlertStub(float celcius) {
 
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if(celcius < 200 || celcius > 200){
        return celcius;
    }
    return 200;

}

void stubprintToConsole(){
 FailureCount++;
}

 
void alertCheck( float (*fpPrintalertInCelcius)(float), float farenheit,void (*fpPrintToConsole)(),int (*fpnetworkAlertStub)(float)){
    float localfarenheit =farenheit;
    float localCelsius = fpPrintalertInCelcius(localfarenheit);
    int returnCode = fpnetworkAlertStub(localCelsius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount ++;
        fpPrintToConsole();
    }   
 }

float alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
   return celcius;

}

void printToConsole(float celcius){
 printf("ALERT: Temperature is %.1f celcius.\n", celcius);
}




int main() {
    alertInCelcius(alertInCelcius,303.6,stubprintToConsole, networkAlertStub);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
