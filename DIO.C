#include "DIO.h"
#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"

/*
 * Description: Retrieves the state of a specified DIO channel.
 * Parameters: ChannelId - The ID of the DIO channel.
 * Returns: Dio_LevelType - STD_HIGH if the corresponding pin's physical level is high, STD_LOW if it's low.
 */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId) {
    Dio_PortType portNum = ChannelId / NUMBER_OF_PINS;  /* Determine the port associated with this channel ID. */
    Dio_ChannelType pinNum = ChannelId % NUMBER_OF_PINS; /* Determine the pin number. */

    Dio_LevelType value = STD_HIGH;  /* Initialize the value to STD_HIGH. */

    switch(portNum) {
        case PORTA:
            value = getBit(GPIO_PORTA_DATA_R, pinNum);
            break;
        case PORTB:
            value = getBit(GPIO_PORTB_DATA_R, pinNum);
            break;
        case PORTC:
            value = getBit(GPIO_PORTC_DATA_R, pinNum);
            break;
        case PORTD:
            value = getBit(GPIO_PORTD_DATA_R, pinNum);
            break;
        case PORTE:
            value = getBit(GPIO_PORTE_DATA_R, pinNum);
            break;
        case PORTF:
            value = getBit(GPIO_PORTF_DATA_R, pinNum);
            break;
        default:
            break;
    }

    return value;
}

/*
 * Description: Sets the state of a channel.
 * Parameters(In): ChannelId - The ID of the DIO channel.
 *                 Level - The value to be written.
 * Returns: None
 */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level) {
    Dio_PortType portNum = ChannelId / NUMBER_OF_PINS;  /* Determine the port associated with this channel ID. */
    Dio_ChannelType pinNum = ChannelId % NUMBER_OF_PINS; /* Determine the pin number. */

    switch (portNum) {
        case PORTA:
            GPIO_PORTA_BIT_DATA(pinNum) = (Level << pinNum);
            break;
        case PORTB:
            GPIO_PORTB_BIT_DATA(pinNum) = (Level << pinNum);
            break;
        case PORTC:
            GPIO_PORTC_BIT_DATA(pinNum) = (Level << pinNum);
            break;
        case PORTD:
            GPIO_PORTD_BIT_DATA(pinNum) = (Level << pinNum);
            break;
        case PORTE:
            GPIO_PORTE_BIT_DATA(pinNum) = (Level << pinNum);
            break;
        case PORTF:
            GPIO_PORTF_BIT_DATA(pinNum) = (Level << pinNum);
            break;
        default:
            break;
    }
}

/*
 * Description: Retrieves the state of all channels of a specific port.
 * Parameters(In): PortId - The ID of the DIO port.
 * Returns: Dio_PortLevelType - The state of all channels of that port.
 */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId) {
    Dio_PortLevelType result;

    switch (PortId) {
        case PORTA:
            result = (uint8_t)GPIO_PORTA_DATA_R;
            break;
        case PORTB:
            result = (uint8_t)GPIO_PORTB_DATA_R;
            break;
        case PORTC:
            result = (uint8_t)GPIO_PORTC_DATA_R;
            break;
        case PORTD:
            result = (uint8_t)GPIO_PORTD_DATA_R;
            break;
        case PORTE:
            result = (uint8_t)GPIO_PORTE_DATA_R;
            break;
        case PORTF:
            result = (uint8_t)GPIO_PORTF_DATA_R;
            break;
        default:
            break;
    }
    return result;
}

/*
 * Description: Sets the state of a specific port.
 * Parameters(In): PortId - The ID of the DIO port.
 *                 Level - The value to be written.
 * Returns: None
 */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level) {
    switch (PortId) {
        case PORTA:
            GPIO_PORTA_DATA_R = Level;
            break;
        case PORTB:
            GPIO_PORTB_DATA_R = Level;
            break;
        case PORTC:
            GPIO_PORTC_DATA_R = Level;
            break;
        case PORTD:
            GPIO_PORTD_DATA_R = Level;
            break;
        case PORTE:
            GPIO_PORTE_DATA_R = Level;
            break;
        case PORTF:
            GPIO_PORTF_DATA_R = Level;
            break;
        default:
            break;
    }
}
