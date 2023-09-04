#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcdmain(0x27, 16, 2);
LiquidCrystal_I2C lcd(0x3E, 16, 2);
LiquidCrystal_I2C lcd1(0x25, 16, 2);
LiquidCrystal_I2C lcd2(0x24, 16, 2);
LiquidCrystal_I2C lcd3(0x23, 16, 2);
LiquidCrystal_I2C lcd4(0x22, 16, 2);


#define SS_PIN 5
#define RST_PIN 22

#define B1 36
#define S1 39
#define S2 34
#define S3 35
#define S4 32
#define S5 33

#define L1 13
#define L2 12
#define L3 14
#define L4 27
#define L5 26



MFRC522 rfid(SS_PIN, RST_PIN);  // Create MFRC522 instance

struct voter {         // store  voter details using structur
  String name;         // voter  name
  bool authenticated;  // voter   authenticated status (voted or not)
  String authId;       //  voter  RFID no
};
voter tags[10];  //  total number of voter is the array  size (tags[10])   11 voters details stored in this array

int eligible = 0;
int C_Candidate1 = 0;
int C_Candidate2 = 0;
int C_Candidate3 = 0;
int C_Candidate4 = 0;
int C_nota = 0;
int C_vote = 0;

int S_Candidate1 = 0;
int S_Candidate2 = 0;
int S_Candidate3 = 0;
int S_Candidate4 = 0;
int S_nota = 0;
int S_vote = 0;

int U_Candidate1 = 0;
int U_Candidate2 = 0;
int U_Candidate3 = 0;
int U_Candidate4 = 0;
int U_nota = 0;
int U_vote = 0;
float percent = 0;
int officer = 0;




void setup() {
  Wire.begin(21, 15);
  Serial.begin(9600);

  lcdmain.begin(16, 2);
  lcd.begin(16, 2);
  lcd1.begin(16, 2);
  lcd2.begin(16, 2);
  lcd3.begin(16, 2);
  lcd4.begin(16, 2);

  lcdmain.backlight();
  lcd.backlight();
  lcd1.backlight();
  lcd2.backlight();
  lcd3.backlight();
  lcd4.backlight();

  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(B1, OUTPUT);

  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);

  digitalWrite(S1, LOW);
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  digitalWrite(S4, LOW);
  digitalWrite(S5, LOW);


  tags[0].name = "Vignesh Vijay P K";
  tags[0].authenticated = false;
  tags[0].authId = { "a101db24" };
  tags[1].name = "Anuradha ch";
  tags[1].authenticated = false;
  tags[1].authId = { "d235cb16" };
  /* tags[2].name = "Vignesh Vijay P K";
  tags[2].authenticated = false;
  tags[2].authId = { "a101db24" };
  tags[3].name = "Vignesh Vijay P K";
  tags[3].authenticated = false;
  tags[3].authId = { "a101db24" };
  tags[4].name = "Vignesh Vijay P K";
  tags[4].authenticated = false;
  tags[4].authId = { "a101db24" };
  tags[5].name = "Vignesh Vijay P K";
  tags[5].authenticated = false;
  tags[5].authId = { "a101db24" };
  tags[6].name = "Vignesh Vijay P K";
  tags[6].authenticated = false;
  tags[6].authId = { "a101db24" };
  tags[7].name = "Vignesh Vijay P K";
  tags[7].authenticated = false;
  tags[7].authId = { "a101db24" };
  tags[8].name = "Vignesh Vijay P K";
  tags[8].authenticated = false;
  tags[8].authId = { "a101db24" };
  tags[9].name = "Vignesh Vijay P K";
  tags[9].authenticated = false;
  tags[9].authId = { "a101db24" };
  tags[10].name = "Vignesh Vijay P K";
  tags[10].authenticated = false;
  tags[10].authId = { "a101db24" };*/

  while (!Serial)
    ;
  SPI.begin();      // Init SPI bus
  rfid.PCD_Init();  // Init MFRC522
}

void loop() {
  RFID();

  if (eligible == 1) {
    chairman();
  } else if (eligible == 2) {
    secretary();
  } else if (eligible == 3) {
    uuc();
  } else if (eligible == 0) {
    done();
  }
  if (officer == 1) {
    result();
  }
  //93dd2f90
}

void chairman() {


  lcd.setCursor(0, 0);
  lcd.print("THE CHAIRMAN");
  lcd1.setCursor(0, 0);
  lcd1.print("C Candidate 1");
  lcd2.setCursor(0, 0);
  lcd2.print("C Candidate 2");
  lcd3.setCursor(0, 0);
  lcd3.print("C Candidate 3");
  lcd4.setCursor(0, 0);
  lcd4.print("C Candidate 4");

  if (digitalRead(S1) == 0) {
    digitalWrite(L1, HIGH);  // turn the LED on (HIGH is the voltage level)
    digitalWrite(B1, HIGH);  // turn on the buzzer
    delay(750);              // wait for a second
    digitalWrite(L1, LOW);   // turn the LED off by making the voltage LOW
    digitalWrite(B1, LOW);   // turn on the buzzer
    delay(750);
    C_Candidate1++;
    eligible++;
    lcd.clear();
    lcd1.clear();
    lcd2.clear();
    lcd3.clear();
    lcd4.clear();
  }
  if (digitalRead(S2) == 0) {
    digitalWrite(L2, HIGH);  // turn the LED on (HIGH is the voltage level)
    digitalWrite(B1, HIGH);  // turn on the buzzer
    delay(750);              // wait for a second
    digitalWrite(L2, LOW);   // turn the LED off by making the voltage LOW
    digitalWrite(B1, LOW);   // turn on the buzzer
    delay(750);
    C_Candidate2++;
    eligible++;
    lcd.clear();
    lcd1.clear();
    lcd2.clear();
    lcd3.clear();
    lcd4.clear();
  }
  if (digitalRead(S3) == 0) {
    digitalWrite(L3, HIGH);  // turn the LED on (HIGH is the voltage level)
    digitalWrite(B1, HIGH);  // turn on the buzzer
    delay(750);              // wait for a second
    digitalWrite(L3, LOW);   // turn the LED off by making the voltage LOW
    digitalWrite(B1, LOW);   // turn on the buzzer
    delay(750);
    C_Candidate3++;

    eligible++;
    lcd.clear();
    lcd1.clear();
    lcd2.clear();
    lcd3.clear();
    lcd4.clear();
  }
  if (digitalRead(S4) == 0) {
    digitalWrite(L4, HIGH);  // turn the LED on (HIGH is the voltage level)
    digitalWrite(B1, HIGH);  // turn on the buzzer
    delay(750);              // wait for a second
    digitalWrite(L4, LOW);   // turn the LED off by making the voltage LOW
    digitalWrite(B1, LOW);   // turn on the buzzer
    delay(750);
    C_Candidate4++;

    eligible++;
    lcd.clear();
    lcd1.clear();
    lcd2.clear();
    lcd3.clear();
    lcd4.clear();
  }
  if (digitalRead(S5) == 0) {
    digitalWrite(L5, HIGH);  // turn the LED on (HIGH is the voltage level)
    digitalWrite(B1, HIGH);  // turn on the buzzer
    delay(750);              // wait for a second
    digitalWrite(L5, LOW);   // turn the LED off by making the voltage LOW
    digitalWrite(B1, LOW);   // turn on the buzzer
    delay(750);
    C_nota++;
    eligible++;
    lcd.clear();
    lcd1.clear();
    lcd2.clear();
    lcd3.clear();
    lcd4.clear();
  }
}


void secretary() {

  lcd.setCursor(0, 0);
  lcd.print("THE SECRETARY");
  lcd1.setCursor(0, 0);
  lcd1.print("S Candidate 1");
  lcd2.setCursor(0, 0);
  lcd2.print("S Candidate 2");
  lcd3.setCursor(0, 0);
  lcd3.print("S Candidate 3");
  lcd4.setCursor(0, 0);
  lcd4.print("S Candidate 4");

  if (digitalRead(S1) == 0) {
    digitalWrite(L1, HIGH);  // turn the LED on (HIGH is the voltage level)
    digitalWrite(B1, HIGH);  // turn on the buzzer
    delay(750);              // wait for a second
    digitalWrite(L1, LOW);   // turn the LED off by making the voltage LOW
    digitalWrite(B1, LOW);   // turn on the buzzer
    delay(750);
    eligible++;
    S_Candidate1++;
    lcd.clear();
    lcd1.clear();
    lcd2.clear();
    lcd3.clear();
    lcd4.clear();
  }
  if (digitalRead(S2) == 0) {
    digitalWrite(L2, HIGH);  // turn the LED on (HIGH is the voltage level)
    digitalWrite(B1, HIGH);  // turn on the buzzer
    delay(750);              // wait for a second
    digitalWrite(L2, LOW);   // turn the LED off by making the voltage LOW
    digitalWrite(B1, LOW);   // turn on the buzzer
    delay(750);
    S_Candidate2++;

    eligible++;
    lcd.clear();
    lcd1.clear();
    lcd2.clear();
    lcd3.clear();
    lcd4.clear();
  }
  if (digitalRead(S3) == 0) {
    digitalWrite(L3, HIGH);  // turn the LED on (HIGH is the voltage level)
    digitalWrite(B1, HIGH);  // turn on the buzzer
    delay(750);              // wait for a second
    digitalWrite(L3, LOW);   // turn the LED off by making the voltage LOW
    digitalWrite(B1, LOW);   // turn on the buzzer
    delay(750);
    S_Candidate3++;

    eligible++;
    lcd.clear();
    lcd1.clear();
    lcd2.clear();
    lcd3.clear();
    lcd4.clear();
  }
  if (digitalRead(S4) == 0) {
    digitalWrite(L4, HIGH);  // turn the LED on (HIGH is the voltage level)
    digitalWrite(B1, HIGH);  // turn on the buzzer
    delay(750);              // wait for a second
    digitalWrite(L4, LOW);   // turn the LED off by making the voltage LOW
    digitalWrite(B1, LOW);   // turn on the buzzer
    delay(750);
    S_Candidate4++;

    eligible++;
    lcd.clear();
    lcd1.clear();
    lcd2.clear();
    lcd3.clear();
    lcd4.clear();
  }
  if (digitalRead(S5) == 0) {
    digitalWrite(L5, HIGH);  // turn the LED on (HIGH is the voltage level)
    digitalWrite(B1, HIGH);  // turn on the buzzer
    delay(750);              // wait for a second
    digitalWrite(L5, LOW);   // turn the LED off by making the voltage LOW
    digitalWrite(B1, LOW);   // turn on the buzzer
    delay(750);
    S_nota++;
    eligible++;
    lcd.clear();
    lcd1.clear();
    lcd2.clear();
    lcd3.clear();
    lcd4.clear();
  }
}

void uuc() {

  lcd.setCursor(0, 0);
  lcd.print("THE UUC");
  lcd1.setCursor(0, 0);
  lcd1.print(" U Candidate 1");
  lcd2.setCursor(0, 0);
  lcd2.print("U Candidate 2");
  lcd3.setCursor(0, 0);
  lcd3.print("U Candidate 3");
  lcd4.setCursor(0, 0);
  lcd4.print("U Candidate 4");

  if (digitalRead(S1) == 0) {
    digitalWrite(L1, HIGH);  // turn the LED on (HIGH is the voltage level)
    digitalWrite(B1, HIGH);  // turn on the buzzer
    delay(750);              // wait for a second
    digitalWrite(L1, LOW);   // turn the LED off by making the voltage LOW
    digitalWrite(B1, LOW);   // turn on the buzzer
    delay(750);
    U_Candidate1++;
    eligible = 0;
    lcd.clear();
    lcd1.clear();
    lcd2.clear();
    lcd3.clear();
    lcd4.clear();
  }
  if (digitalRead(S2) == 0) {
    digitalWrite(L2, HIGH);  // turn the LED on (HIGH is the voltage level)
    digitalWrite(B1, HIGH);  // turn on the buzzer
    delay(750);              // wait for a second
    digitalWrite(L2, LOW);   // turn the LED off by making the voltage LOW
    digitalWrite(B1, LOW);   // turn on the buzzer
    delay(750);
    U_Candidate2++;
    eligible = 0;
    lcd.clear();
    lcd1.clear();
    lcd2.clear();
    lcd3.clear();
    lcd4.clear();
  }
  if (digitalRead(S3) == 0) {
    digitalWrite(L3, HIGH);  // turn the LED on (HIGH is the voltage level)
    digitalWrite(B1, HIGH);  // turn on the buzzer
    delay(750);              // wait for a second
    digitalWrite(L3, LOW);   // turn the LED off by making the voltage LOW
    digitalWrite(B1, LOW);   // turn on the buzzer
    delay(750);
    U_Candidate3++;
    eligible = 0;
    lcd.clear();
    lcd1.clear();
    lcd2.clear();
    lcd3.clear();
    lcd4.clear();
  }
  if (digitalRead(S4) == 0) {
    digitalWrite(L4, HIGH);  // turn the LED on (HIGH is the voltage level)
    digitalWrite(B1, HIGH);  // turn on the buzzer
    delay(750);              // wait for a second
    digitalWrite(L4, LOW);   // turn the LED off by making the voltage LOW
    digitalWrite(B1, LOW);   // turn on the buzzer
    delay(750);
    U_Candidate4++;
    eligible = 0;
    lcd.clear();
    lcd1.clear();
    lcd2.clear();
    lcd3.clear();
    lcd4.clear();
  }
  if (digitalRead(S5) == 0) {
    digitalWrite(L5, HIGH);  // turn the LED on (HIGH is the voltage level)
    digitalWrite(B1, HIGH);  // turn on the buzzer
    delay(750);              // wait for a second
    digitalWrite(L5, LOW);   // turn the LED off by making the voltage LOW
    digitalWrite(B1, LOW);   // turn on the buzzer
    delay(750);
    U_nota++;
    eligible = 0;
    lcd.clear();
    lcd1.clear();
    lcd2.clear();
    lcd3.clear();
    lcd4.clear();
  }
}
void done() {
  lcd.clear();
  lcd1.clear();
  lcd2.clear();
  lcd3.clear();
  lcd4.clear();
  lcd.setCursor(0, 0);
  lcd.print("VOTING DONE ");
  lcdmain.setCursor(0, 0);
  lcdmain.print(percent);
}

void RFID() {
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    // Get tag UID
    String tagUID = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
      tagUID += String(rfid.uid.uidByte[i] < 0x10 ? "0" : "");
      tagUID += String(rfid.uid.uidByte[i], HEX);
    }

    Serial.println("Tag ID: " + tagUID);
    rfid.PICC_HaltA();       // Stop reading
    rfid.PCD_StopCrypto1();  // Stop encryption on tag

    // Check if tag UID matches authorized tag ID and hasn't been authenticated yet
    if (!tags[0].authenticated && tagUID == tags[0].authId) {

      lcdmain.clear();
      Serial.println("Authentication successful!");
      lcdmain.setCursor(0, 0);
      lcdmain.print("Eligible voter");
      lcdmain.setCursor(0, 1);
      lcdmain.print(tags[0].name);
      eligible = 1;
      tags[0].authenticated = true;
      digitalWrite(B1, HIGH);  // turn on the buzzer
      delay(700);
      digitalWrite(B1, LOW);  // turn off the buzzer
      delay(700);

    } else if (!tags[1].authenticated && tagUID == tags[1].authId) {
      lcdmain.clear();
      Serial.println("Authentication successful!");
      lcdmain.setCursor(0, 0);
      lcdmain.print("Eligible voter");
      lcdmain.setCursor(0, 1);
      lcdmain.print(tags[1].name);
      eligible = 1;
      tags[1].authenticated = true;
      digitalWrite(B1, HIGH);  // turn on the buzzer
      delay(700);
      digitalWrite(B1, LOW);  // turn off the buzzer
      delay(700);
    } else {
      lcdmain.clear();
      Serial.println("Authentication faild!");
      lcdmain.setCursor(0, 0);
      lcdmain.print("InEligible voter");
      digitalWrite(B1, HIGH);  // turn on the buzzer
      delay(900);
      digitalWrite(B1, LOW);  // turn off the buzzer
      delay(900);
    }

    if (tagUID == "93dd2f90") {
      Serial.println("Authentication successful!");
      officer = 1;
    }
  }
}
void count() {
  float div;
  C_vote = C_Candidate1 + C_Candidate2 + C_Candidate3 + C_Candidate4 + C_nota;
  S_vote = S_Candidate1 + S_Candidate2 + S_Candidate3 + S_Candidate4 + S_nota;
  U_vote = U_Candidate1 + U_Candidate2 + U_Candidate3 + U_Candidate4 + U_nota;
  div = C_vote / 2;  //2 is total voters
  percent = div * 100;
}

void result() {
  count();
  //lcdmain.clear();
  lcdmain.clear();
  lcdmain.setCursor(0, 0);
  lcdmain.print("CHAIRMAN");
  lcdmain.setCursor(0, 1);
  lcdmain.print(C_vote);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("C CANDIDATE 1");
  lcd.setCursor(0, 1);
  lcd.print(C_Candidate1);

  lcd1.clear();
  lcd1.setCursor(0, 0);
  lcd1.print("C CANDIDATE 2");
  lcd1.setCursor(0, 1);
  lcd1.print(C_Candidate2);

  lcd2.clear();
  lcd2.setCursor(0, 0);
  lcd2.print("C CANDIDATE 3");
  lcd2.setCursor(0, 1);
  lcd2.print(C_Candidate3);

  lcd3.clear();
  lcd3.setCursor(0, 0);
  lcd3.print("C CANDIDATE 4");
  lcd3.setCursor(0, 1);
  lcd3.print(C_Candidate4);

  lcd4.clear();
  lcd4.setCursor(0, 0);
  lcd4.print("C NOTA");
  lcd4.setCursor(0, 1);
  lcd4.print(C_nota);

  delay(10000);

  lcdmain.clear();
  lcdmain.setCursor(0, 0);
  lcdmain.print("SECRETARY");
  lcdmain.setCursor(0, 1);
  lcdmain.print(S_vote);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("S CANDIDATE 1");
  lcd.setCursor(0, 1);
  lcd.print(S_Candidate1);

  lcd1.clear();
  lcd1.setCursor(0, 0);
  lcd1.print("S CANDIDATE 2");
  lcd1.setCursor(0, 1);
  lcd1.print(S_Candidate2);

  lcd2.clear();
  lcd2.setCursor(0, 0);
  lcd2.print("S CANDIDATE 3");
  lcd2.setCursor(0, 1);
  lcd2.print(S_Candidate3);

  lcd3.clear();
  lcd3.setCursor(0, 0);
  lcd3.print("S CANDIDATE 4");
  lcd3.setCursor(0, 1);
  lcd3.print(S_Candidate4);

  lcd4.clear();
  lcd4.setCursor(0, 0);
  lcd4.print("S NOTA");
  lcd4.setCursor(0, 1);
  lcd4.print(S_nota);

  delay(10000);

  lcdmain.clear();
  lcdmain.setCursor(0, 0);
  lcdmain.print("UUC");
  lcdmain.setCursor(0, 1);
  lcdmain.print(U_vote);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("U CANDIDATE 1");
  lcd.setCursor(0, 1);
  lcd.print(U_Candidate1);

  lcd1.clear();
  lcd1.setCursor(0, 0);
  lcd1.print("U CANDIDATE 2");
  lcd1.setCursor(0, 1);
  lcd1.print(U_Candidate2);

  lcd2.clear();
  lcd2.setCursor(0, 0);
  lcd2.print("U CANDIDATE 3");
  lcd2.setCursor(0, 1);
  lcd2.print(U_Candidate3);

  lcd3.clear();
  lcd3.setCursor(0, 0);
  lcd3.print("U CANDIDATE 4");
  lcd3.setCursor(0, 1);
  lcd3.print(U_Candidate4);

  lcd4.clear();
  lcd4.setCursor(0, 0);
  lcd4.print("U NOTA");
  lcd4.setCursor(0, 1);
  lcd4.print(U_nota);

  delay(10000);
}