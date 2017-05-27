#include <Bounce.h>

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.

// Buttons 1-6, then left, right, up, down, start select
uint8_t buttons[25] = {0,    1,       2,    3,    4,      5,    6,        7,          8,      9,        10,       11,     12,     13,   14,   15,     16,   17,     18,     19,   20,   21,     22,   23, 26};
int keyPress[25]  = {KEY_Z, KEY_X, KEY_C, KEY_A, KEY_S, KEY_D, KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN, KEY_ENTER, KEY_D, KEY_B, KEY_E, KEY_F, KEY_G, KEY_H, KEY_J, KEY_L, KEY_M, KEY_N, KEY_O, KEY_Y, KEY_T, KEY_T};

Bounce buttonHolder[25] = {
  buttonHolder[0] = Bounce(buttons[0], 10),
  buttonHolder[1] = Bounce(buttons[1], 10),
  buttonHolder[2] = Bounce(buttons[2], 10),
  buttonHolder[3] = Bounce(buttons[3], 10),
  buttonHolder[4] = Bounce(buttons[4], 10),
  buttonHolder[5] = Bounce(buttons[5], 10),
  buttonHolder[6] = Bounce(buttons[6], 10),
  buttonHolder[7] = Bounce(buttons[7], 10),
  buttonHolder[8] = Bounce(buttons[8], 10),
  buttonHolder[9] = Bounce(buttons[9], 10),
  buttonHolder[10] = Bounce(buttons[10], 10),
  buttonHolder[11] = Bounce(buttons[11], 10),
  buttonHolder[12] = Bounce(buttons[12], 10),
  buttonHolder[13] = Bounce(buttons[13], 10),
  buttonHolder[14] = Bounce(buttons[14], 10),
  buttonHolder[15] = Bounce(buttons[15], 10),
  buttonHolder[16] = Bounce(buttons[16], 10),
  buttonHolder[17] = Bounce(buttons[17], 10),
  buttonHolder[18] = Bounce(buttons[18], 10),
  buttonHolder[19] = Bounce(buttons[19], 10),
  buttonHolder[20] = Bounce(buttons[20], 10),
  buttonHolder[21] = Bounce(buttons[21], 10),
  buttonHolder[22] = Bounce(buttons[22], 10),
  buttonHolder[23] = Bounce(buttons[23], 10),
  buttonHolder[24] = Bounce(buttons[24], 10)
};

void setup() {
  for (int i=0; i < 24; i++){
    pinMode(buttons[i], INPUT_PULLUP);
  }
}

void loop() {
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.
  for (int i=0; i < 25; i++){
    buttonHolder[i].update();
  }

  // Check each button for "falling" edge.
  // Type a message on the Keyboard when each button presses
  // Update the Joystick buttons only upon changes.
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)
  for (int i=0; i < 25; i++){
    if (buttonHolder[i].fallingEdge()) {
      Keyboard.press(keyPress[i]);
    }
  }
  
  // Check each button for "rising" edge
  // Type a message on the Keyboard when each button releases.
  // For many types of projects, you only care when the button
  // is pressed and the release isn't needed.
  // rising = low (pressed - button connects pin to ground)
  //          to high (not pressed - voltage from pullup resistor)
  for (int i=0; i < 25; i++){
    if (buttonHolder[i].risingEdge()) {
      Keyboard.release(keyPress[i]);
    }
  }
}

