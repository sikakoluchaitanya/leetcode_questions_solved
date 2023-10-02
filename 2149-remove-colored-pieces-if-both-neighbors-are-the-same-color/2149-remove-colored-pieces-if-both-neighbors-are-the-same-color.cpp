class Solution {
public:
    bool winnerOfGame(string colors) 
    {
      int n = colors.size();
      int alice_count=0;
      int bob_count=0;
      if(n<=2)
        return false;

    
        for(int i=0;i<n-2;i++)
      {
        if(colors[i]== 'A' && colors[i+1]== 'A' && colors[i+2]=='A')
        {
          alice_count++;
        }  
        else if(colors[i]== 'B' && colors[i+1]== 'B' && colors[i+2]=='B')
        {
            bob_count++;
        }
      }  
      
      
      if(alice_count>bob_count)
      return true; 
      else return false;
    }
};