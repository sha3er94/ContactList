#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
int i,j,n=0,flag=0,flag2=0,temp=0;
char last_name[20];
int numberofcontacts=0;
typedef struct
{
    char firstname[15];
    char lastname[15];
    char phone[15];
    char adress[100];
    char city[20];
} info;
info stock[100];
void load()
{
    FILE *f;
    char path[100];
    char line[1000];
    gets(path);
    f=fopen(path,"r");
    if(f!=NULL)
    {
        flag2=1;
        printf("File loaded\n\n\n");
        while(!(feof(f)))
        {
            fgets(line,1000,f);
            structure(line,numberofcontacts);
            numberofcontacts++;
        }
    }
    else printf("Nothing Found\n\n");
}
void structure(char x[],int n)
{
    char y[100];
    i=0;
    j=0;
    int counter=0;
    int stri=0;
    for(counter=0; counter<5; counter++)
    {
        stri=0;
        for(j=j; x[j]!=','  && x[j]!='\0'; j++)
        {
            y[stri]=x[j];
            stri++;
        }
        y[stri]='\0';
        j++;
        switch(counter)
        {
        case 0:
            for(i=0; y[i]!='\0'; i++)
            {
                stock[n].lastname[i]=y[i];

            }
            break;
        case 1:
            for(i=0; y[i]!='\0'; i++)
            {
                stock[n].firstname[i]=y[i];
            }
            break;
        case 2:
            for(i=0; y[i]!='\0'; i++)
            {
                stock[n].adress[i]=y[i];
            }
            break;
        case 3:
            for(i=0; y[i]!='\0'; i++)
            {
                stock[n].city[i]=y[i];
                //counter++;
            }
            break;
        case 4:
            for(i=0; y[i]!='\0'; i++)
            {
                stock[n].phone[i]=y[i];
                //counter++;
            }
            break;
        default:
            break;
        }
    }
}
int SearchContact ()
{
    int z;
    int m;
    int sub;
    int flags=0;
    printf("Enter The Last Name Of The Contact You Want To Look For : ");
    getchar();
    gets(last_name);
    for (i=0; i<numberofcontacts; i++)
    {
        z=strcmpi(last_name,stock[i].lastname);
        if (z==0)
        {
            printf("\n%d--\nlastname :%s\n",i,stock[i].lastname);
            printf("firstname:%s\n",stock[i].firstname);
            printf("adress :%s\n",stock[i].adress);
            printf("city :%s\n",stock[i].city);
            printf("phone :%s\n",stock[i].phone);
            flag=1;
        }
}

    if(flag==0){
        printf("No Contacts Have The Last Name You're Trying To Look For.\n");
                return 0;}
    return 1;}
void Edit()
{
    int editn;
    i=0;
    editn=SearchContact();
    if(editn==1){
    printf("Enter the number of the cont. you want to edit\n");
    scanf("%d",&editn);
    char boolean;
    for(i=0; i<5; i++)
    {
        switch(i)
        {
        case 0:
            printf("Last name:%s \nIf u want to change enter y for no enter n\n",stock[editn].lastname);
            getchar();
            scanf("%c",&boolean);
            if(boolean=='y')
            {
                printf("Enter the new entry\n");
                getchar();
                gets(stock[editn].lastname);
            }
            else getchar();
            break;
        case 1:
            printf("first name:%s \nIf u want to change enter y for no enter n\n",stock[editn].firstname);
            //getchar();
            scanf("%c",&boolean);
            if(boolean=='y')
            {
                printf("Enter the new entry\n");
                getchar();
                gets(stock[editn].firstname);
            }
            else getchar();
            break;
        case 2:
            printf("adress:%s \nIf u want to change enter y for no enter n\n",stock[editn].adress);
            //getchar();
            scanf("%c",&boolean);
            if(boolean=='y')
            {
                printf("Enter the new entry\n");
                getchar();
                gets(stock[editn].adress);
            }
            else getchar();
            break;
        case 3:
            printf("city:%s \nIf u want to change enter y for no enter n\n",stock[editn].city);
            //getchar();
            scanf("%c",&boolean);
            if(boolean=='y')
            {
                printf("Enter the new entry\n");
                getchar();
                gets(stock[editn].city);
            }
            else getchar();
            break;
        case 4:
            printf("phone: %s \nIf u want to change enter y for no enter n\n",stock[editn].phone);
            //getchar();
            scanf("%c",&boolean);
            //getchar();
            if(boolean!='y' && boolean!='n'){printf("please answer y/n");scanf("%c",&boolean);}
            if(boolean=='y')
            {
                printf("Enter the new entry\n");
                getchar();
                gets(stock[editn].phone);
                printf("%s\n",stock[editn].phone);
            }
           // else getchar();
            break;


        }
    }
    }
}
void add()
{

printf("Enter the information as asked, please\n");
    i=0;
    getchar();
    //printf("The number %d\n",numberofcontacts);
        switch(i)
        {
        case 0:
            printf("Enter the last name\n");
            gets(stock[numberofcontacts].lastname);
           // printf("the last name %s",stock[numberofcontacts].lastname);

        case 1:
            printf("Enter the first name\n");
            //getchar();
            gets(stock[numberofcontacts].firstname);
            //printf("%s\n",stock[numberofcontacts].firstname);
        case 2:
            printf("Enter the address\n");
            //getchar();
            gets(stock[numberofcontacts].adress);

        case 3:
            printf("Enter the city\n");
            //getchar();
            gets(stock[numberofcontacts].city);
        case 4:
            printf("Enter the phone number\n");
            //getchar();
            gets(stock[numberofcontacts].phone);
        }
numberofcontacts++;}
void DeleteContact()
{
    int x;
   temp=SearchContact();
   if(temp==1){
    printf("Enter the number of contact you want to delete\n");
    scanf("%d",&x);
        for(i=x;i<numberofcontacts;i++){
            stock[i]=stock[i+1];
        }
    numberofcontacts--;
   }
}
void sortcontacts()
{

    int i,j,compare1,compare2;
    char t[1][100];
    for(i=0; i<numberofcontacts; i++)
        for(j=0; j<numberofcontacts-1; j++)
        {
            compare1=strcmp(stock[j].lastname,stock[j+1].lastname);

            if(compare1>0)
            {
                strcpy(t[0],stock[j+1].lastname);
                strcpy(stock[j+1].lastname,stock[j].lastname);
                strcpy(stock[j].lastname,t[0]);

                strcpy(t[0],stock[j+1].firstname);
                strcpy(stock[j+1].firstname,stock[j].firstname);
                strcpy(stock[j].firstname,t[0]);

                strcpy(t[0],stock[j+1].phone);
                strcpy(stock[j+1].phone,stock[j].phone);
                strcpy(stock[j].phone,t[0]);

                strcpy(t[0],stock[j+1].adress);
                strcpy(stock[j+1].adress,stock[j].adress);
                strcpy(stock[j].adress,t[0]);

                strcpy(t[0],stock[j+1].city);
                strcpy(stock[j+1].city,stock[j].city);
                strcpy(stock[j].city,t[0]);
            }
            else if(compare1==0)
            {
            compare2=strcmp(stock[j].firstname,stock[j+1].firstname);

            if(compare2>0)
            {
                strcpy(t[0],stock[j+1].firstname);
                strcpy(stock[j+1].firstname,stock[j].firstname);
                strcpy(stock[j].firstname,t[0]);

                strcpy(t[0],stock[j+1].lastname);
                strcpy(stock[j+1].lastname,stock[j].lastname);
                strcpy(stock[j].lastname,t[0]);

                strcpy(t[0],stock[j+1].phone);
                strcpy(stock[j+1].phone,stock[j].phone);
                strcpy(stock[j].phone,t[0]);

                strcpy(t[0],stock[j+1].adress);
                strcpy(stock[j+1].adress,stock[j].adress);
                strcpy(stock[j].adress,t[0]);

                strcpy(t[0],stock[j+1].city);
                strcpy(stock[j+1].city,stock[j].city);
                strcpy(stock[j].city,t[0]);
            }
        }

}
}
void print(){
   sortcontacts();
for(i=0;i<numberofcontacts;i++){
    printf("Last name:%s\nFirst name:%s\nAdress:%s\nCity:%s\nPhone:%s\n\n\n",stock[i].lastname,stock[i].firstname,stock[i].adress,stock[i].city,stock[i].phone);

}
}
void save(){
printf("Enter the path you want to save into\n");
char savef[200];
getchar();
gets(savef);
FILE *fil;
fil =fopen(savef,"w");
//printf("number of contacts %d\n",numberofcontacts);
for(i=0;i<numberofcontacts;i++)
{   fprintf(fil,"%d-->\n",numberofcontacts);
    fprintf(fil,"Last name :%s\n",stock[i].lastname);
    fprintf(fil,"First name:%s\n",stock[i].firstname);
    fprintf(fil,"Adress :%s\n",stock[i].adress);
    fprintf(fil,"City :%s\n",stock[i].city);
    fprintf(fil,"Phone :%s\n",stock[i].phone);
    fprintf(fil,"\n");

}
fclose(fil);
}
int main()
{
int choice;
char path[100];
    printf("\t\t\tWelcome To Phonebook\n\t\t\n");
    printf("1-Load a contact\n2-Search a contact\n3-Add a contact\n4-Remove a contact\n5-Modify a contact\n6-Print Directory\n7-Save\n8-Exit\n");
    printf("\n\nSelect The Number Of Option You Want To Do : \n");
    scanf("%d",&choice);

    if(choice==8)
        exit(0);
    while(choice!=8)
        {
    if (numberofcontacts==0&&choice!=1&&choice!=3&&choice!=7)
    {
    printf("You Must Enter Data First\n\n");
    printf("1-Load a contact\n2-Search a contact\n3-Add a contact\n4-Remove a contact\n5-Modify a contact\n6-Print Directory\n7-Save\n8-Exit\n");
    printf("\nSelect The Number Of Option You Want To Do : \n");
    scanf("%d",&choice);
    }
    else{
    if (choice==1){
    printf("Enter the path of the file that contains the contacts\n");
    gets(path);
    load();
   // break;
    }
    else if (choice==2){
        //getchar();
        SearchContact();}
    else if (choice==3)
        add();
    else if (choice==4)
        DeleteContact();
    else if (choice==5)
        Edit();
    else if (choice==6)
        print();
    else if (choice==7)
        save();
    else printf("Wrong Number Entered");
            printf("1-Load a contact\n2-Search a contact\n3-Add a contact\n4-Remove a contact\n5-Modify a contact\n6-Print Directory\n7-Save\n8-Exit\n");
printf("\nSelect The Number Of Option You Want To Do : \n");
        scanf("%d",&choice);

    }
        }
    return 0;
}

