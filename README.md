# arduino-temp-display

Reads the temperature and humidity from a DHT11 sensor and displays them on a LCD1602 display module. Requires the Elegoo `dht_nonblocking` library since the component I used is apparently a modified version of a DHT11 that has a built-in pull up resistor (10k) and changes the pins around. If you use the Adafruit DHT library with a regular DHT11 sensor you'll need to make appropriate modifications to the code.
