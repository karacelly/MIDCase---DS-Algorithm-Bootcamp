struct Patients{
   int day;
   char cmonth[15];
   int month;
   int year;
   char name[255];
};

struct Node{
   Patients patient;
   Node *prev, *next;
}*head, *tail, *curr;
