#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <iostream>
#include <string>
#include "WinAdapt.h"
#include "Punkt.h"
#include "World.h"

class Textbox : public World {
protected:
    std::string text;
private:
    Punkt position;
    Punkt size;
public:
    Textbox(std::string TEXT, Punkt pos, Punkt size);
    std::string GetText();
    void SetText(std::string TEXT);
    void Draw();
    void Draw(std::string string_to_draw);

};

Textbox::Textbox(std::string TEXT, Punkt POS, Punkt SIZE): World(POS, SIZE){
    text = TEXT;
}

std::string Textbox::GetText(){
    return text;
}

void Textbox::SetText(std::string TEXT){
    text = TEXT;
}

void Textbox::Draw(){
 Rect(GetPos().X, GetPos().Y, GetSize().X, GetSize().Y);
 Text(GetPos().X + (GetSize().X - GetPos().X) / 2 - (text.size() * 3.2), GetPos().Y + (GetSize().Y - GetPos().Y) / 2 - 10, GetText().c_str());
}

void Textbox::Draw(std::string string_to_draw){
Rect(GetPos().X, GetPos().Y, GetSize().X, GetSize().Y);
Text(GetPos().X + (GetSize().X - GetPos().X) / 2 - (string_to_draw.size() * 3.2), GetPos().Y + (GetSize().Y - GetPos().Y) / 2 - 10, string_to_draw.c_str()); 
}


class Scorebox : public Textbox{
private:
    int* score_pointer;
    std::string score_string;
    std::string text_to_print;

public:
    Scorebox(std::string TEXT, Punkt POS, Punkt SIZE, int* score) : Textbox(TEXT, POS, SIZE){
        score_pointer = score;
        
        score_string = std::to_string(*score_pointer);
    }
    ~Scorebox(){
        ;
    }

    void updateScore();

    int* getScore(){
        return score_pointer;
    }
    void Draw();
protected:
};


void Scorebox::Draw(){
    

    Textbox::Draw(text_to_print);
}

void Scorebox::updateScore(){
    
    score_string = std::to_string(*score_pointer);
    text_to_print = GetText();
    text_to_print.append(score_string);
    
}

#endif