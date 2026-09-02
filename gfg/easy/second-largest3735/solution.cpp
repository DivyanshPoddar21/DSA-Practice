class Solution {
  public:
    int getSecondLargest(vector<int> &arr) 
    {
        int largest=-1, second_largest=-1;
        for(int num:arr)
        {
            if(num>largest)
            {
                second_largest=largest;
                largest=num;
            }
            else if(num<largest && num>second_largest)
            {
                second_largest=num;
            }
        }
        return second_largest;
        
    }
};