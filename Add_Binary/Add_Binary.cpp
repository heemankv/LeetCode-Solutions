class Solution {
public:
    string addBinary(string a, string b) {
        string answer = "";
        
        int ia = a.length() -1;
        int ib = b.length() -1;
        int carry = 0;

        // Either I have ia or ib or carry i need to keep adding it to my answer;
        while(ia >=0 || ib >= 0 || carry){
            if(ia >=0){
                carry += a[ia] - '0'; // add to carry from string a ka last
                ia--;    
            }
            if(ib >=0){
                carry += b[ib] - '0'; // add to carry from string a ka last
                ib--;    
            }
            // carry % 2 => 
            // on 0 will give 0
            // on 1 will give 1
            // on 2 will give 2
            // on 3 will give 1
            char something = carry % 2  + '0';
            answer = something + answer;
            //  now re-evaluate carry by dividing by 2 
            carry/=2;
        }
        return answer;



        // for(int i = 0; i < max(sa,sb); i++){
        //     int vala = (sa-1) -i >= 0 ? (int) a[(sa-1)-i] - '0' : 0;
        //     int valb = (sb-1) -i >= 0 ? (int) b[(sb-1)-i] - '0' : 0;

        //     int sum = vala + valb + carry;

        //     if(sum==2){
        //         // handle carry
        //         carry = 1;
        //         answer = '0' + answer; 
        //     }
        //     else if(sum==3){
        //         // add to current string
        //         answer = (char)(sum%2 + '0') + answer; 
        //         carry = 1;
        //     }
        //     else{
        //         // add to current string
        //         answer = (char)(sum + '0') + answer; 
        //         carry = 0;
        //     }
        // }
        // if(carry == 1){
        //   answer = "1" + answer; 
        // }
        // return answer;
    }




    // string addBinary(string a, string b) {
    //     int sa = a.length();
    //     int sb = b.length();
    //     string answer = "";
    //     int carry = 0;
    //     for(int i = 0; i < max(sa,sb); i++){
    //         int vala = (sa-1) -i >= 0 ? (int) a[(sa-1)-i] - '0' : 0;
    //         int valb = (sb-1) -i >= 0 ? (int) b[(sb-1)-i] - '0' : 0;

    //         int sum = vala + valb + carry;

    //         if(sum==2){
    //             // handle carry
    //             carry = 1;
    //             answer = '0' + answer; 
    //         }
    //         else if(sum==3){
    //             // add to current string
    //             answer = (char)(sum%2 + '0') + answer; 
    //             carry = 1;
    //         }
    //         else{
    //             // add to current string
    //             answer = (char)(sum + '0') + answer; 
    //             carry = 0;
    //         }
    //     }
    //     if(carry == 1){
    //       answer = "1" + answer; 
    //     }
    //     return answer;
    // }

};
