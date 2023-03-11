
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Team {
    double participants;
    double oponents;
    double score;
    int index;
};

bool comparatorFn(Team& first, Team& second) {
    if(first.score == second.score) {
        return first.participants > second.participants;
    }
    else {
        return first.score > second.score;
    }
}

int main() {
    int n;
    double participants, oponents;
    cin >> n;

    vector<Team> teams;
    for (int i = 0; i < n; ++i) {
        cin >> participants;
        cin >> oponents;
        Team team = {participants, oponents, (team.participants * team.participants) / team.oponents, i+1};
        teams.push_back(team);
    }


    sort(teams.begin(), teams.end(), comparatorFn);

    for (int i = 0; i < teams.size(); i++) {
        cout << teams[i].index << " ";
    }
}
