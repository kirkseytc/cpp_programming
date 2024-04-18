#include <iostream>
#include <cstdlib>
#include <time.h>

#include "player.hpp"
#include "land.hpp"

using namespace std;

const int LAND_TYPES = 5;
const int MAP_SIZE = 10;
Land* map[MAP_SIZE][MAP_SIZE];

void populateMap(){
    for(int i = 0; i < MAP_SIZE; i++){
        for(int j = 0; j < MAP_SIZE; j++){
            int randomNum = rand() % 5;
            switch(randomNum){
                case 0: // Forest
                    map[i][j] = new Forest;
                    break;
                case 1: // Lake
                    map[i][j] = new Lake;
                    break;
                case 2: // Mountain
                    map[i][j] = new Mountain;
                    break;
                case 3: // Desert
                    map[i][j] = new Desert;
                    break;
                case 4: // Field
                    map[i][j] = new Field;
                    break;
                default: // IDK how we got here
                    cout << "Invalid land type selected" << endl;
                    break;
            }
        }
    }
}

int main(){
    srand(time(0));
    
    populateMap();
    
    Player player(MAP_SIZE/2, MAP_SIZE/2);
    
    cout << "You wake up and find yourself in " << map[player.x][player.y]->getDescription() << endl << endl;
    
    while(player.isAlive()){

        cout << "DAY " << player.getScore() << endl;

        string north_desc, east_desc, south_desc, west_desc;
        
        if(player.y == 0){ // north wrap around
            north_desc = map[player.x][MAP_SIZE - 1]->getDescription();  
        } else {
            north_desc = map[player.x][player.y - 1]->getDescription();
        }

        if(player.x == (MAP_SIZE - 1)){
            east_desc = map[0][player.y]->getDescription();
        } else {
            east_desc = map[player.x + 1][player.y]->getDescription();
        }
        
        if(player.y == (MAP_SIZE - 1)){
            south_desc = map[player.x][0]->getDescription();    
        } else {
            south_desc = map[player.x][player.y + 1]->getDescription();
        }
        
        if(player.x == 0){
            west_desc = map[MAP_SIZE - 1][player.y]->getDescription();
        } else {
            west_desc = map[player.x - 1][player.y]->getDescription();
        }

        cout << "To the north you see " << north_desc << endl;
        cout << "To the east you see " << east_desc << endl;
        cout << "To the south you see " << south_desc << endl;
        cout << "To the west you see " << west_desc << endl;
        
        cout << "Which way will you go? Enter N, E, S, or W:" << endl;
        char userInput;
        cin >> userInput;
        
        switch(userInput){
            case 'n':
            case 'N':
                player.y = player.y - 1;
                break;
            case 'e':
            case 'E':
                player.x = player.x + 1;
                break;
            case 's':
            case 'S':
                player.y = player.y + 1;
                break;
            case 'w':
            case 'W':
                player.x = player.x - 1;
                break;
            default:
                cout << "You couldn't decide where to go, so you stayed put." << endl;
                break;
        }
        
        if(player.x < 0){
            player.x = MAP_SIZE - 1;
        } else if(player.x >= MAP_SIZE){
            player.x = 0;
        }

        if(player.y < 0){
            player.y = MAP_SIZE - 1;
        } else if(player.y >= MAP_SIZE){
            player.y = 0;
        }

        cout << map[player.x][player.y]->visit(player) << endl;
        
        player.takeTurn();
        cout << player.getStats() << endl;
    }
    
    cout << "You died." << endl;
    cout << "You survived a total of " << player.getScore() << " days." << endl;
    
    return 0;
}