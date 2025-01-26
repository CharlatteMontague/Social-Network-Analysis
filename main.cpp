//include libraries that your code uses
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Graph.h"
using namespace std;
///////////////// Before submitting your code
//1) uncomment this part since zyBooks use it.
int main(int argc, const char* argv[]) {
    if (argc != 2)
    {
        std::cout << "./project4 inputFile" << std::endl;
        return EXIT_FAILURE;
    }
    string inputFileName = argv[1];
    
///////////////////// uncomment above befofre submitting on zyBooks /////////////////
//2) Comment the next 2 lines below
//int main(void) {
    //string inputFileName = "input3.txt";    //Do NOT change the name "inputFileName" since used above
    
    //opens file//
    ifstream inputFile;
    inputFile.open(inputFileName);
    
    //shows error if file isn't open//
    if(!inputFile.is_open()){
        cout << "Error opening file" << endl;
    }
    
    Graph userGraph;
    vector<Graph> usernames;
    vector <string> allUser;
    int numUsers = 0;
    string name1;
    string name2;
    
    //read usernames from file//
    while(inputFile >> name1 >> name2){
        Graph userGraph;
        //changes usernames to lowercase//
        for(long unsigned int i = 0; i < name1.length() ; i++){
            name1[i] = tolower(static_cast<unsigned char>(name1[i]));
        }
        for(long unsigned int i = 0; i < name2.length() ; i++){
            name2[i] = tolower(static_cast<unsigned char>(name2[i]));
        }
        userGraph.setName(name1);
        
        //find number of users//
        int userFound = 0;
        //checks usernames//
        for(unsigned int i = 0; i < allUser.size(); i++){
            if(allUser.at(i) == name1){
                userFound = 1;
            }
        }
        if(userFound == 0){
            allUser.push_back(name1);
        }
        
        userFound = 0; //reset to check followers//
        //checks followers//
        for(unsigned int i = 0; i < allUser.size(); i++){
            if(allUser.at(i) == name2){
                userFound = 1;
            }
        }
        if(userFound == 0){
            allUser.push_back(name2);
        }
        
        //puts followers into vector//
        int found = 0;
        for(unsigned int i = 0; i < usernames.size(); i++){
            if(usernames.at(i).getName() == name1){
                found = 1;
                usernames.at(i).addEdge({name2});
            }
        }
        if(found == 0){
            numUsers++;
            userGraph.addEdge({name2});
            usernames.push_back(userGraph);
        }
    }
    inputFile.close(); //close file//
    
    numUsers = allUser.size();
    
    //finds username with the most followers//
    int max = 0;
    string root;
    int index = 0; //index root is at//
    for(unsigned int i = 0; i < usernames.size(); i++){
        int count = usernames.at(i).numFollowers();
        //finds the root and replaces it if username has higher count or is higher in alphabet//
        if(count > max){
            max = count;
            root = usernames.at(i).getName();
            index = i;
        }
        else if(count == max){
            if(usernames.at(i).getName() < root){
                root = usernames.at(i).getName();
                index = i;
            }
        }
    }
    
    cout << "The root user is " << root << ", with in-degree centrality of " << max << "." << endl;
    cout << "There are " << numUsers << " users in the social network." << endl;
    cout << root << " (0)" << endl;
    
    //outputs root's followers as well as their followers followers//
    for(unsigned int i = 0; i < usernames.at(index).followers.size(); i++){
        cout << usernames.at(index).followers.at(i) << " (1)" << endl;
        for(unsigned int j = 0; j < usernames.size(); j++){
            if(usernames.at(index).followers.at(i) == usernames.at(j).getName()){
                usernames.at(j).printGraph();
            }
        }
    }
    
   return 0;   
}
