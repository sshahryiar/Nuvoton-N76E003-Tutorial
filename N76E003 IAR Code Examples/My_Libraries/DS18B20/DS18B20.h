#include "one_wire.h"  


#define convert_T						0x44
#define read_scratchpad          		0xBE            
#define write_scratchpad				0x4E 
#define copy_scratchpad         		0x48   
#define recall_E2		        		0xB8 
#define read_power_supply				0xB4    
#define skip_ROM						0xCC

#define resolution						12


void DS18B20_init(void);
float DS18B20_get_temperature(void);  
