/*
 * @file: T41_template_function
 * @brief: this skecth will show the usage of template function which is the foundation of generic programming
 */

void setup() 
{
  Serial.begin(9600);
  Serial.println("nameplate usage example");

  //adding ints
  Serial.print("5+6: ");
  Serial.println(add(5,6));

  //adding floats
  Serial.print("5.1+6.2: ");
  Serial.println(add(5.1,6.2));

  //adding negative float
  Serial.print("5.1-6.2: ");
  Serial.println(add(5.1,-6.2));

  /*
   * //wont compile as both arguments should be same typed
  Serial.print("5+6.2: ");
  Serial.println(add(5,6.2));
  */

  //will compile now
  Serial.print("5+6.2: ");
  Serial.println(add(5.0,6.2));
  
}

void loop() 
{}

template<class AnyDataType>AnyDataType add(AnyDataType a, AnyDataType b)
{
  return(a+b);
}

