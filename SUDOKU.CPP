/*
			ART OF PROGRAMMING
		       INNOVATIVE ASSIGNMENT

	       Made By: RAJENDRA PRATAP SINGH
	       Roll No: 14BEC096
*/
#include<iostream.h> //for input (i.e. cin>>), output(i.e. cout<<)
#include<conio.h>    //for clrscr(),getch()
#include<process.h>  //for exit()
#include<stdlib.h>   //for randomize(),random()
#include<string.h>   //for strcmp(),strlen()
#include<stdio.h>    //for gets()

//DECLARATION OF GLOBAL VARIABLES
int S[9][9],fix[9][9],flag[9],i,j,n;
char decide[10];
//S[9][9] - Sudoku Matrix or Grid
//fix[9][9] - Stores 1 at one location if number at that location in Sudoku Matrix is fix, otherwise stores 0
//i,j - used for loop control variable
//decide - to select option from user

//FUNCTION DEFINITIONS
void start();              //Operates at the begining of Program, to allocate fix numbers in the Sudoku

void instructions();       //Displays Instruction to play Sudoku to user.
void display(char,int,int);// takes character (ch) entered by user, location of cursur(_) having row(p) and column(q)
// and displays a 9 X 9 Sudoku Matrix or Grid along with location of cursur

int check_full();          //Checks wether every box is filled or not and returns 1 if filled completely otherwise returns 0.

int check_seq();           //Checks wether every row, column and labelled box is filled in correct order or not
//returns 1 if all row, column and labelled box are in correct oder, otherwise 0

int check1(int [],int);    //Takes a 1-D Matrix with its size and returns 1, if every element in matrix is 1, otherwise 0
void check_box(int,int,int,int);//Takes the initial and final row and column number of a box in Sudoku Matrix and checks wether it has correct sequence or not
void empt_flag();          //To empty flag[] matrix after use.

//main() function
int main()
{
    int i,j,p,q,count;
    char ch=NULL;
    clrscr();
    cout<<"\n\n\n\n\n\n                               >> S U D O K U <<"
	  <<"\n                                  ~~~~~~~~~~~"
	<<"\n\n\n\n\n\n\t\t\t- Made by RAJENDRA PRATAP SINGH\n"
	<<"\t\t\t  Roll No: 14BEC096";
    getch();
    instructions();
    start:
    start();
    p=4;
    q=4;
    display:
    display(ch,p,q);
    if(check_full())
    {
	if(check_seq())
	{
	     clrscr();
	     cout<<"\n\n\nCongrations!!!\n\n"
		 <<"\t\t\t~~~~You WIN~~~~";
	     getch();
	     exit(0);
	}

    }
    ask:
    ch=getch();
    switch(ch)
    {

	   case 'a': if(q==0)   //Moves position of curser left
		     goto ask;
		     else
		     {
			 count=0;
			 for(i=q-1;fix[p][i]==1;i--)
			    count++;
			 if(i==-1)
			 goto ask;
			 else
			 q=q-count-1;
		     }
		     break;

	   case 'A': if(q==0)   //Moves position of curser left
		     goto ask;
		     else
		     {
			 count=0;
			 for(i=q-1;fix[p][i]==1;i--)
			    count++;
			 if(i==-1)
			 goto ask;
			 else
			 q=q-count-1;
		     }
		     break;

	   case 'd': if(q==8)   //Moves position of curser right
		     goto ask;
		     else
		     {
			 count=0;
			 for(i=q+1;fix[p][i]==1;i++)
			    count++;
			 if(i==9)
			 goto ask;
			 else
			 q=q+count+1;
		     }
		     break;

	   case 'D': if(q==8)   //Moves position of curser right
		     goto ask;
		     else
		     {
			 count=0;
			 for(i=q+1;fix[p][i]==1;i++)
			    count++;
			 if(i==9)
			 goto ask;
			 else
			 q=q+count+1;
		     }
		     break;

	   case 'w': if(p==0)  //Moves position of curser upward
		     goto ask;
		     else
		     {
			 count=0;
			 for(i=p-1;fix[i][q]==1;i--)
			    count++;
			 if(i==-1)
			 goto ask;
			 else
			 p=p-count-1;
		     }
		     break;
	   case 'W': if(p==0)  //Moves position of curser upward
		     goto ask;
		     else
		     {
			 count=0;
			 for(i=p-1;fix[i][q]==1;i--)
			    count++;
			 if(i==-1)
			 goto ask;
			 else
			 p=p-count-1;
		     }
		     break;

	   case 's': if(p==8)  //Moves position of curser downward
		     goto ask;
		     else
		     {
			 count=0;
			 for(i=p+1;fix[i][q]==1;i++)
			    count++;
			 if(i==9)
			 goto ask;
			 else
			 p=p+count+1;
		     }
		     break;

	   case 'S': if(p==8)  //Moves position of curser downward
		     goto ask;
		     else
		     {
			 count=0;
			 for(i=p+1;fix[i][q]==1;i++)
			    count++;
			 if(i==9)
			 goto ask;
			 else
			 p=p+count+1;
		     }
		     break;

	   case '0': if(S[p][q]!=NULL) //Vanishes the previosly assigned value at curser position
		     S[p][q]=NULL;
		     else
		     goto ask;
		     break;

       //For ch equals 1 to 9 it is initialized at (p,q) position of the grid
	   case '1': S[p][q]=1; break;
	   case '2': S[p][q]=2; break;
	   case '3': S[p][q]=3; break;
	   case '4': S[p][q]=4; break;
	   case '5': S[p][q]=5; break;
	   case '6': S[p][q]=6; break;
	   case '7': S[p][q]=7; break;
	   case '8': S[p][q]=8; break;
	   case '9': S[p][q]=9; break;

	   case '.': clrscr();  //Displays "OPTIONS"
		     cout<<"            >> OPTIONS <<"
			 <<"\n\n1. Press c or C to close"
			 <<"\n\tOnce closed, your previously filled numbers will disappear."
			 <<"\n\n2. Press b or B to go back"
			 <<"\n\n3. Press i or I to see Instructions"
			 <<"\n\n4. Press r or R to restart the same game"
			 <<"\n\n5. Press n or N to restart with new pattern.\n\nOption: ";
		     decide:
		     gets(decide);
		     if(strcmp(decide,"c")==0||strcmp(decide,"C")==0)
			goto end;
		     else if(strcmp(decide,"b")==0||strcmp(decide,"B")==0)
			goto display;
		     else if(strcmp(decide,"R")==0||strcmp(decide,"r")==0)
			goto start;
		     else if(strcmp(decide,"n")==0||strcmp(decide,"N")==0)
			goto start;
		     else if(strcmp(decide,"i")==0||strcmp(decide,"I")==0)
		     {
			instructions();
			goto display;
		     }
		     else
		     {
			cout<<"\n Invalid Answer...";
			cout<<"\n Give your answer: ";
			goto decide;
		     }
	   default:  goto ask;
    }
    goto display;  //Flow of control moved to display the Sudoku Grid.
    end:
    clrscr();
    cout<<"Game Closed...\n\nPress any key";
    getch();
    return 0;
}

//Displays Instruction to play Sudoku to user.
void instructions()
{
	clrscr();
	cout<<"\n\n                             >> INSTRUCTIONS <<"
	<<"\n\n1. You have to fill the 9 X 9 Grid in the manner that:"
	<<"\n\t(a) All rows have natural number from 1 to 9 without repitition."
	<<"\n\t(b) All columns have natural number from 1 to 9 without repititon."
	<<"\n\t(c) All labelled box have natural number from 1 to 9 without repitition."
	<<"\n\n2. Instructions to play:\n"
	<<"\t(a) Press 'a' to move to left box."
	<<"\n\t(b) Press 'd' to move to right box."
	<<"\n\t(c) Press 'w' to move upward box."
	<<"\n\t(d) Press 's' to move downward box."
	<<"\n\t(e) Press '0' to remove the value given by the player to some box."
	<<"\n\t(f) Press '.', to move to \"OPTIONS\".";
	getch();
}

// takes character (ch) entered by user, location of cursur(_) having row(p) and column(q)
// and displays a 9 X 9 Sudoku Matrix or Grid along with location of cursur
void display(char ch,int p, int q)
{
    int ascii;
    ascii=(int)ch;
    clrscr();
    cout<<"\n*-------------------------------------*";
    for(i=0;i<9;i++)
    {
	if(i==3||i==6)
	cout<<"\n*-------------------------------------*";
	cout<<"\n|";
	for(j=0;j<9;j++)
	{

	     if(i==p && j==q && ascii>=49 && ascii<=57)
	     cout<<' '<<S[i][j];
	     else if(i==p&&j==q)
	     cout<<' '<<'_';
	     else if(S[i][j]==NULL)
	     cout<<' '<<' ';
	     else
	     cout<<' '<<S[i][j];
	     if(j==2||j==5)
	     cout<<" ||";
	     else
	     cout<<" |";
	}
	cout<<'\n';
    }
    cout<<"*-------------------------------------*";
    cout<<" ("<<p+1<<','<<q+1<<")";
}

//Operates at the begining of Program, to allocate fix numbers in the Sudoku
void start()
{
    int i,j;
    for(i=0;i<9;i++)
			for(j=0;j<9;j++)
					S[i][j]=NULL;
    randomize();
    if(strcmp(decide,"n")==0||strcmp(decide,"N")==0)
    {
    for(i=n;n==i;)
    {
	n=random(3);
    }
    }
    else if(strcmp(decide,"r")!=0 && strcmp(decide,"R")!=0)
    n=random(3);

    switch(n)
    {
    case 0:
    S[1][0]=1; S[1][2]=8; S[2][1]=3; S[2][2]=4;
    S[0][4]=6; S[0][5]=4; S[2][3]=9; S[2][5]=2;
    S[0][7]=7; S[1][6]=4; S[2][6]=6; S[2][7]=8;
    S[3][1]=4; S[4][1]=8; S[5][0]=2; S[5][1]=7; S[5][2]=1;
    S[3][4]=2; S[4][3]=4; S[4][5]=1; S[5][3]=3;
    S[3][6]=3; S[4][7]=6; S[5][7]=5;
    S[6][0]=9; S[6][1]=5; S[6][2]=6; S[7][1]=2; S[8][2]=7;
    S[6][3]=2; S[6][5]=3; S[7][5]=7; S[8][4]=5;
    S[6][7]=4; S[6][8]=1; S[8][6]=2; S[8][7]=3;
    break;

    case 1:
    S[0][0]=2; S[1][0]=8; S[1][2]=4; S[2][1]=1; S[2][2]=3;
    S[0][3]=3; S[1][4]=6; S[1][5]=2; S[2][3]=8;
    S[0][8]=8; S[1][8]=3; S[2][6]=2;
    S[4][0]=5; S[4][2]=7; S[5][1]=3; S[5][2]=2;
    S[3][4]=2; S[5][5]=6;
    S[3][6]=3; S[3][7]=9; S[4][6]=6; S[4][7]=2; S[4][8]=1;
    S[6][1]=2; S[7][0]=6; S[7][2]=1;
    S[6][5]=9; S[7][3]=2; S[7][4]=5; S[8][5]=1;
    S[6][6]=1; S[6][7]=4; S[7][6]=8; S[7][8]=9; S[8][8]=2;
    break;

    case 2:
    S[1][1]=8; S[1][2]=7;
    S[0][5]=6; S[1][5]=5;
    S[0][8]=1; S[2][7]=8; S[2][8]=2;
    S[3][0]=3; S[4][2]=4; S[5][2]=9;
    S[3][3]=1; S[3][5]=4; S[4][3]=3; S[4][5]=8; S[5][3]=5;
    S[3][8]=6; S[5][6]=4; S[5][7]=3;
    S[6][2]=6; S[7][0]=9; S[8][0]=2; S[8][2]=3;
    S[7][5]=1; S[8][3]=7; S[8][5]=9;
    S[7][6]=2; S[7][7]=5;
    }

    //To define whether number at a specific position in Sudoku is fix number or not
    //if number is fix, fix[][]=1, otherwise 0.
    for(i=0;i<9;i++)
    {
	for(j=0;j<9;j++)
	{
		if(S[i][j]==NULL)
			fix[i][j]=0;
		else
			fix[i][j]=1;
	}
    }
}

//Checks wether every box is filled or not and returns 1 if filled completely otherwise returns 0.
int check_full()
{
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(S[i][j]==NULL)
				return 0;
		}
	}
	return 1;
}

//Checks wether every row, column and labelled box is filled in correct order or not
//returns 1 if all row, column and labelled box are in correct oder, otherwise 0
int check_seq()
{
	int row[9],column[9],box[9],k,l;
	for(i=0;i<9;i++)
	{
		empt_flag();
		for(j=0;j<9;j++)
		{
		      k=S[i][j];
		      flag[k-1]=1;
		}
		row[i]=check1(flag,9);
		if(row[i]==0)
		return 0;
	}

	for(i=0;i<9;i++)
	{
		empt_flag();
	    for(j=0;j<9;j++)
		{
		      k=S[j][i];
		      flag[k-1]=1;
		}
		column[i]=check1(flag,9);
		if(column[i]==0)
		return 0;
	}
	check_box(0,2,0,2);
    box[0]=check1(flag,9);
	check_box(0,2,3,5);
    box[1]=check1(flag,9);
	check_box(0,2,6,8);
    box[2]=check1(flag,9);
	check_box(3,5,0,2);
    box[3]=check1(flag,9);
	check_box(3,5,3,5);
    box[4]=check1(flag,9);
	check_box(3,5,6,8);
    box[5]=check1(flag,9);
	check_box(6,8,0,2);
    box[6]=check1(flag,9);
	check_box(6,8,3,5);
    box[7]=check1(flag,9);
    check_box(6,8,6,8);
    box[8]=check1(flag,9);

    for(i=0;i<9;i++)
    {
	if(box[i]==0)
		return 0;
	}
    return 1;
}

//Takes a 1-D Matrix with its size and returns 1, if every element in matrix is 1, otherwise 0
int check1(int a[], int size)
{
	int l;
	for(l=0;l<size;l++)
	{
		if(a[l]!=1)
			return 0;
	}
	return 1;
}

//Takes the initial and final row and column number of a box in Sudoku Matrix and checks wether it has correct sequence or not
void check_box(int r1,int r2,int c1,int c2)
{
	int k;
    empt_flag();
    for(i=r1;i<=r2;i++)
	{
	     for(j=c1;j<=c2;j++)
	     {
		 k=S[i][j];
		 flag[k-1]=1;
	     }
	}
}

//To empty flag[] matrix after use.
void empt_flag()
{
    int i;
    for(i=0;i<9;i++)
		    flag[i]=NULL;
}
