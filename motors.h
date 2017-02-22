#ifndef

AF_DCMotor motorlinks(1);
AF_DCMotor motorrechts(2);

void Vorwaertsfahren(int steps = 1) {
    setStepCount(steps+10);
    linkerMotor->run(FORWARD);
    rechterMotor->run(FORWARD);
    while(testStep())
    {
        delayMicroseconds(10);
    }
}

void Linksfahren(int steps = 1) {
    setStepCount(steps+10);
    linkerMotor->run(BACKWARD);
    rechterMotor->run(FORWARD);
    while(testStep())
    {
        delayMicroseconds(10);
    }
}

void Rechtsfahren(int steps = 1) {
    setStepCount(steps+10);
    linkerMotor->run(FORWARD);
    rechterMotor->run(BACKWARD);
    while(testStep())
    {
        delayMicroseconds(10);
    }
}

void Zurueckfahren(int steps = 1) {
    setStepCount(steps+10);
    linkerMotor->run(BACKWARD);
    rechterMotor->run(BACKWARD);
    while(testStep())
    {
        delayMicroseconds(10);
    }
}

void MotorStop() {
   linkerMotor->run(RELEASE);
   rechterMotor->run(RELEASE);
}

#endif
