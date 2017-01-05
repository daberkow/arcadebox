#include <Bounce.h>

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.

// Buttons 1-6, then left, right, up, down, start select
uint8_t buttons[12] = {1, 9, 0, 8, 16, 15, 11, 2, 4, 10, 14, 13};
int keyPress[12]  = {KEY_Z, KEY_X, KEY_C, KEY_A, KEY_S, KEY_D, KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN, KEY_ENTER, KEY_HOME};

Bounce buttonHolder[12] = {
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
  buttonHolder[11] = Bounce(buttons[11], 10)
};

void setup() {
  for (int i=0; i < 12; i++){
    pinMode(buttons[i], INPUT_PULLUP);
  }
}

void loop() {
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.
  for (int i=0; i < 12; i++){
    buttonHolder[i].update();
  }

  // Check each button for "falling" edge.
  // Type a message on the Keyboard when each button presses
  // Update the Joystick buttons only upon changes.
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)
  for (int i=0; i < 12; i++){
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
  for (int i=0; i < 12; i++){
    if (buttonHolder[i].risingEdge()) {
      Keyboard.release(keyPress[i]);
    }
  }
}

