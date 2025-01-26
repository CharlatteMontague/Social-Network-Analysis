#include "Graph.h"

Graph::Graph(){}

void Graph::setName(string userName){
    name = userName;
}

string Graph::getName(){
    return name;
}

//puts follower into vector and sorts alphabetically//
void Graph::addEdge(string userFollower){
    for (unsigned int i = 0; i < followers.size(); i++) {
        if (followers.at(i) > userFollower) {
            followers.insert(followers.begin() + i, userFollower);
            return;
        }
    }
    followers.push_back(userFollower);
}

//returns the number of followers a username has//
int Graph::numFollowers(){
    return followers.size();
}

//prints followers of root's followers//
void Graph::printGraph(){
    for(unsigned int i = 0; i < followers.size(); i++){
        cout << followers.at(i) << " (2)" << endl;
    }
}


    
