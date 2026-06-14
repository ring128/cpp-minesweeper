#include <bits/stdc++.h>
using namespace std;

enum class gamestate{
    playing,
    won,
    lost,
    error
};
gamestate st = gamestate::playing;
void shu(vector<char>& o);
void flg(int r, int c);
void opn(int r, int c);
vector<vector<char>> hw(10, vector<char>(10)); //h,w変更不可
vector<char> o(99); //
vector<vector<char>> bhw(10, vector<char>(10, '#')); //

int npmc = 0; bool gane = false;
int main(){

    for(auto bhww : bhw){
        for(auto nu : bhww){
            cout << nu;
        }
        cout << "\n";
    }
    
    while(st == gamestate::playing){
        string cmd; int hd; int wd;
        cin >> cmd;
        if(cmd == "help"){
            cout << "How to play : type \"cmd((open, flag) or (o, f)) h(0~9) w(0~9)\"" << endl;
            continue;
        }
        cin >> hd >> wd;
        if(bhw[hd][wd] != '#') continue;
        else if(gane == false){
            shu(o); bool tf = false; 
            for(int i = 0; i < 10; i++){ //
                for(int j = 0; j < 10; j++){ //
                    if(i == hd && j == wd){
                        hw[i][j] = '-';
                        tf = true;
                        continue;
                    } 
                    if(tf == false) hw[i][j] = o[i * 10 + j];
                    else hw[i][j] = o[i * 10 + j - 1];
                }
            }
            gane = true;
        }
        if(cmd == "open" || cmd == "o") opn(hd, wd);
        else if(cmd == "flag" || cmd == "f") flg(hd, wd);
        for(auto p : bhw){
            for(auto co : p){
                cout << co;
            }
            cout << "\n";
        }
    }
    if(st == gamestate::won) cout << "You win!" << endl;
    else if(st == gamestate::lost) cout << "You lose..." << endl;
    else if(st == gamestate::error){
        cout << "Error" << endl;
        return 0;
    }

}
void shu(vector<char>& o){
    for(int i = 0; i < 15; i++) o[i] = '*'; //
    for(int i = 15; i < 99; i++) o[i] = '-'; //
    random_device rd; mt19937 sh(rd());
    shuffle(o.begin(), o.end(), sh);
}
void flg(int r, int c){ 
    bhw[r][c] = 'P';
}
void opn(int r, int c){
    if(r > 9 || r < 0 || c > 9 || c < 0) return; //
    if(bhw[r][c] != '#') return;
    if(hw[r][c] == '-'){
        int mc = 0;
        for(int dr = -1; dr <= 1; dr++){
            for(int dc = -1; dc <= 1; dc++){
                if(r + dr > 9 || r + dr < 0 || c + dc > 9 || c + dc < 0) continue; //h,w変更不可
                if(dr == 0 && dc == 0) continue;
                else if(hw[r + dr][c + dc] == '*'){
                    mc++;
                }
            }
        }
        if(mc == 0){
            bhw[r][c] = '.'; npmc++;
            for(int dr = -1; dr <= 1; dr++){
                for(int dc = -1; dc <= 1; dc++){
                    if(r + dr > 9 || r + dr < 0 || c + dc > 9 || c + dc < 0) continue; //h,w変更不可
                    if(dr == 0 && dc == 0) continue;
                    opn(r + dr, c + dc);
                }
            }
        }    
        else if(mc >= 1 && mc <= 8){
            bhw[r][c] = '0' + mc;
            npmc++;
        }    
        else st = gamestate::error;
    }
    else if(hw[r][c] == '*') st = gamestate::lost;
    else st = gamestate::error;
    if(npmc == 85) st = gamestate::won;
}   