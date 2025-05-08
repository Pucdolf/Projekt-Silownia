#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cmath>

/**
 * @class GymMember
 * @brief Reprezentuje jednego cz³onka si³owni z jego parametrami treningowymi.
 */
class GymMember
{
private:
    int age;
    std::string gender;
    double weight;
    double height;
    double maxBPM;
    double avgBPM;
    double restingBPM;
    double sessionDuration;
    double caloriesBurned;
    std::string workoutType;
    double fatPercentage;
    double waterIntake;
    int workoutFrequency;
    int experienceLevel;
    double BMI;

public:
    /// Konstruktor domyœlny
    GymMember() = default;

    /**
     * @brief Konstruktor inicjalizuj¹cy wszystkie pola.
     */
    GymMember(int age, const std::string& gender, double weight, double height, double maxBPM, double avgBPM, double restingBPM,
        double sessionDuration, double caloriesBurned, const std::string& workoutType, double fatPercentage, double waterIntake,
        int workoutFrequency, int experienceLevel, double BMI)
        : age(age), gender(gender), weight(weight), height(height), maxBPM(maxBPM), avgBPM(avgBPM), restingBPM(restingBPM),
        sessionDuration(sessionDuration), caloriesBurned(caloriesBurned), workoutType(workoutType), fatPercentage(fatPercentage),
        waterIntake(waterIntake), workoutFrequency(workoutFrequency), experienceLevel(experienceLevel), BMI(BMI) {
    }

    /// Gettery pól danych
    int getAge() const { return age; }
    std::string getGender() const { return gender; }
    double getWeight() const { return weight; }
    double getHeight() const { return height; }
    double getMaxBPM() const { return maxBPM; }
    double getAvgBPM() const { return avgBPM; }
    double getRestingBPM() const { return restingBPM; }
    double getSessionDuration() const { return sessionDuration; }
    double getCaloriesBurned() const { return caloriesBurned; }
    std::string getWorkoutType() const { return workoutType; }
    double getFatPercentage() const { return fatPercentage; }
    double getWaterIntake() const { return waterIntake; }
    int getWorkoutFrequency() const { return workoutFrequency; }
    int getExperienceLevel() const { return experienceLevel; }
    double getBMI() const { return BMI; }

    /**
     * @brief Parsuje liniê z pliku CSV do obiektu GymMember.
     *
     * @param csvLine Linia z danymi rozdzielanymi przecinkami.
     * @return GymMember Sparsowany obiekt.
     */
    static GymMember fromCSV(const std::string& csvLine)
    {
        std::istringstream stream(csvLine);
        std::string token;

        int age;
        std::string gender;
        double weight, height, maxBPM, avgBPM, restingBPM, sessionDuration, caloriesBurned, fatPercentage, waterIntake, BMI;
        std::string workoutType;
        int workoutFrequency, experienceLevel;

        std::getline(stream, token, ',');
        age = std::stoi(token);

        std::getline(stream, gender, ',');

        std::getline(stream, token, ',');
        weight = std::stod(token);

        std::getline(stream, token, ',');
        height = std::stod(token);

        std::getline(stream, token, ',');
        maxBPM = std::stod(token);

        std::getline(stream, token, ',');
        avgBPM = std::stod(token);

        std::getline(stream, token, ',');
        restingBPM = std::stod(token);

        std::getline(stream, token, ',');
        sessionDuration = std::stod(token);

        std::getline(stream, token, ',');
        caloriesBurned = std::stod(token);

        std::getline(stream, workoutType, ',');

        std::getline(stream, token, ',');
        fatPercentage = std::stod(token);

        std::getline(stream, token, ',');
        waterIntake = std::stod(token);

        std::getline(stream, token, ',');
        workoutFrequency = std::stoi(token);

        std::getline(stream, token, ',');
        experienceLevel = std::stoi(token);

        std::getline(stream, token, ',');
        BMI = std::stod(token);

        return GymMember(age, gender, weight, height, maxBPM, avgBPM, restingBPM, sessionDuration, caloriesBurned, workoutType,
            fatPercentage, waterIntake, workoutFrequency, experienceLevel, BMI);
    }
};
