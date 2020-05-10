/*
Project: AIAA Introduction to C++
Author: Delenn Bauer
Date: 5/10/2020
File: delenn_stats.cpp
*/

/*
NOTE: This is not actually the solution. This is me kind of doing the activity but also getting distracted and adding other functions in as well. Also I don't think we mention static_cast or .at() both of which I use here. But in general, the functions should work.
*/

//libraries
#include<iostream>
#include<vector>
#include<string>
using namespace std;

// my functions:
vector<double> add_vec(); // takes in a user inputted vector
void print_vec(vector<double> v_print); // prints a vector

// functions for stats activity:
int max(vector<double> v_in);
int min(vector<double> v_in);
int range(vector<double> v_in);
double mean(vector<double> v_in);
bool ascend(vector<double> v_in);

int main(){
    vector<double> a = add_vec();

    int maximum = max(a);
    int minimum = min(a);
    int range_ans = range(a);
    double mean_ans = mean(a);
    bool ascending = ascend(a);

    cout << "The vector [";
    print_vec(a);
    cout << "] has the following properties:" << endl;
    cout << "max: " << maximum << endl;
    cout << "min: " << minimum << endl;
    cout << "range: " << range_ans << endl;
    cout << "mean: " << mean_ans << endl;
    cout << "ascending: " << ascending << endl;
    return 0;
}

void print_vec(vector<double> v_print){
    for(int i = 0; i < v_print.size(); i++){
        cout << v_print.at(i);
        if(i != v_print.size()-1){
            cout << " ";
        }
    }
}

vector<double> add_vec(){
    cout << "Enter vector (values seperated by spaces): ";
    string vec_in;
    getline(cin, vec_in);
    vector<double> new_v;
    int elem_end;
    while(vec_in.find(' ') != vec_in.npos){
        //cout << "vec_in before:" << vec_in << endl;
        elem_end = vec_in.find(' ');
        new_v.push_back(stod(vec_in.substr(0,elem_end)));
        vec_in.erase(0,elem_end+1);
        //cout << "elem_end: " << elem_end << "    vec_in after:" << vec_in << endl;
        //cout << "new_v: ";
        //print_vec(new_v);
        //cout << endl << endl;
    }
    new_v.push_back(stod(vec_in));
    return new_v;
}

int max(vector<double> v_in){
    double max_val = v_in.at(0);
    for(int i = 1; i < v_in.size(); i++){
        if(v_in.at(i) > max_val){
            max_val = v_in.at(i);
        }
    }
    return static_cast<int>(max_val);
}

int min(vector<double> v_in){
    double min_val = v_in.at(0);
    for(int i = 1; i < v_in.size(); i++){
        if(v_in.at(i) < min_val){
            min_val = v_in.at(i);
        }
    }
    return static_cast<int>(min_val);
}

int range(vector<double> v_in){
    double max_val = max(v_in);
    double min_val = min(v_in);
    return static_cast<int>(max_val - min_val);
}

double mean(vector<double> v_in){
    double mean_val;
    double sum = 0;
    for(int i = 0; i < v_in.size(); i++){
        sum += v_in.at(i);
    }
    mean_val = sum / static_cast<double>(v_in.size());
    return mean_val;
}

bool ascend(vector<double> v_in){
    bool ans = true;
    for(int i = 1; i < v_in.size(); i++){
        if(v_in.at(i) < v_in.at(i-1)){
            ans = false;
            break;
        }
    }
    return ans;
}