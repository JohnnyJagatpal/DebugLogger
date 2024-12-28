# DebugLogger

**DebugLogger** is a lightweight logging library for Arduino and PlatformIO projects. It provides macros and functions for logging messages at different levels, such as `DEBUG`, `INFO`, `WARNING`, and `ERROR`, with configurable log levels using build flags.

---

## Features

- Easy-to-use logging macros for different levels (`LOG_DEBUG`, `LOG_INFO`, `LOG_WARNING`, `LOG_ERROR`).
- Customizable log levels via build flags (`-DDEBUG`, `-DINFO`, etc.).
- Outputs messages with context (e.g., function names).
- Works with both Arduino IDE and PlatformIO.

---

## Installation

### For Arduino IDE:
1. Download or clone this repository.
2. Compress the library folder as a `.zip` file.
3. In the Arduino IDE, go to **Sketch > Include Library > Add .ZIP Library** and import the `.zip`.

### For PlatformIO:
Place the library folder in the `lib/` directory of your project.

---

## Usage

### Example Sketch
```cpp
#include <Arduino.h>
#include <DebugLogger.h>

void setup() {
    Serial.begin(9600);

    LOG_DEBUG("This is a debug message");
    LOG_INFO("This is an info message");
    LOG_WARNING("This is a warning message");
    LOG_ERROR("This is an error message");
}

void loop() {
    // Your code here
}
```

### Configure Log Levels
Set the desired log level by defining one of the following flags during compilation:
- `-DDEBUG`: Enables `DEBUG`, `INFO`, `WARNING`, and `ERROR`.
- `-DINFO`: Enables `INFO`, `WARNING`, and `ERROR`.
- `-DWARNING`: Enables `WARNING` and `ERROR`.
- `-DERROR`: Enables only `ERROR`.

For PlatformIO, add the flags in your `platformio.ini`:
```ini
build_flags = -DDEBUG
```

---

## License

This library is licensed under the GPL v 3.0 License. See [LICENSE](LICENSE) for details.

---

## Contribution

Contributions, issues, and feature requests are welcome! Feel free to open an issue or submit a pull request. 

--- 

This `README.md` provides a concise overview of the library, installation instructions, and a quick usage guide.