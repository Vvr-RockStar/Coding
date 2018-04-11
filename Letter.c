#include <stdio.h>
#include <string.h>

struct count {
	//to count no of words
	int counter;
	//to include the letter
	char letter;
};

int main(){

	//get the string from user
	printf("Input Your String :");
	char inputt[100];
	gets(inputt);

	//read the length of string
	int length = strlen(inputt);

	//create length of input so min to max get covered
	struct count cnt[100];

	//read a to z
	int readLetterUp = 65,readLetterDown = 97;
	int toggle = 0,number=0;

	
	//upper case
	for(int i=readLetterUp; i<=90; i++){
		//add the letter to data
		cnt[number].counter = 0;
		printf("number = \n",number);
		cnt[number].letter = readLetterUp;
		//start reading for all uppercase in the string
		for(int j=0; j<=length; j++){
			/*while reading string if checking letter is same as the reading string
			  then increase the letter counter
			  else just go ahed
			*/
			if(inputt[j] == i || inputt[j] == readLetterUp){
				cnt[number].counter += 1;
				number++;
				printf("LOG: cnt[%d].counter = %d \t cnt[%d].letter = %c\n",number,cnt[number].counter, number,cnt[number].letter);
			}
			else{
					number++;
			}
		}
	}

	return 0;
}
