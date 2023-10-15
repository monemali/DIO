/*
 * DIO.h
 *
 * Created on: August 13, 2023
 * Author: Monem
 */

#ifndef DIO_H_
#define DIO_H_

#include <stdint.h>

#define STD_HIGH 1U
#define STD_LOW 0U

#define NUMBER_OF_PINS 8U

#define PORTA   0U
#define PORTB   1U
#define PORTC   2U
#define PORTD   3U
#define PORTE   4U
#define PORTF   5U

#define PF1_ID 41U
#define PF2_ID 42U
#define PF3_ID 43U

typedef uint8_t Dio_ChannelType;
typedef uint8_t Dio_PortType;
typedef uint8_t Dio_LevelType;
typedef uint8_t Dio_PortLevelType;

/*
 * Description: Retrieves the state of the specified DIO channel.
 * Parameters: ChannelId - ID of the DIO channel
 * Returns: Dio_LevelType - STD_HIGH if the corresponding pin's physical level is high, STD_LOW if it's low.
 */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/*
 * Description: Sets the state of a channel.
 * Parameters(In): ChannelId - ID of DIO channel
 *                 Level - Value to be written
 * Returns: None
 */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/*
 * Description: Retrieves the state of all channels of a specific port.
 * Parameters(In): PortId - ID of DIO Port
 * Returns: Dio_PortLevelType - The state of all channels of that port
 */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/*
 * Description: Sets the state of a specific port.
 * Parameters(In): PortId - ID of DIO Port
 *                 Level - Value to be written
 * Returns: None
 */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

#endif /* DIO_H_ */
