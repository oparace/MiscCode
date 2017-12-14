
#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class Game_Object
{

	protected:
		Cart_Point location;
		int id_num;
		char display_code;
		char state;


	public: 
    
		Game_Object(char in_code);
		Game_Object(Cart_Point, int, char);
		virtual ~Game_Object();
		Cart_Point get_location();
		int get_id();
		char get_state();
		virtual void show_status();
		virtual bool update() = 0;
		void drawself(char* ptr);

};

#endif
