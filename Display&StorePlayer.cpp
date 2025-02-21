#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Player {
    std::string PlayerName;
    std::string PlayerCity;
    std::string PlayerRegion;
    
	int PlayerKills;
    int PlayerDeaths;
    int PlayerTierPoints;
};

class PlayerNode{
	public:
	Player PlayerData;
    PlayerNode* next;
    PlayerNode* prev;

    PlayerNode(const Player& player) : PlayerData(player), next(nullptr), prev(nullptr) {}
};

class PlayerScore{
private:
    PlayerNode* head;
    PlayerNode* tail;
   
public:
	PlayerScore();
	
	void InsertPlayer();
	void SaveToFilePlayer(const string& filename);
	void DisplayAllPlayers();
};
PlayerScore::PlayerScore() : head(nullptr), tail(nullptr) {}

	
/*void PlayerScore::InsertPlayer() {
    Player player;
    
    cout << "Enter Player Name: ";
    cin >> player.PlayerName;
    cin.ignore();
    
    cout << "Enter player Kills: ";
    cin>> player.PlayerKills;
    cin.ignore();
    
    cout << "Enter Player Deaths: ";
    cin >> player.PlayerDeaths;
    cin.ignore();
    
    cout << "Enter Player City: ";
    getline(cin, player.PlayerCity);

    cout << "Enter PlayerRegion: ";
    getline(cin, player.PlayerRegion);
    
    cout<< "Enter Player TierPoints: ";
	cin>> player.PlayerTierPoints;
	
	
	
    PlayerNode* newNode = new PlayerNode(player);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void PlayerScore::SaveToFilePlayer(const string& filename) {
    ofstream file(filename.c_str(), ios_base::app);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    PlayerNode* current = head;
    while (current != nullptr) {
        file << current->PlayerData.PlayerName << " "
             << current->PlayerData.PlayerKills << " "
             << current->PlayerData.PlayerDeaths << " "
             << current->PlayerData.PlayerCity << " "
             << current->PlayerData.PlayerRegion << " "
             << current->PlayerData.PlayerTierPoints << "\n";
        current = current->next;
    }

    file.close();
}
*/
void PlayerScore::DisplayAllPlayers() {
    Player player;
    string line;
    
    system("cls");
    ifstream myFile;
    myFile.open("Players.txt");
    if (myFile.is_open()){
        cout << "ALL PLAYERS" << "\n";
        while(getline(myFile, line)){
            stringstream ss(line);
            ss >> player.PlayerName >> player.PlayerKills >> player.PlayerDeaths >> player.PlayerCity>> player.PlayerRegion >> player.PlayerTierPoints;
            cout <<""<<endl;
            cout<<player.PlayerName <<" - "<<player.PlayerKills <<" - "<<player.PlayerDeaths <<" - "<< player.PlayerCity <<" - "<< player.PlayerRegion <<" - "<< player.PlayerTierPoints;
        }
        myFile.close();
    }
    else{
        cout<<"ERROR! CAN'T FIND FILE.";
    }
}
int main(){
	PlayerScore score;
	
    /*score.InsertPlayer();
    score.SaveToFilePlayer("Player.txt");
    cout << "Video inserted and saved successfully.\n";*/
	
	score.DisplayAllPlayers();
	
	return 0;
}




