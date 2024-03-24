# IO-board communication protocol

## Communication data structure for IOboard->Server

|Byte Index|Data Type|Description|
|-|-|-|
|0|uint8|Start Byte|
|1|int8|temperature|
|2|uint8|**Bit0:** Led0 status (0:OFF, 1:ON)<br>**Bit1:** Led1 status (0:OFF, 1:ON)<br>|
|3|uint8|CRC (which is calculated from Byte0-Byte2)|
|4|uint8|Stop Byte|


## Communication data structure for Server->IOboard

|Byte Index|Data Type|Description|
|-|-|-|
|0|uint8|Start Byte|
|1|uint8|**Bit0:** Led0 set status (0:OFF, 1:ON)<br>**Bit1:** Led1 set status (0:OFF, 1:ON)<br>|
|3|uint8|CRC (which is calculated from Byte0-Byte2)|
|4|uint8|Stop Byte|

