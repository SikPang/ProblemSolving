class SeatManager {
private:
    bool* seats;
    int size;
    int lowest;

public:
    SeatManager(int n) 
        : seats(new bool[n+1]())
        , size(n+1)
        , lowest(1)
    {}
    
    int reserve() 
    {
        for (int i=lowest; i<size; ++i)
        {
            if (seats[i] == false)
            {
                lowest = i;
                break;
            }
        }
        seats[lowest] = true;
        return lowest;
    }
    
    void unreserve(int seatNumber) 
    {
        seats[seatNumber] = false;
        if (seatNumber < lowest)
            lowest = seatNumber;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */