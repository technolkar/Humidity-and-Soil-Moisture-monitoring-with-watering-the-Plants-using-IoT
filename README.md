<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:2D6A4F,100:95D5B2&height=200&section=header&text=IoT%20Smart%20Plant%20Monitor&fontSize=42&fontColor=ffffff&desc=Soil%20moisture%20%E2%80%A2%20Humidity%20%E2%80%A2%20Remote%20watering&descAlignY=72&descSize=18&animation=fadeIn" width="100%" alt="IoT Smart Plant Monitor banner"/>

### 🪴 Your plants send you their status — and you water them from your phone.

![ESP8266](https://img.shields.io/badge/NodeMCU%20ESP8266-E7352C?style=for-the-badge&logo=espressif&logoColor=white)
![Blynk](https://img.shields.io/badge/Blynk%20IoT-23C48E?style=for-the-badge)
![C++](https://img.shields.io/badge/Arduino%20C%2B%2B-00599C?style=for-the-badge&logo=arduino&logoColor=white)
![DHT11](https://img.shields.io/badge/DHT11-2D6A4F?style=for-the-badge)

![Year](https://img.shields.io/badge/built-2022-2D6A4F?style=flat-square)

</div>

---

## 📌 At a glance

> A NodeMCU reads **soil moisture**, **temperature** and **humidity** and sends them live to a **Blynk phone dashboard**. The moisture gauge turns **green when the soil is wet and red when it is dry** — and a relay-controlled **water pump** lets you water the plant from anywhere.

<div align="center">
<table>
<tr>
<td align="center" width="50%"><img src="media/plant-monitor-app.jpg" alt="Plant monitor with the phone dashboard"/><br/><sub><b>Prototype</b> with the Blynk dashboard on a phone</sub></td>
<td align="center" width="50%"><img src="IMG_20220326_102206.jpg" alt="Plant monitor setup with relay board, pump and water tanks"/><br/><sub><b>Setup</b> — NodeMCU, relays, pump and water tanks</sub></td>
</tr>
</table>
</div>

---

## ✨ Features

| | |
|---|---|
| 🌡️ **Climate sensing** | Temperature and humidity from a DHT11 |
| 💧 **Soil sensing** | Analog soil-moisture sensor |
| 📱 **Live dashboard** | Values on Blynk virtual pins `V10`, `V11`, `V12` |
| 🟢🔴 **Instant status** | Moisture widget turns green (wet) or red (dry) |
| 🚿 **Remote watering** | Pump switched through a relay from the app |

---

## 🔄 How it works

```mermaid
flowchart LR
    D[DHT11<br/>temp + humidity] --> N[NodeMCU ESP8266]
    S[Soil-moisture sensor] --> N
    N <-->|Wi-Fi| B[(Blynk Cloud)]
    B <--> P[📱 Phone dashboard]
    P -->|water button| B
    N --> R[Relay] --> PU[💧 Water pump]
```

---

## 💻 Code

[`SOIL_AND_HUMIDITY_SENSOR_IOT.ino`](SOIL_AND_HUMIDITY_SENSOR_IOT.ino):

```cpp
void loop() {
  Blynk.run();
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int   m = analogRead(A0);

  Blynk.virtualWrite(V10, h);
  Blynk.virtualWrite(V11, t);
  Blynk.virtualWrite(V12, m);
  Blynk.setProperty(V12, "color", m <= 1000 ? "#00FF00" : "#FF0000");  // wet / dry
}
```

<details>
<summary><b>▶ How to run it</b></summary>

1. Install the **ESP8266 board package**, **Blynk** and **DHT sensor library**
2. Enter **your own** Blynk template ID, auth token and Wi-Fi details
3. Wire the DHT11 to D4 and the soil sensor to A0, then upload
4. Add gauges on `V10`–`V12` and a button for the pump relay in the Blynk app

</details>

---

## 🌱 Related work

The same idea also went into the **Technolkar smart-agriculture display** shown below. Related projects:
the [**offline mesh farm monitor**](https://github.com/technolkar/Mesh-Networking-for-smart-agriculture-system-without-Internet) and the [**solar agriculture robot**](https://github.com/technolkar/Multipurpose-Agriculture-Robot-).

<div align="center">
<img src="IMG_20230106_015226.jpg" width="70%" alt="Technolkar smart agriculture display model"/>
<br/><sub><b>Technolkar Smart Agriculture</b> display model</sub>
</div>

---

<div align="center">

### 👋 Built by **Ajay Arjun Mannolkar**
[![Portfolio](https://img.shields.io/badge/Portfolio-technolkar.github.io-2D6A4F?style=for-the-badge&logo=githubpages&logoColor=white)](https://technolkar.github.io)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-ajaymannolkar-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/ajaymannolkar)
[![YouTube](https://img.shields.io/badge/YouTube-TECHNOL%20KAR-FF0000?style=for-the-badge&logo=youtube&logoColor=white)](https://www.youtube.com/@TechnolkarInnovations)

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:95D5B2,100:2D6A4F&height=100&section=footer" width="100%"/>

</div>
