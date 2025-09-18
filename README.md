# Bioinspired Robots (Arduino)

This repository contains Arduino implementations of **bioinspired robotic behaviors** inspired by Braitenberg vehicles.  
The project demonstrates how simple sensor-motor couplings generate lifelike behaviors.

## 📌 Features
- **Shy Robot** – slows down and stops as objects approach
- **Explorer Robot** – avoids obstacles and keeps moving
- **Offended Robot** – turns away and refuses to face objects
- **Aggressive Robot** – charges forward toward detected objects
- **Light-Follower (Curious)** – follows light sources while avoiding obstacles
- **Adolescent Robot** – cycles between explorer, offended, and aggressive states

## 🛠️ Hardware Used
- Arduino UNO / MEGA
- Ultrasonic sensor HC-SR04
- Photoresistors (LDRs)
- LEDs (status indicators)
- Servo motors
- DC motors and motor driver

## 📂 Folder Structure
```
bioinspired-robots/
├── braitenberg/
│   ├── shy/
│   ├── explorer/
│   ├── offended/
│   ├── aggressive/
│   ├── light_follower/
│   └── adolescent/
├── lib/
│   └── distance_utils.h
└── README.md
```

## ▶️ Usage
1. Open the `.ino` file in **Arduino IDE**.
2. Wire the circuit according to the code comments.
3. Upload to your Arduino board.
4. Place the robot and observe its behavior.

## 📹 Demo
- [Shy Robot Demo](#)
- [Explorer Robot Demo](#)

## 📜 License
MIT License – free to use, modify, and distribute.
