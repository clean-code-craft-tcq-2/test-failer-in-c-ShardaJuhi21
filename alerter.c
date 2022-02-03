#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;
//int FailureCount = 0;
int networkAlertStub(float celcius) {
 
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if(celcius < 200 || celcius > 200){
        return celcius;
    }
    return 200;

}

// void stubPrintToConsole(float celcius){
//   float localCelsius = celcius;
//  FailureCount++;
// }

// float CelsiusCounter =0;
// float NetworkCounter =0;
// float stubAlertInCelcius(float farenheit) {
//   float localfarenheit =farenheit;
//   CelsiusCounter++;
//  return 0;
// }

// int StubnetworkAlert(float celcius) {
//  float localCelsius = celcius;
//     NetworkCounter++;
//     return 0;

// }

 
void alertCheck( float (*fpalertInCelcius)(float), float (*fpInputFromConsole)(),void (*fpPrintToConsole)(float),int (*fpnetworkAlertStub)(float)){
    float localfarenheit =fpInputFromConsole();
    float localCelsius = fpalertInCelcius(localfarenheit);
    int returnCode = fpnetworkAlertStub(localCelsius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount ++;
        fpPrintToConsole( float (returnCode));
    }   
 }

float alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
   return celcius;

}

float inputFromConsole()
 {
  float farehneit;
 printf("Temperature is &f celcius.\n", farehneit);
 return farehneit;
}

void printToConsole(float celcius){
 printf("ALERT: Temperature is %.1f celcius.\n", celcius);
}


int main() {
    alertCheck(alertInCelcius,inputFromConsole,printToConsole, networkAlertStub);
 //test
    //alertCheck(stubAlertInCelcius,303.6,stubPrintToConsole, StubnetworkAlert);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
