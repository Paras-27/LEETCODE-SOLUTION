class Solution {
public:
    double calculateEntropy(vector<int>& input) {
        const int inputSize = input.size();        
        double entropy = 0.0;
        unordered_map<int,int> value_to_count;
        
        for (const int& n : input) {
            ++value_to_count[n];
        }
        
        for (const pair<int,int>& p : value_to_count) {
            const int value = p.first;
            const int hitcount = p.second;
            
            double probability = static_cast<double>(hitcount) / inputSize;
            double logProbability = log2(probability);
            
            entropy -= (probability * logProbability);
        }
        
        return entropy;        
    }
};