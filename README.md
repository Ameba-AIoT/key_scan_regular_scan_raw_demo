* [中文版本](./README.md)

### Ameba RTL8721Dx SoC: key_scan_regular_scan_demo (Raw API, FreeRTOS)

🚀 This example is based on the Key-Scan peripheral of the RTL8721Dx SoC.  
It demonstrates how to use a **4×4 keypad matrix** in **regular scan mode** with the raw API.

- 📎 EVB Purchase Links: [🛒 Taobao](https://item.taobao.com/item.htm?id=904981157046) | [📦 Amazon](https://www.amazon.com/-/zh/dp/B0FB33DT2C/)
- 📄 [Chip Information](https://aiot.realmcu.com/cn/module/index.html)
- 📚 [Key-Scan Documentation](https://aiot.realmcu.com/cn/latest/rtos/peripherals/key_scan/index.html)

---

### ✨ Features

✅ 4×4 keypad matrix support  
✅ **Regular scan mode**:  
  - Only **key press events** are recorded in the FIFO (key release is not stored as a separate event)  
  - While a key remains pressed, its press event stays in the FIFO until the key is released and handled by the system  

✅ Multi-key detection: up to **6 keys** can be pressed simultaneously  
✅ Provides detailed 4×4 keypad pin assignment and comparison diagrams for easier wiring and understanding  

#### 4×4 Keypad Matrix Pin Assignment

![alt text](image.png)

Row pins:

| Row | Pin  |
|-----|------|
| Row 1 | PA31 |
| Row 2 | PA30 |
| Row 3 | PA29 |
| Row 4 | PA28 |

Column pins:

| Column | Pin  |
|--------|------|
| Col 1 | PB17 |
| Col 2 | PB18 |
| Col 3 | PB20 |
| Col 4 | PA14 |

---

### Working Principle

- The Key-Scan peripheral scans row/column pins to detect state changes on the keypad matrix.  
- When a key is pressed or released, an interrupt is generated and the event is written into the FIFO.  
- This demo uses **regular scan mode**:  
  - An application thread reads key data from the FIFO and decodes the row/column to identify the specific key;  
  - Compared with **event trigger mode**, regular scan mode is more like “continuous scanning + pressed-state record”.  
- For more details, refer to the SDK Key-Scan chapter:  
  📚 [Key-Scan Documentation](https://aiot.realmcu.com/cn/latest/rtos/peripherals/key_scan/index.html)

- Difference between regular scan mode and event trigger mode:  
  ![alt text](image-1.png)

---

### 🚀 Quick Start

1️⃣ **Set Up SDK Environment**

- Configure the `env.sh` (or `env.bat`) path:

  ```bash
  source {sdk}/env.sh
  ```

- Replace `{sdk}` with the absolute path to `env.sh` in the root directory of the [ameba-rtos SDK](https://github.com/Ameba-AIoT/ameba-rtos).  
- If the SDK path does not change, this step only needs to be executed once.

⚡ **Note**: This example supports SDK version **≥ v1.2**.

2️⃣ **Build the Project**

In this demo root directory (for example, this demo or `HELLO_WORLD`), run:

```bash
source env.sh
ameba.py build -p
```

3️⃣ **Flash to the EVB**

⚡ **Note**: Precompiled bin files are provided in this project directory and can be flashed directly:

```bash
ameba.py flash --p COMx --image km4_boot_all.bin 0x08000000 0x8014000 --image km0_km4_app.bin 0x08014000 0x8200000
```

> If you want to use bin files from the parent directory, adjust the paths accordingly before flashing.

4️⃣ **Open Serial Monitor**

```bash
ameba.py monitor --port COMx --b 1500000
```

> Replace `COMx` with the actual serial port, e.g. `COM5`.

5️⃣ **Keypad Test**

- Press and release keys on the 4×4 keypad matrix;  
- Observe key events printed on the serial terminal (including row/column information);  
- Combine with the “regular scan vs event trigger mode” diagram to better understand the log output.

6️⃣ **Check Log Output** 📜  

- Refer to the “Log Example” below to verify that Key-Scan initialization and interrupt events are working correctly.

---

### 📝 Log Example

```bash
Log example:
14:45:24.474  ROM:[V1.1]
14:45:24.474  FLASH RATE:1, Pinmux:1
14:45:24.474  IMG1(OTA1) VALID, ret: 0
14:45:24.474  IMG1 ENTRY[f800779:0]
14:45:24.474  [BOOT-I] KM4 BOOT REASON 0: Initial Power on
14:45:24.474  [BOOT-I] KM4 CPU CLK: 240000000 Hz
14:45:24.474  [BOOT-I] KM0 CPU CLK: 96000000 Hz
14:45:24.474  [BOOT-I] PSRAM Ctrl CLK: 240000000 Hz 
14:45:24.474  [BOOT-I] IMG1 ENTER MSP:[30009FDC]
14:45:24.474  [BOOT-I] Build Time: Mar  2 2026 14:41:35
14:45:24.474  [BOOT-I] IMG1 SECURE STATE: 1
14:45:24.490  [FLASH-I] FLASH CLK: 80000000 Hz
14:45:24.490  [FLASH-I] Flash ID: 85-20-16 (Capacity: 32M-bit)
14:45:24.490  [FLASH-I] Flash Read 4IO
14:45:24.490  [FLASH-I] FLASH HandShake[0x2 OK]
14:45:24.490  [BOOT-I] KM0 XIP IMG[0c000000:82c0]
14:45:24.490  [BOOT-I] KM0 SRAM[20068000:860]
14:45:24.490  [BOOT-I] KM0 PSRAM[0c008b20:20]
14:45:24.490  [BOOT-I] KM0 ENTRY[20004d00:60]
14:45:24.490  [BOOT-I] KM4 XIP IMG[0e000000:18800]
14:45:24.490  [BOOT-I] KM4 SRAM[2000b000:480]
14:45:24.490  [BOOT-I] KM4 PSRAM[0e018c80:20]
14:45:24.490  [BOOT-I] KM4 ENTRY[20004d80:40]
14:45:24.490  [BOOT-I] IMG2 BOOT from OTA 1, Version: 1.1 
14:45:24.490  [BOOT-I] Image2Entry @ 0xe007b51 ...
14:45:24.490  [APP-[I] KLOCKM4 APP SS-I] KM0TART 
14:45:24.490  [ init_reAPP-I] Vtarget_lTOR: 30007000, Vocks
14:45:24.490  TOR_NS:30007000
14:45:24.490  [APP-I] VTOR: 30007000, VTOR_NS:30007000
14:45:24.490  [APP-I] IMG2 SECURE STAT[MAIN-IE: 1
14:45:24.490  ] IWDG refresh on!
14:45:24.490  [MAIN-I] K[CM0L KO-IS ] S[TCAARLT4M ]
14:45:24.490  : delta:0 target:320 PPM: 0 PPM_Limit:30000 
14:45:24.506  [CLK-I] [CAL131K]: delta:7 target:2441 PPM: 2867 PPM_Limit:30000 
14:45:24.506  [LOCKS-I] KM4 init_retarget_locks
14:45:24.506  [APP-I] BOR arises when supply voltage decreases under 2.57V and recovers above 2.7V.
14:45:24.506  [MAIN-I] KM4 MAIN 
14:45:24.506  [VER-I] AMEBA-RTOS SDK VERSION: 1.2.0
14:45:24.524  [MAIN-I] File System Init Success 
14:45:24.524  [app_main-I] kscan_regular_scan_raw_thread creat!
14:45:24.524  [MAIN-I] KM4 START SCHEDULER 
14:45:26.605  SWD PAD Port0_Pin31 is configured to funcID SWD PAD Port0_Pin30 is configured to funcID [app_main-I] SCAN_EVENT_INT FIFO Data: 111 
14:45:26.628  [app_main-I] SCAN_EVENT_INT FIFO Data: 111 
14:45:26.637  [app_main-I] SCAN_EVENT_INT FIFO Data: 111 
14:45:26.653  [app_main-I] SCAN_EVENT_INT FIFO Data: 111 
14:45:26.668  [app_main-I] SCAN_EVENT_INT FIFO Data: 111 
14:45:26.684  [app_main-I] SCAN_EVENT_INT FIFO Data: 111 
14:45:26.700  [app_main-I] SCAN_EVENT_INT FIFO Data: 111 
14:45:26.728  [app_main-I] SCAN_EVENT_INT FIFO Data: 111 
14:45:26.731  [app_main-I] SCAN_EVENT_INT FIFO Data: 111 
14:45:26.762  [app_main-I] ALL RELEASE intr
14:45:28.154  [app_main-I] SCAN_EVENT_INT FIFO Data: 122 
14:45:28.169  [app_main-I] SCAN_EVENT_INT FIFO Data: 122 
14:45:28.185  [app_main-I] SCAN_EVENT_INT FIFO Data: 122 
14:45:28.200  [app_main-I] SCAN_EVENT_INT FIFO Data: 122 
14:45:28.216  [app_main-I] SCAN_EVENT_INT FIFO Data: 122 
14:45:28.232  [app_main-I] SCAN_EVENT_INT FIFO Data: 122 
14:45:28.248  [app_main-I] SCAN_EVENT_INT FIFO Data: 122 
14:45:28.263  [app_main-I] SCAN_EVENT_INT FIFO Data: 122 
14:45:28.279  [app_main-I] SCAN_EVENT_INT FIFO Data: 122 
14:45:28.295  [app_main-I] SCAN_EVENT_INT FIFO Data: 122 
14:45:28.331  [app_main-I] ALL RELEASE intr
14:45:29.635  [app_main-I] SCAN_EVENT_INT FIFO Data: 133 
14:45:29.647  [app_main-I] SCAN_EVENT_INT FIFO Data: 133 
14:45:29.662  [app_main-I] SCAN_EVENT_INT FIFO Data: 133 
14:45:29.678  [app_main-I] SCAN_EVENT_INT FIFO Data: 133 
14:45:29.694  [app_main-I] SCAN_EVENT_INT FIFO Data: 133 
14:45:29.709  [app_main-I] SCAN_EVENT_INT FIFO Data: 133 
14:45:29.735  [app_main-I] SCAN_EVENT_INT FIFO Data: 133 
14:45:29.741  [app_main-I] SCAN_EVENT_INT FIFO Data: 133 
14:45:29.772  [app_main-I] ALL RELEASE intr
14:45:30.892  [app_main-I] SCAN_EVENT_INT FIFO Data: 144 
14:45:30.907  [app_main-I] SCAN_EVENT_INT FIFO Data: 144 
14:45:30.923  [app_main-I] SCAN_EVENT_INT FIFO Data: 144 
14:45:30.939  [app_main-I] SCAN_EVENT_INT FIFO Data: 144 
14:45:30.955  [app_main-I] SCAN_EVENT_INT FIFO Data: 144 
14:45:30.970  [app_main-I] SCAN_EVENT_INT FIFO Data: 144 
14:45:30.986  [app_main-I] SCAN_EVENT_INT FIFO Data: 144 
14:45:31.001  [app_main-I] SCAN_EVENT_INT FIFO Data: 144 
14:45:31.017  [app_main-I] SCAN_EVENT_INT FIFO Data: 144 
14:45:31.033  [app_main-I] SCAN_EVENT_INT FIFO Data: 144 
14:45:31.049  [app_main-I] SCAN_EVENT_INT FIFO Data: 144 
14:45:31.064  [app_main-I] ALL RELEASE intr
...

```