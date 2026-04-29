#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "YOUR_BLYNK_TOKEN";
char ssid[] = "YOUR_WIFI";
char pass[] = "YOUR_PASS";

// Motor pins
#define L_RPWM 12
#define L_LPWM 13
#define R_RPWM 14
#define R_LPWM 15

// PWM setup
#define PWM_FREQ 1000
#define PWM_RES 8

int speedVal = 180; // ~70%

HardwareSerial CamSerial(2); // UART2

void setup() {
  Serial.begin(115200);

  // Motor pins
  ledcSetup(0, PWM_FREQ, PWM_RES);
  ledcSetup(1, PWM_FREQ, PWM_RES);
  ledcSetup(2, PWM_FREQ, PWM_RES);
  ledcSetup(3, PWM_FREQ, PWM_RES);

  ledcAttachPin(L_RPWM, 0);
  ledcAttachPin(L_LPWM, 1);
  ledcAttachPin(R_RPWM, 2);
  ledcAttachPin(R_LPWM, 3);

  // UART to CAM
  CamSerial.begin(115200, SERIAL_8N1, 16, 17);

  // WiFi + Blynk
  Blynk.begin(auth, ssid, pass);
}

// MOTOR FUNCTIONS
void stopMotor() {
  ledcWrite(0, 0);
  ledcWrite(1, 0);
  ledcWrite(2, 0);
  ledcWrite(3, 0);
}

void forward() {
  ledcWrite(0, speedVal);
  ledcWrite(1, 0);
  ledcWrite(2, speedVal);
  ledcWrite(3, 0);
}

void backward() {
  ledcWrite(0, 0);
  ledcWrite(1, speedVal);
  ledcWrite(2, 0);
  ledcWrite(3, speedVal);
}

void left() {
  ledcWrite(0, 0);
  ledcWrite(1, speedVal);
  ledcWrite(2, speedVal);
  ledcWrite(3, 0);
}

void right() {
  ledcWrite(0, speedVal);
  ledcWrite(1, 0);
  ledcWrite(2, 0);
  ledcWrite(3, speedVal);
}

// BLYNK CONTROLS

BLYNK_WRITE(V0) { if (param.asInt()) forward(); else stopMotor(); }
BLYNK_WRITE(V1) { if (param.asInt()) backward(); else stopMotor(); }
BLYNK_WRITE(V2) { if (param.asInt()) left(); else stopMotor(); }
BLYNK_WRITE(V3) { if (param.asInt()) right(); else stopMotor(); }
BLYNK_WRITE(V4) { stopMotor(); }

void loop() {
  Blynk.run();
}