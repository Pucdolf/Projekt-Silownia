## 🏋️ Gym Project – Console System for Management and Analysis of Gym Member Data

**Gym Project** is an advanced console application designed for tracking gym members and performing detailed analysis of their training and health parameters. This project was developed as part of the *Computer Programming* course at the Silesian University of Technology.

---

### 🕹️ Preview / Gallery

<p align="center">
  <img src="https://github.com/user-attachments/assets/aea22851-8c8d-419c-9928-17c7e30a3db3" width="700" alt="Gym Project application demo">
</p>

---

### 📂 Project Structure and Features

The project is written in **C++** using the **Standard Template Library (STL)**. Main application modules:

* `GymMember` – A class representing a gym member, storing parameters such as age, weight, BMI, or BPM, and containing logic for parsing data from CSV format.
* `CSVReader` – A module responsible for streaming data from text files (.csv) and converting them into `GymMember` objects.
* `MainMenu` – The main application controller managing the user interface, data validation, and implementing business logic (statistics, sorting, list management).
* `Border` – A utility class used for aesthetic rendering of menu borders in the console window.
* `raport.txt` – A reporting module that automatically logs every change in the member database (additions/removals).

**Key Features:**
- Loading and saving data to CSV files.
- Statistical analysis of average BPM for different types of workouts.
- Calculating Spearman correlation between exercise frequency and BMI.
- Sorting the database by age, BMI, or training frequency.

---

### 🎨 Resources and License
* This is an open-source project with public source code, created for educational purposes. It utilizes standard C++ libraries and Windows system functions for console handling.

---

### 🛠️ Requirements

* C++17 standard or newer
* Compiler supporting MSVC standards (Visual Studio 2019/2022 recommended)
* OS: Windows (uses `<conio.h>` library and system screen clearing)
* Environment: Visual Studio with "Desktop development with C++" workload

---

## 🚀 Compilation and Running

To develop the project or analyze the code, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/Pucdolf/Projekt-Silownia.git
   ```
2. Open the `Silownia Projekt.sln` file in Visual Studio.
3. Ensure that the `gym_members_exercise_tracking.csv` file is located in the project's working directory.
4. Compile and run the project (F5).
