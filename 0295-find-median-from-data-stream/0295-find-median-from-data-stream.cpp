class MedianFinder {
public:
    priority_queue<double> maxi;
    priority_queue<double,vector<double> ,greater<double>> mini;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxi.push(num);
        if(!maxi.empty() && !mini.empty() && maxi.top() > mini.top()){
            double temp = maxi.top();
            maxi.pop();
            mini.push(temp);
        }
       if( maxi.size() > mini.size() + 1){
            double temp = maxi.top();
            maxi.pop();
            mini.push(temp);
        }

        if( mini.size() > maxi.size()+1){
            double temp = mini.top();
            mini.pop();
            maxi.push(temp);
        }
    }
    
    double findMedian() {
        if( maxi.size() > mini.size()) return maxi.top();
        if( mini.size() > maxi.size()) return mini.top();
        return (maxi.top() + mini.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */