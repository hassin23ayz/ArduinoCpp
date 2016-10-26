struct Phase{
    float v;
    float i;
    char *ptrLoadname;
    char phaseName[10];
};

struct Phase ph[3];

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

ph[0].v = random(150,220);
ph[0].i = random(0,5);
ph[0].ptrLoadname = "Fan";
char tmp[] = "PhaseA"; 
strcpy(ph[0].phaseName,tmp);

ph[1].v = random(150,220);
ph[1].i = random(0,5);
ph[1].ptrLoadname = "Light";
strcpy(ph[1].phaseName,"PhaseB");
//ph[1].phaseName = "phaseB"; // error incompatible types

ph[2].v = random(150,220);
ph[2].i = random(0,5);
ph[2].ptrLoadname = "airConditioner";
strcpy(ph[2].phaseName,"PhaseC");
}

void loop() {
  // put your main code here, to run repeatedly:
  static byte i=0;
  Serial.println(ph[i].v);
  Serial.println(ph[i].i);
  Serial.println(ph[i].ptrLoadname);
  Serial.println(ph[i].phaseName);
  i++;
  delay(1000);
  Serial.println("");
  if(i>2)i=0;
}
