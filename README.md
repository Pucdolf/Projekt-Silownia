## 🏋️ Silownia Projekt – Konsolowy system zarządzania i analizy danych członków siłowni

**Silownia Projekt** to zaawansowana aplikacja konsolowa służąca do ewidencjonowania członków siłowni oraz szczegółowej analizy ich parametrów treningowych i zdrowotnych. Projekt został zrealizowany jako część kursu *Programowanie Komputerów* na Politechnice Śląskiej.

---

### 🕹️ Podgląd / Galeria

<p align="center">
  <img src="https://github.com/user-attachments/assets/aea22851-8c8d-419c-9928-17c7e30a3db3" width="700" alt="Prezentacja działania programu Silownia Projekt">
</p>

---

### 📂 Struktura projektu i Funkcjonalności

Projekt został napisany w **C++** z użyciem **Standard Template Library (STL)**. Główne moduły aplikacji:

* `GymMember` – Klasa reprezentująca członka siłowni, przechowująca parametry takie jak wiek, waga, BMI czy BPM oraz zawierająca logikę parsowania danych z formatu CSV.
* `CSVReader` – Moduł odpowiedzialny za strumieniowe wczytywanie danych z plików tekstowych (.csv) i ich konwersję na obiekty klasy `GymMember`.
* `MainMenu` – Główny kontroler aplikacji zarządzający interfejsem użytkownika, walidacją danych oraz implementujący logikę biznesową (statystyki, sortowanie, zarządzanie listą).
* `Border` – Klasa pomocnicza służąca do estetycznego renderowania obramowań menu w oknie konsoli.
* `raport.txt` – Moduł raportowania, który automatycznie loguje każdą zmianę w bazie członków (dodanie/usunięcie).

**Kluczowe funkcjonalności:**
- Wczytywanie i zapisywanie danych do plików CSV.
- Analiza statystyczna średniego BPM dla różnych typów treningów.
- Obliczanie korelacji Spearmana między częstotliwością ćwiczeń a współczynnikiem BMI.
- Sortowanie bazy danych według wieku, BMI lub częstotliwości treningów.

---

### 🎨 Zasoby i Licencja
* Jest to projekt typu open-source z otwartym kodem źródłowym, stworzony w celach edukacyjnych. Wykorzystuje standardowe biblioteki C++ oraz systemowe funkcje Windows do obsługi konsoli.

---

### 🛠️ Wymagania

* Standard języka C++17 lub nowszy
* Kompilator wspierający standardy MSVC (zalecany Visual Studio 2019/2022)
* System: Windows (wykorzystuje bibliotekę `<conio.h>` oraz systemowe czyszczenie ekranu)
* Środowisko: Visual Studio z nakładką "Desktop development with C++"

---

## 🚀 Kompilacja i uruchamianie

Jeśli chcesz rozwijać projekt lub analizować kod, wykonaj poniższe kroki:

1. Sklonuj repozytorium:
   ```bash
   git clone https://github.com/Pucdolf/Projekt-Silownia.git
   ```
2. Otwórz plik `Silownia Projekt.sln` w środowisku Visual Studio.
3. Upewnij się, że plik `gym_members_exercise_tracking.csv` znajduje się w katalogu roboczym projektu.
4. Skompiluj i uruchom projekt (F5).
