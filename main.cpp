#include <iostream>
#include <list>
#include <cstring> 

using namespace std;

void displayList(const list<const char*>& stations) {
    for (const auto& station : stations) {
        cout << station << " ";
    }
    cout << endl;
}

int main() {


    // 駅名リスト（英語表記）
    list<const char*> stations_1970s = {
        "Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno", "Uguisudani",
        "Nippori", "Tabata", "Komagome", "Sugamo", "Otsuka", "Ikebukuro",
        "Mejiro", "Takadanobaba", "Shin-Okubo", "Shinjuku", "Yoyogi", "Harajuku",
        "Shibuya", "Ebisu", "Meguro", "Gotanda", "Osaki", "Shinagawa",
        "Tamachi", "Hamamatsucho", "Shimbashi", "Yurakucho"
    };

    
    auto it = stations_1970s.begin();
    advance(it, 8); 
    stations_1970s.insert(it, "Nishi-Nippori");

    
    list<const char*> stations_2019 = stations_1970s;

    
    list<const char*> stations_2022 = stations_2019;
    it = stations_2022.begin();
    advance(it, 22); // Shinagawaの後に追加
    stations_2022.insert(it, "Takanawa Gateway");

    // 駅リストを表示
    cout << "Stations in 1970s:" << endl;
    displayList(stations_1970s);

    cout << "\nStations in 2019:" << endl;
    displayList(stations_2019);

    cout << "\nStations in 2022:" << endl;
    displayList(stations_2022);

    return 0;
}
