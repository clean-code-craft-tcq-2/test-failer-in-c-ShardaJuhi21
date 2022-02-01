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
 FailureCount++;
}

   

void alertInCelcius(float farenheit, void (*fpPrintToConsole)(int)) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount ++;
        fpPrintToConsole();
        
    }
}

void printToConsole(int celcius){
 printf("ALERT: Temperature is %.1f celcius.\n", celcius);
}
//stubs



int main() {
    alertInCelcius(400.5,networkAlertStub);
    alertInCelcius(303.6,networkAlertStub);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
