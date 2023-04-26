#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <random>
#include <chrono>
using namespace std;
using namespace chrono;

class movieNode{
    //store data for a singular movie
private:
    unsigned int movieID;
    string movieName;
    unsigned int movieYear;
    string movieCertificate;
    unsigned int movieRuntime;
    vector<string> movieGenre;
    float movieRating;
    unsigned int movieVotes;
    string movieGrossIncome;
    int tempFloat;
public:
    movieNode(unsigned int movieID, string movieName, unsigned int movieYear, unsigned int movieRuntime, float movieRating, unsigned int movieVotes, int tempFloat);
    movieNode();
    movieNode(string movieName, int tempFloat);
    unsigned int getID();
    string getName() const;
    unsigned int getYear();
    unsigned int getRunTime() const;
    float getRating() const;
    unsigned int getVotes();
    int getTempFloat() const;
    void Display(); //displays all attributes of movieNode
};
//Constructor
movieNode::movieNode(unsigned int movieID, string movieName, unsigned int movieYear,
                         unsigned int movieRuntime, float movieRating, unsigned int movieVotes, int tempFloat) {
    this->movieID = movieID;
    this->movieName = movieName;
    this->movieYear = movieYear;
    this->movieRuntime = movieRuntime;
    this->movieRating = movieRating;
    this->movieVotes = movieVotes;
    this->tempFloat = tempFloat;

}

movieNode::movieNode() {
    this->movieID = 0;
    this->movieName = "";
    this->movieYear = 0;
    this->movieRuntime = 0;
    this->movieRating = 0.0;
    this->movieVotes = 0;
    this->tempFloat = 0.0;
}

unsigned int movieNode::getID() {
    return movieID;
}

string movieNode::getName() const {
    return movieName;
}

unsigned int movieNode::getYear() {
    return movieYear;
}

unsigned int movieNode::getRunTime() const {
    return movieRuntime;
}

float movieNode::getRating() const {
    return movieRating;
}

unsigned int movieNode::getVotes() {
    return movieVotes;
}

void movieNode::Display(){
    cout << movieID << endl;
    cout << movieName << endl;
    cout << movieYear << endl;
    cout << movieRuntime << endl;
    cout << movieRating << endl;
    cout << movieVotes << endl;
}

movieNode::movieNode(string movieName, int tempFloat) {
    this->movieName = movieName;
    this->tempFloat = tempFloat;
}

int movieNode::getTempFloat() const {
    return tempFloat;
}



//Quick Sort, Merge Sort, Counting sort algorithms:
//use .clock now() to determine time for each method to run and return sorted vec

//https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
vector<movieNode> randomizeVec(vector<movieNode> movieNodes){
    auto rng = default_random_engine {};
    shuffle(begin(movieNodes), end(movieNodes), rng);
    return movieNodes;
}
/* mergesort(vector){
    split in half
    merge sort first half
    merge sortsecond half
    merge two sorted halves
}*/
//merge sort used idea from https://ufl.instructure.com/courses/471516/pages/module-6-sorting
void merge(vector<movieNode>& movies, int start, int middle, int end, int choice){
    if(choice == 4) {
        vector<movieNode> leftHalf(middle - start + 1);
        vector<movieNode> rightHalf(end - middle);
        for (int i = 0; i < leftHalf.size(); ++i) {
            leftHalf[i] = movies[start + i];
        }
        for (int i = 0; i < rightHalf.size(); ++i) {
            rightHalf[i] = movies[middle + 1 + i];
        }
        int i = 0;
        int j = 0;
        int k = start;

        while (i < leftHalf.size() && j < rightHalf.size()) {
            if (leftHalf[i].getVotes() <= rightHalf[j].getVotes()) {
                movies[k] = leftHalf[i];
                i++;
            } else {
                movies[k] = rightHalf[j];
                j++;
            }
            k++;
        }
        while (i < leftHalf.size()) {
            movies[k] = leftHalf[i];
            i++;
            k++;
        }
        while (i < rightHalf.size()) {
            movies[k] = rightHalf[j];
            j++;
            k++;
        }
    }
    else if(choice == 3){
        vector<movieNode> leftHalf(middle-start+1);
        vector<movieNode> rightHalf(end-middle);
        for(int i = 0; i < leftHalf.size(); ++i){
            leftHalf[i] = movies[start +i];
        }
        for(int i = 0; i < rightHalf.size(); ++i){
            rightHalf[i] = movies[middle + 1  +i];
        }
        int i = 0;
        int j = 0;
        int k = start;

        while(i < leftHalf.size() && j < rightHalf.size()){
            if(leftHalf[i].getRating() <= rightHalf[j].getRating()){
                movies[k] = leftHalf[i];
                i++;
            }
            else{
                movies[k] = rightHalf[j];
                j++;
            }
            k++;
        }
        while( i< leftHalf.size()){
            movies[k] = leftHalf[i];
            i++;
            k++;
        }
        while( i< rightHalf.size()){
            movies[k] = rightHalf[j];
            j++;
            k++;
        }
    }
    else if(choice == 2){
        vector<movieNode> leftHalf(middle-start+1);
        vector<movieNode> rightHalf(end-middle);
        for(int i = 0; i < leftHalf.size(); ++i){
            leftHalf[i] = movies[start +i];
        }
        for(int i = 0; i < rightHalf.size(); ++i){
            rightHalf[i] = movies[middle + 1  +i];
        }
        int i = 0;
        int j = 0;
        int k = start;

        while(i < leftHalf.size() && j < rightHalf.size()){
            if(leftHalf[i].getRunTime() <= rightHalf[j].getRunTime()){
                movies[k] = leftHalf[i];
                i++;
            }
            else{
                movies[k] = rightHalf[j];
                j++;
            }
            k++;
        }
        while( i< leftHalf.size()){
            movies[k] = leftHalf[i];
            i++;
            k++;
        }
        while( i< rightHalf.size()){
            movies[k] = rightHalf[j];
            j++;
            k++;
        }
    }
    else if(choice == 1){
        vector<movieNode> leftHalf(middle-start+1);
        vector<movieNode> rightHalf(end-middle);
        for(int i = 0; i < leftHalf.size(); ++i){
            leftHalf[i] = movies[start +i];
        }
        for(int i = 0; i < rightHalf.size(); ++i){
            rightHalf[i] = movies[middle + 1  +i];
        }
        int i = 0;
        int j = 0;
        int k = start;

        while(i < leftHalf.size() && j < rightHalf.size()){
            if(leftHalf[i].getID() <= rightHalf[j].getID()){
                movies[k] = leftHalf[i];
                i++;
            }
            else{
                movies[k] = rightHalf[j];
                j++;
            }
            k++;
        }
        while( i< leftHalf.size()){
            movies[k] = leftHalf[i];
            i++;
            k++;
        }
        while( i< rightHalf.size()){
            movies[k] = rightHalf[j];
            j++;
            k++;
        }
    }
}
void mergesort(vector<movieNode>& movies, int start, int end, int choice){
    if(start < end){
        int middle = start + (end - start)/2;
        mergesort(movies, start, middle, choice);
        mergesort(movies, middle+1, end, choice);
        merge(movies, start, middle, end, choice);
    }
}

void countSort(vector<movieNode>& currentVec, int sortType){
    if (sortType == 0){ //movie runtime unsigned int 0-1000
        //create an array to determine how many instances of a current number occur
        vector<unsigned int> countingVec(1001, 0); //set vec of size range each with value 0
        //loop through the entire vector and increment the counts of each number in the countingVec
        for (const auto& movieNode : currentVec){
            countingVec[movieNode.getRunTime()]++;
        }
        //increment the countingVec as described logically in the video: https://www.youtube.com/watch?v=OKd534EWcdk&ab_channel=CSDojo
        for (int i = 1; i <= 1000; i++){
            countingVec[i] += countingVec[i-1];
        }
        //place sort into output
        vector<movieNode> tempOutput(currentVec.size());
        //fill output vec
        for (int i = currentVec.size()-1; i >= 0; i--){
            tempOutput[countingVec[currentVec[i].getRunTime()]-1] = currentVec[i];
            countingVec[currentVec[i].getRunTime()]--;
        }
        //fill the initial vec
        for (int i = 0; i < currentVec.size(); i++){
            currentVec[i] = tempOutput[i];
        }

    }
    else if (sortType == 1){ //movie rating float 0.0-10.0 (multiply by 10 so dont have to deal with floats with counting sort)
        //create an array to determine how many instances of a current number occur
        int counter = 0;
        vector<int> countingVec(100, 0); //set vec of size range each with value 0
        //loop through the entire vector and increment the counts of each number in the countingVec
        for (const auto& movieNode : currentVec){
            countingVec[movieNode.getTempFloat()]++;
        }
        //increment the countingVec as described logically in the video: https://www.youtube.com/watch?v=OKd534EWcdk&ab_channel=CSDojo
        for (int i = 1; i <= 99; i++){
            countingVec[i] += countingVec[i-1];
        }
        //place sort into output
        vector<movieNode> tempOutput(currentVec.size());
        //fill output vec
        for (int i = currentVec.size()-1; i >= 0; i--){
            tempOutput[countingVec[currentVec[i].getTempFloat()]-1] = currentVec[i];
            countingVec[currentVec[i].getTempFloat()]--;
        }
        //fill the initial vec
        for (int i = 0; i < currentVec.size(); i++){
            currentVec[i] = tempOutput[i];
        }
    }
}
int main() {
    //Read data from csv file, create movieNodes, and push_back into a vector for sorting algorithm tests
    fstream file;
    file.open("movies5.csv", ios::in);
    std::string line;
    string movieID;
    string movieName;
    string movieYear;
    int movieYearInt;
    string movieRuntime;
    string movieRating;
    float movieRatingFloat;
    string movieVotes;
    int movieVotesInt;
    vector<movieNode> movieNodes; //store movieNodes in a vector to compare sorting algorithms
    string trash;

    if (file.fail()) {
        cout << "File Read Failed" << endl;
    }
    getline(file , line);
    int counter = 0;
    while(counter < 100010) {
        //read the current line in the csv file
        getline(file, movieID, ',');
        getline(file, trash, '"');
        getline(file, trash, '"');
        getline(file, trash, '"');
        getline(file, movieName, '"');
        getline(file, trash, ',');
        getline(file, movieYear, ',');
        getline(file, movieRuntime, ',');
        getline(file, movieRating, ',');
        getline(file, movieVotes);

        //construct node based on data from current line
        bool year = true;
        for (int i = 0; i < movieYear.length(); i++) {
            if(movieYear.empty()){
                year = false;
                break;
            }
            else if (!isdigit(movieYear[i])) {
                year = false;
                break;
            }
            else {
                year = true;
            }
        }
        if (year == false || movieYear.empty()) {
            movieYearInt = 0;
        } else {
            movieYearInt = stoi(movieYear);
        }
        if (movieRating.empty()) {
            movieRatingFloat = 0.0;
        }  else {
            movieRatingFloat = stof(movieRating);
        }
        if (movieVotes.empty()) {
            movieVotesInt = 0;
        }
        else {
            movieVotesInt = stoi(movieVotes);
        }
        unsigned int movieRuntimeInt;
        movieID = movieID.substr(2);
        unsigned int movieIDtransfer = stoi(movieID);
        movieNode tempNode(movieIDtransfer , movieName , movieYearInt ,
        stoi(movieRuntime) , movieRatingFloat , movieVotesInt, (int)(movieRatingFloat*10.0));

        movieNodes.push_back(tempNode); //push back current nodes then read the next line
        counter++; //track num insertions
    }
    //stores how the user wants to sort and what type of data they want sorted
    int sortSelection = 0;
    int dataSelection = 0;
    while (dataSelection != 5){
        /*
         * For each cycle:
         * sort the vector based on type of sorting algorithm and type of data user picks
         * return sorted vector + output the time it took to sort
         */

        //Ask user for input
        cout << "Type the number for the corresponding sort in the menu." << endl;
        cout << "1. Counting Sort" << endl;
        cout << "2. Merge Sort" << endl;
        cout << "3. Stop Sorting" << endl;
        cin >> sortSelection;
        if (sortSelection == 4){
            break;
        }
        cout << "Please enter the movie data type you would like sorted." << endl;
        cout << "1. Movie ID" << endl;
        cout << "2. Movie Runtime" << endl;
        cout << "3. Movie Rating" << endl;
        cout << "4. Move Votes" << endl;
        cout << "5. Stop Sorting" << endl;
        cin >> dataSelection;
        //Randomize vector before each sort to properly measure time it takes.
        movieNodes = randomizeVec(movieNodes);
        if (sortSelection == 1){
            //Counting sort
            //Implement for runtime, rating because other two do not work considering space complexity
            //rating is from 0.0 to 10.0
            //runtime is from 0 to 1000
            if (dataSelection == 2){ //runtime
                //count the time to run + display sort with movie names
                //calculate time with chrono: https://www.geeksforgeeks.org/measure-execution-time-function-cpp/#
                auto start = high_resolution_clock::now();
                countSort(movieNodes, 0);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                for (unsigned int i = 0; i <= 10; i++) {
                    cout << movieNodes[i].getName() << ", ID: " << movieNodes[i].getID() << ", Runtime: " <<
                         movieNodes[i].getRunTime() << ", Rating: " << movieNodes[i].getRating() << ", Votes: " << movieNodes[i].getVotes() << endl;
                }
                for (unsigned int i = movieNodes.size()-10; i < movieNodes.size(); i++) {
                    cout << movieNodes[i].getName() << ", ID: " << movieNodes[i].getID() << ", Runtime: " <<
                         movieNodes[i].getRunTime() << ", Rating: " << movieNodes[i].getRating() << ", Votes: " << movieNodes[i].getVotes() << endl;
                }
                cout << "The time counting sort took was: " << duration.count() << " microseconds." << endl;
            }
            else if (dataSelection == 3){ //rating
                //count the time to run + display sort with movie names
                auto start = high_resolution_clock::now();
                countSort(movieNodes, 1);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << "First 10 movies: " << endl;
                for (unsigned int i = 0; i <= 10; i++) {
                    cout << movieNodes[i].getName() << ", ID: " << movieNodes[i].getID() << ", Runtime: " <<
                         movieNodes[i].getRunTime() << ", Rating: " << (float)(movieNodes[i].getTempFloat() / 10.0) << ", Votes: " << movieNodes[i].getVotes() << endl;
                }
                for (unsigned int i = movieNodes.size()-10; i < movieNodes.size(); i++) {
                    cout << movieNodes[i].getName() << ", ID: " << movieNodes[i].getID() << ", Runtime: " <<
                         movieNodes[i].getRunTime() << ", Rating: " << (float)(movieNodes[i].getTempFloat() / 10.0) << ", Votes: " << movieNodes[i].getVotes() << endl;
                }
                cout << "The time counting sort took was: " << duration.count() << " microseconds." << endl;
                }
            else{
                cout << "The space complexity is not sufficient to run counting sort for this data." << endl;
            }

        }
        else if (sortSelection == 2){
            auto start = high_resolution_clock::now();
            mergesort(movieNodes, 0, movieNodes.size()-1, dataSelection);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "First 10 movies: " << endl;
            for (unsigned int i = 0; i <= 10; i++) {
                cout << movieNodes[i].getName() << ", ID: " << movieNodes[i].getID() << ", Runtime: " <<
                        movieNodes[i].getRunTime() << ", Rating: " << movieNodes[i].getRating() << ", Votes: " << movieNodes[i].getVotes() << endl;
            }
            for (unsigned int i = movieNodes.size()-10; i < movieNodes.size(); i++) {
                cout << movieNodes[i].getName() << ", ID: " << movieNodes[i].getID() << ", Runtime: " <<
                        movieNodes[i].getRunTime() << ", Rating: " << movieNodes[i].getRating() << ", Votes: " << movieNodes[i].getVotes() << endl;
            }
            cout << "The time merge sort took was: " << duration.count() << " microseconds." << endl;
        }

    }
    return 0;
}