//Aaron Reich, COP 2220, 7/29/2014, Project 3, Video Game Inventory Program
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <ctype.h>  
#define maxsize 50//defines the max size to 50
typedef struct {
					char name[30];
					char manuf[30];
					int id;
					int qty;
					double cost;
					double price;
}game;//declares the struct and all its components

void Hardcopy (game list[]);//saves five video game entry structs to the inventory(array of structs)

void Printgames(game list[],int *invsize);//prints the inventory(array of structs) using a for loop to iterate through the indexes of the entries

void Save(game list[],int *invsize);//prints the inventory(array of structs) to a text file using a for loop to iterate through the indexes of the entries

game Fillgames();//prompts and gets from the user video game name,manufacturer,id,quantity,cost, and price and saves them in a temporary struct which it returns 

void Addgame(game list[],int *invsize);/*first makes sure that the inventory is less than the max size of 50 and then saves the temporary struct 
returned from Fillgames into the array off video game structs*/

int Search(game list[],int *invsize);/*prompts and gets from the user a video game id and then starts a for loop to iterate through the indexes 
of the entries comparing the id's of the entries to the user's provided id and returns the index if there is a match and a -1 if none*/

void Delete(game list[],int *invsize,int *index);/*calls the Search function and uses the Printgamesforsearch function to display entry(struct) 
using the index returned from the Search function and then subtracts the selected index from the array and updates the size of the inventory(array)*/

void Printgamesforsearch(game list[],int *invsize,int *index);//prints the entry(struct) with the index returned from the Search function

void Modifyqty(game list[],int *invsize,int *index);/*calls the Search function and uses the Printgamesforsearch function to display the entry(struct)
using the index returned from the Search function and gets the new quantity from the user and saves it at the quantity of the struct with the index
returned from the search function*/

void Clear(game list[],int *invsize);//subtracts the inventory size(array size) from itself and then updates the inventory size essentially clearing the inventory

int main ()
{
	game list [maxsize];
	int *invsize,*index;
	int ind;
	int size=5;
	char command='z';
	printf("Welcome to VGames\n\nThis is the video game store's inventory program\n\nFive video games have already been entered into the database\n\n");//prints to the user the welcome and that 5 entries have already been entered
	Hardcopy(list);//calls Hardcopy function
	while(command!='q')//while loop until a 'q' is entered
	{
		printf("\n\nPlease select a menu command\n\nP...Display all video games\nS...Create a current report\nA...Add a video game\nM...Modify quantity of a video game\nD...Delete a video game from the inventory\nC...Clear all records\nQ...Quit\n\n");/*
		prints menu options and prompts them to enter a character for the command*/
		scanf(" %c",&command);//gets command character from the user
		command=tolower(command);//converts command character from a uppercase to lowercase
		if(command=='p')//the if/if else statements calling a certain function if a certain letter is entered for the command
		{
			Printgames(list,&size);//calls Printgames function
		}
		else if(command=='s')
		{
			Save(list,&size);//calls Save function
		}
		else if(command=='a')
		{
			Addgame(list,&size);//calls Addgame function
		}
		else if(command=='m')
		{
			Modifyqty(list,&size,&ind);//calls Modifyqty function
		}
		else if(command=='d')
		{
			Delete(list,&size,&ind);//calls Delete function
		}
		else if(command=='c')
		{
			Clear(list,&size);//calls Clear function
		}
	}
	printf("\nGoodbye\n");//prints to the user goodbye
}



void Hardcopy (game list[])//saves five video game entry structs to the inventory(array of structs)
{
	strcpy(list[0].name,"Infamous");	
	strcpy(list[0].manuf,"Sucker Punch Productions");
	list[0].id=9543;
	list[0].qty=20;
	list[0].cost=35.5;
	list[0].price=45.99;

	strcpy(list[1].name,"Call of Duty");	
	strcpy(list[1].manuf,"Activision");
	list[1].id=4937;
	list[1].qty=25;
	list[1].cost=41.35;
	list[1].price=59.99;

	strcpy(list[2].name,"Watch Dogs");	
	strcpy(list[2].manuf,"Ubisoft");
	list[2].id=3926;
	list[2].qty=14;
	list[2].cost=24.5;
	list[2].price=35.89;

	strcpy(list[3].name,"Mario Kart");	
	strcpy(list[3].manuf,"Nintendo");
	list[3].id=2039;
	list[3].qty=19;
	list[3].cost=23.45;
	list[3].price=55.99;

	strcpy(list[4].name,"Grand Theft Auto");	
	strcpy(list[4].manuf,"Rockstar Games");
	list[4].id=3973;
	list[4].qty=30;
	list[4].cost=15.40;
	list[4].price=37.89;
}

void Printgames(game list[],int *invsize)//prints the inventory(array of structs) using a for loop to iterate through the indexes of the entries
{
	int x,q;
	for (x=0;x<*invsize;x++)//for loop that iterate through the indexes of the entries by using a counter until it is equal to the inventory size
	{
	q=x+1;
	printf("\n\n---Video Game %d---",q);//prints video game number
	printf("\nThe Video Game's name is %s",list[x].name);//prints video game name
	printf("\nThe manufacturer is %s",list[x].manuf);//prints video game manufacturer
	printf("\nThe product id number is %d",list[x].id);//prints video game id
	printf("\nThe quantity is %d",list[x].qty);//prints the quantity of the video game
	printf("\nThe cost is $%.2f",list[x].cost);//prints the cost of the video game
	printf("\nThe price is $%.2f",list[x].price);//prints the price of the video game
	}
}


void Save(game list[],int *invsize)//prints the inventory(array of structs) to a text file using a for loop to iterate through the indexes of the entries
{
	FILE *Saved_Inventory;//declares the file pointer
	int y,q;
	Saved_Inventory=fopen("Saved Inventory of VGames.txt","w");//opens a text file to write by printing to it all of the video games' information
	for (y=0;y!=*invsize;y++)//for loop that iterate through the indexes of the entries by using a counter until it is equal to the inventory size
	{
		q=y+1;
		fprintf(Saved_Inventory,"\n\n---Video Game %d---",q);//prints video game number to the text file
		fprintf(Saved_Inventory,"\n\nThe Video Game's name is %s",list[y].name);//prints video game name to the text file
		fprintf(Saved_Inventory,"\nThe manufacturer is %s",list[y].manuf);//prints video game manufacturer to the text file
		fprintf(Saved_Inventory,"\nThe product id number is %d",list[y].id);//prints video game id to the text file
		fprintf(Saved_Inventory,"\nThe quantity is %d",list[y].qty);//prints the quantity of the video game to the text file
		fprintf(Saved_Inventory,"\nThe cost is $%.2f",list[y].cost);//prints the cost of the video game to the text file
		fprintf(Saved_Inventory,"\nThe price is $%.2f",list[y].price);//prints the price of the video game to the text file
	}
	fclose(Saved_Inventory);//closes the file
	printf("\nThe inventory has been saved");//prints to the user that the inventory has been saved
}

game Fillgames()//prompts and gets from the user video game name,manufacturer,id,quantity,cost, and price and saves them in a temporary struct which it returns 
{
	game temp;
	printf("\nPlease enter the video game's name. Use underscores for spaces ");//prompts the user for the video game name
	scanf("%s",temp.name);//gets from the user the video game name
	printf("\nPlease enter the manufacturer. Use underscores for spaces ");//prompts the user for the video game manufacturer
	scanf("%s",temp.manuf);//gets from the user the video game manufacturer
	printf("\nPlease enter the product id ");//prompts the user for the video game id
	scanf("%d",&temp.id);//gets from the user the video game id
	printf("\nPlease enter the quantity ");//prompts the user for the video game quantity
	scanf("%d",&temp.qty);//gets from the user the video game quantity
	printf("\nPlease enter the cost $");//prompts the user for the video game cost
	scanf("%lf",&temp.cost);//gets from the user the video game cost
	printf("\nPlease enter the price $");//prompts the user for the video game price
	scanf("%lf",&temp.price);//gets from the user the video game price
	return temp;//returns the temporary struct 
}

void Addgame(game list[],int *invsize)/*first makes sure that the inventory is less than the max size of 50 and then saves the temporary struct 
returned from Fillgames into the array off video game structs*/
{
	if (*invsize<maxsize)//if statement that makes sure that the inventory size is less than the max size of 50
	{
		list[*invsize]=Fillgames();//call the Fillgames function and fills the struct array with the struct returned from the Fillgames function
		*invsize=*invsize+1;//increases the inventory size by 1
		printf("\n\nGame added");//prints to the user that a game has been added
	}
	else//else statement that executes if the inventory size has reached the maxsize of 50
	{
		printf("\n\nThe inventory is full");//prints that the inventory is full
	}
}

int Search(game list[],int *invsize)/*prompts and gets from the user a video game id and then starts a for loop to iterate through the indexes 
of the entries comparing the id's of the entries to the user's provided id and returns the index if there is a match and a -1 if none*/
{	
	int i,uid;
	printf("Enter the id of the video game ");//prompts the user for the video game's id
	scanf("%d",&uid);//gets the video game's id from the user
	for(i=0;i<*invsize;i++)//for loop with a counter that continues until it is equal to the inventory size
	{
		if(list[i].id==uid)//if statement that compares the video games' id's (iterating through the indexes using the counter from the for loop) with the id the user entered
		{
			return i;//returns the counter that will be the index of the video game that matches the id the user entered
		}
	}
	return -1;//returns a -1 if the id's of the video games never match after iterating through the whole array
}


void Delete(game list[],int *invsize,int *index)/*calls the Search function and uses the Printgamesforsearch function to display entry(struct) 
using the index returned from the Search function and then subtracts the selected index from the array and updates the size of the inventory(array)*/
{
	char yes[20]="yes";
	char yes2[20];
	*index=Search(list,invsize);//calls the Search function and fills the index pointer with the counter returned from the Search function 
	if(*index==-1)//if statement for -1 which was returned if none of the id's matched
	{
		printf("\nGame not found");//prints that the game was not found
	}
	else//else statement for if the video game was found
	{
		Printgamesforsearch(list,invsize,index);//calls the Printgamesforsearch function
		printf("\n\nWould you like to delete this video game ");//asks the user if they want to delete the video game
		scanf("%s",yes2);//gets from the user the yes or no if they want to delete the video game
		yes2[0]=tolower(yes2[0]);//converts the first letter of the word from a uppercase to lowercase
		if (strcmp(yes,yes2)==0)//if statement for if the user entered a yes
		{
			list[*index]=list[*invsize-1];//deletes a index from the struct array
			*invsize=*invsize-1;//subtracts 1 from the inventory size
			printf("\n\nGame deleted");//prints to the user that a game has been deleted
		}
	}
}


void Printgamesforsearch(game list[],int *invsize,int *index)//prints the entry(struct) with the index returned from the Search function
{
	int x;
	for (x=0;x<1;x++)//for loop iterating once
	{
		printf("\n\nThe Video Game's name is %s",list[*index].name);//prints video game name
		printf("\nThe manufacturer is %s",list[*index].manuf);//prints video game manufacturer
		printf("\nThe product id number is %d",list[*index].id);//prints video game id
		printf("\nThe quantity is %d",list[*index].qty);//prints video game quantity
		printf("\nThe cost is $%.2f",list[*index].cost);//prints video game cost
		printf("\nThe price is $%.2f",list[*index].price);//prints video game price
	}
}

void Modifyqty(game list[],int *invsize,int *index)/*calls the Search function and uses the Printgamesforsearch function to display the entry(struct)
using the index returned from the Search function and gets the new quantity from the user and saves it at the quantity of the struct with the index
returned from the search function*/
{
	*index=Search(list,invsize);//calls the Printgamesforsearch function
	if(*index==-1)//if statement for -1 which was returned if none of the id's matched
	{
		printf("\nGame not found");//prints that the game was not found
	}
	else//else statement for if the video game was found
	{
		Printgamesforsearch(list,invsize,index);//calls the Printgamesforsearch function
		printf("\n\nWhat do you want to change the quantity of the video game to ");//asks the user for what they want to change the quantity of the video game to 
		scanf("%d",&list[*index].qty);//gets from the user the new id and saves it at the index returned from the Search function
		printf("\n\nThe quantity has been changed to %d",list[*index].qty);//prints the new quantity
	}
}

void Clear(game list[],int *invsize)//subtracts the inventory size(array size) from itself and then updates the inventory size essentially clearing the inventory
{
	list[*invsize]=list[*invsize-*invsize];//subtracts the indexes from theirselves clearing the inventory
	*invsize=*invsize-*invsize;//subtracts the array size from the array size clearing the array size
	printf("\n\nAll entries deleted");//prints that all the entries have been deleted
}