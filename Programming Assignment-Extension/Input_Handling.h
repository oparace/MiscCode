#ifndef INPUT_HANDLING
#define INPUT_HANDLING

class Invalid_Input 
{
public:
  Invalid_Input(const char* in_ptr) : msg_ptr(in_ptr) {}
  const char* const msg_ptr;
private:
  Invalid_Input();
};

#endif