// Unlike in C, where passing by reference was really just passing a pointer by value, in C++ we can genuinely pass by reference.


void pass_by_ptr_C(int* ptr_a);
void pass_by_ref_Cpp(int& ref_a);
void pass_by_ptr_C_Cpp_array(int* ptr_array);
void pass_by_ref_Cpp_array(int (&ref_array)[8]);


void setup() 
{
  Serial.begin(9600);
  int a = 1;
  Serial.print("initially value of a is: ");
  Serial.println(a,DEC);
  pass_by_ptr_C(&a);
  Serial.print("by C After pass by pointer (pass by value(memory) actually)\nwhich is in C known as pass by refrence .. value of a is: ");
  Serial.println(a,DEC);  
  pass_by_ref_Cpp(a);
  Serial.print("by C++ After pass by reference(genuine).. value of a is: ");
  Serial.println(a,DEC);

  Serial.println("--------------------------------");
  Serial.println("Array operation using pointer *:");
  int array[8] = {0,1,2,3,4,5,6,7};
  pass_by_ptr_C_Cpp_array(array);

  Serial.println("--------------------------------");
  Serial.println("Array operation using reference &:");
  pass_by_ref_Cpp_array(array);
}

void pass_by_ptr_C(int* ptr_a)
{
  *ptr_a = 2;
}

void pass_by_ref_Cpp(int& ref_a)
{
  ref_a = 3;
}

void pass_by_ptr_C_Cpp_array(int* ptr_array)
{
  for(byte i=0; i<8; i++)
  {
    Serial.println(ptr_array[i]);
  }
  Serial.println("***********************");
  for(byte i=0; i<8; i++)
  {
    Serial.println(*(ptr_array+i));
  }
}

void pass_by_ref_Cpp_array(int (&ref_array)[8])
{
  for(byte i=0; i<8; i++)
  {
    Serial.println(ref_array[i]);
  }  
}

void loop()
{

}
