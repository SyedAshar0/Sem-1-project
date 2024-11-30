/* 
READ BEFORE RUNNING THE CODE
	code for clearing the screen is used
	if you're on windows you can IGNORE this
	if you're on mac you need to comment system("cls");
	and uncomment system("clear");
	you will find these inside the clear_screen function
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Question{
    int num1;
    int num2;
    int correct_answer;
};
void clear_screen(){
	//stdlib code for clearing screen
	system("cls");
//	system("clear");
}

int get_high_score(){
	//return value inside text file as high_score
    int high_score=0;
    FILE *file=fopen("highscore.txt", "r");
    if(file==NULL){
    	printf("Error: Could not open the file.\n");
	}else{
		fscanf(file, "%d", &high_score);
	    fclose(file);
	}
    return high_score;
}
void save_high_score(int score){
	//update high score
	int high_score=get_high_score();
	if(score>high_score){ 
	    FILE *file=fopen("highscore.txt", "w");
	    if(file==NULL){
	        printf("Error: Could not open highscore.txt for writing.\n");
	    }else{
	        fprintf(file, "%d", score);
	        fclose(file);
	    }
	}
}

void multiplication_question(struct Question *q){
	//randomize 2 numbers and figure out the correct answer based on them
    q->num1 = rand() % 9 + 1;
    q->num2 = rand() % 9 + 1;
    q->correct_answer = q->num1 * q->num2;
}
void double_multiplication_question(struct Question *q){
    q->num1 = rand() % 11 + 10;//between 10 and 20
    q->num2 = rand() % 9 + 1;  //between 1 and 9
    q->correct_answer = q->num1 * q->num2;
}
void addition_question(struct Question *q){
    q->num1 = rand() % 15 + 1;//between 1 and 15
    q->num2 = rand() % 15 + 1;
    q->correct_answer = q->num1 + q->num2;
}
void double_addition_question(struct Question *q) {
    q->num1 = rand() % 16 + 15;//between 15 and 30
    q->num2 = rand() % 16 + 15;
    q->correct_answer = q->num1 + q->num2;
}

//3 print functions to give illusion of vertical progress
void print_platforms1(struct Question *current,struct Question *next,char mychar){
    printf("\n					   %d%c%d\n", next->num1,mychar, next->num2);
    printf("					___________\n\n");
    printf("\n	   		   %d%c%d\n", current->num1,mychar, current->num2);
    printf("			___________\n\n");
    printf("\n	   YOU\n");
    printf("	___________\n\n");
}
void print_platforms2(struct Question *current,struct Question *next,char mychar){
    printf("\n	   %d%c%d\n", next->num1,mychar, next->num2);
    printf("	_________\n\n");
    printf("\n					   %d%c%d\n", current->num1,mychar, current->num2);
    printf("					_________\n\n");
    printf("\n	   		   YOU\n");
    printf("			_________\n\n");
}
void print_platforms3(struct Question *current,struct Question *next,char mychar){
	printf("\n	   		   %d%c%d\n", next->num1,mychar, next->num2);
    printf("			_________\n\n");
    printf("\n	   %d%c%d\n", current->num1,mychar, current->num2);
    printf("	_________\n\n");
    printf("\n					   YOU\n");
    printf("					_________\n\n");
}
void death_message(){
    printf("\\\\  //   ____    ||    ||\n");
    printf(" \\\\//   /    \\   ||    ||\n");
    printf("  ||   /      \\  ||    ||\n");
    printf("  ||   \\      /  ||    ||\n");
    printf("  ||    \\____/   \\\\____//\n\n");
    printf("  ||\\   /////   //////\n");
    printf("  |  \\    ||    |\n");
    printf("  |   \\   ||    //////\n");
    printf("  |   /   ||    |\n");
    printf("  |  /    ||    |\n");
    printf("  ||/   /////   //////\n");
}
void print_startup_lore(){
	char are_you_ready[4];
	//startup lore
	printf("You slowly open your eyes, disoriented. The world around you is nothing like you\'ve ever seen before.\n");
	printf("You\'re standing at the edge of a platform, but the ground is nowhere to be found.\n");
	printf("A chill runs down your spine as you peer into the endless void below, the sensation of weightlessness creeping over you.\n");
	printf("Suddenly, a mysterious voice echoes in the air, sending a shiver through your body:\n");
	printf("Welcome... to the unknown.....\n");
	getchar();
	printf("You must be wondering... where am I?\n");
	printf("I don\'t have all the answers, but I do know this: a prize awaits you at the top.\n");
	printf("But to reach it, you\'ll have to face the Guardians--ancient beings who test your mind and resolve.\n");
	printf("Each one represents a trial, a challenge that will push you further than you\'ve ever gone.\n");
	printf("The deeper you go, the more you\'ll question everything.\n");
	printf("Once you start, there\'s no turning back. Are you ready? (yes/no)\n\n");
	scanf("%s", &are_you_ready);
	getchar();
	if(strcmp(are_you_ready, "yes") == 0) {
	    printf("\nGood! Let\'s see....\nI can\'t do much, but I can manipulate the position of the guardians!\n");
	    printf("Just tell me which guardians you want to face.\n");
	}else if(strcmp(are_you_ready, "no") == 0){
	    printf("\nOk.......\nYou see... Unfortunately you don\'t have a choice..\n");
	    printf("I won\'t help you much, but I can manipulate the position of the guardians!\n");
	    printf("Just tell me which guardians you want to face.\n");
	}else{
		printf("I don\'t know what you are trying to say\n");
		printf("I won\'t help you much, but I can manipulate the position of the guardians!\n");
	    printf("Just tell me which guardians you want to face.\n");
	}
}
void print_score(int score, int wrong_answers, int high_score, int points_per_question, int streak, int lifeline){
	if(score>10 && wrong_answers>1){
		printf("\nScore = %d	Wrong Answers = %d	  High Score = %d	Streak Multiplier = %d	Streak = %d  Life Lines = %d",
		score,wrong_answers,high_score,points_per_question,streak,lifeline);
	}else if(score>10){
			printf("\nScore = %d	Wrong Answers = %d	  High Score = %d	Streak Multiplier = %d	Streak = %d",
			score,wrong_answers,high_score,points_per_question,streak);
	}else if(wrong_answers>1){
			printf("\nScore = %d	Wrong Answers = %d	  High Score = %d	Life Lines = %d",
			score,wrong_answers,high_score,lifeline);
	}else{
		printf("\nScore = %d	Wrong Answers = %d	  High Score = %d",
		score,wrong_answers,high_score,points_per_question,streak);
	}
	printf("\n");
}
void print_plot_twist(){
	clear_screen();
	printf("You\'ve crossed the threshold...\nYou should know--this wasn\'t a test; you're in a simulation.\n");
	printf("The reward you thought awaited you was never real...\nIt was just a fake promise to keep you going.\n");
	printf("All you were was a small part in a research program.\n");
	printf("It\'s your own fault for beliving something like guardians would actually exist.\n");
	printf("The research continues; you were never meant to win.\n");
	getchar();
	clear_screen();
	printf("I do pity you though.....\n");
	printf("Hey, I\'ll give you something to cheer you up\n");
	printf("You can now get a multiplier added to your score\n");
	printf("But make sure you keep up your streak!\n");
	getchar();	
	clear_screen();
}

int is_answer_correct(int *user_answer,struct Question *current, int *score, int *bonus, int *platform_counter, int *streak, int *lifeline, int *wrong_answers){
	//check if answer is correct
	//while loop so you take input again if -1 is put despite not having lifelines
	while(1){
		if(*user_answer==current->correct_answer){
	        *score+=*bonus;
	        (*platform_counter)++;
	        (*streak)++;
	        if(*bonus<3 && *streak%10==0){
	            (*bonus)++;
	        }
	        break;
	    }else if(*user_answer==-1 && *lifeline>0){
	        (*lifeline)--;
	        (*platform_counter)++;
	        (*streak)++;
	        break;
	    }else if(*user_answer==-1 && *lifeline==0){
	        printf("\nYou have no lifelines right now!\n");
	        printf("You must answer the question\n");
	        scanf("%d",&*user_answer);
	        getchar();
	    }else if(*user_answer==0){
	    	clear_screen();
	    	printf("\n\nYou have decided to quit the game\n\n");
	    	death_message();
	    	getchar();
	    	clear_screen();
	    	return 1;
		}else{
	        (*wrong_answers)++;
	        *streak=0;
	        *bonus=1;
	        break;
	    }
	}
return 0;	
}
void integer_input_check(int *input){
	//while loop to see if scanf takes integer input
	//if not remove everything till new line and ask for input again
	while(scanf("%d", input)!=1){
        	printf("\nPlease input an integer not a string!\n");
        	while(getchar() != '\n');
	}
	getchar();
}
void give_lifeline(int *lifeline){
	clear_screen();
    printf("What are you doing!!!!!!\n");
   	printf("I can\'t let this end just yet\n");
    printf("You know what.....\n");
    printf("You get one lifeline.. Just one");
    getchar();
    *lifeline=1;
    clear_screen();
	printf("Just answer -1 the next time you\'re not sure about a question!\n");
    printf("I\'ll go behind the scenes and change your answer to the actual one\n");
    printf("But you can only use this once\n");
    printf("I can\'t risk changing the system again and again\n");
    getchar();
    clear_screen();
}


	

void actual_game(){
	clear_screen();
    int platform_counter=1,high_score,lifeline=0;
    int score=0,wrong_answers=0,user_answer;
    int choice,counter=0,found=0,found2=0,found3=0;
    int points_per_question=1,streak=0;
    char mychar='+';
    struct Question current_question = {0, 0, 0};//make current question num1,num2,answer=0
    struct Question next_question;
    
    // Seed
    srand(time(0));
    
	print_startup_lore();
	
	//menu starts
	printf("\n\n1. The Keeper of Wisdom: Conquer basic addition.\n");
	printf("2. The Guardian of Simple Numbers: Master single-digit multiplication.\n");
	printf("3. The Judge of Knowledge: Solve advanced addition problems.\n");
	printf("4. The Architect of Infinity: Overcome advanced multiplication challenges.\n\n");
	integer_input_check(&choice);	

	clear_screen();
	printf("RULES OF THE GAME:\n");
	printf("1. You must answer questions correctly to progress.\n");
	printf("2. If you get 3 wrong answers, you\'ll fail the challenge.\n");
	printf("3. Stay sharp and good luck!\n");
	printf("Press ENTER to continue\n");
	getchar();
	clear_screen();
	
	// print 2 questions to start off with
	switch(choice){
		case 1:
			addition_question(&current_question);
	    	addition_question(&next_question);
	    	mychar='+';
	    	break;
	    case 2:
	    	multiplication_question(&current_question);
			multiplication_question(&next_question);
	    	mychar='x';
	    	break;
	    case 3:
	    	double_addition_question(&current_question);
	    	double_addition_question(&next_question);
	    	mychar='+';
	    	break;
	    case 4:
	    	double_multiplication_question(&current_question);
			double_multiplication_question(&next_question);
			mychar='x';
			break;
	    default:
	    	addition_question(&current_question);
	    	addition_question(&next_question);
	    	mychar='+';
	}
	
    while(1){
    	clear_screen();
    	
	    if (score / 20 > counter && choice != 4) {
	    		//if score > multiple of 20 and level !=4 ask user to increase difficulty
				char too_ez[4];
				counter = score / 20;
				clear_screen();
				printf("This is getting too easy for you, isn't it?\n");
				printf("Why not make things more interesting?\n");
				printf("Step up, choose a higher challenge, and show that you're more than just a passing participant.\n");
				printf("After all, it's only to improve the research.(yes/no)\n");
				scanf("%s", too_ez);
				getchar();
				if (strcmp(too_ez, "yes") == 0) {
				    printf("\nAh, so you've decided to take on the greater challenge.\n");
				    printf("Good. Let's see how high you can climb.\n");
				    if (choice == 1) {
				        choice = 2;
				        multiplication_question(&current_question);
				        multiplication_question(&next_question);
				        mychar = 'x';
				    } else if (choice == 2) {
				        choice = 3;
				        double_addition_question(&current_question);
				        double_addition_question(&next_question);
				        mychar = '+';
				    } else if (choice == 3) {
				        choice = 4;
				        double_multiplication_question(&current_question);
				        double_multiplication_question(&next_question);
				        mychar = 'x';
				    }
				}else {
					printf("\nBetter to fall in a true challenge than live in the comfort of mediocrity.\n");
				    printf("After all, it's only to improve the research.\n");
				    printf("But you do you\n");
				    printf("Keep fighting knowing that nothing lies ahead\n");
				    printf("I'll be back... Maybe you'll reconsider then\n");
				}
				getchar();
				clear_screen();
	    }
    	if(score>10 && found!=1){
    		print_plot_twist();
		    found=1;
		}
		
		//change which print function called based on variable
    	switch(platform_counter){
    		case 1:
    			print_platforms1(&current_question, &next_question,mychar);
    			break;
    		case 2:
    			print_platforms2(&current_question, &next_question,mychar);
    			break;
    		case 3:
    			print_platforms3(&current_question, &next_question,mychar);
    			break;
    		default:
    			platform_counter=1;
    			print_platforms1(&current_question, &next_question,mychar);	
		}
		
		
		high_score=get_high_score();
		print_score(score, wrong_answers, high_score, points_per_question, streak, lifeline);
		
        printf("( 0 = exit, -1  = lifeline )\nWhat is %d %c %d? ", current_question.num1,mychar, current_question.num2);
        integer_input_check(&user_answer);
        
        //call function to deal with answer
		if(is_answer_correct(&user_answer, &current_question, &score, &points_per_question, &platform_counter, &streak, &lifeline, &wrong_answers)==1){
			return;
		}
		//move to next question
        current_question = next_question;
        switch(choice){
        	case 1:	addition_question(&next_question); break;
        	case 2:	multiplication_question(&next_question); break;
        	case 3:	double_addition_question(&next_question); break;
        	case 4:	double_multiplication_question(&next_question); break;
        	default: multiplication_question(&next_question);
		}
		
		if(wrong_answers>1 && found3!=1){
			give_lifeline(&lifeline);
			found3=1;
		}
		if(wrong_answers>=3 && lifeline>0){
			printf("\nWhoopsie Daisy\n");
			printf("Almost died there didn\'t \'ya\n");
			printf("The system has used a lifeline to bring you back to life.\n");
			getchar();
			wrong_answers--;
			lifeline--;
		}else if(wrong_answers>=3 && lifeline==0){
        	clear_screen();
            printf("\nYou have failed to meet the conditions of the game\n\n\n");
            death_message();
            getchar();
            clear_screen();
            break;
        }
        save_high_score(score);
    }
return;
}
void game_menu(){
	int choice,choice2,high_score;
    while (1){
        printf("******************************\n");
	    printf("	   PIXEL LEAP\n");
	    printf("******************************\n");
	    printf("	   MAIN MENU\n");
	    printf("******************************\n");
	    printf("1. START GAME\n");
	    printf("2. HELP\n");
	    printf("3. CREDITS\n");
	    printf("4. HIGH SCORE\n");
	    printf("5. QUIT GAME\n");
	    printf("******************************\n");
	    printf("Please enter your choice : ");
	    integer_input_check(&choice);
        switch(choice){
            case 1:
            	clear_screen();
            	printf("Please read the HELP section before starting...\n");
            	printf("It addresses any queries you might have about the game\n");
            	printf("\n1. Already read it\n");
            	printf("2. Send me back\n");
            	integer_input_check(&choice2);
            	clear_screen();
				if(choice2==1){
					clear_screen();
					actual_game();
				}else if(choice2==2){
					clear_screen();
					continue;
				}else{
					printf("Invalid Input\nPress ENTER to go back to menu");
					getchar();
					clear_screen();
					continue;
				}
                break;
            case 2:
            	clear_screen();
                printf("\nHELP SECTION:\n");
			    printf("This is a simple menu-based game.\nChoose options to start the game,");
			    printf("to view credits, to view high scores, or quit the game.\n");
			    printf("Good luck!\n");
			    
			    printf("GAME HELP");
			    printf("Press 0 to exit game and return to menu\n");
			    printf("Press -1 to use a lifeline if you have any\n");
			    
			    printf("\n\nCOMMON QUESTIONS\nIf your screen is not clearing properly?\nPlease refer to the code\n");
			    printf("If you are not on a Window\'s device uncomment every system(\"clear\"); and put a comment on every system(\"cls\");\n");
			    printf("\nDon\'t know what to input?\n");
			    printf("Choices for input are given.\n");
			    printf("If no choice is given press ENTER as it is just a buffer\n");
			    printf("Try it... Just press ENTER and you\'ll move on from this screen");
                getchar();
                clear_screen();
                break;
            case 3:
            	clear_screen();
	            printf("\nCREDITS:\n");
	    		printf("Game developed by:\n");
	    		printf("Bilal Ahmed 		24K-0777\n");
	    		printf("Ahmed Nadir Shah 	24K-0609\n");
	    		printf("Syed Ashar Tahir 	24K-0582\n");
                getchar();
                clear_screen();
                break;
            case 4:
            	clear_screen();
                high_score = get_high_score();
    			printf("\nHIGH SCORE: %d\n", high_score);
                getchar();
                clear_screen();
                break;
            case 5:
            	clear_screen();
                printf("\nGAME EXITED\n");
                return;
            default:
                printf("\nInvalid choice! Please choose a valid option.\n");
                getchar();
                clear_screen();
        }
    }
}
int main() {
	game_menu();	
    return 0;
}

