#include <stdio.h>
#include <assert.h>

#define FARENHEITTEMP 303.6
#define FARENHEITTEMP2 400.5
int alertFailureCount = 0;
int Counter =0;
int networkAlertStub(float celcius) {
 
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if(celcius < 200 || celcius > 200){
        return 500;
    }
    return 200;
}

void stubPrintToConsole(float Counter){
Counter++;
}

float stubAlertInCelcius(float celcius) {
      if(celcius < 200 || celcius > 200){
        return 500;
    }
    return 200;
}

 
void alertCheck( float (*fpalertInCelcius)(float), float farenheit,void (*fpPrintToConsole)(float),int (*fpnetworkAlertStub)(float)){
    float localCelsius = fpalertInCelcius(farenheit);
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

void printToConsole(float celcius){
 printf("ALERT: Temperature is %.1f celcius.\n", celcius);
}


int main() {
 //test
    alertCheck(stubAlertInCelcius,FARENHEITTEMP,stubPrintToConsole, networkAlertStub);
    assert(Counter == alertFailureCount);
    alertCheck(stubAlertInCelcius,FARENHEITTEMP2,stubPrintToConsole, networkAlertStub);
    assert(Counter == alertFailureCount);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
