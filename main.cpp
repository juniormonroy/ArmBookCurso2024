#include "mbed.h"

//Create a DigitalOutput object to toggle an led whenever data is received
DigitalOut led(LED1);


// Create a UnbufferedSerial object with a default baud rate
UnbufferedSerial serial_port(USBTX, USBRX);



int main()
{
    //DigitalIn B1_USER(BUTTON1);
    
    //Set desired propertiers (9600-8-N-1)
    serial_port.baud(9600);

    serial_port.format(
        /* bits*/ 8,
        /* Parity */ SerialBase::None,
        /* stop bit */ 1
    );
    
char c;


    while (true) 
    {
        //Read the data
        if(serial_port.read(&c, 1)){
            
        //Toggle the led
        led = !led;
        
        //Send a # back to the terminal
        serial_port.write("#", 1);
        }
        //LD2 = B1_USER;
    }
}
