/*@author : Þükrü Erdem Gök
*@date: 13/6/2020 - 14/6/2020
*https://github.com/SukruGokk
*TDM-GCC 4.9.2 32-bit release Windows
* ~ MÝNÝ SNAKE GAME ~
*/


//LIB
#include <graphics.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//to hide console
void HideConsole()
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

int main(){

	//hide console
	HideConsole();

	//initialize window
	initwindow(250, 250);

	//snake pieces
	int snakePiecesY[100] = {10, 10, 10, 10, 10, 10};
	int snakePiecesX[100] = {200, 190, 180, 170, 160, 150};
	
	//increaser variables
	int ix = 10;
	int iy = 0;

	//for loop
	int i;
	
	//direction
	int dir = 4;
	
	//apples random coordinates
	int rx;
	int ry;

	srand(time(NULL));   // Initialization, should only be called once.
	
	//to help creating random cooordinates
	int r;
	
	r = rand() % 20;
	r += 1;
	
	//random x coordinate
	rx = r * 10;
	
	r = rand() % 20;
	r += 1;
	
	//random y coordinate
	ry = r * 10;
	int length = 6;
	
	//score
	int score = 0;
	
	//to write score we need a char list
	char scoreTxt[2] = {"0"};
	
	//main game loop
	while (true){

		//clear the window
		cleardevice();
		
		//writes score
		outtextxy(0 ,0 , scoreTxt);
		
		//turn right
    	if(GetAsyncKeyState(VK_RIGHT)){

			//block counter direction
			if (dir != 1){
				
				dir = 3;
			}

		}
    	
    	//turn left
	    else if(GetAsyncKeyState(VK_LEFT)){
			
			//block counter direction
			if (dir != 3){
				
				dir = 1;
			}
		}
		
		//turn up
	    else if(GetAsyncKeyState(VK_UP)){
	    	
	    	//block counter direction
			if (dir != 4){
				
				dir = 2;
			}
		}
		
		//turn bottom
	    else if(GetAsyncKeyState(VK_DOWN)) {
			
			//block counter direciton
			if (dir != 2){
				
				dir = 4;
			}
		}

		//move according to direction
		if (dir == 1){ix = -10; iy = 0;}
		else if (dir == 2){ix = 0; iy = -10;}
		else if (dir == 3){ix = 10; iy = 0;}
		else if (dir  == 4){ix = 0; iy = 10;}

		//move the head of snake
		snakePiecesX[0] += ix;
		snakePiecesY[0] += iy;

		//change color
		setfillstyle(11, 3);
		
		//setfillstyle pattern
		/*empty fill = 0
		*solid fill = 1
		*line fill = 2
		*lite slash fill = 3
		*slash fill = 4
		*back slash fill = 5
		*lite back slash fill = 6
		*hatch fill = 7
		*crossed hatch fill = 8
		*interleave fill = 9
		*wide dot fill = 10
		*close dot fill = 11
		*user fill = 12
		*/
		
		//setfillstyle color
		/*black = 0
		*blue = 1
		*green = 2
		*cyan = 3
		*red = 4
		*purple = 5
		*yellow = 6
		*light gray = 7
		*dark gray = 8
		*light blue = 9
		*light green = 10
		*light cyan = 11
		*light red = 12
		*light magenta = 13
		*yellow = 14
		*white = 15
		*/

		//i. piece's coordinates will be equal to i-1.pieces
		//for ex: i = 5 5.piece's coordinates will be equal to 4.piece's coordinates
		for (i = length - 1; i >=0; i--){
			
			if(i != 0){snakePiecesX[i] = snakePiecesX[i - 1];snakePiecesY[i] = snakePiecesY[i - 1];}

			setfillstyle(11, 9);

			bar(snakePiecesX[i], snakePiecesY[i], snakePiecesX[i] + 10, snakePiecesY[i] + 10);
		}

		//eat the apple
		if (snakePiecesY[0] < ry + 10 && snakePiecesY[0] + 10 > ry && snakePiecesX[0] < rx + 10 && snakePiecesX[0] +10 > rx){
			
			//change apples coordinates
			r = rand() % 20;
			r += 1;
	
			rx = r * 6;
	
			r = rand() % 20;
			r += 1;
	
			ry = r * 10;
			
			//increases the length
			length++;
			
			//increases the score
			score++;
			
			//converts score to char list
			sprintf(scoreTxt, "%d", score);
		}
		
		//out of the boundary
		if (snakePiecesX[0] > 250 or snakePiecesX[0] < 0 or snakePiecesY[0] > 250 or snakePiecesY[0] < 0){
			cleardevice();
			outtextxy(70, 100, "YOU LOSE !!!");
			delay(1000);
			closegraph();
			return 0;
		}

		//draw apple
		setfillstyle(11, 14);

		bar(rx, ry, rx + 10, ry + 10);

		delay(100);
	}

	return 0;
}

//ALGORITHM:
/*1.setup(initialize, variables etc.)
*2.get arrow key presses and change directory
*3.move the head of snake according to directory
*4.make i.piece's coordinates to i-1.piece's coordinates
*5.check if it ate the apple, and if ate, change apple's coordinates, increase the length and score, update score
*6.check if it's out of the boundary, if it is, kill the snake
*2, 3, 4, 5 and 6th steps are in loop
*/
