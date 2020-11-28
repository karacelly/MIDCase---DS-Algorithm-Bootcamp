#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../models/models.h"

Node *createNode(Patients pat) {
   Node *temp = (Node *)malloc(sizeof(Node));
   strcpy(temp->patient.name, pat.name);
   strcpy(temp->patient.cmonth, pat.cmonth);
   temp->patient.day = pat.day;
   temp->patient.month = pat.month;
   temp->patient.year = pat.year;

   temp->next = NULL;
   temp->prev = NULL;

   return temp;
}

void pushHead(Patients pat){
   curr = createNode(pat);

   if(head == NULL){
      head = tail = curr;
   }
   else{
      curr->next = head;
      head->prev = curr;
      head = curr;
   }
   tail->next = NULL;
}

void pushTail(Patients pat){
   curr = createNode(pat);

   if(head == NULL){
      head = tail = curr;
   }
   else{
      tail->next = curr;
      curr->prev = tail;
      tail = curr;
   }
   tail->next = NULL;
}

int compareDate(Patients pat1, Patients pat2){
   if(pat1.year < pat2.year){
      return -1;
   }
   else if(pat1.year > pat2.year){
      return 1;
   }
   if(pat1.year == pat2.year){
      if (pat1.month<pat2.month) return -1;
      else if (pat1.month>pat2.month) return 1;
      else if (pat1.day<pat2.day) return -1;
      else if(pat1.day>pat2.day) return 1;
      else return 0;
   }
}

void pushMid(Patients pat){
   if(!head) pushHead(pat);
   //kl lebih tua, dia bakal diprioritas 
   //brti yg tua di pushhead
   else if(compareDate(pat, head->patient) == -1) pushHead(pat);
   else if(compareDate(pat, tail->patient) == 1 || compareDate(pat, tail->patient) == 0) pushTail(pat);
   else{
      curr = createNode(pat);
      Node *temp = head;
      while(temp){ // misal 2001 2003 mau mskin 2002
         //brti berenti di temp = 2001
         if(compareDate(pat, temp->patient) == -1){
            curr->next = temp;
            curr->prev = temp->prev;
            temp->prev->next = curr;
            temp->prev = curr;
            break;
         }
         temp = temp->next;
      }
   }
}

void popHead(){
   if(!head) return;
   curr = head;
   head = curr->next;
   head->prev = NULL;
   free(curr);
}

void display(){
   if(!head){
      puts("empty!");
      return;
   }
   else{
      curr = head;
      while(curr){
         printf("%d %s %d - %s\n", curr->patient.day, curr->patient.cmonth, curr->patient.year, curr->patient.name);
         curr = curr->next;
      }
   }
}
