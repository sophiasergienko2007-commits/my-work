#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <cmath> 

using namespace std::chrono_literals;

// --- ANSI Escape Codes для кольору ---
// КОЛІР ДЛЯ МОЗАЇКИ: Персиковий/Блідо-Оранжевий (ANSI 256 Code: 216)
const std::string ANSI_COLOR_ART = "\033[38;5;216m"; 
// КОЛІР ДЛЯ ТЕКСТУ ПІСНІ: Бірюзовий (Cyan)
const std::string ANSI_COLOR_TEXT = "\033[36m";
// Код для скидання кольору до стандартного
const std::string ANSI_COLOR_RESET = "\033[0m";

void sleep_seconds(double seconds) {
    auto duration = std::chrono::milliseconds(static_cast<long long>(std::round(seconds * 1000)));
    std::this_thread::sleep_for(duration);
}

// --- ВАШ ASCII-АРТ ВСТАВЛЕНО СЮДИ ---
// (Вміст ASCII_ART залишається незмінним)
const std::string ASCII_ART = R"RAW(
##B5P##B&B#B@B#BB&&#B&B##&GB##&BG5PGJ7~7?Y#GB#@@PJPG&@&@@&#GYYBB&#BGP5G#B#&
B#BYP##B&B#B@B#BB&#BB&B##&GB&B#B###BJJ7!~~JPP5P?7YB&&@&@@&#B#B##&@@#BBGGGG#
B#BYP##B&B#B@B#BB&#BB&B##&GB##&###BBJJJYJ~^77~JPPYG@@@&@&##PBB#&&@@&B##G55G
B#BYP##G&G#B@G#GG&#BB#GB#&BB&BBB##B&P?7Y5?~~~!?Y#&&&@&@@#GP5PBB##&B&B#&BGPB
B#BYP#BG&G#B@G#GG&#BB&GBB@BPP5YY5P#B5YPGB5J?7??JG@@@@&@@&PPPPPG#&&G####&&@@
#&BYP#BG&G#G@B#BB&#B#&BBB&5YGGGP5YBBBPPBP5J7J?7?PGB&@@&&&&&&&&&@@@BB##&&@&&
G#BYP#BB&G#G&G#GG&#GB#GBBBPG&#&5!?P##GY?777JP5JJPB5P@@@&&@@@@@@&@&&BG##@&&&
B#J7GG55GG#G@PJ!~!75G#GBB@GG&B#G???5BJJJ???7YBPJY#&#&G#@&&&&@&&&@&&#PB#&&&&
BB7~77~~JG#G&?~7J7~~5&G##&GG&B&B#P?!??YYY?J?JP5J?JP#&5P@@&&&@@&&&@&####&&&&
?!!7J57!YB#B&Y77J?7JG#B##&GB&B#G&#GY77JJJJPP#BYJJJYYJY5B&@&&&&&&&&&&&&##&&&
!~!77!~!JG#B@BPYYPGGB#B##@GB&B#G&##&GP?!?Y5##G55PPPPG#&&&&&&&&&&&&&&&&&&&&&
!Y7!JY?!!777PB##G@&#B#B#B@GG&B#B###&BG7JGPJJJ5GGB#&@@@@@&&&&&&&&&&&&&@&&&&&
YJ!!7JYJ~7?7JG&#G&#BB#G#B@GB&##B#BBB5PPGBPYYYYYJJY5B@@&&&&&&&&&&&&&@@&&&&&&
BJ7!JGG5??!!YB##B&#B#&B#B@BG&B#BYJ??!?Y5PGGGGGGGG5YYG@&&&&&&&&&&&&&&&&&@&&&
Y7!7YY7?J?7YPG##B&#B#&##G@BG&#&B?!!?JJ5PG555PPPPPPP55&@&&&&&&&@&&&&&&&&&&&&
P5P5BP5Y?!~~^!?5G&#BB#BBG@GB@B#B#GG##BBG57~^^^~~~!75PB@&&&&&&&&&&&&&&&&&&&&
GBBBBJPPJ!~~~~!YP&#GG#G#GB55BB&B#B#&B#P55?77?7!~J5PPPPB@@&&&&&&&&&&&&&&&&&&
77?55?!!!~~!!?YPG&#GBBB5!~~~~7BB#B#&BBY!JJJYY?!!5JJ?YPB@&&@&&&&&&&&&&&&&&&&
JYYJJJ7!!!7?5GPYP&#BB##7~!J?~^JB#B##BBB?!J!~~~775?!?PP&@&@@&&&@@&&&&&&&&&&&
55Y?5GY!77!J5B#BG&&####GJ!!!!7PGBGPPGG#BPP?!!!7J5Y?JG&@@@&&&&&&&&&&&&&&&&&&
~~!7?JJ?YPB#&G#BG&#B###&GB55BB#GPPGP5Y5G#&BY7!!!7JYGGJ5PB5#@@@@@@@&&&&&&&&&
::::~Y5YYG#GG5BBB&#B####G@BB@BP###57~^~!7JG#G5YYYPBGY77!7?JPGBB#&&@@&&&&&&&
:::^!YJJ5J75PYPBB&#B####G&BB&PG&BJ~~~~~~!?YBP77JYJ?!7??77?7?7777?JYB&&&&&&&
.:::~?55PPYJJ?5PPB#B####B&BBB5Y5J~~!JY?~7PPPJ!^^~~~!7?777??77777?Y55#@&&&&&
~~~~~75Y????77?YJYG##B##B&GG5P?^!!~^^!~~!J7?J^^^^::~7?777??????JYYJ?G@&&&&&
Y55YJ?J?J755Y~~BG5JYPBB##&G5PGBPY?!~7J!7JGY5J^^:::^7??77?JJJJJY555YYJB@&&&&
5PP5Y5GPPGGYPJ?PP&#YJ5YBBB5GGGB#B5???!~!75GP?^:::^7??77JYJYJYPPYYY55YY&@&&&
7JY??JJJPYJP#P?5Y##B#BGBGGP5YJ7!!?7~?Y5GB#GJY?^:^?JJ?77JJ55YYP5JY55YYY5@&&&
!?77J77J5!7G@PP&B##G###BGPY7~^^^:~7J7?5#BGYJYJ?~?JJ?J?7YPP5JYGYJYYY555Y#@&&
^~!!~77?57J5GYYBB##G#BG5PY7~!77!^!JBY5GBBPJ?YYJJJJJY5JPPPPYYPGJYYYYYYYJG@&&
:^~!!~^~J??77?BBBB&5Y7!7?!^~!^^^!?5YYYBBGJJJ?5JJJJ5YJJJYJY5PGGYYJJYYY?JP&&&
!~^^:^^^~~!75GBBBBPJ7^~~~~~!!!!7JYJ!77?PYJJJJYJJ5PYJYY5PPGGGGGYYYYJJJ55Y#@&
77^:^^^^~!!???GB#BYY~!7!~!!77!7YG57!!7!?5YYYJY5PPJJJ5PPPPPPGGB5YYYYYYJJJ#@&
7!^!^^^^~~!77P#B##GY7J5J7!!7??JPG?!!!!!!5?JYYYBPYYY55YYY55PPPGPYYYYYYY55#@&
:^^!^::^^~!7?P###B#PY5BGY7!7JJ5PY!777??JBYJJJYYJJJJJJYY55PP555J?7?JY555P&@&
~~~~!!!~~!??YP5GBB&B&BP?!^^~!7JGY?JJY5PB#GGJJJJJJJJJYYY5555YYJ77?JY5555G&@&
P55YPGPY55PPGP5BBB&B&G57!^^~~!5#J?JJY55G##5JYJYYYYYYYYYYYYJJ???YY55PPGB&@&&
GGPYPGP555PGPYY#BG#G#GY7!~~~~!JY??????Y5#PJJYY5PYYYYYYJJ???JJJ5555PB#&@@&&&
YJ55Y55YYYJYY?J5GG#P&P?7!~~~~~~!!77????YBYJJJJJY?JYJJJ??JJYYY555GG#@@@&&@@&
7?YJJJYJJJ??YYJB#B&B&5!!?JJ?777777777777J7777!!!!!5GYJJYYYY55PB##GB@&&&&&@#
!!?7~7777777JJ?G#G&GGJ7!75PPP5YYJJJJJ???777!!!!!!7?B#G5555PB##&&#GG@@@@@&&&
^^~!~!~^7~~~!7!~!!?Y5JJ??????JYYYYY5PGGGGJ7??7?JJJYB&&B55G###&#BGPP&@@&&@&&
:^~~^~^^^^^^^^^^~7Y?Y??7???????7?7?YJYYPBGB#GPP55GB####GB#&#BG5555G@@&&&&&&
^^^~~^^~~~~~~!!!J5YJ5JJ???????J7?7?YJYJY5P#B&&&&#BBGPPGPB#BPYY555PG&@@&@&&&
~~~~~~~~~~~~!!!?P5JYBG5YJ???JJJ77?7YYYYY555B&BB#B5YYYYYYY5YYYYY5PGG#@&&@&&&
~~~~~~~~~!!!!77J5JY5#BPYJJJJJJJ777?JYY5YPPP&B5YYYY55YYYYYYYYY55PGGB@&&&&&&&
!!!!!!!!!!!!77?YYY5P##BP5YJJJJJ777?J55PYPPYBG5P5555GBBGGP555Y55PGG#@&&&&&&#
7!!777777?????JJJY5PGG5YJ77JYYJ7777J5PP5PPYPBPGPPP55555YYYYYYY5PGG&@&&&&&&&
7777???JJJYJJJYYJYJ?7!!!!!?YYYJ7777?YPP5PPY5#BGGGBG555555YYYY5PP5G@&&&@&&&&
??????JJJJ???777777?JY5PGBG5YYJ7777?YPGPP55YG#BBG#G55YYYYYY5555PP#@&&&&&&&&
???JJJJYYYY55PPGP5YG&&&&&BP55YJ?7?7?Y5GPP55YP#BBBBB55YYYYYYY5555P&&&&&&&&&#
####&&#YYB#&&&&&GJ75&&&&#BP55YJ?????J5GGPP555##BBBB5555YYYYY55PPG&&##&&&&&&
BPGB&&#J?B#&&&&&BY75##BBBGGP5YJJ????JYGGPP555G&BBB#P5555555555PPB&###&&&&&&
#G55#&&55BB##&&BBGPP#BBBBBBBG5YJ????JYPBPP555P##GB#G5555555555PP#&&##&&&&&&
GGG55#BGPB5PG##PGBBB########BP5Y????JY5BGP5555B&BBBP555555555PPP#&&&#&&&&&&
B#&G5BBBGB5PGB#BBBBB#########BG5J???JY5BGP5555G&#BBG5555555555PG#&##&&&&&&&
BB&GP&B#GB5GGB##BB############BG5J?JJY5GBGP555P&#BBG55555555PPPG####&&&&&&&
PPBP5BGBBG55GG##B##############BGPYYJY5YG55555P#&#BG5555555PPPBG#&&#&&&&&&&
)RAW";
// ------------------------------------

void printSong() {
    std::vector<std::pair<std::string, double>> lines = {
        // --- 1. КУПЛЕТ (Швидкий, речитативний темп) ---
        {"And when brotherhood come first, then the line'll never be crossed", 0.040},
        {"Established it on our own when that line had to be drawn", 0.040},
        {"And that line is what we reached, so remember me when I'm gone", 0.040},
        {"(Remember me when I'm gone)", 0.060}, 

        // --- 2. ПРИСПІВ (Повільніший, емоційний) ---
        {"How can we not talk about family when family's all that we got?", 0.045}, 
        {"Everythin' I went through, you were standin' there by my side", 0.045},
        {"And now you gon' be with me for the last ride", 0.035}, 

        // --- 3. ПЕРЕД-ПРИСПІВ ---
        {"So let the light guide your way, yeah", 0.135},
        {"Hold every memory as you go", 0.185},
        {"And every road you take", 0.135},
        {"Will always lead you home, home", 0.180},
    };

    std::vector<double> delays = {
        // Куплет 
        0.25, 
        0.25, 
        0.30, 
        1.00, // Пауза після "(Remember me...)"

        // Приспів 2
        0.30,
        0.40,
        1.20, // Пауза перед переходом до пре-приспіву

        // Перед-приспів
        0.50,
        0.50,
        0.60,
        2.50, // Дуже довга пауза після "home, home"
    };

    if (lines.size() != delays.size()) {
        std::cerr << ANSI_COLOR_TEXT << "Помилка: Кількість рядків (" << lines.size() << ") не збігається з кількістю затримок (" << delays.size() << "). Перевірте код." << ANSI_COLOR_RESET << std::endl;
        return;
    }
    
    // --- ВИВЕДЕННЯ АРТУ (Персиковий/Блідо-Оранжевий) ---
    std::cout << ANSI_COLOR_ART << ASCII_ART << ANSI_COLOR_RESET << "\n";
    sleep_seconds(1.0); 
    // --- КІНЕЦЬ ВИВЕДЕННЯ АРТУ ---

    // Ітерація по рядках (Бірюзовий)
    for (size_t i = 0; i < lines.size(); ++i) {
        const std::string& line = lines[i].first;
        double words_delay = lines[i].second;

        // Використовуємо Бірюзовий колір для тексту пісні
        std::cout << ANSI_COLOR_TEXT;

        for (char character : line) {
            std::cout << character << std::flush;
            sleep_seconds(words_delay);
        }

        std::cout << ANSI_COLOR_RESET;
        
        std::cout << "\n";
        sleep_seconds(delays[i]);
    }
}

int main() {
    printSong();
    return 0;
}