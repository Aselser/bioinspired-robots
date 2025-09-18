# Bioinspired Robots (Arduino)

This repository contains Arduino implementations of **bioinspired robotic behaviors** inspired by Braitenberg vehicles.  
The project demonstrates how simple sensor-motor couplings generate lifelike behaviors.
  [Demo Video](https://youtu.be/zCdSMHul44c)

## 📖 Behaviors Explained + video
- **Shy Robot** – Moves forward, slows down when objects are closer than 70 cm, and stops before 30 cm.  

- **Explorer Robot** – Moves forward, stops when detecting obstacles closer than 30 cm, and turns on its axis before continuing.  
  
- **Offended Robot** – Turns away from objects at 30 cm and refuses to continue exploring. Once offended, it remains in place.  
 
- **Aggressive Robot** – Moves calmly until detecting an object at 70 cm, then accelerates abruptly for 2 seconds before stopping.  

- **Light-Follower (Curious) Robot** – Uses photoresistors to follow light sources relative to a calibrated baseline, while still avoiding obstacles.  

- **Adolescent Robot (3 States)** – Cycles between explorer, offended, and aggressive every 20–30 seconds. LEDs indicate the state.  

- **Robotic Eye** – Built with a 3D-printed structure and two servos for eyelid and eyeball motion, with smooth sweeper control.  

## 🛠️ Hardware Used
- Arduino UNO / MEGA  
- Ultrasonic sensor HC-SR04  
- Photoresistors (LDRs)  
- LEDs  
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
1. Open the `.ino` file in Arduino IDE.  
2. Connect the hardware as described in the code comments.  
3. Upload to the Arduino board.  
4. Place the robot and observe the behavior.  

## 📜 License
MIT License – free to use, modify, and distribute.
