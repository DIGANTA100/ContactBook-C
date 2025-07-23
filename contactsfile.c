#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void help(){
printf("Enter numbers according to your choice(1/2/3/4/5)\n");
printf("1. Add new contact\n");
printf("2. Search things\n");
printf("3. Show all contacts\n");
printf("4. List of the operations\n");
printf("5. Exit\n");
}

void addcontact(){
FILE *fp=fopen("contacts.txt","a");
if(fp==NULL){
    printf("Failed to open the file\n");
    return ;

}
char name[100]; char phone[100]; char email[100];
printf("Enter the name : ");
getchar();
fgets(name,100,stdin);
printf("Enter the PhoneNumber : ");
fgets(phone,100,stdin);
printf("Enter the Email : ");
fgets(email,100,stdin);

fprintf(fp,"Name: %s",name);
fprintf(fp,"Phone: %s",phone);
fprintf(fp,"Email: %s",email);
fprintf(fp,"----------------------------------------------\n");

fclose(fp);



}


void Showcontacts(){

FILE *fp=fopen("contacts.txt","r");
if(fp==NULL){
    printf("Failed to open the file\n");
    return ;

}


char ch;
while((ch=fgetc(fp))!=EOF){
    putchar(ch);



}


fclose(fp);


}

void Search(){

FILE *fp=fopen("contacts.txt","r");
if(fp==NULL){
    printf("Failed to open the file\n");
    return ;

}

char s[1000]; char str[100]; int f=0;
printf("Enter what you want to search : ");
getchar();
fgets(str,100,stdin);
str[strlen(str)-1]='\0';

while(fgets(s,1000,fp)){
    char *p;
    p=strstr(s,str);
    if(p){
      f=1;
       printf("Found in the line : %s",s);


    }







}

if(!f) printf("Sorry! No such thing was found\n");


fclose(fp);




}


int main(){
help();

int cho;
while(1){
printf("\nEnter your choice : ");
scanf("%d",&cho);

if(cho==1){
  addcontact();



}

else if(cho==2) Search();


else if(cho==3) Showcontacts();

else if(cho==5) exit(1);

else if(cho==4) help();

else{
    printf("\nUnknown Choice.Press 4 for Operation Lists");



}


}



}


