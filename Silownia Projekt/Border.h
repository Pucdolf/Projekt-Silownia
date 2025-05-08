#pragma once

#include<iostream>
#include<vector>
#include<string>

/**
 * @class Border
 * @brief Klasa odpowiedzialna za rysowanie obramowania wokó³ elementów menu.
 */
class Border
{
public:
    /**
     * @brief Rysuje obramowanie wokó³ listy tekstów.
     *
     * @param menuItems Lista pozycji menu do oprawienia ramk¹.
     */
    void drawBorder(const std::vector<std::string>& menuItems) const
    {
        size_t maxLength{ 0 };
        for (const auto& item : menuItems)
            maxLength = std::max(maxLength, item.length());

        std::cout << "+";
        for (size_t i = 0; i < maxLength + 2; i++)
            std::cout << "-";
        std::cout << "+\n";

        for (const auto& item : menuItems)
        {
            std::cout << "|" << item;
            for (size_t i = item.length(); i < maxLength; i++)
                std::cout << " ";
            std::cout << " |\n";
        }

        std::cout << "+";
        for (size_t i = 0; i < maxLength + 2; i++)
            std::cout << "-";
        std::cout << "+\n";
    }
};
