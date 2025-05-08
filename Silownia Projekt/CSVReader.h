#pragma once

#include"GymMember.h"
#include<vector>
#include<fstream>

/**
 * @class CSVReader
 * @brief Klasa pomocnicza do wczytywania danych cz³onków si³owni z pliku CSV.
 */
class CSVReader
{
public:
    /**
     * @brief Wczytuje dane z pliku CSV i tworzy obiekty GymMember.
     *
     * @param filename Nazwa pliku CSV do odczytu.
     * @return std::vector<GymMember> Lista wczytanych cz³onków.
     */
    static std::vector<GymMember> readFromCSV(const std::string& filename)
    {
        std::vector<GymMember> members;
        std::ifstream in(filename);

        if (!in.is_open()) {
            throw std::runtime_error("Nie mozna otworzyc pliku" + filename);
        }

        std::string line;
        std::getline(in, line); // pominiêcie nag³ówka

        while (std::getline(in, line))
        {
            try {
                GymMember member = GymMember::fromCSV(line);
                members.push_back(member);
            }
            catch (const std::exception& e) {
                std::cerr << "Blad podczas przetwarzania linii. Szczegoly: " << e.what() << std::endl;
            }
        }

        in.close();
        return members;
    }
};
