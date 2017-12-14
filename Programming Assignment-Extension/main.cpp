// Step 7: Gravity change is random. Both astronauts and aliens can die and attack each other. The aliens can chase immediately the astronaut moves.

#include <iostream>
#include "Game_Command.h"
#include "Model.h"
#include "View.h"
#include "Input_Handling.h"

using namespace std;

int main()
{
 
  cout << "EC327: Introduction to Software Engineering" << endl;
  cout << "Fall 2017" << endl;
  cout << "Programming Assignment 4" << endl;

  
  char command;

  
  Model m;

  View v = View();

  char mode;

  COMP:try
  {
    cout << "Would you like to play in Normal Mode(n) or in Computer Mode(c)? ";
    cin >> mode;
    if(mode != 'n' && mode != 'c')
    {
      throw Invalid_Input("Enter 'n' for Normal Mode or 'c' for Computer Mode.");
    }
  }
  catch(Invalid_Input& except)
  {
    cout << "ERROR: " << except.msg_ptr << endl;
    cin.clear();
    cin.ignore(256, '\n');
    goto COMP;
  }

  if (mode == 'n')
  {
    m.compMode = false;
  }
  else if (mode == 'c')
  {
    m.compMode = true;
  }

  
  m.show_status();
  m.display(v);


  while (true)
  {
    bool show;

    cout << "Enter a command: ";

    try
    {
      cin >> command;
      if(cin.fail())
      {
        throw Invalid_Input("Please enter one character as the command.");
      }
      switch (command)
      {
        case 'm':
        {
          do_move_command(m);
          show = false;
          break;
        }
        case 'w':
        {
          do_work_command(m);
          show = false;
          break;
        }
        case 'd':
        {
          do_deposit_command(m);
          show = false;
          break;
        }
        case 's':
        {
          do_stop_command(m);
          show = false;
          break;
        }
        case 'l':
        {
          do_lock_command(m);
          show = false;
          break;
        }
        case 'g':
        {
          do_go_command(m);
          show = true;
          break;
        }
        case 'r':
        {
          do_run_command(m);
          show = true;
          break;
        }
        case 'a':
        {
          do_attack_command(m);
          show = false;
          break;
        }
        case 'n':
        {
          do_new_command(m);
          show = false;
          break;
        }
        case 'q':
        {
          do_quit_command(m);
          break;
        }
        default:
        {
          show = false;
          throw Invalid_Input("Please enter a valid command!");
          break;
        }
      }

      if (show)
      {
        m.display(v);
      }
    }
    catch(Invalid_Input& except)
    {
      cout << "ERROR: " << except.msg_ptr << endl;
      cin.clear();
      cin.ignore(256, '\n');
    }
  }
  return 0;
}
