//@DEV. FEB 19 2020.
//voters Part Written By @Vikrant. FEB 19 2020.
//candidates and voting parts by @JEEVAN+@PRAJWOL.
//further edits and improvements by @PRAJWOL.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>//to show current time
int i,j,k;
 typedef struct candidates
  {char lastname[20],firstname[30],month[10];
     char sex[1];
     int day,year;
  char address[100],nationality[10]};
struct candidates candidate;
 typedef struct voters
  { char lastname[20],firstname[30];
     char sex;
     char roll[10];
    char address[100],nationality[10]};
struct voters voter;
struct candidates candidate;
int main()
{
initial();
anykey();
    return 0;
}

void initial()
{
   int i;
   system("color A");
   Sleep(500);
   printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tLoading:");
   for (i = 0; i <= 7; i++)
   {
      Sleep(200);
      printf(".");

      if (i == 5)
      {
         Sleep(150);
         printf("HI THERE! LET'S ROCK AND ROLL!");
         system("color 4");
         system("color 6");
         system("color 2");
         system("color 0A");
         system("color 4F");
         system("color 6");
         system("color 2E");
         system("color 00");

      }
   }
}


void time_in_patan()
{
   struct t * local;
   time_t t = time(NULL);
   local = localtime(&t); // Get the localtime
   printf("\t\t\t\tTime Right Now In Patan!:: %s\n\n\n\n  ", asctime(local));
}


void anykey()
{
   system("cls");
   system("color F");
   printf("\n\n\n\n\t\t-----Welcome to eMatadaan.c!!-----\n\n\n\n\n");
   printf("\n\n\t\tThis program was jointly developed by:");
   printf("\n\t\t\t-DEVRAJ PARAJULI  (076BEI013)");
   printf("\n\t\t\t-JEEVAN KOIRI     (076BEI016)");
   printf("\n\t\t\t-PRAJWOL PRADHAN  (076BEI023)");
   printf("\n\t\t\t-VIKRANT PANJIYAR (076BEI048)");



   printf("\n\n\n\n\n\n\n\t\t..........Press Enter Key To Continue............\t");
   char name;
 //name=getchar();

  if (name=getchar())
  {
      menu();
  }

}


void menu()
{
   int getKey;
   system("cls");
   time_in_patan();
   printf("::Please press the specified keys to proceed!!::\n\n");
   printf("\t:Voter Management      [1]\n");
   printf("\t:Candidate Management  [2]\n");
   printf("\t:Start Voting          [3]\n\n");


  chooseOpt_menu:
   printf("\t\tChoose an Option:: ");
   scanf("%d", &getKey);

   switch (getKey)
   {

     case 1:
	     printf("\n\t\tLoading:");

       for (i = 0; i < 6; i++)
       {
         printf("-");
         Sleep(250);
       }

      system("cls");

       voterMgmt();

      break;


   //-----------------------------------------

     case 2:
     	 printf("\n\t\tLoading:");

       for (i = 0; i < 6; i++)
       {
         printf("-");
         Sleep(250);
       }

      system("cls");

       candidateMgmt();

      break;


     //-----------------------------------------


     case 3:
        printf("\n\t\tLoading:");

       for (i = 0; i < 6; i++)
       {
         printf("-");
         Sleep(250);
       }

      system("cls");

       votingDay();

      break;

     //-----------------------------------------


     default:
      {
         printf("\t\tKey Invalid!!\n");
         goto chooseOpt_menu;

      }
   }
}


void candidateMgmt()
{
   system("cls");
   time_in_patan();

  char datas[6][40] = {
      	"Add Candidate",
      	"Search Candidate",
      	"See Canditates' list",
      	"Delete All Candidate Record",
      	"Return to Menu"
   };

   printf("\n\tSelect any one to proceed::\n\n");

   for (i = 0; i < 5; i++)
   {

     for (j = 0; j < 3; j++)
     {
         printf("\t");
     }

     printf("[%d] %s\n",  i + 1, datas[i]);
   }

   printf("\n\n\t\t\tEnter key::");

  dev: //for goto statement
      scanf("%d", &k); //get key

  switch (k)
  {

    case 1:		//Add candidate(s)
      {
         printf("Please Give us your Correct Information:\n");
         system("cls");
         Newcandidates();
      }

      break;

   	case 2:
      search_candidates();
      break;

    case 3:
      see_candidates_list();
      break;

    case 4:
      delete_candidates();
      break;

    case 5:
      menu();

   default:
      {
         printf("\n\n\t\t\tInvalid Key!!\nChoose Again::");
         goto dev;
      }
   }
}


void Newcandidates() 		//a many people can be added.
{
   FILE *ptr = fopen("candidatesInfo.txt", "ab+");
   if (ptr == NULL)
   {
      printf("Error!!");
   }

   fflush(stdin);

    printf("Enter Candidates LastName::\n");
    scanf("%s", candidate.lastname);

  	printf("Enter Candidates FirstName::\n");
   	scanf("%s", candidate.firstname);

   	printf("Enter his/her gender(M/F)::\n");
   	scanf("%s", candidate.sex);

    printf("Enter Date Of Birth:: format eg. 1945/01/01 ::\n");
    scanf("%d/%d/%d", &candidate.year, &candidate.month, &candidate.day);

    printf("Enter full Address in a line::\n");
    scanf("%s", candidate.address);

   printf("Enter Nationality::\n");
   scanf("%s", candidate.nationality);

   fwrite(&candidate, sizeof(candidate), 1, ptr);
   fclose(ptr);
   Sleep(500);
   printf("\nThe record is sucessfully added.\n");
   Sleep(1000);

   int i;
   printf("\t\tProcess returning to main Panel::");

  for (i = 4; i > 0; i--)
  {
     printf("-", i);
     Sleep(200);
  }
   system("cls");

   candidateMgmt();

}


void search_candidates() {
   system("cls");
   printf("Search Candidate Record::\n\n");
   char rec[25]; //
   int isFound = 0;
   printf("\t\tEnter a candidate's name to Search: ");
   fflush(stdin);
   gets(rec);
   FILE *fptr;
   FILE *ptr = fopen("candidatesInfo.txt", "rb");

   while (fread(&candidate, sizeof(candidate), 1, ptr) == 1)
   {
      if (strcmp(rec, candidate.firstname) == 0)
      {
         isFound = 1;
         break;
      }
   }

   if (isFound == 1)
   {
      printf("\t\tRecord Found::\n\n");
      printf("\t\tLastname: %s\n", candidate.lastname);
      printf("\t\tFirstname: %s\n", candidate.firstname);
      printf("\t\tSex: %s\n", candidate.sex);
      printf("\t\tDate of Birth: %04d/%02d/%02d\n", candidate.year, candidate.month, candidate.day);
      printf("\t\tAddress: %s\n", candidate.address);
      printf("\t\tNationality: %s\n", candidate.nationality);
      Sleep(1000);
      printf("\t\tSystem returning to main Panel:");

     for (i = 0; i < 6; i++)
     {
         printf(".");
         Sleep(200);
     }
      system("cls");

     candidateMgmt();
   }

  else
  {
      printf("Sorry, No record found in the database");
      Sleep(1000);
      printf("\n\n\t\tSystem returning to main Panel:");

    for (i = 0; i < 6; i++)
	{
         printf(".");
         Sleep(200);
    }
      system("cls");

    candidateMgmt();
  }

   fclose(ptr);
}


void delete_candidates()
{
   system("cls");
   int count = 0;
   printf("This Section is Secured by admin:\nPlease Enter Admin Password to Proceed !:: Here password is 1532::!");

  marina:
      count++;
   printf("\n\n\t\tEnter Password:: ");
   int pass = 1532;
   int get;

   scanf("%d", &get);

   if (get == pass)
   {
      system("cls");
      printf("Password Match:\nThe process will remove all the data from CandidateInfo.txt:");

      FILE *ptr;
      ptr = fopen("candidatesInfo.txt", "ab+");
      fflush(stdin);
      fclose(ptr);
      remove("candidatesInfo.txt");
      fflush(stdin);
      FILE *fp = fopen("candidatesInfo.txt", "ab+");



     //---------------------------------
    if (fp != NULL)			//----------------
      {

         Sleep(1000);
         printf("The records were sucessfully deleted");
      }

      printf("\n\n\t\tSystem returning to main Panel:");

     for (i = 0; i < 6; i++)
     {
         printf(".");
         Sleep(500);
     }
      system("cls");
      candidateMgmt();
      fclose(fp);

   }
  else
  {
      while (count < 4)
      {
         printf("\nInvalid Password!! Try Again. You have %d chance left to login:", 4 - count);
         goto marina;

      }
      printf("\n\nProcess Returning to main Panel! Get Back and Try Again to Proceed!!\n\n");

    for (i = 0; i < 6; i++)
    {
         printf(".");
         Sleep(500);
    }
      system("cls");
      candidateMgmt();
   }
}


void see_candidates_list()
{
   system("cls");
   int count = 0;
   FILE *ptr;
   ptr = fopen("candidatesInfo.txt", "r");
   printf(":::::::Candidate List::::::\n");

  while (fread(&candidate, sizeof(candidate), 1, ptr) == 1)
   {
      count++;
      printf("\n\nCandidate %d::\n\n",count);

      printf("\t\t\tFirstname: %s\n",candidate.firstname);
      printf("\t\t\tLastname: %s\n",candidate.lastname);
      printf("\t\t\tSex: %s\n",&candidate.sex);
      printf("\t\t\tDate of Birth: %04d/%02d/%02d\n",candidate.year, candidate.month, candidate.day);
      printf("\t\t\tAddress: %s\n",candidate.address);
      printf("\t\t\tNationality: %s\n\n",candidate.nationality);
      Sleep(500);
   }

   if (count == 0)
   {
      printf("No Candidate record listed::\n");
      printf("\t\tSystem returning to main Panel:");

     for (i = 0; i < 5; i++)
     {
         printf("-");
         Sleep(200);
     }

     system("cls");
     candidateMgmt();

   }

  else
  {
      char ch;
      printf("\tPress Enter Key to goto main Menu:");
      ch = getchar();

    if (getchar())
    {
         printf("\t\tSystem returning to main Panel:");

      for (i = 0; i < 5; i++)
      {
            printf("-");
            Sleep(200);
      }

      system("cls");
      candidateMgmt();
  	}

    else
    {
         system("cls");
         candidateMgmt();
    }
   }
   fclose(ptr);
}



//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------

void voterMgmt()
{
    int count=0;

   system("cls");
   chooseOpt_voter:
      time_in_patan();

   char datas[5][20] = {
      "Add Voter",
      "Search Voters",
      "See Voters' List",
      "Delete all Voters",
      "Return to Main Menu"
   };           //datas has the memebers that are enclosed in " "

   printf("\n\tSelect any one to proceed::\n\n");

   for (i = 0; i < 5; i++)
   {
      for (j = 0; j < 4; j++)
      {
         printf("\t");
      }
      printf("[%d]  %s\n", i + 1, datas[i]);

   }

   printf("\n\n\t\t\tEnter key::");
   ment: //for goto statement
      scanf("%d", &k); //get key

  switch (k)
  {
      system("cls");

    case 1:
      {
         FILE *ptr1 = fopen("votersInfo.txt", "ab+");

        if (ptr1 == NULL)
        {
            printf("Error!!");
        }

         fflush(stdin);
        system("cls");
        printf("Enter Voter LastName::\n");
         scanf("%s", voter.lastname);

        printf("Enter Voter FirstName::\n");
         scanf("%s", voter.firstname);

        printf("Enter his/her gender::type M or F::\n");
         scanf("%s", voter.sex);

        printf("Enter Voter ID or Std Roll number::eg.076BEI049:: \n");
         scanf("%s", voter.roll);

       printf("Enter full Address in a line::\n");
         scanf("%s", voter.address);

        printf("Enter Nationality::\n");
         scanf("%s", voter.nationality);


         printf("\r\n");


        fwrite(&voter, sizeof(voter), 1, ptr1);
         fclose(ptr1);
         Sleep(500);
         printf("\nThe record is sucessfully added to votersInfo.txt.\n");

         count++;

         Sleep(1000);
         int i;
         printf("\t\tProcess returning to main Panel::");
         for (i = 4; i > 0; i--)
         {
            printf("-", i);
            Sleep(200);
         }
         system("cls");
         goto chooseOpt_voter;
      }
      break;

   case 2:
      {
         system("cls");
         printf("Search Voters Record::\n\n");
         char rec[25]; //
         int search_counter = 0;
         printf("\t\tEnter Voter Id or std Rollnum to Search::eg.076BEI049::\n");
         fflush(stdin);
         gets(rec);
         FILE *ptr1 = fopen("votersInfo.txt", "rb");

         while (fread(&voter, sizeof(voter), 1, ptr1) == 1)
         {
            if (strcmp(rec, voter.roll) == 0)
            {
               search_counter = 1;
               break;
            }
         }

         if (search_counter == 1)
         {
            printf("\t\tVoter Record Found:\n\n");
            printf("\t\tLastname: %s\n", voter.lastname);
            printf("\t\tFirstname: %s\n", voter.firstname);
            printf("\t\tSex: %s\n", voter.sex);
            printf("\t\tVoter ID: %s\n", voter.roll);
            printf("\t\tAddress: %s\n", voter.address);
            printf("\t\tNationality: %s\n", voter.nationality);
            Sleep(1000);
            printf("\t\tSystem returning to main Panel:");

           for (i = 0; i < 6; i++)
           {
               printf(".");
               Sleep(200);
           }
            system("cls");
            goto chooseOpt_voter;
         }

         else
         {
            printf("Sorry, No record found in the database");
            Sleep(1000);
            printf("\n\n\t\tSystem returning to main Panel:");

           for (i = 0; i < 6; i++)
		   {
               printf(".");
               Sleep(200);
           }
            system("cls");
            goto chooseOpt_voter;
         }
         fclose(ptr1);
      }
      break;

    case 3:
      system("cls");
        count=0;

      FILE *ptr1;
      ptr1 = fopen("votersInfo.txt", "r");
      printf(":::::::Voters List::::::\n");

      while (fread(&voter, sizeof(voter), 1, ptr1) == 1)
      {
         count++;
         printf("Voter number %d:", count);
         printf("\n\t\tVoter Name: %s %s\n", voter.firstname, voter.lastname);
         printf("\t\tSex: %s\n", voter.sex);
         // printf("\t\tID= %s",voter.roll);
         printf("\t\tAddress: %s\n", voter.address);
         printf("\t\tNationality: %s\n\n", voter.nationality);
         Sleep(1000);
      }

      if (count == 0)
      {
         printf("No voter found::\n");
         printf("\t\tSystem returning to main Panel:");

        for (i = 0; i < 5; i++)
        {
            printf("-");
            Sleep(200);
        }

         system("cls");
         goto chooseOpt_voter;
      }

      else
      {
         char ch;
         printf("\tPress Enter Key to Goto Main Menu:");
         ch = getchar();

        if (getchar())
        {
            printf("\t\tSystem returning to main Panel:");

          for (i = 0; i < 5; i++)
          {
               printf("-");
               Sleep(200);
          }

            system("cls");
            goto chooseOpt_voter;
         }

         else
         {
            system("cls");
            goto chooseOpt_voter;
         }
      }
      fclose(ptr1);
      break;

    case 4:
      {
         system("cls");
         count = 0;
         printf("This Section is Secured by admin:\nPlease Enter Admin Password to Proceed !::Here password is 1532::!");

         marina:
         count++;
         printf("\n\n\t\tEnter Password:: ");
         int pass = 1532;
         int get;

         scanf("%d", &get);

        if (get == pass)
        {
            system("cls");
            printf("Password Match:\nThe process will remove all the data from CandidateInfo.txt:");

            FILE *ptr1;
            ptr1 = fopen("votersInfo.txt", "ab+");
            fflush(stdin);
            fclose(ptr1);
            remove("votersInfo.txt");

            FILE *fp = fopen("votersInfo.txt", "ab+");

           if (fp != NULL)
           {
               fflush(stdin);
               Sleep(1000);
               printf("The records were sucessfully deleted");
           }

        	 printf("\n\n\t\tSystem returning to main Panel:");

          	for (i = 0; i < 6; i++)
            {
            	printf(".");
              	Sleep(500);
            }

            system("cls");
            goto chooseOpt_voter;
            fclose(fp);
         }


         else
         {
            while (count < 4)
            {
               printf("\nInvalid Password!!...You have %d chance(s) left to login:", 4 - count);
               goto marina;

            }

            printf("\n\nProcess Returning to main Panel! Get Back and Try Again to Proceed!!\n\n");

            for (i = 0; i < 6; i++)
            {
               printf(".");
               Sleep(500);
            }
            system("cls");
            goto chooseOpt_voter;
         }
      }
      break;

   case 5:
      {
         menu();
      }

   default:
      {
         printf("\n\n\t\t\tInvalid Key!!Choose Again::");
         goto ment;
      }
   }



}



//-----------------------------------------

//voting starts:

void votingDay()
{
    int a[26] = {0};
    int choice_candidate;
    int password;
    int id_num;
    int getChoice;

    int voterNumber = 0, voterCount = 0, candidateCount = 0;


     printf("\n\n\t\tMaking sure that the number of voters and the candidates is not zero.\n\n");
     printf("\t\t\t    ------Please Wait");
       for (i = 0; i < 6; i++)
       {
         printf("-");
         Sleep(250);
       }



       //Check for voters:

        FILE *ptr1;
        ptr1 = fopen("votersInfo.txt", "r");

        while (fread(&voter, sizeof(voter), 1, ptr1) == 1)
        {
            voterCount++;
        }
        fclose(ptr1);


       //Check for candidates:

       FILE *ptr;
            ptr = fopen("candidatesInfo.txt", "r");

       while (fread(&candidate, sizeof(candidate), 1, ptr) == 1)
        {
            candidateCount++;
        }
        fclose(ptr);


       printf("\n\n\n\n\tResult::\n\n");

       printf("\t  Number of Voters = %d\n", voterCount);

       printf("\t  Number of Candidates = %d\n\n", candidateCount);

       Sleep(2000);




    if(voterCount == 0 || candidateCount == 0)
    {

        if(voterCount == 0)
        {
            printf("\n\n\n\tThe number of voters is zero.");
            printf("\n\tPlease add some voters.\n\n");
        }


        if(candidateCount == 0)
        {
            printf("\n\n\n\tThe number of candidates is zero.");
            printf("\n\tPlease add some candidates.\n\n");
        }



            printf("\n\n\n\tYOU WILL BE SHORTLY REDIRECTED TO THE MAIN MENU.\n");
            Sleep(4500);
            printf("\n\n\t\t------Please Wait");

            for (i = 0; i < 6; i++)
            {
                printf("-");
                Sleep(250);
            }


            menu();

    }        //end of if for voterCount||candidateCount==0




    //!start of else part:


    voterNumber = voterCount;

    while (voterNumber!=0)
    {
        voting:

        system("cls");
        time_in_patan();
        printf ("......WELCOME TO VOTING PROCESS.......\n\n");


        printf ("\nEnter your ID: ");
        scanf ("%d", &id_num);


        printf ("\nEnter your Password: ");
        scanf ("%d", &password);


        //------------------

/*
        char rec[25];
         int search_counter = 0;

         fflush(stdin);
         gets(rec);
         FILE *ptr1 = fopen("votersInfo.txt", "rb");

         while (fread(&voter, sizeof(voter), 1, ptr1) == 1)
         {
            if (strcmp(rec, voter.roll) == 0)
            {
               search_counter = 1;
               break;
            }
         }

         if (search_counter == 1)
         {
            printf("\t\tVoter Record Found:\n\n");
            printf("\t\tLastname: %s\n", voter.lastname);
            printf("\t\tFirstname: %s\n", voter.firstname);
            printf("\t\tSex: %s\n", voter.sex);
            printf("\t\tVoter ID: %s\n", voter.roll);
            printf("\t\tAddress: %s\n", voter.address);
            printf("\t\tNationality: %s\n", voter.nationality);
            Sleep(1000);
            printf("\t\tSystem returning to main Panel:");

           for (i = 0; i < 6; i++)
           {
               printf(".");
               Sleep(200);
           }
            system("cls");

         }

         else
         {
            printf("Sorry, No record found in the database");
            Sleep(1000);
            printf("\n\n\t\tSystem returning to main Panel:");

           for (i = 0; i < 6; i++)
		   {
               printf(".");
               Sleep(200);
           }
            system("cls");

         }
         fclose(ptr1);


    */
        //------------------

        if (password == id_num)
        {
            system ("cls");
            int count=0;

            FILE *ptr;
            ptr = fopen("candidatesInfo.txt", "r");

            if (ptr == NULL)
            {
                printf("\nERROR\n!");

            }


                printf(":::::::Candidate List::::::\n");
                printf ("\n______________________________________________\n");


                while (fread(&candidate, sizeof(candidate), 1, ptr) == 1)
                {
                    count++;
                    printf("\nCandidate %d::", count);

                    printf("\t%s %s\n", candidate.firstname, candidate.lastname);

                }
            fclose(ptr);


            Sleep(500);
            printf ("\n\t  %d::\tNONE\n", count+1);

            printf ("\n______________________________________________\n");

            printf ("\n\n\tEnter Your choice: ");
            scanf ("%d", &choice_candidate);




            switch (choice_candidate)
            {
                case 1:
                    a[0] += 1;
                    break;

                case 2:
                    a[1] += 1;
                    break;

                case 3:
                    a[2] += 1;
                    break;

                case 4:
                    a[3] += 1;
                    break;

                case 5:
                    a[4] += 1;
                    break;

                case 6:
                    a[5] += 1;
                    break;

                case 7:
                    a[6] += 1;
                    break;

                case 8:
                    a[7] += 1;
                    break;

                case 9:
                    a[8] += 1;
                    break;

                case 10:
                    a[9] += 1;
                    break;

                case 11:
                    a[10] += 1;
                    break;

                case 12:
                    a[11] += 1;
                    break;

                case 13:
                    a[12] += 1;
                    break;

                case 14:
                    a[13] += 1;
                    break;

                case 15:
                    a[14] += 1;
                    break;

                case 16:
                    a[15] += 1;
                    break;

                case 17:
                    a[16] += 1;
                    break;

                case 18:
                    a[17] += 1;
                    break;

                case 19:
                    a[18] += 1;
                    break;

                case 20:
                    a[19] += 1;
                    break;

                case 21:
                    a[20] += 1;
                    break;

                case 22:
                    a[21] += 1;
                    break;

                case 23:
                    a[22] += 1;
                    break;

                case 24:
                    a[23] += 1;
                    break;

                case 25:
                    a[24] += 1;
                    break;

                case 26:
                    a[25] += 1;
                    break;

         //------------------------------------------------------


                case 1532:	//This is the password to terminate the voting process and show the result, 1532 is the password
                    system("cls");

                   printf("\n\n\n\n\n\n\tYou typed the admin password. This will end the voting process.\n\n\n");

                    printf("\n\t [1] Main Menu");
                    printf("\n\t [2] Result of Voting");


                    printf("\t  Please choose an option:: ");
                    scanf("%d", &getChoice);

                   if(getChoice == 1)
                   {
                       printf("\n\n\n\t You will be taken to the Main Menu now.\n");
                       Sleep(300);
                       menu();
                   }

                   else if(getChoice == 2)
                    {

                        goto end;
                    }



            }
            voterNumber--;

            printf("\n\n\t\tThank you for voting!\a\n");
            Sleep(300);

        }



        else
        {
            printf ("\n\t You Entered Wrong Password!!\n");
            Sleep(300);

            goto voting;
        }


    }   //closes while
 if (voterNumber == 0)
    {
        printf("\n\n\tThe voting process is over.\n");
        Sleep(200);

        printf("\n\n\t\t------Please Wait");

            for (i = 0; i < 6; i++)
            {
                printf("-");
                Sleep(250);
            }

        goto end;
    }


        end:
           votingResult(a, 26);


}   //closes votingday function







void votingResult(int *x, int candidate_no)
{
    int adminPw = 1532;
    int getPw;
    int choiceResult;
    int i;

    system("cls");

    printf("\n\n\n\n\n\n\t\tEnter the admin password to access the result of voting (password: 1532): ");
    scanf("%d", &getPw);


    if(getPw == adminPw)
    {

        system("cls");

        selOpt:

        printf("\n\n\n\n\n\t\tHow do you want the result to be displayed?\n");
        printf("\t\t[1]  List\n");
        printf("\t\t[2]  Bar Graph\n");

        printf("\n\t\tEnter your choice:: ");
        scanf("%d", &choiceResult);



        switch(choiceResult)
        {
            case 1:
                goto listView;

                break;

            case 2:
                system("cls");
                printf("\n\n\n\n\n\n\t\tRESULT OF VOTING::");
                printf("\n\n\t---BAR GRAPH---::\n\n");

                graph(x, 26);
                break;

            default:
                printf("\n\n\t\tPlease enter valid choice.\n\n");
                goto selOpt;    //takes above to choose an option again
        }



		listView:
		   system("cls");
                printf("\n\n\n\n\n\n\t\tRESULT OF VOTING::");
                printf("\n\n\t ---LIST---::\n\n");
                printf("\n (Candidates with no votes will not be displayed)\n\n");
                //result in list form

                for(i = 0; i <= (candidate_no-1); i++)
                {
                    if(x[i] != 0)
                    {
                        printf("\n\tCandidate %d :: %d votes\n\n", i+1, x[i]);
                    }

                }

    }
}




void graph (int *p, int candidate_no)
{
    int i, j;





    for(i = 0; i <= (candidate_no-1); i++)
        {
            if(p[i] != 0)
            {
                printf("\n\xB1");

                    for(j=1; j<=p[i]; j++)
                    {
                        printf("\xB1");
                    }

            printf(" :: %d votes (Candidate %d) \a", p[i], i+1);
            printf("\n");
            }
        }
getch();
}
