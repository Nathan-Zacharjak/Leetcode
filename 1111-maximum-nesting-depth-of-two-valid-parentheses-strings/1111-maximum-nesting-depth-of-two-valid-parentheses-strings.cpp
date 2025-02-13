class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> depths;
        int currentDepth = 0;
        int bracketBalance = 0;
        int maxDepth = 0;

        for (const auto& c: seq){
            switch (c){
                case '(':
                currentDepth = bracketBalance;
                bracketBalance++;
                break;
                case ')':
                bracketBalance--;
                currentDepth = bracketBalance;
                break;
            }

            maxDepth = max(maxDepth, currentDepth);
            depths.push_back(currentDepth);
        }

        int halfMaxDepth = maxDepth / 2;
        for (auto& depth: depths){
            if (depth > halfMaxDepth){
                depth = 1;
            } else {
                depth = 0;
            }
        }

        return depths;
    }
};