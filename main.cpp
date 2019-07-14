#include <iostream>
#include "WinAdapt.h"
#include "Textbox.h"
#include "Punkt.h"
#include "World.h"
#include "Snakebody.h"
using namespace std;

World world(Punkt (100,100), Punkt (500,500));
Textbox Headline("Snake friendo", Punkt(250,10), Punkt(350, 30));
Snakebody Snake(Punkt (290,290), 119);
int counter = 0, length = 0;

void VtlInit(){
    cout << "Welcome to Snake" << endl;
}

void VtlZyk(){
    if(Snake.GetOrientation() == 119&&Snake.GetPos().Y-5>world.GetPos().Y){ //W               
    Snake.SetHeadpos(Punkt(Snake.GetPos().X, Snake.GetPos().Y-5));
    }
    if(Snake.GetOrientation() == 97&&Snake.GetPos().X-5>world.GetPos().X){    //A x-5
    Snake.SetHeadpos(Punkt(Snake.GetPos().X-5, Snake.GetPos().Y));
    }
    if(Snake.GetOrientation() == 115&&Snake.GetPos().Y+5<world.GetSize().Y){ //Sy+5
    Snake.SetHeadpos(Punkt(Snake.GetPos().X, Snake.GetPos().Y+5));
    }
    if(Snake.GetOrientation() == 100&&Snake.GetPos().X+5<world.GetSize().X){ //Dx+5
    Snake.SetHeadpos(Punkt(Snake.GetPos().X+5, Snake.GetPos().Y));
    }
	//New orientation and positioning for the bodyparts
	Snakebody* temp = Snake.NextBody;
	while(temp!=NULL){
		temp->SetHeadpos(Punkt(temp->GetPrevPos().X, temp->GetPrevPos().Y)); //Setting new position to the one of the previous object, same with orientation
		temp->SetOrientation(temp->GetPrevorient());	
		temp->SetPrevorient(temp->PrevBody->GetOrientation());		//Retrieving new position from previous object and saving it
		temp->SetPrevPos(temp->PrevBody->GetPos());
		temp = temp->NextBody;
	}
	temp = Snake.NextBody;
	//Appending of new Snakebodypart
    ++counter;
    if(counter == 10){
       
		if (length != 0) {
			while (temp->NextBody != NULL) {
				temp = temp->NextBody;
			}
			temp->AppendBodyEle();
		}
		else if (length == 0) {
			Snake.AppendBodyEle();
		}
		counter = 0;
	}
	
}
void VtlPaint(int xl, int yo, int xr, int yu){
    world.Draw();
    Headline.Draw();
    Snake.Draw();
	Snakebody* temp = Snake.NextBody;
	while(temp != NULL){
		temp->Draw();
		temp = temp->NextBody;
	}
}
void VtlKeyHit(int key){
    if(key == 119&&Snake.GetPos().Y>100){ //W               
    Snake.SetOrientation(119);
    }
    if(key == 97&&Snake.GetPos().X>100){    //A
    Snake.SetOrientation(97);
    }
    if(key == 115&&Snake.GetPos().Y+10<500){ //S
    Snake.SetOrientation(115);
    }
    if(key == 100&&Snake.GetPos().X+10<500){ //D
    Snake.SetOrientation(100);
    }
    
}

void VtlMouse(int X, int Y){

}