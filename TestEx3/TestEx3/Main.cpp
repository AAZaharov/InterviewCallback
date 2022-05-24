#include <iostream>
#include <string>
#include <regex>

//
//Выведете конечные координаты устройства после выполнения комманд GCODE.
//

struct Point
{
    float x, y, z;
};

int main()
{
    std::cmatch result;
    std::regex regular("(X)?(-)?([0-9]*);?(Y)?(-)?([0-9]*);?(Z)?(-)?([0-9]*);?");
    std::regex exception("[<>!@#$%^&*()!%:?*]+");

    Point P{};
    std::string str;

    std::cout << "Enter coordinate of the point: ";
    std::cin >> P.x;
    std::cin >> P.y;
    std::cin >> P.z;


    while (1) {

        std::getline(std::cin, str);

        if (std::regex_search(str.c_str(), result, exception)) {
            std::cout << "\nERROR SCRIPT";
            break;
        }


        std::regex_match(str.c_str(), result, regular);
        for (int i = 0; i < result.size(); ++i) {

            if (result[i] == "X")
            {
                if (result[i + 1] == "-") {
                    P.x -= std::stoi(result[i + 2]);
                }
                else {
                    P.x += std::stoi(result[i + 2]);
                }
            }

            if (result[i] == "Y")
            {
                if (result[i + 1] == "-") {
                    P.y -= std::stoi(result[i + 2]);
                }
                else {
                    P.y += std::stoi(result[i + 2]);
                }
            }

            if (result[i] == "Z")
            {
                if (result[i + 1] == "-") {
                    P.z -= std::stoi(result[i + 2]);
                }
                else {
                    P.z += std::stoi(result[i + 2]);
                }
            }
        }

        std::cout << "\nP1 coord (" << P.x << "'" << P.y << "'" << P.z << ")\n";
    }

    return 0;
}
