// simple student database management system
#include<stdio.h>
#include<conio.h>

void addStudent();
void studentRecord();
void searchStudent();
void deleteStudent();

struct Student{
    char firstName[20];
    char lastName[20];
    int roll_no;
    char Class[10];
    char vill[20];
    float per;
}Student;
// MENU
void main ()
{
    int choice;
    while (choice!=5)
    {
        printf("\n\t\t\t ===== STUDENT DATABASE MANAGMENT SYSTEM =====");
        printf("\n\n\n \t\t\t\t 1.Add Student Record \n ");
        printf("\t\t\t\t 2.Student Records \n ");
        printf("\t\t\t\t 3.Search Student \n ");
        printf("\t\t\t\t 4.Delete Student  \n ");
        printf("\t\t\t\t 5.Exit \n ");
        printf("\t\t\t\t __________________________\n ");
        printf("\t\t\t\t ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                //clrscr();
                addStudent();
               // clrscr();
                break;

            case 2:
               // clrscr();
                studentRecord();
                printf("\t\t\t\t Press any key to exit \n");
                getch();
                //clrscr();
                break;


            case 3:
               // clrscr();
                searchStudent();
                printf("\t\t\t\t Press any key to exit \n");
                getch();
                //clrscr();
                break;

            case 4:
               // clrscr();
                deleteStudent();
                printf("\t\t\t\t Press any key to exit \n");
                getch();
                //clrscr();
                break;
            }
    }
}
//ADD NEW STUDENT
void addStudent(){
    char another;
    FILE *fp;
    struct Student info;

    do {
        //clrscr();
        printf("\t\t\t\t ===== ADD STUDENT INFO ===== \n\n\n\n");
        fp=fopen("student_info.txt","a");
        printf("\n \t\t Enter first name :");
        scanf("%s",&info.firstName);

        printf("\n \t\t Enter last name :");
        scanf("%s",&info.lastName);

        printf("\n \t\t Enter roll no :");
        scanf("%d",&info.roll_no);

        printf("\n \t\t Enter Class :");
        scanf("%s",&info.Class);

        printf("\n \t\t Enter address :");
        scanf("%s",&info.vill);

        printf("\n \t\t Enter percentage :");
        scanf("%f",&info.per);
        printf("\n\t\t\t __________________________\n ");

        if (fp==NULL){
        fprintf(stderr, "\t\t\t Can't open file \n");


        }
        else {
            printf("\t\t\t Record stored successfuly \n");
        }
        fwrite(&info,sizeof(struct Student),1,fp);
        fclose(fp);
        printf("\t\t\t Do want to add another record? (y/n) \n");
        scanf("%s",&another);
    }while(another=='y'|| another=='Y');
}


//SHOW ALL STUDENTS
void studentRecord(){
    FILE *fp;
    struct Student info;
    fp=fopen("student_info.txt","r");
    printf("\t\t\t\t ==== Student Records ==== \n\n\n");
    if(fp==NULL)
    {
        fprintf(stderr, "\t\t\t Can't open file \n");
    }
    else {
            printf("\t\t\t Records \n");
            printf("\n\t\t\t _________________\n ");

    }
    while(fread(&info,sizeof(struct Student),1,fp)){
        printf("\n\t\t\t\t Student name %s %s",info.firstName, info.lastName);
        printf("\n\t\t\t\t Roll n %d ",info.roll_no);
        printf("\n\t\t\t\t Class %s",info.Class);
        printf("\n\t\t\t\t Address %s",info.vill);
        printf("\n\t\t\t\t Percentage %f",info.per);
        printf("\n\t\t\t ______________________________________\n ");

    }
    fclose(fp);
    getch();
}

// SEARCH STUDENT
void searchStudent(){
    FILE *fp;
    int roll_no,found=0;
    struct Student info;
    fp=fopen("student_info.txt","r");
    printf("\t\t\t\t ==== Search Student Records ==== \n\n\n");
    printf("\t\t\t\t Enter roll no :");
    scanf("%d",&roll_no);
  while(fread(&info,sizeof(struct Student),1,fp)){
        if(info.roll_no==roll_no){
            found=1;

        printf("\n\t\t\t\t Student name %s %s",info.firstName, info.lastName);
        printf("\n\t\t\t\t Roll n %d ",info.roll_no);
        printf("\n\t\t\t\t Class %s",info.Class);
        printf("\n\t\t\t\t Address %s",info.vill);
        printf("\n\t\t\t\t Percentage %f",info.per);
        printf("\n\t\t\t ______________________________________\n ");
    }
    }
    if (!found)
    {
    printf("\n\t\t\t\t Student not found :");

    }
    fclose(fp);
    getch();

}

// DELETE STUDENT
void deleteStudent(){


    FILE *fp, *fp1;
    int roll_no,found=0;
    struct Student info;

    printf("\t\t\t\t ==== Delete Student Records ==== \n\n\n");
    fp=fopen("student_info.txt","r");
    fp1=fopen("temp.txt","w");
    printf("\t\t\t\t Enter roll no :");
    scanf("%d",&roll_no);

    if(fp==NULL)
    {
        fprintf(stderr, "\t\t\t Can't open file \n");
    }

    while(fread(&info,sizeof(struct Student),1,fp)){
        if(info.roll_no==roll_no){
            found=1;
        }else{
            fwrite(&info,sizeof(struct Student),1,fp1);
        }
    }
    fclose(fp);
    fclose(fp1);

    if (found)
    {
     fp1=fopen("temp.txt","r");
     fp=fopen("student_info.txt","w");
       while(fread(&info,sizeof(struct Student),1,fp1)){
            fwrite(&info,sizeof(Student),1,fp);
       }
     //remove("student_info");
     //rename("temp.txt","student_info");
     printf("\n\t\t\t\t Record deleted successfully \n");
     fclose(fp);
     fclose(fp1);

    }
    if(!found)
    {
        printf("\n\t\t\t\t Student not found :");

    }

    getch();

}
