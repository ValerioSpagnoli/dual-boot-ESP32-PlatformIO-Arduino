#include "app.h"

void setup() {
  Serial.begin(115200);
  pinMode(SWITCH_PARTITION_PIN, INPUT_PULLUP);
  switch_firmware();
}

void loop() {
  switch_firmware();

  #ifdef OTA_0
    Serial.println("Blinking OTA_0");
  #endif

  #ifdef OTA_1
    Serial.println("Blinking OTA_1");  
  #endif

  delay(1000);
}

void switch_firmware(){
  if (digitalRead(SWITCH_PARTITION_PIN) == SWITCH_PIN_STATE) {
    const esp_partition_t *partition = esp_partition_find_first(ESP_PARTITION_TYPE_APP, PARTITION_TYPE, NULL);
    if (partition != nullptr){

      esp_err_t ret = esp_ota_set_boot_partition(partition);
      if (ret != ESP_OK) Serial.printf("Failed to set boot partition");
      else {
        Serial.println("Boot partition set, restarting");
        esp_restart();
      }
    }
    else Serial.println("Failed to find the application partition");
  }
}