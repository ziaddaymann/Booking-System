/*
 * main.c
 *
 *  Created on: Apr 27, 2023
 *      Author: ziadayman
 */



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <regex.h>


///////////////////////////// ************** Functions Prototype ******************///////////////////////


void Main_Menu ();
void Menu();
void Register ();
void Log_in ();
void forget_pass();
void Website();
void Prices ();
void Oneway();
void Roundtrip();
void Multiple();
void Flight();
void Start();


///////////////////////////// ************** Basic Information ******************///////////////////////

void Main_Menu ()
{
	printf ("\n****** Welcome to Booking.com ******\n");
    printf ("\nIf you want to register please enter a\n");
    printf ("\nIf you already have an account please enter b\n");
    printf ("\nIf you forgot your password enter y\n");
}


void Menu()
{
	printf ("\nBook Flight enter a\n");
    printf ("\nBook Hotel enter b\n");
    printf ("\nRent a car enter c\n");
    printf ("\nYour Bookings l\n");
	printf ("\nSign out enter d\n");
    printf ("\nChange Password enter f\n");
    printf ("\nDelete your account enter h\n");
}


void Register ()
{
	FILE *fp;
	char mail[50];
	char pass[50];
	char buffer[1024];
	char file[256] = "/Users/ziadayman/Desktop/Booking Site/Book1.txt";

//////////////////////////////Mail////////////////////////////////////////////////////
	printf ("Please enter your Email \n");
	scanf("%s", mail);
	char *find1 = strchr(mail, '@');
	char *find2 = strstr(mail, ".com");

	if (find1)
	{
		if (find2)
		{

		}
	}

	else
	{
		printf ("Invalid Mail\n");
		Start();
	}

	 fp = fopen(file, "r");
	    if (fp == NULL)
	    {
	        printf("Error opening file %s\n", file);
	    }

	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{
	        if (strstr(buffer, mail) != NULL)
	        {
	            printf("This mail is taken\n");
	            fclose(fp);
	            Start();
	            break;
	        }
	    }

//////////////////////////////Password////////////////////////////////////////////////////


	printf ("Please enter you Password \n");
	scanf ("%s",pass);

	if (strlen(pass) == 0)
	{
		printf ("Invalid Password\n");
		Register();
	}



//////////////////////////////Adding////////////////////////////////////////////////////


	fp = fopen(file, "a");

		if (fp == NULL)
		{
		        printf("Error opening file %s\n", file);
		}
		fprintf(fp, "%s:%s\n", mail, pass);

	fclose(fp);

	printf ("\nSign up successful\n");
}


void Log_in ()
{
	char mail[50];
	char pass[50];
	char buffer[1024];
	char f=0;
	char file[256] = "/Users/ziadayman/Desktop/Booking Site/Book1.txt";


//////////////////////////////Mail////////////////////////////////////////////////////

	printf ("Please enter your Email \n");
	scanf("%s", mail);

	char *find1 = strchr(mail, '@');
	char *find2 = strstr(mail, ".com");

	if (find1)
	{
		if (find2)
		{

		}
	}

	else
	{
		printf ("Invalid Mail\n");
		Start();
	}

//////////////////////////////Password////////////////////////////////////////////////////


	printf ("Please enter the password\n");
	scanf("%s",pass);

	if (strlen(pass) == 0)
	{
		printf ("Invalid Password\n");
		Start();
	}


//////////////////////////////File////////////////////////////////////////////////////

	FILE *fp = fopen(file, "r");
	    if (fp == NULL)
	    {
	        printf("Error opening file %s\n", file);
	    }

	    while (fgets(buffer, sizeof(buffer), fp) != NULL)
	    {

	        char *e = strtok(buffer, ":");
	        char *p = strtok(NULL, "\n");


	        if (strcmp(e, mail) == 0 && strcmp(p, pass) == 0)
	        {
	        	f=1;
	            fclose(fp);
	            break;
	        }
	    }
	    fclose(fp);
	    if (f)
	    {
	    	printf("\nLogin successful\n");
	    	f=0;
	    }
	    else
	    {
	    	printf ("\nLogin unsuccessful\n ");
	    	Start();
	    }
}


void forget_pass()
{
	FILE *fp;
	char mail[50];
	char pass[50];
	char buffer[1024];
	char file[256] = "/Users/ziadayman/Desktop/Booking Site/Book1.txt";
	char f=0;

//////////////////////////////Mail////////////////////////////////////////////////////

	printf ("Please enter your Email \n");
	scanf("%s", mail);

	char *find1 = strchr(mail, '@');
	char *find2 = strstr(mail, ".com");

		if (find1)
		{
			if (find2)
			{

			}
		}

		else
		{
			printf ("Invalid Mail\n");
			Register();
		}

//////////////////////////////File////////////////////////////////////////////////////

		 fp = fopen(file, "r");
		    if (fp == NULL)
		    {
		        printf("Error opening file %s\n", file);
		    }

		    while (fgets(buffer,sizeof(buffer), fp) != NULL)
		    {
		        char *ptr = strtok(buffer, ":");
		        if (strcmp(ptr, mail) == 0)
		        {
		            ptr = strtok(NULL, "\n");
		            strcpy(pass, ptr);
		            f=1;
		            break;
		        }


		    }

		    fclose(fp);

//////////////////////////////Password////////////////////////////////////////////////////


		    if (f)
		    {
		         printf("Your password is: %s\n", pass);
		         f=0;
		    }
		    else
		    {
		         printf("Email not found\n");
		         Start();
		    }
}


void Website()
{
	int run =1;
	char input;

	Menu();

	while (run == 1)
	{
		scanf("%c",&input);

		switch (input)
		{
		case 'a':
		case 'A': Flight();
		break;
		}
	}
}

///////////////////////////// ************** Flight Information ******************///////////////////////

void Prices ()
{
	printf ("\n  Economy :\n Adults: 1000\n Childs: 500\n\n Premium Economy:\n Adults: 2000\n Childs: 1000\n\n Business :\n Adults: 5000\n Childs: 3000\n\n First class :\n Adults: 10000\n Childs: 6500\n\n ");
}


void Oneway()
{
	FILE *fp , *tmp;
	char adults [1],childs[1],degree[1];
	char check,check1,ch;
	long long money;
	char input[1];
	char From[50];
	char To[50];
	int day,month,hours;
	int year;
	char buffer[1024];
	int f=0;
	char file[256] = "/Users/ziadayman/Desktop/Booking Site/Dates.txt";
	char file1[256] = "/Users/ziadayman/Desktop/Booking Site/Capitals.txt";

//////////////////////////////Data////////////////////////////////////////////////////


	printf ("\nFrom?\n");
	printf ("\nPlease enter full capital Name with first uppercase letter\n");

	scanf("%s",From);

	 fp = fopen(file1, "r");
	    if (fp == NULL)
	    {
	        printf("Error opening file %s\n", file1);
	    }

	    while (fgets(buffer, sizeof(buffer), fp) != NULL)
	    {
	        if (strstr(buffer, From) != NULL)
	        {
	            f=1;
	            fclose(fp);
	            break;
	        }
	    }
	    fclose(fp);

	    if (f)
	    {
	    	printf ("Founded\n");
	    	f=0;
	    }
	    else
	    {
	    	printf ("Invalid Capital\n");
	    	Flight();
	    }

	printf ("\nTo ?\n");

	printf ("\nPlease enter full capital Name with first uppercase letter\n");

	scanf("%s",To);

	 fp = fopen(file1, "r");
	    if (fp == NULL)
	    {
	        printf("Error opening file %s\n", file1);
	    }

	    while (fgets(buffer, sizeof(buffer), fp) != NULL)
	    {
	        if (strstr(buffer, To) != NULL)
	        {
	            f=1;
	            fclose(fp);
	            break;
	        }
	    }
	    fclose(fp);

	    if (f)
	    {
	    	printf ("Founded\n");
	    	f=0;
	    }
	    else
	    {
	    	printf ("Invalid Capital\n");
	    	Flight();
	    }


	printf ("\nDay ? xx\n");
	scanf("%d",&day);
	printf ("\nMonth ? xx\n");
	scanf("%d",&month);
	printf ("\nYear ? xxxx\n");
	scanf("%d",&year);
	printf ("\nHour ? xx\n");
	scanf("%d",&hours);

//////////////////////////////File////////////////////////////////////////////////////
	tmp = fopen(file, "r");
		    if (tmp == NULL)
		    {
		        printf("Error opening file %s\n", file);
		    }

		    char line[256];
		    int days, months, years, hour;
		    int n_matches;
		    char* pattern = "%d;%d;%d;%d";

		    while (fgets(line, sizeof(line), tmp)) {
		    n_matches = sscanf(line, pattern, &days, &months, &years, &hour);
		    if (n_matches == 4 && days == day && months == month && years == year && hour == hours) {
		    printf("Found date and time: %02d-%02d-%04d %02d:00\n", days, months, years, hour);
		    f = 1;
		    break;
		    }
		    }
		    fclose(tmp);


		    if (f)
		    {
		    	printf("\nThis flight is booked , Try Another Date\n");
		    	Oneway();
		    	f=0;
		    }


//////////////////////////////Money////////////////////////////////////////////////////

	    printf ("How many Adults ?\n");
	    scanf ("%s",adults);

	    check = atoi(adults);
		if (check == 0)
		{
			printf ("Error\n");
			Oneway();
		}

		else
		{
		    printf ("How many Childs ?\n");
		    scanf ("%s",childs);
		}

		check1 = atoi(childs);

		Prices();

		printf ("Enter your degree\n (Economy: 1 , Premium Economy: 2 , Business: 3 ,  First class: 4)\n");

		scanf ("%s",degree);
		ch = atoi(degree);

		switch (ch)
		{
		case 1:  money = (check * 1000) + (check1 *500);
		break;

		case 2:  money = (check * 2000) + (check1 *1000);
		break;

		case 3:  money = (check * 5000) + (check1 *3000);
		break;

		case 4:  money = (check * 10000) + (check1 *6500);
		break;
		}


        printf ("\nThe total money from %s to %s at %02d-%02d-%04d %02d:00 is %lld \n" , From , To , day , month , year , hours , money);


	    printf ("\nDo you want to continue Y/N\n");

        scanf ("%s",input);

	    	if ((strcmp(input, "y") == 0) || (strcmp(input, "Y") == 0))
	    	{
	    		printf ("\nBooked\n ");
	    	}
	    	else
	    	{
	    		Website();
	    	}

 //////////////////////////////Adding////////////////////////////////////////////////////

	    tmp = fopen(file, "a");

	    		if (fp == NULL)
	    		{
	    		        printf("Error opening file %s\n", file);
	    		}
	    		fprintf(fp, "\n%02d;%02d;%04d;%02d", day, month, year, hours);

	    	fclose(tmp);

	    	Website();




}


void Roundtrip()
{
	FILE *fp , *tmp;
	char adults [1],childs[1],degree[1],degree1[1];
	char check,check1,ch,ch1;
	long long money;
	long long money1;
	long long total;
	char input[1];
	char From[50];
	char To[50];
	int day,month,hours;
	int year;
	int day1,month1,hours1;
	int year1;
	char buffer[1024];
	int f=0;
	char file[256] = "/Users/ziadayman/Desktop/Booking Site/Dates.txt";
	char file1[256] = "/Users/ziadayman/Desktop/Booking Site/Capitals.txt";

//////////////////////////////Data////////////////////////////////////////////////////


	printf ("\nFrom?\n");
	printf ("\nPlease enter full capital Name with first uppercase letter\n");

	scanf("%s",From);

	 fp = fopen(file1, "r");
	    if (fp == NULL)
	    {
	        printf("Error opening file %s\n", file1);
	    }

	    while (fgets(buffer, sizeof(buffer), fp) != NULL)
	    {
	        if (strstr(buffer, From) != NULL)
	        {
	            f=1;
	            fclose(fp);
	            break;
	        }
	    }
	    fclose(fp);

	    if (f)
	    {
	    	printf ("Founded\n");
	    	f=0;
	    }
	    else
	    {
	    	printf ("Invalid Capital\n");
	    	Flight();
	    }

	printf ("\nTo ?\n");

	printf ("\nPlease enter full capital Name with first uppercase letter\n");

	scanf("%s",To);

	 fp = fopen(file1, "r");
	    if (fp == NULL)
	    {
	        printf("Error opening file %s\n", file1);
	    }

	    while (fgets(buffer, sizeof(buffer), fp) != NULL)
	    {
	        if (strstr(buffer, To) != NULL)
	        {
	            f=1;
	            fclose(fp);
	            break;
	        }
	    }
	    fclose(fp);

	    if (f)
	    {
	    	printf ("Founded\n");
	    	f=0;
	    }
	    else
	    {
	    	printf ("Invalid Capital\n");
	    	Flight();
	    }


			printf ("\nGoing Day ? xx\n");
			scanf("%d",&day);
			printf ("\nGoing Month ? xx\n");
			scanf("%d",&month);
			printf ("\nGoing Year ? xxxx\n");
			scanf("%d",&year);
			printf ("\nGoing Hour ? xx\n");
			scanf("%d",&hours);

		//////////////////////////////File////////////////////////////////////////////////////
			tmp = fopen(file, "r");
				    if (tmp == NULL)
				    {
				        printf("Error opening file %s\n", file);
				    }

				    char line[256];
				    int days, months, years, hour;
				    int n_matches;
				    char* pattern = "%d;%d;%d;%d";

				    while (fgets(line, sizeof(line), tmp)) {
				    n_matches = sscanf(line, pattern, &days, &months, &years, &hour);
				    if (n_matches == 4 && days == day && months == month && years == year && hour == hours) {
				    printf("Found date and time: %02d-%02d-%04d %02d:00\n", days, months, years, hour);
				    f = 1;
				    break;
				    }
				    }
				    fclose(tmp);


				    if (f)
				    {
				    	printf("\nThis flight is booked , Try Another Date\n");
				    	Roundtrip();
				    	f=0;
				    }


					printf ("\nComing Back Day ? xx\n");
					scanf("%d",&day1);
					printf ("\nComing Back Month ? xx\n");
					scanf("%d",&month1);
					printf ("\nComing Back Year ? xxxx\n");
					scanf("%d",&year1);
					printf ("\nComing Back Hour ? xx\n");
					scanf("%d",&hours1);

				//////////////////////////////File////////////////////////////////////////////////////
					tmp = fopen(file, "r");
						    if (tmp == NULL)
						    {
						        printf("Error opening file %s\n", file);
						    }

						    char line1[256];
						    int days1, months1, years1, hour1;
						    int n_matches1;
						    char* pattern1 = "%d;%d;%d;%d";

						    while (fgets(line1, sizeof(line1), tmp)) {
						    n_matches1 = sscanf(line1, pattern1, &days1, &months1, &years1, &hour1);
						    if (n_matches1 == 4 && days1 == day1 && months1 == month1 && years1 == year1 && hour1 == hours1) {
						    printf("Found date and time: %02d-%02d-%04d %02d:00\n", days1, months1, years1, hour1);
						    f = 1;
						    break;
						    }
						    }
						    fclose(tmp);


						    if (f)
						    {
						    	printf("\nThis flight is booked , Try Another Date\n");
						    	Roundtrip();
						    	f=0;
						    }


//////////////////////////////Money////////////////////////////////////////////////////

	    printf ("How many Adults ?\n");
	    scanf ("%s",adults);

	    check = atoi(adults);
		if (check == 0)
		{
			printf ("Error\n");
			Roundtrip();
		}

		else
		{
		    printf ("How many Childs ?\n");
		    scanf ("%s",childs);
		}

		check1 = atoi(childs);

		Prices();

		printf ("Enter your Going degree\n (Economy: 1 , Premium Economy: 2 , Business: 3 ,  First class: 4)\n");

		scanf ("%s",degree);
		ch = atoi(degree);

		switch (ch)
		{
		case 1:  money = (check * 1000) + (check1 *500);
		break;

		case 2:  money = (check * 2000) + (check1 *1000);
		break;

		case 3:  money = (check * 5000) + (check1 *3000);
		break;

		case 4:  money = (check * 10000) + (check1 *6500);
		break;
		}

		printf ("Enter your Coming Back degree\n (Economy: 1 , Premium Economy: 2 , Business: 3 ,  First class: 4)\n");

		scanf ("%s",degree1);
		ch1 = atoi(degree1);

		switch (ch1)
		{
		case 1:  money1 = (check * 1000) + (check1 *500);
		break;

		case 2:  money1 = (check * 2000) + (check1 *1000);
		break;

		case 3:  money1 = (check * 5000) + (check1 *3000);
		break;

		case 4:  money1 = (check * 10000) + (check1 *6500);
		break;
		}

		total = money+money1;


        printf ("\nThe Going trip money from %s to %s at %02d-%02d-%04d %02d:00 is %lld \n" , From , To , day , month , year , hours , money);
        printf ("\nThe Coming Back trip money from %s to %s at %02d-%02d-%04d %02d:00 is %lld \n" , To , From , day1 , month1 , year1 , hours1 , money1);

        printf ("\nThe total money is %lld\n" ,total);

	    printf ("\nDo you want to continue Y/N\n");

        scanf ("%s",input);

	    	if ((strcmp(input, "y") == 0) || (strcmp(input, "Y") == 0))
	    	{
	    		printf ("\nBooked\n ");
	    	}
	    	else
	    	{
	    		Website();
	    	}

 //////////////////////////////Adding////////////////////////////////////////////////////

	    tmp = fopen(file, "a");

	    		if (fp == NULL)
	    		{
	    		        printf("Error opening file %s\n", file);
	    		}
	    		fprintf(fp, "\n%02d;%02d;%04d;%02d", day, month, year, hours);
	    		fprintf(fp, "\n%02d;%02d;%04d;%02d", day1, month1, year1, hours1);

	    	fclose(tmp);

	    	Website();



}


void Multiple()
{
	char no_of_cities[1],check;
	int f=0,i;
	long long total =0;
	char file[256] = "/Users/ziadayman/Desktop/Booking Site/Dates.txt";
	char file1[256] = "/Users/ziadayman/Desktop/Booking Site/Capitals.txt";
	printf ("How Many cities do you want\n");
	scanf ("%s",no_of_cities);

	check = atoi(no_of_cities);
	long long money[check];

	for (i=1;i<=check;i++)
	{
		FILE *fp , *tmp;
		char adults [1],childs[1],degree[1];
		char check,check1,ch;
		char input[1];
		char From[50];
		char To[50];
		int day,month,hours;
		int year;
		char buffer[1024];

		printf ("The booking of %d Flight\n" , i);

		//////////////////////////////Data////////////////////////////////////////////////////


			printf ("\nFrom?\n");
			printf ("\nPlease enter full capital Name with first uppercase letter\n");

			scanf("%s",From);

			 fp = fopen(file1, "r");
			    if (fp == NULL)
			    {
			        printf("Error opening file %s\n", file1);
			    }

			    while (fgets(buffer, sizeof(buffer), fp) != NULL)
			    {
			        if (strstr(buffer, From) != NULL)
			        {
			            f=1;
			            fclose(fp);
			            break;
			        }
			    }
			    fclose(fp);

			    if (f)
			    {
			    	printf ("Founded\n");
			    	f=0;
			    }
			    else
			    {
			    	printf ("Invalid Capital\n");
			    	Flight();
			    }

			printf ("\nTo ?\n");

			printf ("\nPlease enter full capital Name with first uppercase letter\n");

			scanf("%s",To);

			 fp = fopen(file1, "r");
			    if (fp == NULL)
			    {
			        printf("Error opening file %s\n", file1);
			    }

			    while (fgets(buffer, sizeof(buffer), fp) != NULL)
			    {
			        if (strstr(buffer, To) != NULL)
			        {
			            f=1;
			            fclose(fp);
			            break;
			        }
			    }
			    fclose(fp);

			    if (f)
			    {
			    	printf ("Founded\n");
			    	f=0;
			    }
			    else
			    {
			    	printf ("Invalid Capital\n");
			    	Flight();
			    }


			printf ("\nDay ? xx\n");
			scanf("%d",&day);
			printf ("\nMonth ? xx\n");
			scanf("%d",&month);
			printf ("\nYear ? xxxx\n");
			scanf("%d",&year);
			printf ("\nHour ? xx\n");
			scanf("%d",&hours);

		//////////////////////////////File////////////////////////////////////////////////////
			tmp = fopen(file, "r");
				    if (tmp == NULL)
				    {
				        printf("Error opening file %s\n", file);
				    }

				    char line[256];
				    int days, months, years, hour;
				    int n_matches;
				    char* pattern = "%d;%d;%d;%d";

				    while (fgets(line, sizeof(line), tmp)) {
				    n_matches = sscanf(line, pattern, &days, &months, &years, &hour);
				    if (n_matches == 4 && days == day && months == month && years == year && hour == hours) {
				    printf("Found date and time: %02d-%02d-%04d %02d:00\n", days, months, years, hour);
				    f = 1;
				    break;
				    }
				    }
				    fclose(tmp);


				    if (f)
				    {
				    	printf("\nThis flight is booked , Try Another Date\n");
				    	Multiple();
				    	f=0;
				    }


		//////////////////////////////Money////////////////////////////////////////////////////

			    printf ("How many Adults ?\n");
			    scanf ("%s",adults);

			    check = atoi(adults);
				if (check == 0)
				{
					printf ("Error\n");
					Multiple();
				}

				else
				{
				    printf ("How many Childs ?\n");
				    scanf ("%s",childs);
				}

				check1 = atoi(childs);

				Prices();

				printf ("Enter your degree\n (Economy: 1 , Premium Economy: 2 , Business: 3 ,  First class: 4)\n");

				scanf ("%s",degree);
				ch = atoi(degree);

				switch (ch)
				{
				case 1:  money[i-1] = (check * 1000) + (check1 *500);
				break;

				case 2:  money[i-1] = (check * 2000) + (check1 *1000);
				break;

				case 3:  money[i-1] = (check * 5000) + (check1 *3000);
				break;

				case 4:  money[i-1] = (check * 10000) + (check1 *6500);
				break;
				}


		        printf ("\nThe total money from %s to %s at %02d-%02d-%04d %02d:00 is %lld \n" , From , To , day , month , year , hours , money[i-1]);


			    printf ("\nDo you want to continue Y/N\n");

		        scanf ("%s",input);

			    	if ((strcmp(input, "y") == 0) || (strcmp(input, "Y") == 0))
			    	{
			    		printf ("\nBooked\n ");
			    	}
			    	else
			    	{
			    		Website();
			    	}

		 //////////////////////////////Adding////////////////////////////////////////////////////

			    tmp = fopen(file, "a");

			    		if (fp == NULL)
			    		{
			    		        printf("Error opening file %s\n", file);
			    		}
			    		fprintf(fp, "\n%02d;%02d;%04d;%02d", day, month, year, hours);

			    	fclose(tmp);
			    	total +=money[i-1];
	}

    printf ("\nThe total money of the trip is %lld \n" , total);
    Website();

}

void Flight()
{
	int run = 1;
	char input;
	printf ("\n****** Welcome to Flight Booking ******\n");
	printf ("\nOne way enter a\n");
    printf ("\nRound Trip enter b\n");
    printf ("\nMultiple cities enter c\n");

    while (run==1)
    {
    scanf("%c",&input);

    switch (input)
    {
    case 'a':
    case 'A':Oneway();
    break;

    case 'b':
    case 'B':Roundtrip();
    break;

    case 'c':
    case 'C':Multiple();
    break;
    }

    }
}


///////////////////////////// ************** Start ******************////////////////////////////////////

void Start()
{
	int run =1;
	char input;

	Main_Menu();

	while (run == 1)
	{
		scanf (" %c" , &input);

		switch (input)
		{
		case 'a':
		case 'A': Register();
		          Start();
				break;

		case 'b':
		case 'B': Log_in();
		          Website();
		break;

		case 'y':
		case 'Y': forget_pass();
		          Start();
		break;

		default:
			Start();
			break;

		}
	}
}


int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	Start();
}


