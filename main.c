#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stbool.h>
#include "funcs.h"

int main()
{
   int n = 0;            // Πλήθος διαδρομών
   char k;                // Επιλογή χρήστη (εντολή)
   struct route *A = NULL; // Δείκτης στον δυναμικά δεσμευμένο πίνακα διαδρομών

   do
   {
      // Διαβάζει την εντολή του χρήστη (π.χ. 'i', 'p', 'q')
      scanf("%c",&k);
      
      // Καθαρίζει τον buffer εισόδου για να μη διαβαστούν ανεπιθύμητοι χαρακτήρες (π.χ. newline)
      int c;
      while ((c = getchar() ) != EOF && c != '\n' && c!='\r');
      
      switch (k)
      {
        case 'i': 
            // Απελευθερώνει την παλιά μνήμη πριν τη φόρτωση νέων δεδομένων (αποφυγή memory leak)
            if (A != NULL) {
                free(A);
                A = NULL;
            }
            // Φόρτωση από είσοδο και δέσμευση μνήμης
            A = readFromInput(&n);
            // Ταξινόμηση του πίνακα αμέσως μετά τη φόρτωση
            if (A != NULL && n > 0) {
                sortRoutesByLength(A, n);
            }
            break;
            
        case 'f':
            // Απελευθερώνει την παλιά μνήμη πριν τη φόρτωση νέων δεδομένων
            if (A != NULL) {
                free(A);
                A = NULL;
            }
            // Φόρτωση από αρχείο και δέσμευση μνήμης
            A = readFromFile(&n);
            // Ταξινόμηση του πίνακα αμέσως μετά τη φόρτωση
            if (A != NULL && n > 0) {
                sortRoutesByLength(A, n);
            }
            break;
            
        case 'p': printData(A,n);
            break;
        case 'l': findShort(A,n);
            break;
        case 's': findLocation(A,n);
            break;
        case 'u': findUpHill(A,n);
            break;
        case 'd': findDownHill(A,n);
            break;
        case 'h': findAltitude(A,n);
            break;
        case 't': findTimely(A,n);
            break;
        case 'o': saveData(A,n);
            break;
      }
    
   }
   while (k!='q'); // Ο βρόχος τερματίζεται με την εντολή 'q'
   
   // Απελευθέρωση της δυναμικά δεσμευμένης μνήμης πριν την έξοδο του προγράμματος
   if (A != NULL) {
       free(A);
   }
   
   return 0;
}
