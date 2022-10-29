#include "Map.hpp"

using namespace std;

pair<bool,int> Map::logSearch(int key) const{

    bool exists = false;
    int lowerBound = 0; 
    int upperBound = mapVector.size()-1;
    int middlePoint;

    while (!exists && lowerBound <= upperBound){

        middlePoint = (lowerBound + upperBound) / 2;
        if (mapVector[middlePoint].key>key) { upperBound = middlePoint - 1; }
        else if (mapVector[middlePoint].key<key) { lowerBound = middlePoint + 1; }
        else { exists = true; }
    }

    if (!exists) middlePoint = lowerBound;
    
    return pair<bool,int>(exists,middlePoint);
}

void Map::insert(Item e){

    pair<bool,int> out = logSearch(e.key);

    if (!out.first){ // if an element doesn't exist in a map

        mapVector.resize(mapVector.size()+1);

        for (int i = mapVector.size() - 2; i >= out.second; i--)
        { 
         mapVector[i+1] = mapVector[i];
        }

        mapVector[out.second] = e;
    }
    else  throw ExistingKeyException;
    
}

void Map::erase(int key) throw (CustomExceptions)
{ 

    pair<bool,int> out = logSearch(key);

    if (out.first) {

        for (unsigned int i=out.second+1;i<mapVector.size();i++)
        {
         mapVector[i-1] = mapVector[i];
        }
        mapVector.pop_back();
    }
    else  throw NonExistingKeyException;
    
}

bool Map::isIn(int key) const{

    return logSearch(key).first;
}

string &Map::operator[](int key) throw (CustomExceptions)
{ 

    pair<bool,int> out = logSearch(key);

    if (out.first) return mapVector[out.second].data;

    else throw NonExistingKeyException;
    
}

ostream& operator<<(ostream& s, const Map& m) {

    s << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    s << "Number of elements: " << m.mapVector.size() << "\nContent: " << endl;
    for(unsigned i = 0; i < m.mapVector.size(); ++i){
        s << " " << m.mapVector[i];
    }
    s << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";
    return s;
}

vector<Item> Map::getItems() const {

    vector<Item> v;
    for(unsigned i=0; i<mapVector.size(); ++i) v.push_back(mapVector[i]);

    return v;
}
