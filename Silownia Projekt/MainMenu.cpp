#include "MainMenu.h"

#include<iostream>
#include<vector>
#include<string>
#include<conio.h>
#include<iomanip>
#include<map>
#include<algorithm>
#include<numeric>


MainMenu::MainMenu()
{
	try {
		std::string filename = { "gym_members_exercise_tracking.csv" };
		members = CSVReader::readFromCSV(filename);
		std::cout << "Dane zostaly pomyslnie wczytane z pliku." << std::endl;
		_getch();
		system("cls");
	}
	catch (const std::exception& e) {
		std::cerr << "Blad podczas wczytywania danych:" << e.what() << std::endl;
		_getch();
		system("cls");

	}
}

bool MainMenu::error(int choice, const std::string error_msg, int size)
{
	if (choice > size or choice < 1 or std::cin.rdstate())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		system("cls");
		std::cout << error_msg << std::endl;
		_getch();
		system("cls");
		return false;
	}
	return true;
}


void MainMenu::displayMenu()
{
	system("cls");

	std::vector<std::string> mainMenuItems{
		"--Main Menu--",
		"1. Wyswietl wszystkich czlonkow",
		"2. Sortuj dane",
		"3. Analiza danych",
		"4. Korelacja Spearmana",
		"5. Dodaj nowego czlonka",
		"6. Usun czlonka",
		"7. Zakoncz program"
	};

	int choice;
	/*std::string filename{ "gym_members_exercise_tracking.csv" };
	members = CSVReader::readFromCSV(filename);*/

	do {
		drawBorder(mainMenuItems);
		std::cout << "Wybierz opcje [1-7]:";
		std::cin >> choice;


		switch (choice) {
		case 1:
			displayAllMembers();
			displayMenu();
			break;
		case 2:
			sortData();
			displayMenu();
			break;
		case 3:
			WorkoutTypeAvgBPM();
			displayMenu();
			break;
		case 4:
			calculateSpearmanCorrelation();
			displayMenu();
			break;
		case 5:
			addNewMember();
			displayMenu();
			break;
		case 6:
			removeMember();
			displayMenu();
			break;
		case 7:
			std::cout << "Zamknieto program..." << std::endl;
			exit(0);
		}

	} while (!error(choice, "Blad! By wybrac ponownie nacisnij dowonly klawisz.", mainMenuItems.size() - 1));
}

//1
void MainMenu::displayAllMembers()
{
	system("cls");

	if (members.empty()) {
		std::cout << "Brak danych do wyswietlenia." << std::endl;
		_getch();
		system("cls");
		return;
	}

	std::cout << std::left
		<< std::setw(8) << "Index"
		<< std::setw(5) << "Age"
		<< std::setw(10) << "Gender"
		<< std::setw(12) << "Weight(kg)"
		<< std::setw(12) << "Height(m)"
		<< std::setw(10) << "Max BPM"
		<< std::setw(10) << "Avg BPM"
		<< std::setw(12) << "Resting BPM"
		<< std::setw(12) << "Session(h)"
		<< std::setw(15) << "Calories"
		<< std::setw(15) << "Workout"
		<< std::setw(12) << "Fat %"
		<< std::setw(12) << "Water(L)"
		<< std::setw(15) << "Freq(days)"
		<< std::setw(12) << "Exp Level"
		<< std::setw(10) << "BMI" << std::endl;


	std::cout << std::string(175, '-') << std::endl;

	int index = 1;
	for (const auto& member : members) {
		std::cout << std::left
			<< std::setw(8) << index++
			<< std::setw(5) << member.getAge()
			<< std::setw(10) << member.getGender()
			<< std::setw(12) << member.getWeight()
			<< std::setw(12) << member.getHeight()
			<< std::setw(10) << member.getMaxBPM()
			<< std::setw(10) << member.getAvgBPM()
			<< std::setw(12) << member.getRestingBPM()
			<< std::setw(12) << member.getSessionDuration()
			<< std::setw(15) << member.getCaloriesBurned()
			<< std::setw(15) << member.getWorkoutType()
			<< std::setw(12) << member.getFatPercentage()
			<< std::setw(12) << member.getWaterIntake()
			<< std::setw(15) << member.getWorkoutFrequency()
			<< std::setw(12) << member.getExperienceLevel()
			<< std::setw(10) << member.getBMI() << std::endl;
	}

	_getch();
	system("cls");
}


//2
void MainMenu::sortData() {

	system("cls");

	if (members.empty()) {
		std::cout << "Brak danych do sortowania." << std::endl;
		_getch();
		system("cls");
		return;
	}

	std::vector<std::string> sortMenuItems{
		"Sortuj wedlug:",
		"1. Wiek",
		"2. BMI",
		"3. Czestotliwosc treningow",
		"4. Wroc"
	};
	int choice;


	do {
		drawBorder(sortMenuItems);
		std::cout << "Wybierz opcje [1-4]:";
		std::cin >> choice;
	} while (!error(choice, "Blad! By wybrac ponownie nacisnij dowonly klawisz.", sortMenuItems.size() - 1));

	switch (choice)
	{
	case 1:
		std::sort(members.begin(), members.end(), [](const GymMember& a, const GymMember& b) {
			return a.getAge() < b.getAge();
			});
		std::cout << "Dane zostaly posortowane wedlug wieku.";
		break;

	case 2:
		std::sort(members.begin(), members.end(), [](const GymMember& a, const GymMember& b) {
			return a.getBMI() < b.getBMI();
			});
		std::cout << "Dane zostaly posortowane wedlug BMI.";
		break;

	case 3:
		std::sort(members.begin(), members.end(), [](const GymMember& a, const GymMember& b) {
			return a.getWorkoutFrequency() < b.getWorkoutFrequency();
			});
		std::cout << "Dane zostaly posortowane wedlug czestotliwosci treningow.";
		break;
	case 4:
		displayMenu();
		break;
	}

	_getch();
	system("cls");
}

//3
void MainMenu::WorkoutTypeAvgBPM()
{
	system("cls");

	if (members.empty()) {
		std::cout << "Brak danych do analizy." << std::endl;
		_getch();
		system("cls");
		return;
	}

	std::map<std::string, std::pair<double, int>> bpmData;

	for (const auto& member : members)
	{
		const std::string& workoutType = member.getWorkoutType();
		bpmData[workoutType].first += member.getAvgBPM();
		bpmData[workoutType].second++;
	}

	std::cout << std::left << std::setw(20) << "Workout Type: "
		<< std::setw(15) << "Average BPM " << std::endl;
	std::cout << std::string(35, '-') << std::endl;

	for (const auto& [workoutType, data] : bpmData) {
		double averageBPM = data.first / data.second;
		std::cout << std::left << std::setw(20) << workoutType
			<< std::setw(15) << averageBPM << std::endl;
	}
	_getch();
	system("cls");

}

//4
void MainMenu::calculateSpearmanCorrelation()
{
	system("cls");

	std::cout << "Korelacja Spearmana jest miara zaleznosci pomiedzy dwoma zmiennymi.\n"
		<< "Przyjmuje wartosci od -1 do 1, gdzie:\n"
		<< " - 1 oznacza idealna dodatnia zaleznosc (im wieksza jedna zmienna, tym wieksza druga),\n"
		<< " - -1 oznacza idealna ujemna zaleznosc (im wieksza jedna zmienna, tym mniejsza druga),\n"
		<< " - 0 oznacza brak zaleznosci.\n\n"
		<< "W tym przypadku analizujemy zaleznosc pomiedzy czestotliwoscia cwiczen (Workout_Frequency)\n"
		<< "a wskaznikiem masy ciala (BMI).\n\n";

	if (members.empty()) {
		std::cout << "Brak danych do analizy." << std::endl;
		_getch();
		system("cls");
		return;
	}

	std::vector<std::pair<int, double>> data;
	for (const auto& member : members) {
		data.emplace_back(member.getWorkoutFrequency(), member.getBMI());
	}

	auto calculateRanks = [](const std::vector<double>& values) {
		std::vector<std::pair<double, size_t>> indexedValues;
		for (size_t i = 0; i < values.size(); ++i) {
			indexedValues.emplace_back(values[i], i);
		}
		std::sort(indexedValues.begin(), indexedValues.end());

		std::vector<double> ranks(values.size());
		for (size_t i = 0; i < indexedValues.size(); ++i) {
			ranks[indexedValues[i].second] = i + 1;
		}
		return ranks;
		};


	std::vector<double> workoutFrequencies, bmis;
	for (const auto& [frequency, bmi] : data) {
		workoutFrequencies.push_back(frequency);
		bmis.push_back(bmi);
	}

	std::vector<double> ranksWorkout = calculateRanks(workoutFrequencies);
	std::vector<double> ranksBMI = calculateRanks(bmis);


	std::vector<double> rankDifferences(ranksWorkout.size());
	for (size_t i = 0; i < ranksWorkout.size(); ++i) {
		rankDifferences[i] = ranksWorkout[i] - ranksBMI[i];
	}
	std::vector<double> rankDifferencesSquared(rankDifferences.size());
	std::transform(rankDifferences.begin(), rankDifferences.end(), rankDifferencesSquared.begin(),
		[](double d) { return d * d; });


	size_t n = data.size();
	double numerator = 6 * std::accumulate(rankDifferencesSquared.begin(), rankDifferencesSquared.end(), 0.0);
	double denominator = n * (n * n - 1);
	double spearmanCorrelation = 1 - (numerator / denominator);

	std::cout << "Korelacja Spearmana pomiedzy Workout_Frequency a BMI wynosi: " << spearmanCorrelation << std::endl;

	_getch();
	system("cls");
}

//5
void MainMenu::addNewMember()
{
	system("cls");

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

	int choice;

	std::vector<std::string> menuItems{
		"--Menu--",
		"1. Dodaj czlonka",
		"2. Wroc",
	};

	do {
		drawBorder(menuItems);
		std::cout << "Wybierz opcje [1-2]:";
		std::cin >> choice;
	} while (!error(choice, "Blad! By wybrac ponownie nacisnij dowonly klawisz.", menuItems.size() - 1));

	auto add = [&]() {
		system("cls");
		do {
			std::cout << "Podaj wiek: ";
			std::cin >> age;
		} while (age <= 0 or age >= 120);

		do {
			std::cout << "Podaj plec (Male/Female): ";
			std::cin >> gender;
		} while (gender != "Male" and gender != "Female");

		do {
			std::cout << "Podaj wage (kg): ";
			std::cin >> weight;
		} while (weight <= 0);

		do {
			std::cout << "Podaj wzrost (m): ";
			std::cin >> height;
		} while (height <= 0);

		do {
			std::cout << "Podaj maksymalne BPM: ";
			std::cin >> maxBPM;
		} while (maxBPM <= 0);

		do {
			std::cout << "Podaj srednie BPM: ";
			std::cin >> avgBPM;
		} while (avgBPM <= 0);

		do {
			std::cout << "Podaj BPM w spoczynku: ";
			std::cin >> restingBPM;
		} while (restingBPM <= 0);

		do {
			std::cout << "Podaj czas trwania sesji (godziny): ";
			std::cin >> sessionDuration;
		} while (sessionDuration <= 0);

		do {
			std::cout << "Podaj liczbe spalonych kalorii: ";
			std::cin >> caloriesBurned;
		} while (caloriesBurned <= 0);

		std::cout << "Podaj typ cwiczenia (np. Cardio, Strength): ";
		std::cin >> workoutType;

		do {
			std::cout << "Podaj procent tkanki tluszczowej: ";
			std::cin >> fatPercentage;
		} while (fatPercentage <= 0);

		do {
			std::cout << "Podaj ilosc spozywanej wody (litry): ";
			std::cin >> waterIntake;
		} while (waterIntake <= 0 or waterIntake >= 5);

		do {
			std::cout << "Podaj czestotliwosc treningow (dni/tydzien): ";
			std::cin >> workoutFrequency;
		} while (workoutFrequency <= 0 or workoutFrequency >= 8);

		do {
			std::cout << "Podaj poziom doswiadczenia (1-10): ";
			std::cin >> experienceLevel;
		} while (experienceLevel <= 0 or experienceLevel >= 11);

		do {
			std::cout << "Podaj poziom BMI: ";
			std::cin >> BMI;
		} while (BMI <= 0);

		GymMember newMember(age, gender, weight, height, maxBPM, avgBPM, restingBPM, sessionDuration, caloriesBurned,
			workoutType, fatPercentage, waterIntake, workoutFrequency, experienceLevel, BMI);

		members.push_back(newMember);

		std::ofstream reportFile("raport.txt", std::ios::app);
		if (reportFile.is_open()) {
			reportFile << "Dodano czlonka: "
				<< newMember.getAge() << " "
				<< newMember.getGender() << " "
				<< newMember.getWeight() << " "
				<< newMember.getHeight() << " "
				<< newMember.getMaxBPM() << " "
				<< newMember.getAvgBPM() << " "
				<< newMember.getRestingBPM() << " "
				<< newMember.getSessionDuration() << " "
				<< newMember.getCaloriesBurned() << " "
				<< newMember.getWorkoutType() << " "
				<< newMember.getFatPercentage() << " "
				<< newMember.getWaterIntake() << " "
				<< newMember.getWorkoutFrequency() << " "
				<< newMember.getExperienceLevel() << " "
				<< newMember.getBMI() << "\n";
			reportFile.close();
		}
		else {
			std::cerr << "Blad: Nie mozna otworzyc pliku raportu.\n";
		}

		std::ofstream file("gym_members_exercise_tracking.csv", std::ios::app);
		if (file.is_open()) {
			file << age << "," << gender << "," << weight << "," << height << "," << maxBPM << ","
				<< avgBPM << "," << restingBPM << "," << sessionDuration << "," << caloriesBurned << ","
				<< workoutType << "," << fatPercentage << "," << waterIntake << "," << workoutFrequency << ","
				<< experienceLevel << "," << BMI << "\n";
			file.close();
		}
		else
			std::cerr << "Blad: Nie mozna otworzyc pliku CSV do zapisu.\n";


		std::cout << "Czlonek zostal dodany i plik CSV zaktualizowany.\n";
		_getch();
		displayMenu();

		};

	switch (choice)
	{
	case 1:
		add();
		break;
	case 2:
		displayMenu();
		break;
	}
}

//6
void MainMenu::removeMember()
{
	system("cls");

	if (members.empty())
	{
		std::cout << "Brak czlonkow do usuniecia. \n";
		_getch();
		return;
	}

	int choice;

	std::vector<std::string> menuItems{
		"--Menu--",
		"1. Usun czlonka",
		"2. Wroc",
	};

	do {
		drawBorder(menuItems);
		std::cout << "Wybierz opcje [1-2]:";
		std::cin >> choice;
	} while (!error(choice, "Blad! By wybrac ponownie nacisnij dowonly klawisz.", menuItems.size() - 1));

	auto remove = [&]() {

		int index;
		do {
			std::cout << "Podaj indeks czlonka do usuniecia (1-" << members.size() << "): ";
			std::cin >> index;

		} while (index <1 or index >static_cast<int>(members.size()));

		const auto& removedMember = members[index - 1];

		std::ofstream reportFile("raport.txt", std::ios::app);
		if (reportFile.is_open())
		{
			reportFile << "Usunieto czlonka: "
				<< removedMember.getAge() << " "
				<< removedMember.getGender() << " "
				<< removedMember.getWeight() << " "
				<< removedMember.getHeight() << " "
				<< removedMember.getMaxBPM() << " "
				<< removedMember.getAvgBPM() << " "
				<< removedMember.getRestingBPM() << " "
				<< removedMember.getSessionDuration() << " "
				<< removedMember.getCaloriesBurned() << " "
				<< removedMember.getWorkoutType() << " "
				<< removedMember.getFatPercentage() << " "
				<< removedMember.getWaterIntake() << " "
				<< removedMember.getWorkoutFrequency() << " "
				<< removedMember.getExperienceLevel() << " "
				<< removedMember.getBMI() << "\n";
			reportFile.close();
		}
		else
			std::cout << "Blad: Nie mozna otworzyc pliku raportu.\n";

		members.erase(members.begin() + (index - 1));

		std::ofstream file("gym_members_exercise_tracking.csv");
		if (file.is_open())
		{
			for (const auto& member : members) {
				file << member.getAge() << "," << member.getGender() << "," << member.getWeight() << ","
					<< member.getHeight() << "," << member.getMaxBPM() << "," << member.getAvgBPM() << ","
					<< member.getRestingBPM() << "," << member.getSessionDuration() << "," << member.getCaloriesBurned() << ","
					<< member.getWorkoutType() << "," << member.getFatPercentage() << "," << member.getWaterIntake() << ","
					<< member.getWorkoutFrequency() << "," << member.getExperienceLevel() << "," << member.getBMI() << "\n";
			}
			file.close();
			std::cout << "Czlonek zostal usuniety i plik CSV zaktualizowany.\n";
		}
		else
			std::cerr << "Blad: Nie mozna otworzyc pliku CSV do zapisu.\n";
		_getch();
		displayMenu();
		};

	switch (choice)
	{
	case 1:
		remove();
		break;
	case 2:
		displayMenu();
		break;
	}
}
