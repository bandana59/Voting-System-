# Voting-System-

# 🗳️ Voting System in C

A simple yet effective console-based **Voting System** built in C! 💻  
Vote, search, view results, and keep your data persistent with file storage.  
Perfect for beginners learning C file handling, structures, and menu-driven programs!

---

## 📌 Features

✅ Add new candidates  
✅ Search candidate by name  
✅ Cast votes to your favorite one  
✅ View real-time voting results  
✅ Save and load data from a file (`candidates.txt`)  
✅ Initializes with default candidates if no data is found

---

## 🛠️ Tech Stack

- **Language**: C
- **Concepts Used**:  
  - File I/O (`fopen`, `fscanf`, `fprintf`)  
  - Structures  
  - Strings (`fgets`, `strcmp`, `strcpy`)  
  - Dynamic Menus & Loops  

---

## 🧠 How It Works

1. 📂 Loads data from a file on start
2. ❌ If file is empty, it adds default candidates (`Sandhya`, `Bandana`, `Neha`, `Priyanka`)
3. 🎮 Menu-based system for user interaction:
   - Add candidates
   - Search them
   - Vote for them
   - View total votes
4. 💾 Data gets saved to file on exit so nothing is lost

---

## 📷 Demo Screenshot

> _Insert a terminal screenshot here if you want!_

---

## 🚀 How to Run

1. **Clone this repo**  
   ```bash
   git clone https://github.com/yourusername/voting-system-c.git
   cd voting-system-c
