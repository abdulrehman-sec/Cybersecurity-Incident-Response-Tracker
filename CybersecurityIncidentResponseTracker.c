//==========================CYBERSECURITY INCIDENT RESPONSE TRACKER=============================
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void addIncident();
void Incidentrecord();   
void searchIncident();
void delete();

struct Incident{
    int Incident_id;        // Unique incident number
    char Incident_type[30]; // Malware, Phishing, DDoS, etc.
    char severity[10];      // Low, Medium, High                           
    char reported_by[30];   //Person or department            
    char date[15];          // Date of incident
    char status[20];        // Open / In Progress / Resolved
    char description[100];  // Short incident details
};
int main(){
    int choice;
    while(choice!=5){
        printf("\t\t\t====== CYBER SECURITY INCIDENT RESPONSE TRACKER======");
        printf("\n\n\n\t\t\t\t 1. Add Incident Record\n");
        printf("\t\t\t\t 2. Incident Record\n");
        printf("\t\t\t\t 3. Search Student\n");
        printf("\t\t\t\t 4. Delete Record\n");
        printf("\t\t\t\t 5. Exit\n");
        printf("\t\t\t____________________________________________________________\n");
        printf("\t\t\t\t ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
            system("cls");  
            addIncident();
            system("cls");
            break;

            case 2:

            system("cls");
            Incidentrecord();
            printf("\n\t\t\tPress any key to exit\n");
            getch(); 
            system("cls");
            break;


            case 3:
            system("cls");
            searchIncident();
            printf("\n\t\t\tPress any key to exit\n");
            getch(); 
            system("cls");
            break;

            case 4:
            system("cls");
            delete();
            printf("\n\t\t\tPress any key to exit\n");
            getch();
            system("cls");
            break;

            case 5:
            printf("\n\t\t\tThank you, for using this software. \n\n");
            break;

            default:
            getch();
            printf("\n\t\t\tEnter a valid number");
            printf("\n\t\t\tPress any key to continue .......\n");
            getch();
            break;
        }
    }
}
void addIncident(){
    char another;
    FILE *fp;  
    struct Incident info; 

    do{

        printf("\t\t\t\t======Add Incident Info======\n\n\n");
        fp=fopen("Incident_info", "a");  
        printf("\n\t\t\tEnter Incident ID: ");
        scanf("%d", &info.Incident_id);
        printf("\n\t\t\tEnter Incident Type: ");
        scanf("%s", &info.Incident_type);
        printf("\n\t\t\tEnter Severity: ");
        scanf("%s", &info.severity);
        printf("\n\t\t\tEnter Reported by: ");
        scanf("%s", &info.reported_by);
        printf("\n\t\t\tEnter Date: ");
        scanf("%s", &info.date);
        printf("\n\t\t\tEnter Status: ");
        scanf("%s", &info.status);
        printf("\n\t\t\tEnter Description: ");
        scanf("%s", &info.description);

        if(fp==NULL){
            fprintf(stderr, "\t\t\tCan't open file\n");
        }else{
            printf("\t\t\tRecord stored successfuly\n");
        }

        fwrite(&info,sizeof(struct Incident), 1, fp); 
        fclose(fp);                                   

        printf("\t\t\tDo you want to add another record?(y/n): " );
        scanf("%s", &another);

    }while(another =='y' || another == 'Y');
}

void Incidentrecord(){
    FILE *fp;
    struct Incident info;
    fp = fopen("Incident_info", "r");

    printf("\t\t\t\t======Incident Records======\n\n\n");

    if(fp==NULL){
        fprintf(stderr, "\t\t\t\tCan't open file\n");
    }else{
        printf("\t\t\t\tRecords\n");
        printf("\t\t\t\t________________\n\n");
    }

 while(fread(&info,sizeof(struct Incident), 1, fp)){
    printf("\n\t\t\t\tEnter Incident ID   : %d", info.Incident_id);
    printf("\n\t\t\t\tEnter Incident Type : %s", info.Incident_type);
    printf("\n\t\t\t\tEnter Severity      : %s", info.severity);
    printf("\n\t\t\t\tEnter Reported by   : %s", info.reported_by);
    printf("\n\t\t\t\tEnter Date          : %s", info.date);
    printf("\n\t\t\t\tEnter Status        : %s", info.status);
    printf("\n\t\t\t\tEnter Description   : %s", info.description);
    printf("\n\t\t\t\t__________________________________________\n");
    
 }
 fclose(fp);
 getch();
}
void searchIncident(){
    FILE *fp;
    struct Incident info;
    int Incident_id, found = 0;
    
    fp = fopen("Incident_info", "r");

    printf("\t\t\t\t======Search Incident======\n\n\n");
    printf("\t\t\tEnter Incident ID: ");
    scanf("%d", &Incident_id);

    while(fread(&info,sizeof(struct Incident), 1, fp)){
          if(info.Incident_id==Incident_id){
          found=1;
    printf("\n\t\t\t\tEnter Incident ID   : %d", info.Incident_id);
    printf("\n\t\t\t\tEnter Incident Type : %s", info.Incident_type);
    printf("\n\t\t\t\tEnter Severity      : %s", info.severity);
    printf("\n\t\t\t\tEnter Reported by   : %s", info.reported_by);
    printf("\n\t\t\t\tEnter Date          : %s", info.date);
    printf("\n\t\t\t\tEnter Status        : %s", info.status);
    printf("\n\t\t\t\tEnter Description   : %s", info.description);
    printf("\n\t\t\t\t__________________________________________\n");
    }
}
if(!found){
        printf("\n\t\t\tRecord not found\n");
    }
    fclose(fp);
    getch();

}

void delete(){
    FILE *fp, *fp1;
    struct Incident info;
    int Incident_id, found = 0;

    printf("\t\t\t\t======Delete Incident======\n\n\n");
    fp=fopen("Incident_info", "r");
    fp1=fopen("temp.txt", "w");
    printf("\t\t\tEnter Incident id: ");
    scanf("%d", &Incident_id);

    if(fp==NULL){
        fprintf(stderr, "\t\t\tCan't open file\n");
    }
    while(fread(&info, sizeof(struct Incident), 1, fp)){
        if(info.Incident_id==Incident_id){
            found = 1;
        }else{
            fwrite(&info,sizeof(struct Incident), 1, fp);
        }
    }

    fclose(fp);
    fclose(fp1);

    if(found){
        remove("Incident_info");
        rename("temp.txt", "Incident_info");
        printf("\n\t\t\tRecord deleted successfully\n");
    }
    if(!found){
        printf("\n\t\t\tRecord not found\n");
    }

getch();
}