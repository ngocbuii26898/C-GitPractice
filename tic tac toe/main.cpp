#include <iostream>

using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn ='O';
int row,column;
char name1[10];
char name2[10];
bool draw =false;

void display_board(){
	system("cls");
	
	cout<<"\tplayer "<<name1<< "[o]\n\tplayer "<<name2<<" [x]\n\n";
	
	cout<<"\t\t       |        |        \n";
	cout<<"\t\t   "<<board[0][0]<<"   |    "<<board[0][1]<<"   |   "<<board[0][2]<<"  \n";
	cout<<"\t\t_______|________|________\n";
    cout<<"\t\t       |        |        \n";
	cout<<"\t\t   "<<board[1][0]<<"   |    "<<board[1][1]<<"   |   "<<board[1][2]<<"   \n";
	cout<<"\t\t_______|________|________\n";
	cout<<"\t\t       |        |        \n";
	cout<<"\t\t   "<<board[2][0]<<"   |    "<<board[2][1]<<"   |    "<<board[2][2]<<"  \n";
	cout<<"\t\t       |        |        \n";
	


}
void player_turn(){
		int choice;
		if(turn=='O')
cout<<"\n\tplayer1 [O] turn:";
if(turn=='X')
cout<<"\n\tplayer2 [X] turn:";
cin>>choice;

switch(choice){
	case 1: row=0;column=0; break;
	case 2: row=0;column=1; break;
	case 3: row=0;column=2; break;
    case 4: row=1;column=0; break;
	case 5: row=1;column=1; break;
	case 6: row=1;column=2; break;
	case 7: row=2;column=0; break;
	case 8: row=2;column=1; break;
	case 9: row=2;column=2; break;
	default:
		cout<<"invalid choise\n";
		break;
		
			
}
if (turn=='O'&& board[row][column]!='O'&&board[row][column]!='X')
{
	board[row][column]='O';
	turn ='X';
	}
	else if(turn=='X'&&board[row][column]!='O'&&board[row][column]!='X')
	{board[row][column]='X';
	turn='O';
	}
	else {
		cout<<"\n\n\talready choise!\n\tplease choise again!\n\n";
		player_turn();
	}
	display_board();

}
bool gameover(){
	//checkwwin
	for (int i=0;i<3;i++)
	if(board[i][0]==board[i][1]&&board[i][0]==board[i][2] ||board[0][i]==board[1][i]&&board[0][i]==board[2][i])
	return false;
	if(board[0][0]==board[1][1]&&board[0][0]==board[2][2]||board[0][2]==board[1][1]&&board[0][0]==board[2][0] )
	return false;
	
	//not filled
	for (int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	if(board[i][j] !='O'&&board[i][j] !='X')
	return true;
	
	
	draw =true;
	return false;
	}
int main() {
	cout<<  "\n\n\tWelcome To Tic-tac-toe game!"<<endl;
	    cout<<" \tPlay with your way!"<<endl;
	    
		cout<<"\n\tEnter Player 1 Name:";
	cin>>name1;

	cout<<"\n\tEnter Player 2 Name:";
	cin>>name2;
		

	while(gameover()){
	
		display_board();
player_turn();
gameover();
	
	}
	if(turn =='O'&&draw ==false)
	cout<<"\n\n\t\tplayer "<<name2<<"[X] WINS!"<<endl;
	else if(turn =='X'&&draw==false)
	cout<<"\n\n\t\tplayer "<<name1<<" [O] WINS!"<<endl;
else 
cout<<"/n/t/tGAME DRAW!!\n";

	return 0;
}
