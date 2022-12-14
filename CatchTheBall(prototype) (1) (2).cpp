/*Nama anggota :
* Abi Ihza Rafi Alfano  2217051114
* Audhia Safitri        2217051105
* M. Arif Rizki Pohan    2217051090
*
* UAP TEAM 13
*/

#include<iostream>
#include<conio.h>
#include<dos.h> 
#include <windows.h>
#include <time.h>

#define LEBAR_LAYAR 90
#define TINGGI_LAYAR 27
#define WIN_WIDTH 70 
#define MENU_WIDTH 20

using namespace std; 
 
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int bolaY[5];
int bolaX[5];
int bolaFlag[3];
char keranjang[2][9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',
					'|','_','_','_','_','_','_','_','|' }; 
					
int keranjangPos = WIN_WIDTH/2;
int score = 0; 

void gotoxy(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void setcursor(bool visible, DWORD size) {
	if(size == 0)
		size = 20;	
	
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}


void Border(){ 
	
	for(int i=0; i<LEBAR_LAYAR; i++){
		gotoxy(i,0); cout<<"±";
		gotoxy(i,TINGGI_LAYAR); cout<<"±";
	}
	
	for(int i=0; i<TINGGI_LAYAR; i++){
		gotoxy(0,i); cout<<"±";
		gotoxy(LEBAR_LAYAR,i); cout<<"±";
	}
	for(int i=0; i<TINGGI_LAYAR; i++){
		gotoxy(WIN_WIDTH,i); cout<<"±";
	}
}

void arahBola(int ind){
	bolaX[ind] = 2 + rand()%(40);  
}
void gambarBola(int ind){
	if( bolaFlag[ind] == true ){
		gotoxy(bolaX[ind], bolaY[ind]);   cout<<"O";  

	} 
}

void hapusBola(int ind){
	if( bolaFlag[ind] == true ){
		gotoxy(bolaX[ind], bolaY[ind]); cout<<" ";  

	} 
}
void resetBola(int ind){
	hapusBola(ind);
	bolaY[ind] = 1;
	arahBola(ind);
}

void gambarKeranjang(){
	for(int i=0; i<2; i++){
		for(int j=0; j<9; j++){
			gotoxy(j+keranjangPos, i+22); cout<<keranjang[i][j];
		}
	}
}
void hapusKeranjang(){
	for(int i=0; i<2; i++){
		for(int j=0; j<9; j++){
			gotoxy(j+keranjangPos, i+22); cout<<" ";
		}
	}
}

//void gameover(){
//	system("cls");
//	cout<<endl;
//	cout<<"\t\t--------------------------"<<endl;
//	cout<<"\t\t-------- Game Over -------"<<endl;
//	cout<<"\t\t--------------------------"<<endl<<endl;
//	cout<<"\t\t Your Score\t: "<<score;
//	cout<<"\t\tPress any key to go back to menu.";
//	getch();
//
//}


void loading()
	//Prosedur untuk menambahkan loading screen sebelum masuk menu
{
	
	for(int i=1; i<=3; i++){
		system("cls");
		gotoxy(15,10);cout<<"LOADING [         ]";
		Sleep(100);
		gotoxy(15,10);cout<<"LOADING [=>       ]";
		Sleep(100);
		gotoxy(15,10);cout<<"LOADING [==>      ]";
		Sleep(100);
		gotoxy(15,10);cout<<"LOADING [===>     ]";
		Sleep(100);
		gotoxy(15,10);cout<<"LOADING [====>    ]";
		Sleep(100);
		gotoxy(15,10);cout<<"LOADING [=====>   ]";
		Sleep(100);
		gotoxy(15,10);cout<<"LOADING [======>  ]";
		Sleep(100);
		gotoxy(15,10);cout<<"LOADING [=======> ]";
		Sleep(100);
		gotoxy(15,10);cout<<"LOADING [=========]";
		Sleep(100);
		
	}
	system("cls");
	gotoxy(15,15);cout<<"SELAMAT BERMAIN ! ";
}

void instructions(){
	
	system("cls");
	cout<<"Instructions";
	cout<<"\n----------------";
	cout<<"\n Catch balls by moving left or right. ";
	cout<<"\n\n Press 'a' to move left";
	cout<<"\n Press 'd' to move right";
	cout<<"\n Press 'escape' to exit";
	cout<<"\n\nPress any key to go back to menu";
	getch();
}

void play(){
	keranjangPos = -1 + WIN_WIDTH/2;

	bolaFlag[0] = 1;
	bolaFlag[1] = 0;
	bolaY[0] = bolaY[1] = 1;
	  
	system("cls"); 
	Border(); 
	arahBola(0);
	arahBola(1);
	
	gotoxy(WIN_WIDTH + 4, 2);cout<<"Catch the Ball";
	gotoxy(WIN_WIDTH + 6, 4);cout<<"----------";
	gotoxy(WIN_WIDTH + 6, 6);cout<<"----------";
	gotoxy(WIN_WIDTH + 7, 12);cout<<"Control ";
	gotoxy(WIN_WIDTH + 7, 13);cout<<"-------- ";
	gotoxy(WIN_WIDTH + 2, 14);cout<<" A Key - Left";
	gotoxy(WIN_WIDTH + 2, 15);cout<<" D Key - Right"; 
	
	gotoxy(18, 5);cout<<"Press any key to start";
	getch();
	gotoxy(18, 5);cout<<"                      ";
	
	while(1){
		if(kbhit()){
			char ch = getch();
			if( ch=='a' || ch=='A' ){
				if( keranjangPos > 2 )
					keranjangPos -= 4;
			}
			if( ch=='d' || ch=='D' ){
				if( keranjangPos < 58 )
					keranjangPos += 5;
			} 
			if(ch==27){
				break;
			}
		} 
		
		gambarKeranjang(); 
		gambarBola(0); 
		gambarBola(1);
		
		
		Sleep(100);
		hapusKeranjang();
		hapusBola(0);
		hapusBola(1);   
		
		if( bolaY[0] == 10 )
			if( bolaFlag[1] == 0 )
				bolaFlag[1] = 1;
				
			
		
		if( bolaFlag[0] == 1 )
			bolaY[0] += 1;
			score++;
			
		
		if( bolaFlag[1] == 1 )
			bolaY[1] += 1;
		 
		if( bolaY[0] > TINGGI_LAYAR-4 ){
			resetBola(0);
		
		}
		if( bolaY[1] > TINGGI_LAYAR-4 ){
			resetBola(1);
		
		}
	}
}

int main()
{
	loading();
	setcursor(0,0); 
	srand( (unsigned)time(NULL)); 
	 
	do{
		system("cls");
		gotoxy(10,5); cout<<" -------------------------- "; 
		gotoxy(10,6); cout<<" |     Catch The Ball     | "; 
		gotoxy(10,7); cout<<" --------------------------";
		gotoxy(10,9); cout<<"1. Start Game";
		gotoxy(10,10); cout<<"2. Instructions";	 
		gotoxy(10,11); cout<<"3. Quit";
		gotoxy(10,13); cout<<"Select option: ";
		char op = getche();
		
		if( op=='1') loading(), play();
		else if( op=='2') instructions();
		else if( op=='3') exit(0);
		
	}while(1);
	
	return 0;
}
