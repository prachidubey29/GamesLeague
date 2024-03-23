#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
int game(char you, char computer)
{
	if (you == computer)
		return -1;
	if (you == 's' && computer == 'p')
		return 0;
			else if (you == 'p' && computer == 's') return 1;
	if (you == 's' && computer == 'z')
		return 1;
	else if (you == 'z' && computer == 's')
		return 0;
	if (you == 'p' && computer == 'z')
		return 0;
	else if (you == 'z' && computer == 'p')
		return 1;
}
int number(int lucky)
{
if(lucky==1)
printf("\nYOUR NUMEROLOGY NUMBER IS 1\nAssociated with independence, leadership, and individuality. It represents new beginnings, ambition, and self-confidence.");
else if(lucky==2)
printf("\nYOUR NUMEROLOGY NUMBER IS 2\nSymbolizes harmony, cooperation, and balance. It represents partnerships, diplomacy, and sensitivity.");
else if(lucky==3)
printf("\nYOUR NUMEROLOGY NUMBER IS 3\nRepresents creativity, self-expression, and joy. It signifies communication, socializing, and optimism.");
else if(lucky==4)
printf("\nYOUR NUMEROLOGY NUMBER IS 4\nAssociated with stability, practicality, and hard work. It represents organization, discipline, and building solid foundations.");
else if(lucky==5)
printf("\nYOUR NUMEROLOGY NUMBER IS 5\nSymbolizes adaptability, freedom, and adventure. It represents change, versatility, and embracing new experiences.");
else if(lucky==6)
printf("\nYOUR NUMEROLOGY NUMBER IS 6\nRepresents harmony, nurturing, and responsibility. It symbolizes family, love, and service to others.");
else if(lucky==7)
printf("\nYOUR NUMEROLOGY NUMBER IS 7\nYou are a great thinker,a analyzer and a seeker of knowledge.");
else if(lucky==8)
printf("\nYOUR NUMEROLOGY NUMBER IS 8\n It represents leadership, the organizer, the achiever.");
else
printf("\nYOUR NUMEROLOGY NUMBER IS 9\nIt represents the humanitarian, the altruist, the visionary.");
return lucky;
}
int generateNumber() {
    srand(time(NULL));
    return rand() % 100 + 1;
}

void playGame(int number) {
    int guess, attempts = 0;
    printf("Welcome to Guess the Number!\n");
    printf("I have selected a number between 1 and 100. Can you guess it?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > number) {
            printf("Too high! Try again.\n");
        } else if (guess < number) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number %d correctly in %d attempts!\n", number, attempts);
        }
    } while (guess != number);
}
int main()
{
    int ch;
    printf("CHOOSE BETWEEN [1,2,3]:");
    scanf("%d",&ch);
    switch(ch) 
    {
        case 1:
        {
            int n;
            char you, computer, result;
            srand(time(NULL));
            n = rand() % 100;
            if (n < 33)
                computer = 's';
            else if (n > 33 && n < 66)
                computer = 'p';
            else
                computer = 'z';
            printf("\n\n\n\n\t\t\t\tEnter s for STONE, p for PAPER and z for SCISSOR\n\t\t\t\t\t\t\t");
            scanf(" %c", &you);
            result = game(you, computer);

            if (result == -1) {
                printf("\n\n\t\t\t\tGame Draw!\n");
            }
            else if (result == 1) {
                printf("\n\n\t\t\t\tWow! You have won the game!\n");
            }
            else { 
                printf("\n\n\t\t\t\tOh! You have lost the game!\n");
            }
            printf("\t\t\t\tYou choose: %c and Computer choose: %c\n", you, computer);

            
            break;
        }
        case 2:
        {
        int date,c,d;
        char ans;
        printf("\n\n\t\t\t\tSEEMS LIKE IT'S TIME TO FIND YOUR NUMEROLOGY NUMBER!!\n\n\n");
    printf("Enter your DATE of birth:");
    scanf("%d", &date);
    if(date<=31)
    {
    int luck=0;
    if (date < 10)
        luck = date;
    else
    {
     c = date % 10;
     d = (date / 10) % 10;
     luck = (c + d) % 9;
    }
    ans = number(luck);
    printf("%c", ans);
    }
    else
    printf("INPUT A VALID DATE OF BIRTH");
    break;
        }
        case 3:
        {
  char questions[][100] = {"1. If we terminate the loop will it exectue even for once?:",
                             "2. Is do while a:-",
                             "3. a=1\nWhat will be the output for ++a,++a,a in the mentioned order:- "};

    char options[][100] = {"A. YES AFTER THE CONDITION BEING FALSE", "B.YES BUT NO NEED OF CHECKING CONDITION", "C. NO", "D.DON'T KNOW ",
                           "A. ENTRY CONTROLL LOOP", "B. EXIST CONTROLL LOOP", "C. BOTH A AND B", "D. NONE OF THE ABOVE",
                           "A. (2,3,3)", "B. (2,3,1)", "C. (3,3,3)", "D. NONE OF THE ABOVE"};

    char answers[] = {'A', 'B', 'C'};
    int numberOfQuestions = sizeof(questions) / sizeof(questions[0]);

    char guess = ' ';
    int score = 0;

    printf("QUIZ GAME\n");

    for (int i = 0; i < numberOfQuestions; i++) {
        printf("*********************\n");
        printf("%s\n", questions[i]);
        printf("*********************\n");

        for (int j = (i * 4); j < (i * 4) + 4; j++) {
            printf("%s\n", options[j]);
        }

        printf("guess: ");
        scanf(" %c", &guess);
        getchar();

        guess = toupper(guess);

        if (guess != answers[i]) {
            printf("WRONG!\n");
        } else {
            printf("CORRECT!\n");
            score++;
        }
    }
    printf("*********************\n");
    printf("FINAL SCORE: %d/%d\n", score, numberOfQuestions);
    printf("*********************\n");

    
   break;
        }
     default:
     {
     int number = generateNumber();
    playGame(number);
    
        break;
     }
    }
    
}
