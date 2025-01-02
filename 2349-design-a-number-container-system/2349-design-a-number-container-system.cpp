class NumberContainers {
private:
    unordered_map<int, int> container;
    unordered_map<int, set<int>> indexes;

public:
    NumberContainers() {

    }
    
    void change(int index, int number) {
        if (container.contains(index)){
            int oldNum = container.at(index);
            indexes.at(oldNum).erase(index);

            if (indexes.at(oldNum).empty()){
                indexes.erase(oldNum);
            }
        }

        container[index] = number;
        indexes[number].insert(index);
    }
    
    int find(int number) {
        if (indexes.contains(number)){
            return *indexes.at(number).begin();
        }

        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */