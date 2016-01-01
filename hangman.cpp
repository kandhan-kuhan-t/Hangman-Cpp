#include<iostream>
#include<string>
#include<vector>

using namespace std;

class hangman{
	string word;
	string dashedWord;
	int score;
	int attemptsLeft;
	vector<int>charPos;
	public:
	hangman(string gWord) : word{gWord}, score{100}, attemptsLeft{3} {}
	//Set the word to start playing. Given 100 points(maximum possible score) and three attempts. 
	//A Successful guess isn't considered an attempt.
	void show(){
		cout<<"Maximum Possible score: "<<score<<endl;
		cout<<"Attempts Left: "<<attemptsLeft<<endl;
	}
	void show(bool game){
		if(game == true){
			cout<<"You have Won and you score is: "<<score<<endl;;
		}
		else{
			cout<<"You have lost :| "<<endl;
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
		for(iterator it = str.begin();it != str.end(); it++){
			if(letter == *it){
				charPos.push_back(i);
			}
		i++;
		}
	}
	void display(){
					
		
};

int main(){
	hangman gameOne("new year!");
	gameOne.show();
	gameOne.score_attempt_downgrade();
	gameOne.show();
	gameOne.show(true);
	return 0;	
}  
