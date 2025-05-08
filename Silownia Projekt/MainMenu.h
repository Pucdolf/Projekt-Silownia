#pragma once

#include"Border.h"
#include"GymMember.h"
#include"CSVReader.h"

/**
 * @class MainMenu
 * @brief Klasa zarz¹dzaj¹ca g³ównym menu aplikacji oraz operacjami na danych cz³onków si³owni.
 */
class MainMenu : public Border
{
    std::vector<GymMember> members;

public:
    /// Konstruktor – wczytuje dane z pliku CSV
    MainMenu();

    /**
     * @brief Wyœwietla g³ówne menu u¿ytkownika i obs³uguje wybory.
     */
    void displayMenu();

    /**
     * @brief Waliduje wybór u¿ytkownika z menu.
     *
     * @param choice Wybrana opcja.
     * @param error_msg Komunikat b³êdu do wyœwietlenia.
     * @param size Liczba dostêpnych opcji.
     * @return true jeœli poprawny wybór, false jeœli b³êdny.
     */
    bool error(int choice, const std::string error_msg, int size);

    /// Wyœwietla tabelê wszystkich cz³onków
    void displayAllMembers();

    /// Analizuje œrednie BPM wzglêdem rodzaju æwiczenia
    void WorkoutTypeAvgBPM();

    /// Sortuje dane wed³ug wybranej kolumny
    void sortData();

    /// Dodaje nowego cz³onka do listy i pliku CSV
    void addNewMember();

    /// Usuwa cz³onka z listy oraz pliku CSV
    void removeMember();

    /// Oblicza wspó³czynnik korelacji Spearmana miêdzy czêstotliwoœci¹ æwiczeñ a BMI
    void calculateSpearmanCorrelation();
};
