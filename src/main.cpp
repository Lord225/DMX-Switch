#include <Arduino.h>
#include <DMXSerial.h>


struct PinSettings {
  /// The pin number maped to the DMX channel
  uint8_t pin;
  /// The DMX channel
  int channel;
  /// The default value of the pin when no DMX signal is received. Note that it is reversed if reverse is true
  int defaultValue;
  /// If the value should be reversed
  bool reverse;
};

constexpr auto DMX_TIMEOUT_TIME = 1000;

// Define the mapping of DMX channels to pins
constexpr PinSettings PIN_MAPPER[] = {
  {13, 1, 0, true},
  {12, 2, 0, true},
};

void setup() {
  DMXSerial.init(DMXReceiver);
  // set all pins to output
  for (const auto& pin : PIN_MAPPER) {
    pinMode(pin.pin, OUTPUT);
  }
}

uint8_t mapValue(const uint8_t value, const PinSettings& pin) {
  if (pin.reverse) {
    return 255 - value;
  }
  return value;
}

void setPin(const uint8_t value, const PinSettings& pin) {
  digitalWrite(pin.pin, mapValue(value, pin) > 127 ? HIGH : LOW);
}

void loop() {
  const auto lastPacket = DMXSerial.noDataSince();


  if (lastPacket > DMX_TIMEOUT_TIME) {
    for (const auto& pin : PIN_MAPPER) {
      setPin(pin.defaultValue, pin);
    }
  } else {
    for (const auto& pin : PIN_MAPPER) {
      setPin(DMXSerial.read(pin.channel), pin);
    }
  }
}

