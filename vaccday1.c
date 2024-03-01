#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>

//declaring the functions
void instructionspage();    //instructions page function
void userlogin(void);       //Login function
void vaccine_book();        //Vaccine booking function
void vaccine_cancel();      //Vaccine slot cancellation function
void vaccine_status();      //vaccination status function
void vacinfo();                //vaccination information function

//structure to store User's login as well as basic data
struct user
{
    char username[10];
    char password[10];
    char realname[50];
    char gender[10];
    char age[10];
    char phone_no[20];
    char blood_group[10];
}*pUser;


int main()
{
    //initializing the variables
    char a_no[20];
    char uName[10], pwd[10];
    int i;
    int trial;
    char c;
    int vxchoice;


    printf("========================================================================================================================");
    printf("\n\n\t\t\t\t\t::::::::::::::::::::::::::\t\t\t");
    printf("\n\t\t\t\t\t:  WELCOME TO E-VACCINE  :\n");
    printf("\t\t\t\t\t::::::::::::::::::::::::::\t\t\t\n");
    printf("\n\t\t\t\t    A digital platform to book vaccines\n");

    FILE *fp;   //Initializing file pointer fp

    pUser=(struct user *)malloc(sizeof(struct user));
    printf(".......................................................................................................................");
    printf("\n\n\t\t\t\t\t      |LOGIN/SIGN UP|\n\n");
    printf("\n\n1. Login Through An Existing Account\n2. Create New account\n\n");
    scanf("%d",& i);

    //Start of the outer switch case
    switch(i)
    {
            case 1:   //This case is for User login

            {
                if ( ( fp=fopen("user.dat", "r+")) == NULL)

               {
                    if ( ( fp=fopen("user.dat", "w+")) == NULL)
                    {
                    printf ("Could not open file\n");
                    exit (1);
                    }
                }

            printf("\nUsername: ");
            scanf("%9s",uName);
            printf("Password: ");
            scanf("%9s",pwd);

            //Start of the while loop
            while ( fread (pUser, sizeof(struct user), 1, fp) == 1)
                {
                if( strcmp ( pUser->username, uName) == 0)      //Checking the Username entered with the Username stored
                {
                    printf ("\nusername matched");
                    if( strcmp ( pUser->password, pwd) == 0)    //Checking the Password entered with the Password stored
                    {
                        printf ("\npassword verified");

                        //Here, if the entered username and the password matches with the username and password stored then it gives access to the all the functions

                        printf("\n========================================================================================================================");
                        printf("\n\t\t\t\t\t\t|WELCOME TO EVAX|\n\n");

                        printf("\n\t\t\t\t\tPLEASE ENTER YOUR CHOICE TO CONTINUE");

                        instructionspage();     //Calling the instructions page

                        scanf("%d",&vxchoice);  //Accepting the choice to perform actions

                        //inside switch for performing all the functions start
                        switch(vxchoice)
                        {

                            case 1: //This case will show the user's data
                              printf(".......................................................................................................................");
                              printf("\n\n\t\t\t\t\t\t   |DETAILS|\n\n");
                              fflush(stdin);
                              printf("\n Your Details:");
                              printf("\n\n\n Full Name:          %s",pUser->realname);            //displaying the name of user
                              printf("\n Age:           %s",pUser->age);                  //displaying the age
                              printf("\n Gender:        %s",pUser->gender);            //displaying the gender
                              printf("\n Blood group:   %s",pUser->blood_group);    //displaying the blood group
                              printf("\n Phone Number:  %s",pUser->phone_no);    //displaying the phone number
                              getch();
                              break;

                            case 2: //This case for booking the vaccine slot
                              printf(".......................................................................................................................");
                              printf("\n\n\n\t\t\t\t\t|WELCOME TO THE EVAX SLOT BOOKING PAGE|\n\n");
                              fflush(stdin);

                              vaccine_book();   //Calling the vaccine_book() function which books the user's vaccination slot
                              break;

                            case 3: //This case is for vaccine slot cancellation
                              printf(".......................................................................................................................");
                              printf("\n\n\t\t\t\t\t|WELCOME TO THE EVAX SLOT CANCELLATION PAGE|\n\n");
                              fflush(stdin);

                              vaccine_cancel();    //Calling the vaccine_cancel() function which cancels the user's booked slot
                              break;

                            case 4: //This case is to check the user's vaccination Status
                              printf(".......................................................................................................................");
                              printf("\n\n\t\t\t\t\t|WELCOME TO THE VACCINATION STATUS PAGE|\n\n");
                              fflush(stdin);

                              printf("\n\t Name: %s",pUser->realname);            //displaying the name of user
                              printf("\t Age: %s",pUser->age);                  //displaying the age
                              printf("\t Gender: %s",pUser->gender);            //displaying the gender
                              printf("\t Blood group: %s\n",pUser->blood_group);    //displaying the blood group

                              vaccine_status();     //Calling the vaccine_stat function which shows the vaccine status of the user
                              break;

                            case 5: //This case is to view the basic information about vaccination
                              printf(".......................................................................................................................");
                              fflush(stdin);
                               vacinfo();   //calling the vacinfo() function which has vaccine related information
                               getch();
                              break;

                        }   //Inside switch case ends

                    }
                }
            }   //End of while loop

            }
            break;


        case 2:     //This case for the account creation
             {
                do  //do-while starts
                {
                    if ( ( fp=fopen("user.dat", "a+")) == NULL)     //to check whether there is a file created
                    {
                        if ( ( fp=fopen("user.dat", "w+")) == NULL)
                        {
                        printf ("Could not open file\n");
                        exit (1);
                        }
                    }

                printf("Choose A Username: ");
                fflush(stdin);
                scanf("%9s",pUser->username);   //Accepting Username to store

                printf("Choose A Password: ");
                fflush(stdin);
                scanf("%9s",pUser->password);   //Accepting Password to store

                //For details of the user

                printf("\n\nEnter your name: ");
                fflush(stdin);
                gets(pUser->realname);
                //scanf("%s",pUser->realname);    //Accepting the User's name to store

                printf("Enter your Age: ");       //Accepting the User's age
                gets(pUser->age);

                fflush(stdin);

                printf("Enter your Gender: ");     //Accepting the User's gender
                gets(pUser->gender);

                fflush(stdin);
                printf("Enter your Blood group: ");    //Accepting the User's blood group
                gets(pUser->blood_group);


                fflush(stdin);
                printf("Enter your Phone number: ");    //Accepting the User's phone number
                gets(pUser->phone_no);

                fwrite(pUser,sizeof(struct user),1,fp);

                FILE *f_point;      //Creating a new filepointer for the aadhaar number
                printf("\nEnter your Aadhaar number : ");
                fflush(stdin);
                gets(a_no);         //Accepting the Aadhaar number

                strcat(a_no,"vsta.txt");    //Creating a new file with aadhaar card as the name with .txt extension
                f_point = fopen(a_no,"w");   //opening the file in write mode
                fclose(f_point);

                fflush(stdin);

                printf("\nAdd another account? (Y/N): ");
                scanf("%c",&c);         //skip leading whitespace

                }
                while(c=='Y'||c=='y');    //This expression checks whether the user wants to add another account

            //do while loop ends
        }
    break;
    }   //Outer switch ends
    free ( pUser);//free allocated memory
    fclose(fp);

    fflush(stdin);
    system("cls");

    return 0;

}   //end of main function


//This function displays the instructions

void instructionspage()
{
    printf("\n\n select 1 For your details"
           "\n select 2 for Booking your vaccine slot"
           "\n select 3 to cancel your booking"
           "\n select 4 to View your vaccination status"
           "\n select 5 for Vaccine related information\n\n");
           fflush(stdin);
}

//This is the booking function
void vaccine_book()
{

    char adno[20];
    int vstat=0;
    FILE *filepointer;
     //printf("\n..............................................................................\n\n");
     //printf("\t\t\t| WELCOME TO THE EVAX SLOT BOOKING PAGE|\n\n")


    printf("\nPlease enter your Aadhaar number : ");
    gets(adno);        //Accepting the aadhaar numbers

    fflush(stdin);
    strcat(adno,"vsta.txt");
    puts(adno);
    filepointer = fopen(adno,"r+"); //used r+ to open the file in both reading and writing mode

    fscanf(filepointer,"%d",&vstat); // IMPORTANT! : we need to perform a scanf to make the pointer move...if there isn't something to fscanf then it won't move, retaining it's value as 0  (empty file , pointer still pointing at the start of the file)
	//... if there is something then after this fscanf the pointer will move giving out it's next position which would be 1 as we only have scanned one character.

    if(ftell(filepointer) == 0)    //ftell returns a long int by default
    {
        //printf("File is empty!");
        printf("\n\nSigning you up for 1st Dose!");
        fprintf(filepointer,"%d",1);
    }
    else if(ftell(filepointer) == 1)  //we are not checking the content of what we have scanned , just the position of the file pointer by using ftell, although for extra security you can simply add an and in this one to also check if in vstat 1 was scanned
    {
        //printf("File isn't empty!");
        printf("\n\nIt seems you've already got your first dose!\nSigning you up for the 2nd dose!");
        fprintf(filepointer,"%d",2);
    }
    else
    {
        printf("Congratulations you are fully vaccinated");
    }
    fclose(filepointer);
    getch();
}


//This is the vaccine slot cancellations
void vaccine_cancel()
{
    char adno[20];
    int vstat;
    FILE *filepointer;

    printf("\n\tPlease Enter your Aadhaar number : ");
    gets(adno);
    fflush(stdin);
    strcat(adno,"vsta.txt");
    filepointer = fopen(adno,"r+");   //used r+ file reading mode
    fscanf(filepointer,"%d",&vstat);// IMPORTANT! : we need to perform a scanf to make the pointer move...if there isn't something to fscanf then it won't move, retaining it's value as 0  (empty file , pointer still pointing at the start of the file)
					//... if there is something then after this fscanf the pointer will move giving out it's next position which would be 1 as we only have scanned one character.
    if(vstat==12)
    {
        printf("\n\tYour slot booked for the second dose is cancelled");
        fprintf(filepointer,"%d",1);
    }
    else if(vstat==121||vstat==1)  //we are not checking the content of what we have scanned , just the position of the file pointer by using ftell, although for extra security you can simply add an and in this one to also check if in vstat 1 was scanned
    {
        printf("\nYour slot booked for the first dose is cancelled");
        fprintf(filepointer,"%d",0);
    }
    else
    {
        printf("\n\tLooks like you haven't booked any slot for vaccination!");
        printf("\n\tFirst book your 1st dose");
    }
    fclose(filepointer);
    getch();
}


//For displaying the vaccination status
void vaccine_status()
{

    {
        char adno[20];
        int vstat;
        FILE *filepointer;

        printf("\n\tPlease Enter your Aadhaar number : ");
        gets(adno);
        fflush(stdin);
        strcat(adno,"vsta.txt");
        filepointer = fopen(adno,"r+");   //used r+ file reading mode
        fscanf(filepointer,"%d",&vstat);// IMPORTANT! : we need to perform a scanf to make the pointer move...if there isn't something to fscanf then it won't move, retaining it's value as 0  (empty file , pointer still pointing at the start of the file)
					//... if there is something then after this fscanf the pointer will move giving out it's next position which would be 1 as we only have scanned one character.
        if(vstat==12)
        {
            printf("\n\tYou are fully vaccinated");
        }
        else if(vstat==121||vstat==1)  //we are not checking the content of what we have scanned , just the position of the file pointer by using ftell, although for extra security you can simply add an and in this one to also check if in vstat 1 was scanned
        {
            printf("\n\tYou have received your first dose");
        }
        else
        {
            printf("\n\tLooks like you haven't booked any slot for vaccination!");
        }
    fclose(filepointer);
    getch();

}
}

//FOR VACCINE RELATED INFORMATION
void vacinfo()
{
    int gchoice;
    printf(".......................................................................................................................");
    printf("\n\n\t\t\t\t\t|WELCOME TO THE EVAX VACCINE INFORMATION PAGE|\n\n");
     printf("\n\t\t\t\t\t    Together,India will defeat COVID-19");
    printf("\n\n\n  Enter 1 for vaccination basic information.\n  Enter 2 to view some common vaccine side effects.\n  Please enter your choice to continue: ");
    scanf("%d",&gchoice);
    switch(gchoice)
    {
        case 1://vaccination guidelines
            printf("\n\n  Why get vaccinated?\n\n\n  A Covid vaccine might:\n\n  -> Prevent you from getting COVID-19 or from becoming seriously ill or dying of COVID-19."
                   "\n  -> Prevent you from spreading the COVID-19 virus to others."
                   "\n  -> Add to the number of people in the community who are protected from getting COVID-19."
                   "\n  -> Prevent the COVID-19 virus from spreading and replicating, which allows it to mutate \n     and possibly become more resistant to vaccines.\n"
                   );
                   break;
        case 2://vaccination side effects
            printf("\n\nCOVID-19 vaccines can cause mild side effects after the first or second dose, including:"
                   "\n  * Pain, redness or swelling where the shot was given"
                   "\n  * Fever\n  * Fatigue\n  * Headache\n  * Muscle pain\n  * Chills\n  * Joint pain\n  * Nausea and vomiting\n  * Swollen lymph nodes"
                   "\n  Most side effects happen within the first three days after vaccination and typically last only 1 to 2 days.\n"
                   );
                   break;
        default:
            printf("Invalid choice! Please try again.\n");
    }
}







































































