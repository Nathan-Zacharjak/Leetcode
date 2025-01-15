class Solution {
public:
    int numRabbits(vector<int>& answers) {
        // Rabbits that answer 0 have to have their own colour
        // Rabbits that answer 1 have to pair with other rabbits that answer 1, or be on their own, which means 1 extra rabbit in the forest
        // Rabbits that answer 2 have to belong to 2 other rabbits that answer 2, or be on their own, or have only 1 rabbit to pair with,
        // which means there is 1 extra or 2 extra rabbits in the forrest

        int otherRabbits = 0;
        int answeredRabbits = answers.size();
        unordered_map<int,int> seenAnswers;

        for (const auto &answer : answers){
            // If the number is zero, skip that rabbit
            if (answer == 0){
                continue;
            }

            // When you see a number for the first time, add it to the total of "other" rabbits that could exist
            if (!seenAnswers.contains(answer)){
                otherRabbits += answer;
                seenAnswers[answer] = answer;
            } else {
                // When you see the same number again, minus 1 from the total of "other" rabbits
                otherRabbits -= 1;
                // Then, keep track of the number of times you have minused 1 from the total for that number
                seenAnswers[answer] -= 1;
                // Once you have minused 1 the same number of times as the number itself, mark the number as unseen again
                if (seenAnswers[answer] == 0){
                    seenAnswers.erase(answer);
                }
            }
        }

        // At the end, sum the length of the answers array with the total number of "other" rabits and return
        return otherRabbits + answeredRabbits;
    }
};