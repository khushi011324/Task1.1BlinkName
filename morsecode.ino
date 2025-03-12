#define LED_PIN 13      
#define BUTTON_PIN 2    

bool buttonPressed = false;  
bool blinking = false;       


const char* morseCode[] = {
    "-.-",  // K
    "....", // H
    "..-",  // U
    "...",  // S
    "....", // H
    ".."    // I
};


void dot() {
    digitalWrite(LED_PIN, HIGH);
    delay(500); //0.5
    digitalWrite(LED_PIN, LOW);
    delay(500);  //0.5
}


void dash() {
    digitalWrite(LED_PIN, HIGH);
    delay(1500); 
    digitalWrite(LED_PIN, LOW);
    delay(500);  
}


void blinkLetter(const char* letter) {
    while (*letter) {
        if (*letter == '.') dot();
        else if (*letter == '-') dash();
        letter++;
    }
    delay(2000); // (2 sec)
}


void blinkName() {
    for (int i = 0; i < 6; i++) {  
        blinkLetter(morseCode[i]);
    }
    delay(3000); 
}

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);  // keeps the button high when not pressed 
}

void loop() {
    if (digitalRead(BUTTON_PIN) == LOW) {  
        delay(50);       // filter out quick signals
        if (!buttonPressed) {
            buttonPressed = true; 
            blinking = !blinking; // toggle

            if (blinking) {
                blinkName();
            }
        }
    } else {
        buttonPressed = false; 
    }
}
