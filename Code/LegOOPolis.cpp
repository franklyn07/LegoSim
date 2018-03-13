#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

//including header file for parser
#include "csv_reader.h"

//including header files of pieces
#include "brick.h"
#include "window.h"
#include "door.h"

//including piece factory
#include "lego_factory.h"

//including header files for buildings
#include "_1storey.h"

//include generic linked list header file
#include "linked_list.h"

//include quarry header file
#include "quarry.h"

//include header files of contractors
#include "Bob.h"
#include "Jane.h"
#include "Peter.h"

//include header files for city
#include "city.h"

using namespace std;

void bounds_checker(int amount){
    if(amount>100 || amount<0){
        throw invalid_argument("Out of bounds amount!");
    }
}

int main(int argc, char*argv[]){
    //assign location of input file (passed as cla) at time of declaration
    string location(argv[1]);
    
    //vectors which will hold the parsing of the input file
    vector<string> vec;
    vector<vector<string>> sortedvec;

    //variables containing sizes of lego pieces
    int brick = 0;
    int window = 0;
    int door = 0;

    //sizes of desired amount of buildings
    int _1storey = 0;
    int _2storey = 0;
    int church = 0;
    int hospital = 0;
    int university = 0;


    if (argc < 2)
    {
        cout << "Usage: csv <filename>" << endl;
        return 0;
    }

    try
    {
        CsvReader reader(location);

        while (reader.readLine(vec))
        {
            //push each vector on a vector of vectors if it contains 2 tokens only
            if(vec.size()>2 || vec.size()<2){
                cout<<"Erroneous input!"<<endl;
            }else{
                sortedvec.push_back(vec);
            }
        }

    }
    catch (ifstream::failure &e)
    {
        cout << "Exception! " << e.what() << endl;
    }
    catch (...)
    {
        cout << "Exception!" << endl;
    }

    Quarry *q = Quarry::instance();

    //initialising city to build
    City* city = new City;

    Bob bob;
    Jane jane;
    Peter peter;

    for(unsigned int i=0; i<sortedvec.size(); i++){
        try{
            if (sortedvec[i][0] == "brick"){
                bounds_checker(stoi(sortedvec[i][1]));
                brick = stoi(sortedvec[i][1]);
                q->add_bricks(brick);
            }else if (sortedvec[i][0] == "door"){
                bounds_checker(stoi(sortedvec[i][1]));
                door = stoi(sortedvec[i][1]);
                q->add_doors(door);
            }else if (sortedvec[i][0] == "window"){
                bounds_checker(stoi(sortedvec[i][1]));
                window = stoi(sortedvec[i][1]);
                q->add_windows(window);
            }else if (sortedvec[i][0] == "1storeyhouse"){
                _1storey = stoi(sortedvec[i][1]);
                for(int i = 0; i<_1storey;i++){
                    city->addBuilding(bob._1Storeybuilder::build(q));
                }
            }else if (sortedvec[i][0] == "2storeyhouse"){
                _2storey = stoi(sortedvec[i][1]);
                for(int i = 0; i<_2storey;i++){
                    city->addBuilding(bob._2Storeybuilder::build(q));
                }
            }else if (sortedvec[i][0] == "church"){
                church = stoi(sortedvec[i][1]);
                for(int i = 0; i<church;i++){
                    city->addBuilding(peter.build(q));
                }
            }else if (sortedvec[i][0] == "hospital"){
                hospital = stoi(sortedvec[i][1]);
                for(int i = 0; i<hospital;i++){
                    city->addBuilding(jane.Hospital_builder::build(q));
                }
            }else if (sortedvec[i][0] == "university"){
                university = stoi(sortedvec[i][1]);
                for(int i = 0; i<university;i++){
                    city->addBuilding(jane.University_builder::build(q));
                }
            }
        }catch(const invalid_argument& ia){
            //if 2 tokens however second one is not an integer, we catch exception
            cerr<<"Erroneous input: "<<ia.what()<<endl;
        }catch(const char* msg){
            cerr<<msg<<endl;
        }catch(...){
            //just in case any other exception arises
            cerr<<"Error!"<<endl;
        }
    }

    city->generateReport(university, church, _1storey, _2storey, hospital);

    delete city;
    q->reset_instance();

    return 0;
}