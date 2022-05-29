

void delay_us(unsigned int value);
void delay_ms(unsigned int value);


void delay_us(unsigned int value)
{
  value = (value / (16 / 16));
  
  while(value > 0)
  {
    asm("nop");
    value--;
  }
}


void delay_ms(unsigned int value)
{ 
  while(value > 0)
  {
    --value;
    delay_us(1000);
  }
}
