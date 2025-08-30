

float Kp, Ki, Kd;
float integral, pError;

float led_val,pot_val;
float computePID(float setpoint, float input, float dt) {
    float error = setpoint - input;
    float derivative = (error - pError) / dt;
    pError = error;
    integral += error * dt;
    return error * Kp + integral * Ki + derivative * Kd;
}
void setup() {
  // put your setup code here, to run once:
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(3,OUTPUT);
  Serial.begin(9600);
  Kp = 0.1;
  Ki = 0.1;
  Kd = 0;

}
void loop() {
  // put your main code here, to run repeatedly:
  
  led_val = analogRead(A1);
  pot_val = analogRead(A2);
  pot_val = map(pot_val,0,600,0,80);
  led_val = map(led_val,20,80,0,80);
// риды дацеков
  
  
  //
  float computedPID = computePID(pot_val, led_val, 0.01);
  //computedPID = map(computedPID,-1000,1000,0,255);
  analogWrite(3, computedPID);
  Serial.print(led_val);
  Serial.print(" ");
  Serial.print(pot_val);
  Serial.print(" ");
  Serial.println(computedPID);
  delay(100);
  // ПИДР РЕГУЛЯТОР
}
