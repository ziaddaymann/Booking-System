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

void Main_Menu ();
void Menu();
void Register ();
void Log_in ();
void forget_pass();
void Website();
void Oneway();
void Flight();
void Start();


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

	///////////////////////////Mail///////////////////////
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

	///////////////////////////////////Pass///////////////////////


	printf ("Please enter you Password \n");
	scanf ("%s",pass);

	if (strlen(pass) == 0)
	{
		printf ("Invalid Password\n");
		Register();
	}



	//////////////////////////////////////Adding///////////////////

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
	FILE *fp;
	char mail[50];
	char pass[50];
	char buffer[1024];
	char f;
	char file[256] = "/Users/ziadayman/Desktop/Booking Site/Book1.txt";


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

	printf ("Please enter the password\n");
	scanf("%s",pass);

	if (strlen(pass) == 0)
	{
		printf ("Invalid Password\n");
		Start();
	}



	 fp = fopen(file, "r");
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
	char f;


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

		    if (f)
		    {
		         printf("Your password is: %s\n", pass);
		    }
		    else
		    {
		         printf("Email not found\n");
		         Start();
		    }
}

void Oneway()
{
	FILE *fp , *tmp;
	char From[50];
	char To[50];
	int day,month,hours;
	int year;
	char buffer[1024];
	int f=0;
	char file[256] = "/Users/ziadayman/Desktop/Booking Site/Dates.txt";
	char file1[256] = "/Users/ziadayman/Desktop/Booking Site/Capitals.txt";

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

	 tmp = fopen(file, "r");
	    if (tmp == NULL)
	    {
	        printf("Error opening file %s\n", file);
	    }

	    char line[256];
	    regex_t regex;
	    regmatch_t match[5];
	    char* pattern = "([0-9]{2});([0-9]{2});([0-9]{4});([0-9]{2})";
	    if (regcomp(&regex, pattern, REG_EXTENDED)) {
	        printf("Error: Unable to compile regex pattern.\n");
	    }

	    while (fgets(line, sizeof(line), tmp)) {
	        if (regexec(&regex, line, 5, match, 0) == 0) {
	            int d, m, y, h;
	            sscanf(line + match[1].rm_so, "%d", &d);
	            sscanf(line + match[2].rm_so, "%d", &m);
	            sscanf(line + match[3].rm_so, "%d", &y);
	            sscanf(line + match[4].rm_so, "%d", &h);
	            if (d == day && m == month && y == year && h == hours) {
	                printf("Found date and time: %02d-%02d-%04d %02d:00\n", day, month, year, hours);
	                f = 1;
	                break;
	            }
	        }
	    }

	    regfree(&regex);
	    fclose(tmp);



	    if (f)
	    {
	    	printf("\nThis flight is booked , Try Another Date\n");
	    	Oneway();
	    	f=0;
	    }
	    else
	    {
	    	printf ("\nBooked\n ");
	    }

	    tmp = fopen(file, "a");

	    		if (fp == NULL)
	    		{
	    		        printf("Error opening file %s\n", file);
	    		}
	    		fprintf(fp, "\n%d;%d;%d;%d\n", day, month , year , hours);

	    	fclose(tmp);




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
/*
    case 2: Roundtrip();
    break;

    case 3: Multiple();
    break;
    }
*/
    }
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
	Start();
}

