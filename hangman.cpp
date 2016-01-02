#include<iostream>
#include<string>
#include<vector>
#include<string.h>
#include<cstdlib>
using namespace std;




class hangman{
	string word;
	string dashedWord;
	int score;
	int attemptsLeft;
	vector<int>charPos;
	bool game_status = true;

	public:
	hangman(string gWord) : word{gWord}, score{100}, attemptsLeft{3} {}


	//Set the word to start playing. Given 100 points(maximum possible score) and three attempts. 
	//A Successful guess isn't considered an attempt.
	void show(){
		cout<<"Maximum Possible score: "<<score<<endl;
		cout<<"Attempts Left: "<<attemptsLeft<<endl;
		//cout<<word;
	}
	void show(bool game){
		system("clear");
		if(game == true){
			cout<<word<<endl<<endl;
			cout<<"You have Won and you score is: "<<score<<endl;;
		}
		else{
			
			cout<<"You have lost :|"<<endl;
			cout<<"The correct word is: "<<word<<endl;
			
		}
	}
	void score_attempt_downgrade(){
		if(attemptsLeft == 3){
			attemptsLeft--;
			score = score - 50;
		}
		else if(attemptsLeft == 2){
			attemptsLeft--;
			score = score - 25;
		}
		else{
			attemptsLeft--;
			score = score - 15;
		}
	}
	void findCharNumber(char letter){
		int i = 0;
		for(string::iterator it = word.begin();it != word.end(); it++){
			if(letter == *it){
				charPos.push_back(i);
			}
			i++;
		}
	}
	void display(char a){
		//cout<<dashedWord<<endl;
		findCharNumber(a);
		while(charPos.size()){
			dashedWord.replace(charPos.back(),1,1,word[charPos.back()]);
			charPos.pop_back();
		}
		system("clear");
		cout<<dashedWord<<endl;
		show();

	}
	void display(){
		cout<<dashedWord<<endl;
		show();
	}
	void strip_space(){
		size_t found = word.find(' ',0);
		while(found != string::npos){
			word.erase(found,1);
			found = word.find(' ',found+1);
		}
	}
	void set_dashedWord(){
		strip_space();
		dashedWord = word;
		dashedWord.replace(0,word.size(),word.size(),'-');
	}
	bool check_letter(char letter){
		if(word.find(letter,0) == string::npos)return false;
		return true;
	}		

	void game_check(){
		if(!word.compare(dashedWord)){
			game_status = false;
			show(true);
		}
		else if(attemptsLeft == 0){
			game_status = false;
			show(false);
		}
	}


	void game_interface(){
		system("clear");
		set_dashedWord();
		char letter;
		display();
		while(game_status){
			cout<<"Enter the letter: ";
			cin>>letter;
			bool guess = check_letter(letter);
			if(!guess){
				score_attempt_downgrade();
			}
			display(letter);
			game_check();
		}
	}			
};




int main(){
	hangman gameOne("new year!");
	gameOne.game_interface();
	return 0;	
}  
