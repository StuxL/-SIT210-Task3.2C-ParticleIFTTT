int LDR = A1;
int lux = 0;
bool light_detected = false;

//Define Lux variable which can be accessed via the Web IDE
void setup() {
    Particle.variable("Lux", &lux, INT);
    pinMode(LDR, INPUT);
}

void loop() {
    //Read value from A1 pin
    lux = analogRead(LDR);
    
    //If no light previously detected, and now sufficient light detected
    //Publish "Light-detected" event and set light_detected true
    if (!light_detected & lux > 250)
    {
        Particle.publish("Light-detected");
        light_detected = true;
    }
    //Else if light is no longer detected, set as false
    else if (light_detected & lux < 250)
    {
        light_detected = false;
    }
    delay(10000);
}
