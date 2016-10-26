typedef int lumen;
typedef byte watt;

typedef struct Led{
    lumen lm;
    watt w;
    char company[10];
}Led;

Led led[3];

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

led[0].lm = random(60,100);
led[0].w = random(5,20);
strcpy(led[0].company,"Cree");

led[1].lm = random(60,100);
led[1].w = random(5,20);
strcpy(led[1].company,"Phillips");

led[2].lm = random(60,100);
led[2].w = random(5,20);
strcpy(led[2].company,"Aura");

}

void loop() {
  // put your main code here, to run repeatedly:
  static byte i=0;
  Serial.print("lumen:");
  Serial.println(led[i].lm);
  Serial.print("Watt:");
  Serial.println(led[i].w);
  Serial.println(led[i].company);
  i++;
  delay(1000);
  Serial.println("");
  if(i>2)
    {
      i=0;
      Serial.flush();
      exit(0);
    }
}
