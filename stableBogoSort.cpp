#include <iostream>
#include <vector>
#include <algorithm> 
#include <random>
#include <chrono>
using namespace std;

class Elements{
    private:
    vector <int> nums;
    vector <int> ordering;
    vector <bool> needIndex;
    int totalNums;
    int attempts;

    public:
    void setTotal(){
        int input;
        cout << endl << "Enter how many numbers (recommended 12 or less):" << endl << endl;
        cin >> input;
        totalNums = input;
    }

    void getNums(){
        cout << endl << "Enter each number" << endl << endl;
        for(unsigned int i=0; i<totalNums; i++){
            int tempTwo;
            cin >> tempTwo;
            nums.push_back(tempTwo);
            ordering.push_back(i);
            needIndex.push_back(false);
        }
    }


    bool IsSorted() {
        for(unsigned int i=1; i<nums.size(); i++){
            if(nums[i] < nums[i-1]) return false;
            if(nums[i] == nums[i-1]){
                if(ordering[i-1] > ordering[i]) return false;
            }
        }
        return true;
    }

    void BogoSort() {
        // Initialize a random number generator
        random_device rd;
        mt19937 rng(rd());

        cout << endl << "Beginning sort..." << endl;
        while (!IsSorted()) {
            shuffle(nums.begin(), nums.end(), rng);
            attempts++;
        }
       
    }

    void PrintVector() {
        for(unsigned int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]){
                needIndex[i] = true;
                needIndex[i-1] = true;
            }
        }
        cout << endl << "Numbers: ";
        for (unsigned int i=0; i<nums.size(); i++) {
            int temp = nums.at(ordering.at(i));
            cout << "\033[36m" << temp << "\033[0m";
            if(needIndex[i] == true){
                cout << "\033[35m" << "[" << ordering[i] << "]\033[0m ";
            }
            else cout << "  ";
        }
        cout << endl << endl;
        cout << "Stablely sorted after " << attempts << " shuffles!" << endl << endl;
    }   

};
 
int main()
{
    Elements numbers;
    numbers.setTotal();
    numbers.getNums();

    numbers.BogoSort();
    numbers.PrintVector();
    return 0;
}