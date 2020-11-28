#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../controllers/controllers.h"

int main(){
   //prompt input
   int npat, cure;
   scanf("%d %d", &npat, &cure);

   Patients pat;
   char month[15][15] = {"january", "february", "march",
                        "april", "may", "june", "july", "september",
                        "october", "november", "december"};
   for(int i=0; i<npat; i++){
      scanf("%d %s %d - %[^\n]", &pat.day, pat.cmonth, &pat.year, pat.name);
      getchar();
      for(int i=0; i<12; i++){
         if(strcmp(pat.cmonth, month[i]) == 0) pat.month = i+1; 
      }

      pushMid(pat);
   }

   for(int i=0; i<cure; i++) popHead();

   //output here
   if(cure - npat >= 0){
      printf("All patients get the cure, %d cure left\n", cure-npat);
   }
   else{
      printf("Need %d more cure\n", npat-cure);
      display();
   }
}