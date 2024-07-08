#include <Arduino.h>
#include <esp_ota_ops.h>

/*
 ** OTA partitions
 *  - OTA_0: Partition 0
 *  - OTA_1: Partition 1
 *  - SWITCH_PARTITION_PIN: Pin to switch between partitions
*/
#define SWITCH_PARTITION_PIN 16

#ifdef OTA_0
#define PARTITION_TYPE ESP_PARTITION_SUBTYPE_APP_OTA_1
#define SWITCH_PIN_STATE LOW
#endif

#ifdef OTA_1
#define PARTITION_TYPE ESP_PARTITION_SUBTYPE_APP_OTA_0
#define SWITCH_PIN_STATE HIGH
#endif

//** Setup
void switch_firmware();