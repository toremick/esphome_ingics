#pragma once

#include "esphome/core/component.h"
#include "esphome/components/esp32_ble_tracker/esp32_ble_tracker.h"

#ifdef USE_ESP32

namespace esphome {
namespace ingics_ble {

struct IngicsParseResult {
  optional<float> humidity;
  optional<float> temperature;
  optional<float> pressure;
  optional<float> acceleration;
  optional<float> acceleration_x;
  optional<float> acceleration_y;
  optional<float> acceleration_z;
  optional<float> battery_voltage;
  optional<float> tx_power;
  optional<float> movement_counter;
  optional<float> measurement_sequence_number;
};

bool parse_ingics_data_byte(uint8_t data_type, const uint8_t *data, uint8_t data_length, IngicsParseResult &result);

optional<IngicsParseResult> parse_ingics(const esp32_ble_tracker::ESPBTDevice &device);

class IngicsListener : public esp32_ble_tracker::ESPBTDeviceListener {
 public:
  bool parse_device(const esp32_ble_tracker::ESPBTDevice &device) override;
};

}  // namespace ruuvi_ble
}  // namespace esphome

#endif
